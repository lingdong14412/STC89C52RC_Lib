#ifndef __OLED_H
#define __OLED_H

#include "typedef.h"
void oled_init(void);
void oled_clear(void);
void oled_showchar(u8 Line, u8 Column, char Char);
void oled_showstring(u8 Line, u8 Column, char *String);
void oled_show_num(u8 Line, u8 Column, u32 Number, u8 Length);
void oled_show_signednum(u8 Line, u8 Column, int32 Number, u8 Length);
void oled_show_hexnum(u8 Line, u8 Column, u32 Number, u8 Length);
void oled_show_binnum(u8 Line, u8 Column, u32 Number, u8 Length);

#endif
