/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "i2c.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "lcd_cfg.h"
#include "rgb.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
//NoteProfile notes[] = {
//    {1000, 1300,  800, 1100, 600, 900, "5 EGP"},
//    {1400, 1700, 1100, 1400, 900, 1200, "10 EGP"},
//    // Add others here...
//};

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define RECEIVE_DATA 1
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
uint8_t BL_data ;
uint8_t money_category ;
uint8_t counter ;

char ch_counter[12];
char ch_total[12];
char ch_ca[12];
uint8_t ir1_status;

uint16_t total;

uint8_t flag ;

uint16_t red,green,blue,clear;


uint8_t ca5_counter;
uint8_t ca10_counter;
uint8_t ca20_counter;
uint8_t ca50_counter;
uint8_t ca100_counter;
uint8_t ca200_counter;

uint8_t ch_5[12];

uint8_t flag2;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C1_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */

  lcd_4bit_intialize(&lcd_1);
  //TCS34725_Init(&hi2c1);
  HAL_UART_Receive_IT(&huart2, &BL_data, 1);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  lcd_4bit_send_command(&lcd_1, _LCD_CLEAR);
  lcd_4bit_send_string_pos(&lcd_1, 1, 1, "Count :");
  lcd_4bit_send_string_pos(&lcd_1, 2, 1, "Total :");
  lcd_4bit_send_string_pos(&lcd_1, 1, 11, "CA:");

  while (1)
  {

	  if(!(HAL_GPIO_ReadPin(IR_1_GPIO_Port, IR_1_Pin))){
		  lcd_4bit_send_command(&lcd_1, _LCD_CLEAR);
		  lcd_4bit_send_string_pos(&lcd_1, 1, 1, "count:");
		  lcd_4bit_send_string_pos(&lcd_1, 2, 1, "Total :");
		  lcd_4bit_send_string_pos(&lcd_1, 1, 11, "CA:");
		  counter++;
		  switch(money_category){
		  case 200:
			  ca200_counter++;
			  break;
		  case 100:
			  ca100_counter++;
			  break;
		  case 50:
			  ca50_counter++;
			  break;
		  case 20:
			  ca20_counter++;
			  break;
		  case 10:
			  ca10_counter++;
			  break;
		  case 5:
			  ca5_counter++;
			  break;
		  }
		  //total += ((counter*money_category) - (money_category * (counter-1)));
		  total += money_category;  // every time
		  convert_uint8_to_string(counter,ch_counter);
		  convert_uint8_to_string(money_category,ch_ca);
		  convert_uint16_to_string(total,ch_total);
		  lcd_4bit_send_string_pos(&lcd_1, 1, 8,ch_counter);
		  lcd_4bit_send_string_pos(&lcd_1, 1, 14,ch_ca);
		  lcd_4bit_send_string_pos(&lcd_1, 2, 9,ch_total);
		  while(!(HAL_GPIO_ReadPin(IR_1_GPIO_Port, IR_1_Pin)));
		  HAL_Delay(50);
	  }
	  if(flag){
		 flag = 0;
		 money_category = 0 ;
		total = 0 ;
	    counter = 0;
		ca5_counter = 0;
		ca50_counter = 0;
		ca20_counter = 0;
		ca100_counter = 0;
		ca10_counter = 0;
		ca200_counter = 0;
		lcd_4bit_send_command(&lcd_1, _LCD_CLEAR);
		lcd_4bit_send_command(&lcd_1, _LCD_CLEAR);
		lcd_4bit_send_string_pos(&lcd_1, 1, 1, "count:");
		lcd_4bit_send_string_pos(&lcd_1, 2, 1, "Total :");
		lcd_4bit_send_string_pos(&lcd_1, 1, 11, "CA:");
	  }

	  if(flag2){
		  flag2 = 0;
			lcd_4bit_send_command(&lcd_1, _LCD_CLEAR);
			lcd_4bit_send_string_pos(&lcd_1, 1, 1, "5 10 20 50 100 2");
			convert_uint8_to_string(ca5_counter,ch_5);
			lcd_4bit_send_string_pos(&lcd_1, 2, 1,ch_5 );
			convert_uint8_to_string(ca10_counter,ch_5);
			lcd_4bit_send_string_pos(&lcd_1, 2, 3,ch_5);
			convert_uint8_to_string(ca20_counter,ch_5);
			lcd_4bit_send_string_pos(&lcd_1, 2, 6,ch_5);
			convert_uint8_to_string(ca50_counter,ch_5);
			lcd_4bit_send_string_pos(&lcd_1, 2, 10,ch_5);
			convert_uint8_to_string(ca100_counter,ch_5);
			lcd_4bit_send_string_pos(&lcd_1, 2, 13,ch_5);
			convert_uint8_to_string(ca200_counter,ch_5);
			lcd_4bit_send_string_pos(&lcd_1, 2, 16,ch_5);
	  }


    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){

	HAL_UART_Receive_IT(&huart2, &BL_data, 1);
	switch (BL_data){
	case '1':
		money_category = 5;
		counter = 0;
		break;
	case '2':
		money_category = 10;
		counter = 0;
		break;
	case '3':
		money_category = 20;
		counter = 0;
		break;
	case '4':
		money_category = 50;
		counter = 0;
		break;
	case '5':
		money_category = 100;
		counter = 0;
		break;
	case '6':
		money_category = 200;
		counter = 0;
		break;

	}
}


/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
