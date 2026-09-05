#ifndef __UART_H_
#define __UART_H_


#include "typedef.h"
#include <stdio.h>
#define BUFSIZE 20

extern u8 rxBuffer[BUFSIZE];
extern u8 rxIndex;
extern u8 cmdReady;

typedef void (*uart_callback_t)(void);

void uart_init();
void uart_set_callback(uart_callback_t callback);
void uart_sendbyte(u8 dat);
void uart_sendstring(char *string);
char putchar(char c);

#endif