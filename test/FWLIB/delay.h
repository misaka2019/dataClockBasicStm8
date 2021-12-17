#ifndef __DELAY_H__
#define __DELAY_H__

/***************************************
*由于硬件执行速度的差异，
*此文件内的纯软件延时函数只适合于某些CPU频率下使用，
*详见#define后面的注释
*
*使用方法：根据CPU的工作频率，去掉相应注释即可
*延时精度：平均达到 1%
****************************************/

/*****IAR环境中纯软件延时的准确数据*****/
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
*f_CPU=2M后，10us延时误差大，已不再适用
****************************************/

void delay_s(unsigned int num);
void delay_ms(unsigned int num);
void delay_10us(unsigned int num);

#endif
