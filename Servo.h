#ifndef __SERVO_H_
#define __SERVO_H_

#define SUCCESS		0
#define FAIL		-1

#include "typedef.h"
#include "GPIO.h"
#include "Delay.h"


typedef struct
{
    u8 Port;
    u8 Pin;
} Servo;

void Servo_Init(Servo *S);
u16 SetDuty(u16 angle);
void ServoWrite(Servo *S, u16 angle);

#endif