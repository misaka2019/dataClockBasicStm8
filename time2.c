#include "iostm8s105c6.h"

/*用extern修饰词将minutes和seconds的作用域扩展至此文件，
  因为将要在TIM2的中断函数中实时地修改这两个变量的值*/

#define LeapYear(x) (x%4==0&&x%100!=0||x%400==0)?1:0    //闰年判断

extern unsigned int year, month, week, day, hour, min, sec;

//查询月份天数
int Monthnum(int y,int m)
{
  int months[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
     if(LeapYear(y))
     months[2]=29;      //闰年二月29天，平年28天
     return months[m];
}
//查询年天数
int Yearnum(int y)
{
     int t=365;         //平年365天  52周+1天
     t+=LeapYear(y);    //闰年366天 52周+2天
     return t;
}
//计算给定年月的当月第一天星期几
int isWeek(int y,int m)
{
     int year=1900,week=1,i; //定义万年历是从1900年开始  1900年1月1日 星期一
     long sum=0;
     for(i=year;i<y;i++)    //计算制定年之前所有年的天数
     {
         sum+=Yearnum(i);
     }
     for(i=1;i<m;i++)       //计算月份天数
     {
         sum+=Monthnum(y,i);
     }
     i=sum%7;
     week=(week+i)%7;
     return week;
}
//根据给定的年月日，计算星期几
int getWeek(int y,int m,int d)
{
    int week;
    week=(d+isWeek(y,m)-1)%7; /*计算星期*/

    return week;
}

void timecount(void)
{
    if(sec>59)//分
    {
      sec=0;
      min++;
    }
    if(min>59)//时
    {
       min=0;
       hour++;
    }
    if(hour>23)//日
    {
        hour=0;
        day++;
    }
    if(day>Monthnum(year,month))//月
    {
        day=1;
        month++;
    }
    if(month>12)//年
    {
        month=1;
        year++;
    }
    week=getWeek(year,month,day);
}



/*****************************
* 函数名：TIM2_Config
* 描述：  TIM2的配置函数
* 注意：  此配置方式只是作为普通计数器的工作方式而已，
******************************/
void TIM2_Config(void)
{
	TIM2_PSCR = 5;			/*设置预分频系数为 2^5=32，即频率为2M/32=62500，
	                          注意不同定时器的分频计算公式*/
	TIM2_ARRH = 0xF4;		//设置自动装载寄存器的值为 62500，那么定时中断周期刚好为1s
	TIM2_ARRL = 0x24;		// 62500转换成十六进制为 0xF424
	
	TIM2_CR1 |= 0x04;		//设置为更新时计数器不停止，且仅计数器溢出时中断有效
//	TIM2_CR1_URS = 1;
	
	TIM2_EGR |= 0x01;		//产生一个更新事件，触发重装并初始化计数器
//	TIM2_EGR_UG = 1;
	
	TIM2_IER |= 0x01;		//允许更新中断
//	TIM2_IER_UIE = 1;
	
	TIM2_CR1 |= 0x01;		//使能定时器
//	TIM2_CR1_CEN = 1;
}

/*****************************
* 函数名：TIM2_Overflow_IRQHandler
* 描述：  TIM2的溢出中断函数
******************************/
#pragma vector = TIM2_OVR_UIF_vector
//#pragma vector = 15
__interrupt void TIM2_Overflow_IRQHandler(void)
{
        TIM2_SR1 = 0x00;		//清除中断标志
	
        sec++;				//每 1s中断一次，seconds加 1
        timecount();
        
}


