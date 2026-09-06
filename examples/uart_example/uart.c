#include "uart.h"
#include "config.h"
#include "typedef.h"
#include "register.h"
#include <stdio.h>
#include <stddef.h>

u8 BaudRate = 9600;

u8 rxBuffer[20];
u8 rxIndex = 0;
u8 cmdReady = 0;

static uart_callback_t uart_callback=NULL;

void uart_set_callback(uart_callback_t callback)
{
    uart_callback=callback;
}


void uart_isr(void) interrupt 4
{
    u8 ch;
    if (RI)
    {
        RI = 0;
        ch = SBUF;
        if (ch == '\n' || ch == '\r')
        {
            if (rxIndex > 0)
            {
                rxBuffer[rxIndex] = '\0';
                cmdReady = 1;
                rxIndex = 0;
                if(uart_callback!=NULL)
                {
                    uart_callback();
                }
                rxBuffer[0]='\0';
            }
            return;
        }
        if (rxIndex < sizeof(rxBuffer) - 1)
        {
            rxBuffer[rxIndex++] = ch;
        }
    }
}

void uart_init()
{
    SCON = 0x50;  
    TMOD &= 0x0F; 
    TMOD |= 0x20; 

#if FOSC == 11059200L
    switch (BaudRate)
    {
    case 2400:
        TL1 = 244;
        TH1 = 244;
        break;
    case 4800:
        TL1 = 250;
        TH1 = 250;
        break;
    case 9600:
        TL1 = 253;
        TH1 = 253;
        break;
    default:
        break;
    }

#elif FOSC == 12000000L
    switch (BaudRate)
    {
    case 2400:
        TL1 = 204;
        TH1 = 204;
        break;
    case 4800:
        TL1 = 230;
        TH1 = 230;
        break;
    case 9600:
        TL1 = 243;
        TH1 = 243;
        break;
    default:
        break;
    }
#endif

    ET1 = 0; 
    TR1 = 1; 
    ES = 1;  
    EA = 1; 
}
void uart_sendbyte(u8 dat)
{
    SBUF = dat;
    while (!TI)
        ;
    TI = 0;
}

void uart_sendstring(char *str)
{
    while (*str != '\0')
    {
        uart_sendbyte(*str++);
    }
}

char putchar(char c)
{
    uart_sendbyte((u8)c);
    return c;
}