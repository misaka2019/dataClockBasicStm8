#include "iostm8s105c6.h"
#include "spi.h"
#include "gpio.h"

#ifndef __OLED_H
#define __OLED_H

void OLED_Init(void);//初始化OLED
void OLED_ON(void);//唤醒OLED
void OLED_OFF(void);//OLED休眠
void OLED_Refresh_Gram(void);//更新显存到OLED
void OLED_Clear(void);//清屏
void OLED_DrawPoint(u8 x,u8 y,u8 t);//画点
void OLED_Fill(u8 x1,u8 y1,u8 x2,u8 y2,u8 dot);//填充
void OLED_ShowChar(u8 x,u8 y,u8 chr,u8 size,u8 mode);//显示字符
void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 size);//显示2个数字
void OLED_ShowString(u8 x,u8 y,const u8 *p,u8 size);//显示字符串
void OLED_ShowChinese(u8 x, u8 y,  u8 num, u8 size,u8 mode);
#endif