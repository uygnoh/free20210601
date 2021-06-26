#ifndef __LCD1602_H__
#define __LCD1602_H__

#include<reg52.h>

#define uint16_t unsigned int
#define uint8_t unsigned char
#define DATA_1602   P0      /* __P0__数据端口 */

 
sbit RS = P2^5;
sbit RW = P2^6;
sbit EN = P2^7;


void lcd1602_write_cmd(uint8_t cmd);
void lcd1602_write_dat(uint8_t dat);
void lcd1602_init(void);
void lcd1602_clear_all(void);
bit lcd1602_busy(void);
void delay_ms(uint16_t z);
void lcd1602_char_set(uint8_t p_x, uint8_t p_y, char p_char);
void lcd1602_string_set(uint8_t p_x, uint8_t p_y, const uint8_t *p_string);
#endif



