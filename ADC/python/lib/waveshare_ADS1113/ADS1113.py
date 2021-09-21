#!/usr/bin/python
# -*- coding:utf-8 -*-

# from . import I2C_config
import time
import I2C_config
import smbus


class ADS1113:
    def __init__(self,add ):
        self.i2c = I2C_config.I2C_config(add)       
        
    def Read_Word_Reg(self, Reg):
        data =  self.i2c.I2C_Read_Word(Reg)
        data = data>>8 | ((data<<8)&0xff00)
        return data
        
    def Write_Word_Reg(self, Reg, data):
        self.i2c.I2C_Send_Word (Reg, data)
        
    def ADS1113_Init(self):
        self.Write_Word_Reg(0x01,0x00E0); 
        #Continuous mode 
        #860 SPS

    def ADS1113_ReadData (self):
        return self.Read_Word_Reg(0x00)

    def ADS1113_GetValue(self):
        data = self.Read_Word_Reg(0x00)
        if((data>>15)>0):
            data = (((~data) & 0x7fff )* 2.048 / 0x7fff) * -1.0
        else :
            data = (((~data) & 0x7fff )* 2.048 / 0x7fff)
        return data
    
if __name__=="__main__":
    ADC = ADS1113(add = 0x48)
    ADC.ADS1113_Init()
    while(1):
        value = ADC.ADS1113_GetValue()
        print ("AD : %f\r\n"%value)
        time.sleep(1)
        
        