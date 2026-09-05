# STC89C52RC库函数说明
# 使用前须知：仅支持11.0592Mhz和12.0000Mhz两种晶振，且使用12.0000Mhz时须在stc-isp软件中勾选6T模式
## 公共头文件：
### register.h  用于声明寄存器
### typedef.h   类型声明
### config.h    用于选择晶振频率，以便匹配不同的外设函数
## 外设文件：

# GPIO
### gpio.h  (借鉴STC8G_H系列库函数及Arduino框架函数风格)
#### 端口宏：GPIP_P0 ~ GPIO_P4
#### 引脚宏：GPIO_Pin_0 ~ GPIO_Pin_7
#### 端口配置宏：
        P0_MODE_IO_PU(GPIO_Pin_x)  配置P0的【一个】引脚为上拉模式
        P0_MODE_IN_HIZ(GPIO_Pin_x) 配置P0的【一个】引脚为高阻模式
        P0_MODE_OUT_PP(GPIO_Pin_x) 配置P0的【一个】引脚为推挽模式
        P0_MODE_OUT_OD(GPIO_Pin_x) 配置P0的【一个】引脚为开漏模式

        P1_MODE_IO_PU(GPIO_Pin_x)  配置P1的【一个】引脚为上拉模式
        P1_MODE_IN_HIZ(GPIO_Pin_x) 配置P1的【一个】引脚为高阻模式
        P1_MODE_OUT_PP(GPIO_Pin_x) 配置P1的【一个】引脚为推挽模式
        P1_MODE_OUT_OD(GPIO_Pin_x) 配置P1的【一个】引脚为开漏模式

        P2_MODE_IO_PU(GPIO_Pin_x)  配置P2的【一个】引脚为上拉模式
        P2_MODE_IN_HIZ(GPIO_Pin_x) 配置P2的【一个】引脚为高阻模式
        P2_MODE_OUT_PP(GPIO_Pin_x) 配置P2的【一个】引脚为推挽模式
        P2_MODE_OUT_OD(GPIO_Pin_x) 配置P2的【一个】引脚为开漏模式

        P3_MODE_IO_PU(GPIO_Pin_x)  配置P3的【一个】引脚为上拉模式
        P3_MODE_IN_HIZ(GPIO_Pin_x) 配置P3的【一个】引脚为高阻模式
        P3_MODE_OUT_PP(GPIO_Pin_x) 配置P3的【一个】引脚为推挽模式
        P3_MODE_OUT_OD(GPIO_Pin_x) 配置P3的【一个】引脚为开漏模式

        P4_MODE_IO_PU(GPIO_Pin_x)  配置P4的【一个】引脚为上拉模式
        P4_MODE_IN_HIZ(GPIO_Pin_x) 配置P4的【一个】引脚为高阻模式
        P4_MODE_OUT_PP(GPIO_Pin_x) 配置P4的【一个】引脚为推挽模式
        P4_MODE_OUT_OD(GPIO_Pin_x) 配置P4的【一个】引脚为开漏模式

        GPIO_MODE_IO_PU(GPIO_Px,GPIO_Pin_x) 配置【多个】引脚为上拉模式(使用或运算)
        GPIO_MODE_IN_HIZ(GPIO_Px,GPIO_Pin_x) 配置【多个】引脚为高阻模式(使用或运算)
        GPIO_MODE_OUT_PP(GPIO_Px,GPIO_Pin_x) 配置【多个】引脚为推挽模式(使用或运算)
        GPIO_MODE_OUT_OD(GPIO_Px,GPIO_Pin_x) 配置【多个】引脚为开漏模式(使用或运算)
    
#### 结构体：struct gpio_t
#### 成员：
        Mode  设置端口模式
        Pin   设置引脚(可用或运算设置多个引脚)
#### 函数：
        u8 gpio_init(u8 GPIO_Px,gpio_t *GPIO_Structure)
            返回值：成功SUCCESS
                    失败FAIL

        u8 gpio_set(u8 Port,u8 Pin)      
            把引脚设置为高电平(可使用或运算)
            返回值：成功SUCCESS
                    失败FAIL

        u8 gpio_reset(u8 Port,u8 Pin)    
            把引脚设置为低电平(可使用或运算)
            返回值：成功SUCCESS
                    失败FAIL

        u8 gpio_write(u8 Port,u8 Pin,u8 Level)   
            设置引脚电平状态(HIGH/LOW)
            返回值：成功SUCCESS
                    失败FAIL

        u8 gpio_read(u8 Port,u8 Pin)    
            读取引脚电平状态
            返回值：HIGH高电平
                    LOW低电平

# OLED屏幕
### oled.h  (SPI协议七针屏幕)(此为移植江科大STM32的OLED函数)
#### 管脚：
    时钟P10
    数据P11
    复位P12
    数据/命令选择P13
    片选P14（可在OLED.c头顶的宏函数修改）
#### 函数：
    void oled_init()
        初始化
        返回值：无

    void oled_clear()
        清屏
        返回值：无

    void oled_showchar(u8 Line,u8 Column,char Char)
        显示一个字符
        返回值：无

    void oled_showstring(u8 Line,u8 Column,char*String)
        显示一个字符串
        返回值：无

    void oled_show_num(u8 Line,u8 Column,u32 Number,u8 Length)
        显示一个无符号数字
        返回值：无

    void oled_show_signednum(u8 Line,u8 Column,int32 Number,u8 Length)
        显示一个有符号数字
        返回值：无

    void oled_show_hexnum(u8 Line,u8 Column,u32 Number,u8 Length)
        显示一个十六进制数字
        返回值：无

    void oled_show_binnum(u8 Line,u8 Column,u32 Number,u8 Length)
        显示一个二进制数字
        返回值：无

# 串口
### uart.h
#### 宏：
    BUFSIZE  设置接收数据缓冲区大小
#### 变量：
    u8 BaudRate (在UART.c里)设置波特率(仅支持2400，4800，9600)，默认9600
    extern u8 rxBuffer[BUFSIZE] 存放接收数据的缓冲区，需在用户代码中手动清空(rxBuffer='\0';)
    extern u8 cmdReady  接收数据完成标志，接收完成自动变为1，在用户代码中需手动置0
#### 函数：
    void uart_init()
        初始化

    void uart_sendbyte(u8 dat)
        发送一个字符

    void uart_sendstring(char *string);
        发送一个字符串

    void uart_set_callback(void(*fn)(void))
        设置串口接收中断回调函数
        接受一个返回值为void，无参数的函数作为参数
        

##### 另：已重定向printf()，可直接用printf发送字符串数据

# 延时
### delay.h
#### 函数:
    void delay(u16 ms)
        延时指定毫秒数

# 定时器(使用定时器0，16位模式)
### timer.h
#### 函数：
    u8 tim_set_arv(u16 x)
        设置定时器定时长度(x为微秒数)
        要求x>100且x<10000
        返回值：SUCCESS成功
                FAIL失败
#### 使用定时器必须使用此函数设置定时长度
    void timer_init()
        初始化定时器
        返回值：无
    void timer_set_callback(void(*fn)(void))
        设置定时器回调函数
        接受一个返回值为void，参数为空的函数作为参数





