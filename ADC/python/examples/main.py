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
from waveshare_ADS1113 import ADS1113


ADC = ADS1113.ADS1113(0x48)

try:
    while(1):
        value = ADC.ADS1113_GetValue()
        print ("AD : %f\r\n"%value)
        time.sleep(1)
            
except KeyboardInterrupt:    
    logging.info("ctrl + c:")
    exit()


     
     
     
     