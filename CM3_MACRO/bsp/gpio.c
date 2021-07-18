#include "gpio.h"

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
	GPIOA->BRR = M16_SET_BIT_00;
	
	/* 清除GPIOA_ODR第“0”位(高16位清除) */
	GPIOA->BSRR = M32_SET_BIT_16;
	/* 设置GPIOA_ODR第“0”位(低16位设置) */
	GPIOA->BSRR = M32_SET_BIT_00;
}


/**************************************************************
               AFIO_MAPR_复用重映射和调试I/O配置寄存器
26:24   SWJ_CFG[2:0]：串行线JTAG配置 (Serial wire JTAG configuration)
        ！这些位只可由软件写(读这些位，将返回未定义的数据值)
000     完全SWJ(JTAG-DP + SW-DP)：复位状态； 
001     完全SWJ(JTAG-DP + SW-DP)但没有NJTRST；
010     关闭JTAG-DP，启用SW-DP；
100     关闭JTAG-DP，关闭SW-DP；
**************************************************************/
void gpio_swd_setup(void)
{
	/* 禁用JTAG, 开启SWD */
	RCC->APB2ENR |= (uint32_t)(0x00000001);
	AFIO->MAPR   &= (uint32_t)(0x00FFFFFF);
	AFIO->MAPR   |= (uint32_t)(0x02000000);
}
