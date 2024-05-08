/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : TouchGFXHAL.cpp
  ******************************************************************************
  * This file was created by TouchGFX Generator 4.23.2. This file is only
  * generated once! Delete this file from your project and re-generate code
  * using STM32CubeMX or change this file manually to update it.
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

#include <TouchGFXHAL.hpp>

/* USER CODE BEGIN TouchGFXHAL.cpp */

#include <main.h>

#include <stm32u5xx.h>
#include <stm32u5xx_hal_dsi.h>

#include <touchgfx/hal/OSWrappers.hpp>
#include <touchgfx/hal/GPIO.hpp>

using namespace touchgfx;

void TouchGFXHAL::initialize()
{
    // Calling parent implementation of initialize().
    //
    // To overwrite the generated implementation, omit call to parent function
    // and implemented needed functionality here.
    // Please note, HAL::initialize() must be called to initialize the framework.

    TouchGFXGeneratedHAL::initialize();
}

/**
 * Gets the frame buffer address used by the TFT controller.
 *
 * @return The address of the frame buffer currently being displayed on the TFT.
 */
uint16_t* TouchGFXHAL::getTFTFrameBuffer() const
{
    // Calling parent implementation of getTFTFrameBuffer().
    //
    // To overwrite the generated implementation, omit call to parent function
    // and implemented needed functionality here.

    return TouchGFXGeneratedHAL::getTFTFrameBuffer();
}

/**
 * Sets the frame buffer address used by the TFT controller.
 *
 * @param [in] address New frame buffer address.
 */
void TouchGFXHAL::setTFTFrameBuffer(uint16_t* address)
{
    // Calling parent implementation of setTFTFrameBuffer(uint16_t* address).
    //
    // To overwrite the generated implementation, omit call to parent function
    // and implemented needed functionality here.

    TouchGFXGeneratedHAL::setTFTFrameBuffer(address);
}

/**
 * This function is called whenever the framework has performed a partial draw.
 *
 * @param rect The area of the screen that has been drawn, expressed in absolute coordinates.
 *
 * @see flushFrameBuffer().
 */
void TouchGFXHAL::flushFrameBuffer(const touchgfx::Rect& rect)
{
    // Calling parent implementation of flushFrameBuffer(const touchgfx::Rect& rect).
    //
    // To overwrite the generated implementation, omit call to parent function
    // and implemented needed functionality here.
    // Please note, HAL::flushFrameBuffer(const touchgfx::Rect& rect) must
    // be called to notify the touchgfx framework that flush has been performed.
    // To calculate he start adress of rect,
    // use advanceFrameBufferToRect(uint8_t* fbPtr, const touchgfx::Rect& rect)
    // defined in TouchGFXGeneratedHAL.cpp

    TouchGFXGeneratedHAL::flushFrameBuffer(rect);
}

bool TouchGFXHAL::blockCopy(void* RESTRICT dest, const void* RESTRICT src, uint32_t numBytes)
{
    return TouchGFXGeneratedHAL::blockCopy(dest, src, numBytes);
}

/**
 * Configures the interrupts relevant for TouchGFX. This primarily entails setting
 * the interrupt priorities for the DMA and LCD interrupts.
 */
void TouchGFXHAL::configureInterrupts()
{
    // Calling parent implementation of configureInterrupts().
    //
    // To overwrite the generated implementation, omit call to parent function
    // and implemented needed functionality here.

    TouchGFXGeneratedHAL::configureInterrupts();
}

/**
 * Used for enabling interrupts set in configureInterrupts()
 */
void TouchGFXHAL::enableInterrupts()
{
    // Calling parent implementation of enableInterrupts().
    //
    // To overwrite the generated implementation, omit call to parent function
    // and implemented needed functionality here.

	NVIC_EnableIRQ(DSI_IRQn);

    TouchGFXGeneratedHAL::enableInterrupts();
}

/**
 * Used for disabling interrupts set in configureInterrupts()
 */
void TouchGFXHAL::disableInterrupts()
{
    // Calling parent implementation of disableInterrupts().
    //
    // To overwrite the generated implementation, omit call to parent function
    // and implemented needed functionality here.

	NVIC_DisableIRQ(DSI_IRQn);

    TouchGFXGeneratedHAL::disableInterrupts();
}

/**
 * Configure the LCD controller to fire interrupts at VSYNC. Called automatically
 * once TouchGFX initialization has completed.
 */
void TouchGFXHAL::enableLCDControllerInterrupt()
{
    // Calling parent implementation of enableLCDControllerInterrupt().
    //
    // To overwrite the generated implementation, omit call to parent function
    // and implemented needed functionality here.

    TouchGFXGeneratedHAL::enableLCDControllerInterrupt();
}

bool TouchGFXHAL::beginFrame()
{
    return TouchGFXGeneratedHAL::beginFrame();
}

void TouchGFXHAL::endFrame()
{
	static bool display_on = false;

    if (!display_on)
    {
        display_on = true;
        /* Enable the LCD, Send Display on DCS command to display */

//    	HAL_DSI_ShortWrite(&hdsi, 0, DSI_DCS_SHORT_PKT_WRITE_P0, 0x29, 0x00);
//        HAL_DSI_ShortWrite(&hdsi, 0, DSI_DCS_SHORT_PKT_WRITE_P1, DSI_SET_DISPLAY_ON, 0x00);
    }

    TouchGFXGeneratedHAL::endFrame();
}


void HAL_DSI_TearingEffectCallback(DSI_HandleTypeDef* hdsi)
 {
   GPIO::set(GPIO::VSYNC_FREQ);
   HAL::getInstance()->vSync();
   OSWrappers::signalVSync();

//   if (HAL::getInstance())
//   {
//     // Swap frame buffers immediately instead of waiting for the task to be scheduled in.
//     // Note: task will also swap when it wakes up, but that operation is guarded and will not have
//     // any effect if already swapped.
//     HAL::getInstance()->swapFrameBuffers();
//   }

   // Transfer frame buffer data
   HAL_DSI_Refresh(hdsi);
 }//

 void HAL_DSI_EndOfRefreshCallback(DSI_HandleTypeDef* hdsi)
 {
   //Point LTDC base address to the new frame buffer:
//   __HAL_DSI_WRAPPER_DISABLE(hdsi);
//   LTDC_LAYER(&hltdc, 0)->CFBAR = ((uint32_t)currFbBase);
//   __HAL_LTDC_RELOAD_IMMEDIATE_CONFIG(&hltdc);
//   __HAL_DSI_WRAPPER_ENABLE(hdsi);

   GPIO::clear(GPIO::VSYNC_FREQ);
 }


/* USER CODE END TouchGFXHAL.cpp */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
