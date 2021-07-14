#ifndef __COMMON_H__
#define __COMMON_H__

#include "stm32f4xx.h"



/************************* Polling mode IO operation *************************/
/*
HAL_StatusTypeDef HAL_UART_Transmit(
	UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout)
HAL_StatusTypeDef HAL_UART_Receive(
	UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout)
*/
#ifdef POLLING_MODE
#define TX_MACRO		HAL_UART_Transmit	/* 发送数据宏 */
#define RX_MACRO		HAL_UART_Receive	/* 接收数据宏 */
#define TX_HANDLE		do{&huart2}while(0)	/* 发送句柄 */
#define RX_HANDLE		do{&usart1}while(0)	/* 接收句柄 */
#define TX_BUF_SIZE		16			/* 发送缓冲区大小 */
#define RX_BUF_SIZE		16			/* 接收缓冲区大小 */
#define TX_DATA_SIZE		7			/* 发送数据大小 */
#define RX_DATA_SIZE		7			/* 接收数据大小 */
#define TX_TIMEOUT		1000			/* 发送超时 */
#define RX_TIMEOUT		1000			/* 接收超时 */

extern uint8_t tx_buf[TX_BUF_SIZE];	/* 发送数据缓冲区 */
extern uint8_t rx_buf[RX_BUF_SIZE];	/* 接收数据缓冲区 */
//extern uint8_t tx_flag;/* 标志位置“1” */
extern uint8_t rx_flag;			/* 串口接收到数据， 标志位置“1” */
#endif



/************************ Interrupt mode IO operation ************************/
/*
HAL_StatusTypeDef HAL_UART_Transmit_IT(
	UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size)
HAL_StatusTypeDef HAL_UART_Receive_IT(
	UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size)
*/
#ifdef INTERRUPT_MODE
#define TX_MACRO		HAL_UART_Transmit_IT	/* 发送数据宏 */
#define RX_MACRO		HAL_UART_Receive_IT	/* 接收数据宏 */
#define TX_HANDLE		do{&huart2}while(0)	/* 发送句柄 */
#define RX_HANDLE		do{&usart1}while(0)	/* 接收句柄 */
#define TX_BUF_SIZE		16			/* 发送缓冲区大小 */
#define RX_BUF_SIZE		16			/* 接收缓冲区大小 */
#define TX_DATA_SIZE		7			/* 发送数据大小 */
#define RX_DATA_SIZE		7			/* 接收数据大小 */
#define TX_TIMEOUT		1000			/* 发送超时 */
#define RX_TIMEOUT		1000			/* 接收超时 */

extern uint8_t tx_buf[TX_BUF_SIZE];	/* 发送数据缓冲区 */
extern uint8_t rx_buf[RX_BUF_SIZE];	/* 接收数据缓冲区 */
//extern uint8_t tx_flag;/* 标志位置“1” */
extern uint8_t rx_flag;			/* 串口接收到数据， 标志位置“1” */
#endif



/*************************** DMA mode IO operation ***************************/
#ifdef DMA_MODE
#endif

#endif
