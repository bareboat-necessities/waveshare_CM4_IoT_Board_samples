#include <stdio.h>      //printf()
#include <stdlib.h>     //exit()
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include "DEV_Config.h"


int LED_1 = 20;
int LED_2 = 26;
int Buzzer = 22;
void  Handler(int signo)
{
    //System Exit
    printf("\r\nHandler:Program stop\r\n"); 
    DEV_Digital_Write(Buzzer, 1);
    DEV_Digital_Write(LED_1, 1);
    DEV_Digital_Write(LED_2, 1);
    DEV_ModuleExit();

    exit(0);
}

int main(int argc, char **argv)
{
    // Exception handling:ctrl + c
    signal(SIGINT, Handler);
    
    if (DEV_ModuleInit()==1)return 1;
    DEV_GPIO_Mode(LED_1,1);
    DEV_GPIO_Mode(LED_2,1);
    DEV_GPIO_Mode(Buzzer,1);
    
    int i=0;
    printf("LED low level light\r\n");
    while(1){
       DEV_Digital_Write(LED_1, i%2);
       DEV_Digital_Write(LED_2, (i+1)%2);
       printf("LED_1 :%d    LED_2 :%d \r\n\r\n", i%2,(i+1)%2);
       i++;
       
       for(int j=0;j<10;j++){
           DEV_Digital_Write(Buzzer, j%2);
           DEV_Delay_ms(30);
       }
       DEV_Delay_ms(1000);
    }

    DEV_ModuleExit();
    return 0; 
}
