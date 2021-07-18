#ifndef __GPIO_H__
#define __GPIO_H__
#include "stm32f10x.h"

/******************************************************************************/
/*                                                                            */
/*                     STM32F10X___GPIO___位带操作                             */
/*                                                                            */
/******************************************************************************/
#define  GPIOA_ODR_A  (GPIOA_BASE + 0x0C)
#define  GPIOA_IDR_A  (GPIOA_BASE + 0x08)
#define  GPIOB_ODR_B  (GPIOB_BASE + 0x0C)
#define  GPIOB_IDR_B  (GPIOB_BASE + 0x08)
#define  GPIOC_ODR_C  (GPIOC_BASE + 0x0C)
#define  GPIOC_IDR_C  (GPIOC_BASE + 0x08)
#define  GPIOD_ODR_D  (GPIOD_BASE + 0x0C)
#define  GPIOD_IDR_D  (GPIOD_BASE + 0x08)
#define  GPIOE_ODR_E  (GPIOE_BASE + 0x0C)
#define  GPIOE_IDR_E  (GPIOE_BASE + 0x08)
#define  GPIOF_ODR_F  (GPIOF_BASE + 0x0C)
#define  GPIOF_IDR_F  (GPIOF_BASE + 0x08)
#define  GPIOG_ODR_G  (GPIOG_BASE + 0x0C)
#define  GPIOG_IDR_G  (GPIOG_BASE + 0x08)
#define BitBand(Addr, BitNum)  *((volatile unsigned long *)\
((Addr & 0xF0000000) + 0x2000000 + ((Addr & 0xFFFFF) << 5) + (BitNum << 2)))
#define PA_IN(n) 	BitBand(GPIOA_IDR_A, n)
#define PA_OUT(n) 	BitBand(GPIOA_ODR_A, n)
#define PB_IN(n) 	BitBand(GPIOB_IDR_B, n)
#define PB_OUT(n) 	BitBand(GPIOB_ODR_B, n)
#define PC_IN(n) 	BitBand(GPIOC_IDR_C, n)
#define PC_OUT(n) 	BitBand(GPIOC_ODR_C, n)
#define PD_IN(n) 	BitBand(GPIOD_IDR_D, n)
#define PD_OUT(n) 	BitBand(GPIOD_ODR_D, n)
#define PE_IN(n) 	BitBand(GPIOE_IDR_E, n)
#define PE_OUT(n) 	BitBand(GPIOE_ODR_E, n)
#define PF_IN(n) 	BitBand(GPIOF_IDR_F, n)
#define PF_OUT(n) 	BitBand(GPIOF_ODR_F, n)
#define PG_IN(n) 	BitBand(GPIOG_IDR_G, n)
#define PG_OUT(n) 	BitBand(GPIOG_ODR_G, n)




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

void gpio_mode_setup(void);
void gpio_bit_setup(void);
void gpio_swd_setup(void);
#endif
