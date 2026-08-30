#include "GPIO.h"

u8 GPIO_Init(u8 GPIO, GPIO_Type *GPIOx)
{
    if (GPIO > GPIO_P4)
        return FAIL;
    if (GPIOx->Mode > GPIO_OUT_PP)
        return FAIL;

    // 配置端口模式
    switch (GPIO)
    {
    case GPIO_P0:
        if (GPIOx->Mode == GPIO_PullUp)
            // P0M1 &= ~GPIOx->Pin, P0M0 &= ~GPIOx->Pin;
            P0_MODE_IO_PU(GPIOx->Pin);
        else if (GPIOx->Mode == GPIO_HighZ)
            // P0M1 |= GPIOx->Pin, P0M0 &= ~GPIOx->Pin;
            P0_MODE_IN_HIZ(GPIOx->Pin);
        else if (GPIOx->Mode == GPIO_OUT_OD)
            // P0M1 |= GPIOx->Pin, P0M0 |= GPIOx->Pin;
            P0_MODE_OUT_OD(GPIOx->Pin);
        else if (GPIOx->Mode == GPIO_OUT_PP)
            // P0M1 &= ~GPIOx->Pin, P0M0 |= GPIOx->Pin;
            P0_MODE_OUT_PP(GPIOx->Pin);
        break;

    case GPIO_P1:
        if (GPIOx->Mode == GPIO_PullUp)
            // P1M1 &= ~GPIOx->Pin, P1M0 &= ~GPIOx->Pin;
            P1_MODE_IO_PU(GPIOx->Pin);
        else if (GPIOx->Mode == GPIO_HighZ)
            // P1M1 |= GPIOx->Pin, P1M0 &= ~GPIOx->Pin;
            P1_MODE_IN_HIZ(GPIOx->Pin);
        else if (GPIOx->Mode == GPIO_OUT_OD)
            // P1M1 |= GPIOx->Pin, P1M0 |= GPIOx->Pin;
            P1_MODE_OUT_OD(GPIOx->Pin);
        else if (GPIOx->Mode == GPIO_OUT_PP)
            // P1M1 &= ~GPIOx->Pin, P1M0 |= GPIOx->Pin;
            P1_MODE_OUT_PP(GPIOx->Pin);
        break;

    case GPIO_P2:
        if (GPIOx->Mode == GPIO_PullUp)
            // P2M1 &= ~GPIOx->Pin, P2M0 &= ~GPIOx->Pin;
            P2_MODE_IO_PU(GPIOx->Pin);
        else if (GPIOx->Mode == GPIO_HighZ)
            // P2M1 |= GPIOx->Pin, P2M0 &= ~GPIOx->Pin;
            P2_MODE_IN_HIZ(GPIOx->Pin);
        else if (GPIOx->Mode == GPIO_OUT_OD)
            // P2M1 |= GPIOx->Pin, P2M0 |= GPIOx->Pin;
            P2_MODE_OUT_OD(GPIOx->Pin);
        else if (GPIOx->Mode == GPIO_OUT_PP)
            // P2M1 &= ~GPIOx->Pin, P2M0 |= GPIOx->Pin;
            P2_MODE_OUT_PP(GPIOx->Pin);
        break;

    case GPIO_P3:
        if (GPIOx->Mode == GPIO_PullUp)
            // P3M1 &= ~GPIOx->Pin, P3M0 &= ~GPIOx->Pin;
            P3_MODE_IO_PU(GPIOx->Pin);
        else if (GPIOx->Mode == GPIO_HighZ)
            // P3M1 |= GPIOx->Pin, P3M0 &= ~GPIOx->Pin;
            P3_MODE_IN_HIZ(GPIOx->Pin);
        else if (GPIOx->Mode == GPIO_OUT_OD)
            // P3M1 |= GPIOx->Pin, P3M0 |= GPIOx->Pin;
            P3_MODE_OUT_OD(GPIOx->Pin);
        else if (GPIOx->Mode == GPIO_OUT_PP)
            // P3M1 &= ~GPIOx->Pin, P3M0 |= GPIOx->Pin;
            P3_MODE_OUT_PP(GPIOx->Pin);
        break;  

    case GPIO_P4:
        if (GPIOx->Mode == GPIO_PullUp)
            // P4M1 &= ~GPIOx->Pin, P4M0 &= ~GPIOx->Pin;
            P4_MODE_IO_PU(GPIOx->Pin);
        else if (GPIOx->Mode == GPIO_HighZ)
            // P4M1 |= GPIOx->Pin, P4M0 &= ~GPIOx->Pin;
            P4_MODE_IN_HIZ(GPIOx->Pin);
        else if (GPIOx->Mode == GPIO_OUT_OD)
            // P4M1 |= GPIOx->Pin, P4M0 |= GPIOx->Pin;
            P4_MODE_OUT_OD(GPIOx->Pin);
        else if (GPIOx->Mode == GPIO_OUT_PP)
            // P4M1 &= ~GPIOx->Pin, P4M0 |= GPIOx->Pin;
            P4_MODE_OUT_PP(GPIOx->Pin);
        break;
    }

    return SUCCESS;
}

/**
 * @brief  设置引脚为高电平（支持位掩码）
 * @param  Port: 端口号 (0~4)
 * @param  Pin: 位掩码 (0x01~0xFF)，可组合多个引脚
 * @retval SUCCESS/FAIL
 */
u8 GPIO_Pin_Set(u8 Port, u8 Pin)
{
    if (Port > 4) return FAIL;
    if (Pin == 0) return FAIL;
    
    switch (Port)
    {
        case 0:
            P0 |= Pin;
            break;
        case 1:
            P1 |= Pin;
            break;
        case 2:
            P2 |= Pin;
            break;
        case 3:
            P3 |= Pin;
            break;
        case 4:
            P4 |= Pin;
            break;
        default:
            return FAIL;
    }
    return SUCCESS;
}

/**
 * @brief  设置引脚为低电平（支持位掩码）
 * @param  Port: 端口号 (0~4)
 * @param  Pin: 位掩码 (0x01~0xFF)，可组合多个引脚
 * @retval SUCCESS/FAIL
 */
u8 GPIO_Pin_Reset(u8 Port, u8 Pin)
{
    if (Port > 4) return FAIL;
    if (Pin == 0) return FAIL;
    
    switch (Port)
    {
        case 0:
            P0 &= ~Pin;
            break;
        case 1:
            P1 &= ~Pin;
            break;
        case 2:
            P2 &= ~Pin;
            break;
        case 3:
            P3 &= ~Pin;
            break;
        case 4:
            P4 &= ~Pin;
            break;
        default:
            return FAIL;
    }
    return SUCCESS;
}

u8 GPIO_Write(u8 Port, u8 Pin, u8 Level)
{
    if(Port>4)return FAIL;
    if (Level == HIGH)
    {
        GPIO_Pin_Set(Port, Pin);
    }
    else if (Level == LOW)
    {
        GPIO_Pin_Reset(Port, Pin);
    }
    return FAIL;
}
