#include "timer.h"

u16 ARV = 1000;

u8 tim_set_arv(u16 x)
{
    if (x < 100 || x > 10000)
    {
        return FAIL;
    }
    else
    {
#if FOSC == 12000000L
        ARV = 12000000/6/x*2;
#elif FOSC == 11059200L
        ARV = 11059200/12/x;
#endif
        return SUCCESS;
    }
}

static timer_callback_t timer_callback = NULL;

void timer_set_callback(timer_callback_t callback)
{
    timer_callback = callback;
}

void Timer0_Isr(void) interrupt 1
{
    TH0 = (65536 - ARV) >> 8;
    TL0 = ARV;

    if (timer_callback != NULL)
    {
        timer_callback();
    }
}

void timer0_init(void)
{

    TMOD &= 0xF0;
    TMOD |= 0x01;
    TH0 = (65536 - ARV) >> 8;
    TL0 = ARV;
    TF0 = 0;
    TR0 = 1;
    ET0 = 1;
    EA = 1;
}
