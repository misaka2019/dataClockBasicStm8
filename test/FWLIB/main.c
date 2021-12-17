#include "iostm8s105c6.h"
#include "gpio.h"
#include "oled.h"
#include "spi.h"




void main( void )
{
  GPIO_Init();
  OLED_Init();
  while(1)
  {
    OLED_ShowString(0,0,"Welcome To",24);  
    OLED_ShowString(0,24, "GDUT_ELC",16);  
    OLED_ShowString(0,40,"Edit TIME: 2018/11/24",12);  
    OLED_ShowString(0,52,"Writer:",12);  
    OLED_ShowString(42,52,"Mr.Lu",12);  
    OLED_Refresh_Gram();  //将所写的数据更新到OLED显存上
  }
}