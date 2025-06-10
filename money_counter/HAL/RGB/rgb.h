/*
 * rgb.h
 *
 *  Created on: Jun 2, 2025
 *      Author: Lenovo
 */

#ifndef RGB_RGB_H_
#define RGB_RGB_H_

#include "stander_file.h"


#include "stm32f4xx_hal.h"
#include <stdbool.h>


typedef struct {
    uint16_t r_min, r_max;
    uint16_t g_min, g_max;
    uint16_t b_min, b_max;
    const char* label;
} NoteProfile;



#define TCS34725_ADDRESS        (0x29 << 1)  // I2C 7-bit address shifted for HAL
#define TCS34725_COMMAND_BIT    0x80

// Register addresses
#define TCS34725_ENABLE         0x00
#define TCS34725_ATIME          0x01
#define TCS34725_CONTROL        0x0F
#define TCS34725_ID             0x12
#define TCS34725_CDATAL         0x14
#define TCS34725_RDATAL         0x16
#define TCS34725_GDATAL         0x18
#define TCS34725_BDATAL         0x1A

// Enable register flags
#define TCS34725_ENABLE_PON     0x01
#define TCS34725_ENABLE_AEN     0x02

bool TCS34725_Init(I2C_HandleTypeDef *hi2c);
void TCS34725_GetRawData(I2C_HandleTypeDef *hi2c, uint16_t *r, uint16_t *g, uint16_t *b, uint16_t *c);
const char* detect_note(uint16_t r, uint16_t g, uint16_t b);


#endif /* RGB_RGB_H_ */
