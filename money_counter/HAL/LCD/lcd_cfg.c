/*
 * lcd_cfg.c
 *
 *  Created on: Aug 6, 2024
 *      Author: mokhtar
 */


#include"lcd_cfg.h"

chr_lcd_4bit_type lcd_1 = {
		.lcd_en_port = GPIOA,
		.lcd_en_pin = GPIO_PIN_0,
		.lcd_rs_port = GPIOA,
		.lcd_rs_pin  = GPIO_PIN_1,
		.lcd_data_port[0] = GPIOA,
		.lcd_data_port[1] = GPIOA,
		.lcd_data_port[2] = GPIOA,
		.lcd_data_port[3] = GPIOA,
		.lcd_data_pin[0] = GPIO_PIN_4,
		.lcd_data_pin[1] = GPIO_PIN_5,
		.lcd_data_pin[2] = GPIO_PIN_6,
		.lcd_data_pin[3] = GPIO_PIN_7,

};
