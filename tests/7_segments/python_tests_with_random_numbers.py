import serial
import time
import random

SerialObj = serial.Serial('COM4') # COMxx format on Windows
# ttyUSBx format on Linux

SerialObj.baudrate = 9600 # set Baud rate to 9600
SerialObj.bytesize = 8 # Number of data bits = 8
SerialObj.parity ='N' # No parity
SerialObj.stopbits = 1 # Number of Stop bits = 1

time.sleep(1)


for testEnvoiNombres in range(1, 50, 1):
	nombreAleatoire=str(random.randint(0, 1000))
	print(nombreAleatoire)
	SerialObj.write(bytes(nombreAleatoire, 'ascii')) #transmit ‘A’ (8bit) to micro/Arduino
	time.sleep(0.1)

SerialObj.close() # Close the port
