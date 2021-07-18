#include "usart.h"

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
	nvic_set_irq_priority(USART1_IRQ, (uint8_t)(pri_mask & priority));

	/* 使能外设时钟 */
	GPIOA_CLOCK_ENABLE();
	USART1_CLOCK_ENABLE();
	
	/* usart1—gpio基本配置(uint32_t)类型数据 */
	/* Tx(PA.09)_复用推挽输出(50MHz)   Rx(PA.10)_浮空输入 */
	GPIOA->CRH &= (uint32_t)(0xFFFFF00F);
	GPIOA->CRH |= (uint32_t)(0x000000B0);
	GPIOA->CRH |= (uint32_t)(0x00000400);
	
	/* usart1基本配置(uint16_t)类型数据 */
	USART1->CR1 |= M16_SET_BIT_13;      /* USART模块使能 */
	USART1->CR1 &= ~M16_SET_BIT_12;     /* 1个起始位, 8个数据位 */
	USART1->CR2 &= (uint16_t)(0xCFFF); /* 1个停止位(bit13, bit12) */
	USART1->CR1 |= M16_SET_BIT_03;      /* 发送使能 */
	USART1->CR1 |= M16_SET_BIT_02;      /* 接收使能 */
	USART1->BRR = 0x0271;               /* 72MHz@115200 */			
}





