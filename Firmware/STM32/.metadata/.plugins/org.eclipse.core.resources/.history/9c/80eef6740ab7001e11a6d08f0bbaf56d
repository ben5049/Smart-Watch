/*
 * M24256X.c
 *
 *  Created on: Jan 18, 2024
 *      Author: bens1
 */

#include "M24256X.h"

M24256X_StatusTypeDef M24256X_Init(M24256X_HandleTypeDef *dev, I2C_HandleTypeDef *i2cHandle){

	M24256X_StatusTypeDef status = M24256X_OK;

	dev->i2cHandle = i2cHandle;

	return status;
}

M24256X_StatusTypeDef M24256X_ReadMemoryByte(M24256X_HandleTypeDef *dev, uint8_t *data, uint16_t address){

	M24256X_StatusTypeDef status = M24256X_OK;
	uint8_t attempts_remaining = M24256X_MAX_ATTEMPTS;

	while (attempts_remaining > 0){
		status = HAL_I2C_Mem_Read(dev->i2cHandle, M24256X_MEM_DEV_ADDR, (address & 0x7FFF), I2C_MEMADD_SIZE_16BIT, data, 1, HAL_MAX_DELAY);

		if (status == M24256X_OK){
			attempts_remaining = 0;
		}
		else{
			attempts_remaining--;
		}
	}

	return status;
}

M24256X_StatusTypeDef M24256X_WriteMemoryByte(M24256X_HandleTypeDef *dev, uint8_t *data, uint16_t address){

	M24256X_StatusTypeDef status = M24256X_OK;
	uint8_t attempts_remaining = M24256X_MAX_ATTEMPTS;

	while (attempts_remaining > 0){
		status = HAL_I2C_Mem_Write(dev->i2cHandle, M24256X_MEM_DEV_ADDR, (address & 0x7FFF), I2C_MEMADD_SIZE_16BIT, data, 1, HAL_MAX_DELAY);

		if (status == M24256X_OK){
			attempts_remaining = 0;
		}
		else{
			attempts_remaining--;
		}
	}

	return status;
}

//
//M24256X_StatusTypeDef ADP5360_ReadRegister(M24256X_HandleTypeDef *dev, uint8_t reg, uint8_t *data){
//
//	return HAL_I2C_Mem_Read(dev->i2cHandle, ADP5360_I2C_ADDR, reg, I2C_MEMADD_SIZE_8BIT, data, 1, HAL_MAX_DELAY);
//}
//
//M24256X_StatusTypeDef ADP5360_WriteRegister(M24256X_HandleTypeDef *dev, uint8_t reg, uint8_t *data){
//
//	return HAL_I2C_Mem_Write(dev->i2cHandle, ADP5360_I2C_ADDR, reg, I2C_MEMADD_SIZE_8BIT, data, 1, HAL_MAX_DELAY);
//}
