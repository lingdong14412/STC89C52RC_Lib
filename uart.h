#ifndef __UART_H_
#define __UART_H_


#include "typedef.h"
#include <stdio.h>
#define BUFSIZE 20

extern u8 rxBuffer[BUFSIZE];
extern u8 rxIndex;
extern u8 cmdReady;
void uart_init();
void uart_sendbyte(u8 dat);
void uart_sendstring(char *string);
char putchar(char c);

#endif