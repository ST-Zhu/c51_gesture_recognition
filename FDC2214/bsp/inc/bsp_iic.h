#ifndef __BSP_IIC_H__
#define __BSP_IIC_H__


/**********************
引脚别名定义
***********************/	

sbit    SDA=P2^3;			//IIC数据引脚定义
sbit    SCL=P2^2;			//IIC时钟引脚定义


void WriteRegfdc2214(unsigned char add,unsigned int value);
unsigned int ReadRegfdc2214(unsigned char add);
void lcd_printf(uint8 *s,int temp_data);     
void InitSinglefdc2214(void);
#endif 