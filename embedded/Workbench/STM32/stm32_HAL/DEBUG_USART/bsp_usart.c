#include "bsp_usart.h"

huartTypeDef huart;


void UART1_Config(void)
{
    huart.Instance             = USART1;
    huart.Init.BaudRate        = 115200;
    huart.Init.WordLength      = UART_WORDLENGTH_8B;
    huart.Init.StopBits        = UART_STOPBITS_1;
    huart.Init.Parity          = UART_PARITY_NONE;
    huart.Init.Mode            = UART_MODE_TX_RX;
    huart.Init.HwFlowCtl       = UART_HWCONTROL_NONE;
    huart.Init.OverSampling    = UART_OVERSAMPLING_16;
    HAL_UART_Init(&huart);
    
    if (HAL_UART_Init(&huart) != HAL_OK)
    {
        Error_Handler();
    }
    
    // 使能串口接收中断
    __HAL_UART_ENABLE_IT(&huart, UART_IT_RXNE);   
}


void HAL_UART_MspInit(huartTypeDef* huart)
{
    GPIO_InitTypeDef PORT;
    
    if (huart->Instance == USART1)
    {
        /* 打开usart时钟， gpio引脚时钟 */
        __HAL_RCC_USART1_CLK_ENABLE();
        __HAL_RCC_GPIOA_CLK_ENABLE();
       
        /* Tx <===> PA9 */
        /* 配置TX为引脚复用功能 */
        PORT.Pin   = GPIO_PIN_9;
        PORT.Mode  = GPIO_MODE_AF_PP;
        PORT.Pull  = GPIO_PULLUP;
        PORT.Speed = GPIO_SPEED_FREQ_HIGH;
        HAL_GPIO_Init(GPIOA, &PORT);
        /* Rx <===> PA10 */
        /* 配置RX为引脚复用功能 */
        PORT.Pin   = GPIO_PIN_10;
        PORT.Mode  = GPIO_MODE_AF_INPUT;
        HAL_GPIO_Init(GPIOA, &PORT);

        /* 抢占优先级0，子优先级0 */
        HAL_NVIC_SetPriority(USART1_IRQ, 0, 0);
        /* 使能USART1中断通道 */
        HAL_NVIC_EnableIRQ(USART1_IRQ);
    }
}





