/*
 * ADP5360.h
 *
 *  Created on: Jan 11, 2024
 *      Author: bens1
 */

#ifndef INC_ADP5360_H_
#define INC_ADP5360_H_


/* Includes*/
#include "stm32u5xx_hal.h" /* Needed for I2C */

typedef enum{
	false = 0x00,
	true = 0x01
} bool;

/* Defines*/
#define ADP5360_I2C_ADDR (0x46 << 1) /* p. 58*/
#define ADP5360_MANUFACTURER_ID		0x1
#define ADP5360_MODEL_ID			0x0
#define ADP5360_SILICON_REVISION	0x8
#define ADP5360_BATTERY_DEGRADATION_PER_OVERFLOW 0.015 /* 0.015 = 1.5% Battery capacity lost every 41 full charges */

/* Default values */
#define ADP5360_DEFAULT_BUCK_VOLTAGE			1800 	/* Voltage in mV */
#define ADP5360_DEFAULT_BUCK_BOOST_VOLTAGE  	3300 	/* Voltage in mV */
#define ADP5360_DEFAULT_BATTERY_CAPACITY	  	300 	/* Capacity in mAh */

/* Bit Masks */
#define ADP5360_BIT_EN_CHG 			0x01
#define ADP5360_BIT_EN_LDO 			0x08
#define ADP5360_BIT_VBUS_OV 		0x80
#define ADP5360_BIT_VBUSOK	 		0x08
#define ADP5360_BITS_CHARGER_STATUS 0x07
#define ADP5360_BITS_BAT_CHG_STATUS 0x07
#define ADP5360_BITS_BAT_SOC		0x7F
#define ADP5360_BIT_EN_BUCKBST		0x01
#define ADP5360_BIT_EN_MR_SD		0x02

/* Interrupts (0xFF = on, 0x00 = off) */
#define ADP5360_VBUS_INT		(0x01 & 0xFF)
#define ADP5360_CHG_INT			(0x02 & 0xFF)
#define ADP5360_BAT_INT			(0x04 & 0xFF)
#define ADP5360_THR_INT			(0x08 & 0x00)
#define ADP5360_BATPRO_INT		(0x10 & 0x00)
#define ADP5360_ADPICHG_INT		(0x20 & 0x00)
#define ADP5360_SOCACM_INT		(0x40 & 0xFF)
#define ADP5360_SOCLOW_INT		(0x80 & 0xFF)
#define ADP5360_BUCKBSTPG_INT 	(0x10 & 0x00)
#define ADP5360_BUCKPG_INT		(0x20 & 0x00)
#define ADP5360_WD_INT			(0x40 & 0x00)
#define ADP5360_MR_INT			(0x80 & 0x00)

/* Registers */
#define ADP5360_REG_MANUFACTURER_AND_MODEL_ID						0x00
#define ADP5360_REG_SILICON_REVISION								0x01
#define ADP5360_REG_CHARGER_VBUS_ILIM								0x02
#define ADP5360_REG_CHARGER_TERMINATION_SETTING						0x03
#define ADP5360_REG_CHARGER_CURRENT_SETTING							0x04
#define ADP5360_REG_CHARGER_VOLTAGE_THRESHOLD						0x05
#define ADP5360_REG_CHARGER_TIMER_SETTING							0x06
#define ADP5360_REG_CHARGER_FUNCTION_SETTING						0x07
#define ADP5360_REG_CHARGER_STATUS1									0x08
#define ADP5360_REG_CHARGER_STATUS2									0x09
#define ADP5360_REG_BATTERY_THERMISTOR_CONTROL 						0x0A
#define ADP5360_REG_THERMISTOR_60C_THRESHOLD 						0x0B
#define ADP5360_REG_THERMISTOR_45C_THRESHOLD 						0x0C
#define ADP5360_REG_THERMISTOR_10C_THRESHOLD 						0x0D
#define ADP5360_REG_THERMISTOR_0C_THRESHOLD 						0x0E
#define ADP5360_REG_THR_VOLTAGE_L			 						0x0F
#define ADP5360_REG_THR_VOLTAGE_H			 						0x10
#define ADP5360_REG_BATTERY_PROTECTION_CONTROL 						0x11
#define ADP5360_REG_BATTERY_PROTECTION_UNDERVOLTAGE_SETTING 		0x12
#define ADP5360_REG_BATTERY_PROTECTION_OVERCHARGE_SETTING 			0x13
#define ADP5360_REG_BATTERY_PROTECTION_OVERVOLTAGE_SETTING 			0x14
#define ADP5360_REG_BATTERY_PROTECTION_CHARGE_OVERCHARGE_SETTING 	0x15
#define ADP5360_REG_V_SOC_0			 								0x16
#define ADP5360_REG_V_SOC_5		 									0x17
#define ADP5360_REG_V_SOC_11		 								0x18
#define ADP5360_REG_V_SOC_19		 								0x19
#define ADP5360_REG_V_SOC_28		 								0x1A
#define ADP5360_REG_V_SOC_41		 								0x1B
#define ADP5360_REG_V_SOC_55		 								0x1C
#define ADP5360_REG_V_SOC_69		 								0x1D
#define ADP5360_REG_V_SOC_84		 								0x1E
#define ADP5360_REG_V_SOC_100		 								0x1F
#define ADP5360_REG_BAT_CAP 										0x20
#define ADP5360_REG_BAT_SOC 										0x21
#define ADP5360_REG_BAT_SOCACM_CTL		 							0x22
#define ADP5360_REG_BAT_SOCACM_H		 							0x23
#define ADP5360_REG_BAT_SOCACM_L		 							0x24
#define ADP5360_REG_VBAT_READ_H		 								0x25
#define ADP5360_REG_VBAT_READ_L		 								0x26
#define ADP5360_REG_FUEL_GAUGE_MODE		 							0x27
#define ADP5360_REG_SOC_RESET		 								0x28
#define ADP5360_REG_BUCK_CONFIG		 								0x29
#define ADP5360_REG_BUCK_VOUT		 								0x2A
#define ADP5360_REG_BUCK_BOOST_CONFIG		 						0x2B
#define ADP5360_REG_BUCK_BOOST_VOUT		 							0x2C
#define ADP5360_REG_SUPERVISORY_SETTING		 						0x2D
#define ADP5360_REG_FAULT		 									0x2E
#define ADP5360_REG_PGOOD_STATUS		 							0x2F
#define ADP5360_REG_PGOOD1_MASK		 								0x30
#define ADP5360_REG_PGOOD2_MASK		 								0x31
#define ADP5360_REG_INTERRUPT_ENABLE1		 						0x32
#define ADP5360_REG_INTERRUPT_ENABLE2		 						0x33
#define ADP5360_REG_INTERRUPT_FLAG1		 							0x34
#define ADP5360_REG_INTERRUPT_FLAG2		 							0x35
#define ADP5360_REG_SHIPMODE 										0x36

/* ADP5360 Status typedef */
typedef enum {
	ADP5360_OK 				= 0x00,
	ADP5360_ERROR    		= 0x01,
	ADP5360_BUSY    		= 0x02,
	ADP5360_TIMEOUT 		= 0x03,
	ADP5360_ERROR_WRONG_ID 	= 0x04,
	ADP5360_ERROR_NO_VBUS 	= 0x05
} ADP5360_StatusTypeDef;

/* ADP5360 Charge status typedef */
typedef enum {
	ADP5360_CHG_OFF			= 0x00,
	ADP5360_CHG_TRICKLE  	= 0x01,
	ADP5360_CHG_FAST_CC		= 0x02,
	ADP5360_CHG_FAST_CV		= 0x03,
	ADP5360_CHG_DONE		= 0x04,
	ADP5360_CHG_LDO			= 0x05,
	ADP5360_CHG_TIME_OUT	= 0x06,
	ADP5360_CHG_DET			= 0x07
} ADP5360_CHG_STATUS;

/* ADP5360 Battery charger status typedef */
typedef enum {
	ADP5360_BAT_CHG_NORMAL 		= 0x00,
	ADP5360_BAT_CHG_NO_BATTERY  = 0x01,
	ADP5360_BAT_CHG_IN_CHARGE1	= 0x02,
	ADP5360_BAT_CHG_IN_CHARGE2	= 0x03,
	ADP5360_BAT_CHG_IN_CHARGE3	= 0x04
} ADP5360_BAT_CHG_STATUS;

/* ADP5360 Device Struct */
typedef struct {
	/* I2C Handle*/
	I2C_HandleTypeDef *i2cHandle;

	/* Battery and charging variables */
	bool chargingEnabled;
	ADP5360_CHG_STATUS chargeStatus;
	ADP5360_BAT_CHG_STATUS batteryChargerStatus;
	uint8_t batteryChargePercentage;

	uint16_t originalBatteryCapacity;
	uint8_t batterySOCACMOverflows;
	uint16_t effectiveBatteryCapacity;

	uint16_t batteryVoltage;

	/* Regulator variables */
	uint16_t buckVoltage;
	uint16_t buckBoostVoltage;
	bool buckEnabled;
	bool buckBoostEnabled;

} ADP5360_HandleTypeDef;


/* Initialisation */
ADP5360_StatusTypeDef ADP5360_Init(ADP5360_HandleTypeDef *dev, I2C_HandleTypeDef *i2cHandle);

/* User Functions */
ADP5360_StatusTypeDef ADP5360_UpdateCharging(ADP5360_HandleTypeDef *dev); /* If VBUS present: enable charging, if VBUS absent: disable charging */
ADP5360_StatusTypeDef ADP5360_GetBatteryCharge(ADP5360_HandleTypeDef *dev);
ADP5360_StatusTypeDef ADP5360_EnableBuckBoost(ADP5360_HandleTypeDef *dev);
ADP5360_StatusTypeDef ADP5360_DisableBuckBoost(ADP5360_HandleTypeDef *dev);
ADP5360_StatusTypeDef ADP5360_Interrupt(ADP5360_HandleTypeDef *dev); /* Run this function whenever an interrupt occurs */
ADP5360_StatusTypeDef ADP5360_EnterShipmentMode(ADP5360_HandleTypeDef *dev);

/* Internal/debug Functions */
ADP5360_StatusTypeDef ADP5360_EnableCharging(ADP5360_HandleTypeDef *dev);
ADP5360_StatusTypeDef ADP5360_DisableCharging(ADP5360_HandleTypeDef *dev);
ADP5360_StatusTypeDef ADP5360_SetVBUSCurrentLimit(ADP5360_HandleTypeDef *dev, uint16_t current); /* Current in mA */
ADP5360_StatusTypeDef ADP5360_GetChargingStatus(ADP5360_HandleTypeDef *dev);
ADP5360_StatusTypeDef ADP5360_GetChargingStatusString(ADP5360_HandleTypeDef *dev, char *chargeStatusString);
ADP5360_StatusTypeDef ADP5360_SetBatteryCapacity(ADP5360_HandleTypeDef *dev, uint16_t s); /* Capacity in mAh */
ADP5360_StatusTypeDef ADP5360_SetSOCACMOverflows(ADP5360_HandleTypeDef *dev, uint8_t batterySOCACMOverflows);
ADP5360_StatusTypeDef ADP5360_GetBatteryChargerStatus(ADP5360_HandleTypeDef *dev);
ADP5360_StatusTypeDef ADP5360_GetBatteryVoltage(ADP5360_HandleTypeDef *dev);
ADP5360_StatusTypeDef ADP5360_EnableInterrupts(ADP5360_HandleTypeDef *dev);
ADP5360_StatusTypeDef ADP5360_DisableInterrupts(ADP5360_HandleTypeDef *dev);
ADP5360_StatusTypeDef ADP5360_EnableMRShipmentMode(ADP5360_HandleTypeDef *dev);
/* TODO: Set VBUS current */
/* TODO: Set charging currents */

/* Low-Level Functions */
ADP5360_StatusTypeDef ADP5360_ReadRegister(ADP5360_HandleTypeDef *dev, uint8_t reg, uint8_t *data);
ADP5360_StatusTypeDef ADP5360_WriteRegister(ADP5360_HandleTypeDef *dev, uint8_t reg, uint8_t *data);


#endif /* INC_ADP5360_H_ */
