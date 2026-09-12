#ifndef __GPIO_H_
#define __GPIO_H_


#include "register.h"
#include "typedef.h"


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



#define P0_MODE_OUT_PP(Pin) P0M0 |= (Pin), P0M1 &= ~(Pin)
#define P1_MODE_OUT_PP(Pin) P1M0 |= (Pin), P1M1 &= ~(Pin)
#define P2_MODE_OUT_PP(Pin) P2M0 |= (Pin), P2M1 &= ~(Pin)
#define P3_MODE_OUT_PP(Pin) P3M0 |= (Pin), P3M1 &= ~(Pin)
#define P4_MODE_OUT_PP(Pin) P4M0 |= (Pin), P4M1 &= ~(Pin)

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

#define P0_MODE_IO_PU(Pin) P0M0 &= ~(Pin), P0M1 &= ~(Pin)
#define P1_MODE_IO_PU(Pin) P1M0 &= ~(Pin), P1M1 &= ~(Pin)
#define P2_MODE_IO_PU(Pin) P2M0 &= ~(Pin), P2M1 &= ~(Pin)
#define P3_MODE_IO_PU(Pin) P3M0 &= ~(Pin), P3M1 &= ~(Pin)
#define P4_MODE_IO_PU(Pin) P4M0 &= ~(Pin), P4M1 &= ~(Pin)

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

#define P0_MODE_OUT_OD(Pin) P0M0 |= (Pin), P0M1 |= (Pin)
#define P1_MODE_OUT_OD(Pin) P1M0 |= (Pin), P1M1 |= (Pin)
#define P2_MODE_OUT_OD(Pin) P2M0 |= (Pin), P2M1 |= (Pin)
#define P3_MODE_OUT_OD(Pin) P3M0 |= (Pin), P3M1 |= (Pin)
#define P4_MODE_OUT_OD(Pin) P4M0 |= (Pin), P4M1 |= (Pin)

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

#define P0_MODE_IN_HIZ(Pin) P0M0 &= ~(Pin), P0M1 |= (Pin)
#define P1_MODE_IN_HIZ(Pin) P1M0 &= ~(Pin), P1M1 |= (Pin)
#define P2_MODE_IN_HIZ(Pin) P2M0 &= ~(Pin), P2M1 |= (Pin)
#define P3_MODE_IN_HIZ(Pin) P3M0 &= ~(Pin), P3M1 |= (Pin)
#define P4_MODE_IN_HIZ(Pin) P4M0 &= ~(Pin), P4M1 |= (Pin)

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

#define GPIO_PullUp 0 
#define GPIO_HighZ  1 
#define GPIO_OUT_OD 2 
#define GPIO_OUT_PP 3 

#define HIGH        1
#define LOW         0

typedef struct
{
    u8 Mode; 
    u8 Pin;  
} gpio_t;

u8 gpio_init(u8 GPIO, gpio_t *GPIOx);
u8 gpio_set(u8 Port, u8 Pin);
u8 gpio_reset(u8 Port, u8 Pin);
u8 gpio_write(u8 Port, u8 Pin, u8 Level);
u8 gpio_read(u8 Port, u8 Pin);

#endif
