/*
 * rfid.h
 *
 *  Created on: Mar 5, 2024
 *      Author: bens1
 */

#ifndef INC_RFID_H_
#define INC_RFID_H_

#include "stdint.h"

typedef enum {
	RFID_MODE_OFF,
	RFID_MODE_TX,
	RFID_MODE_RX
} RFID_Mode;

typedef enum {
	RFID_STATE_OFF,
	RFID_STATE_IDLE,
	RFID_STATE_BUSY
} RFID_State;

typedef enum {
	RFID_POWER_LOW,
	RFID_POWER_NORMAL,
	RFID_POWER_HIGH
} RFID_Power;

typedef struct {
	RFID_Mode mode;
	RFID_State state;
	uint32_t timeout;
	RFID_Power power;
} RFID_Handle_t;

void RFID_Init(RFID_Handle_t *rfid);
void RFID_ChangeMode(RFID_Handle_t *rfid, RFID_Mode mode);
void RFID_Transmit(RFID_Handle_t *rfid, uint8_t *data, uint8_t length);
void RFID_Receive(RFID_Handle_t *rfid, uint8_t *data, uint8_t length);

#endif /* INC_RFID_H_ */
