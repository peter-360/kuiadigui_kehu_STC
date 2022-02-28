/*                        -- 渡河蚂蚁电子工作室 --                        */
/*
*   说    明: CS1180驱动
*   开发平台: STC15W408S     
*   淘宝网店: 
*
//  文件名：uart.h                                                              
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
#ifndef __UART_H
#define __UART_H

#include "config.h"


/**
    用途：     小内存环形缓冲区（FIFO模式）
    作者： 南栀<kellygod95@gmail.com>
*/
// #define BUFFER_MAX  64
// //16      //缓冲区大小

// typedef struct _circle_buffer{
//     unsigned char head_pos;             //缓冲区头部位置
//     unsigned char tail_pos;             //缓冲区尾部位置   
//     unsigned char circle_buffer[BUFFER_MAX];    //缓冲区数组 
// }circle_buffer;


//  #define QUEUE_MAX 64  
// typedef struct ringq{  
//     int head;   
//     int tail;    
//     int tag ;   
//      int size_t ;   
//     unsigned char space[QUEUE_MAX];   
// }RINGQ;  
 
// extern int ringq_init(RINGQ * p_queue);  
// extern int ringq_free(RINGQ * p_queue);    
// extern int ringq_push(RINGQ * p_queue,int data_t);  
// extern int ringq_poll(RINGQ * p_queue,int *p_data);  
// #define ringq_is_empty(q) ( (q->head == q->tail) && (q->tag == 0))  
// #define ringq_is_full(q) ( (q->head == q->tail) && (q->tag == 1))  
// #define print_ringq(q) printf("ring head %d,tail %d,tag %d\n", q->head,q->tail,q->tag);  

// extern RINGQ rq, * p_queue;


void Uart1Init(void);
void UartSend(unsigned char dat);
void UART1_IOPORT_CHANGE(void);
void UartSendStr(unsigned char *p);



extern unsigned char Uart1_Buffer[];
extern unsigned char Uart1_Rx ;
extern unsigned char packerflag;




extern void debug_uart_send_datas(unsigned char* str, unsigned char len);
extern int bufferPop(unsigned char* _buf);
extern void UartSend_dbg(unsigned char dat);
//extern circle_buffer buffer;




#define UART_DBG_P 0//printf
#define UART_DBG_0 0
#define UART_DBG_1 0
#define UART_DBG_2 0
#endif
