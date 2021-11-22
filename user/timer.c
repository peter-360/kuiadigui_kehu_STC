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
#include "timer.h"

//测试工作频率为11.0592MHz
uint16 Timer_CNT;
uint16 Timer_CNT_OpenAll;
uint8 Timer_flag;
uint8 lock_channel=1;

//void Timer0_Init(void)
//{
//    TMOD = 0x00;                                //模式0
//    TL0 = 0x66;                                 //65536-11.0592M/12/1000	定时1ms
//    TH0 = 0xfc;
//    TR0 = 1;                                    //启动定时器
//    ET0 = 1;                                    //使能定时器中断
//    EA = 1;
//}

void Timer0_Init(void)		//10000??@24.000MHz
{
	AUXR &= 0x7F;		//?????12T??
//	TMOD &= 0xF0;		//???????
	TMOD = 0x00;
//	TL0 = 0xE0;		//??????
//	TH0 = 0xB1;		//??????  10ms
	TL0 = 0xA0;		//??????
	TH0 = 0x15;		//?????? 30ms
	
	ET0 = 1;  
	TF0 = 0;		//??TF0??
	TR0 = 0;		//---off-----???0????
}

extern void debug_uart_send_data1(uint8_t str);
extern u16	RX_write;
extern u8 	xdata RX1_Buffer[];
void TM0_Isr() interrupt 1 using 1
{
	Timer_CNT++;
	//debug_uart_send_data1(Timer_CNT);
	if(Timer_CNT >= 30)
	{
		Timer_CNT =0;
		TF0 = 0;
		TR0 = 0;

		debug_uart_send_data1(Uart1_Rx);

		Uart1_Rx =0 ;
		
//		RX_write = 0;	//add
//		memset(RX1_Buffer,0,RX_Length);//add
		//LED = !LED;
	}
	
	//Timer0_Init();
	//TR0 = 1;                       
}

//void TM0_Isr() interrupt 1 using 1
//{
//	Timer_CNT++;
//	if(Timer_CNT >= 5)
//	{
//		Timer_CNT = 0;
//		LED = !LED;			 //测试端口
//	}                         
//}


void TM1_Isr() interrupt 3 using 1
{
	TF1 = 0;		//??TF1??
	TR1 = 0;		//???1????
	
	
//  Timer_CNT++;
//	if(Timer_CNT >= 500)
//	{
//		Timer_CNT = 0;
//		LED = !LED;			 //测试端口
//	}                                  
}

//void Timer1_Init(void)
//{
//    TMOD = 0x00;                                //模式0
//    TL1 = 0x66;                                 //65536-11.0592M/12/1000
//    TH1 = 0xfc;
//    TR1 = 1;                                    //启动定时器
//    ET1 = 1;                                    //使能定时器中断
//    EA = 1;
//}

void Timer1Init(void)		//10??@20.000MHz
{
	AUXR &= 0xBF;		//?????12T??
	TMOD = 0x00;
	TL1 = 0xE5;		//??????
	TH1 = 0xBE;		//??????
	
	ET1 = 1;
	TF1 = 0;		//??TF1??
	TR1 = 0;		//???1????
}


void TM2_Isr() interrupt 12 using 1
{
    AUXINTIF &= ~T2IF;                          //清中断标志
	Timer_CNT++;
	if(Timer_CNT >= 300)
	{
		Timer_CNT = 0;
		LED = !LED;			 //测试端口
	} 
}

void Timer2_Init(void)
{
    T2L = 0x66;                                 //65536-11.0592M/12/1000
    T2H = 0xfc;
    AUXR = 0x10;                                //启动定时器
    IE2 = ET2;                                  //使能定时器中断
    EA = 1;
}


void timer_open_init()
{
	T4T3M &= ~0x08;		//定时器3 close
	T3L = 0x30;		//设置定时初值 1ms
	T3H = 0xF8;		//设置定时初值	
	T4T3M |= 0x08;		//定时器3开始计时
}
void timer_close_init()
{
	T4T3M &= ~0x08;		//定时器3 close
	T3L = 0x80;		//设置定时初值  8ms
	T3H = 0xC1;		//设置定时初值
	T4T3M |= 0x08;		//定时器3开始计时
}


void TM3_Isr() interrupt 19 using 1
{                                
	//测试端口
	AUXINTIF &= ~T3IF;                          //清中断标志
	Timer_CNT_OpenAll++;
	// UartSendStr("----11---\r\n");
	// debug_uart_send_data1(Timer_CNT_OpenAll);
	// feed_dog();
	if(Timer_CNT_OpenAll >= 100)//20
	{
		// feed_dog();
		// UartSendStr("22\r\n");
		// TF1 = 0;		//清除TF1标志
		// // AUXINTIF &= ~T1IF;
		// TR1=0;
		Timer_CNT_OpenAll = 0;
		// LED = !LED;			 //测试端口

		// lock_channel++;
		debug_uart_send_data1(lock_channel);
		if(lock_channel <=24)
		{
			switch(lock_channel)
			{
				// debug_uart_send_data1(lock_channel);
				case 1://power on
					
					if(0==Timer_flag)
					{
						Timer_flag =1;
						debug_uart_send_data1(0x11);
						GO_1=1; 					//open
						timer_close_init();

					}
					else
					{
						Timer_flag =0;
						debug_uart_send_data1(0x12);
						GO_1=0;
						timer_open_init();
						lock_channel++;						
					}
					break;


				case 2://
					if(0==Timer_flag)
					{
						Timer_flag =1;
						debug_uart_send_data1(0x21);
						GO_2=1; 					//open
						timer_close_init();

					}
					else
					{
						Timer_flag =0;
						debug_uart_send_data1(0x22);
						GO_2=0;
						timer_open_init();
						lock_channel++;						
					}
					break;
		
	
				case 3:
					if(0==Timer_flag)
					{
						Timer_flag =1;
						debug_uart_send_data1(0x21);
						GO_3=1; 					//open
						timer_close_init();

					}
					else
					{
						Timer_flag =0;
						debug_uart_send_data1(0x22);
						GO_3=0;						//close
						timer_open_init();
						lock_channel++;						
					}
					break;
				case 4:
					if(0==Timer_flag)
					{
						Timer_flag =1;
						debug_uart_send_data1(0x21);
						GO_4=1; 					//open
						timer_close_init();

					}
					else
					{
						Timer_flag =0;
						debug_uart_send_data1(0x22);
						GO_4=0;						//close
						timer_open_init();
						lock_channel++;						
					}
					break;
				case 5:
					if(0==Timer_flag)
					{
						Timer_flag =1;
						debug_uart_send_data1(0x21);
						GO_5=1; 					//open
						timer_close_init();

					}
					else
					{
						Timer_flag =0;
						debug_uart_send_data1(0x22);
						GO_5=0;						//close
						timer_open_init();
						lock_channel++;						
					}
					break;
				case 6:
					if(0==Timer_flag)
					{
						Timer_flag =1;
						debug_uart_send_data1(0x21);
						GO_6=1; 					//open
						timer_close_init();

					}
					else
					{
						Timer_flag =0;
						debug_uart_send_data1(0x22);
						GO_6=0;						//close
						timer_open_init();
						lock_channel++;						
					}
					break;
				case 7:
					if(0==Timer_flag)
					{
						Timer_flag =1;
						debug_uart_send_data1(0x21);
						GO_7=1; 					//open
						timer_close_init();

					}
					else
					{
						Timer_flag =0;
						debug_uart_send_data1(0x22);
						GO_7=0;						//close
						timer_open_init();
						lock_channel++;						
					}
					break;
				case 8:
					if(0==Timer_flag)
					{
						Timer_flag =1;
						debug_uart_send_data1(0x21);
						GO_8=1; 					//open
						timer_close_init();

					}
					else
					{
						Timer_flag =0;
						debug_uart_send_data1(0x22);
						GO_8=0;						//close
						timer_open_init();
						lock_channel++;						
					}
					break;
				case 9:
					if(0==Timer_flag)
					{
						Timer_flag =1;
						debug_uart_send_data1(0x21);
						GO_9=1; 					//open
						timer_close_init();

					}
					else
					{
						Timer_flag =0;
						debug_uart_send_data1(0x22);
						GO_9=0;						//close
						timer_open_init();
						lock_channel++;						
					}
					break;
				case 10:
					if(0==Timer_flag)
					{
						Timer_flag =1;
						debug_uart_send_data1(0x21);
						GO_10=1; 					//open
						timer_close_init();

					}
					else
					{
						Timer_flag =0;
						debug_uart_send_data1(0x22);
						GO_10=0;						//close
						timer_open_init();
						lock_channel++;						
					}
					break;
				case 11:
					if(0==Timer_flag)
					{
						Timer_flag =1;
						debug_uart_send_data1(0x21);
						GO_11=1; 					//open
						timer_close_init();

					}
					else
					{
						Timer_flag =0;
						debug_uart_send_data1(0x22);
						GO_11=0;						//close
						timer_open_init();
						lock_channel++;						
					}
					break;
				case 12:
					if(0==Timer_flag)
					{
						Timer_flag =1;
						debug_uart_send_data1(0x21);
						GO_12=1; 					//open
						timer_close_init();

					}
					else
					{
						Timer_flag =0;
						debug_uart_send_data1(0x22);
						GO_12=0;						//close
						timer_open_init();
						lock_channel++;						
					}
					break;
				case 13:
					if(0==Timer_flag)
					{
						Timer_flag =1;
						debug_uart_send_data1(0x21);
						GO_13=1; 					//open
						timer_close_init();

					}
					else
					{
						Timer_flag =0;
						debug_uart_send_data1(0x22);
						GO_13=0;						//close
						timer_open_init();
						lock_channel++;						
					}
					break;
				case 14:
					if(0==Timer_flag)
					{
						Timer_flag =1;
						debug_uart_send_data1(0x21);
						GO_14=1; 					//open
						timer_close_init();

					}
					else
					{
						Timer_flag =0;
						debug_uart_send_data1(0x22);
						GO_14=0;						//close
						timer_open_init();
						lock_channel++;						
					}
					break;
				case 15:
					if(0==Timer_flag)
					{
						Timer_flag =1;
						debug_uart_send_data1(0x21);
						GO_15=1; 					//open
						timer_close_init();

					}
					else
					{
						Timer_flag =0;
						debug_uart_send_data1(0x22);
						GO_15=0;						//close
						timer_open_init();
						lock_channel++;						
					}
					break;
				case 16:
					if(0==Timer_flag)
					{
						Timer_flag =1;
						debug_uart_send_data1(0x21);
						GO_16=1; 					//open
						timer_close_init();

					}
					else
					{
						Timer_flag =0;
						debug_uart_send_data1(0x22);
						GO_16=0;						//close
						timer_open_init();
						lock_channel++;						
					}
					break;
				case 17:
					if(0==Timer_flag)
					{
						Timer_flag =1;
						debug_uart_send_data1(0x21);
						GO_17=1; 					//open
						timer_close_init();

					}
					else
					{
						Timer_flag =0;
						debug_uart_send_data1(0x22);
						GO_17=0;						//close
						timer_open_init();
						lock_channel++;						
					}
					break;
				case 18:
					if(0==Timer_flag)
					{
						Timer_flag =1;
						debug_uart_send_data1(0x21);
						GO_18=1; 					//open
						timer_close_init();

					}
					else
					{
						Timer_flag =0;
						debug_uart_send_data1(0x22);
						GO_18=0;						//close
						timer_open_init();
						lock_channel++;						
					}
					break;
				case 19:
					if(0==Timer_flag)
					{
						Timer_flag =1;
						debug_uart_send_data1(0x21);
						GO_19=1; 					//open
						timer_close_init();

					}
					else
					{
						Timer_flag =0;
						debug_uart_send_data1(0x22);
						GO_19=0;						//close
						timer_open_init();
						lock_channel++;						
					}
					break;
				case 20:
					if(0==Timer_flag)
					{
						Timer_flag =1;
						debug_uart_send_data1(0x21);
						GO_20=1; 					//open
						timer_close_init();

					}
					else
					{
						Timer_flag =0;
						debug_uart_send_data1(0x22);
						GO_20=0;						//close
						timer_open_init();
						lock_channel++;						
					}
					break;
				case 21:
					if(0==Timer_flag)
					{
						Timer_flag =1;
						debug_uart_send_data1(0x21);
						GO_21=1; 					//open
						timer_close_init();

					}
					else
					{
						Timer_flag =0;
						debug_uart_send_data1(0x22);
						GO_21=0;
						timer_open_init();
						lock_channel++;						
					}
					break;
				case 22:
					if(0==Timer_flag)
					{
						Timer_flag =1;
						debug_uart_send_data1(0x21);
						GO_22=1; 					//open
						timer_close_init();

					}
					else
					{
						Timer_flag =0;
						debug_uart_send_data1(0x22);
						GO_22=0;
						timer_open_init();
						lock_channel++;						
					}
					break;
				case 23:
					if(0==Timer_flag)
					{
						Timer_flag =1;
						debug_uart_send_data1(0x21);
						GO_23=1; 					//open
						timer_close_init();

					}
					else
					{
						Timer_flag =0;
						debug_uart_send_data1(0x22);
						GO_23=0;
						timer_open_init();
						lock_channel++;						
					}
					break;
				case 24:
					if(0==Timer_flag)
					{
						Timer_flag =1;
						debug_uart_send_data1(0x21);
						GO_24=1; 					//open
						timer_close_init();

					}
					else
					{
						Timer_flag =0;
						debug_uart_send_data1(0x22);
						GO_24=0;
						timer_open_init();
						lock_channel++;						
					}
					break;
				
				
				default:
					lock_channel++;
					break;
			}
			// LED2_CTL = 0;
			if(0==Timer_flag)
				lock_all_off();
			// TIM4_Set(1);			//TIM 
		}
		else
		{
			debug_uart_send_data1(0x55);
			T4T3M &= ~0x08;		//定时器3 close
			// TIM4_Set(0);			//TIM 
			// IE2 &= ~0x04;                    //关定时器2中断
			lock_channel=1;
			Timer_flag =0;
			// key_mode = 1;
		}







	}
}




// void TM3_Isr() interrupt 19 using 1
// {
//     AUXINTIF &= ~T3IF;                          //清中断标志

// 	Timer_CNT++;
// 	if(Timer_CNT >= 1000)//10*100  700
// 	{
// 		UartSendStr("11\r\n");
// 		Timer_CNT = 0;
// 		// LED = !LED;			 //测试端口


// 		if(0==Timer_flag)
// 		{
// 			timer_open_init();
// 		}
// 		else
// 		{
// 			timer_close_init();
// 		}
// 	}
// }

void Timer3_Init(void)
{
	T4T3M &= 0xFD;		//定时器时钟12T模式   add
    // T3L = 0x66;                                 //65536-11.0592M/12/1000
    // T3H = 0xfc;
	T3L = 0xE0;		//设置定时初值
	T3H = 0xB1;		//设置定时初值
    // T4T3M = 0x08;                               //启动定时器
	// T4T3M |= 0x08;		//定时器3开始计时
    IE2 = ET3;                                  //使能定时器中断
    EA = 1;
}

void TM4_Isr() interrupt 20 using 1
{                                //测试端口
    AUXINTIF &= ~T4IF;                          //清中断标志
	Timer_CNT++;
	if(Timer_CNT >= 1000)
	{
		Timer_CNT = 0;
		LED = !LED;			 //测试端口
	}
}

void Timer4_Init(void)
{
    T4L = 0x66;                                 //65536-11.0592M/12/1000
    T4H = 0xfc;
    T4T3M = 0x80;                               //启动定时器
    IE2 = ET4;                                  //使能定时器中断
    EA = 1;
}








