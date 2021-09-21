#include <stdio.h>      //printf()
#include <stdlib.h>     //exit()
#include <signal.h>
 #include <stdio.h>
 #include <string.h>
#include "DEV_Config.h"
#include "ADS1113.h"


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
    UWORD value = 0;
    ADS1113_Init();
    while(1){
        printf("AD : %f\r\n",ADS1113_GetValue());
        DEV_Delay_ms(1000);
    }
    DEV_ModuleExit();
    return 0; 
}
