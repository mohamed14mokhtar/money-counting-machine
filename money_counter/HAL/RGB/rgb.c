/*
 * rgb.c
 *
 *  Created on: Jun 2, 2025
 *      Author: Lenovo
 */


#include "rgb.h"
#include "string.h"


NoteProfile notes[] = {
    {1000, 1300,  800, 1100, 600, 900, "5 EGP"},
    {1400, 1700, 1100, 1400, 900, 1200, "10 EGP"},
    // Add others here...
};


static void TCS34725_Write8(I2C_HandleTypeDef *hi2c, uint8_t reg, uint8_t value) {
    uint8_t data[2] = {TCS34725_COMMAND_BIT | reg, value};
    HAL_I2C_Master_Transmit(hi2c, TCS34725_ADDRESS, data, 2, HAL_MAX_DELAY);
}

static uint8_t TCS34725_Read8(I2C_HandleTypeDef *hi2c, uint8_t reg) {
    uint8_t value = 0;
    uint8_t regAddr = TCS34725_COMMAND_BIT | reg;
    HAL_I2C_Master_Transmit(hi2c, TCS34725_ADDRESS, &regAddr, 1, HAL_MAX_DELAY);
    HAL_I2C_Master_Receive(hi2c, TCS34725_ADDRESS, &value, 1, HAL_MAX_DELAY);
    return value;
}

static uint16_t TCS34725_Read16(I2C_HandleTypeDef *hi2c, uint8_t reg) {
    uint8_t buffer[2] = {0};
    uint8_t regAddr = TCS34725_COMMAND_BIT | reg;
    HAL_I2C_Master_Transmit(hi2c, TCS34725_ADDRESS, &regAddr, 1, HAL_MAX_DELAY);
    HAL_I2C_Master_Receive(hi2c, TCS34725_ADDRESS, buffer, 2, HAL_MAX_DELAY);
    return (uint16_t)(buffer[1] << 8 | buffer[0]);
}

bool TCS34725_Init(I2C_HandleTypeDef *hi2c) {
    uint8_t id = TCS34725_Read8(hi2c, TCS34725_ID);
    if (id != 0x44) return false;

    TCS34725_Write8(hi2c, TCS34725_ATIME, 0xFF);     // 2.4ms integration time
    TCS34725_Write8(hi2c, TCS34725_CONTROL, 0x00);   // 1x gain
    TCS34725_Write8(hi2c, TCS34725_ENABLE, TCS34725_ENABLE_PON);
    HAL_Delay(3);
    TCS34725_Write8(hi2c, TCS34725_ENABLE, TCS34725_ENABLE_PON | TCS34725_ENABLE_AEN);
    return true;
}

void TCS34725_GetRawData(I2C_HandleTypeDef *hi2c, uint16_t *r, uint16_t *g, uint16_t *b, uint16_t *c) {
    *c = TCS34725_Read16(hi2c, TCS34725_CDATAL);
    *r = TCS34725_Read16(hi2c, TCS34725_RDATAL);
    *g = TCS34725_Read16(hi2c, TCS34725_GDATAL);
    *b = TCS34725_Read16(hi2c, TCS34725_BDATAL);
}



const char* detect_note(uint16_t r, uint16_t g, uint16_t b) {
    for (int i = 0; i < sizeof(notes) / sizeof(notes[0]); i++) {
        if (r >= notes[i].r_min && r <= notes[i].r_max &&
            g >= notes[i].g_min && g <= notes[i].g_max &&
            b >= notes[i].b_min && b <= notes[i].b_max) {
            return notes[i].label;
        }
    }
    return "Unknown";
}
