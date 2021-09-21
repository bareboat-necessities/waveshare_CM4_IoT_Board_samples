#include "DEV_Config.h"

#define ADS1113_Address 0x48


// #define CMD_Write       0x90 
// #define CMD_Read        0x91
#define CMD_POINT_REG   0x00 
#define CMD_CONF_REG    0x01

float ADS1113_GetValue(void);
void ADS1113_Init(void);





