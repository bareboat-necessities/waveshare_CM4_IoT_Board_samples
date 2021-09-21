#include "ADS1113.h"


UWORD ADS1113_Read_Reg(UBYTE Reg)
{
    UBYTE buf[2] = {Reg};
    I2C_Write_nByte(buf, 1);
    I2C_Read_nByte(buf,2);
    return buf[0]<<8 |  buf[1];
}

void ADS1113_Write_Reg(UBYTE Reg, UWORD data)
{
    UBYTE buf[3] = {Reg, (data >> 8) & 0xff, data & 0xff};
    // printf("fasong 0x%x 0x%x 0x%x\r\n",buf[0], buf[1], buf[2]);
    I2C_Write_nByte(buf, 3);
}

void ADS1113_Init(void)
{
    DEV_I2C_Init(ADS1113_Address);
    ADS1113_Write_Reg(0x01,0x00E0);
    // printf("ADS1113_Read_Reg = 0x%x \r\n",ADS1113_Read_Reg(0x01));
}


UWORD ADS1113_ReadData (void)
{ 
    UBYTE buf[2];
    buf[0] = 0x00; //00
    I2C_Write_nByte(buf, 1);
    I2C_Read_nByte(buf,2);
    return buf[0]<<8 |  buf[1];
}

float ADS1113_GetValue(void)
{
    UWORD value = 0;
    value = ADS1113_ReadData(); 
    float data = 0;
    if(value>>15){
        data = (((~value) & 0x7fff )* 2.048 / 0x7fff)*-1;
    }else {
        data = (((~value) & 0x7fff )* 2.048 / 0x7fff);
    }
    return data;
}




