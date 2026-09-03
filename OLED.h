#ifndef __OLED_H
#define __OLED_H

#include "typedef.h"
void OLED_Init(void);
void OLED_Clear(void);
void OLED_ShowChar(u8 Line, u8 Column, char Char);
void OLED_ShowString(u8 Line, u8 Column, char *String);
void OLED_ShowNum(u8 Line, u8 Column, u32 Number, u8 Length);
void OLED_ShowSignedNum(u8 Line, u8 Column, int32 Number, u8 Length);
void OLED_ShowHexNum(u8 Line, u8 Column, u32 Number, u8 Length);
void OLED_ShowBinNum(u8 Line, u8 Column, u32 Number, u8 Length);

#endif
