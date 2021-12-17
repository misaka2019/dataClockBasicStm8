/****************************************************
***ƽ̨��GDUT��ELC STM8 V1
***������ѧϰ��ѯ������������KEY0�ɿ���LED0��������
****************************************************/

#include "iostm8s105c6.h"		//�������õĵ�Ƭ���ͺ�ͷ�ļ�

#define led0  PB_ODR_ODR0		//λ���壬�����
#define key0  PA_IDR_IDR4		//λ���壬���尴��

void IO_Init(void)
{
  PB_DDR |= 0x01;	//led0�������ų�ʼ��Ϊ�������
  PB_CR1 |= 0x01;
  PB_ODR |= 0x01;

  //PA_DDR &= 0x8f;	//����PA4��PA5��PA6Ϊ��������                            
  PA_CR1 |= 0x70;
}

void delay_ms(int xms)	//ms����ʱ����,��Ƶ��2M
{
  for(int i=0;i<xms;i++)
	for(int j=400;j>0;j--);
}

void Query(void)
{
  if(!key0)
  {
    delay_ms(10);          //�����ʱ���10ms����
    if(!key0)
    {
      led0 = ~led0;    //�л���״̬
      while(!key0);    //���ּ�⣬�����ɿ��������ִ�У����Գ���ע�͵�������䣬��һ��Ч����˼��Ϊʲô^-^
    }
   }       
}

void main(void)
{
  IO_Init();		//��ʼ������Ҫ�õ�������
  while(1)		//CPU���ϵ�ִ�в�ѯ����
  {
    Query();	        //���ò�ѯ����
  }
}
