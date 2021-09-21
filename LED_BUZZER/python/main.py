#!/usr/bin/python
# -*- coding:utf-8 -*-
import serial
import os
import sys
import logging
import RPi.GPIO 
import time

LED_1 = 20;
LED_2 = 26;
Buzzer = 22;

GPIO = RPi.GPIO
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

GPIO.setup(LED_1, GPIO.OUT)
GPIO.setup(LED_2, GPIO.OUT)
GPIO.setup(Buzzer, GPIO.OUT)

try:
    i = 0
    while(1):
        GPIO.output(LED_1, i%2)
        GPIO.output(LED_2, (i+1)%2)
        print("OUT1 :%d    OUT2 :%d \r\n"%(i%2,(i+1)%2))
        for j in range(0, 10):
            GPIO.output(Buzzer, (j)%2)
            time.sleep(0.03)
            
        i = i + 1
        time.sleep(1)
        
        
except KeyboardInterrupt:    
    logging.info("ctrl + c:")
    GPIO.output(LED_1, 1)
    GPIO.output(LED_2, 1)
    GPIO.output(Buzzer, 1)
    exit()


     
     
     
     