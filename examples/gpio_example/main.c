#include "gpio.h"
#include "delay.h"

gpio_t GPIO_Struct;

void main()
{
	GPIO_Struct.Mode=GPIO_OUT_PP;
	GPIO_Struct.Pin=GPIO_Pin_0|GPIO_Pin_1;	
	gpio_init(GPIO_P2,&GPIO_Struct);		//初始化
	gpio_write(GPIO_P2,GPIO_Pin_0|GPIO_Pin_1,LOW);	//GPIO_Pin_0和GPIO_Pin_1写入低电平
	
	GPIO_MODE_OUT_PP(GPIO_P2,GPIO_Pin_2);
	gpio_set(GPIO_P2,GPIO_Pin_2);
	while(1){
			gpio_write(GPIO_P2,GPIO_Pin_2,!gpio_read(GPIO_P2,GPIO_Pin_2));	
		delay(1000);		//每1秒改变一次电平
	}

}