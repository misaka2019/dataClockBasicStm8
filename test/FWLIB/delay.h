#ifndef __DELAY_H__
#define __DELAY_H__

/***************************************
*����Ӳ��ִ���ٶȵĲ��죬
*���ļ��ڵĴ������ʱ����ֻ�ʺ���ĳЩCPUƵ����ʹ�ã�
*���#define�����ע��
*
*ʹ�÷���������CPU�Ĺ���Ƶ�ʣ�ȥ����Ӧע�ͼ���
*��ʱ���ȣ�ƽ���ﵽ 1%
****************************************/

/*****IAR�����д������ʱ��׼ȷ����*****/
//	#define mscount 3200	//f_CPU=16M
//	#define mscount 1600	//f_CPU=8M
//	#define mscount 800		//f_CPU=4M
	#define mscount 400		//f_CPU=2M
//	#define mscount 200		//f_CPU=1M
//	#define mscount 100		//f_CPU=500K

//	#define uscount 28		//f_CPU=16M
//	#define uscount 13		//f_CPU=8M
//	#define uscount 4		//f_CPU=4M
	#define uscount 1		//f_CPU=2M

/**************************************
*f_CPU=2M��10us��ʱ�����Ѳ�������
****************************************/

void delay_s(unsigned int num);
void delay_ms(unsigned int num);
void delay_10us(unsigned int num);

#endif
