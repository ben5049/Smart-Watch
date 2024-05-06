/*
 * PCA9570.h
 *
 *  Created on: Apr 29, 2024
 *      Author: bens1
 */

#ifndef INC_PCA9570_H_
#define INC_PCA9570_H_

/* Includes*/
#include "stm32u5xx_hal.h" /* Needed for I2C */

#define PCA9570_I2C_DEV_ADDR (0x24 << 1) /* p. 5 */
#define PCA9570_I2C_ID_ADDR	 (0x7C << 1) /* p. 5 */

#define PCA9570_PIN_1 0x01
#define PCA9570_PIN_2 0x02
#define PCA9570_PIN_3 0x04
#define PCA9570_PIN_4 0x08

/* PCA9570 Status typedef */
typedef enum {
	PCA9570_OK 				= 0x00,
	PCA9570_ERROR    		= 0x01,
	PCA9570_BUSY    		= 0x02,
	PCA9570_TIMEOUT 		= 0x03,
	PCA9570_ERROR_WRONG_ID 	= 0x04
} PCA9570_StatusTypeDef;

/* PCA9570 Device Struct */
typedef struct {
	I2C_HandleTypeDef *i2cHandle;
	uint8_t pinStates;
} PCA9570_HandleTypeDef;


/* Initialisation */
PCA9570_StatusTypeDef PCA9570_Init(PCA9570_HandleTypeDef *dev, I2C_HandleTypeDef *i2cHandle);

/*  */
PCA9570_StatusTypeDef PCA9570_Reset(PCA9570_HandleTypeDef *dev);
PCA9570_StatusTypeDef PCA9570_GetID(PCA9570_HandleTypeDef *dev, uint32_t *data);
PCA9570_StatusTypeDef PCA9570_WritePins(PCA9570_HandleTypeDef *dev, uint8_t pins, GPIO_PinState state);

#endif /* INC_PCA9570_H_ */
