#include "Delay.h"

void delayx10us(u16 us)
{
#if FOSC == 11059200L
    while (us--) //@11.0592MHz
    {
        unsigned char data i;
        i = 2;
        while (--i)
            ;
    }
#elif FOSC == 12000000L
    u16 dus = 4 * us;
    while (dus--) //@12.000MHz
    {
        unsigned char data i;
        _nop_();
        i = 2;
        while (--i)
            ;
    }

#endif
}

void delay(u16 ms)
{

#if FOSC == 11059200L
    while (ms--) //@11.0592MHz
    {
        unsigned char data i, j;
        _nop_();
        i = 2;
        j = 199;
        do
        {
            while (--j)
                ;
        } while (--i);
    }
#elif FOSC == 12000000L
    u16 dms = 4 * ms;
    while (dms--) //@12.000MHz
    {
        unsigned char data i, j;
        i = 2;
        j = 239;
        do
        {
            while (--j)
                ;
        } while (--i);
    }

#endif
}