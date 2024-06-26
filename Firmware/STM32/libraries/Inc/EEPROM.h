/*
 * EEPROM.h
 *
 *  Created on: Jan 20, 2024
 *      Author: bens1
 */

#ifndef INC_EEPROM_H_
#define INC_EEPROM_H_

#include "stm32u5xx_hal.h" /* Needed for I2C */
#include "EEPROM_Addresses.h" /* Used by files that use this library */

/* Define which EEPROM to use */
#define M24256X


/* EEPROM Status typedef */
typedef enum {
	EEPROM_OK 		= 0x00,
	EEPROM_ERROR   	= 0x01,
	EEPROM_BUSY    	= 0x02,
	EEPROM_TIMEOUT	= 0x03,
} EEPROM_StatusTypeDef;

/* EEPROM Device Struct */
typedef struct {

	/* I2C Handle*/
	I2C_HandleTypeDef *i2cHandle;

} EEPROM_HandleTypeDef;



/* Initialisation */
EEPROM_StatusTypeDef EEPROM_Init(EEPROM_HandleTypeDef *dev, I2C_HandleTypeDef *i2cHandle);

/* User Functions */
EEPROM_StatusTypeDef EEPROM_ReadMemoryByte(EEPROM_HandleTypeDef *dev, uint16_t address, uint8_t *data);
EEPROM_StatusTypeDef EEPROM_WriteMemoryByte(EEPROM_HandleTypeDef *dev, uint16_t address, uint8_t *data);

/* Internal/debug Functions */
EEPROM_StatusTypeDef EEPROM_SetChipEnableAddress(EEPROM_HandleTypeDef *dev, uint8_t address); /* Address between 0x00 and 0x07 */
EEPROM_StatusTypeDef EEPROM_LockChipEnableAddress(EEPROM_HandleTypeDef *dev); /* THIS IS PERMANENT */


#endif /* INC_EEPROM_H_ */
