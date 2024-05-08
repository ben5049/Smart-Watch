/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "stm32u5xx_hal.h"

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
#define DISPLAY_RST_Pin GPIO_PIN_3
#define DISPLAY_RST_GPIO_Port GPIOH
#define GNSS_WAKEUP_Pin GPIO_PIN_14
#define GNSS_WAKEUP_GPIO_Port GPIOG
#define GNSS_PPS_Pin GPIO_PIN_12
#define GNSS_PPS_GPIO_Port GPIOG
#define TP_INT_Pin GPIO_PIN_2
#define TP_INT_GPIO_Port GPIOE
#define TP_RST_Pin GPIO_PIN_3
#define TP_RST_GPIO_Port GPIOE
#define SWIRE_IN_Pin GPIO_PIN_0
#define SWIRE_IN_GPIO_Port GPIOE
#define GNSS_RST_Pin GPIO_PIN_15
#define GNSS_RST_GPIO_Port GPIOG
#define SWIRE_OUT_Pin GPIO_PIN_4
#define SWIRE_OUT_GPIO_Port GPIOE
#define IMU_INT1_Pin GPIO_PIN_5
#define IMU_INT1_GPIO_Port GPIOE
#define GPIO3_Pin GPIO_PIN_13
#define GPIO3_GPIO_Port GPIOG
#define AVDDEN_Pin GPIO_PIN_6
#define AVDDEN_GPIO_Port GPIOE
#define IMU_INT2_Pin GPIO_PIN_13
#define IMU_INT2_GPIO_Port GPIOC
#define BT_DEV_WAKE_Pin GPIO_PIN_2
#define BT_DEV_WAKE_GPIO_Port GPIOI
#define BT_HOST_WAKE_Pin GPIO_PIN_3
#define BT_HOST_WAKE_GPIO_Port GPIOI
#define FLASH_RSTO_Pin GPIO_PIN_7
#define FLASH_RSTO_GPIO_Port GPIOC
#define BT_EN_Pin GPIO_PIN_0
#define BT_EN_GPIO_Port GPIOI
#define WL_EN_Pin GPIO_PIN_1
#define WL_EN_GPIO_Port GPIOI
#define GPIO2_Pin GPIO_PIN_2
#define GPIO2_GPIO_Port GPIOF
#define GPIO1_Pin GPIO_PIN_2
#define GPIO1_GPIO_Port GPIOC
#define FLASH_INT_Pin GPIO_PIN_6
#define FLASH_INT_GPIO_Port GPIOC
#define WL_HOST_WAKE_Pin GPIO_PIN_14
#define WL_HOST_WAKE_GPIO_Port GPIOH
#define WL_BT_PWR_EN_Pin GPIO_PIN_15
#define WL_BT_PWR_EN_GPIO_Port GPIOH
#define MAG_INT_Pin GPIO_PIN_8
#define MAG_INT_GPIO_Port GPIOE
#define TOUCH_RST_Pin GPIO_PIN_15
#define TOUCH_RST_GPIO_Port GPIOD
#define FLASH_RST_Pin GPIO_PIN_13
#define FLASH_RST_GPIO_Port GPIOH
#define ALS_INT_Pin GPIO_PIN_1
#define ALS_INT_GPIO_Port GPIOG
#define SD_CD_Pin GPIO_PIN_0
#define SD_CD_GPIO_Port GPIOG
#define PWR_INT_Pin GPIO_PIN_9
#define PWR_INT_GPIO_Port GPIOD
#define ELVSS_ADC_Pin GPIO_PIN_3
#define ELVSS_ADC_GPIO_Port GPIOC
#define ELVDD_ADC_Pin GPIO_PIN_4
#define ELVDD_ADC_GPIO_Port GPIOA
#define SD_EN_Pin GPIO_PIN_7
#define SD_EN_GPIO_Port GPIOE
#define TOUCH_INT_Pin GPIO_PIN_11
#define TOUCH_INT_GPIO_Port GPIOD
#define HR_INT_Pin GPIO_PIN_10
#define HR_INT_GPIO_Port GPIOD
#define LRA_EN_Pin GPIO_PIN_14
#define LRA_EN_GPIO_Port GPIOD
#define AVDD_ADC_Pin GPIO_PIN_3
#define AVDD_ADC_GPIO_Port GPIOA
#define ISYS_ADC_Pin GPIO_PIN_1
#define ISYS_ADC_GPIO_Port GPIOB
#define BTN_Pin GPIO_PIN_15
#define BTN_GPIO_Port GPIOB
#define PWR_ENCHG_Pin GPIO_PIN_8
#define PWR_ENCHG_GPIO_Port GPIOD

/* USER CODE BEGIN Private defines */
extern uint32_t framebuf[];
extern DSI_HandleTypeDef hdsi;
extern LTDC_HandleTypeDef hltdc;
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
