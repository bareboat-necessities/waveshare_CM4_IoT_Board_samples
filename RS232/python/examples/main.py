#!/usr/bin/python
# -*- coding:utf-8 -*-
import serial
import os
import sys
import logging

logging.basicConfig(level=logging.INFO)
libdir = os.path.join(os.path.dirname(os.path.dirname(os.path.realpath(__file__))), 'lib')
if os.path.exists(libdir):
    sys.path.append(libdir)
    
import RPi.GPIO as GPIO
import time
from waveshare_UART import config

ser = config.config(dev = "/dev/ttyAMA1",Baudrate = 115200)
data = ''

print("A carriage return and line feed need to be added to the end of the sending string\r\n");
ser.Uart_SendString('Compute Module PoE 4G Board\r\n')
    
try:
    while(1):
        data_t = ser.Uart_ReceiveByte()
        data += str(data_t)
        if(data_t == '\n'):
            print(data)
            ser.Uart_SendString(data)
            data = ''
            
except KeyboardInterrupt:    
    logging.info("ctrl + c:")
    exit()


     
     
     
     