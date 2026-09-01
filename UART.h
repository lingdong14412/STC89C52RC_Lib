#ifndef __UART_H_
#define __UART_H_
#include "typedef.h"
#include "config.h"
#include "GPIO.h"
#include <stdio.h>
#include <string.h>
#define BAUDRATE 4800

#if FOSC == 12000000L
#if BAUDRATE == 2400
#define _TL1_ (12/ 6 / 16 / 2400 * 1000000)
#define _TH1_ (12 / 6 / 16 / 2400 * 1000000)
#elif BAUDRATE == 4800
#define _TL1_ (12 / 6 / 16 / 4800 * 1000000)
#define _TH1_ (12 / 6 / 16 / 4800 * 1000000)
#elif BAUDRATE == 9600
#define _TL1_ (12 / 6 / 16 / 9600 * 1000000)
#define _TH1_ (12 / 6 / 16 / 9600 * 1000000)
#else
#error "Unsupported Baudrate!"
#endif
#endif

extern u8 rxBuffer[20];
extern u8 rxIndex;
extern u8 cmdReady;
void UART_Init();
void UART_SendByte(u8 dat);
void UART_SendString(char *string);
char putchar(char c);

#endif