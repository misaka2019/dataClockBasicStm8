#include "iostm8s105c6.h"
#include "spi.h"
#include "gpio.h"

#ifndef __OLED_H
#define __OLED_H

void OLED_Init(void);//��ʼ��OLED
void OLED_ON(void);//����OLED
void OLED_OFF(void);//OLED����
void OLED_Refresh_Gram(void);//�����Դ浽OLED
void OLED_Clear(void);//����
void OLED_DrawPoint(u8 x,u8 y,u8 t);//����
void OLED_Fill(u8 x1,u8 y1,u8 x2,u8 y2,u8 dot);//���
void OLED_ShowChar(u8 x,u8 y,u8 chr,u8 size,u8 mode);//��ʾ�ַ�
void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 size);//��ʾ2������
void OLED_ShowString(u8 x,u8 y,const u8 *p,u8 size);//��ʾ�ַ���

#endif