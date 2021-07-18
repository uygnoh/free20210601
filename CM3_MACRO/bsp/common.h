#ifndef __COMMON_H__
#define __COMMON_H__
#include "stm32f10x.h"

/******************************************************************************/
/*                                                                            */
/*                     STM32F10X___位绑定                                      */
/*                                                                            */
/******************************************************************************/
#define  GPIOA_ODR_A  (GPIOA_BASE + 0x0C)
#define  GPIOA_IDR_A  (GPIOA_BASE + 0x08)
#define  GPIOB_ODR_B  (GPIOB_BASE + 0x0C)
#define  GPIOB_IDR_B  (GPIOB_BASE + 0x08)
#define  GPIOC_ODR_C  (GPIOC_BASE + 0x0C)
#define  GPIOC_IDR_C  (GPIOC_BASE + 0x08)
#define  GPIOD_ODR_D  (GPIOD_BASE + 0x0C)
#define  GPIOD_IDR_D  (GPIOD_BASE + 0x08)
#define  GPIOE_ODR_E  (GPIOE_BASE + 0x0C)
#define  GPIOE_IDR_E  (GPIOE_BASE + 0x08)
#define  GPIOF_ODR_F  (GPIOF_BASE + 0x0C)
#define  GPIOF_IDR_F  (GPIOF_BASE + 0x08)
#define  GPIOG_ODR_G  (GPIOG_BASE + 0x0C)
#define  GPIOG_IDR_G  (GPIOG_BASE + 0x08)
#define BitBand(Addr, BitNum)  *((volatile unsigned long *)\
((Addr & 0xF0000000) + 0x2000000 + ((Addr & 0xFFFFF) << 5) + (BitNum << 2)))
#define PA_IN(n) 	BitBand(GPIOA_IDR_A, n)
#define PA_OUT(n) 	BitBand(GPIOA_ODR_A, n)
#define PB_IN(n) 	BitBand(GPIOB_IDR_B, n)
#define PB_OUT(n) 	BitBand(GPIOB_ODR_B, n)
#define PC_IN(n) 	BitBand(GPIOC_IDR_C, n)
#define PC_OUT(n) 	BitBand(GPIOC_ODR_C, n)
#define PD_IN(n) 	BitBand(GPIOD_IDR_D, n)
#define PD_OUT(n) 	BitBand(GPIOD_ODR_D, n)
#define PE_IN(n) 	BitBand(GPIOE_IDR_E, n)
#define PE_OUT(n) 	BitBand(GPIOE_ODR_E, n)
#define PF_IN(n) 	BitBand(GPIOF_IDR_F, n)
#define PF_OUT(n) 	BitBand(GPIOF_ODR_F, n)
#define PG_IN(n) 	BitBand(GPIOG_IDR_G, n)
#define PG_OUT(n) 	BitBand(GPIOG_ODR_G, n)

/******************************************************************************/
/*                                                                            */
/*                     AHB外设时钟使能寄存器___RCC_AHBENR                        */
/*                                                                            */
/******************************************************************************/
#define DM1_CLOCK_ENABLE()      do {    \
                RCC->AHBENR  |= ((uint32_t)0x00000001); } while (0)     /*0*/
#define DM2_CLOCK_ENABLE()      do {    \
                RCC->AHBENR  |= ((uint32_t)0x00000002); } while (0)     /*2*/

/******************************************************************************/
/*                                                                            */
/*                     APB2外设时钟使能寄存器___RCC_APB2ENR                      */
/*                                                                            */
/******************************************************************************/
#define AFIO_CLOCK_ENABLE()     do {    \
                RCC->APB2ENR |= ((uint32_t)0x00000001); } while (0)     /*0*/
#define GPIOA_CLOCK_ENABLE()    do {    \
                RCC->APB2ENR |= ((uint32_t)0x00000004); } while (0)     /*2*/
#define GPIOB_CLOCK_ENABLE()    do {    \
                RCC->APB2ENR |= ((uint32_t)0x00000008); } while (0)     /*3*/

#define GPIOC_CLOCK_ENABLE()    do {    \
                RCC->APB2ENR |= ((uint32_t)0x00000010); } while (0)     /*4*/
#define GPIOD_CLOCK_ENABLE()    do {    \
                RCC->APB2ENR |= ((uint32_t)0x00000020); } while (0)     /*5*/
#define GPIOE_CLOCK_ENABLE()    do {    \
                RCC->APB2ENR |= ((uint32_t)0x00000040); } while (0)     /*6*/
#define GPIOF_CLOCK_ENABLE()    do {    \
                RCC->APB2ENR |= ((uint32_t)0x00000080); } while (0)     /*7*/

#define GPIOG_CLOCK_ENABLE()    do {    \
                RCC->APB2ENR |= ((uint32_t)0x00000100); } while (0)     /*8*/
#define ADC1_CLOCK_ENABLE()     do {    \
                RCC->APB2ENR |= ((uint32_t)0x00000200); } while (0)     /*9*/
#define ADC2_CLOCK_ENABLE()     do {    \
                RCC->APB2ENR |= ((uint32_t)0x00000400); } while (0)     /*10*/
#define TIM1_CLOCK_ENABLE()     do {    \
                RCC->APB2ENR |= ((uint32_t)0x00000800); } while (0)     /*11*/

#define SPI1_CLOCK_ENABLE()     do {    \
                RCC->APB2ENR |= ((uint32_t)0x00001000); } while (0)     /*12*/
#define TIM8_CLOCK_ENABLE()     do {    \
                RCC->APB2ENR |= ((uint32_t)0x00002000); } while (0)     /*13*/
#define USART1_CLOCK_ENABLE()   do {    \
                RCC->APB2ENR |= ((uint32_t)0x00004000); } while (0)     /*14*/
#define ADC3_CLOCK_ENABLE()     do {    \
                RCC->APB2ENR |= ((uint32_t)0x00008000); } while (0)     /*15*/

/******************************************************************************/
/*                                                                            */
/*                     APB1外设时钟使能寄存器___RCC_APB1ENR                      */
/*                                                                            */
/******************************************************************************/
#define TIM2_CLOCK_ENABLE()     do {    \
                RCC->APB1ENR |= ((uint32_t)0x00000001); } while (0)     /*0*/
#define TIM3_CLOCK_ENABLE()     do {    \
                RCC->APB1ENR |= ((uint32_t)0x00000002); } while (0)     /*1*/
#define TIM4_CLOCK_ENABLE()     do {    \
                RCC->APB1ENR |= ((uint32_t)0x00000004); } while (0)     /*2*/
#define TIM5_CLOCK_ENABLE()     do {    \
                RCC->APB1ENR |= ((uint32_t)0x00000008); } while (0)     /*3*/

#define TIM6_CLOCK_ENABLE()     do {    \
                RCC->APB1ENR |= ((uint32_t)0x00000010); } while (0)     /*4*/
#define TIM7_CLOCK_ENABLE()     do {    \
                RCC->APB1ENR |= ((uint32_t)0x00000020); } while (0)     /*5*/

#define WWDG_CLOCK_ENABLE()     do {    \
                RCC->APB1ENR |= ((uint32_t)0x00000800); } while (0)     /*11*/

#define SPI2_CLOCK_ENABLE()     do {    \
                RCC->APB1ENR |= ((uint32_t)0x00004000); } while (0)     /*14*/
#define SPI3_CLOCK_ENABLE()     do {    \
                RCC->APB1ENR |= ((uint32_t)0x00008000); } while (0)     /*15*/
                
#define USART2_CLOCK_ENABLE()   do {    \
                RCC->APB1ENR |= ((uint32_t)0x00020000); } while (0)     /*17*/
#define USART3_CLOCK_ENABLE()   do {    \
                RCC->APB1ENR |= ((uint32_t)0x00040000); } while (0)     /*18*/
#define USART4_CLOCK_ENABLE()   do {    \
                RCC->APB1ENR |= ((uint32_t)0x00080000); } while (0)     /*19*/

#define USART5_CLOCK_ENABLE()   do {    \
                RCC->APB1ENR |= ((uint32_t)0x00100000); } while (0)     /*20*/
#define I2C1_CLOCK_ENABLE()     do {    \
                RCC->APB1ENR |= ((uint32_t)0x00200000); } while (0)     /*21*/
#define I2C2_CLOCK_ENABLE()     do {    \
                RCC->APB1ENR |= ((uint32_t)0x00400000); } while (0)     /*22*/
#define USB_CLOCK_ENABLE()      do {    \
                RCC->APB1ENR |= ((uint32_t)0x00800000); } while (0)     /*23*/

#define CAN_CLOCK_ENABLE()      do {    \
                RCC->APB1ENR |= ((uint32_t)0x02000000); } while (0)     /*25*/
#define BKP_CLOCK_ENABLE()      do {    \
                RCC->APB1ENR |= ((uint32_t)0x08000000); } while (0)     /*27*/

#define PWR_CLOCK_ENABLE()      do {    \
                RCC->APB1ENR |= ((uint32_t)0x10000000); } while (0)     /*28*/
#define DAC_CLOCK_ENABLE()      do {    \
                RCC->APB1ENR |= ((uint32_t)0x20000000); } while (0)     /*29*/

void delay_us(uint16_t t);
void delay_ms(uint16_t t);

#endif
