/*
 * interrupt.c
 *
 *  Created on: Jun 3, 2025
 *      Author: Lenovo
 */

#include"main.h"
#include "lcd_cfg.h"

void handle_isr0(void);
void handle_isr1(void);
void handle_isr2(void);
void handle_isr3(void);
void handle_isr4(void);
void handle_isr5(void);
void handle_isr6(void);
void handle_isr7(void);
void handle_isr8(void);
void handle_isr9(void);



void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
	switch (GPIO_Pin){
	case GPIO_PIN_0 :
		handle_isr0();
		break;
	case GPIO_PIN_1 :
		handle_isr1();
		break;
	case GPIO_PIN_2 :
		handle_isr2();
		break;
	case GPIO_PIN_3 :
		handle_isr3();
		break;
	case GPIO_PIN_4 :
		handle_isr4();
		break;
	case GPIO_PIN_5 :
		handle_isr5();
		break;
	case GPIO_PIN_6 :
		handle_isr6();
		break;
	case GPIO_PIN_7 :
		handle_isr7();
		break;
	case GPIO_PIN_8 :
		handle_isr8();
		break;
	case GPIO_PIN_9 :
		handle_isr9();
		break;
	}

}


void handle_isr0(void){
	flag++;
}

void handle_isr1(void){
	flag2++;
}

void handle_isr2(void){

}


void handle_isr3(void){

}


void handle_isr4(void){
	money_category = 5;
	counter = 0;

}


void handle_isr5(void){
	money_category = 10;
	counter = 0;

}


void handle_isr6(void){
	money_category = 20;
	counter = 0;

}


void handle_isr7(void){
	money_category = 50;
	counter = 0;

}


void handle_isr8(void){
	money_category = 100;
	counter = 0;

}


void handle_isr9(void){
	money_category = 200;
	counter = 0;

}

void reset_lcd(void){
    lcd_4bit_send_command(&lcd_1, _LCD_CLEAR);
    HAL_Delay(50);
	lcd_4bit_send_string_pos(&lcd_1, 1, 1, "Count :");
	lcd_4bit_send_string_pos(&lcd_1, 2, 1, "Total :");
	lcd_4bit_send_string_pos(&lcd_1, 1, 11, "CA:");
}

//void display_category(void){
//	lcd_4bit_send_command(&lcd_1, _LCD_CLEAR);
//	lcd_4bit_send_string_pos(&lcd_1, 1, 1, "5 10 20 50 100 2");
//	convert_uint8_to_string(ca5_counter,ch_5);
//	lcd_4bit_send_string_pos(&lcd_1, 2, 1,ch_5 );
//	convert_uint8_to_string(ca10_counter,ch_5);
//	lcd_4bit_send_string_pos(&lcd_1, 2, 3,ch_5);
//	convert_uint8_to_string(ca20_counter,ch_5);
//	lcd_4bit_send_string_pos(&lcd_1, 2, 6,ch_5);
//	convert_uint8_to_string(ca50_counter,ch_5);
//	lcd_4bit_send_string_pos(&lcd_1, 2, 10,ch_5);
//	convert_uint8_to_string(ca200_counter,ch_5);
//	lcd_4bit_send_string_pos(&lcd_1, 2, 13,ch_5);
//	convert_uint8_to_string(ca100_counter,ch_5);
//	lcd_4bit_send_string_pos(&lcd_1, 2, 16,ch_5);
//
//}
