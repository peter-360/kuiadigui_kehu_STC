/*                        -- 渡河蚂蚁电子工作室 --                        */
/*
*   说    明: STC8A8KS4A12 DEMO程序
*   开发平台: STC15W408S     
*   淘宝网店: 
*
//  文件名：main.c                                                              
//  说明：供客户测试模块通信使用程序                                                                  
//  编写人员：Duhemayi                                                                   
//  编写日期：2018-09-16                                                               
//  程序维护：
//  维护记录：
//	版    本: V1.0
//                                                          
// 免责声明：该程序仅用于学习与交流 
// (c) Duhemayi Corporation. All rights reserved.     
******************************************************************************/
#include "uart.h"

bit busy;
char wptr;
char rptr;
char buffer[16];

/******************************************************************************/
// 函数名称：uart1Init 
// 输入参数：无 
// 输出参数：无 
// 函数功能：设置好定时器0的工作模式 
/******************************************************************************/
//void Uart1Init(void)
//{
//    SCON = 0x50;	   //8位波特率，允许接收
//    T2L = BRT;
//    T2H = BRT >> 8;
//    AUXR |= 0x15;
//    wptr = 0x00;
//    rptr = 0x00;
//    busy = 0;
//}

//void Uart1Init(void)		//115200bps@11.0592MHz
//{
//	SCON = 0x50;		//8???,?????
//	AUXR |= 0x01;		//??1?????2???????
//	AUXR |= 0x04;		//???2???Fosc,?1T
//	T2L = 0xE8;		//??????
//	T2H = 0xFF;		//??????
//	AUXR |= 0x10;		//?????2
//}


//void Uart1Init(void)		//9600bps@20.000MHz
//{
//	SCON = 0x50;		//8???,?????
//	AUXR |= 0x01;		//??1?????2???????
//	AUXR |= 0x04;		//???2???Fosc,?1T
//	T2L = 0xF7;		//??????
//	T2H = 0xFD;		//??????
//	AUXR |= 0x10;		//?????2
//}

void Uart1Init(void)		//9600bps@24.000MHz
{
	SCON = 0x50;		//8???,?????
	AUXR |= 0x01;		//??1?????2???????
	AUXR |= 0x04;		//???2???Fosc,?1T
	T2L = 0x8F;		//??????
	T2H = 0xFD;		//??????
	AUXR |= 0x10;		//?????2
}




/******************************************************************************/
// 函数名称：uartSendData 
// 输入参数：ucData: 发送字节 
// 输出参数：无 
// 函数功能：使用串口发送一个字节数据 
/******************************************************************************/
//void UartSend(uint8 dat)
//{
//    while (busy);
//    busy = 1;
//    SBUF = dat;
//}

void UartSend(uint8 dat)
{
  SBUF =dat;
	//SBUF =0x55;
	while(!TI);
	TI =0;
}

/******************************************************************************/
// 函数名称：uartSendString 
// 输入参数：pS: 字符串首地址 
// 输出参数：无 
// 函数功能：发送字符串通过串口输出 
/******************************************************************************/
void UartSendStr(uint8 *p)
{
    while (*p)
    {
        UartSend(*p++);
    }
}







unsigned char Uart1_index_flag=0,Uart1_index_flag_end=0;                //???????

unsigned char Uart1_Buffer[256];        //?????
unsigned char Uart1_Rx = 0;             //Uart1_Buffer??
unsigned char packerflag=0;
/******************************************************************************/
// 函数名称：time0ISR 
// 输入参数：无 
// 输出参数：无 
// 函数功能：串口0服务函数 
/******************************************************************************/
void Uart1Isr() interrupt 4 using 1
{
	uint8 ch;
	if (TI)
	{
			TI = 0;
			busy = 0;
	}
//	if (RI)
//	{
//			RI = 0;
//			buffer[wptr++] = SBUF;
//			wptr &= 0x0f;
//	}
	if (RI)
	{
		RI = 0;
		ch = SBUF;
//		UartSend(ch);
		
		
		Uart1_Buffer[Uart1_Rx] = ch; 
		
		if(Uart1_Rx>13)//4+5+4
			Uart1_Rx=0;
		
		if(('s'== Uart1_Buffer[0])
			&&('t'== Uart1_Buffer[1])
			&&('a'== Uart1_Buffer[2])
			&&('r'== Uart1_Buffer[3])
			&& (Uart1_Rx >4))
		{

			//debug_uart_send_datas(Uart1_Buffer,4);
//			SEGGER_RTT_printf(0, "1-Uart1_Buffer[Uart1_Rx] = %02x, Uart1_Rx=%d\n",
//															Uart1_Buffer[Uart1_Rx],Uart1_Rx);      //RTT打印
			switch(Uart1_index_flag_end)
			{
				case 0:
					if(ch == 'e')//process
					{
//						SEGGER_RTT_printf(0, "2-Uart1_Buffer[Uart1_Rx] = %02x, Uart1_Rx=%d\n",
//						Uart1_Buffer[Uart1_Rx],Uart1_Rx);      //RTT打印

						Uart1_index_flag_end =1;
					}
					break;
				case 1:
					if(ch == 'n')//process
						Uart1_index_flag_end =2;
					break;
				case 2:
					if(ch == 'd')//process
						Uart1_index_flag_end =3;
					break;
				case 3:
					if(ch == 'o')//process
					{
						//TIM3_Set(0);
//						SEGGER_RTT_printf(0, "3-Uart1_Buffer[Uart1_Rx] = %02x, Uart1_Rx=%d\n",
//												Uart1_Buffer[Uart1_Rx],Uart1_Rx);      //RTT打印
//						debug_uart_send_datas(Uart1_Buffer,13);
//						debug_uart_send_datas(&Uart1_Rx,1);
						
						Uart1_index_flag_end =0;
						packerflag = 1;                      //

					}
					break;
				default:
					break;
						
				
			}
		
		
		}
		else//timer interrrupt, Uart1_Rx =0;
		{
			TR0 = 1;		//---on----
		}
		Uart1_Rx++;
		//UartSend(Uart1_Rx);
	}
}

/******************************************************************************/
// 函数名称：void UART1_IOPORT_CHANGE(void)
// 输入参数：无 
// 输出参数：无 
// 函数功能：串口一的IO口切换
/******************************************************************************/
void UART1_IOPORT_CHANGE(void)
{
    P_SW1 = 0x00;                               //RXD/P3.0, TXD/P3.1
//  P_SW1 = 0x40;                               //RXD_2/P3.6, TXD_2/P3.7
//  P_SW1 = 0x80;                               //RXD_3/P1.6, TXD_3/P1.7
//  P_SW1 = 0xc0;                               //RXD_4/P4.3, TXD_4/P4.4

}








