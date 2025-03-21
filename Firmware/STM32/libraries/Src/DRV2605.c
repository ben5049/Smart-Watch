/*
 * DRV2605.c
 *
 *  Created on: Jan 19, 2024
 *      Author: bens1
 */

#include "DRV2605.h"

#ifndef min
#define min(a,b) ((a)<(b)?(a):(b))
#endif

DRV2605_StatusTypeDef DRV2605_Init(DRV2605_HandleTypeDef *dev, I2C_HandleTypeDef *i2cHandle, GPIO_TypeDef *EN_Port, uint16_t EN_Pin){

	DRV2605_StatusTypeDef status = DRV2605_OK;
	uint8_t regData;

	/* Assign I2C handle */
	dev->i2cHandle = i2cHandle;

	/* Assign EN pin */
	dev->EN_Port = EN_Port;
	dev->EN_Pin = EN_Pin;

	/* Set default values */
	dev->sequencePointer = 1;

	/* Take the device out of standby */
	status = DRV2605_Enable(dev);
	if (status != DRV2605_OK){
		return status;
	}

	/* Update the device struct */
	dev->enabled = true;

	/* Read the device ID */
	status = DRV2605_ReadRegister(dev, DRV2605_REG_STATUS, &regData);
	if (status != DRV2605_OK){
		return status;
	}

	/* Check device ID for wrong model */
	if (((regData & DRV2605_BITS_DEVICE_ID) == (DRV2604_ID << 5)) || ((regData & DRV2605_BITS_DEVICE_ID) == (DRV2604L_ID << 5))){
		status = DRV2605_ERROR_UNSUPPORTED_MODEL;
		return status;
	}

	/* Check device ID is valid */
	else if (((regData & DRV2605_BITS_DEVICE_ID) == (DRV2605_ID << 5)) != ((regData & DRV2605_BITS_DEVICE_ID) == (DRV2605L_ID << 5))){
		status = DRV2605_ERROR_WRONG_ID;
		return status;
	}

	/* Reset the device */
	status = DRV2605_Reset(dev);
	if (status != DRV2605_OK){
		return status;
	}

	/* Update the device struct */
	dev->standby = true;

	/* Set the device mode */
	status = DRV2605_SetMode(dev, DRV2605_DEFAULT_MODE);
	if (status != DRV2605_OK){
		return status;
	}

	/* Set the device library */
	status = DRV2605_SetLibrary(dev, DRV2605_DEFAULT_LIBRARY);
	if (status != DRV2605_OK){
		return status;
	}

	return status;
}

DRV2605_StatusTypeDef DRV2605_Enable(DRV2605_HandleTypeDef *dev){

	HAL_GPIO_WritePin(dev->EN_Port, dev->EN_Pin, SET);

	return DRV2605_OK;
}

DRV2605_StatusTypeDef DRV2605_Disable(DRV2605_HandleTypeDef *dev){

	HAL_GPIO_WritePin(dev->EN_Port, dev->EN_Pin, RESET);

	return DRV2605_OK;
}

DRV2605_StatusTypeDef DRV2605_Reset(DRV2605_HandleTypeDef *dev){

	DRV2605_StatusTypeDef status = DRV2605_OK;
	uint8_t regData = DRV2605_BIT_RESET;

	/* Write the "DRV2605_REG_MODE" register */
	status = DRV2605_WriteRegister(dev, DRV2605_REG_MODE, &regData);

	return status;
}

DRV2605_StatusTypeDef DRV2605_EnterStandby(DRV2605_HandleTypeDef *dev){

	DRV2605_StatusTypeDef status = DRV2605_OK;
	uint8_t regData;

	/* Read the "DRV2605_REG_MODE" register */
	status = DRV2605_ReadRegister(dev, DRV2605_REG_MODE, &regData);
	if (status != DRV2605_OK){
		return status;
	}

	/* Set the "STANDBY" bit high */
	regData |= DRV2605_BIT_STANDBY;

	/* Write the "DRV2605_REG_MODE" register */
	status = DRV2605_WriteRegister(dev, DRV2605_REG_MODE, &regData);
	if (status != DRV2605_OK){
		return status;
	}

	/* Update the device struct */
	dev->standby = true;
	return status;
}

DRV2605_StatusTypeDef DRV2605_ExitStandby(DRV2605_HandleTypeDef *dev){

	DRV2605_StatusTypeDef status = DRV2605_OK;
	uint8_t regData;

	/* Read the "DRV2605_REG_MODE" register */
	status = DRV2605_ReadRegister(dev, DRV2605_REG_MODE, &regData);
	if (status != DRV2605_OK){
		return status;
	}

	/* Set the "STANDBY" bit low */
	regData &= ~DRV2605_BIT_STANDBY;

	/* Write the "DRV2605_REG_MODE" register */
	status = DRV2605_WriteRegister(dev, DRV2605_REG_MODE, &regData);
	if (status != DRV2605_OK){
		return status;
	}

	/* Update the device struct */
	dev->standby = false;
	return status;
}

DRV2605_StatusTypeDef DRV2605_SetMode(DRV2605_HandleTypeDef *dev, DRV2605_Mode mode){

	DRV2605_StatusTypeDef status = DRV2605_OK;
	uint8_t regData;

	/* Read the "DRV2605_REG_MODE" register */
	status = DRV2605_ReadRegister(dev, DRV2605_REG_MODE, &regData);
	if (status != DRV2605_OK){
		return status;
	}

	/* Set the "MODE" bits */
	regData = (regData & ~DRV2605_BITS_MODE) | mode;

	/* Write the "DRV2605_REG_MODE" register */
	status = DRV2605_WriteRegister(dev, DRV2605_REG_MODE, &regData);
	if (status != DRV2605_OK){
		return status;
	}

	/* Update the device struct */
	dev->mode = mode;
	return status;
}

DRV2605_StatusTypeDef DRV2605_SetLibrary(DRV2605_HandleTypeDef *dev, DRV2605_Library library){

	DRV2605_StatusTypeDef status = DRV2605_OK;
	uint8_t regData;

	/* Read the "DRV2605_REG_LIBRARY_SELECT" register */
	status = DRV2605_ReadRegister(dev, DRV2605_REG_LIBRARY_SELECT, &regData);
	if (status != DRV2605_OK){
		return status;
	}

	/* Set the "LIBRARY_SEL" bits */
	regData = (regData & ~DRV2605_BITS_LIBRARY_SEL) | library;

	/* Write the "DRV2605_REG_LIBRARY_SELECT" register */
	status = DRV2605_WriteRegister(dev, DRV2605_REG_LIBRARY_SELECT, &regData);
	if (status != DRV2605_OK){
		return status;
	}

	/* Update the device struct */
	dev->library = library;
	return status;
}


DRV2605_StatusTypeDef DRV2605_SequenceClear(DRV2605_HandleTypeDef *dev){

	DRV2605_StatusTypeDef status = DRV2605_OK;

	/* Update the device struct */
	dev->sequencePointer = 1;
	dev->sequence[0] = 0;

	/* Write the empty sequence to the device */
	status = DRV2605_SequenceWrite(dev);

	return status;
}

DRV2605_StatusTypeDef DRV2605_SequenceAddDelay(DRV2605_HandleTypeDef *dev, uint8_t delay){

	DRV2605_StatusTypeDef status = DRV2605_OK;

	/* Check the sequence isn't too long */
	if (dev->sequencePointer >= DRV2605_MAX_SEQUENCE_LENGTH){
		status = DRV2605_ERROR_SEQUENCE_TOO_LONG;
		return status;
	}

	/* Update the device struct */
	dev->sequence[dev->sequencePointer] = delay | 0x80;
	dev->sequencePointer++;

	/* Add the stop sequence command to the end of the sequence */
	if (dev->sequencePointer < DRV2605_MAX_SEQUENCE_LENGTH){
		dev->sequence[dev->sequencePointer] = 0;
	}

	return status;
}

DRV2605_StatusTypeDef DRV2605_SequenceAddWaveform(DRV2605_HandleTypeDef *dev, uint8_t effect){

	DRV2605_StatusTypeDef status = DRV2605_OK;

	/* Check the sequence isn't too long */
	if (dev->sequencePointer >= DRV2605_MAX_SEQUENCE_LENGTH){
		status = DRV2605_ERROR_SEQUENCE_TOO_LONG;
		return status;
	}

	/* Update the device struct */
	dev->sequence[dev->sequencePointer] = effect & 0x7F;
	dev->sequencePointer++;

	/* Add the stop sequence command to the end of the sequence */
	if (dev->sequencePointer < DRV2605_MAX_SEQUENCE_LENGTH){
		dev->sequence[dev->sequencePointer] = 0;
	}

	return status;
}

DRV2605_StatusTypeDef DRV2605_SequenceWrite(DRV2605_HandleTypeDef *dev){

	DRV2605_StatusTypeDef status = DRV2605_OK;

	/* Write sequence to device */
	for (uint8_t i = 0; i < min((dev->sequencePointer + 1), DRV2605_MAX_SEQUENCE_LENGTH); i++){
		status = DRV2605_WriteRegister(dev, DRV2605_REG_WAVEFORM_SEQUENCER_FIRST + i, &dev->sequence[i]);
		if (status != DRV2605_OK){
			return status;
		}
	}

	/* Update the device struct */
	dev->sequencePointer = 0;

	return status;
}

DRV2605_StatusTypeDef DRV2605_Trig(DRV2605_HandleTypeDef *dev){

	DRV2605_StatusTypeDef status = DRV2605_OK;

	/* TODO: Implement function */

	return status;
}

DRV2605_StatusTypeDef DRV2605_RunDiagnostic(DRV2605_HandleTypeDef *dev){

	DRV2605_StatusTypeDef status = DRV2605_OK;

	/* TODO: Implement function */

	return status;
}

DRV2605_StatusTypeDef DRV2605_AutoCalibrate(DRV2605_HandleTypeDef *dev){

	DRV2605_StatusTypeDef status = DRV2605_OK;

	/* TODO: Implement function */

	return status;
}

DRV2605_StatusTypeDef DRV2605_ReadRegister(DRV2605_HandleTypeDef *dev, uint8_t reg, uint8_t *data){

	return HAL_I2C_Mem_Read(dev->i2cHandle, DRV2605_I2C_ADDR, reg, I2C_MEMADD_SIZE_8BIT, data, 1, HAL_MAX_DELAY);
}

DRV2605_StatusTypeDef DRV2605_WriteRegister(DRV2605_HandleTypeDef *dev, uint8_t reg, uint8_t *data){

	return HAL_I2C_Mem_Write(dev->i2cHandle, DRV2605_I2C_ADDR, reg, I2C_MEMADD_SIZE_8BIT, data, 1, HAL_MAX_DELAY);
}
