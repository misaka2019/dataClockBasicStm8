#include "delay.h"

/*****1ms�Ĵ������ʱ����*****/
void delay_ms(unsigned int num)
{
	unsigned int i, j;
	for(i=0; i<num; ++i)
		for(j=0; j<400; ++j);
}

/*****10us�Ĵ������ʱ����*****/
void delay_10us(unsigned int num)
{
	unsigned int i, j;
	for(i=0; i<num; ++i)
		for(j=0; j<1; ++j);
}

/*****1s�Ĵ������ʱ*****/
void delay_s(unsigned int num)
{
	unsigned int i;
	for(i=0; i<num; ++i)
	{
		delay_ms(1000);
	}
}

