#include "Servo.h"
#include "GPIO.h"
void Servo_Init(Servo *S)
{
    switch (S->Port)
    {
    case GPIO_P0:
        P0_MODE_OUT_PP(S->Pin);
        break;
    case GPIO_P1:
        P1_MODE_OUT_PP(S->Pin);
        break;
    case GPIO_P2:
        P2_MODE_OUT_PP(S->Pin);
        break;
    case GPIO_P3:
        P3_MODE_OUT_PP(S->Pin);
        break;
    case GPIO_P4:
        P4_MODE_OUT_PP(S->Pin);
        break;
    default:
        break;
    }
}

u16 SetDuty(u16 angle)
{
    return (50 + (250 - 50) * angle / 180);
}

void ServoWrite(Servo *S, u16 angle)
{
    GPIO_Write(S->Port,S->Pin,HIGH);
    delayx10us(SetDuty(angle));
    GPIO_Write(S->Port,S->Pin,LOW);
    delayx10us(2000 - SetDuty(angle));
}