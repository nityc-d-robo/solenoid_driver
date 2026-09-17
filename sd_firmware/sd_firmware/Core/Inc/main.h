/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
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
#include "stm32g4xx_hal.h"

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

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define MCU_State_LED_Pin GPIO_PIN_0
#define MCU_State_LED_GPIO_Port GPIOF
#define FDCAN1_LED_Pin GPIO_PIN_1
#define FDCAN1_LED_GPIO_Port GPIOF
#define Solenoid1_GPIO_Pin GPIO_PIN_0
#define Solenoid1_GPIO_GPIO_Port GPIOA
#define Solenoid2_GPIO_Pin GPIO_PIN_1
#define Solenoid2_GPIO_GPIO_Port GPIOA
#define Solenoid3_GPIO_Pin GPIO_PIN_2
#define Solenoid3_GPIO_GPIO_Port GPIOA
#define Solenoid4_GPIO_Pin GPIO_PIN_3
#define Solenoid4_GPIO_GPIO_Port GPIOA
#define Solenoid5_GPIO_Pin GPIO_PIN_4
#define Solenoid5_GPIO_GPIO_Port GPIOA
#define Solenoid6_GPIO_Pin GPIO_PIN_5
#define Solenoid6_GPIO_GPIO_Port GPIOA
#define Solenoid7_GPIO_Pin GPIO_PIN_6
#define Solenoid7_GPIO_GPIO_Port GPIOA
#define Solenoid8_GPIO_Pin GPIO_PIN_7
#define Solenoid8_GPIO_GPIO_Port GPIOA
#define ID_SW_BIT2_Pin GPIO_PIN_5
#define ID_SW_BIT2_GPIO_Port GPIOB
#define ID_SW_BIT1_Pin GPIO_PIN_6
#define ID_SW_BIT1_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
