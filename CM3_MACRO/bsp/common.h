#ifndef __COMMON_H__
#define __COMMON_H__
#include "stm32f10x.h"

/******************************************************************************/
/*                                                                            */
/*                                M16 | M32                                   */
/*                                                                            */
/******************************************************************************/
#define m16_set_bit_00              ((uint16_t)0x0001)
#define m16_set_bit_01              ((uint16_t)0x0002)
#define m16_set_bit_02              ((uint16_t)0x0004)
#define m16_set_bit_03              ((uint16_t)0x0008)
#define m16_set_bit_04              ((uint16_t)0x0010)
#define m16_set_bit_05              ((uint16_t)0x0020)
#define m16_set_bit_06              ((uint16_t)0x0040)
#define m16_set_bit_07              ((uint16_t)0x0080)
#define m16_set_bit_08              ((uint16_t)0x0100)
#define m16_set_bit_09              ((uint16_t)0x0200)
#define m16_set_bit_10              ((uint16_t)0x0400)
#define m16_set_bit_11              ((uint16_t)0x0800)
#define m16_set_bit_12              ((uint16_t)0x1000)
#define m16_set_bit_13              ((uint16_t)0x2000)
#define m16_set_bit_14              ((uint16_t)0x4000)
#define m16_set_bit_15              ((uint16_t)0x8000)
#define m32_set_bit_00              ((uint32_t)0x00000001)
#define m32_set_bit_01              ((uint32_t)0x00000002)
#define m32_set_bit_02              ((uint32_t)0x00000004)
#define m32_set_bit_03              ((uint32_t)0x00000008)
#define m32_set_bit_04              ((uint32_t)0x00000010)
#define m32_set_bit_05              ((uint32_t)0x00000020)
#define m32_set_bit_06              ((uint32_t)0x00000040)
#define m32_set_bit_07              ((uint32_t)0x00000080)
#define m32_set_bit_08              ((uint32_t)0x00000100)
#define m32_set_bit_09              ((uint32_t)0x00000200)
#define m32_set_bit_10              ((uint32_t)0x00000400)
#define m32_set_bit_11              ((uint32_t)0x00000800)
#define m32_set_bit_12              ((uint32_t)0x00001000)
#define m32_set_bit_13              ((uint32_t)0x00002000)
#define m32_set_bit_14              ((uint32_t)0x00004000)
#define m32_set_bit_15              ((uint32_t)0x00008000)
#define m32_set_bit_16              ((uint32_t)0x00010000)
#define m32_set_bit_17              ((uint32_t)0x00020000)
#define m32_set_bit_18              ((uint32_t)0x00040000)
#define m32_set_bit_19              ((uint32_t)0x00080000)
#define m32_set_bit_20              ((uint32_t)0x00100000)
#define m32_set_bit_21              ((uint32_t)0x00200000)
#define m32_set_bit_22              ((uint32_t)0x00400000)
#define m32_set_bit_23              ((uint32_t)0x00800000)
#define m32_set_bit_24              ((uint32_t)0x01000000)
#define m32_set_bit_25              ((uint32_t)0x02000000)
#define m32_set_bit_26              ((uint32_t)0x04000000)
#define m32_set_bit_27              ((uint32_t)0x08000000)
#define m32_set_bit_28              ((uint32_t)0x10000000)
#define m32_set_bit_29              ((uint32_t)0x20000000)
#define m32_set_bit_30              ((uint32_t)0x40000000)
#define m32_set_bit_31              ((uint32_t)0x80000000)

/******************************************************************************/
/*                                                                            */
/*                     AHB外设时钟使能寄存器___RCC_AHBENR                        */
/*                                                                            */
/******************************************************************************/
#define dma1_clock_enable()     do {RCC->AHBENR |= m32_set_bit_00;} while (0)
#define dma2_clock_enable()     do {RCC->AHBENR |= m32_set_bit_01;} while (0)

/******************************************************************************/
/*                                                                            */
/*                     APB2外设时钟使能寄存器___RCC_APB2ENR                      */
/*                                                                            */
/******************************************************************************/
#define afio_clock_enable()     do {RCC->APB2ENR |= m32_set_bit_00;} while (0)
#define gpioa_clock_enable()    do {RCC->APB2ENR |= m32_set_bit_02;} while (0)
#define gpiob_clock_enable()    do {RCC->APB2ENR |= m32_set_bit_03;} while (0)
#define gpioc_clock_enable()    do {RCC->APB2ENR |= m32_set_bit_04;} while (0)
#define gpiod_clock_enable()    do {RCC->APB2ENR |= m32_set_bit_05;} while (0)
#define gpioe_clock_enable()    do {RCC->APB2ENR |= m32_set_bit_06;} while (0)
#define gpiof_clock_enable()    do {RCC->APB2ENR |= m32_set_bit_07;} while (0)
#define gpiog_clock_enable()    do {RCC->APB2ENR |= m32_set_bit_08;} while (0)
#define adc1_clock_enable()     do {RCC->APB2ENR |= m32_set_bit_09;} while (0)
#define adc2_clock_enable()     do {RCC->APB2ENR |= m32_set_bit_10;} while (0)
#define tim1_clock_enable()     do {RCC->APB2ENR |= m32_set_bit_11;} while (0)
#define spi1_clock_enable()     do {RCC->APB2ENR |= m32_set_bit_12;} while (0)
#define tim8_clock_enable()     do {RCC->APB2ENR |= m32_set_bit_13;} while (0)
#define usart1_clock_enable()   do {RCC->APB2ENR |= m32_set_bit_14;} while (0)
#define adc3_clock_enable()     do {RCC->APB2ENR |= m32_set_bit_15;} while (0)

/******************************************************************************/
/*                                                                            */
/*                     APB1外设时钟使能寄存器___RCC_APB1ENR                      */
/*                                                                            */
/******************************************************************************/
#define tim2_clock_enable()     do {RCC->APB2ENR |= m32_set_bit_00;} while (0)
#define tim3_clock_enable()     do {RCC->APB2ENR |= m32_set_bit_01;} while (0)
#define tim4_clock_enable()     do {RCC->APB2ENR |= m32_set_bit_02;} while (0)
#define tim5_clock_enable()     do {RCC->APB2ENR |= m32_set_bit_03;} while (0)
#define tim6_clock_enable()     do {RCC->APB2ENR |= m32_set_bit_04;} while (0)
#define tim7_clock_enable()     do {RCC->APB2ENR |= m32_set_bit_05;} while (0)
#define wwdg_clock_enable()     do {RCC->APB2ENR |= m32_set_bit_11;} while (0)
#define spi2_clock_enable()     do {RCC->APB2ENR |= m32_set_bit_14;} while (0)
#define spi3_clock_enable()     do {RCC->APB2ENR |= m32_set_bit_15;} while (0)
#define usart2_clock_enable()   do {RCC->APB2ENR |= m32_set_bit_17;} while (0)
#define usart3_clock_enable()   do {RCC->APB2ENR |= m32_set_bit_18;} while (0)
#define usart4_clock_enable()   do {RCC->APB2ENR |= m32_set_bit_19;} while (0)
#define usart5_clock_enable()   do {RCC->APB2ENR |= m32_set_bit_20;} while (0)
#define i2c1_clock_enable()     do {RCC->APB2ENR |= m32_set_bit_21;} while (0)
#define i2c2_clock_enable()     do {RCC->APB2ENR |= m32_set_bit_22;} while (0)
#define usb_clock_enable()      do {RCC->APB2ENR |= m32_set_bit_23;} while (0)
#define can_clock_enable()      do {RCC->APB2ENR |= m32_set_bit_25;} while (0)
#define bkp_clock_enable()      do {RCC->APB2ENR |= m32_set_bit_27;} while (0)
#define pwr_clock_enable()      do {RCC->APB2ENR |= m32_set_bit_28;} while (0)
#define dac_clock_enable()      do {RCC->APB2ENR |= m32_set_bit_29;} while (0)


void delay_us(uint16_t t);
void delay_ms(uint16_t t);

#endif
