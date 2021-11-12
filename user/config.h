/*                        -- 渡河蚂蚁电子工作室 --                        */
/*
*   说    明: CS1180驱动
*   开发平台: STC15W408S     
*   淘宝网店: 
*
//  文件名：config.h                                                              
//  说明：供客户测试单片机的各项基本功能                                                                 
//  编写人员：Duhemayi                                                                   
//  编写日期：2018-09-16                                                               
//  程序维护：
//  维护记录：
//	版    本: V1.0
//                                                          
// 免责声明：该程序仅用于学习与交流 
// (c) Duhemayi Corporation. All rights reserved.     
******************************************************************************/
#ifndef _CONFIG_H
#define _CONFIG_H

/* 通用头文件 */
#include <STC8A.h>
#include <intrins.h>

#include "uart.h"
#include "stc8aid.h"
#include "delay.h"
#include "IO.h"
#include "timer.h"
#include "adc.h"
#include "pwm.h"
#include "pca.h"
#include "string.h"



#define SOFT_VERSION_1  0x00
#define SOFT_VERSION_2  0x00
#define SOFT_VERSION_3  0x02

#define HARD_VERSION_1  'S'
#define HARD_VERSION_2  'T'
#define HARD_VERSION_3  '1'
#define HARD_VERSION_4  'B'



/* 数据类型定义 */
typedef  signed    char    int8;    // 8位有符号整型数
typedef  signed    int     int16;   //16位有符号整型数
typedef  signed    long    int32;   //32位有符号整型数
typedef  unsigned  char    uint8;   // 8位无符号整型数
typedef  unsigned  int     uint16;  //16位无符号整型数
typedef  unsigned  long    uint32;  //32位无符号整型数


typedef  signed    char    int8_t;    // 8位有符号整型数
typedef  signed    int     int16_t;   //16位有符号整型数
typedef  signed    long    int32_t;   //32位有符号整型数
typedef  unsigned  char    uint8_t;   // 8位无符号整型数
typedef  unsigned  int     uint16_t;  //16位无符号整型数
typedef  unsigned  long    uint32_t;  //32位无符号整型数

typedef enum
{
    true=1, false=0
}bool;



typedef uint32_t  u32;
typedef uint16_t u16;
typedef uint8_t  u8;

/* 全局运行参数定义 */
//------24MHz on use--------
//#define FOSC   11059200L  //系统主时钟频率，即振荡器频率÷12
// #define FOSC   20000000L  //系统主时钟频率，即振荡器频率÷12
// #define	BRT	(65536 - FOSC / 115200 / 4)
// #define F125KHZ (65536-(FOSC/2/125000/12))
// #define PGACOUNT      0x07

/* IO引脚分配定义 */

sbit LED  = P0^0;	//P5^4;
sbit LED1 = P0^0;	//P2^6;


	sbit GI_1 = P3^2;//
	sbit GO_1 = P3^3;	//

	sbit GI_2 = P3^5;//
	sbit GO_2 = P3^4;	//

	sbit GI_3 = P6^6;//
	sbit GO_3 = P5^0;	//
	
	sbit GI_4 = P3^6;//
	sbit GO_4 = P5^1;	//

	sbit GI_5 = P3^7;//
	sbit GO_5 = P4^1;	//

	sbit GI_6 = P7^1;//
	sbit GO_6 = P7^0;	//
	
	sbit GI_7 = P7^2;//
	sbit GO_7 = P6^7;	//
	
	sbit GI_8 = P2^0;//
	sbit GO_8 = P7^3;	//
	
	sbit GI_9 = P4^2;//
	sbit GO_9 = P2^1;	//
	
	sbit GI_10 = P2^3;//
	sbit GO_10 = P2^2;	//

	sbit GI_11 = P2^4;//
	sbit GO_11 = P2^5;	//

	sbit GI_12 = P2^7;//
	sbit GO_12 = P2^6;	//



	sbit GI_13 = P6^4;//
	sbit GO_13 = P4^0;	//
	
	sbit GI_14 = P5^4;//
	sbit GO_14 = P5^5;	//
	


	
	sbit GI_15 = P1^7;//
	sbit GO_15 = P1^6;	//

	sbit GI_16 = P4^4;//
	sbit GO_16 = P1^5;	//

	sbit GI_17 = P1^4;//
	sbit GO_17 = P6^3;	//

	sbit GI_18 = P6^1;//
	sbit GO_18 = P6^2;	//

	sbit GI_19 = P6^0;	//
	sbit GO_19 = P1^3;//


	
	sbit GI_20 = P0^7;//
	sbit GO_20 = P1^2;	//
	
	
	sbit GI_21 = P0^6;//
	sbit GO_21 = P1^1;	//

	sbit GI_22 = P0^5;//
	sbit GO_22 = P5^3;	//
	
	
	
	sbit GI_23 = P0^4;//
	sbit GO_23 = P5^2;	//
	
	sbit GI_24 = P0^3;//
	sbit GO_24 = P1^0;	//
	



sbit DSW_1 = P0^2;	//
sbit DSW_2 = P7^4;	//
sbit DSW_3 = P7^5;	//
sbit DSW_4 = P7^6;	//
sbit DSW_5 = P7^7;	//
sbit DSW_6 = P4^3;	//

sbit RS485_RE = P6^5;	//

	/// 不精确的延时
static void RS485_delay( u32 nCount)//__IO
{
	for(; nCount != 0; nCount--);
} 


//6000
#define DELAY_485 1000
/*控制收发引脚*/
#if 0
//进入接收模式,必须要有延时等待485处理完数据
//#define RS485_RX_EN()						delay_ms(10);RS485_delay(1000); RS485_RE=0;  			delay_ms(10);RS485_delay(1000);
////进入发送模式,必须要有延时等待485处理完数据
//#define RS485_TX_EN()						delay_ms(10);RS485_delay(1000); RS485_RE=1;  			delay_ms(10);RS485_delay(1000);

#else

#define RS485_RX_EN() RS485_delay(DELAY_485); RS485_RE=0; RS485_delay(DELAY_485);
//进入发送模式,必须要有延时等待485处理完数据
#define RS485_TX_EN() RS485_delay(DELAY_485); RS485_RE=1; RS485_delay(DELAY_485);



#define	RX_Length	256





///command enum
typedef enum UART_STATE_ENUM
{
	UART_IDLE =0,
	UART_HEADER1,
	UART_HEADER2,
	UART_HEADER3,
	UART_HEADER4,
	// UART_TYPE,
	// UART_LENGTH,
	UART_OPCODE,
	UART_PAYLOAD,
	// UART_CHECKSUM,
	// UART_RESERVE,
	UART_END1,
	UART_END2,
	UART_END3,
	UART_END4,
	UART_RESERVE,
}  UART_STATE_ENUM;










//20 128
#define ElemType      uint8_t
#define QueueSize     128
#define QueueFull     0
#define QueueEmpty    1
#define QueueOperateOk 2
// typedef 
struct FifoQueue
{
    uint16_t front;
    uint16_t rear;
    uint16_t count;
    ElemType dat[QueueSize];
};
//Queue Initalize
extern void QueueInit(struct FifoQueue *Queue);
// Queue In
extern uint8 QueueIn(struct FifoQueue *Queue,ElemType sdat);
// Queue Out
extern uint8 QueueOut(struct FifoQueue *Queue,ElemType *sdat);







#endif

#endif