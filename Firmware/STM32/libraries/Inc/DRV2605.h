/*
 * DRV2605.h
 *
 *  Created on: Jan 19, 2024
 *      Author: bens1
 */

#ifndef SRC_DRV2605_H_
#define SRC_DRV2605_H_

/* Includes*/
#include "stm32u5xx_hal.h" /* Needed for I2C */
#include "stdbool.h"

/* Defines*/
#define DRV2605_I2C_ADDR			(0x5A << 1) /* p. */
#define DRV2605_ID					0x03 /* p. 36 */
#define DRV2604_ID					0x04 /* p. 36 */
#define DRV2604L_ID					0x06 /* p. 36 */
#define DRV2605L_ID					0x07 /* p. 36 */
#define DRV2605_MAX_SEQUENCE_LENGTH	8


#define DRV2605_DEFAULT_MODE 		DRV2605_MODE_INTERNAL_TRIG
#define DRV2605_DEFAULT_LIBRARY 	DRV2605_LIBRARY_TS2200_A

/* Bit Masks */
#define DRV2605_BITS_DEVICE_ID		0xE0
#define DRV2605_BIT_RESET			0x80
#define DRV2605_BIT_STANDBY			0x40
#define DRV2605_BITS_MODE			0x07
#define DRV2605_BITS_LIBRARY_SEL	0x07

/* Registers */
#define DRV2605_REG_STATUS									0x00
#define DRV2605_REG_MODE									0x01
#define DRV2605_REG_RT_PLAYBACK_INPUT						0x02
#define DRV2605_REG_LIBRARY_SELECT							0x03
#define DRV2605_REG_WAVEFORM_SEQUENCER_FIRST				0x04 /* Address 0x04 to 0x0B (8 registers) */
#define DRV2605_REG_WAVEFORM_SEQUENCER_LAST					0x0B /* Address 0x04 to 0x0B (8 registers) */
#define DRV2605_REG_GO										0x0C
#define DRV2605_REG_OVERDRIVE_TIME_OFFSET					0x0D
#define DRV2605_REG_SUSTAIN_TIME_OFFSET_POS					0x0E
#define DRV2605_REG_SUSTAIN_TIME_OFFSET_NEG					0x0F
#define DRV2605_REG_BRAKE_TIME_OFFSET						0x10
#define DRV2605_REG_AUDIO_TO_VIBE_CONTROL					0x11
#define DRV2605_REG_AUDIO_TO_VIBE_MIN_INPUT_LEVEL			0x12
#define DRV2605_REG_AUDIO_TO_VIBE_MAX_INPUT_LEVEL			0x13
#define DRV2605_REG_AUDIO_TO_VIBE_MIN_OUTPUT_DRIVE			0x14
#define DRV2605_REG_AUDIO_TO_VIBE_MAX_OUTPUT_DRIVE			0x15
#define DRV2605_REG_RATED_VOLTAGE							0x16
#define DRV2605_REG_OVERDRIVE_CLAMP_VOLTAGE					0x17
#define DRV2605_REG_AUTO_CALIBRATION_COMPENSATION_RESULT	0x18
#define DRV2605_REG_AUTO_CALIBRATION_BACK_EMF_RESULT		0x19
#define DRV2605_REG_FEEDBACK_CONTROL						0x1A
#define DRV2605_REG_CONTROL1								0x1B
#define DRV2605_REG_CONTROL2								0x1C
#define DRV2605_REG_CONTROL3								0x1D
#define DRV2605_REG_CONTROL4								0x1E
#define DRV2605_REG_VBAT_VOLTAGE_MONITOR					0x21
#define DRV2605_REG_LRA_RESONANCE_PERIOD					0x22


/* DRV2605 Status typedef */
typedef enum {
	DRV2605_OK 						= 0x00,
	DRV2605_ERROR    				= 0x01,
	DRV2605_BUSY    				= 0x02,
	DRV2605_TIMEOUT 				= 0x03,
	DRV2605_ERROR_WRONG_ID 			= 0x04,
	DRV2605_ERROR_UNSUPPORTED_MODEL = 0x05,
	DRV2605_ERROR_SEQUENCE_TOO_LONG = 0x05

} DRV2605_StatusTypeDef;

/* DRV2605 Mode typedef */
typedef enum {
	DRV2605_MODE_INTERNAL_TRIG 			= 0x00,
	DRV2605_MODE_EXTERNAL_TRIG_EDGE    	= 0x01,
	DRV2605_MODE_EXTERNAL_TRIG_LEVEL    = 0x02,
	DRV2605_MODE_PWM_ANALOGUE 			= 0x03,
	DRV2605_MODE_AUDIO_TO_VIBE 			= 0x04,
	DRV2605_MODE_RT_PLAYBACK 			= 0x05,
	DRV2605_MODE_DIAGNOSTICS 			= 0x06,
	DRV2605_MODE_AUTO_CALIBRATION		= 0x07

} DRV2605_Mode;

/* DRV2605 Library typedef */
typedef enum {
	DRV2605_LIBRARY_EMPTY		= 0x00,
	DRV2605_LIBRARY_TS2200_A	= 0x01,
	DRV2605_LIBRARY_TS2200_B	= 0x02,
	DRV2605_LIBRARY_TS2200_C	= 0x03,
	DRV2605_LIBRARY_TS2200_D	= 0x04,
	DRV2605_LIBRARY_TS2200_E	= 0x05,
	DRV2605_LIBRARY_LRA			= 0x06,
	DRV2605_LIBRARY_TS2200_F	= 0x07

} DRV2605_Library;

/* DRV2605 Device Struct */
typedef struct {

	/* I2C Handle*/
	I2C_HandleTypeDef *i2cHandle;

	/* GPIO Control */
	GPIO_TypeDef *EN_Port;
	uint16_t EN_Pin;

	bool enabled;
	bool standby;
	DRV2605_Mode mode;
	DRV2605_Library library;

	uint8_t sequence[8];
	uint8_t sequencePointer;

} DRV2605_HandleTypeDef;


/* Initialisation */
DRV2605_StatusTypeDef DRV2605_Init(DRV2605_HandleTypeDef *dev, I2C_HandleTypeDef *i2cHandle, GPIO_TypeDef *EN_Port, uint16_t EN_Pin);

/* User Functions */
DRV2605_StatusTypeDef DRV2605_Enable(DRV2605_HandleTypeDef *dev);
DRV2605_StatusTypeDef DRV2605_Disable(DRV2605_HandleTypeDef *dev);
DRV2605_StatusTypeDef DRV2605_Reset(DRV2605_HandleTypeDef *dev);
DRV2605_StatusTypeDef DRV2605_EnterStandby(DRV2605_HandleTypeDef *dev);
DRV2605_StatusTypeDef DRV2605_ExitStandby(DRV2605_HandleTypeDef *dev);
DRV2605_StatusTypeDef DRV2605_SetMode(DRV2605_HandleTypeDef *dev, DRV2605_Mode mode);
DRV2605_StatusTypeDef DRV2605_SetLibrary(DRV2605_HandleTypeDef *dev, DRV2605_Library library);

DRV2605_StatusTypeDef DRV2605_SequenceClear(DRV2605_HandleTypeDef *dev); /* Clear the waveform sequence */
DRV2605_StatusTypeDef DRV2605_SequenceAddDelay(DRV2605_HandleTypeDef *dev, uint8_t delay); /* Add delay in steps of 10ms (up to 1270ms) to the waveform sequence */
DRV2605_StatusTypeDef DRV2605_SequenceAddWaveform(DRV2605_HandleTypeDef *dev, uint8_t effect); /* See datasheet p. 63 for waveform library effects list */
DRV2605_StatusTypeDef DRV2605_SequenceWrite(DRV2605_HandleTypeDef *dev); /* Write the waveform sequence to the device */

DRV2605_StatusTypeDef DRV2605_Trig(DRV2605_HandleTypeDef *dev);

/* Internal/debug Functions */
DRV2605_StatusTypeDef DRV2605_RunDiagnostic(DRV2605_HandleTypeDef *dev);
DRV2605_StatusTypeDef DRV2605_AutoCalibrate(DRV2605_HandleTypeDef *dev);

/* Low-Level Functions */
DRV2605_StatusTypeDef DRV2605_ReadRegister(DRV2605_HandleTypeDef *dev, uint8_t reg, uint8_t *data);
DRV2605_StatusTypeDef DRV2605_WriteRegister(DRV2605_HandleTypeDef *dev, uint8_t reg, uint8_t *data);

/* TODO: Auto calibrate/load previous results
 * TODO: Change control mode (control registers) */






#endif /* SRC_DRV2605_H_ */
