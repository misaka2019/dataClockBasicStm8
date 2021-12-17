#include "gpio.h"

/**********
³õÊ¼»¯IO¿Ú
**********/

void GPIO_Init()
{
  PB_DDR |= 0X30;
  PB_CR1 |= 0X30;
  PB_CR2 |= 0X30;
  
  PD_DDR |= 0X01;
  PD_CR1 |= 0X01;
  PD_CR2 |= 0X01;
  
  PG_DDR |= 0X02;
  PG_CR1 |= 0X02;
  PG_CR2 |= 0X02;
  
  PC_DDR |= 0X04;
  PC_CR1 |= 0X04;
  PC_CR2 |= 0X04;
  PC_ODR &= 0XFB;
}