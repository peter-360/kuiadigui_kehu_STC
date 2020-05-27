/*                        -- ¶ÉºÓÂìÒÏµç×Ó¹¤×÷ÊÒ --                        */
/*
*   Ëµ    Ã÷: STC8A8KS4A12 DEMO³ÌĞò
*   ¿ª·¢Æ½Ì¨: STC15W408S     
*   ÌÔ±¦Íøµê: 
*
//  ÎÄ¼şÃû£ºmain.c                                                              
//  ËµÃ÷£º¹©¿Í»§²âÊÔÄ£¿éÍ¨ĞÅÊ¹ÓÃ³ÌĞò                                                                  
//  ±àĞ´ÈËÔ±£ºDuhemayi                                                                   
//  ±àĞ´ÈÕÆÚ£º2018-09-16                                                               
//  ³ÌĞòÎ¬»¤£º
//  Î¬»¤¼ÇÂ¼£º
//	°æ    ±¾: V1.0
//                                                          
// ÃâÔğÉùÃ÷£º¸Ã³ÌĞò½öÓÃÓÚÑ§Ï°Óë½»Á÷ 
// (c) Duhemayi Corporation. All rights reserved.     
******************************************************************************/
#include "config.h"







void spear_uart_send_datas(uint8* str, uint8 len)
{
	while(len--)
	{
//		USART_SendData(USART1, *str);
//		while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET); 
//		str++;
		UartSend(*str++);
	}
}

void debug_uart_send_datas(uint8* str, uint8 len)
{
	UartSend(0xee);
	while(len--)
	{
//		USART_SendData(USART1, *str);
//		while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET); 
//		str++;
		UartSend(*str++);
	}
	UartSend(0xff);
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

void data_parse()
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
	
	//SEGGER_RTT_printf(0, "-parse-Uart1_Rx = %d\n",Uart1_Rx);      //RTT´òÓ¡
	Uart1_Rx_T = Uart1_Rx - 8;
	//SEGGER_RTT_printf(0, "-Uart1_Rx_T = %d\n",Uart1_Rx_T);      //RTT´òÓ
	memcpy(Uart1_Buffer_T,Uart1_Buffer+4,Uart1_Rx_T);
	
	DSW_T_1 = ~DSW_1;
	DSW_T_2 = ~DSW_2;
	DSW_T_3 = ~DSW_3;
	DSW_T_4 = ~DSW_4;
	DSW_T_5 = ~DSW_5;
	DSW_T_6 = ~DSW_6;
	board_addr= DSW_T_1 | (DSW_T_2<<1) | (DSW_T_3<<2) | (DSW_T_4<<3) | (DSW_T_5<<4) | (DSW_T_6<<5) ;
	
	//UartSend(board_addr);
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
							switch(m_data.lock_addr)
							{			
								case 1:
									GO_1=1; 					//open
									delay_ms(20);  
									GO_1=0;						//close
									delay_ms(20);  
								
									GO_1=1;
									GI_1=1;
								
									GO_2=1;
									GI_2=1;
								
									GO_3=1;
									GI_3=1;

									

									
									gpio_level = 0x01;
									//gpio_level= GI_1;
									//SEGGER_RTT_printf(0, "%d:gpio_level = %x\n",m_data.lock_addr,gpio_level);
									UartSendStr("\r\n--1--\r\n");
									break;
								
								case 2:
									GO_2=1;							 //open
									delay_ms(20);  
									GO_2=0;	 						 //close
									delay_ms(20);

								
									GO_1=0;
									GI_1=0;
									
									GO_2=0;
									GI_2=0;
								
									GO_3=0;
									GI_3=0;
								

									
									//gpio_level= GI_2;
									gpio_level = 0x01;
									//SEGGER_RTT_printf(0, "%d:gpio_level = %x\n",m_data.lock_addr,gpio_level);
									UartSendStr("\r\n--2--\r\n");
									break;
								
								
								case 3:
									GO_3=0;							 //open
									delay_ms(20);  
									GO_3=1;	 						 //close
									delay_ms(20);  
									
//									GO_3=1; 					//open
//									delay_ms(20);  
//									GO_3=0;						//close
//									delay_ms(20);  

									gpio_level = 0x01;
									//gpio_level= GI_1;
									//SEGGER_RTT_printf(0, "%d:gpio_level = %x\n",m_data.lock_addr,gpio_level);
									UartSendStr("\r\n--3--\r\n");
									break;
								
								default:
									break;

							}
							
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
//							spear_rtt_send_datas(tx_Buffer,12);

							//SEGGER_RTT_printf(0, "ok,m_data.opcode=%02x\n",m_data.opcode);
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
		
		
		
	}

}




/******************************************************************************/
// º¯ÊıÃû³Æ£ºmain 
// ÊäÈë²ÎÊı£º 
// Êä³ö²ÎÊı£º 
// º¯Êı¹¦ÄÜ£º 
/******************************************************************************/
void main(void)
{
//	uint16 ADC_RES;
		
	Uart1Init();
//	Timer4_Init();
	Timer0_Init();
	ES = 1;
	EA = 1;
//	Read_ID_fromROM();	
////	ADC_Init();
//	PWM0_INIT();
//	PCA_INIT();
	
	
	RS485_RX_EN();

	UartSendStr("Uart Test 1!\r\n");
	while(1)
	{
		if((1== packerflag))
		{
			RS485_TX_EN();

//			SEGGER_RTT_printf(0, "\n");
//			SEGGER_RTT_printf(0, "-main-Uart1_Rx = %d\n",Uart1_Rx);      //RTT´òÓ¡
//			SEGGER_RTT_printf(0, "---rcv-datas---"); 
			//spear_rtt_send_datas(Uart1_Buffer,Uart1_Rx);
			
			//spear_uart_send_datas(Uart1_Buffer,Uart1_Rx); //debug


			data_parse();
			RS485_RX_EN();
			
			memset(Uart1_Buffer,0,13);//max =4+5+4 =13
			Uart1_Rx   = 0 ;
			packerflag = 0;
			//Uart1_index_flag_end =0;
		}
		
	
		
	}
}





//		LED1 = 0;
////		GO_1 = 0;
//		Delay100ms();
//		Delay100ms();
//		Delay100ms();
//		Delay100ms();
//		Delay100ms();
//		LED1 = 1;
////		GO_1 =1;
//		Delay100ms();
//		Delay100ms();
//		Delay100ms();
//		Delay100ms();
//		Delay100ms();

//		ADC_RES = Get_ADC_RES();
//		UartSend(ADC_RES);
//		ADC_RES = ADC_RES>>8;
//		UartSend(ADC_RES>>8);
		

//		UartSend(length);
//		UartSend(length>>8);
//		UartSend(length>>16);
//		UartSend(length>>24);
//		RS485_RX_EN();
//		UartSendStr("Uart Test 2 -RX!\r\n");
//		delay_ms(4000);
//		
//		RS485_TX_EN();
//		UartSendStr("Uart Test 3 -TX!\r\n");//no xianshi
//		delay_ms(2100);
