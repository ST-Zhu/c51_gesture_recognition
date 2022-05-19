#include "bsp.h"
#include "intrins.h"
#include "codetab.h"
#include "LQ12864.h"

sbit KEY1=P0^0;
sbit KEY2=P0^1;
sbit KEY3=P0^2;
sbit KEY4=P0^3;

int temp_CH0,temp_CH1,temp_CH2,temp_CH3;

void Init()
{
	delay_ms(500);		//上电延时		
	InitSinglefdc2214();//初始化
	delay_ms(150);
	OLED_Init(); //OLED初始化
}

void Read()
{
	temp_CH0=ReadRegfdc2214(0x00);
	temp_CH1=ReadRegfdc2214(0x02);
	temp_CH2=ReadRegfdc2214(0x04);
	temp_CH3=ReadRegfdc2214(0x06);		//读取数据
}

void Juger_one()
{
	OLED_P16x16Ch(24,0,1);
	OLED_P16x16Ch(40,0,2);
	OLED_P16x16Ch(57,0,3);
	OLED_P16x16Ch(74,0,4);
	OLED_P8x16Str(91,0,"1");		//OLED显示判决模式1
	
	if((temp_CH0>300)&&(temp_CH0<460)&&(temp_CH1>460)&&(temp_CH1<500)&&(temp_CH2>470)&&(temp_CH2<500)&&(temp_CH3>460)&&(temp_CH3<500))//石头
	{
		OLED_P16x16Ch(40,2,9);
		OLED_P16x16Ch(57,2,10);		//石头
	}
	if((temp_CH0>480)&&(temp_CH0<500)&&(temp_CH1>400)&&(temp_CH1<460)&&(temp_CH2>400)&&(temp_CH2<470)&&(temp_CH3>460)&&(temp_CH3<500))//剪刀
	{
		OLED_P16x16Ch(40,2,16);
		OLED_P16x16Ch(57,2,17);		//剪刀
	}
	if((temp_CH0>300)&&(temp_CH0<460)&&(temp_CH1>300)&&(temp_CH1<440)&&(temp_CH2>300)&&(temp_CH2<450)&&(temp_CH3>300)&&(temp_CH3<440))//布
	{
		OLED_P16x16Ch(40,2,23);
		OLED_P16x16Ch(57,2,24);		//布
	}
	delay_ms(100);
	OLED_P16x16Ch(40,2,26);
	OLED_P16x16Ch(57,2,27);
}

void Juger_two()
{
	OLED_P16x16Ch(24,0,1);
	OLED_P16x16Ch(40,0,2);
	OLED_P16x16Ch(57,0,3);
	OLED_P16x16Ch(74,0,4);
	OLED_P8x16Str(91,0,"2");		//OLED显示判决模式2
	
	if((temp_CH0>480)&&(temp_CH0<500)&&(temp_CH1>400)&&(temp_CH1<460)&&(temp_CH2>470)&&(temp_CH2<500)&&(temp_CH3>460)&&(temp_CH3<500))//1
	{
		OLED_P8x16Str(40,2,"1");
	}
	if((temp_CH0>480)&&(temp_CH0<500)&&(temp_CH1>400)&&(temp_CH1<460)&&(temp_CH2>400)&&(temp_CH2<470)&&(temp_CH3>460)&&(temp_CH3<500))//2
	{
		OLED_P8x16Str(40,2,"2");
	}
	if((temp_CH0>480)&&(temp_CH0<500)&&(temp_CH1>400)&&(temp_CH1<450)&&(temp_CH2>300)&&(temp_CH2<460)&&(temp_CH3>300)&&(temp_CH3<450))//3
	{
		OLED_P8x16Str(40,2,"3");
	}
	if((temp_CH0>480)&&(temp_CH0<500)&&(temp_CH1>300)&&(temp_CH1<400)&&(temp_CH2>300)&&(temp_CH2<460)&&(temp_CH3>300)&&(temp_CH3<450))//4
	{
		OLED_P8x16Str(40,2,"4");
	}
	if((temp_CH0>300)&&(temp_CH0<460)&&(temp_CH1>300)&&(temp_CH1<440)&&(temp_CH2>300)&&(temp_CH2<450)&&(temp_CH3>300)&&(temp_CH3<440))//5
	{
		OLED_P8x16Str(40,2,"5");
	}
	delay_ms(100);
	OLED_P16x16Ch(40,2,26);
}

void Train_one()
{
	OLED_P16x16Ch(24,0,29);
	OLED_P16x16Ch(40,0,30);
	OLED_P16x16Ch(57,0,31);
	OLED_P16x16Ch(74,0,32);
	OLED_P8x16Str(91,0,"1");		//OLED显示训练模式1
	
	delay_ms(1500);
	OLED_P16x16Ch(40,2,9);
	OLED_P16x16Ch(57,2,10);		//石头
	delay_ms(3000);
	
	OLED_P16x16Ch(40,2,16);
	OLED_P16x16Ch(57,2,17);		//剪刀
	delay_ms(3000);
	
	OLED_P16x16Ch(40,2,23);
	OLED_P16x16Ch(57,2,24);		//布
	delay_ms(3000);
	
	OLED_CLS();//清屏
	delay_ms(3000);
}

void Train_two()
{
	OLED_P16x16Ch(24,0,29);
	OLED_P16x16Ch(40,0,30);
	OLED_P16x16Ch(57,0,31);
	OLED_P16x16Ch(74,0,32);
	OLED_P8x16Str(91,0,"2");		//OLED显示训练模式2
	
	delay_ms(1500);
	OLED_P8x16Str(40,2,"1");
	delay_ms(3000);
	
	OLED_P8x16Str(40,2,"2");
	delay_ms(3000);
	
	OLED_P8x16Str(40,2,"3");
	delay_ms(3000);
	
	OLED_P8x16Str(40,2,"4");
	delay_ms(3000);
	
	OLED_P8x16Str(40,2,"5");
	delay_ms(3000);
	
	OLED_CLS();//清屏
	delay_ms(2000);
}

void main()
{
	Init();
	while(1)
	{
		if(KEY1==0)//功能一
		{
			delay(30);
			if(KEY1==0)
			{
				while(KEY1==0);
				while(KEY1!=0)
				{
					Read();
					Juger_one();//判决1
				}
			}
		}
		if(KEY2==0)//功能二
		{
			delay(30);
			if(KEY2==0)
			{
				while(KEY2==0);
				while(KEY2!=0)
				{
					Read();
					Juger_two();//判决2
				}
			}
		}
		if(KEY3==0)//功能三
		{
			delay(30);
			if(KEY3==0)
			{
				while(KEY3==0);
				Train_one();//训练1
				while(KEY3!=0)
				{
					Read();
					Juger_one();//判决1
				}
			}
		}
		if(KEY4==0)//功能四
		{
			delay(30);
			if(KEY4==0)
			{
				while(KEY4==0);
				Train_two();//训练2
				while(KEY4!=0)
				{
					Read();
					Juger_two();//判决2
				}
			}
		}
		OLED_CLS();//清屏
		delay(1000);
	}
}
//		(temp_CH0>480)&&(temp_CH0<500)&&(temp_CH1>460)&&(temp_CH1<500)&&(temp_CH2>470)&&(temp_CH2<500)&&(temp_CH3>460)&&(temp_CH3<500)
