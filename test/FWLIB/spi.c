#include "iostm8s105c6.h"
#include "spi.h"


/*****************************
用IO口模拟SPI，选择OLED的模式
****************************/

void SPI_WriteByte(unsigned char data,unsigned char cmd)
{
   unsigned char i=0;
    OLED_DC =cmd;
    OLED_CLK=0;
    for(i=0;i<8;i++)
    {
        OLED_CLK=0;
        if(data&0x80)OLED_MOSI=1; //从高位到低位
        else OLED_MOSI=0;
        OLED_CLK=1;
        data<<=1;
    }
    OLED_CLK=1;
    OLED_DC=1;
}

/*************************************************************************/
/*函数功能: 写命令                                                        */
/*************************************************************************/

void WriteCmd(unsigned char cmd)
{    
  SPI_WriteByte(cmd,OLED_CMD);
}

/*************************************************************************/
/*函数功能: 写数据                                                        */
/*************************************************************************/

void WriteData(unsigned char data)
{    
  SPI_WriteByte(data,OLED_DATA);
}