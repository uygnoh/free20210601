#include "usart.h"

/**************************************************************
               AFIO_MAPR_复用重映射和调试I/O配置寄存器
26:24   SWJ_CFG[2:0]：串行线JTAG配置 (Serial wire JTAG configuration)
        ！这些位只可由软件写(读这些位，将返回未定义的数据值)
000     完全SWJ(JTAG-DP + SW-DP)：复位状态； 
001     完全SWJ(JTAG-DP + SW-DP)但没有NJTRST；
010     关闭JTAG-DP，启用SW-DP；
100     关闭JTAG-DP，关闭SW-DP；
**************************************************************/
void afio_swd_setup(void)
{
	/* 使能AFIO时钟， 禁用JTAG, 开启SWD */
	m_afio_clock_enable();
	AFIO->MAPR   &= (uint32_t)(0xF0FFFFFF);
	AFIO->MAPR   |= (uint32_t)(0x02000000);
}

/* Tx/Rx 波特率 = ƒck/(16*USARTDIV) 
	float DIV;
	uint16_t div_m; //存放整数部分
	uint16_t div_f;	//存放小数部分
	uint16_t brr;   //
	uint32_t baud_rate; 
	baud_rate = 9600;
	div   = (float)(72 * 1000 * 1000) / (baud_rate * 16);
	div_m = div;                    //取整数部分
	div_f = (div - div_m) * 16;     //小数部分*16得到整数，放到最低4位
	brr   = (div_m << 4) + div_f;   //整合整数部分和小数部分
	// BRR寄存器为16位， 高12位放整数部分，低4位放小数部分
	USART1->BRR = brr;	
*/
void usart_setup(void)
{
	/* 2位抢占优先级, 2位响应优先级 */
	nvic_set_priority_group();
	/* 设置USART1的先占优先级为4，从优先级为4 */
	/* STM32F10x的中断优先级高4位有效 */
	uint8_t pri_mask = 0xF0;
	uint8_t priority = 0xF0;
	nvic_set_irq_priority(USART1_IRQ_N, (uint8_t)(pri_mask & priority));

	/* 使能外设时钟 */
	m_gpioa_clock_enable();
	m_usart1_clock_enable();
	
	/* usart1—gpio基本配置(uint32_t)类型数据 */
	/* Tx(PA.09)_复用推挽输出(50MHz)   Rx(PA.10)_浮空输入 */
	GPIOA->CRH &= (uint32_t)(0xFFFFF00F);
	GPIOA->CRH |= (uint32_t)(0x000000B0);
	GPIOA->CRH |= (uint32_t)(0x00000400);
	
	/* usart1基本配置(uint16_t)类型数据 */
	USART1->CR1 |= m16_set_bit_13;      /* USART模块使能 */
	USART1->CR1 &= ~m16_set_bit_12;     /* 1个起始位, 8个数据位 */
	USART1->CR2 &= (uint16_t)(0xCFFF); /* 1个停止位(bit13, bit12) */
	USART1->CR1 |= m16_set_bit_03;      /* 发送使能 */
	USART1->CR1 |= m16_set_bit_02;      /* 接收使能 */
	USART1->BRR = 0x0271;               /* 72MHz@115200 */			
}



