/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
extern uint8_t BL_data ;
extern uint8_t money_category ;
extern uint8_t counter ;

extern char ch_counter[12];
extern uint8_t ir1_status;

 extern uint16_t total;

 extern uint8_t flag ;


 extern uint8_t ca5_counter;
 extern uint8_t ca10_counter;
 extern uint8_t ca20_counter;
 extern uint8_t ca50_counter;
 extern uint8_t ca100_counter;
 extern uint8_t ca200_counter;

 extern uint8_t flag2 ;

 extern uint8_t ch_5[12];

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define en_Pin GPIO_PIN_0
#define en_GPIO_Port GPIOA
#define es_Pin GPIO_PIN_1
#define es_GPIO_Port GPIOA
#define lcd_0_Pin GPIO_PIN_4
#define lcd_0_GPIO_Port GPIOA
#define lcd_1_Pin GPIO_PIN_5
#define lcd_1_GPIO_Port GPIOA
#define lcd_2_Pin GPIO_PIN_6
#define lcd_2_GPIO_Port GPIOA
#define lcd_3_Pin GPIO_PIN_7
#define lcd_3_GPIO_Port GPIOA
#define IR_1_Pin GPIO_PIN_12
#define IR_1_GPIO_Port GPIOB
#define IR_2_Pin GPIO_PIN_13
#define IR_2_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
