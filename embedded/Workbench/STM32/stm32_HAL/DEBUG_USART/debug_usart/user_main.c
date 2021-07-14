int user_mian(void)
{
	int8_t rx_tmp;
	while (1) {
		// 将USART1中的数据，分析并处理
		if (rx_flag) {
			if (rx_count < sizeof(rx_buf)
			rx_buf[rx_count++] = rx_tmp;
			else
			rx_count = 0;
		}

		// 简单的通信协议，遇到回车换行认为是“1”个命令帧，
		// 遇到换行字符，认为接收到一个命令
		// 0x0A 换行字符
		if (rx_tmp == 0x0A) {
			// 检测到有回车字符就把数据返回给上位机
			TX_MACRO(TX_HANDLE, (uint8_t *)TX_BUFFER, TX_DATA_SIZE, TX_TIMEOUT);
			rx_count = 0;
		}
	} 
}
