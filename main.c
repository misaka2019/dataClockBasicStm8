#include "gpio.h"
#include "oled.h"
#include "spi.h"
#include "iostm8s105c6.h"
#include "intrinsics.h"
#include "time2.h"
#include "delay.h"

#define beep PD_ODR_ODR4
#define led0  PB_ODR_ODR0		//位定义，定义灯
#define key3  PA_IDR_IDR3		//位定义，定义按键
#define key0  PA_IDR_IDR4		//位定义，定义按键
#define key1  PA_IDR_IDR5		//位定义，定义按键
#define key2  PA_IDR_IDR6		//位定义，定义按键

struct AlarmTime{
  int h,m;
};

struct AlarmTime ab={99,99};
int keytimes=0, datatime=0;
unsigned int year=2021,month=11,day=11,week=1,hour=0, min=0, sec=0;	//定义时间计数值，分钟和秒

void IO_Init(void)
{
  PB_DDR |= 0x01;	//led0所接引脚初始化为推挽输出
  PB_CR1 |= 0x01;
  PB_ODR |= 0x01;

  //PA_DDR &= 0x8f;	//配置PA4，PA5，PA6为上拉输入                            
  PA_CR1 |= 0x70;
  
  PD_DDR_DDR4 = 1;
  PD_CR1_C14 = 1;
  PD_CR2_C24 = 0;
  beep = 1;

}


void is_one(int x,int y, int num, int size){
        if(num<10){
          OLED_ShowNum(x,y,0,1,size);
          OLED_ShowNum(x+size/2,y,num,1,size);
  }
        else{
          OLED_ShowNum(x,y,num,2,size);
        }
}


void show_time(int x, int y, int hour, int minute, int second){
        int size=16;
        is_one(x,y,hour, size);
        OLED_ShowString(x+size,y,":",size);
        is_one(x+size*3/2,y,minute, size);
        OLED_ShowString(x+5*size/2,y,":",size);
        is_one(x+3*size,y,second,size);
}

void show_date(int x, int y, int year, int month, int day, int week){
        int size=16;
        OLED_ShowNum(x,y,year,4,size);
        OLED_ShowChinese(x+size*2,y,0,size,1);
        OLED_ShowNum(x+size*3,y,month,2,size);
        OLED_ShowChinese(x+size*4,y,1,size,1);
        OLED_ShowNum(x+size*5,y,day,2,size);
        OLED_ShowChinese(x+size*6,y,2,size,1);
        OLED_ShowChinese(x+size*0,y+16,3,size,1);
        OLED_ShowChinese(x+size*1,y+16,4,size,1);
        switch(week)
        {
           case 0:OLED_ShowChinese(x+size*2,y+16,11,size,1);;break;//星期日
           case 1:OLED_ShowChinese(x+size*2,y+16,5,size,1);;break;//星期一
           case 2:OLED_ShowChinese(x+size*2,y+16,6,size,1);;break;//星期二
           case 3:OLED_ShowChinese(x+size*2,y+16,7,size,1);;break;//星期三
           case 4:OLED_ShowChinese(x+size*2,y+16,8,size,1);;break;//星期四
           case 5:OLED_ShowChinese(x+size*2,y+16,9,size,1);;break;//星期五
           case 6:OLED_ShowChinese(x+size*2,y+16,10,size,1);;break;//星期六
        }
        
}

void add(int x){
  if((x==0)&&(!key2)){
    delay_ms(10);
    year++;
    if(year>2100) year=1900;
  }
  if((x==1)&&(!key2)){
    delay_ms(10);
    month++;
    if(month>12) month=1;
  }
  if((x==2)&&(!key2)){
    delay_ms(10);
    day++;
    if(day>Monthnum(year, month)) day=1;
  }
  if((x==3)&&(!key2)){
    delay_ms(10);
    hour++;
    if(hour>24) ]k=0;
  }
  if((x==4)&&(!key2)){
    delay_ms(10);
    min++;
    if(min>60) min=0;
  }
  if((x==5)&&(!key2)){
    delay_ms(10);
    sec++;
    if(sec>60) sec=0;
  }
  while(!key2);
}

void del(int x){
  if((x==0)&&(!key1)){
    delay_ms(10);
    year--;
    if(year<1900) year=2100;
  }
  if((x==1)&&(!key1)){
    delay_ms(10);
    month--;
    if(month<1) month=12;
  }
  if((x==2)&&(!key1)){
    delay_ms(10);
    day--;
    if(day<1) day=Monthnum(year, month);
  }
  if((x==3)&&(!key1)){
    delay_ms(10);
    hour--;
    if(hour<0) hour=24;
  }
  if((x==4)&&(!key1)){
    delay_ms(10);
    min--;
    if(min<0) min=60;
  }
  if((x==5)&&(!key1)){
    delay_ms(10);
    sec--;
    if(sec<0) sec=60;
  }
  while(!key2);
}

void set_alarm(int x, int y, int datatime){

  ab.h=hour; ab.m=min; 
  while(1){
    if(!key0){
      delay_ms(30);
      datatime++;
      while(!key0);
    }
    show_date(x, y, year, month, day, week);
    show_time(x,y+32,ab.h,ab.m,0);
    OLED_ShowNum(x,y+48,datatime%2,1,16);
    OLED_Refresh_Gram();  //将所写的数据更新到OLED显存上)

    if(!key2){
      delay_ms(30);
      if(datatime%2) ab.h++;
      else ab.m++;
      while(!key2);
    }
    if(!key1){
      delay_ms(30);
      while(!key1);
      OLED_Clear();
      break;
    }
  }
}

void Query(int x, int y, int datatime)
{
  OLED_Clear();
  while(1){//显示时间
    if(!key0){
      delay_ms(30);
      datatime++;
      while(!key1);
    }
    show_date(x, y, year, month, day, week);
    show_time(x,y+32,hour,min,sec);
    OLED_ShowNum(x,y+48,datatime%6,1,16);
    OLED_Refresh_Gram();  //将所写的数据更新到OLED显存上
    if((ab.h==hour)&&(ab.m==min)){
      beep = 0;
      if(key0){
        delay_ms(5*1000);
        beep=1;
        delay_ms(2*1000);
        beep=0;
        delay_ms(5*1000);
        beep=1;
      }
      else beep=1;
    }
    add(datatime%6);
    del(datatime%6);
  if(!key3){
      delay_ms(30);
      OLED_Clear();
      OLED_ShowString(42,48, "alarm", 12);
      set_alarm(x, y, datatime);
    }
  }
}       


void main()
{   
  int x=0, y=0;
  
  GPIO_Init();
  OLED_Init();
  TIM2_Config();					//初始化TIM2
  __enable_interrupt();			//开总中断
  IO_Init();
  Query(x, y, datatime);
}  

