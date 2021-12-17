/****************************************************
***平台：GDUT—ELC STM8 V1
***描述：学习查询处理按键，按下KEY0可控制LED0的亮与灭
****************************************************/

#include "iostm8s105c6.h"		//包含所用的单片机型号头文件

#define led0  PB_ODR_ODR0		//位定义，定义灯
#define key0  PA_IDR_IDR4		//位定义，定义按键

void IO_Init(void)
{
  PB_DDR |= 0x01;	//led0所接引脚初始化为推挽输出
  PB_CR1 |= 0x01;
  PB_ODR |= 0x01;

  //PA_DDR &= 0x8f;	//配置PA4，PA5，PA6为上拉输入                            
  PA_CR1 |= 0x70;
}

void delay_ms(int xms)	//ms级延时函数,主频是2M
{
  for(int i=0;i<xms;i++)
	for(int j=400;j>0;j--);
}

void Query(void)
{
  if(!key0)
  {
    delay_ms(10);          //软件延时大概10ms消抖
    if(!key0)
    {
      led0 = ~led0;    //切换灯状态
      while(!key0);    //松手检测，按键松开程序进行执行，可以尝试注释掉这条语句，看一下效果和思考为什么^-^
    }
   }       
}

void main(void)
{
  IO_Init();		//初始化所需要用到的引脚
  while(1)		//CPU不断的执行查询函数
  {
    Query();	        //调用查询函数
  }
}
