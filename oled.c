#include "register.h"
#include "delay.h"
#include "gpio.h"
#include "intrins.h"
#include "oled_fonts.h"
#include "typedef.h"
#include "oled.h"

#define OLED_SCL(x) gpio_write(GPIO_P1, GPIO_Pin_0, x)
#define OLED_SDA(x) gpio_write(GPIO_P1, GPIO_Pin_1, x)
#define OLED_RES(x) gpio_write(GPIO_P1, GPIO_Pin_2, x)
#define OLED_DC(x) gpio_write(GPIO_P1, GPIO_Pin_3, x)
#define OLED_CS(x) gpio_write(GPIO_P1, GPIO_Pin_4, x)
gpio_t oled;
/*引脚初始化*/
void OLED_SPI_Init(void)
{
    oled.Mode = GPIO_OUT_PP;
    oled.Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4;

    gpio_init(GPIO_P1, &oled);

    OLED_SCL(0);
    OLED_SDA(1);
    OLED_RES(1);
    OLED_DC(1);
    OLED_CS(1);
}

/**
 * @brief  SPI发送一个字节
 * @param  Byte 要发送的一个字节
 * @retval 无
 */
void OLED_SPI_SendByte(u8 Byte)
{
    u8 i;
    for (i = 0; i < 8; i++)
    {
        OLED_SDA(!!(Byte & (0x80 >> i)));
        OLED_SCL(1);
        OLED_SCL(0);
    }
}

/**
 * @brief  OLED写命令
 * @param  Command 要写入的命令
 * @retval 无
 */
void OLED_WriteCommand(u8 Command)
{
    OLED_CS(0);
    OLED_DC(0);
    OLED_SPI_SendByte(Command);
    OLED_CS(1);
}

/**
 * @brief  OLED写数据
 * @param  Data 要写入的数据
 * @retval 无
 */
void OLED_WriteData(u8 Data)
{
    OLED_CS(0);
    OLED_DC(1);
    OLED_SPI_SendByte(Data);
    OLED_CS(1);
}

/**
 * @brief  OLED设置光标位置
 * @param  Y 以左上角为原点，向下方向的坐标，范围：0~7
 * @param  X 以左上角为原点，向右方向的坐标，范围：0~127
 * @retval 无
 */
void OLED_SetCursor(u8 Y, u8 X)
{
    OLED_WriteCommand(0xB0 | Y);                 // 设置Y位置
    OLED_WriteCommand(0x10 | ((X & 0xF0) >> 4)); // 设置X位置高4位
    OLED_WriteCommand(0x00 | (X & 0x0F));        // 设置X位置低4位
}

/**
 * @brief  OLED清屏
 * @param  无
 * @retval 无
 */
void oled_clear(void)
{
    u8 i, j;
    for (j = 0; j < 8; j++)
    {
        OLED_SetCursor(j, 0);
        for (i = 0; i < 128; i++)
        {
            OLED_WriteData(0x00);
        }
    }
}

/**
 * @brief  OLED显示一个字符
 * @param  Line 行位置，范围：1~4
 * @param  Column 列位置，范围：1~16
 * @param  Char 要显示的一个字符，范围：ASCII可见字符
 * @retval 无
 */
void oled_showchar(u8 Line, u8 Column, char Char)
{
    u8 i;
    OLED_SetCursor((Line - 1) * 2, (Column - 1) * 8); // 设置光标位置在上半部分
    for (i = 0; i < 8; i++)
    {
        OLED_WriteData(OLED_F8x16[Char - ' '][i]); // 显示上半部分内容
    }
    OLED_SetCursor((Line - 1) * 2 + 1, (Column - 1) * 8); // 设置光标位置在下半部分
    for (i = 0; i < 8; i++)
    {
        OLED_WriteData(OLED_F8x16[Char - ' '][i + 8]); // 显示下半部分内容
    }
}

/**
 * @brief  OLED显示字符串
 * @param  Line 起始行位置，范围：1~4
 * @param  Column 起始列位置，范围：1~16
 * @param  String 要显示的字符串，范围：ASCII可见字符
 * @retval 无
 */
void oled_showstring(u8 Line, u8 Column, char *String)
{
    u8 i;
    for (i = 0; String[i] != '\0'; i++)
    {
        oled_showchar(Line, Column + i, String[i]);
    }
}

/**
 * @brief  OLED次方函数
 * @retval 返回值等于X的Y次方
 */
u32 OLED_Pow(u32 X, u32 Y)
{
    u32 Result = 1;
    while (Y--)
    {
        Result *= X;
    }
    return Result;
}

/**
 * @brief  OLED显示数字（十进制，正数）
 * @param  Line 起始行位置，范围：1~4
 * @param  Column 起始列位置，范围：1~16
 * @param  Number 要显示的数字，范围：0~4294967295
 * @param  Length 要显示数字的长度，范围：1~10
 * @retval 无
 */
void oled_show_num(u8 Line, u8 Column, u32 Number, u8 Length)
{
    u8 i;
    for (i = 0; i < Length; i++)
    {
        oled_showchar(Line, Column + i, Number / OLED_Pow(10, Length - i - 1) % 10 + '0');
    }
}

/**
 * @brief  OLED显示数字（十进制，带符号数）
 * @param  Line 起始行位置，范围：1~4
 * @param  Column 起始列位置，范围：1~16
 * @param  Number 要显示的数字，范围：-2147483648~2147483647
 * @param  Length 要显示数字的长度，范围：1~10
 * @retval 无
 */
void oled_show_signednum(u8 Line, u8 Column, int32 Number, u8 Length)
{
    u8 i;
    u32 Number1;
    if (Number >= 0)
    {
        oled_showchar(Line, Column, '+');
        Number1 = Number;
    }
    else
    {
        oled_showchar(Line, Column, '-');
        Number1 = -Number;
    }
    for (i = 0; i < Length; i++)
    {
        oled_showchar(Line, Column + i + 1, Number1 / OLED_Pow(10, Length - i - 1) % 10 + '0');
    }
}

/**
 * @brief  OLED显示数字（十六进制，正数）
 * @param  Line 起始行位置，范围：1~4
 * @param  Column 起始列位置，范围：1~16
 * @param  Number 要显示的数字，范围：0~0xFFFFFFFF
 * @param  Length 要显示数字的长度，范围：1~8
 * @retval 无
 */
void oled_show_hexnum(u8 Line, u8 Column, u32 Number, u8 Length)
{
    u8 i, SingleNumber;
    for (i = 0; i < Length; i++)
    {
        SingleNumber = Number / OLED_Pow(16, Length - i - 1) % 16;
        if (SingleNumber < 10)
        {
            oled_showchar(Line, Column + i, SingleNumber + '0');
        }
        else
        {
            oled_showchar(Line, Column + i, SingleNumber - 10 + 'A');
        }
    }
}

/**
 * @brief  OLED显示数字（二进制，正数）
 * @param  Line 起始行位置，范围：1~4
 * @param  Column 起始列位置，范围：1~16
 * @param  Number 要显示的数字，范围：0~1111 1111 1111 1111
 * @param  Length 要显示数字的长度，范围：1~16
 * @retval 无
 */
void oled_show_binnum(u8 Line, u8 Column, u32 Number, u8 Length)
{
    u8 i;
    for (i = 0; i < Length; i++)
    {
        oled_showchar(Line, Column + i, Number / OLED_Pow(2, Length - i - 1) % 2 + '0');
    }
}

/**
 * @brief  OLED初始化
 * @param  无
 * @retval 无
 */
void oled_init(void)
{
    oled_clear();    // OLED清屏
    OLED_SPI_Init(); // 端口初始化

    OLED_WriteCommand(0xAE); // 关闭显示

    OLED_WriteCommand(0xD5); // 设置显示时钟分频比/振荡器频率
    OLED_WriteCommand(0x80);

    OLED_WriteCommand(0xA8); // 设置多路复用率
    OLED_WriteCommand(0x3F);

    OLED_WriteCommand(0xD3); // 设置显示偏移
    OLED_WriteCommand(0x00);

    OLED_WriteCommand(0x40); // 设置显示开始行

    OLED_WriteCommand(0xA1); // 设置左右方向，0xA1正常 0xA0左右反置

    OLED_WriteCommand(0xC8); // 设置上下方向，0xC8正常 0xC0上下反置

    OLED_WriteCommand(0xDA); // 设置COM引脚硬件配置
    OLED_WriteCommand(0x12);

    OLED_WriteCommand(0x81); // 设置对比度控制
    OLED_WriteCommand(0xCF);

    OLED_WriteCommand(0xD9); // 设置预充电周期
    OLED_WriteCommand(0xF1);

    OLED_WriteCommand(0xDB); // 设置VCOMH取消选择级别
    OLED_WriteCommand(0x30);

    OLED_WriteCommand(0xA4); // 设置整个显示打开/关闭

    OLED_WriteCommand(0xA6); // 设置正常/倒转显示

    OLED_WriteCommand(0xAF); // 开启显示

    OLED_WriteCommand(0x8D); // 设置充电泵
    OLED_WriteCommand(0x14);

    oled_clear(); // OLED清屏
}
