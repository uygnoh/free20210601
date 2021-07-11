#include "bsp_led.h"

int main(void)
{
    /* 第1步: HAL初始化 */
    HAL_Init();
    
    /* 第2步: 配置系统时钟 */
    SystemClock_Config();
    
    /* 第3步: led_gpio_init() */
    led_gpio_init();
    
    while (1)
    {
        LED_RED_TOOGLE();
        HAL_Delay(1000);
    }
}
