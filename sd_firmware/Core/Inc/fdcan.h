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
#define FDCAN_FUNC_ALL          ((uint16_t)0b000U << 8)
#define FDCAN_FUNC_TX           ((uint16_t)0b001U << 8)
#define FDCAN_FUNC_RX           ((uint16_t)0b010U << 8) 

#define FDCAN_BOARD_CLASS_1     ((uint16_t)0b000U << 5)
#define FDCAN_BOARD_CLASS_2     ((uint16_t)0b001U << 5)
#define FDCAN_BOARD_CLASS_4     ((uint16_t)0b010U << 5)
#define FDCAN_BOARD_CLASS_8     ((uint16_t)0b011U << 5)
#define FDCAN_BOARD_CLASS_16    ((uint16_t)0b100U << 5)

#define FDCAN_ADDR_1(board_id) \
    (((board_id)  & 0b00011111))

#define FDCAN_ADDR_2(board_id, device_id) \
    ((((board_id) & 0b00001111) << 1) | ((device_id) & 0b1))

#define FDCAN_ADDR_4(board_id, device_id) \
    ((((board_id) & 0b00000111) << 2) | ((device_id) & 0b11))

#define FDCAN_ADDR_8(board_id, device_id) \
    ((((board_id) & 0b00000011) << 3) | ((device_id) & 0b111))

#define FDCAN_ADDR_16(board_id, device_id) \
    ((((board_id) & 0b00000001) << 4) | ((device_id) & 0b1111))

#define FDCAN_ID(func, class, device) \
    ((uint16_t)((func) | (class) | (device)))

/* Masks */
#define FDCAN_MASK_FUNC        0b11100000000U
#define FDCAN_MASK_CLASS       0b00011100000U

#define FDCAN_MASK_BOARD_1     0b00000011111U
#define FDCAN_MASK_BOARD_2     0b00000011110U
#define FDCAN_MASK_BOARD_4     0b00000011100U
#define FDCAN_MASK_BOARD_8     0b00000011000U
#define FDCAN_MASK_BOARD_16    0b00000010000U

#define FDCAN_MASK_DEVICE_1     0b00000000000U
#define FDCAN_MASK_DEVICE_2     0b00000000001U
#define FDCAN_MASK_DEVICE_4     0b00000000011U
#define FDCAN_MASK_DEVICE_8     0b00000000111U
#define FDCAN_MASK_DEVICE_16    0b00000001111U
/* USER CODE END Private defines */

void MX_FDCAN1_Init(void);

/* USER CODE BEGIN Prototypes */
void FDCAN1_ConfigAndStart(void);
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __FDCAN_H__ */

