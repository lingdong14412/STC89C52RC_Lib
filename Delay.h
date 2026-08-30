// #ifndef __DELAY_H_
// #define __DELAY_H_


// void delayx10us(u16 us); 


// #endif



// delay.h
#ifndef __DELAY_H__
#define __DELAY_H__

#include "config.h"
#include "typedef.h"
#include "intrins.h"

// 根据晶振频率计算延时循环参数
// #if FOSC == 12000000L
//     #define DELAY_10US_LOOP  2   // 12MHz

// #elif FOSC == 11059200L
//     #define DELAY_10US_LOOP  2   // 11.0592MHz (实际约10.8us)

// #elif FOSC == 24000000L
//     #define DELAY_10US_LOOP  4   // 24MHz

// #else
//     #error "Unsupported FOSC! Please define FOSC in config.h"
// #endif

void delayx10us(u16 us);
void delay(u16 ms);

#endif