    #include "ysh_nvic.h"
    
    void nvic_init(void)
    {
        /* (设置为第3组)3位抢占优先级, 1位响应优先级 */
        SCB->AIRCR      = 0x05FA0000 | 0x00000400; 

        /* % TIM2, (此定时器的中断编号为: 28) */  
        NVIC->IP[28]    = 0xF0;
        NVIC->ISER[0]   = 0x10000000;
    }

