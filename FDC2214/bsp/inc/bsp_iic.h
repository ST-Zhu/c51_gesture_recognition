#ifndef __BSP_IIC_H__
#define __BSP_IIC_H__


/**********************
���ű�������
***********************/	

sbit    SDA=P2^3;			//IIC�������Ŷ���
sbit    SCL=P2^2;			//IICʱ�����Ŷ���


void WriteRegfdc2214(unsigned char add,unsigned int value);
unsigned int ReadRegfdc2214(unsigned char add);
void lcd_printf(uint8 *s,int temp_data);     
void InitSinglefdc2214(void);
#endif 