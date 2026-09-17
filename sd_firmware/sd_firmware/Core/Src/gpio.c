/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpio.c
  * @brief   This file provides code for the configuration
  *          of all used GPIO pins.
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

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"

/* USER CODE BEGIN 0 */
//ソレノイドピン構造体の定義
typedef struct {
  GPIO_TypeDef *port;
  uint16_t pin;
}SolenoidPin;

//ソレノイドピンの配列を定義
static const SolenoidPin SOLENOID_PINS[SOLENOID_COUNT] = {
  {GPIOA, Solenoid1_GPIO_Pin},
  {GPIOA, Solenoid2_GPIO_Pin},
  {GPIOA, Solenoid3_GPIO_Pin},
  {GPIOA, Solenoid4_GPIO_Pin},
  {GPIOA, Solenoid5_GPIO_Pin},
  {GPIOA, Solenoid6_GPIO_Pin},
  {GPIOA, Solenoid7_GPIO_Pin},
  {GPIOA, Solenoid8_GPIO_Pin}
};

static volatile bool solenoidTargets[SOLENOID_COUNT] = {false}; // 追加：ソレノイドの目標状態を保持する配列
/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/** Configure pins as
        * Analog
        * Input
        * Output
        * EVENT_OUT
        * EXTI
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOF, MCU_State_LED_Pin|FDCAN1_LED_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, Solenoid1_GPIO_Pin|Solenoid2_GPIO_Pin|Solenoid3_GPIO_Pin|Solenoid4_GPIO_Pin
                          |Solenoid5_GPIO_Pin|Solenoid6_GPIO_Pin|Solenoid7_GPIO_Pin|Solenoid8_GPIO_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : MCU_State_LED_Pin FDCAN1_LED_Pin */
  GPIO_InitStruct.Pin = MCU_State_LED_Pin|FDCAN1_LED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

  /*Configure GPIO pins : Solenoid1_GPIO_Pin Solenoid2_GPIO_Pin Solenoid3_GPIO_Pin Solenoid4_GPIO_Pin
                           Solenoid5_GPIO_Pin Solenoid6_GPIO_Pin Solenoid7_GPIO_Pin Solenoid8_GPIO_Pin */
  GPIO_InitStruct.Pin = Solenoid1_GPIO_Pin|Solenoid2_GPIO_Pin|Solenoid3_GPIO_Pin|Solenoid4_GPIO_Pin
                          |Solenoid5_GPIO_Pin|Solenoid6_GPIO_Pin|Solenoid7_GPIO_Pin|Solenoid8_GPIO_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : ID_SW_BIT2_Pin ID_SW_BIT1_Pin */
  GPIO_InitStruct.Pin = ID_SW_BIT2_Pin|ID_SW_BIT1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 2 */

// CAN割り込み用：配列の値を書き換えるだけの軽量処理
void setSolenoidTarget(uint8_t index, bool state){
  if (index >= SOLENOID_COUNT) return;
  solenoidTargets[index] = state;
}

//ソレノイド制御関数
void setSolenoidState(uint8_t index, bool state){
  if (index >= SOLENOID_COUNT) return;
  HAL_GPIO_WritePin(SOLENOID_PINS[index].port,
                    SOLENOID_PINS[index].pin,
                    state ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

// タイマー割り込み用：バッファの値を実際のGPIOピンへ出力
void updateSolenoidOutputs(void){
  for (uint8_t i = 0; i < SOLENOID_COUNT; i++0){
    setSolenoidState(i, solenoidTargets[i]);
  }
}

void stopAllSolenoids(void){
  for (uint8_t i = 0; i < SOLENOID_COUNT; i++){
    setSolenoidState(i, false);
  } 
  updateSolenoidOutputs(); // 追加：全ソレノイドを停止した後、出力を更新
}

uint8_t getNodeID(void){
  GPIO_PinState bit1 = HAL_GPIO_ReadPin(GPIOB, ID_SW_BIT1_Pin); 
  if (bit1 == GPIO_PIN_SET){
    return 0x01; // Bit1がHIGHの場合、Node IDは0x01
  }else{
    return 0x00; // Bit1がLOWの場合、Node IDは0x00
  }
  
}
/* USER CODE END 2 */
