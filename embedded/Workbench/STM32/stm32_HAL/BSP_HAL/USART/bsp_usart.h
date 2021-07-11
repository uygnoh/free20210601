#ifndef __BSP_USART_H__
#define __BSP_USART_H__
#include "stm32f1xx.h"

UART_HandleTypeDef UartHandle;



// 串口波特率
#define YSH_USART_BAUD_RATE                 115200


// 引脚定义
/*************************************************************************/
#define YSH_USART                           USART1
#define YSH_USART_CLK_ENABLE()              __HAL_RCC_USART1_CLK_ENABLE()

#define YSH_USART_RX_GPIO_PORT              GPIOA
#define YSH_USART_RX_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOA_CLK_ENABLE()
#define YSH_USART_RX_PIN                    GPIO_PIN_10

#define YSH_USART_TX_GPIO_PORT              GPIOA
#define YSH_USART_TX_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOA_CLK_ENABLE()
#define YSH_USART_TX_PIN                    GPIO_PIN_9

#define YSH_USART_IRQHandler                USART1_IRQHandler
#define YSH_USART_IRQ                       USART1_IRQ  
/*************************************************************************/
#endif


