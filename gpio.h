#ifndef __GPIO_H_
#define __GPIO_H_


#include "register.h"
#include "typedef.h"

//sfr P0   = 0x80;
//sfr P0M0 = 0x93;
//sfr P0M1 = 0x94;
//sbit P00 = P0 ^ 0;
//sbit P01 = P0 ^ 1;
//sbit P02 = P0 ^ 2;
//sbit P03 = P0 ^ 3;
//sbit P04 = P0 ^ 4;
//sbit P05 = P0 ^ 5;
//sbit P06 = P0 ^ 6;
//sbit P07 = P0 ^ 7;

//sfr SP   = 0x81;
//sfr DPL  = 0x82;
//sfr DPH  = 0x83;
//sfr PCON = 0x87;

//sfr TCON = 0x88;
//sbit TF1 = TCON ^ 7;
//sbit TR1 = TCON ^ 6;
//sbit TF0 = TCON ^ 5;
//sbit TR0 = TCON ^ 4;
//sbit IE1 = TCON ^ 3;
//sbit IT1 = TCON ^ 2;
//sbit IE0 = TCON ^ 1;
//sbit IT0 = TCON ^ 0;

//sfr TMOD = 0x89;
//sfr TL0  = 0x8A;
//sfr TL1  = 0x8B;
//sfr TH0  = 0x8C;
//sfr TH1  = 0x8D;
//sfr AUXR = 0x8E;

//sfr P1   = 0x90;
//sfr P1M0 = 0x91;
//sfr P1M1 = 0x92;
//sbit P10 = P1 ^ 0;
//sbit P11 = P1 ^ 1;
//sbit P12 = P1 ^ 2;
//sbit P13 = P1 ^ 3;
//sbit P14 = P1 ^ 4;
//sbit P15 = P1 ^ 5;
//sbit P16 = P1 ^ 6;
//sbit P17 = P1 ^ 7;

//sbit T2EX = P1 ^ 1;
//sbit T2   = P1 ^ 0;

//sfr SCON = 0x98;
//sbit SM0 = SCON ^ 7;
//sbit SM1 = SCON ^ 6;
//sbit SM2 = SCON ^ 5;
//sbit REN = SCON ^ 4;
//sbit TB8 = SCON ^ 3;
//sbit RB8 = SCON ^ 2;
//sbit TI  = SCON ^ 1;
//sbit RI  = SCON ^ 0;

//sfr SBUF = 0x99;

//sfr P2   = 0xA0;
//sfr P2M0 = 0x95;
//sfr P2M1 = 0x96;
//sbit P20 = P2 ^ 0;
//sbit P21 = P2 ^ 1;
//sbit P22 = P2 ^ 2;
//sbit P23 = P2 ^ 3;
//sbit P24 = P2 ^ 4;
//sbit P25 = P2 ^ 5;
//sbit P26 = P2 ^ 6;
//sbit P27 = P2 ^ 7;

//sfr AUXR1 = 0xA2;

//sfr IE   = 0xA8;
//sbit EA  = IE ^ 7;
//sbit EC  = IE ^ 6;
//sbit ET2 = IE ^ 5;
//sbit ES  = IE ^ 4;
//sbit ET1 = IE ^ 3;
//sbit EX1 = IE ^ 2;
//sbit ET0 = IE ^ 1;
//sbit EX0 = IE ^ 0;

//sfr SADDR = 0xA9;

//sfr P3   = 0xB0;
//sfr P3M0 = 0xb1;
//sfr P3M1 = 0xb2;
//sbit P30 = P3 ^ 0;
//sbit P31 = P3 ^ 1;
//sbit P32 = P3 ^ 2;
//sbit P33 = P3 ^ 3;
//sbit P34 = P3 ^ 4;
//sbit P35 = P3 ^ 5;
//sbit P36 = P3 ^ 6;
//sbit P37 = P3 ^ 7;

//sbit RD   = P3 ^ 7;
//sbit WR   = P3 ^ 6;
//sbit T1   = P3 ^ 5;
//sbit T0   = P3 ^ 4;
//sbit INT1 = P3 ^ 3;
//sbit INT0 = P3 ^ 2;
//sbit TXD  = P3 ^ 1;
//sbit RXD  = P3 ^ 0;

//sfr IPH  = 0xB7;
//sfr IP   = 0xB8;
//sbit PT2 = IP ^ 5;
//sbit PS  = IP ^ 4;
//sbit PT1 = IP ^ 3;
//sbit PX1 = IP ^ 2;
//sbit PT0 = IP ^ 1;
//sbit PX0 = IP ^ 0;

//sfr SADEN = 0xB9;

//sfr XICON = 0xC0;
//sbit PX3  = XICON ^ 7;
//sbit EX3  = XICON ^ 6;
//sbit IE3  = XICON ^ 5;
//sbit IT3  = XICON ^ 4;
//sbit PX2  = XICON ^ 3;
//sbit EX2  = XICON ^ 2;
//sbit IE2  = XICON ^ 1;
//sbit IT2  = XICON ^ 0;

//sfr T2CON   = 0xC8;
//sbit TF2    = T2CON ^ 7;
//sbit EXF2   = T2CON ^ 6;
//sbit RCLK   = T2CON ^ 5;
//sbit TCLK   = T2CON ^ 4;
//sbit EXEN2  = T2CON ^ 3;
//sbit TR2    = T2CON ^ 2;
//sbit C_T2   = T2CON ^ 1;
//sbit CP_RL2 = T2CON ^ 0;

//sfr T2MOD  = 0xC9;
//sfr RCAP2L = 0xCA;
//sfr RCAP2H = 0xCB;
//sfr TL2    = 0xCC;
//sfr TH2    = 0xCD;

//sfr PSW  = 0xD0;
//sbit CY  = PSW ^ 7;
//sbit AC  = PSW ^ 6;
//sbit F0  = PSW ^ 5;
//sbit RS1 = PSW ^ 4;
//sbit RS0 = PSW ^ 3;
//sbit OV  = PSW ^ 2;
//sbit F1  = PSW ^ 1;
//sbit P   = PSW ^ 0;

//sfr ACC = 0xE0;

//sfr WDT_CONTR = 0xE1;
//sfr ISP_DATA  = 0xE2;
//sfr ISP_ADDRH = 0xE3;
//sfr ISP_ADDRL = 0xE4;
//sfr ISP_CMD   = 0xE5;
//sfr ISP_TRIG  = 0xE6;
//sfr ISP_CONTR = 0xE7;

//sfr P4   = 0xE8;
//sfr P4M0 = 0xb3;
//sfr P4M1 = 0xb4;
//sbit P40 = P4 ^ 0;
//sbit P41 = P4 ^ 1;
//sbit P42 = P4 ^ 2;
//sbit P43 = P4 ^ 3;
//sbit P44 = P4 ^ 4;
//sbit P45 = P4 ^ 5;
//sbit P46 = P4 ^ 6;
//sbit P47 = P4 ^ 7;

//sfr B = 0xF0;

#define GPIO_P0    0
#define GPIO_P1    1
#define GPIO_P2    2
#define GPIO_P3    3
#define GPIO_P4    4

#define GPIO_Pin_0 0x01
#define GPIO_Pin_1 0x02
#define GPIO_Pin_2 0x04
#define GPIO_Pin_3 0x08
#define GPIO_Pin_4 0x10
#define GPIO_Pin_5 0x20
#define GPIO_Pin_6 0x40
#define GPIO_Pin_7 0x80


/***************
 ****�������****
 ***************/
// ����P0xΪ���������x: 0-7��
#define P0_MODE_OUT_PP(Pin) P0M0 |= (Pin), P0M1 &= ~(Pin)
// ����P1xΪ�������
#define P1_MODE_OUT_PP(Pin) P1M0 |= (Pin), P1M1 &= ~(Pin)
// ����P2xΪ�������
#define P2_MODE_OUT_PP(Pin) P2M0 |= (Pin), P2M1 &= ~(Pin)
// ����P3xΪ�������
#define P3_MODE_OUT_PP(Pin) P3M0 |= (Pin), P3M1 &= ~(Pin)
// ����P4xΪ�������
#define P4_MODE_OUT_PP(Pin) P4M0 |= (Pin), P4M1 &= ~(Pin)

// �������ö������Ϊ���������Port: 0-4, Pin: λ���룩
#define GPIO_MODE_OUT_PP(Port, Pin) \
    do {                                \
        if ((Port) == 0) {              \
            P0M0 |= (Pin);          \
            P0M1 &= ~(Pin);         \
        } else if ((Port) == 1) {       \
            P1M0 |= (Pin);          \
            P1M1 &= ~(Pin);         \
        } else if ((Port) == 2) {       \
            P2M0 |= (Pin);          \
            P2M1 &= ~(Pin);         \
        } else if ((Port) == 3) {       \
            P3M0 |= (Pin);          \
            P3M1 &= ~(Pin);         \
        } else if ((Port) == 4) {       \
            P4M0 |= (Pin);          \
            P4M1 &= ~(Pin);         \
        }                               \
    } while (0)

/***************
 ****׼˫���****
 ***************/
#define P0_MODE_IO_PU(Pin) P0M0 &= ~(Pin), P0M1 &= ~(Pin)
#define P1_MODE_IO_PU(Pin) P1M0 &= ~(Pin), P1M1 &= ~(Pin)
#define P2_MODE_IO_PU(Pin) P2M0 &= ~(Pin), P2M1 &= ~(Pin)
#define P3_MODE_IO_PU(Pin) P3M0 &= ~(Pin), P3M1 &= ~(Pin)
#define P4_MODE_IO_PU(Pin) P4M0 &= ~(Pin), P4M1 &= ~(Pin)

// �������ö������Ϊ׼˫���
#define GPIO_MODE_IO_PU(Port, Pin) \
    do {                               \
        if ((Port) == 0) {             \
            P0M0 &= ~(Pin);        \
            P0M1 &= ~(Pin);        \
        } else if ((Port) == 1) {      \
            P1M0 &= ~(Pin);        \
            P1M1 &= ~(Pin);        \
        } else if ((Port) == 2) {      \
            P2M0 &= ~(Pin);        \
            P2M1 &= ~(Pin);        \
        } else if ((Port) == 3) {      \
            P3M0 &= ~(Pin);        \
            P3M1 &= ~(Pin);        \
        } else if ((Port) == 4) {      \
            P4M0 &= ~(Pin);        \
            P4M1 &= ~(Pin);        \
        }                              \
    } while (0)

/***************
 ****��©ģʽ****
 ***************/
#define P0_MODE_OUT_OD(Pin) P0M0 |= (Pin), P0M1 |= (Pin)
#define P1_MODE_OUT_OD(Pin) P1M0 |= (Pin), P1M1 |= (Pin)
#define P2_MODE_OUT_OD(Pin) P2M0 |= (Pin), P2M1 |= (Pin)
#define P3_MODE_OUT_OD(Pin) P3M0 |= (Pin), P3M1 |= (Pin)
#define P4_MODE_OUT_OD(Pin) P4M0 |= (Pin), P4M1 |= (Pin)

// �������ö������Ϊ��©ģʽ
#define GPIO_MODE_OUT_OD(Port, Pin) \
    do {                                \
        if ((Port) == 0) {              \
            P0M0 |= (Pin);          \
            P0M1 |= (Pin);          \
        } else if ((Port) == 1) {       \
            P1M0 |= (Pin);          \
            P1M1 |= (Pin);          \
        } else if ((Port) == 2) {       \
            P2M0 |= (Pin);          \
            P2M1 |= (Pin);          \
        } else if ((Port) == 3) {       \
            P3M0 |= (Pin);          \
            P3M1 |= (Pin);          \
        } else if ((Port) == 4) {       \
            P4M0 |= (Pin);          \
            P4M1 |= (Pin);          \
        }                               \
    } while (0)

/***************
 ****��������****
 ***************/
#define P0_MODE_IN_HIZ(Pin) P0M0 &= ~(Pin), P0M1 |= (Pin)
#define P1_MODE_IN_HIZ(Pin) P1M0 &= ~(Pin), P1M1 |= (Pin)
#define P2_MODE_IN_HIZ(Pin) P2M0 &= ~(Pin), P2M1 |= (Pin)
#define P3_MODE_IN_HIZ(Pin) P3M0 &= ~(Pin), P3M1 |= (Pin)
#define P4_MODE_IN_HIZ(Pin) P4M0 &= ~(Pin), P4M1 |= (Pin)

// �������ö������Ϊ��������
#define GPIO_MODE_IN_HIZ(Port, Pin) \
    do {                                \
        if ((Port) == 0) {              \
            P0M0 &= ~(Pin);         \
            P0M1 |= (Pin);          \
        } else if ((Port) == 1) {       \
            P1M0 &= ~(Pin);         \
            P1M1 |= (Pin);          \
        } else if ((Port) == 2) {       \
            P2M0 &= ~(Pin);         \
            P2M1 |= (Pin);          \
        } else if ((Port) == 3) {       \
            P3M0 &= ~(Pin);         \
            P3M1 |= (Pin);          \
        } else if ((Port) == 4) {       \
            P4M0 &= ~(Pin);         \
            P4M1 |= (Pin);          \
        }                               \
    } while (0)

/***************
 ****ͨ��ģʽ���ú�****
 ***************/
// ����ģʽ�������ţ�Port: 0-4, Pin: λ����, Mode: GPIO_PullUp/GPIO_HighZ/GPIO_OUT_OD/GPIO_OUT_PP��
#define GPIO_SET_MODE(Port, Pin, Mode)   \
    do {                                     \
        if ((Mode) == GPIO_PullUp) {         \
            GPIO_MODE_IO_PU(Port, Pin);  \
        } else if ((Mode) == GPIO_HighZ) {   \
            GPIO_MODE_IN_HIZ(Port, Pin); \
        } else if ((Mode) == GPIO_OUT_OD) {  \
            GPIO_MODE_OUT_OD(Port, Pin); \
        } else if ((Mode) == GPIO_OUT_PP) {  \
            GPIO_MODE_OUT_PP(Port, Pin); \
        }                                    \
    } while (0)

#define GPIO_PullUp 0 // ����׼˫���
#define GPIO_HighZ  1 // ��������
#define GPIO_OUT_OD 2 // ��©���
#define GPIO_OUT_PP 3 // �������

#define HIGH        1
#define LOW         0

typedef struct
{
    u8 Mode; // IOģʽ,  		GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
    u8 Pin;  // Ҫ���õĶ˿�
} gpio_t;

u8 gpio_init(u8 GPIO, gpio_t *GPIOx);
u8 gpio_set(u8 Port, u8 Pin);
u8 gpio_reset(u8 Port, u8 Pin);
u8 gpio_write(u8 Port, u8 Pin, u8 Level);
u8 gpio_read(u8 Port, u8 Pin);

#endif
