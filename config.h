// config.h
#ifndef __CONFIG_H__
#define __CONFIG_H__

// 晶振频率选择（只选一个）
#define FOSC_12M      12000000L
#define FOSC_11_0592M 11059200L


// 选择当前使用的晶振（取消注释其中一个）
//#define FOSC  FOSC_12M       // 使用12MHz晶振
  #define FOSC  FOSC_11_0592M



#endif