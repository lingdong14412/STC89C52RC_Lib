#include "timer.h"
#include "gpio.h"
#include "typedef.h"
static u8 cnt=0;
void isr()
{
		cnt++;
	if(cnt>=1000)
	{
		gpio_write(GPIO_P2,GPIO_Pin_4,!gpio_read(GPIO_P2,GPIO_Pin_4));		//LED每一秒钟改变一次亮灭
		cnt=0;
	}
	
}

void main()
{
	GPIO_MODE_OUT_PP(GPIO_P2,GPIO_Pin_4);		//设置LED使用的引脚为推挽输出
	gpio_write(GPIO_P2,GPIO_Pin_4,HIGH);
	timer_init();
	tim_set_arv(1000);		//设置定时长度为1ms（1000us）
	
	
	
	
}