#include "stm32f10x.h"

int main(void)
{
	/* 发送30个字符 'A' 到 USART的DR寄存器 */
	int i, data;
	data = 'A';

	for (i = 0; i < 30; i++) {
		USART1->DR = data;
		data++;
		//等待数据发送完成
		while ((USART1->SR & M16_SET_BIT_06) == 0);
	}
}
