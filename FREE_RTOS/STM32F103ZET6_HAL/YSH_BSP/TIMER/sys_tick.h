#ifndef __SYS_TICK__
#define __SYS_TICK__
#include "stm32f103xe.h"

void delay_us(uint32_t t);
void delay_ms(uint32_t t);

/* SysTick有两种获得系统时钟的方式
(一种是直接取自系统时钟，另一种是将系统时钟8分频)
 * SysTick->CTRL    
 16 COUNTFLAG
 2  CLKSOURCE   0=系统时钟8分频 1=系统时钟(FCLK)
 1  TICKINT     1=SysTick 倒数到 0 时产生 SysTick 异常请求
 0  ENABLE      SysTick 定时器的使能位
 * SysTick->LOAD
   当倒计数到“0”时，将被重装载的值
 * SysTick->VAL     
   当前数值寄存器( 读取时返回当前倒计数的值，写它则使之清零， 
   同时还会清除在 SysTick 控制及状态寄存器COUNTFLAG标志 )
 * SysTick->CALIB   校准数值寄存器
 */
// 1微秒延时 SysTick = @系统时钟为72MHz / 8
void delay_us(uint32_t t)
{
	uint32_t tmp;

	SysTick->LOAD = 9 * t;
	SysTick->VAL  = 0x00;
	/* 启动SysTick计数器 */
	SysTick->CTRL = 0x01;
	/* 判断(COUNTFLAG)这个标志位的值 */
	do {
		tmp = SysTick->CTRL;
	} while ((tmp & 0x01) && (!(tmp & (1 << 16))));

	SysTick->CTRL = 0x00;
	SysTick->VAL  = 0x00;
}

void delay_ms(uint32_t t)
{
	uint32_t tmp;

	SysTick->LOAD = 9000 * t;
	SysTick->VAL  = 0x00;
	/* 启动SysTick计数器 */
	SysTick->CTRL = 0x01;
	/* 判断(COUNTFLAG)这个标志位的值 */
	do {
		tmp = SysTick->CTRL;
	} while ((tmp & 0x01) && (!(tmp & (1 << 16))));

	SysTick->CTRL = 0x00;
	SysTick->VAL  = 0x00;
}
#endif
