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



typedef uint32_t  u32;
typedef uint16_t u16;
typedef uint8_t  u8;

/* 全局运行参数定义 */
//#define FOSC   11059200L  //系统主时钟频率，即振荡器频率÷12
#define FOSC   20000000L  //系统主时钟频率，即振荡器频率÷12
#define	BRT	(65536 - FOSC / 115200 / 4)

#define F125KHZ (65536-(FOSC/2/125000/12))


#define PGACOUNT      0x07

/* IO引脚分配定义 */

sbit LED  = P0^0;	//P5^4;
sbit LED1 = P0^0;	//P2^6;


	sbit GI_1 = P1^7;//
	sbit GO_1 = P1^6;	//

	sbit GI_2 = P4^4;//
	sbit GO_2 = P1^5;	//

	sbit GI_3 = P1^4;//
	sbit GO_3 = P6^3;	//
	
		sbit GI_8 = P0^0;	//
		sbit GO_8 = P0^0;	//
	
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

/*控制收发引脚*/
#if 0
//进入接收模式,必须要有延时等待485处理完数据
//#define RS485_RX_EN()						delay_ms(10);RS485_delay(1000); RS485_RE=0;  			delay_ms(10);RS485_delay(1000);
////进入发送模式,必须要有延时等待485处理完数据
//#define RS485_TX_EN()						delay_ms(10);RS485_delay(1000); RS485_RE=1;  			delay_ms(10);RS485_delay(1000);

#else

#define RS485_RX_EN()						RS485_delay(1000); RS485_RE=0;  			RS485_delay(1000);
//进入发送模式,必须要有延时等待485处理完数据
#define RS485_TX_EN()						RS485_delay(1000); RS485_RE=1;  			RS485_delay(1000);


#endif

#endif