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
#define OLED_WIDTH 416
#define OLED_HEIGHT 416
#define DISPLAY_SWIRE_IN_Pin GPIO_PIN_12
#define DISPLAY_SWIRE_IN_GPIO_Port GPIOG
#define AVDDEN_Pin GPIO_PIN_9
#define AVDDEN_GPIO_Port GPIOG
#define SDMMC_EN_Pin GPIO_PIN_4
#define SDMMC_EN_GPIO_Port GPIOD
#define SDMMC1_CD_Pin GPIO_PIN_3
#define SDMMC1_CD_GPIO_Port GPIOD
#define GPIO3_Pin GPIO_PIN_5
#define GPIO3_GPIO_Port GPIOB
#define DISPLAY_SWIRE_OUT_Pin GPIO_PIN_10
#define DISPLAY_SWIRE_OUT_GPIO_Port GPIOG
#define BT_INT2_Pin GPIO_PIN_7
#define BT_INT2_GPIO_Port GPIOC
#define GPIO2_Pin GPIO_PIN_1
#define GPIO2_GPIO_Port GPIOD
#define BT_INT1_Pin GPIO_PIN_6
#define BT_INT1_GPIO_Port GPIOC
#define GNSS_RST_Pin GPIO_PIN_3
#define GNSS_RST_GPIO_Port GPIOJ
#define GPIO1_Pin GPIO_PIN_0
#define GPIO1_GPIO_Port GPIOD
#define GNSS_PPS_Pin GPIO_PIN_10
#define GNSS_PPS_GPIO_Port GPIOA
#define TP_RST_Pin GPIO_PIN_7
#define TP_RST_GPIO_Port GPIOJ
#define GNSS_WAKEUP_Pin GPIO_PIN_6
#define GNSS_WAKEUP_GPIO_Port GPIOJ
#define TP_INT_Pin GPIO_PIN_8
#define TP_INT_GPIO_Port GPIOJ
#define FLASH_RST_Pin GPIO_PIN_14
#define FLASH_RST_GPIO_Port GPIOI
#define FLASH_INT_Pin GPIO_PIN_13
#define FLASH_INT_GPIO_Port GPIOI
#define FLASH_RSTO_Pin GPIO_PIN_10
#define FLASH_RSTO_GPIO_Port GPIOI
#define DISPLAY_RST_Pin GPIO_PIN_7
#define DISPLAY_RST_GPIO_Port GPIOF
#define ALS_INT_Pin GPIO_PIN_6
#define ALS_INT_GPIO_Port GPIOF
#define BTN_Pin GPIO_PIN_8
#define BTN_GPIO_Port GPIOE
#define TOUCH_INT_Pin GPIO_PIN_7
#define TOUCH_INT_GPIO_Port GPIOE
#define TOUCH_RST_Pin GPIO_PIN_12
#define TOUCH_RST_GPIO_Port GPIOE
#define HR_INT_Pin GPIO_PIN_14
#define HR_INT_GPIO_Port GPIOD
#define PWR_INT_Pin GPIO_PIN_10
#define PWR_INT_GPIO_Port GPIOD
#define LRA_EN_Pin GPIO_PIN_9
#define LRA_EN_GPIO_Port GPIOD
#define MAG_INT_Pin GPIO_PIN_4
#define MAG_INT_GPIO_Port GPIOC
#define IMU_INT1_Pin GPIO_PIN_2
#define IMU_INT1_GPIO_Port GPIOB
#define IMU_INT2_Pin GPIO_PIN_14
#define IMU_INT2_GPIO_Port GPIOF
#define PWR_ENCHG_Pin GPIO_PIN_15
#define PWR_ENCHG_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
