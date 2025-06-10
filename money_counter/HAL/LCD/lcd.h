/*
 * lcd.h
 *
 *  Created on: Aug 6, 2024
 *      Author: mokhtar
 */

#ifndef HAL_LCD_LCD_H_
#define HAL_LCD_LCD_H_

#include"stander_file.h"
#include"stdio.h"
/* Modes */
#define _LCD_CLEAR                      0X01
#define _LCD_RETURN_HOME                0x02
#define _LCD_ENTRY_MODE_DEC_SHIFT_OFF   0x04
#define _LCD_ENTRY_MODE_DEC_SHIFT_ON    0x05
#define _LCD_ENTRY_MODE_INC_SHIFT_OFF   0x06
#define _LCD_ENTRY_MODE_INC_SHIFT_ON    0x07
#define _LCD_CURSOR_MOVE_SHIFT_LEFT     0x10
#define _LCD_CURSOR_MOVE_SHIFT_RIGHT    0x14
#define _LCD_DISPLAY_SHIFT_LEFT         0x18
#define _LCD_DISPLAY_SHIFT_RIGHT        0x1C
#define _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF 0x0C
#define _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_ON  0x0D
#define _LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_OFF  0x0E
#define _LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_ON   0x0F
#define _LCD_DISPLAY_OFF_CURSOR_OFF              0x08
#define _LCD_8BIT_MODE_2_LINE           0x38
#define _LCD_4BIT_MODE_2_LINE           0x28


#define _LCD_CGRAM_START                0x40
#define _LCD_DDRAM_START                0x80

#define ZERO_INIT 0
#define E_NOT_OK 0
/* rows select */
#define ROW1 1
#define ROW2 2
#define ROW3 3
#define ROW4 4


typedef struct{
	GPIO_TypeDef *lcd_rs_port;
	uint16_t lcd_rs_pin;
	GPIO_TypeDef *lcd_en_port;
	uint16_t lcd_en_pin;
    GPIO_TypeDef *lcd_data_port[4];
    uint16_t lcd_data_pin[4];
}chr_lcd_4bit_type;

typedef struct{
	GPIO_TypeDef *lcd_rs_port;
	uint16_t lcd_rs_pin;
	GPIO_TypeDef *lcd_en_port;
	uint16_t lcd_en_pin;
    GPIO_TypeDef *lcd_data_port[8];
    uint16_t lcd_data_pin[8];
}chr_lcd_8bit_type;


StdReturnType lcd_4bit_intialize(const chr_lcd_4bit_type *lcd);
StdReturnType lcd_4bit_send_command(const chr_lcd_4bit_type *lcd, uint8_t command);
StdReturnType lcd_4bit_send_char_data(const chr_lcd_4bit_type *lcd, uint8_t data);
StdReturnType lcd_4bit_send_char_data_pos(const chr_lcd_4bit_type *lcd,uint8_t row,
		                                 uint8_t column, uint8_t data);
StdReturnType lcd_4bit_send_string(const chr_lcd_4bit_type *lcd, uint8_t *str);
StdReturnType lcd_4bit_send_string_pos(const chr_lcd_4bit_type *lcd, uint8_t row,
		                               uint8_t column, uint8_t *str);
StdReturnType lcd_4bit_send_custom_char(const chr_lcd_4bit_type *lcd, uint8_t row, uint8_t column,
                                         const uint8_t _chr[], uint8_t mem_pos);



StdReturnType lcd_8bit_intialize(const chr_lcd_8bit_type *lcd);
StdReturnType lcd_8bit_send_command(const chr_lcd_8bit_type *lcd, uint8_t command);
StdReturnType lcd_8bit_send_char_data(const chr_lcd_8bit_type *lcd, uint8_t data);
StdReturnType lcd_8bit_send_char_data_pos(const chr_lcd_8bit_type *lcd,uint8_t row,
		                                  uint8_t column, uint8_t data);
StdReturnType lcd_8bit_send_string(const chr_lcd_8bit_type *lcd, uint8_t *str);
StdReturnType lcd_8bit_send_string_pos(const chr_lcd_8bit_type *lcd, uint8_t row,
		                               uint8_t column, uint8_t *str);
StdReturnType lcd_8bit_send_custom_char(const chr_lcd_8bit_type *lcd, uint8_t row, uint8_t column,
                                         const uint8_t _chr[], uint8_t mem_pos);


StdReturnType convert_uint8_to_string(uint8_t value, char *str);
StdReturnType convert_uint16_to_string(uint16_t value, char *str) ;
StdReturnType convert_uint32_to_string(uint32_t value, char *str) ;

#endif /* HAL_LCD_LCD_H_ */
