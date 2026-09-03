#ifndef __UART_H_
#define __UART_H_


#include "typedef.h"
#include <stdio.h>
#define BUFSIZE 20

extern u8 rxBuffer[BUFSIZE];
extern u8 rxIndex;
extern u8 cmdReady;
void UART_Init();
void UART_SendByte(u8 dat);
void UART_SendString(char *string);
char putchar(char c);

#endif