#include <Servo.h>
Servo myservo;
#define trigPin 3
#define echoPin 2

int i = 0;
int avg_rate = 3;
float distance_sum = 0;

void setup() 
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.attach(5);
}

void loop()
{
  int duration, sample_rate; //sample rate is number of measurements per second
  sample_rate=6;
  float avg_distance, distance;
  int pos = 0;
  
  for (pos = 0; pos < 180; pos += 1)
  {
    myservo.write(pos);
    distance_sum=0;
    for (i = 0; i < avg_rate; i++)
    {
      digitalWrite(trigPin, LOW);
      delayMicroseconds(5);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      duration=pulseIn(echoPin, HIGH);
      distance=(duration/2)/29.1;
      distance_sum += distance;
      delay((1/sample_rate)/avg_rate-1);
    }
    avg_distance = distance_sum / avg_rate;
    
    Serial.print(avg_distance);         //Serial.print(" cm");
    Serial.print('\n');
    Serial.print(pos);
    Serial.print('\n');
    delay(1/sample_rate);
  }
  
  for (pos = 180; pos > 0; pos -= 1)
  {
    myservo.write(pos);
    distance_sum=0;
    for (i = 0; i < avg_rate; i++)
    {
      digitalWrite(trigPin, LOW);
      delayMicroseconds(5);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      duration=pulseIn(echoPin, HIGH);
      distance=(duration/2)/29.1;
      distance_sum += distance;
      delay((1/sample_rate)/avg_rate-1);
    }
    avg_distance = distance_sum / avg_rate;
    
    Serial.print(avg_distance);         //Serial.print(" cm");
    Serial.print('\n');
    Serial.print(pos);
    Serial.print('\n');
    delay(1/sample_rate);
  }

}
