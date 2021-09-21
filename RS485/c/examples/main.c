#include <stdio.h>      //printf()
#include <stdlib.h>     //exit()
#include <signal.h>
 #include <stdio.h>
 #include <string.h>
#include "DEV_Config.h"

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
    
    DEV_UART_Init("/dev/ttyAMA2");
    UART_Set_Baudrate(115200);
    UBYTE pData[1000]={0};
    int i=0;
    printf("A carriage return and line feed need to be added to the end of the sending string\r\n");
    UART_Write_nByte("Compute Module PoE 4G Board\r\n", 29);
    while(1){
        pData[i] = UART_Read_Byte();
        if(pData[i] == '\n'){
            for(int j=0; j<i+1; j++)
                printf("%c",pData[j]);
            UART_Write_nByte(pData, i+1);
            i=0;
        }else if(i>1000){
            i=0;
        }else{
            i++;
        }
    }
    
    DEV_ModuleExit();
    return 0; 
}
