void setup() {
Serial.begin(115200);
int sample_size;
float time_offset;
}

int get_sample_size(){
  while (Serial.available()==0);
   int sample_size = Serial.read()-'0';return sample_size;}
float get_time(){
  return float(millis())/1000.0;
  }
float avg_array(int a[], int num_elements){
  int i, sum=0;
   for (i=0; i<num_elements; i++){
    sum = sum + a[i];
    }
   return(sum/num_elements);
   }

void loop() {
  while(sample_size == false){
    sample_size=get_sample_size();
    time_offset=get_time();
    }
    
  int IR_arr[sample_size], Red_arr[sample_size], Orange_arr[sample_size], Yellow_arr[sample_size], Green_arr[sample_size], Blue_arr[sample_size], Purple_arr[sample_size], UV_arr[sample_size];
  
  for (int i=0;i<sample_size;i++){
    IR_arr[i]=analogRead(A0);
    Red_arr[i]=analogRead(A1);
    Orange_arr[i]=analogRead(A2);
    Yellow_arr[i]=analogRead(A3);
    Green_arr[i]=analogRead(A4);
    Blue_arr[i]=analogRead(A5);
    Purple_arr[i]=analogRead(A6);
    UV_arr[i]=analogRead(A7);
    delay(10);
    }
       
 float IR_avg = avg_array(IR_arr, sample_size);
 float Red_avg = avg_array(Red_arr, sample_size);
 float Orange_avg = avg_array(Orange_arr, sample_size);
 float Yellow_avg = avg_array(Yellow_arr, sample_size);
 float Green_avg = avg_array(Green_arr, sample_size);
 float Blue_avg = avg_array(Blue_arr, sample_size);
 float Purple_avg = avg_array(Purple_arr, sample_size);
 float UV_avg = avg_array(UV_arr, sample_size);
  Serial.println(IR_avg);
  Serial.println(Red_avg);
  Serial.println(Orange_avg);
  Serial.println(Yellow_avg);
  Serial.println(Green_avg);
  Serial.println(Blue_avg);
  Serial.println(Purple_avg);
  Serial.println(UV_avg);
  Serial.println(get_time()-time_offset);
}
