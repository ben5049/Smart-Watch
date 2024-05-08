/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file         stm32u5xx_hal_msp.c
  * @brief        This file provides code for the MSP Initialization
  *               and de-Initialization codes.
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

/* Includes ------------------------------------------------------------------*/
#include "main.h"
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */
extern DMA_NodeTypeDef Node_GPDMA1_Channel0;

extern DMA_QListTypeDef List_GPDMA1_Channel0;

extern DMA_HandleTypeDef handle_GPDMA1_Channel0;

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN Define */

/* USER CODE END Define */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN Macro */

/* USER CODE END Macro */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* External functions --------------------------------------------------------*/
/* USER CODE BEGIN ExternalFunctions */

/* USER CODE END ExternalFunctions */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */
/**
  * Initializes the Global MSP.
  */
void HAL_MspInit(void)
{

  /* USER CODE BEGIN MspInit 0 */

  /* USER CODE END MspInit 0 */

  __HAL_RCC_PWR_CLK_ENABLE();
  HAL_PWREx_EnableVddA();

  /* System interrupt init*/

  /* Peripheral interrupt init */
  /* RCC_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(RCC_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(RCC_IRQn);

  /** Enable the VREF clock
  */
  __HAL_RCC_VREF_CLK_ENABLE();

  /** Configure the internal voltage reference buffer voltage scale
  */
  HAL_SYSCFG_VREFBUF_VoltageScalingConfig(SYSCFG_VREFBUF_VOLTAGE_SCALE0);

  /** Enable the Internal Voltage Reference buffer
  */
  HAL_SYSCFG_EnableVREFBUF();

  /** Configure the internal voltage reference buffer high impedance mode
  */
  HAL_SYSCFG_VREFBUF_HighImpedanceConfig(SYSCFG_VREFBUF_HIGH_IMPEDANCE_DISABLE);

  /* USER CODE BEGIN MspInit 1 */

  /* USER CODE END MspInit 1 */
}

/**
* @brief ADC MSP Initialization
* This function configures the hardware resources used in this example
* @param hadc: ADC handle pointer
* @retval None
*/
void HAL_ADC_MspInit(ADC_HandleTypeDef* hadc)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  DMA_NodeConfTypeDef NodeConfig;
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};
  if(hadc->Instance==ADC1)
  {
  /* USER CODE BEGIN ADC1_MspInit 0 */

  /* USER CODE END ADC1_MspInit 0 */

  /** Initializes the peripherals clock
  */
    PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADCDAC;
    PeriphClkInit.AdcDacClockSelection = RCC_ADCDACCLKSOURCE_HSI;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
    {
      Error_Handler();
    }

    /* Peripheral clock enable */
    __HAL_RCC_ADC12_CLK_ENABLE();

    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**ADC1 GPIO Configuration
    PC3     ------> ADC1_IN4
    PA4     ------> ADC1_IN9
    PA3     ------> ADC1_IN8
    PB1     ------> ADC1_IN16
    */
    GPIO_InitStruct.Pin = ELVSS_ADC_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(ELVSS_ADC_GPIO_Port, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = ELVDD_ADC_Pin|AVDD_ADC_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = ISYS_ADC_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(ISYS_ADC_GPIO_Port, &GPIO_InitStruct);

    /* ADC1 DMA Init */
    /* GPDMA1_REQUEST_ADC1 Init */
    NodeConfig.NodeType = DMA_GPDMA_LINEAR_NODE;
    NodeConfig.Init.Request = GPDMA1_REQUEST_ADC1;
    NodeConfig.Init.BlkHWRequest = DMA_BREQ_SINGLE_BURST;
    NodeConfig.Init.Direction = DMA_PERIPH_TO_MEMORY;
    NodeConfig.Init.SrcInc = DMA_SINC_FIXED;
    NodeConfig.Init.DestInc = DMA_DINC_FIXED;
    NodeConfig.Init.SrcDataWidth = DMA_SRC_DATAWIDTH_HALFWORD;
    NodeConfig.Init.DestDataWidth = DMA_DEST_DATAWIDTH_HALFWORD;
    NodeConfig.Init.SrcBurstLength = 1;
    NodeConfig.Init.DestBurstLength = 1;
    NodeConfig.Init.TransferAllocatedPort = DMA_SRC_ALLOCATED_PORT0|DMA_DEST_ALLOCATED_PORT1;
    NodeConfig.Init.TransferEventMode = DMA_TCEM_BLOCK_TRANSFER;
    NodeConfig.Init.Mode = DMA_NORMAL;
    NodeConfig.TriggerConfig.TriggerPolarity = DMA_TRIG_POLARITY_MASKED;
    NodeConfig.DataHandlingConfig.DataExchange = DMA_EXCHANGE_NONE;
    NodeConfig.DataHandlingConfig.DataAlignment = DMA_DATA_RIGHTALIGN_ZEROPADDED;
    if (HAL_DMAEx_List_BuildNode(&NodeConfig, &Node_GPDMA1_Channel0) != HAL_OK)
    {
      Error_Handler();
    }

    if (HAL_DMAEx_List_InsertNode(&List_GPDMA1_Channel0, NULL, &Node_GPDMA1_Channel0) != HAL_OK)
    {
      Error_Handler();
    }

    if (HAL_DMAEx_List_SetCircularMode(&List_GPDMA1_Channel0) != HAL_OK)
    {
      Error_Handler();
    }

    handle_GPDMA1_Channel0.Instance = GPDMA1_Channel0;
    handle_GPDMA1_Channel0.InitLinkedList.Priority = DMA_LOW_PRIORITY_LOW_WEIGHT;
    handle_GPDMA1_Channel0.InitLinkedList.LinkStepMode = DMA_LSM_FULL_EXECUTION;
    handle_GPDMA1_Channel0.InitLinkedList.LinkAllocatedPort = DMA_LINK_ALLOCATED_PORT0;
    handle_GPDMA1_Channel0.InitLinkedList.TransferEventMode = DMA_TCEM_BLOCK_TRANSFER;
    handle_GPDMA1_Channel0.InitLinkedList.LinkedListMode = DMA_LINKEDLIST_CIRCULAR;
    if (HAL_DMAEx_List_Init(&handle_GPDMA1_Channel0) != HAL_OK)
    {
      Error_Handler();
    }

    if (HAL_DMAEx_List_LinkQ(&handle_GPDMA1_Channel0, &List_GPDMA1_Channel0) != HAL_OK)
    {
      Error_Handler();
    }

    __HAL_LINKDMA(hadc, DMA_Handle, handle_GPDMA1_Channel0);

    if (HAL_DMA_ConfigChannelAttributes(&handle_GPDMA1_Channel0, DMA_CHANNEL_NPRIV) != HAL_OK)
    {
      Error_Handler();
    }

    /* ADC1 interrupt Init */
    HAL_NVIC_SetPriority(ADC1_2_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(ADC1_2_IRQn);
  /* USER CODE BEGIN ADC1_MspInit 1 */

  /* USER CODE END ADC1_MspInit 1 */
  }

}

/**
* @brief ADC MSP De-Initialization
* This function freeze the hardware resources used in this example
* @param hadc: ADC handle pointer
* @retval None
*/
void HAL_ADC_MspDeInit(ADC_HandleTypeDef* hadc)
{
  if(hadc->Instance==ADC1)
  {
  /* USER CODE BEGIN ADC1_MspDeInit 0 */

  /* USER CODE END ADC1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_ADC12_CLK_DISABLE();

    /**ADC1 GPIO Configuration
    PC3     ------> ADC1_IN4
    PA4     ------> ADC1_IN9
    PA3     ------> ADC1_IN8
    PB1     ------> ADC1_IN16
    */
    HAL_GPIO_DeInit(ELVSS_ADC_GPIO_Port, ELVSS_ADC_Pin);

    HAL_GPIO_DeInit(GPIOA, ELVDD_ADC_Pin|AVDD_ADC_Pin);

    HAL_GPIO_DeInit(ISYS_ADC_GPIO_Port, ISYS_ADC_Pin);

    /* ADC1 DMA DeInit */
    HAL_DMA_DeInit(hadc->DMA_Handle);

    /* ADC1 interrupt DeInit */
    HAL_NVIC_DisableIRQ(ADC1_2_IRQn);
  /* USER CODE BEGIN ADC1_MspDeInit 1 */

  /* USER CODE END ADC1_MspDeInit 1 */
  }

}

/**
* @brief CRC MSP Initialization
* This function configures the hardware resources used in this example
* @param hcrc: CRC handle pointer
* @retval None
*/
void HAL_CRC_MspInit(CRC_HandleTypeDef* hcrc)
{
  if(hcrc->Instance==CRC)
  {
  /* USER CODE BEGIN CRC_MspInit 0 */

  /* USER CODE END CRC_MspInit 0 */
    /* Peripheral clock enable */
    __HAL_RCC_CRC_CLK_ENABLE();
  /* USER CODE BEGIN CRC_MspInit 1 */

  /* USER CODE END CRC_MspInit 1 */
  }

}

/**
* @brief CRC MSP De-Initialization
* This function freeze the hardware resources used in this example
* @param hcrc: CRC handle pointer
* @retval None
*/
void HAL_CRC_MspDeInit(CRC_HandleTypeDef* hcrc)
{
  if(hcrc->Instance==CRC)
  {
  /* USER CODE BEGIN CRC_MspDeInit 0 */

  /* USER CODE END CRC_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_CRC_CLK_DISABLE();
  /* USER CODE BEGIN CRC_MspDeInit 1 */

  /* USER CODE END CRC_MspDeInit 1 */
  }

}

/**
* @brief DSI MSP Initialization
* This function configures the hardware resources used in this example
* @param hdsi: DSI handle pointer
* @retval None
*/
void HAL_DSI_MspInit(DSI_HandleTypeDef* hdsi)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};
  if(hdsi->Instance==DSI)
  {
  /* USER CODE BEGIN DSI_MspInit 0 */

  /* USER CODE END DSI_MspInit 0 */

  /** Initializes the peripherals clock
  */
    PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_DSI;
    PeriphClkInit.DsiClockSelection = RCC_DSICLKSOURCE_PLL3;
    PeriphClkInit.PLL3.PLL3Source = RCC_PLLSOURCE_HSE;
    PeriphClkInit.PLL3.PLL3M = 4;
    PeriphClkInit.PLL3.PLL3N = 125;
    PeriphClkInit.PLL3.PLL3P = 8;
    PeriphClkInit.PLL3.PLL3Q = 2;
    PeriphClkInit.PLL3.PLL3R = 8;
    PeriphClkInit.PLL3.PLL3RGE = RCC_PLLVCIRANGE_0;
    PeriphClkInit.PLL3.PLL3FRACN = 0;
    PeriphClkInit.PLL3.PLL3ClockOut = RCC_PLL3_DIVP;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
    {
      Error_Handler();
    }

    /* Peripheral clock enable */
    __HAL_RCC_DSI_CLK_ENABLE();

    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**DSIHOST GPIO Configuration
    PB7     ------> DSIHOST_TE
    DSI_D0N     ------> DSIHOST_D0N
    DSI_D0P     ------> DSIHOST_D0P
    DSI_CKN     ------> DSIHOST_CKN
    DSI_CKP     ------> DSIHOST_CKP
    DSI_D1N     ------> DSIHOST_D1N
    DSI_D1P     ------> DSIHOST_D1P
    */
    GPIO_InitStruct.Pin = GPIO_PIN_7;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF11_DSI;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* DSI interrupt Init */
    HAL_NVIC_SetPriority(DSI_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(DSI_IRQn);
  /* USER CODE BEGIN DSI_MspInit 1 */

  /* USER CODE END DSI_MspInit 1 */
  }

}

/**
* @brief DSI MSP De-Initialization
* This function freeze the hardware resources used in this example
* @param hdsi: DSI handle pointer
* @retval None
*/
void HAL_DSI_MspDeInit(DSI_HandleTypeDef* hdsi)
{
  if(hdsi->Instance==DSI)
  {
  /* USER CODE BEGIN DSI_MspDeInit 0 */

  /* USER CODE END DSI_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_DSI_CLK_DISABLE();

    /**DSIHOST GPIO Configuration
    PB7     ------> DSIHOST_TE
    DSI_D0N     ------> DSIHOST_D0N
    DSI_D0P     ------> DSIHOST_D0P
    DSI_CKN     ------> DSIHOST_CKN
    DSI_CKP     ------> DSIHOST_CKP
    DSI_D1N     ------> DSIHOST_D1N
    DSI_D1P     ------> DSIHOST_D1P
    */
    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_7);

    /* DSI interrupt DeInit */
    HAL_NVIC_DisableIRQ(DSI_IRQn);
  /* USER CODE BEGIN DSI_MspDeInit 1 */

  /* USER CODE END DSI_MspDeInit 1 */
  }

}

/**
* @brief I2C MSP Initialization
* This function configures the hardware resources used in this example
* @param hi2c: I2C handle pointer
* @retval None
*/
void HAL_I2C_MspInit(I2C_HandleTypeDef* hi2c)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};
  if(hi2c->Instance==I2C5)
  {
  /* USER CODE BEGIN I2C5_MspInit 0 */

  /* USER CODE END I2C5_MspInit 0 */

  /** Initializes the peripherals clock
  */
    PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_I2C5;
    PeriphClkInit.I2c5ClockSelection = RCC_I2C5CLKSOURCE_PCLK1;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
    {
      Error_Handler();
    }

    __HAL_RCC_GPIOD_CLK_ENABLE();
    /**I2C5 GPIO Configuration
    PD0     ------> I2C5_SDA
    PD1     ------> I2C5_SCL
    */
    GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF4_I2C5;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    /* Peripheral clock enable */
    __HAL_RCC_I2C5_CLK_ENABLE();
  /* USER CODE BEGIN I2C5_MspInit 1 */

  /* USER CODE END I2C5_MspInit 1 */
  }

}

/**
* @brief I2C MSP De-Initialization
* This function freeze the hardware resources used in this example
* @param hi2c: I2C handle pointer
* @retval None
*/
void HAL_I2C_MspDeInit(I2C_HandleTypeDef* hi2c)
{
  if(hi2c->Instance==I2C5)
  {
  /* USER CODE BEGIN I2C5_MspDeInit 0 */

  /* USER CODE END I2C5_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_I2C5_CLK_DISABLE();

    /**I2C5 GPIO Configuration
    PD0     ------> I2C5_SDA
    PD1     ------> I2C5_SCL
    */
    HAL_GPIO_DeInit(GPIOD, GPIO_PIN_0);

    HAL_GPIO_DeInit(GPIOD, GPIO_PIN_1);

  /* USER CODE BEGIN I2C5_MspDeInit 1 */

  /* USER CODE END I2C5_MspDeInit 1 */
  }

}

/**
* @brief LTDC MSP Initialization
* This function configures the hardware resources used in this example
* @param hltdc: LTDC handle pointer
* @retval None
*/
void HAL_LTDC_MspInit(LTDC_HandleTypeDef* hltdc)
{
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};
  if(hltdc->Instance==LTDC)
  {
  /* USER CODE BEGIN LTDC_MspInit 0 */

  /* USER CODE END LTDC_MspInit 0 */

  /** Initializes the peripherals clock
  */
    PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_LTDC;
    PeriphClkInit.LtdcClockSelection = RCC_LTDCCLKSOURCE_PLL2;
    PeriphClkInit.PLL2.PLL2Source = RCC_PLLSOURCE_HSE;
    PeriphClkInit.PLL2.PLL2M = 1;
    PeriphClkInit.PLL2.PLL2N = 10;
    PeriphClkInit.PLL2.PLL2P = 2;
    PeriphClkInit.PLL2.PLL2Q = 2;
    PeriphClkInit.PLL2.PLL2R = 8;
    PeriphClkInit.PLL2.PLL2RGE = RCC_PLLVCIRANGE_1;
    PeriphClkInit.PLL2.PLL2FRACN = 0;
    PeriphClkInit.PLL2.PLL2ClockOut = RCC_PLL2_DIVR;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
    {
      Error_Handler();
    }

    /* Peripheral clock enable */
    __HAL_RCC_LTDC_CLK_ENABLE();
    /* LTDC interrupt Init */
    HAL_NVIC_SetPriority(LTDC_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(LTDC_IRQn);
  /* USER CODE BEGIN LTDC_MspInit 1 */

  /* USER CODE END LTDC_MspInit 1 */
  }

}

/**
* @brief LTDC MSP De-Initialization
* This function freeze the hardware resources used in this example
* @param hltdc: LTDC handle pointer
* @retval None
*/
void HAL_LTDC_MspDeInit(LTDC_HandleTypeDef* hltdc)
{
  if(hltdc->Instance==LTDC)
  {
  /* USER CODE BEGIN LTDC_MspDeInit 0 */

  /* USER CODE END LTDC_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_LTDC_CLK_DISABLE();

    /* LTDC interrupt DeInit */
    HAL_NVIC_DisableIRQ(LTDC_IRQn);
  /* USER CODE BEGIN LTDC_MspDeInit 1 */

  /* USER CODE END LTDC_MspDeInit 1 */
  }

}

/**
* @brief RTC MSP Initialization
* This function configures the hardware resources used in this example
* @param hrtc: RTC handle pointer
* @retval None
*/
void HAL_RTC_MspInit(RTC_HandleTypeDef* hrtc)
{
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};
  if(hrtc->Instance==RTC)
  {
  /* USER CODE BEGIN RTC_MspInit 0 */

  /* USER CODE END RTC_MspInit 0 */

  /** Initializes the peripherals clock
  */
    PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_RTC;
    PeriphClkInit.RTCClockSelection = RCC_RTCCLKSOURCE_LSE;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
    {
      Error_Handler();
    }

    /* Peripheral clock enable */
    __HAL_RCC_RTC_ENABLE();
    __HAL_RCC_RTCAPB_CLK_ENABLE();
    __HAL_RCC_RTCAPB_CLKAM_ENABLE();
  /* USER CODE BEGIN RTC_MspInit 1 */

  /* USER CODE END RTC_MspInit 1 */
  }

}

/**
* @brief RTC MSP De-Initialization
* This function freeze the hardware resources used in this example
* @param hrtc: RTC handle pointer
* @retval None
*/
void HAL_RTC_MspDeInit(RTC_HandleTypeDef* hrtc)
{
  if(hrtc->Instance==RTC)
  {
  /* USER CODE BEGIN RTC_MspDeInit 0 */

  /* USER CODE END RTC_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_RTC_DISABLE();
    __HAL_RCC_RTCAPB_CLK_DISABLE();
    __HAL_RCC_RTCAPB_CLKAM_DISABLE();
  /* USER CODE BEGIN RTC_MspDeInit 1 */

  /* USER CODE END RTC_MspDeInit 1 */
  }

}

/**
* @brief UART MSP Initialization
* This function configures the hardware resources used in this example
* @param huart: UART handle pointer
* @retval None
*/
void HAL_UART_MspInit(UART_HandleTypeDef* huart)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};
  if(huart->Instance==UART4)
  {
  /* USER CODE BEGIN UART4_MspInit 0 */

  /* USER CODE END UART4_MspInit 0 */

  /** Initializes the peripherals clock
  */
    PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_UART4;
    PeriphClkInit.Uart4ClockSelection = RCC_UART4CLKSOURCE_PCLK1;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
    {
      Error_Handler();
    }

    /* Peripheral clock enable */
    __HAL_RCC_UART4_CLK_ENABLE();

    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**UART4 GPIO Configuration
    PA0     ------> UART4_TX
    PA1     ------> UART4_RX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF8_UART4;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* USER CODE BEGIN UART4_MspInit 1 */

  /* USER CODE END UART4_MspInit 1 */
  }

}

/**
* @brief UART MSP De-Initialization
* This function freeze the hardware resources used in this example
* @param huart: UART handle pointer
* @retval None
*/
void HAL_UART_MspDeInit(UART_HandleTypeDef* huart)
{
  if(huart->Instance==UART4)
  {
  /* USER CODE BEGIN UART4_MspDeInit 0 */

  /* USER CODE END UART4_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_UART4_CLK_DISABLE();

    /**UART4 GPIO Configuration
    PA0     ------> UART4_TX
    PA1     ------> UART4_RX
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_0|GPIO_PIN_1);

  /* USER CODE BEGIN UART4_MspDeInit 1 */

  /* USER CODE END UART4_MspDeInit 1 */
  }

}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
