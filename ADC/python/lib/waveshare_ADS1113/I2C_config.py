#!/usr/bin/python
# -*- coding:utf-8 -*-
import smbus


class I2C_config(object):
    def __init__(self,address):
        self.i2c = smbus.SMBus(1)
        self.address = address#0x20
    
    def I2C_Send_Byte(self, Reg, data): 
        self.i2c.write_byte(self.address, Reg, data)
    
    def I2C_Read_Byte(self, Reg): 
        return self.i2c.read_byte(self.address, Reg)
    
    def I2C_Send_Word(self, Reg, data ): 
        self.i2c.write_word_data(self.address, Reg, data)
        
    def I2C_Read_Word(self,Reg):
        return self.i2c.read_word_data (self.address, Reg)
        
    def I2C_Set_Address(self, Add):
        self.address = Add
    
        
         
         
         