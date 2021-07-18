#ifndef __GPIO_H__
#define __GPIO_H__
#include "stm32f10x.h"

/******************  M32设置位  *******************/
#define M32_SET_BIT_00              ((uint32_t)0x00000001)
#define M32_SET_BIT_01              ((uint32_t)0x00000002)
#define M32_SET_BIT_02              ((uint32_t)0x00000004)
#define M32_SET_BIT_03              ((uint32_t)0x00000008)
#define M32_SET_BIT_04              ((uint32_t)0x00000010)
#define M32_SET_BIT_05              ((uint32_t)0x00000020)
#define M32_SET_BIT_06              ((uint32_t)0x00000040)
#define M32_SET_BIT_07              ((uint32_t)0x00000080)
#define M32_SET_BIT_08              ((uint32_t)0x00000100)
#define M32_SET_BIT_09              ((uint32_t)0x00000200)
#define M32_SET_BIT_10              ((uint32_t)0x00000400)
#define M32_SET_BIT_11              ((uint32_t)0x00000800)
#define M32_SET_BIT_12              ((uint32_t)0x00001000)
#define M32_SET_BIT_13              ((uint32_t)0x00002000)
#define M32_SET_BIT_14              ((uint32_t)0x00004000)
#define M32_SET_BIT_15              ((uint32_t)0x00008000)
#define M32_SET_BIT_16              ((uint32_t)0x00010000)
#define M32_SET_BIT_17              ((uint32_t)0x00020000)
#define M32_SET_BIT_19              ((uint32_t)0x00040000)
#define M32_SET_BIT_19              ((uint32_t)0x00080000)
#define M32_SET_BIT_20              ((uint32_t)0x00100000)
#define M32_SET_BIT_21              ((uint32_t)0x00200000)
#define M32_SET_BIT_22              ((uint32_t)0x00400000)
#define M32_SET_BIT_23              ((uint32_t)0x00800000)
#define M32_SET_BIT_24              ((uint32_t)0x01000000)
#define M32_SET_BIT_25              ((uint32_t)0x02000000)
#define M32_SET_BIT_26              ((uint32_t)0x04000000)
#define M32_SET_BIT_27              ((uint32_t)0x08000000)
#define M32_SET_BIT_28              ((uint32_t)0x10000000)
#define M32_SET_BIT_29              ((uint32_t)0x20000000)
#define M32_SET_BIT_30              ((uint32_t)0x40000000)
#define M32_SET_BIT_31              ((uint32_t)0x80000000)
/******************  M16设置位  *******************/
#define M16_SET_BIT_00              ((uint16_t)0x0001)
#define M16_SET_BIT_01              ((uint16_t)0x0002)
#define M16_SET_BIT_02              ((uint16_t)0x0004)
#define M16_SET_BIT_03              ((uint16_t)0x0008)
#define M16_SET_BIT_04              ((uint16_t)0x0010)
#define M16_SET_BIT_05              ((uint16_t)0x0020)
#define M16_SET_BIT_06              ((uint16_t)0x0040)
#define M16_SET_BIT_07              ((uint16_t)0x0080)
#define M16_SET_BIT_08              ((uint16_t)0x0100)
#define M16_SET_BIT_09              ((uint16_t)0x0200)
#define M16_SET_BIT_10              ((uint16_t)0x0400)
#define M16_SET_BIT_11              ((uint16_t)0x0800)
#define M16_SET_BIT_12              ((uint16_t)0x1000)
#define M16_SET_BIT_13              ((uint16_t)0x2000)
#define M16_SET_BIT_14              ((uint16_t)0x4000)
#define M16_SET_BIT_15              ((uint16_t)0x8000)
/******************  M16设置位  *******************/


/**************************************************************
                   AFIO_EVCR_事件控制寄存器
7       EVOE位“1”允许事件输出 (Event output enable)
6:4     端口选择, 选择用于输出Cortex的EVENTOUT信号的端口
000     选择GPIOA
001     选择GPIOB
010     选择GPIOC
011     选择GPIOD
100     选择GPIOE
3:0     引脚选择(x=A…E), 选择用于输出Cortex的EVENTOUT信号的引脚
0000    选择GPIOx_PIN_0
0001    选择GPIOx_PIN_1
0010    选择GPIOx_PIN_2
0011    选择GPIOx_PIN_3
........................
1111    选择GPIOx_PIN_15
**************************************************************/


/**************************************************************
                AFIO_EXTICR1_外部中断配置寄存器 1
EXTIx[3:0]      EXTIx配置(x = 0 … 3) (EXTI x configuration) 
                这些位可由软件读写，用于选择 EXTI0~EXTI3 外部中断的输入源
0000            GPIOA[x]引脚 
0001            GPIOB[x]引脚 
0011            GPIOD[x]引脚
0100            GPIOE[x]引脚
0101            GPIOF[x]引脚
0110            GPIOG[x]引脚
                AFIO_EXTICR2_外部中断配置寄存器 2
EXTIx[3:0]      EXTIx配置(x = 4 … 7) (EXTI x configuration) 
                这些位可由软件读写，用于选择 EXTI4~EXTI7 外部中断的输入源
0000            GPIOA[x]引脚 
0001            GPIOB[x]引脚 
0011            GPIOD[x]引脚
0100            GPIOE[x]引脚
0101            GPIOF[x]引脚
0110            GPIOG[x]引脚
                AFIO_EXTICR3_外部中断配置寄存器 3
EXTIx[3:0]      EXTIx配置(x = 8 … 11) (EXTI x configuration) 
                这些位可由软件读写，用于选择 EXTI8~EXTI11 外部中断的输入源
0000            GPIOA[x]引脚 
0001            GPIOB[x]引脚 
0011            GPIOD[x]引脚
0100            GPIOE[x]引脚
0101            GPIOF[x]引脚
0110            GPIOG[x]引脚
                AFIO_EXTICR4_外部中断配置寄存器 4
EXTIx[3:0]      EXTIx配置(x = 12 … 15) (EXTI x configuration) 
                这些位可由软件读写，用于选择 EXTI12~EXTI15 外部中断的输入源
0000            GPIOA[x]引脚 
0001            GPIOB[x]引脚 
0011            GPIOD[x]引脚
0100            GPIOE[x]引脚
0101            GPIOF[x]引脚
0110            GPIOG[x]引脚
**************************************************************/


/**************************************************************
EXTI_IMR_中断屏蔽寄存器
31:20           保留,必须始终保持为复位状态(0)
19:0            MR0~MR19 线 0~19上的中断屏蔽
0               屏蔽来自线0~19上的中断请求
1               开放来自线0~19上的中断请求
注:位19只适用于互联型产品,对于其它产品为保留位


EXTI_EMR_事件屏蔽寄存器
31:20           保留,必须始终保持为复位状态(0)
19:0            MR0~MR19 线 0~19上的事件屏蔽
0               屏蔽来自线0~19上的事件请求
1               开放来自线0~19上的事件请求
注:位19只适用于互联型产品,对于其它产品为保留位


EXTI_RTSR_上升沿触发选择寄存器
31:20           保留,必须始终保持为复位状态(0)
19:0            TR0~TR19 线 0~19上的上升沿触发事件配置位
0               禁止输入线 0~19上的上升沿触发(中断和事件)
1               允许输入线 0~19上的上升沿触发(中断和事件)
注:位19只适用于互联型产品,对于其它产品为保留位


EXTI_FTSR_下降沿触发选择寄存器
31:20           保留,必须始终保持为复位状态(0)
19:0            TR0~TR19 线 0~19上的下降沿触发事件配置位
0               禁止输入线 0~19上的下降沿触发(中断和事件)
1               允许输入线 0~19上的下降沿触发(中断和事件)
注:位19只适用于互联型产品,对于其它产品为保留位


EXTI_SWIER_软件中断事件寄存器
31:20           保留,必须始终保持为复位状态(0)
19:0            SWIER0~SWIER19 线0~19上的软件中断
当该位为“0”时,写“1”将设置 EXTI_PR 中相应的挂起位。
如果在 EXTI_IMR 和 EXTI_EMR中允许产生该中断,则产生中断请求。
通过清除 EXTI_PR 的对应位(写入“1”),可以清除该位为“0”。
注:位19只适用于互联型产品,对于其它产品为保留位


EXTI_PR_挂起寄存器
31:20           保留,必须始终保持为复位状态(0)
19:0
0		没有发生触发请求
1		发生了选择的触发请求
当在外部中断线上发生了选择的边沿事件,该位被置“1”。在此位中写入“1”可以清除它,
也可以通过改变边沿检测的极性清除。
注:位19只适用于互联型产品,对于其它产品为保留位
**************************************************************/
#endif
