#include "iostm8s105c6.h"
#include "gpio.h"
#ifndef __SPI_H
#define __SPI_H


#define u32 unsigned int 
#define u16 unsigned short 
#define s32 int 
#define s16 short int 
#define u8  unsigned char 
#define s8  char


#define OLED_CMD 0 //��������
#define OLED_DATA 1 //��������
#define OLED_CLK PB_ODR_ODR5   //d0
#define OLED_MOSI  PB_ODR_ODR4  // MOSI     d1
#define OLED_RST PD_ODR_ODR0    // RET��λ    ret
#define OLED_DC PG_ODR_ODR1   // ����|����    dc  ��0��������1�������ݣ�


void SPI_WriteByte(unsigned char addr,unsigned char data); //��Ĵ�����ַдһ��byte������
void WriteCmd(unsigned char cmd); //д����
void WriteData(unsigned char data); //д����


#endif