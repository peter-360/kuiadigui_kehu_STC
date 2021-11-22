/*                        -- �ɺ����ϵ��ӹ����� --                        */
/*
*   ˵    ��: STC8A8KS4A12 DEMO����
*   ����ƽ̨: STC15W408S     
*   �Ա�����: 
*
//  �ļ�����main.c                                                              
//  ˵�������ͻ�����ģ��ͨ��ʹ�ó���                                                                  
//  ��д��Ա��Duhemayi                                                                   
//  ��д���ڣ�2018-09-16                                                               
//  ����ά����
//  ά����¼��
//	��    ��: V1.0
//                                                          
// �����������ó��������ѧϰ�뽻�� 
// (c) Duhemayi Corporation. All rights reserved.     
******************************************************************************/
#include "timer.h"

//���Թ���Ƶ��Ϊ11.0592MHz
uint16 Timer_CNT;
uint16 Timer_CNT_OpenAll;
uint8 Timer_flag;
uint8 lock_channel=1;

//void Timer0_Init(void)
//{
//    TMOD = 0x00;                                //ģʽ0
//    TL0 = 0x66;                                 //65536-11.0592M/12/1000	��ʱ1ms
//    TH0 = 0xfc;
//    TR0 = 1;                                    //������ʱ��
//    ET0 = 1;                                    //ʹ�ܶ�ʱ���ж�
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
//		LED = !LED;			 //���Զ˿�
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
//		LED = !LED;			 //���Զ˿�
//	}                                  
}

//void Timer1_Init(void)
//{
//    TMOD = 0x00;                                //ģʽ0
//    TL1 = 0x66;                                 //65536-11.0592M/12/1000
//    TH1 = 0xfc;
//    TR1 = 1;                                    //������ʱ��
//    ET1 = 1;                                    //ʹ�ܶ�ʱ���ж�
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
    AUXINTIF &= ~T2IF;                          //���жϱ�־
	Timer_CNT++;
	if(Timer_CNT >= 300)
	{
		Timer_CNT = 0;
		LED = !LED;			 //���Զ˿�
	} 
}

void Timer2_Init(void)
{
    T2L = 0x66;                                 //65536-11.0592M/12/1000
    T2H = 0xfc;
    AUXR = 0x10;                                //������ʱ��
    IE2 = ET2;                                  //ʹ�ܶ�ʱ���ж�
    EA = 1;
}


void timer_open_init()
{
	T4T3M &= ~0x08;		//��ʱ��3 close
	T3L = 0x30;		//���ö�ʱ��ֵ 1ms
	T3H = 0xF8;		//���ö�ʱ��ֵ	
	T4T3M |= 0x08;		//��ʱ��3��ʼ��ʱ
}
void timer_close_init()
{
	T4T3M &= ~0x08;		//��ʱ��3 close
	T3L = 0x80;		//���ö�ʱ��ֵ  8ms
	T3H = 0xC1;		//���ö�ʱ��ֵ
	T4T3M |= 0x08;		//��ʱ��3��ʼ��ʱ
}


void TM3_Isr() interrupt 19 using 1
{                                
	//���Զ˿�
	AUXINTIF &= ~T3IF;                          //���жϱ�־
	Timer_CNT_OpenAll++;
	// UartSendStr("----11---\r\n");
	// debug_uart_send_data1(Timer_CNT_OpenAll);
	// feed_dog();
	if(Timer_CNT_OpenAll >= 100)//20
	{
		// feed_dog();
		// UartSendStr("22\r\n");
		// TF1 = 0;		//���TF1��־
		// // AUXINTIF &= ~T1IF;
		// TR1=0;
		Timer_CNT_OpenAll = 0;
		// LED = !LED;			 //���Զ˿�

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
			T4T3M &= ~0x08;		//��ʱ��3 close
			// TIM4_Set(0);			//TIM 
			// IE2 &= ~0x04;                    //�ض�ʱ��2�ж�
			lock_channel=1;
			Timer_flag =0;
			// key_mode = 1;
		}







	}
}




// void TM3_Isr() interrupt 19 using 1
// {
//     AUXINTIF &= ~T3IF;                          //���жϱ�־

// 	Timer_CNT++;
// 	if(Timer_CNT >= 1000)//10*100  700
// 	{
// 		UartSendStr("11\r\n");
// 		Timer_CNT = 0;
// 		// LED = !LED;			 //���Զ˿�


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
	T4T3M &= 0xFD;		//��ʱ��ʱ��12Tģʽ   add
    // T3L = 0x66;                                 //65536-11.0592M/12/1000
    // T3H = 0xfc;
	T3L = 0xE0;		//���ö�ʱ��ֵ
	T3H = 0xB1;		//���ö�ʱ��ֵ
    // T4T3M = 0x08;                               //������ʱ��
	// T4T3M |= 0x08;		//��ʱ��3��ʼ��ʱ
    IE2 = ET3;                                  //ʹ�ܶ�ʱ���ж�
    EA = 1;
}

void TM4_Isr() interrupt 20 using 1
{                                //���Զ˿�
    AUXINTIF &= ~T4IF;                          //���жϱ�־
	Timer_CNT++;
	if(Timer_CNT >= 1000)
	{
		Timer_CNT = 0;
		LED = !LED;			 //���Զ˿�
	}
}

void Timer4_Init(void)
{
    T4L = 0x66;                                 //65536-11.0592M/12/1000
    T4H = 0xfc;
    T4T3M = 0x80;                               //������ʱ��
    IE2 = ET4;                                  //ʹ�ܶ�ʱ���ж�
    EA = 1;
}








