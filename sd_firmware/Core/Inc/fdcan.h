/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    fdcan.h
  * @brief   This file contains all the function prototypes for
  *          the fdcan.c file
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
#ifndef __FDCAN_H__
#define __FDCAN_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

extern FDCAN_HandleTypeDef hfdcan1;

/* USER CODE BEGIN Private defines */
#define FDCAN_FUNC_WRITE        ((uint16_t)0b000U << 7)
#define FDCAN_FUNC_READ         ((uint16_t)0b001U << 7)
#define FDCAN_FUNC_STATE        ((uint16_t)0b010U << 7) 

/* Masks */
#define FDCAN_MASK_FUNC         0b11110000000U
#define FDCAN_MASK_DEVICE       0b00001111111U

//旧CAN規格
#define FDCAN_FUNC_TX           0b001U
#define FDCAN_FUNC_RX           0b010U
#define FDCAN_BOARD_CLASS_8     0b011U
#define BOARD_ID                0b1
#define FDCAN_MASK_FUNC_OLD     (0b111U << 8)
#define FDCAN_MASK_CLASS        (0b111U << 5)
#define FDCAN_MASK_BOARD_8      (0b11U << 3)
#define FDCAN_MASK_DEVICE_8     0b111
#define PACKET_TYPE_CMD         0x1

/* USER CODE END Private defines */

void MX_FDCAN1_Init(void);

/* USER CODE BEGIN Prototypes */
void FDCAN1_ConfigAndStart(void);

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __FDCAN_H__ */

