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
//char buffer[16];

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

void UartSend_dbg(uint8 dat)
{
    // RS485_TX_EN();

	// SBUF =0xAA;
	// while(!TI);
	// TI =0;


	// SBUF =dat;
	// while(!TI);
	// TI =0;


	// SBUF =0x55;
	// while(!TI);
	// TI =0;

    // RS485_RX_EN();
}

/******************************************************************************/
// 函数名称：uartSendString 
// 输入参数：pS: 字符串首地址 
// 输出参数：无 
// 函数功能：发送字符串通过串口输出 
/******************************************************************************/
void UartSendStr(uint8 *p)
{
    // RS485_TX_EN();
    // while (*p)
    // {
    //     UartSend(*p++);
    // }
    // RS485_RX_EN();
}







unsigned char Uart1_index_flag=0,Uart1_index_flag_end=0;                //???????

unsigned char Uart1_Buffer[256];        //?????
//unsigned char Uart1_Rx = 0;             //Uart1_Buffer??
uint8_t Uart1_Rx = 0;             //Uart1_Buffer??
unsigned char packerflag=0;




// circle_buffer buffer;

// int bufferPop(unsigned char* _buf)
// {
//     if(buffer.head_pos==buffer.tail_pos)        //如果头尾接触表示缓冲区为空
// 	{

//         *_buf=0xFF;		
// 		return -1;
// 	}

//     else
//     {
//         *_buf=buffer.circle_buffer[buffer.head_pos];    //如果缓冲区非空则取头节点值并偏移头节点
//         if(++buffer.head_pos>=BUFFER_MAX)
//             buffer.head_pos=0;

// 		return 1;
//     }


// }

// void bufferPush(const unsigned char _buf)
// {   
//     buffer.circle_buffer[buffer.tail_pos]=_buf; //从尾部追加
//     if(++buffer.tail_pos>=BUFFER_MAX)           //尾节点偏移
//         buffer.tail_pos=0;                      //大于数组最大长度 制零 形成环形队列
//         if(buffer.tail_pos==buffer.head_pos)    //如果尾部节点追到头部节点 则修改头节点偏移位置丢弃早期数据
//         if(++buffer.head_pos>=BUFFER_MAX)
//             buffer.head_pos=0;

// }





extern struct FifoQueue MyQueue;
extern void debug_uart_send_data2(uint8_t str,uint8_t dbg_data);
/******************************************************************************/
// 函数名称：time0ISR 
// 输入参数：无 
// 输出参数：无 
// 函数功能：串口0服务函数 
/******************************************************************************/
void Uart1Isr() interrupt 4 using 1
{
    uint8 ch;
	if(RI)
    {
        RI=0;    
        ch = SBUF;


        // bufferPush(SBUF);
        if(QueueIn(&MyQueue,ch) == QueueFull) 
        {
            //debug_uart_send_data2(ch,0x52);	
            //break;			   
        }
        else
        {
            //debug_uart_send_data2(ch,0x54);			   
        }
        
		// ringq_push(p_queue,SBUF);

    }
    if(TI)
    {
        TI=0;
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








