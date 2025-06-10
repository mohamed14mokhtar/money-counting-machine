/*
 * lcd.c
 *
 *  Created on: Aug 6, 2024
 *      Author: mokhtar
 */


#include "lcd.h"


static StdReturnType lcd_send_4bits(const chr_lcd_4bit_type *lcd, uint8_t _data_command);
static StdReturnType lcd_4bit_send_enable_signal(const chr_lcd_4bit_type *lcd);
static StdReturnType lcd_4bit_set_cursor(const chr_lcd_4bit_type *lcd,
		                                 uint8_t row, uint8_t coulmn);

static StdReturnType lcd_8bit_send_enable_signal(const chr_lcd_8bit_type *lcd);
static StdReturnType lcd_8bit_set_cursor(const chr_lcd_8bit_type *lcd,
		                                 uint8_t row, uint8_t coulmn);
StdReturnType lcd_4bit_intialize(const chr_lcd_4bit_type *lcd){
	StdReturnType ret = E_OK;
	    if(NULL == lcd){
	        ret = E_NOT_OK;
	    }
	    else{

	        HAL_Delay(20);
	        ret = lcd_4bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
	        HAL_Delay(5);
	        ret = lcd_4bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
	        HAL_Delay(1);
	        ret = lcd_4bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);

	        ret = lcd_4bit_send_command(lcd, _LCD_CLEAR);
	        ret = lcd_4bit_send_command(lcd, _LCD_RETURN_HOME);
	        ret = lcd_4bit_send_command(lcd, _LCD_ENTRY_MODE_INC_SHIFT_OFF);
	        ret = lcd_4bit_send_command(lcd, _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF);
	        ret = lcd_4bit_send_command(lcd, _LCD_4BIT_MODE_2_LINE);
	        ret = lcd_4bit_send_command(lcd, 0x80);
	    }
	    return ret;
}
StdReturnType lcd_4bit_send_command(const chr_lcd_4bit_type *lcd, uint8_t command){
	StdReturnType ret = E_OK;
	    if(NULL == lcd){
	        ret = E_NOT_OK;
	    }
	    else{
	        /* R/W Pin connected to the GND -> Logic (0) "Hard Wired" */
	        /* Write Logic (0) to the "Register Select" Pin to select the "Instruction Register"  */
	    	HAL_GPIO_WritePin(lcd->lcd_rs_port,lcd->lcd_rs_pin, GPIO_PIN_RESET);
	        /* Send the Command through the (4-Pins" Data lines */
	        ret = lcd_send_4bits(lcd, command >> 4);
	        /* Send the Enable Signal on the "E" Pin */
	        ret = lcd_4bit_send_enable_signal(lcd);
	        /* Send the Command through the (4-Pins" Data lines */
	        ret = lcd_send_4bits(lcd, command);
	        /* Send the Enable Signal on the "E" Pin */
	        ret = lcd_4bit_send_enable_signal(lcd);
	    }
	    return ret;
}
StdReturnType lcd_4bit_send_char_data(const chr_lcd_4bit_type *lcd, uint8_t data){
	StdReturnType ret = E_OK;
	    if(NULL == lcd){
	        ret = E_NOT_OK;
	    }
	    else{
	        /* R/W Pin connected to the GND -> Logic (0) "Hard Wired" */
	        /* Write Logic (1) to the "Register Select" Pin to select the "Data Register"  */
	    	HAL_GPIO_WritePin(lcd->lcd_rs_port,lcd->lcd_rs_pin, GPIO_PIN_SET);
	        /* Send the Data through the (4-Pins" Data lines */
	        ret = lcd_send_4bits(lcd, data >> 4);
	        /* Send the Enable Signal on the "E" Pin */
	        ret = lcd_4bit_send_enable_signal(lcd);
	        /* Send the Data through the (4-Pins" Data lines */
	        ret = lcd_send_4bits(lcd, data);
	        /* Send the Enable Signal on the "E" Pin */
	        ret = lcd_4bit_send_enable_signal(lcd);
	    }
	    return ret;
}
StdReturnType lcd_4bit_send_char_data_pos(const chr_lcd_4bit_type *lcd,uint8_t row,
		                                 uint8_t column, uint8_t data){
	StdReturnType ret = E_OK;
	    if(NULL == lcd){
	        ret = E_NOT_OK;
	    }
	    else{
	        ret = lcd_4bit_set_cursor(lcd, row, column);
	        ret = lcd_4bit_send_char_data(lcd, data);
	    }
	    return ret;
}
StdReturnType lcd_4bit_send_string(const chr_lcd_4bit_type *lcd, uint8_t *str){
	StdReturnType ret = E_OK;
	    if(NULL == lcd){
	        ret = E_NOT_OK;
	    }
	    else{
	        while(*str){
	            ret = lcd_4bit_send_char_data(lcd, *str++);
	        }
	    }
	    return ret;
}
StdReturnType lcd_4bit_send_string_pos(const chr_lcd_4bit_type *lcd, uint8_t row,
		                               uint8_t column, uint8_t *str){
	StdReturnType ret = E_OK;
	    if(NULL == lcd){
	        ret = E_NOT_OK;
	    }
	    else{
	        ret = lcd_4bit_set_cursor(lcd, row, column);
	        while(*str){
	            ret = lcd_4bit_send_char_data(lcd, *str++);
	        }
	    }
	    return ret;
}
StdReturnType lcd_4bit_send_custom_char(const chr_lcd_4bit_type *lcd, uint8_t row, uint8_t column,
                                         const uint8_t _chr[], uint8_t mem_pos);


/**
 *
 * @param lcd
 * @param _data_command
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
static StdReturnType lcd_send_4bits(const chr_lcd_4bit_type *lcd, uint8_t _data_command){

	StdReturnType ret = E_OK;
    HAL_GPIO_WritePin(lcd->lcd_data_port[0], lcd->lcd_data_pin[0],
    		(_data_command >> 0) & (uint8_t)0x01);
    HAL_GPIO_WritePin(lcd->lcd_data_port[1], lcd->lcd_data_pin[1],
    		(_data_command >> 1) & (uint8_t)0x01);
    HAL_GPIO_WritePin(lcd->lcd_data_port[2], lcd->lcd_data_pin[2],
    		(_data_command >> 2) & (uint8_t)0x01);
    HAL_GPIO_WritePin(lcd->lcd_data_port[3], lcd->lcd_data_pin[3],
    		(_data_command >> 3) & (uint8_t)0x01);
    return ret;
}


/**
 *
 * @param lcd
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
static StdReturnType lcd_4bit_send_enable_signal(const chr_lcd_4bit_type *lcd){
	StdReturnType ret = E_OK;
    HAL_GPIO_WritePin(lcd->lcd_en_port,lcd->lcd_en_pin, GPIO_PIN_SET);
    HAL_Delay(10);
    HAL_GPIO_WritePin(lcd->lcd_en_port,lcd->lcd_en_pin,GPIO_PIN_RESET);
    return ret;
}

/**
 *
 * @param lcd
 * @param row
 * @param coulmn
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
static StdReturnType lcd_4bit_set_cursor(const chr_lcd_4bit_type *lcd,
		                                 uint8_t row, uint8_t coulmn){
	StdReturnType ret = E_OK;
    coulmn--;
    switch(row){
        case ROW1 : ret = lcd_4bit_send_command(lcd, (0x80 + coulmn)); break;
        case ROW2 : ret = lcd_4bit_send_command(lcd, (0xc0 + coulmn)); break;
        case ROW3 : ret = lcd_4bit_send_command(lcd, (0x94 + coulmn)); break;
        case ROW4 : ret = lcd_4bit_send_command(lcd, (0xd4 + coulmn)); break;
        default : ;
    }
    return ret;
}



StdReturnType lcd_8bit_intialize(const chr_lcd_8bit_type *lcd){
	StdReturnType ret = E_OK;
	    if (NULL == lcd) {
	        ret = E_NOT_OK;
	    } else {
	        HAL_Delay(20);
	        ret = lcd_8bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
	        HAL_Delay(10);
	        ret = lcd_8bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
	        HAL_Delay(5);
	        ret = lcd_8bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);

	        ret = lcd_8bit_send_command(lcd, _LCD_CLEAR);
	        HAL_Delay(3); // Ensure sufficient delay after clearing
	        ret = lcd_8bit_send_command(lcd, _LCD_RETURN_HOME);
	        HAL_Delay(3); // Ensure sufficient delay after returning home
	        ret = lcd_8bit_send_command(lcd, _LCD_ENTRY_MODE_INC_SHIFT_OFF);
	        ret = lcd_8bit_send_command(lcd, _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF);
	        ret = lcd_8bit_send_command(lcd, 0x80); // Set cursor to the beginning of the first line
	    }
	    return ret;
}
StdReturnType lcd_8bit_send_command(const chr_lcd_8bit_type *lcd, uint8_t command){
	StdReturnType ret = E_OK;
	uint8_t l_pin_counter = ZERO_INIT;
	    if(NULL == lcd){
	        ret = E_NOT_OK;
	    }
	    else{
	        /* R/W Pin connected to the GND -> Logic (0) "Hard Wired" */
	        /* Write Logic (0) to the "Register Select" Pin to select the "Instruction Register"  */
	    	HAL_GPIO_WritePin(lcd->lcd_rs_port,lcd->lcd_rs_pin, GPIO_PIN_RESET);
	        /* Send the Command through the (8-Pins" Data lines */
	        for(l_pin_counter=0; l_pin_counter<8; ++l_pin_counter){
	             HAL_GPIO_WritePin(lcd->lcd_data_port[l_pin_counter],lcd->lcd_data_pin[l_pin_counter]
						           , ((command >> l_pin_counter) & (uint8_t)0x01));
	        }
	        /* Send the Enable Signal on the "E" Pin */
	        ret = lcd_8bit_send_enable_signal(lcd);
	    }
	    return ret;
}

StdReturnType lcd_8bit_send_char_data(const chr_lcd_8bit_type *lcd, uint8_t data){
	StdReturnType ret = E_OK;
	uint8_t l_pin_counter = ZERO_INIT;
	    if(NULL == lcd){
	        ret = E_NOT_OK;
	    }
	    else{
	        /* R/W Pin connected to the GND -> Logic (0) "Hard Wired" */
	        /* Write Logic (1) to the "Register Select" Pin to select the "Data Register"  */
	    	HAL_GPIO_WritePin(lcd->lcd_rs_port,lcd->lcd_rs_pin, GPIO_PIN_SET);
	        /* Send the Data through the (8-Pins" Data lines */
	        for(l_pin_counter=0; l_pin_counter<8; ++l_pin_counter){
	        	HAL_GPIO_WritePin(lcd->lcd_data_port[l_pin_counter],lcd->lcd_data_pin[l_pin_counter],
	        			((data >> l_pin_counter) & (uint8_t)0x01));
	        }
	        /* Send the Enable Signal on the "E" Pin */
	        ret = lcd_8bit_send_enable_signal(lcd);
	    }
	    return ret;
}
StdReturnType lcd_8bit_send_char_data_pos(const chr_lcd_8bit_type *lcd,uint8_t row,
		                                  uint8_t column, uint8_t data){
	StdReturnType ret = E_OK;
	    if(NULL == lcd){
	        ret = E_NOT_OK;
	    }
	    else{
	        ret = lcd_8bit_set_cursor(lcd, row, column);
	        ret = lcd_8bit_send_char_data(lcd, data);
	    }
	    return ret;
}
StdReturnType lcd_8bit_send_string(const chr_lcd_8bit_type *lcd, uint8_t *str){
	StdReturnType ret = E_OK;
	    if(NULL == lcd){
	        ret = E_NOT_OK;
	    }
	    else{
	        while(*str){
	            ret = lcd_8bit_send_char_data(lcd, *str++);
	        }
	    }
	    return ret;
}
StdReturnType lcd_8bit_send_string_pos(const chr_lcd_8bit_type *lcd, uint8_t row,
		                               uint8_t column, uint8_t *str){
	StdReturnType ret = E_OK;
	    if(NULL == lcd){
	        ret = E_NOT_OK;
	    }
	    else{
	        ret = lcd_8bit_set_cursor(lcd, row, column);
	        ret = lcd_8bit_send_string(lcd, str);
	    }
	    return ret;
}
StdReturnType lcd_8bit_send_custom_char(const chr_lcd_8bit_type *lcd, uint8_t row, uint8_t column,
                                         const uint8_t _chr[], uint8_t mem_pos);




/**
 *
 * @param lcd
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
static StdReturnType lcd_8bit_send_enable_signal(const chr_lcd_8bit_type *lcd){
	StdReturnType ret = E_OK;
	HAL_GPIO_WritePin(lcd->lcd_en_port,lcd->lcd_en_pin, GPIO_PIN_SET);
    HAL_Delay(5);
    HAL_GPIO_WritePin(lcd->lcd_en_port,lcd->lcd_en_pin, GPIO_PIN_RESET);
    return ret;
}

static StdReturnType lcd_8bit_set_cursor(const chr_lcd_8bit_type *lcd,
		                                 uint8_t row, uint8_t coulmn){
	StdReturnType ret = E_OK;
    coulmn--;
    switch(row){
        case ROW1 : ret = lcd_8bit_send_command(lcd, (0x80 + coulmn)); break; /* 0x00 -> Decimal : 0  */
        case ROW2 : ret = lcd_8bit_send_command(lcd, (0xc0 + coulmn)); break; /* 0x40 -> Decimal : 64 */
        case ROW3 : ret = lcd_8bit_send_command(lcd, (0x94 + coulmn)); break; /* 0x14 -> Decimal : 20 */
        case ROW4 : ret = lcd_8bit_send_command(lcd, (0xd4 + coulmn)); break; /* 0x54 -> Decimal : 84 */
        default : ;
    }
    return ret;
}
/**
 *
 * @param value
 * @param str
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
StdReturnType convert_uint8_to_string(uint8_t value, char *str) {
	StdReturnType ret = E_OK;
    if (str == NULL) {
        ret = E_NOT_OK;
    } else {
        // Ensure the string buffer is large enough
        snprintf(str, 4, "%u", value); // 4 bytes: 3 for digits + 1 for null-terminator
    }
    return ret;
}

/**
 *
 * @param value
 * @param str
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */

StdReturnType convert_uint16_to_string(uint16_t value, char *str) {
	StdReturnType ret = E_OK;
    if (str == NULL) {
        ret = E_NOT_OK;
    } else {
        // Format the string directly into the provided buffer
        snprintf(str, 6, "%u", value); // 6 bytes: 5 for digits + 1 for null-terminator
    }
    return ret;
}

/**
 *
 * @param value
 * @param str
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
StdReturnType convert_uint32_to_string(uint32_t value, char *str) {
	StdReturnType ret = E_OK;
    if (str == NULL) {
        ret = E_NOT_OK;
    } else {
        // Format the number into the provided buffer
        snprintf(str, 11, "%u", value); // 11 bytes: 10 for digits + 1 for null-terminator
    }
    return ret;
}

