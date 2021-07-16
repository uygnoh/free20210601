#include "common.h"
extern uint8_t Rxflag;

void  DEBUG_USART_IRQHandler(void)
{
	uint8_t ch = 0; 

	if(__HAL_UART_GET_FLAG( &UartHandle, UART_FLAG_RXNE ) != RESET) {		
		ch = ( uint16_t)READ_REG(UartHandle.Instance->DR);
		WRITE_REG(UartHandle.Instance->DR,ch); 
	}
}

int user_main(void)
{
	unsigned int k = 0;
	do {
		HAL_UART_Transmit(&UartHandle, (uint8_t *)(str + k) , 1, 1000);
		k++;
	} while(*(str + k) != '\0');
  
}

int user_mian_it(void)
{
	int8_t rx_tmp;
	int8_t rx_cnt = 0;
	while (1) {
		// 将USART1中的数据，分析并处理
		if (rx_flag) {
			if (rx_cnt < sizeof(rx_buf)
				rx_buf[rx_cnt++] = rx_tmp;
			else
				rx_cnt = 0;
		}

		// 简单的通信协议，遇到回车换行认为是“1”个命令帧，
		// 遇到换行字符，认为接收到一个命令
		// 0x0A 换行字符
		if (rx_tmp == 0x0A) {
			// 检测到有回车字符就把从上位机接收到的数据返回给上位机
			TX_MACRO(TX_HANDLE, (uint8_t *)rx_buf, TX_DATA_SIZE, TX_TIMEOUT);
			rx_count = 0;
		}
	} 
}


