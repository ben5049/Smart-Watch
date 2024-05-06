/*
 * PCA9570.c
 *
 *  Created on: Apr 29, 2024
 *      Author: bens1
 */

#include "PCA9570.h"

PCA9570_StatusTypeDef PCA9570_Init(PCA9570_HandleTypeDef *dev, I2C_HandleTypeDef *i2cHandle){

	PCA9570_StatusTypeDef status = PCA9570_OK;
	uint32_t regData32;

	/* Assign I2C handle */
	dev->i2cHandle = i2cHandle;
	dev->pinStates = 0x00;

	/* Reset the device */
	status = PCA9570_Reset(dev);
	if (status != PCA9570_OK){
		return status;
	}

	/* Check the ID of the chip */
	status = PCA9570_GetID(dev, &regData32);
	// TODO: CHECK ID
	if (status != PCA9570_OK){
		return status;
	}

	/* Set the pins to a known state */
	status = PCA9570_WritePins(dev, PCA9570_PIN_1 | PCA9570_PIN_2 | PCA9570_PIN_3 | PCA9570_PIN_4, GPIO_PIN_RESET);
	if (status != PCA9570_OK){
		return status;
	}

	return status;
}


PCA9570_StatusTypeDef PCA9570_Reset(PCA9570_HandleTypeDef *dev){
	return PCA9570_OK;
}

PCA9570_StatusTypeDef PCA9570_GetID(PCA9570_HandleTypeDef *dev, uint32_t *data){
	return PCA9570_OK;
}

PCA9570_StatusTypeDef PCA9570_WritePins(PCA9570_HandleTypeDef *dev, uint8_t pins, GPIO_PinState state){

	PCA9570_StatusTypeDef status = PCA9570_OK;

	/* Prepare the updated register value */
	if (state == GPIO_PIN_SET){
		dev->pinStates |= pins;
	}
	else {
		dev->pinStates &= (~pins);
	}

	status = HAL_I2C_Master_Transmit(dev->i2cHandle, PCA9570_I2C_DEV_ADDR, &dev->pinStates, 1, HAL_MAX_DELAY);

	return status;
}
