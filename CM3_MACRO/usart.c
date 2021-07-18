#include "usart.h"

/* Tx/Rx 波特率 = ƒck/(16*USARTDIV) 
	float DIV;
	uint16_t DIV_M, DIV_F, BRR;
	uint32_t BOUND; 
	BOUND = 9600;
	DIV   = (float)(72 * 1000 * 1000) / (BOUND * 16);
	DIV_M = DIV;                    //取整数部分
	DIV_F = (DIV - DIV_M) * 16;     //取小数部分
	BRR   = (DIV_M << 4) + DIV_F;   //整合整数部分和小数部分
	USART1->BRR = BRR;	
*/
void usart_setup(void)
{
	/* 2位抢占优先级, 2位响应优先级 */
	nvic_set_priority_group();
	/* 设置USART1的先占优先级为4，从优先级为4 */
	nvic_set_irq_priority(USART1_IRQn, 0x0F)
	
	GPIOA_CLOCK_ENABLE();
	USART1_CLOCK_ENABLE();
	
	/* gpio基本配置 */
	/* Tx(PA.09)_复用推挽输出(50MHz)   Rx(PA.10)_浮空输入 */
	GPIOA->CRH &= (uint32_t)(0xFFFFF00F);
	GPIOA->CRH |= (uint32_t)(0x000000B0);
	GPIOA->CRH |= (uint32_t)(0x00000400);
	
	/* usart基本配置 */
	USART1->CR1 |= M16_SET_BIT_13;      /* USART模块使能 */
	USART1->CR1 &= ~M16_SET_BIT_12;     /* 1个起始位, 8个数据位 */
	USART1->CR2 &= (uint16_t)(0xCFFF); /* 1个停止位(bit13, bit12) */
	USART1->CR1 |= M16_SET_BIT_3;       /* 发送使能 */
	USART1->CR1 |= M16_SET_BIT_2;       /* 接收使能 */
	USART1->BRR = 0x27;                 /* 72MHz@115200 */			
}


int main(void)
{
	/* 发送30个字符 'A' 到 USART的DR寄存器 */
	int i, data,;
	data = 'A';

	for (i = 0; i < 30; i++) {
		USART1->DR = data;
		data++;
		//等待数据发送完成
		while ((USART1->SR & M16_SET_BIT_6) == 0);
	}
}


