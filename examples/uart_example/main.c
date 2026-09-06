#include "uart.h"

void isr()
{
	printf(rxBuffer);		//回显串口收到的的数据
}

void main()
{
	uart_init();
	uart_set_callback(isr);	//设置回调函数

}