#include "gpio.h"

/**********
初始化IO口
**********/

void GPIO_Init()
{
  PB_DDR |= 0X30;
  PB_CR1 |= 0X30;
  PB_CR2 |= 0X30;//PB4,PB5输出模式
  
  PD_DDR |= 0X01;
  PD_CR1 |= 0X01;
  PD_CR2 |= 0X01;//PD0输出模式
  
  PG_DDR |= 0X02;
  PG_CR1 |= 0X02;
  PG_CR2 |= 0X02;//PG1输出模式
  
  PC_DDR |= 0X04;
  PC_CR1 |= 0X04;
  PC_CR2 |= 0X04;
  PC_ODR &= 0XFB;//RGB灯，PC3置0
}