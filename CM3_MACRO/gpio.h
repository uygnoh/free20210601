#ifndef __GPIO_H__
#define __GPIO_H__
/* GPIOx_CRL {CNF0[1:0] MODE[1:0]} 0~7  */

/* _____________________________
0 0 0 0     模拟输入
0 1 0 0     浮空输入(复位后的状态) 
1 0 0 0     下拉输入 PxODR = 0
1 0 0 0     上拉输入 PxODR = 1

0 0 0 1     推挽输出(10MHz)
0 0 1 0     推挽输出( 2MHz)
0 0 1 1     推挽输出(50MHz)

0 1 0 1     开漏输出(10MHz)
0 1 1 0     开漏输出( 2MHz)
0 1 1 1     开漏输出( 2MHz)

1 0 0 1     复用推挽输出(10MHz)
1 0 1 0     复用推挽输出( 2MHz)
1 0 1 1     复用推挽输出(50MHz)

1 1 0 1     复用开漏输出(10MHz)
1 1 1 0     复用开漏输出( 2MHz)
1 1 1 1     复用开漏输出(50MHz)
_____________________________ */

/* _____________________________
0  模拟输入 
4  浮空输入(复位后的状态) 
8  下拉输入
8  上拉输入

1   推挽输出(10MHz)
2   推挽输出( 2MHz)
3   推挽输出(50MHz)

5   开漏输出(10MHz)
6   开漏输出( 2MHz)
7   开漏输出(50MHz)

9   复用推挽输出(10MHz)
A   复用推挽输出( 2MHz)
B   复用推挽输出(50MHz)

D   复用开漏输出(10MHz)
E   复用开漏输出( 2MHz)
F   复用开漏输出(50MHz)
_____________________________ */



/*
 * 设置GPIOA的第“0”位为下拉输入模式
 */
void gpio_conf_input(void)
{
	GPIOA->CRL &= (uint32_t)(0xFFFFFFF0);	//PA0 清除要设置的位
	GPIOA->CRL |= (uint32_t)(0x00000008);	//PA0 输入   
	GPIOA->ODR |= (uint32_t)(0<<0);     	//PA0 下拉
	
	GPIOA->CRL &= (uint32_t)(0xFFFFFFF0);	//PA0 清除要设置的位
	GPIOA->CRL |= (uint32_t)(0x00000008);	//PA0 输入  
	GPIOA->ODR |= (uint32_t)(1<<0);     	//PA0 上拉
}


void gpio_conf_usart1(void)
{
	GPIOA->CRH &= (uint32_t)(0xFFFFF00F);	////
	GPIOA->CRH |= (uint32_t)(0x000000B0);	//USART1 Tx(PA.09)
	GPIOA->CRH |= (uint32_t)(0x00000400);	//USART1 Rx(PA.10)
}










#endif
