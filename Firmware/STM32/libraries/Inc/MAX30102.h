/*
 * MAX30102.h
 *
 *  Created on: Jan 22, 2024
 *      Author: bens1
 */

#ifndef SRC_MAX30102_H_
#define SRC_MAX30102_H_

/* Includes*/
#include "stm32u5xx_hal.h" /* Needed for I2C */
#include "stdbool.h"

/* Defines*/
#define MAX30102_I2C_ADDR 	(0x57 << 1) /* p. 5 */
#define MAX30102_PART_ID		0x15

/* Registers */
#define MAX30102_REG_INT1					0x00
#define MAX30102_REG_INT2					0x01
#define MAX30102_REG_INT3					0x02
#define MAX30102_REG_INT4					0x03
#define MAX30102_REG_FIFO_WRITE_PTR			0x04
#define MAX30102_REG_FIFO_OVERFLOW_COUNTER	0x05
#define MAX30102_REG_FIFO_READ_PTR			0x06
#define MAX30102_REG_FIFO_DATA				0x07
#define MAX30102_REG_FIFO_CONFIG			0x08
#define MAX30102_REG_MODE_CONFIG			0x09
#define MAX30102_REG_SPO2_CONFIG			0x0A
#define MAX30102_REG_LED1_PULSE_AMPLITUDE	0x0C
#define MAX30102_REG_LED2_PULSE_AMPLITUDE	0x0D
#define MAX30102_REG_MULTI_LED_CONTROL1		0x11
#define MAX30102_REG_MULTI_LED_CONTROL2		0x12
#define MAX30102_REG_DIE_TEMP_INTEGER		0x1F
#define MAX30102_REG_DIE_TEMP_FRACTION		0x20
#define MAX30102_REG_DIE_TEMP_CONFIG		0x21
#define MAX30102_REG_REVISION_ID			0xFE
#define MAX30102_REG_PART_ID				0xFF

/* MAX30102 Status typedef */
typedef enum {
	MAX30102_OK 			= 0x00,
	MAX30102_ERROR    		= 0x01,
	MAX30102_BUSY    		= 0x02,
	MAX30102_TIMEOUT 		= 0x03,
	MAX30102_ERROR_WRONG_ID = 0x04,
	MAX30102_ERROR_NO_VBUS 	= 0x05,
} MAX30102_StatusTypeDef;

/* MAX30102 Device Struct */
typedef struct {

	/* I2C Handle*/
	I2C_HandleTypeDef *i2cHandle;

} MAX30102_HandleTypeDef;


/* Initialisation */
MAX30102_StatusTypeDef MAX30102_Init(MAX30102_HandleTypeDef *dev, I2C_HandleTypeDef *i2cHandle);

/* Low-Level Functions */
MAX30102_StatusTypeDef MAX30102_ReadRegister(MAX30102_HandleTypeDef *dev, uint8_t reg, uint8_t *data);
MAX30102_StatusTypeDef MAX30102_WriteRegister(MAX30102_HandleTypeDef *dev, uint8_t reg, uint8_t *data);

#endif /* SRC_MAX30102_H_ */
