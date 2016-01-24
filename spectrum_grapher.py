from time import sleep
import serial
import numpy as np
import matplotlib.pyplot as plt
import math as m

x_values=[940,630,590,570,510,480,400,370]
color_vector=['#8B0000','r','#FFA500','#FFFF00','g','b','#800080','#663399']
ser = serial.Serial(2, 115200)
plt.axis([350,1000,0,600])
plt.ion()
plt.show()
duration=100
for j in range(0,duration):
      IR = float(ser.readline())
      red = float(ser.readline())
      orange = float(ser.readline())
      yellow = float(ser.readline())
      green = float(ser.readline())
      blue = float(ser.readline())
      purple = float(ser.readline())
      UV = float(ser.readline())
      y_values=[IR,red,orange,yellow,green,blue,purple,UV]
      plt.cla()
      plt.scatter(x_values,y_values, c=color_vector, s=50)
      plt.title('Voltage vs Wavelength')
      plt.xlabel('Wavelength (nm)')
      plt.ylabel('Voltage (mV)')
      plt.yticks(np.arange(0, 600, 100))
      plt.autoscale(False)
      plt.draw()

plt.ioff()
plt.savefig('spectrum_iamge.png')
plt.close()
