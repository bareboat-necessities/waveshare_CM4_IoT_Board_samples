#!/usr/bin/python
# -*- coding:utf-8 -*-
import serial
import os
import sys
import logging


    
import RPi.GPIO 
import time


IN1 = 23;
IN2 = 24;

OUT1 = 17;
OUT2 = 27;


GPIO = RPi.GPIO
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)


GPIO.setup(OUT1, GPIO.OUT)
GPIO.setup(OUT2, GPIO.OUT)


GPIO.setup(IN1, GPIO.IN)
GPIO.setup(IN2, GPIO.IN)


try:
    i = 0
    while(1):
        GPIO.output(OUT1, i%2)
        GPIO.output(OUT2, (i+1)%2)
        print("OUT1 %d       OUT2  %d"%((i%2),(i+1)%2))
        print("IN1  %d       IN2   %d\r\n\r\n"%(GPIO.input(IN1),GPIO.input(IN2)))
        time.sleep(1)
        i=i+1;
        if(i>=100):
            i = 0;
        
        
except KeyboardInterrupt:    
    logging.info("ctrl + c:")
    exit()


     
     
     
     