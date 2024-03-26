/*
 * rfid.c
 *
 *  Created on: Mar 5, 2024
 *      Author: bens1
 */

#include "rfid.h"
#include "stm32g0xx_hal.h"
#include "main.h"

void RFID_Init(RFID_Handle_t *rfid){
	rfid->mode = RFID_MODE_OFF;
	rfid->state = RFID_STATE_IDLE;
	rfid->timeout = UINT32_MAX;
	rfid->power = RFID_POWER_NORMAL;

	HAL_GPIO_WritePin(BOOST_EN_GPIO_Port, BOOST_EN_Pin, RESET);
	HAL_GPIO_WritePin(OPAMP_SHDN_GPIO_Port, OPAMP_SHDN_Pin, RESET);
	HAL_GPIO_WritePin(PULL_GPIO_Port, PULL_Pin, RESET);
}

void RFID_ChangeMode(RFID_Handle_t *rfid, RFID_Mode mode){
	rfid->mode = mode;
}

void RFID_Transmit(RFID_Handle_t *rfid, uint8_t *data, uint8_t length){

}

void RFID_Receive(RFID_Handle_t *rfid, uint8_t *data, uint8_t length){

}
