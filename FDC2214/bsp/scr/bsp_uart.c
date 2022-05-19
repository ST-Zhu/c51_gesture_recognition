#include "bsp.h"
/**************************************
功能描述：串口初始化(串口1)
入口参数：无
返回值：无
备注：波特率9600bps   晶振11.0592MHz
***************************************/
void UartInit(void)		
{
	PCON &= 0x3f;		//波特率不倍速，串行口工作方式由SM0、SM1决定	
	SCON = 0x50;		//8位数据,可变波特率
	AUXR |= 0x40;		//定时器1时钟为Fosc,即1T
	AUXR &= 0xfe;		//串口1选择定时器1为波特率发生器
	TMOD &= 0x0f;		//清除定时器1模式位
	TMOD |= 0x20;		//设定定时器1为8位自动重装方式
	TL1 = 0xDC;		  //设定定时初值
	TH1 = 0xDC;		  //设定定时器重装值
	ET1 = 0;		    //禁止定时器1中断
	TR1 = 1;		    //启动定时器1
}

/**************************************
功能描述：串口1发送数据
入口参数：uint8 ch
返回值：无
***************************************/
void U1SendData(uint8 ch)
{
    SBUF = ch;                  //写数据到UART数据寄存器
		while(TI == 0);             //在停止位没有发送时，TI为0即一直等待
		TI = 0;                     //清除TI位（该位必须软件清零）
}

/**************************************
功能描述：串口1发送字符串
入口参数：uint8 *s
返回值：无
***************************************/
void U1SendString(uint8 *s)
{
    while (*s)                    //检测字符串结束标志
    {
        U1SendData(*s++);         //发送当前字符
    }
}


/***************************************************************************
 * 描  述 : 串口1中断服务函数
 * 入  参 : 无
 * 返回值 : 无
 **************************************************************************/
void Uart1() interrupt UART1_VECTOR using 1
{
	ES = 0;                       // 串口1中断关闭
	if (RI)                       //串行接收到停止位的中间时刻时，该位置1
  {
      RI = 0;                   //清除RI位 （该位必须软件清零）         
   }
   if (TI)                    //在停止位开始发送时，该位置1
   {
      TI = 0;                 //清除TI位（该位必须软件清零）
   }
	 ES =  1;                   // 串口1中断打开
}

