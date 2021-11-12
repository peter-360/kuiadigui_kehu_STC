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
#include "config.h"
#include "stdlib.h"
#include <stdio.h>



u8 	xdata RX1_Buffer[RX_Length];	//接收缓冲
u16	RX_write;		//发送写指针



void spear_uart_send_datas(uint8* str, uint8 len)
{
	RS485_TX_EN();
	while(len--)
	{
//		USART_SendData(USART1, *str);
//		while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET); 
//		str++;
		UartSend(*str++);
	}
	RS485_RX_EN();
}

void debug_uart_send_datas(uint8* str, uint8 len)
{
	RS485_TX_EN();
	UartSend(0xee);
	while(len--)
	{
//		USART_SendData(USART1, *str);
//		while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET); 
//		str++;
		UartSend(*str++);
	}
	UartSend(0xDD);
	RS485_RX_EN();
}



void debug_uart_send_data1(uint8_t str)//
{
	RS485_TX_EN();
	UartSend(0xee);
	UartSend(str);
	UartSend(0xff);
	RS485_RX_EN();
}
void debug_uart_send_data2(uint8_t str,uint8_t dbg_data)//add
{
	// RS485_TX_EN();
	// UartSend(0xaa);
	// UartSend(str);
	// UartSend(dbg_data);
	// RS485_RX_EN();
}


///command struct
typedef struct
{
	//uint8_t type;
	uint8_t opcode;
	
	uint8_t board_addr;
	uint8_t lock_addr;//-------
	uint8_t gu_ding;//---
	
	uint8_t bcc;
}command1_struct;

/////start process the data in

command1_struct m_data;


void lock_all_off(void)
{
	GO_1=0;
	//GI_1=0;

	GO_2=0;
	//GI_2=0;

	GO_3=0;
	//GI_3=0;


	GO_4=0;
	//GI_4=0;

	GO_5=0;
	//GI_5=0;

	GO_6=0;
	//GI_6=0;

	GO_7=0;
	//GI_7=0;

	GO_8=0;
	//GI_8=0;

	GO_9=0;
	//GI_9=0;

	GO_10=0;
	//GI_10=0;

	GO_11=0;
	//GI_11=0;

	GO_12=0;
	//GI_12=0;

	GO_13=0;
	//GI_13=0;

	GO_14=0;
	//GI_14=0;

	GO_15=0;
	//GI_15=0;

	GO_16=0;
	//GI_16=0;

	GO_17=0;
	//GI_17=0;

	GO_18=0;
	//GI_18=0;

	GO_19=0;
	//GI_19=0;

	GO_20=0;
	//GI_20=0;

	GO_21=0;
	//GI_21=0;

	GO_22=0;
	//GI_22=0;

	GO_23=0;
	//GI_23=0;

	GO_24=0;
	//GI_24=0;  

}


void lock_all_on_off(void)
{

	GO_1=1; 					//open
	delay_ms(500);  //>=20
	if(0==GI_1)//no open
	{
		//debug_uart_send_data1(0x01);
		;
	}
	if(0==GI_1)//no open
	{
		//debug_uart_send_data1(0x02);
		delay_ms(450);
	}
	GO_1=0;						//close
	delay_ms(500);


	//LED1 =1;

	
	GO_2=1;							 //open
	delay_ms(500);  //>=20
	if(0==GI_2)//no open
	{
		;
	}
	if(0==GI_2)//no open
	{
		delay_ms(450);
	}
	GO_2=0;	 						 //close
	//LED1 =0;
	delay_ms(500);LED1=!LED1;

	
	
	GO_3=1;							 //open
	delay_ms(500);  //>=20
	if(0==GI_3)//no open
	{
		;
	}
	if(0==GI_3)//no open
	{
		delay_ms(450);
	}
	GO_3=0;	 						 //close
	delay_ms(500);LED1=!LED1;


	GO_4=1;							 //open
	delay_ms(500);  //>=20
	if(0==GI_4)//no open
	{
		;
	}
	if(0==GI_4)//no open
	{
		delay_ms(450);
	} 
	GO_4=0;	 						 //close
	delay_ms(500);LED1=!LED1;


	GO_5=1;							 //open
	delay_ms(500);  //>=20
	if(0==GI_5)//no open
	{
		;
	}
	if(0==GI_5)//no open
	{
		delay_ms(450);
	} 
	GO_5=0;	 						 //close
	delay_ms(500);LED1=!LED1;


	GO_6=1;							 //open
	delay_ms(500);  //>=20
	if(0==GI_6)//no open
	{
		;
	}
	if(0==GI_6)//no open
	{
		delay_ms(450);
	}
	GO_6=0;	 						 //close
	delay_ms(500);LED1=!LED1;


	GO_7=1;							 //open
	delay_ms(500);  //>=20
	if(0==GI_7)//no open
	{
		;
	}
	if(0==GI_7)//no open
	{
		delay_ms(450);
	}
	GO_7=0;	 						 //close
	delay_ms(500);LED1=!LED1;


	GO_8=1;							 //open
	delay_ms(500);  //>=20
	if(0==GI_8)//no open
	{
		;
	}
	if(0==GI_8)//no open
	{
		delay_ms(450);
	}
	GO_8=0;	 						 //close
	delay_ms(500);LED1=!LED1;
	

	GO_9=1;							 //open
	delay_ms(500);  //>=20
	if(0==GI_9)//no open
	{
		;
	}
	if(0==GI_9)//no open
	{
		delay_ms(450);
	}
	GO_9=0;	 						 //close
	delay_ms(500);LED1=!LED1;


	GO_10=1;							 //open
	delay_ms(500);  //>=20
	if(0==GI_10)//no open
	{
		;
	}
	if(0==GI_10)//no open
	{
		delay_ms(450);
	} 
	GO_10=0;	 						 //close
	delay_ms(500);LED1=!LED1;


	GO_11=1;							 //open
	delay_ms(500);  //>=20
	if(0==GI_11)//no open
	{
		;
	}
	if(0==GI_11)//no open
	{
		delay_ms(450);
	} 
	GO_11=0;	 						 //close
	delay_ms(500);LED1=!LED1;


	GO_12=1;							 //open
	delay_ms(500);  //>=20
	if(0==GI_12)//no open
	{
		;
	}
	if(0==GI_12)//no open
	{
		delay_ms(450);
	} 
	GO_12=0;	 						 //close
	delay_ms(500);LED1=!LED1;


	GO_13=1;							 //open
	delay_ms(500);  //>=20
	if(0==GI_13)//no open
	{
		;
	}
	if(0==GI_13)//no open
	{
		delay_ms(450);
	} 
	GO_13=0;	 						 //close
	delay_ms(500);LED1=!LED1;


	GO_14=1;							 //open
	delay_ms(500);  //>=20
	if(0==GI_14)//no open
	{
		;
	}
	if(0==GI_14)//no open
	{
		delay_ms(450);
	} 
	GO_14=0;	 						 //close
	delay_ms(500);LED1=!LED1;


	GO_15=1;							 //open
	delay_ms(500);  //>=20
	if(0==GI_15)//no open
	{
		;
	}
	if(0==GI_15)//no open
	{
		delay_ms(450);
	} 
	GO_15=0;	 						 //close
	delay_ms(500);LED1=!LED1;


	GO_16=1;							 //open
	delay_ms(500);  //>=20
	if(0==GI_16)//no open
	{
		;
	}
	if(0==GI_16)//no open
	{
		delay_ms(450);
	} 
	GO_16=0;	 						 //close
	delay_ms(500);LED1=!LED1;


	GO_17=1;							 //open
	delay_ms(500);  //>=20
	if(0==GI_17)//no open
	{
		;
	}
	if(0==GI_17)//no open
	{
		delay_ms(450);
	} 
	GO_17=0;	 						 //close
	delay_ms(500);LED1=!LED1;


	GO_18=1;							 //open
	delay_ms(500);  //>=20
	if(0==GI_18)//no open
	{
		;
	}
	if(0==GI_18)//no open
	{
		delay_ms(450);
	} 
	GO_18=0;	 						 //close
	delay_ms(500);LED1=!LED1;


	GO_19=1;							 //open
	delay_ms(500);  //>=20
	if(0==GI_19)//no open
	{
		;
	}
	if(0==GI_19)//no open
	{
		delay_ms(450);
	} 
	GO_19=0;	 						 //close
	delay_ms(500);LED1=!LED1;


	GO_20=1;							 //open
	delay_ms(500);  //>=20
	if(0==GI_20)//no open
	{
		;
	}
	if(0==GI_20)//no open
	{
		delay_ms(450);
	}   
	GO_20=0;	 						 //close
	delay_ms(500);LED1=!LED1;


	
	GO_21=1;							 //open
	delay_ms(500);  //>=20
	if(0==GI_21)//no open
	{
		;
	}
	if(0==GI_21)//no open
	{
		delay_ms(450);
	}  
	GO_21=0;	 						 //close
	delay_ms(500);LED1=!LED1;


	GO_22=1;							 //open
	delay_ms(500);  //>=20
	if(0==GI_22)//no open
	{
		;
	}
	if(0==GI_22)//no open
	{
		delay_ms(450);
	} 
	GO_22=0;	 						 //close
	delay_ms(500);LED1=!LED1;


	GO_23=1;							 //open
	delay_ms(500);  //>=20
	if(0==GI_23)//no open
	{
		;
	}
	if(0==GI_23)//no open
	{
		delay_ms(450);
	} 
	GO_23=0;	 						 //close
	delay_ms(500);LED1=!LED1;


	GO_24=1;							 //open
	delay_ms(500);  //>=20
	if(0==GI_24)//no open
	{
		;
	}
	if(0==GI_24)//no open
	{
		delay_ms(450);
	} 
	GO_24=0;	 						 //close
	
	lock_all_off();

}
uint8_t ComputXor(uint8_t *InData, uint16_t Len)
{
	uint8_t Sum = 0;
	uint16_t i;
	for(i = 0; i < Len; i++)
	{
		Sum ^= InData[i];	
	}
	return Sum;
}

void data_parse(uint8_t* RX1_Buffer_0,uint16_t Uart1_Rx_0)
{
	uint8_t bcc_temp;
	uint8_t tx_Buffer[256]={0};        //?????
	//uint8_t length = 0;             //??
	uint8_t gpio_level=0;
	uint8_t grp_level_1;
	uint8_t grp_level_2;
	uint8_t grp_level_3;
	uint8_t board_addr;
	
	uint8_t Uart1_Buffer_T[256]={0};        //?????
	uint8_t Uart1_Rx_T = 0;             //??
	
	uint8_t DSW_T_1, DSW_T_2, DSW_T_3, DSW_T_4, DSW_T_5, DSW_T_6 ;
	
	uint8_t GI_T_1=GI_1,   GI_T_2=GI_2,   GI_T_3=GI_3,   GI_T_4=GI_4,   GI_T_5=GI_5,   GI_T_6=GI_6,
					GI_T_7=GI_7,   GI_T_8=GI_8,   GI_T_9=GI_9,   GI_T_10=GI_10, GI_T_11=GI_11, GI_T_12=GI_12, 
					GI_T_13=GI_13, GI_T_14=GI_14, GI_T_15=GI_15, GI_T_16=GI_16, GI_T_17=GI_17, GI_T_18=GI_18,
					GI_T_19=GI_19, GI_T_20=GI_20, GI_T_21=GI_21, GI_T_22=GI_22, GI_T_23=GI_23, GI_T_24=GI_24;
	
					
	// Uart1_Rx_T = Uart1_Rx_0 - 8;
	// memcpy(Uart1_Buffer_T,RX1_Buffer_0+4,Uart1_Rx_T);
	

	Uart1_Rx_T = Uart1_Rx_0 ;
	memcpy(Uart1_Buffer_T,RX1_Buffer_0,Uart1_Rx_T);



	DSW_T_1 = ~DSW_1;
	DSW_T_2 = ~DSW_2;
	DSW_T_3 = ~DSW_3;
	DSW_T_4 = ~DSW_4;
	DSW_T_5 = ~DSW_5;
	DSW_T_6 = ~DSW_6;
	board_addr= DSW_T_1 | (DSW_T_2<<1) | (DSW_T_3<<2) | (DSW_T_4<<3) | (DSW_T_5<<4) | (DSW_T_6<<5) ;
	
	// UartSend(board_addr);
	debug_uart_send_data2(board_addr,0x58);
	debug_uart_send_data2(Uart1_Buffer_T[1],0x59);
	if(board_addr == Uart1_Buffer_T[1])//todo
	{
		if(5==Uart1_Rx_T)
		{
			m_data.opcode = Uart1_Buffer_T[0];
			m_data.board_addr = Uart1_Buffer_T[1];// to do
			m_data.lock_addr = Uart1_Buffer_T[2];//
			m_data.gu_ding = Uart1_Buffer_T[3];//
			m_data.bcc = Uart1_Buffer_T[4];

			bcc_temp = ComputXor(Uart1_Buffer_T,4);
			//SEGGER_RTT_printf(0, "bcc_temp = %x\n",bcc_temp);
			if(bcc_temp == m_data.bcc)
			{
				switch(m_data.opcode)
				{
					case 0x8A:
						//----1------
						if(m_data.gu_ding  == 0x11)//process
						{
							LED1=0;	//on
							//UartSend(m_data.lock_addr);
							switch(m_data.lock_addr)
							{			
								case 1:
									GO_1=1; 					//open
									delay_ms(500);  //>=20
									if(0==GI_1)//no open
									{
										//debug_uart_send_data1(0x01);
										;
									}
									if(0==GI_1)//no open
									{
										//debug_uart_send_data1(0x02);
										delay_ms(450);
									}
									GO_1=0;						//close

								
									//LED1 =1;
									gpio_level= GI_1;
									//SEGGER_RTT_printf(0, "%d:gpio_level = %x\n",m_data.lock_addr,gpio_level);
									//UartSendStr("\r\n--1--\r\n");
									
									break;
								
								case 2:
									GO_2=1;							 //open
									delay_ms(500);  //>=20
									if(0==GI_2)//no open
									{
										;
									}
									if(0==GI_2)//no open
									{
										delay_ms(450);
									}
									GO_2=0;	 						 //close


									//LED1 =0;
									gpio_level= GI_2;
									//SEGGER_RTT_printf(0, "%d:gpio_level = %x\n",m_data.lock_addr,gpio_level);
									break;
								
							case 3:
									GO_3=1;							 //open
									delay_ms(500);  //>=20
									if(0==GI_3)//no open
									{
										;
									}
									if(0==GI_3)//no open
									{
										delay_ms(450);
									}
									GO_3=0;	 						 //close

									gpio_level= GI_3;
									//SEGGER_RTT_printf(0, "%d:gpio_level = %x\n",m_data.lock_addr,gpio_level);
									break;
								case 4:
									GO_4=1;							 //open
									delay_ms(500);  //>=20
									if(0==GI_4)//no open
									{
										;
									}
									if(0==GI_4)//no open
									{
										delay_ms(450);
									} 
									GO_4=0;	 						 //close

									gpio_level= GI_4;
									//SEGGER_RTT_printf(0, "%d:gpio_level = %x\n",m_data.lock_addr,gpio_level);
									break;
								case 5:
									GO_5=1;							 //open
									delay_ms(500);  //>=20
									if(0==GI_5)//no open
									{
										;
									}
									if(0==GI_5)//no open
									{
										delay_ms(450);
									} 
									GO_5=0;	 						 //close

									gpio_level= GI_5;
									//SEGGER_RTT_printf(0, "%d:gpio_level = %x\n",m_data.lock_addr,gpio_level);
									break;
								case 6:
									GO_6=1;							 //open
									delay_ms(500);  //>=20
									if(0==GI_6)//no open
									{
										;
									}
									if(0==GI_6)//no open
									{
										delay_ms(450);
									}
									GO_6=0;	 						 //close

									gpio_level= GI_6;
									//SEGGER_RTT_printf(0, "%d:gpio_level = %x\n",m_data.lock_addr,gpio_level);
									break;
								case 7:
									GO_7=1;							 //open
									delay_ms(500);  //>=20
									if(0==GI_7)//no open
									{
										;
									}
									if(0==GI_7)//no open
									{
										delay_ms(450);
									}
									GO_7=0;	 						 //close

									gpio_level= GI_7;
									//SEGGER_RTT_printf(0, "%d:gpio_level = %x\n",m_data.lock_addr,gpio_level);
									break;
								case 8:
									GO_8=1;							 //open
									delay_ms(500);  //>=20
									if(0==GI_8)//no open
									{
										;
									}
									if(0==GI_8)//no open
									{
										delay_ms(450);
									}
									GO_8=0;	 						 //close

									gpio_level= GI_8;//GI_2;
									//SEGGER_RTT_printf(0, "%d:gpio_level = %x\n",m_data.lock_addr,gpio_level);
									break;
								case 9:
									GO_9=1;							 //open
									delay_ms(500);  //>=20
									if(0==GI_9)//no open
									{
										;
									}
									if(0==GI_9)//no open
									{
										delay_ms(450);
									}
									GO_9=0;	 						 //close

									gpio_level= GI_9;
									//SEGGER_RTT_printf(0, "%d:gpio_level = %x\n",m_data.lock_addr,gpio_level);
									break;
								case 10:
									GO_10=1;							 //open
									delay_ms(500);  //>=20
									if(0==GI_10)//no open
									{
										;
									}
									if(0==GI_10)//no open
									{
										delay_ms(450);
									} 
									GO_10=0;	 						 //close

									gpio_level= GI_10;
									//SEGGER_RTT_printf(0, "%d:gpio_level = %x\n",m_data.lock_addr,gpio_level);
									break;
								case 11:
									GO_11=1;							 //open
									delay_ms(500);  //>=20
									if(0==GI_11)//no open
									{
										;
									}
									if(0==GI_11)//no open
									{
										delay_ms(450);
									} 
									GO_11=0;	 						 //close

									gpio_level= GI_11;
									//SEGGER_RTT_printf(0, "%d:gpio_level = %x\n",m_data.lock_addr,gpio_level);
									break;
								case 12:
									GO_12=1;							 //open
									delay_ms(500);  //>=20
									if(0==GI_12)//no open
									{
										;
									}
									if(0==GI_12)//no open
									{
										delay_ms(450);
									} 
									GO_12=0;	 						 //close

									gpio_level= GI_12;
									//SEGGER_RTT_printf(0, "%d:gpio_level = %x\n",m_data.lock_addr,gpio_level);
									break;
								case 13:
									GO_13=1;							 //open
									delay_ms(500);  //>=20
									if(0==GI_13)//no open
									{
										;
									}
									if(0==GI_13)//no open
									{
										delay_ms(450);
									} 
									GO_13=0;	 						 //close

									gpio_level= GI_13;
									//SEGGER_RTT_printf(0, "%d:gpio_level = %x\n",m_data.lock_addr,gpio_level);
									break;
								case 14:
									GO_14=1;							 //open
									delay_ms(500);  //>=20
									if(0==GI_14)//no open
									{
										;
									}
									if(0==GI_14)//no open
									{
										delay_ms(450);
									} 
									GO_14=0;	 						 //close

									gpio_level= GI_14;
									//SEGGER_RTT_printf(0, "%d:gpio_level = %x\n",m_data.lock_addr,gpio_level);
									break;
								case 15:
									GO_15=1;							 //open
									delay_ms(500);  //>=20
									if(0==GI_15)//no open
									{
										;
									}
									if(0==GI_15)//no open
									{
										delay_ms(450);
									} 
									GO_15=0;	 						 //close

									gpio_level= GI_15;
									//SEGGER_RTT_printf(0, "%d:gpio_level = %x\n",m_data.lock_addr,gpio_level);
									break;
								case 16:
									GO_16=1;							 //open
									delay_ms(500);  //>=20
									if(0==GI_16)//no open
									{
										;
									}
									if(0==GI_16)//no open
									{
										delay_ms(450);
									} 
									GO_16=0;	 						 //close

									gpio_level= GI_16;
									//SEGGER_RTT_printf(0, "%d:gpio_level = %x\n",m_data.lock_addr,gpio_level);
									break;
								case 17:
									GO_17=1;							 //open
									delay_ms(500);  //>=20
									if(0==GI_17)//no open
									{
										;
									}
									if(0==GI_17)//no open
									{
										delay_ms(450);
									} 
									GO_17=0;	 						 //close

									gpio_level= GI_17;
									//SEGGER_RTT_printf(0, "%d:gpio_level = %x\n",m_data.lock_addr,gpio_level);
									break;
								case 18:
									GO_18=1;							 //open
									delay_ms(500);  //>=20
									if(0==GI_18)//no open
									{
										;
									}
									if(0==GI_18)//no open
									{
										delay_ms(450);
									} 
									GO_18=0;	 						 //close

									gpio_level= GI_18;
									//SEGGER_RTT_printf(0, "%d:gpio_level = %x\n",m_data.lock_addr,gpio_level);
									break;
								case 19:
									GO_19=1;							 //open
									delay_ms(500);  //>=20
									if(0==GI_19)//no open
									{
										;
									}
									if(0==GI_19)//no open
									{
										delay_ms(450);
									} 
									GO_19=0;	 						 //close

									gpio_level= GI_19;
									//SEGGER_RTT_printf(0, "%d:gpio_level = %x\n",m_data.lock_addr,gpio_level);
									break;
								case 20:
									GO_20=1;							 //open
									delay_ms(500);  //>=20
									if(0==GI_20)//no open
									{
										;
									}
									if(0==GI_20)//no open
									{
										delay_ms(450);
									}   
									GO_20=0;	 						 //close

									gpio_level= GI_20;
									//SEGGER_RTT_printf(0, "%d:gpio_level = %x\n",m_data.lock_addr,gpio_level);
									break;
								case 21:
									GO_21=1;							 //open
									delay_ms(500);  //>=20
									if(0==GI_21)//no open
									{
										;
									}
									if(0==GI_21)//no open
									{
										delay_ms(450);
									}  
									GO_21=0;	 						 //close

									gpio_level= GI_21;
									//SEGGER_RTT_printf(0, "%d:gpio_level = %x\n",m_data.lock_addr,gpio_level);
									break;
								case 22:
									GO_22=1;							 //open
									delay_ms(500);  //>=20
									if(0==GI_22)//no open
									{
										;
									}
									if(0==GI_22)//no open
									{
										delay_ms(450);
									} 
									GO_22=0;	 						 //close

									gpio_level= GI_22;
									//SEGGER_RTT_printf(0, "%d:gpio_level = %x\n",m_data.lock_addr,gpio_level);
									break;
								case 23:
									GO_23=1;							 //open
									delay_ms(500);  //>=20
									if(0==GI_23)//no open
									{
										;
									}
									if(0==GI_23)//no open
									{
										delay_ms(450);
									} 
									GO_23=0;	 						 //close

									gpio_level= GI_23;
									//SEGGER_RTT_printf(0, "%d:gpio_level = %x\n",m_data.lock_addr,gpio_level);
									break;
								case 24:
									GO_24=1;							 //open
									delay_ms(500);  //>=20
									if(0==GI_24)//no open
									{
										;
									}
									if(0==GI_24)//no open
									{
										delay_ms(450);
									} 
									GO_24=0;	 						 //close

									gpio_level= GI_24;
									//SEGGER_RTT_printf(0, "%d:gpio_level = %x\n",m_data.lock_addr,gpio_level);
									break;

								
								default:
									break;

							}
							lock_all_off();
							
							memcpy(tx_Buffer,"star",4);
							tx_Buffer[4]= m_data.opcode;
							tx_Buffer[5]= m_data.board_addr;
							tx_Buffer[6]= m_data.lock_addr;
							
//							if(0x00 == gpio_level)
							if(0x01 == gpio_level)
								tx_Buffer[7]= 0x11;//lock state todo open
							else
								tx_Buffer[7]= 0x00;//lock state todo close
							
							bcc_temp = ComputXor(tx_Buffer+4,4);
							tx_Buffer[8]= bcc_temp;
							memcpy(tx_Buffer+9,"end",3);
							
							tx_Buffer[12]='\0';
							
							spear_uart_send_datas(tx_Buffer,12);

							debug_uart_send_data2(Uart1_Buffer_T[1],0x5a);
//							spear_rtt_send_datas(tx_Buffer,12);

							//SEGGER_RTT_printf(0, "ok,m_data.opcode=%02x\n",m_data.opcode);
						}
						else
						{
							//SEGGER_RTT_printf(0, "error-2,m_data.opcode=%02x\n",m_data.opcode);
						}
						LED1=1;	//off
						break;

					case 0x80:
						if(m_data.gu_ding  == 0x33)//process
						{
							if(0x00== m_data.lock_addr)//----4------
							{
//								debug_uart_send_data1((GI_T_1) | (GI_T_2<<1));
								grp_level_1= GI_T_1 | (GI_T_2<<1) | (GI_T_3<<2) | (GI_T_4<<3) | (GI_T_5<<4) | (GI_T_6<<5) | (GI_T_7<<6) | (GI_T_8<<7);
								grp_level_2= GI_T_9 | (GI_T_10<<1) | (GI_T_11<<2) | (GI_T_12<<3) | (GI_T_13<<4) | (GI_T_14<<5) | (GI_T_15<<6) | (GI_T_16<<7);
								grp_level_3= GI_T_17 | (GI_T_18<<1) | (GI_T_19<<2) | (GI_T_20<<3) | (GI_T_21<<4) | (GI_T_22<<5) | (GI_T_23<<6) | (GI_T_24<<7);
								//SEGGER_RTT_printf(0, "grp_level_1 = %x\n",grp_level_1);
								//SEGGER_RTT_printf(0, "grp_level_2 = %x\n",grp_level_2);
								//SEGGER_RTT_printf(0, "grp_level_3 = %x\n",grp_level_3);
								
								memcpy(tx_Buffer,"star",4);
								tx_Buffer[4]= m_data.opcode;
								tx_Buffer[5]= m_data.board_addr;
								tx_Buffer[6]= grp_level_1;
								tx_Buffer[7]= grp_level_2;
								tx_Buffer[8]= grp_level_3;


								
								bcc_temp = ComputXor(tx_Buffer+4,5);
								tx_Buffer[9]= bcc_temp;
								memcpy(tx_Buffer+10,"end",3);//now is 2?
								
								tx_Buffer[12]='\0';//tx_Buffer[12]='\0';
								
								spear_uart_send_datas(tx_Buffer,12);
								//spear_rtt_send_datas(tx_Buffer,12);//to do 13?

								//SEGGER_RTT_printf(0, "ok,m_data.opcode=%02x\n",m_data.opcode);
								//spear_uart_send_datas
							}
							else//----3------
							{
								
								switch(m_data.lock_addr)
								{
									case 1:
										gpio_level= GI_1;
										break;
									case 2:
										gpio_level= GI_2;
										break;
									case 3:
										gpio_level= GI_3;
										break;
									case 4:
										gpio_level= GI_4;
										break;
									case 5:
										gpio_level= GI_5;
										break;
									case 6:
										gpio_level= GI_6;
									case 7:
										gpio_level= GI_7;
										break;
									case 8:
										gpio_level= GI_8;
										break;
									case 9:
										gpio_level= GI_9;
										break;
									case 10:
										gpio_level= GI_10;
										break;
									case 11:
										gpio_level= GI_11;
										break;
									case 12:
										gpio_level= GI_12;
										break;
									case 13:
										gpio_level= GI_13;
										break;
									case 14:
										gpio_level= GI_14;
										break;
									case 15:
										gpio_level= GI_15;
									case 16:
										gpio_level= GI_16;
										break;
									case 17:
										gpio_level= GI_17;
										break;
									case 18:
										gpio_level= GI_18;
										break;
									case 19:
										gpio_level= GI_19;
										break;
									case 20:
										gpio_level= GI_20;
										break;
									case 21:
										gpio_level= GI_21;
										break;
									case 22:
										gpio_level= GI_22;
										break;
									case 23:
										gpio_level= GI_23;
										break;
									case 24:
										gpio_level= GI_24;
										break;
									
									default:
										break;

								}
								//SEGGER_RTT_printf(0, "--%d:gpio_level = %x\n",m_data.lock_addr,gpio_level);
								
								memcpy(tx_Buffer,"star",4);
								tx_Buffer[4]= m_data.opcode;
								tx_Buffer[5]= m_data.board_addr;
								tx_Buffer[6]= m_data.lock_addr;
								
								if(0x01 == gpio_level)
									tx_Buffer[7]= 0x11;//lock state todo open
								else
									tx_Buffer[7]= 0x00;//lock state todo close

								
								bcc_temp = ComputXor(tx_Buffer+4,4);
								tx_Buffer[8]= bcc_temp;
								memcpy(tx_Buffer+9,"end",3);
								
								tx_Buffer[12]='\0';
								
								spear_uart_send_datas(tx_Buffer,12);
								//spear_rtt_send_datas(tx_Buffer,12);

								//SEGGER_RTT_printf(0, "--ok,m_data.opcode=%02x\n",m_data.opcode);
							}
							
						}
						else
						{
							//SEGGER_RTT_printf(0, "error-2,m_data.opcode=%02x\n",m_data.opcode);
						}
						break;

					default:
						break;
				}
				
				//SEGGER_RTT_printf(0, "m_data.bcc = %x\n",m_data.bcc);
			}
			else
			{
				//SEGGER_RTT_printf(0, "error-1-m_data.bcc = %x\n",m_data.bcc);
			}
			
		}
		else if(3==Uart1_Rx_T)
		{
			m_data.opcode = Uart1_Buffer_T[0];
			m_data.board_addr = Uart1_Buffer_T[1];

			m_data.bcc = Uart1_Buffer_T[2];
			
			bcc_temp = ComputXor(Uart1_Buffer_T,2);
			//SEGGER_RTT_printf(0, "bcc_temp = %x\n",bcc_temp);
			if(bcc_temp == m_data.bcc)
			{
				switch(m_data.opcode)
				{
					case 0x90://--------2---------
						lock_all_on_off();
						grp_level_1= GI_T_1 | (GI_T_2<<1) | (GI_T_3<<2) | (GI_T_4<<3) | (GI_T_5<<4) | (GI_T_6<<5) | (GI_T_7<<6) | (GI_T_8<<7);
						grp_level_2= GI_T_9 | (GI_T_10<<1) | (GI_T_11<<2) | (GI_T_12<<3) | (GI_T_13<<4) | (GI_T_14<<5) | (GI_T_15<<6) | (GI_T_16<<7);
						grp_level_3= GI_T_17 | (GI_T_18<<1) | (GI_T_19<<2) | (GI_T_20<<3) | (GI_T_21<<4) | (GI_T_22<<5) | (GI_T_23<<6) | (GI_T_24<<7);
						//SEGGER_RTT_printf(0, "grp_level_1 = %x\n",grp_level_1);
						//SEGGER_RTT_printf(0, "grp_level_2 = %x\n",grp_level_2);
						//SEGGER_RTT_printf(0, "grp_level_3 = %x\n",grp_level_3);
						
						memcpy(tx_Buffer,"star",4);
						tx_Buffer[4]= 0x80;//m_data.opcode;
						tx_Buffer[5]= m_data.board_addr;
						tx_Buffer[6]= grp_level_1;
						tx_Buffer[7]= grp_level_2;
						tx_Buffer[8]= grp_level_3;


						
						bcc_temp = ComputXor(tx_Buffer+4,5);
						tx_Buffer[9]= bcc_temp;
						memcpy(tx_Buffer+10,"end",3);//now is 2?
						
						tx_Buffer[12]='\0';//tx_Buffer[12]='\0';
						
						spear_uart_send_datas(tx_Buffer,12);
						//SEGGER_RTT_printf(0, "ok,m_data.opcode=%02x\n",m_data.opcode);
						break;
					case 0x91://--------2.1---------
						lock_all_on_off();
						grp_level_1= GI_T_1 | (GI_T_2<<1) | (GI_T_3<<2) | (GI_T_4<<3) | (GI_T_5<<4) | (GI_T_6<<5) | (GI_T_7<<6) | (GI_T_8<<7);
						grp_level_2= GI_T_9 | (GI_T_10<<1) | (GI_T_11<<2) | (GI_T_12<<3) | (GI_T_13<<4) | (GI_T_14<<5) | (GI_T_15<<6) | (GI_T_16<<7);
						grp_level_3= GI_T_17 | (GI_T_18<<1) | (GI_T_19<<2) | (GI_T_20<<3) | (GI_T_21<<4) | (GI_T_22<<5) | (GI_T_23<<6) | (GI_T_24<<7);
						//SEGGER_RTT_printf(0, "grp_level_1 = %x\n",grp_level_1);
						//SEGGER_RTT_printf(0, "grp_level_2 = %x\n",grp_level_2);
						//SEGGER_RTT_printf(0, "grp_level_3 = %x\n",grp_level_3);
						
						memcpy(tx_Buffer,"star",4);
						tx_Buffer[4]= 0x80;//m_data.opcode;
						tx_Buffer[5]= m_data.board_addr;
						tx_Buffer[6]= grp_level_1;
						tx_Buffer[7]= grp_level_2;
						tx_Buffer[8]= grp_level_3;


						
						bcc_temp = ComputXor(tx_Buffer+4,5);
						tx_Buffer[9]= bcc_temp;
						memcpy(tx_Buffer+10,"end",3);//now is 2?
						
						tx_Buffer[12]='\0';//tx_Buffer[12]='\0';
						
						spear_uart_send_datas(tx_Buffer,12);
						//SEGGER_RTT_printf(0, "ok,m_data.opcode=%02x\n",m_data.opcode);
						break;
					case 0x92://--------2.2---------
						//SEGGER_RTT_printf(0, "ok,m_data.opcode=%02x\n",m_data.opcode);
						break;
					case 0x93://--------2.3---------
						//SEGGER_RTT_printf(0, "ok,m_data.opcode=%02x\n",m_data.opcode);
						break;
					case 0x70://--------2.4---------
						//SEGGER_RTT_printf(0, "ok,m_data.opcode=%02x\n",m_data.opcode);
						break;
					case 0x71://--------2.5---------
						//SEGGER_RTT_printf(0, "ok,m_data.opcode=%02x\n",m_data.opcode);
						break;		

					case 0xf1://--------2.6---------  software version  add
						// SEGGER_RTT_printf(0, "ok,m_data.opcode=%02x\n",m_data.opcode);
						memset(tx_Buffer,0,256);
						memcpy(tx_Buffer,"star",4);
						tx_Buffer[4]= m_data.opcode;
						tx_Buffer[5]= board_addr;

						tx_Buffer[6]= SOFT_VERSION_1;//major  V0.0.1
						tx_Buffer[7]= SOFT_VERSION_2;//minor
						tx_Buffer[8]= SOFT_VERSION_3;//rev



						bcc_temp = ComputXor(tx_Buffer+4,5);
						tx_Buffer[9]= bcc_temp;
						memcpy(tx_Buffer+10,"end",3);//now is 2?

						tx_Buffer[13]='\0';//tx_Buffer[12]='\0';

						delay_ms(50);  //>=20
						spear_uart_send_datas(tx_Buffer,13);

						// SEGGER_RTT_printf(0, "-----------debug1-----------\n");
						//spear_rtt_send_datas(tx_Buffer,13);
						break;		

					case 0xf2://--------2.7--------- hardware version and dan/shuang xian type  add
						// SEGGER_RTT_printf(0, "ok,m_data.opcode=%02x\n",m_data.opcode);
						memset(tx_Buffer,0,256);
						memcpy(tx_Buffer,"star",4);
						tx_Buffer[4]= m_data.opcode;
						tx_Buffer[5]= board_addr;

						tx_Buffer[6]= HARD_VERSION_1;//major  V4.0.B_1
						tx_Buffer[7]= HARD_VERSION_2;//minor
						tx_Buffer[8]= HARD_VERSION_3;//REV
						tx_Buffer[9]= HARD_VERSION_4;//dan:1/shuang:2 xian


						bcc_temp = ComputXor(tx_Buffer+4,6);
						tx_Buffer[10]= bcc_temp;
						memcpy(tx_Buffer+11,"end",3);//now is 2?

						tx_Buffer[14]='\0';//tx_Buffer[12]='\0';

						delay_ms(50);  //>=20
						spear_uart_send_datas(tx_Buffer,14);

						// SEGGER_RTT_printf(0, "-----------debug2-----------\n");
						//spear_rtt_send_datas(tx_Buffer,14);
						break;

					default:
						break;
				}
				//todo
				
				//SEGGER_RTT_printf(0, "m_data.bcc = %x\n",m_data.bcc);
			}
			else
			{
				//SEGGER_RTT_printf(0, "error-1-m_data.bcc = %x\n",m_data.bcc);
			}
		
		}
		
		
		
	}

}

void gpio_init(void)
{
	P1M0 = 0x6F;                                //??P1.0~P1.7???????
	P1M1 = 0x00;

	P2M0 = 0x66;                                //
	P2M1 = 0x00;
	
	P3M0 = 0x18;                                //
	P3M1 = 0x00;
	
	P4M0 = 0x03;                                //
	P4M1 = 0x00;
	
	P5M0 = 0x2F;                                //
	P5M1 = 0x00;
	
	P6M0 = 0x8C;                                //
	P6M1 = 0x00;
	
	P7M0 = 0x09;                                //
	P7M1 = 0x00;
	
	lock_all_off();

}


static const char *my_memmem(const char *haystack, size_t hlen, const char *needle, size_t nlen)
{
	const char *cur;
	const char *last;
	//assert(haystack);
	//assert(needle);
	//assert(nlen > 1);
	last = haystack + hlen - nlen;
	for (cur = haystack; cur <= last; ++cur)
	{
		if (cur[0] == needle[0] && memcmp(cur, needle, nlen) == 0)
		{
			return cur;
		}
	}
	return NULL;
}

///command struct
typedef struct
{
	//uint8_t type;
	uint8_t len;
	uint8_t opcode;
	uint8_t sum;//uint16_t
	uint8_t dIndx;
	uint8_t data_pkg[256];
	
}command_struct;

command_struct g_data;


#define CMD_SUCCESS 0x01
#define CMD_FAIL	     0x00

/////start process the data in
uint8_t uState = 0;
// static void user_cmd_buffer_clear(void)
// {
// 	uState = 0;
// 	g_data.len = 0;
// 	g_data.type = 0;
// 	g_data.opcode = 0;
// 	g_data.sum = 0;
// 	g_data.dIndx = 0;
// }


void user_send_cmd_response(uint8_t opCode, uint8_t rsp)
{
	// uint8_t sum = 0;
	// uint8_t responseBuffer[32] = {0};
	// responseBuffer[0] = 0x55;
	// responseBuffer[1] = 0x02;
	// responseBuffer[2] = 4;
	// responseBuffer[3] = opCode;
	// responseBuffer[4] = rsp;

	// sum += responseBuffer[2];
	// sum += responseBuffer[3];
	// sum += responseBuffer[4];

	// responseBuffer[5] = sum;

    //uart_write_bytes(UART_NUM_LCD, (const char *) data_rx, len_rx);
	//spear_uart_send_datas(responseBuffer, 6);
	;
}


bool spear_uart_process_data(uint8_t byt)
{
	bool retn = false;
    uint8_t data_t[64]={0};
    // uint8_t data_crc1=0;
    // uint8_t data_crc2=0;
	// UartSendStr(" %x: ", byt);
	// debug_uart_send_data2(byt,0x51);
	switch(uState)
	{
		case UART_IDLE:
		case UART_HEADER1:
			if(byt == 's')
			{
				retn = false;
				g_data.dIndx =0;
				uState = UART_HEADER2;
				//user_start_cmd_receive(true);
			}
			//UartSendStr("header = %02x\r\n", byt);
			break;

		case UART_HEADER2:
			if(byt == 't')
			{
				uState = UART_HEADER3;
				//user_start_cmd_receive(true);
			}
			//UartSendStr("header = %02x\r\n", byt);
			break;
		case UART_HEADER3:
			if(byt == 'a')
			{
				uState = UART_HEADER4;
				//user_start_cmd_receive(true);
			}
			//UartSendStr("header = %02x\r\n", byt);
			break;
		case UART_HEADER4:
			if(byt == 'r')
			{
				uState = UART_OPCODE;
				//user_start_cmd_receive(true);
			}
			//UartSendStr("header = %02x\r\n", byt);
			break;

		case UART_OPCODE:
			g_data.opcode = byt;

			if((0x8A == g_data.opcode)
				||(0x80 == g_data.opcode))
			{
				g_data.len =3+1;
			}
			else if((0x90 == g_data.opcode)
					||(0x91 == g_data.opcode)
					||(0xf1 == g_data.opcode)
					||(0xf2 == g_data.opcode))
			{
				g_data.len =1+1;
			}
			else
			{
				g_data.len =1+1;
			}
			//g_data.sum += byt;
            //g_data.sum = byt;
			uState++;
			//UartSendStr("opcode = %02x\r\n", byt);
			break;
		case UART_PAYLOAD:
			if(g_data.dIndx < g_data.len-1)//<   1
			{
				
				g_data.data_pkg[g_data.dIndx] = byt;
				//g_data.sum += byt;
				//UartSendStr("data_pkg[%d] = %02x\r\n",g_data.dIndx, byt);
                g_data.dIndx++;
				debug_uart_send_data2(g_data.dIndx,0x52);
			}
			else//crc2
			{
				
                g_data.data_pkg[g_data.dIndx] = byt;
                g_data.dIndx++;
				debug_uart_send_data2(g_data.dIndx,0x53);
				//user_start_cmd_receive(false);
				// uState = 0;//--------------
                data_t[0] = g_data.opcode;
                memcpy(data_t+1,g_data.data_pkg,g_data.len -1);//-1

                g_data.sum = ComputXor(data_t, g_data.len  );//+1

                // debug_uart_send_data2(g_data.sum,0x54);
				// debug_uart_send_data2(g_data.data_pkg[g_data.len-1],0x55);

				if(g_data.sum  == g_data.data_pkg[g_data.len-1] )//byt
				{
                    UartSendStr("---data rcv----1-pass\r\n");
					uState = UART_END1;
					// r = true;
				}
				else
				{
					uState =0;
                    UartSendStr("---data rcv----1-fail\r\n");
					// user_send_cmd_response(g_data.opcode, CMD_FAIL);
				}
			}
			break;


		case UART_END1:
			if(byt == 'e')
			{
				UartSendStr("----01---\r\n");
				uState++;
			}
			break;
		case UART_END2:
			if(byt == 'n')
			{
				uState++;
			}
			break;
		case UART_END3:
			if(byt == 'd')
			{
				uState++;
			}
			break;
		case UART_END4:
			if(byt == 'o')
			{
				UartSendStr("----02---\r\n");
				uState = UART_IDLE;
				retn = true;

				
			}
			break;

		case UART_RESERVE:
		default:
			break;
	}

	return retn;
}

//Queue Init
void QueueInit(struct FifoQueue *Queue)
{
   Queue->front = Queue->rear;
   Queue->count = 0;
}
// Queue In
uint8 QueueIn(struct FifoQueue *Queue,ElemType sdat)
{
   if((Queue->front == Queue->rear) && (Queue->count == QueueSize))
   {                   // full
       return QueueFull;
    }else
   {                   // in
       Queue->dat[Queue->rear] = sdat;
       Queue->rear = (Queue->rear + 1) % QueueSize;
       Queue->count = Queue->count + 1;
       return QueueOperateOk;
    }
}
// Queue Out
uint8 QueueOut(struct FifoQueue *Queue,ElemType *sdat)
{
   if((Queue->front == Queue->rear) && (Queue->count == 0))
   {                   // empty
       return QueueEmpty;
    }else
   {                   // out
       *sdat = Queue->dat[Queue->front];
       Queue->front = (Queue->front + 1) % QueueSize;
       Queue->count = Queue->count - 1;
       return QueueOperateOk;
    }
}

u8 queue_rcv_over;
struct FifoQueue MyQueue;


// str = (char*)malloc(50 * sizeof(char)); //给字符串str分配 50字节空间
/******************************************************************************/
//-------main-------

/******************************************************************************/
void main(void)
{
	char *retvalue_star=NULL;
	//内存分配，比如字符串内存动态分配
	char *str=NULL;
	
	unsigned char dat_rcv=0 ;
//	uint16 ADC_RES;
	uint32_t tick_times=0;
	int i=0;
	u8 red_flag=0;
	
    ElemType sh;

	
	Uart1Init();
//	Timer4_Init();
	Timer0_Init();
	ES = 1;
	EA = 1;
//	Read_ID_fromROM();	
////	ADC_Init();
//	PWM0_INIT();
//	PCA_INIT();
	
	gpio_init();


	for(i=0;i<5;i++)
	{
		LED1=0;//on
		delay_ms(50); 
		LED1=1;
		delay_ms(50); 
	}


	RS485_RX_EN();

	UartSendStr("power on !!!\r\n");
	UartSendStr("power on--2222 !!!\r\n");
	

   QueueInit(&MyQueue);
   while(1)
    {

	   if(0==packerflag)
       {
           if(QueueOut(&MyQueue,&sh) == QueueEmpty) 
		   {
			// debug_uart_send_data2(i,0x53);	
		   	// break;			   
		   }
		   else
		   {
		   	// debug_uart_send_data2(sh,0x55);		
			if(spear_uart_process_data(sh))
			{
				// retn = false;
				UartSendStr("----11---\r\n");
				packerflag =1;




				debug_uart_send_data2(g_data.len,0x56);
				// spear_uart_send_datas(g_data.data_pkg,g_data.len);

				Uart1_Buffer[0] = g_data.opcode;
				memcpy(Uart1_Buffer+1,g_data.data_pkg,g_data.len );//-1
				// Uart1_Buffer[g_data.len] = g_data.sum;

				Uart1_Rx = g_data.len + 1;


				debug_uart_send_data2(Uart1_Rx,0x57);
				// spear_uart_send_datas(Uart1_Buffer,Uart1_Rx);
				data_parse(Uart1_Buffer,Uart1_Rx);

				
				//memset(RX1_Buffer,0,13);//max =4+5+4 =13
				// memset(RX1_Buffer,0,RX_Length);
				// RX_write =0;//add

				memset(Uart1_Buffer,0,RX_Length);
				Uart1_Rx   = 0 ;
				packerflag = 0;

			}
			else
			{
				// UartSendStr("----10---\r\n");;
			}


		   }

       }

		tick_times++;
		if(0==red_flag)
		{
			if(tick_times%40000==0)//1000
			{
				tick_times =0;
				red_flag =1;
				LED1=0;	//on
				//UartSendStr("power on !!!\r\n");
			}
		}
		else
		{
			if(tick_times%4000==0)//100
			{
				red_flag =0;
				LED1=1;
			}
		}
		// delay_ms(1); 
	}
}

