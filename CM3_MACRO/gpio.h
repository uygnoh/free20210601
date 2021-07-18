#ifndef __GPIO_H__
#define __GPIO_H__
/******************  Bit definition   *******************/
#define MACRO_BIT_0         ((uint32_t)0x00000001)
#define MACRO_BIT_1         ((uint32_t)0x00000002)
#define MACRO_BIT_2         ((uint32_t)0x00000004)
#define MACRO_BIT_3         ((uint32_t)0x00000008)
#define MACRO_BIT_4         ((uint32_t)0x00000010)
#define MACRO_BIT_5         ((uint32_t)0x00000020)
#define MACRO_BIT_6         ((uint32_t)0x00000040)
#define MACRO_BIT_7         ((uint32_t)0x00000080)
#define MACRO_BIT_8         ((uint32_t)0x00000100)
#define MACRO_BIT_9         ((uint32_t)0x00000200)
#define MACRO_BIT_10        ((uint32_t)0x00000400)
#define MACRO_BIT_11        ((uint32_t)0x00000800)
#define MACRO_BIT_12        ((uint32_t)0x00001000)
#define MACRO_BIT_13        ((uint32_t)0x00002000)
#define MACRO_BIT_14        ((uint32_t)0x00004000)
#define MACRO_BIT_15        ((uint32_t)0x00008000)

#define MACRO_BIT_16        ((uint32_t)0x00010000)
#define MACRO_BIT_17        ((uint32_t)0x00020000)
#define MACRO_BIT_18        ((uint32_t)0x00040000)
#define MACRO_BIT_19        ((uint32_t)0x00080000)
#define MACRO_BIT_20        ((uint32_t)0x00100000)
#define MACRO_BIT_21        ((uint32_t)0x00200000)
#define MACRO_BIT_22        ((uint32_t)0x00400000)
#define MACRO_BIT_23        ((uint32_t)0x00800000)
#define MACRO_BIT_24        ((uint32_t)0x01000000)
#define MACRO_BIT_25        ((uint32_t)0x02000000)
#define MACRO_BIT_26        ((uint32_t)0x04000000)
#define MACRO_BIT_27        ((uint32_t)0x08000000)
#define MACRO_BIT_28        ((uint32_t)0x10000000)
#define MACRO_BIT_29        ((uint32_t)0x20000000)
#define MACRO_BIT_30        ((uint32_t)0x40000000)
#define MACRO_BIT_31        ((uint32_t)0x80000000)

#define CLEAR_BIT_0         ((uint16_t)0x0001)
#define CLEAR_BIT_1         ((uint16_t)0x0002)
#define CLEAR_BIT_2         ((uint16_t)0x0004)
#define CLEAR_BIT_3         ((uint16_t)0x0008)
#define CLEAR_BIT_4         ((uint16_t)0x0010)
#define CLEAR_BIT_5         ((uint16_t)0x0020)
#define CLEAR_BIT_6         ((uint16_t)0x0040)
#define CLEAR_BIT_7         ((uint16_t)0x0080)
#define CLEAR_BIT_8         ((uint16_t)0x0100)
#define CLEAR_BIT_9         ((uint16_t)0x0200)
#define CLEAR_BIT_10        ((uint16_t)0x0400)
#define CLEAR_BIT_11        ((uint16_t)0x0800)
#define CLEAR_BIT_12        ((uint16_t)0x1000)
#define CLEAR_BIT_13        ((uint16_t)0x2000)
#define CLEAR_BIT_14        ((uint16_t)0x4000)
#define CLEAR_BIT_15        ((uint16_t)0x8000)

/* GPIOx_CRL {CNFy[1:0] MODEx[1:0]} x|y 0~7  */
/* GPIOx_CRH {CNFy[1:0] MODEx[1:0]} x|y 8~15 */
/* ______________________________________
0 0 0 0     (0)模拟输入
0 1 0 0     (4)浮空输入(复位后的状态) 
1 0 0 0     (8)下拉输入(PxODR = 0)
1 0 0 0     (8)上拉输入(PxODR = 1)
1 1 0 0     (C)保留

0 0 0 1     (1)推挽输出(10MHz)
0 0 1 0     (2)推挽输出( 2MHz)
0 0 1 1     (3)推挽输出(50MHz)

0 1 0 1     (5)开漏输出(10MHz)
0 1 1 0     (6)开漏输出( 2MHz)
0 1 1 1     (7)开漏输出( 2MHz)

1 0 0 1     (9)复用推挽输出(10MHz)
1 0 1 0     (A)复用推挽输出( 2MHz)
1 0 1 1     (B)复用推挽输出(50MHz)

1 1 0 1     (D)复用开漏输出(10MHz)
1 1 1 0     (E)复用开漏输出( 2MHz)
1 1 1 1     (F)复用开漏输出(50MHz)
______________________________________ */


void gpio_mode_setup(void)
{
	/* GPIOA 下拉输入模式 */
	GPIOA->CRL &= (uint32_t)(0xFFFFFFF0);	//PA0 清除要设置的位
	GPIOA->CRL |= (uint32_t)(0x00000008);	//PA0 输入下拉  
	GPIOA->ODR |= (uint32_t)(0 << 0);     	//(PxODR = 0)
	/* GPIOA 上拉输入模式 */
	GPIOA->CRL &= (uint32_t)(0xFFFFFFF0);	//PA0 清除要设置的位
	GPIOA->CRL |= (uint32_t)(0x00000008);	//PA0 输入上拉
	GPIOA->ODR |= (uint32_t)(1 << 0);     	//(PxODR = 1)

	/* USART1 */
	/* Tx(PA.09)_复用推挽输出(50MHz)   Rx(PA.10)_浮空输入 */
	GPIOA->CRH &= (uint32_t)(0xFFFFF00F);
	GPIOA->CRH |= (uint32_t)(0x000000B0);
	GPIOA->CRH |= (uint32_t)(0x00000400);
}

void gpio_bit_setup(void)
{
	/* 清除GPIOA_ODR第“0”位 */
	GPIOA->BRR = CLEAR_BIT_0;
	
	/* 清除GPIOA_ODR第“0”位(高16位清除) */
	GPIOA->BSRR = MACRO_BIT_16;
	/* 设置GPIOA_ODR第“0”位(低16位设置) */
	GPIOA->BSRR = MACRO_BIT_0;
}

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
               AFIO_MAPR_复用重映射和调试I/O配置寄存器
26:24   SWJ_CFG[2:0]：串行线JTAG配置 (Serial wire JTAG configuration)
        ！这些位只可由软件写(读这些位，将返回未定义的数据值)
000     完全SWJ(JTAG-DP + SW-DP)：复位状态； 
001     完全SWJ(JTAG-DP + SW-DP)但没有NJTRST；
010     关闭JTAG-DP，启用SW-DP； 
100     关闭JTAG-DP，关闭SW-DP；
**************************************************************/


/**************************************************************
                AFIO_EXTICR1_外部中断配置寄存器1
EXTIx[3:0]      EXTIx配置(x = 0 … 3) (EXTI x configuration) 
                这些位可由软件读写，用于选择 EXTI0~EXTI3 外部中断的输入源
0000            GPIOA[x]引脚 
0001            GPIOB[x]引脚 
0011            GPIOD[x]引脚
0100            GPIOE[x]引脚
0101            GPIOF[x]引脚
0110            GPIOG[x]引脚
                AFIO_EXTICR2_外部中断配置寄存器2
EXTIx[3:0]      EXTIx配置(x = 4 … 7) (EXTI x configuration) 
                这些位可由软件读写，用于选择 EXTI4~EXTI7 外部中断的输入源
0000            GPIOA[x]引脚 
0001            GPIOB[x]引脚 
0011            GPIOD[x]引脚
0100            GPIOE[x]引脚
0101            GPIOF[x]引脚
0110            GPIOG[x]引脚
                AFIO_EXTICR3_外部中断配置寄存器3
EXTIx[3:0]      EXTIx配置(x = 8 … 11) (EXTI x configuration) 
                这些位可由软件读写，用于选择 EXTI8~EXTI11 外部中断的输入源
0000            GPIOA[x]引脚 
0001            GPIOB[x]引脚 
0011            GPIOD[x]引脚
0100            GPIOE[x]引脚
0101            GPIOF[x]引脚
0110            GPIOG[x]引脚
                AFIO_EXTICR4_外部中断配置寄存器4
EXTIx[3:0]      EXTIx配置(x = 12 … 15) (EXTI x configuration) 
                这些位可由软件读写，用于选择 EXTI12~EXTI15 外部中断的输入源
0000            GPIOA[x]引脚 
0001            GPIOB[x]引脚 
0011            GPIOD[x]引脚
0100            GPIOE[x]引脚
0101            GPIOF[x]引脚
0110            GPIOG[x]引脚
**************************************************************/

#endif
