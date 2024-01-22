/*
 * EEPROM.c
 *
 *  Created on: Jan 20, 2024
 *      Author: bens1
 */

#include "EEPROM.h"

#ifdef M24256X
#include "M24256X.h"
#endif

EEPROM_StatusTypeDef EEPROM_Init(EEPROM_HandleTypeDef *dev, I2C_HandleTypeDef *i2cHandle){

	EEPROM_StatusTypeDef status = EEPROM_OK;

	/* Assign I2C handle */
	dev->i2cHandle = i2cHandle;

	return status;
}

EEPROM_StatusTypeDef EEPROM_ReadMemoryByte(EEPROM_HandleTypeDef *dev, uint16_t address, uint8_t *data){

	EEPROM_StatusTypeDef status = EEPROM_OK;

#ifdef M24256X

	uint8_t attempts_remaining = M24256X_MAX_ATTEMPTS;

	while (attempts_remaining > 0){
		status = HAL_I2C_Mem_Read(dev->i2cHandle, M24256X_MEM_DEV_ADDR, (address & 0x7FFF), I2C_MEMADD_SIZE_16BIT, data, 1, HAL_MAX_DELAY);

		if (status == EEPROM_OK){
			attempts_remaining = 0;
		}
		else{
			attempts_remaining--;
		}
	}

#endif

	return status;
}

EEPROM_StatusTypeDef EEPROM_WriteMemoryByte(EEPROM_HandleTypeDef *dev, uint16_t address, uint8_t *data){

	EEPROM_StatusTypeDef status = EEPROM_OK;

#ifdef M24256X

	uint8_t attempts_remaining = M24256X_MAX_ATTEMPTS;

	while (attempts_remaining > 0){
		status = HAL_I2C_Mem_Write(dev->i2cHandle, M24256X_MEM_DEV_ADDR, (address & 0x7FFF), I2C_MEMADD_SIZE_16BIT, data, 1, HAL_MAX_DELAY);

		if (status == EEPROM_OK){
			attempts_remaining = 0;
		}
		else{
			attempts_remaining--;
		}
	}

#endif

	return status;
}
