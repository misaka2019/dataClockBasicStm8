#include "iostm8s105c6.h"
#include "spi.h"


/*****************************
��IO��ģ��SPI��ѡ��OLED��ģʽ
****************************/

void SPI_WriteByte(unsigned char data,unsigned char cmd)
{
   unsigned char i=0;
    OLED_DC =cmd;
    OLED_CLK=0;
    for(i=0;i<8;i++)
    {
        OLED_CLK=0;
        if(data&0x80)OLED_MOSI=1; //�Ӹ�λ����λ
        else OLED_MOSI=0;
        OLED_CLK=1;
        data<<=1;
    }
    OLED_CLK=1;
    OLED_DC=1;
}

/*************************************************************************/
/*��������: д����                                                        */
/*************************************************************************/

void WriteCmd(unsigned char cmd)
{    
  SPI_WriteByte(cmd,OLED_CMD);
}

/*************************************************************************/
/*��������: д����                                                        */
/*************************************************************************/

void WriteData(unsigned char data)
{    
  SPI_WriteByte(data,OLED_DATA);
}