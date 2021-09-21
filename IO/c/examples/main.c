#include <stdio.h>      //printf()
#include <stdlib.h>     //exit()
#include <signal.h>
 #include <stdio.h>
 #include <string.h>
#include "DEV_Config.h"


int IN1 = 23;
int IN2 = 24;

int OUT1 = 17;
int OUT2 = 27;


void  Handler(int signo)
{
    //System Exit
    printf("\r\nHandler:Program stop\r\n"); 
    DEV_ModuleExit();

    exit(0);
}


int main(int argc, char **argv)
{
    // Exception handling:ctrl + c
    signal(SIGINT, Handler);
    
	if (DEV_ModuleInit()==1)return 1;
    DEV_GPIO_Mode(OUT1,1);
    DEV_GPIO_Mode(OUT2,1);
    
    DEV_GPIO_Mode(IN1,0);
    DEV_GPIO_Mode(IN2,0);
    
    int i=0;
    while(1){
       DEV_Digital_Write(OUT1, i%2);
       DEV_Digital_Write(OUT2, (i+1)%2);
       printf("OUT1 :%d    OUT2 :%d \r\n", i%2,(i+1)%2);
       DEV_Delay_ms(2);
       printf("IN1  :%d    IN2  :%d \r\n\r\n", DEV_Digital_Read(IN1),DEV_Digital_Read(IN2));
       i++;
       DEV_Delay_ms(1000);
    }

	DEV_ModuleExit();
    return 0; 
}
