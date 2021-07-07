#ifndef __LCD1602_H__
#define __LCD1602_H__

#include<reg52.h>

sbit RS = P2^5;
sbit RW = P2^6;
sbit EN = P2^7;


void lcd1602_write_cmd(uint8_t cmd);
void lcd1602_write_dat(uint8_t dat);
void lcd1602_busy_check(void);

void lcd1602_init(void);
void lcd1602_show_char(uint8_t pos_x, uint8_t pos_y, uint8_t t_char);
void lcd1602_show_string(uint8_t pos_x, uint8_t pos_y, const uint8_t *pstr);
uint8_t int_convert_string(long dat, uint8_t *str);

void delay_ms(uint16_t z);
#endif



