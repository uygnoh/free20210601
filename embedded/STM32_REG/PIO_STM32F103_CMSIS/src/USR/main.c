#include "stm32f10x.h"

int main(void)
{
    /* (设置为第3组)3位抢占优先级, 1位响应优先级 */
    SCB->AIRCR      = 0x05FA0000 | 0x00000400; 

    /* 设置TIM_5的抢占优先级为7，响应优先级为1 */
    NVIC->IP[50]    = 0xF0;

    /* 开启TIM_5中断 */
    NVIC->ISER[1]   = 0x00020000;

    return 0;
}
