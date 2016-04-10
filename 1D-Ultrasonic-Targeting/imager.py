from time import sleep
import xlwt
import serial
import numpy as np
import matplotlib.pyplot as plt

sample_rate=6
n_pos=180

plt.axis([0,180,0,250])
plt.ion()
plt.title('Graph')
plt.xlabel('Angle (deg)')
plt.ylabel('Object Distance (cm)')
plt.show()

dx = []
dtheta = []
for j in range(0,n_pos*4):
      dx_in = ser.readline() 
      dtheta_in = ser.readline()
      dx.append(dx_in)
      dtheta.append(dtheta)
      plt.scatter(dtheta_in,dx_in)
      plt.draw()
      sleep(1/sample_rate)
plt.ioff()
plt.savefig(graph.png')
plt.close()

f = open("object_finder.txt", "w")
for i in range(len(dx)):
    print >>f, dx[i],'  ', dtheta[i]
f.close()

wb=xlwt.Workbook()
sheet1=wb.add_sheet('Motion Sensor Data')
sheet1.write(0,0,'Range (cm)')
sheet1.write(0,1, 'Angle (deg)')
for row_index in range(len(dx)):
     sheet1.write(row_index+1,0,dx[row_index])
for row_index in range(len(dt)):
     sheet1.write(row_index+1,1,dt[row_index])
wb.save('object_finder.xls')
