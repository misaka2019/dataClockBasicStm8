#include "iostm8s105c6.h"

/*��extern���δʽ�minutes��seconds����������չ�����ļ���
  ��Ϊ��Ҫ��TIM2���жϺ�����ʵʱ���޸�������������ֵ*/

#define LeapYear(x) (x%4==0&&x%100!=0||x%400==0)?1:0    //�����ж�

extern unsigned int year, month, week, day, hour, min, sec;

//��ѯ�·�����
int Monthnum(int y,int m)
{
  int months[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
     if(LeapYear(y))
     months[2]=29;      //�������29�죬ƽ��28��
     return months[m];
}
//��ѯ������
int Yearnum(int y)
{
     int t=365;         //ƽ��365��  52��+1��
     t+=LeapYear(y);    //����366�� 52��+2��
     return t;
}
//����������µĵ��µ�һ�����ڼ�
int isWeek(int y,int m)
{
     int year=1900,week=1,i; //�����������Ǵ�1900�꿪ʼ  1900��1��1�� ����һ
     long sum=0;
     for(i=year;i<y;i++)    //�����ƶ���֮ǰ�����������
     {
         sum+=Yearnum(i);
     }
     for(i=1;i<m;i++)       //�����·�����
     {
         sum+=Monthnum(y,i);
     }
     i=sum%7;
     week=(week+i)%7;
     return week;
}
//���ݸ����������գ��������ڼ�
int getWeek(int y,int m,int d)
{
    int week;
    week=(d+isWeek(y,m)-1)%7; /*��������*/

    return week;
}

void timecount(void)
{
    if(sec>59)//��
    {
      sec=0;
      min++;
    }
    if(min>59)//ʱ
    {
       min=0;
       hour++;
    }
    if(hour>23)//��
    {
        hour=0;
        day++;
    }
    if(day>Monthnum(year,month))//��
    {
        day=1;
        month++;
    }
    if(month>12)//��
    {
        month=1;
        year++;
    }
    week=getWeek(year,month,day);
}



/*****************************
* ��������TIM2_Config
* ������  TIM2�����ú���
* ע�⣺  �����÷�ʽֻ����Ϊ��ͨ�������Ĺ�����ʽ���ѣ�
******************************/
void TIM2_Config(void)
{
	TIM2_PSCR = 5;			/*����Ԥ��Ƶϵ��Ϊ 2^5=32����Ƶ��Ϊ2M/32=62500��
	                          ע�ⲻͬ��ʱ���ķ�Ƶ���㹫ʽ*/
	TIM2_ARRH = 0xF4;		//�����Զ�װ�ؼĴ�����ֵΪ 62500����ô��ʱ�ж����ڸպ�Ϊ1s
	TIM2_ARRL = 0x24;		// 62500ת����ʮ������Ϊ 0xF424
	
	TIM2_CR1 |= 0x04;		//����Ϊ����ʱ��������ֹͣ���ҽ����������ʱ�ж���Ч
//	TIM2_CR1_URS = 1;
	
	TIM2_EGR |= 0x01;		//����һ�������¼���������װ����ʼ��������
//	TIM2_EGR_UG = 1;
	
	TIM2_IER |= 0x01;		//��������ж�
//	TIM2_IER_UIE = 1;
	
	TIM2_CR1 |= 0x01;		//ʹ�ܶ�ʱ��
//	TIM2_CR1_CEN = 1;
}

/*****************************
* ��������TIM2_Overflow_IRQHandler
* ������  TIM2������жϺ���
******************************/
#pragma vector = TIM2_OVR_UIF_vector
//#pragma vector = 15
__interrupt void TIM2_Overflow_IRQHandler(void)
{
        TIM2_SR1 = 0x00;		//����жϱ�־
	
        sec++;				//ÿ 1s�ж�һ�Σ�seconds�� 1
        timecount();
        
}


