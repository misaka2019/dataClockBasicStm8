#include "delay.h"

/*****1ms的纯软件延时函数*****/
void delay_ms(unsigned int num)
{
	unsigned int i, j;
	for(i=0; i<num; ++i)
		for(j=0; j<400; ++j);
}

/*****10us的纯软件延时函数*****/
void delay_10us(unsigned int num)
{
	unsigned int i, j;
	for(i=0; i<num; ++i)
		for(j=0; j<1; ++j);
}

/*****1s的纯软件延时*****/
void delay_s(unsigned int num)
{
	unsigned int i;
	for(i=0; i<num; ++i)
	{
		delay_ms(1000);
	}
}

