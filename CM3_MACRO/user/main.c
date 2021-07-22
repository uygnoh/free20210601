#include "stm32f10x.h"

void led_test(void)
{
	m_gpioc_clock_enable();
	/* gpioc_13@50MHz_push-pull */
	GPIOC->CRH &= ((uint32_t)0xFF0FFFFF);
	GPIOC->CRH |= ((uint32_t)0x00300000);
	while (1) {
		m32_pc_out(13) = 0;
		delay_ms(100);
		m32_pc_out(13) = 1;
		delay_ms(100);
	}
}
int main(void)

{
	led_test();
}
