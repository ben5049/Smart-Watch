/*
 * ADP5360.c
 *
 *  Created on: Jan 11, 2024
 *      Author: bens1
 */

#include "ADP5360.h"


ADP5360_StatusTypeDef ADP5360_Init(ADP5360_HandleTypeDef *dev, I2C_HandleTypeDef *i2cHandle){

	ADP5360_StatusTypeDef status = ADP5360_OK;
	uint8_t regData;

	/* Assign I2C handle */
	dev->i2cHandle = i2cHandle;

	/* Set default values, can be changed with functions if needed */
	dev->originalBatteryCapacity = ADP5360_DEFAULT_BATTERY_CAPACITY;
	dev->batterySOCACMOverflows = 0;
	dev->buckVoltage = ADP5360_DEFAULT_BUCK_VOLTAGE;
	dev->buckBoostVoltage = ADP5360_DEFAULT_BUCK_BOOST_VOLTAGE;
	dev->chargingEnabled = false;
	dev->buckEnabled = true;
	dev->buckBoostEnabled = false;


	/* Check the manufacturer and model IDs */
	status = ADP5360_ReadRegister(dev, ADP5360_REG_MANUFACTURER_AND_MODEL_ID, &regData);
	if (status != ADP5360_OK){
		return status;
	}

	if (regData != ((ADP5360_MANUFACTURER_ID << 4) | (ADP5360_MODEL_ID))){
		status = ADP5360_ERROR_WRONG_ID;
		return status;
	}

	/* Turn off the buck boost converter */
	status = ADP5360_DisableBuckBoost(dev);
	if (status != ADP5360_OK){
		return status;
	}

	/* Write the battery capacity */
	status = ADP5360_SetBatteryCapacity(dev, dev->originalBatteryCapacity);
	if (status != ADP5360_OK){
		return status;
	}

	/* Enable interrupts */
	status = ADP5360_EnableInterrupts(dev);
	if (status != ADP5360_OK){
		return status;
	}

	/* Set charging on/off */
	status = ADP5360_UpdateCharging(dev);
	if (status != ADP5360_OK){
		return status;
	}

	/* Read the battery charge */
	status = ADP5360_GetBatteryCharge(dev);
	if (status != ADP5360_OK){
		return status;
	}

	/* Read the charging status/mode */
	status = ADP5360_GetChargingStatus(dev);
	if (status != ADP5360_OK){
		return status;
	}

	/* Read the battery charger status/mode */
	status = ADP5360_GetBatteryChargerStatus(dev);

	return status;
}

ADP5360_StatusTypeDef ADP5360_EnableCharging(ADP5360_HandleTypeDef *dev){

	ADP5360_StatusTypeDef status = ADP5360_OK;
	uint8_t regData;

	/* Read the "CHARGER_FUNCTION_SETTING" register */
	status = ADP5360_ReadRegister(dev, ADP5360_REG_CHARGER_FUNCTION_SETTING, &regData);
	if (status != ADP5360_OK){
		return status;
	}

	/* Set the "EN_LDO" and "EN_CHG" bits high */
	regData = regData | ADP5360_BIT_EN_LDO | ADP5360_BIT_EN_CHG;

	/* Write the "CHARGER_FUNCTION_SETTING" register */
	status = ADP5360_WriteRegister(dev, ADP5360_REG_CHARGER_FUNCTION_SETTING, &regData);
	if (status != ADP5360_OK){
		return status;
	}

	/* Update the device struct */
	dev->chargingEnabled = true;

	return status;
}


ADP5360_StatusTypeDef ADP5360_DisableCharging(ADP5360_HandleTypeDef *dev){

	ADP5360_StatusTypeDef status = ADP5360_OK;
	uint8_t regData;

	/* Read the "CHARGER_FUNCTION_SETTING" register */
	status = ADP5360_ReadRegister(dev, ADP5360_REG_CHARGER_FUNCTION_SETTING, &regData);
	if (status != ADP5360_OK){
		return status;
	}

	/* Set the "EN_CHG" bit low */
	regData &= ~ADP5360_BIT_EN_CHG;

	/* Write the "CHARGER_FUNCTION_SETTING" register */
	status = ADP5360_WriteRegister(dev, ADP5360_REG_CHARGER_FUNCTION_SETTING, &regData);
	if (status != ADP5360_OK){
		return status;
	}

	/* Update the device struct */
	dev->chargingEnabled = false;

	return status;
}

ADP5360_StatusTypeDef ADP5360_UpdateCharging(ADP5360_HandleTypeDef *dev){

	ADP5360_StatusTypeDef status = ADP5360_OK;
	uint8_t regData;

	/* Read the "ADP5360_REG_PGOOD_STATUS" register */
	status = ADP5360_ReadRegister(dev, ADP5360_REG_PGOOD_STATUS, &regData);
	if (status != ADP5360_OK){
		return status;
	}

	/* If VBUS present, enable charging */
	if (regData & ADP5360_BIT_VBUSOK){
		if (dev->chargingEnabled == false){
			status = ADP5360_EnableCharging(dev);
			if (status != ADP5360_OK){
				return status;
			}
		}
	}
	/* If VBUS absent, disable charging */
	else{
		if (dev->chargingEnabled == true){
			status = ADP5360_DisableCharging(dev);
			if (status != ADP5360_OK){
				return status;
			}
		}
	}

	return status;
}

ADP5360_StatusTypeDef ADP5360_GetChargingStatus(ADP5360_HandleTypeDef *dev){

	ADP5360_StatusTypeDef status = ADP5360_OK;
	uint8_t regData;

	/* Read the "ADP5360_REG_CHARGER_STATUS1" register */
	status = ADP5360_ReadRegister(dev, ADP5360_REG_CHARGER_STATUS1, &regData);
	if (status != ADP5360_OK){
		return status;
	}

	/* Extract the "CHARGE_STATUS" bits and update the device struct */
	dev->chargeStatus = regData & ADP5360_BITS_CHARGER_STATUS;

	return status;
}

ADP5360_StatusTypeDef ADP5360_GetChargingStatusString(ADP5360_HandleTypeDef *dev, char *chargeStatusString){

	ADP5360_StatusTypeDef status = ADP5360_OK;

	/* Get the charging status bits */
	status = ADP5360_GetChargingStatus(dev);
	if (status != ADP5360_OK){
		return status;
	}

	/* Turn the charging status bits into human readable text */
	switch (dev->chargeStatus){

	case ADP5360_CHG_OFF:
		chargeStatusString = "off";
		break;

	case ADP5360_CHG_TRICKLE:
		chargeStatusString = "trickle charge";
		break;

	case ADP5360_CHG_FAST_CC:
		chargeStatusString = "fast charge (constant current mode)";
		break;

	case ADP5360_CHG_FAST_CV:
		chargeStatusString = "fast charge (constant voltage mode)";
		break;

	case ADP5360_CHG_DONE:
		chargeStatusString = "charge complete";
		break;

	case ADP5360_CHG_LDO:
		chargeStatusString = "LDO mode";
		break;

	case ADP5360_CHG_TIME_OUT:
		chargeStatusString = "trickle or fast charge timer expired";
		break;

	case ADP5360_CHG_DET:
		chargeStatusString = "battery detection";
		break;

	default:
		chargeStatusString = "status unknown";
	}

	return status;
}


ADP5360_StatusTypeDef ADP5360_GetBatteryChargerStatus(ADP5360_HandleTypeDef *dev){

	ADP5360_StatusTypeDef status = ADP5360_OK;
	uint8_t regData;

	/* Read the "ADP5360_REG_CHARGER_STATUS2" register */
	status = ADP5360_ReadRegister(dev, ADP5360_REG_CHARGER_STATUS2, &regData);
	if (status != ADP5360_OK){
		return status;
	}

	/* Extract the "BAT_CHG_STATUS" bits and update the device struct */
	dev->batteryChargerStatus = regData & ADP5360_BITS_BAT_CHG_STATUS;

	return status;
}


ADP5360_StatusTypeDef ADP5360_SetBatteryCapacity(ADP5360_HandleTypeDef *dev, uint16_t originalBatteryCapacity){

	ADP5360_StatusTypeDef status = ADP5360_OK;

	/* Update the device struct */
	dev->originalBatteryCapacity = originalBatteryCapacity;
	dev->effectiveBatteryCapacity = (dev->originalBatteryCapacity * (1.0 - (ADP5360_BATTERY_DEGRADATION_PER_OVERFLOW * dev->batterySOCACMOverflows)));

	/* Convert  BAT_CAP (p. 46) */
	uint8_t regData = dev->effectiveBatteryCapacity / 2;

	/* Write the "ADP5360_REG_BAT_CAP" register */
	status = ADP5360_WriteRegister(dev, ADP5360_REG_BAT_CAP, &regData);
	if (status != ADP5360_OK){
		return status;
	}

	return status;
}

ADP5360_StatusTypeDef ADP5360_SetSOCACMOverflows(ADP5360_HandleTypeDef *dev, uint8_t batterySOCACMOverflows){

	ADP5360_StatusTypeDef status = ADP5360_OK;

	/* Update the device struct */
	dev->batterySOCACMOverflows = batterySOCACMOverflows;

	/* Recalculate battery capacity */
	status = ADP5360_SetBatteryCapacity(dev, dev->originalBatteryCapacity);
	if (status != ADP5360_OK){
		return status;
	}

	return status;

}

ADP5360_StatusTypeDef ADP5360_GetBatteryCharge(ADP5360_HandleTypeDef *dev){

	ADP5360_StatusTypeDef status = ADP5360_OK;
	uint8_t regData;

	/* Read the "ADP5360_REG_BAT_SOC" register */
	status = ADP5360_ReadRegister(dev, ADP5360_REG_BAT_SOC, &regData);
	if (status != ADP5360_OK){
		return status;
	}

	/* Extract "BAT_SOC" bits and update the device struct */
	dev->batteryChargePercentage = regData & ADP5360_BITS_BAT_SOC;

	return status;
}

ADP5360_StatusTypeDef ADP5360_GetBatteryVoltage(ADP5360_HandleTypeDef *dev){

	ADP5360_StatusTypeDef status = ADP5360_OK;
	uint8_t regData;

	/* Read the "ADP5360_REG_VBAT_READ_H" register */
	status = ADP5360_ReadRegister(dev, ADP5360_REG_VBAT_READ_H, &regData);
	if (status != ADP5360_OK){
		return status;
	}

	/* Write the highest 8 bits of "batteryVoltage" */
	dev->batteryVoltage = (regData << 5);

	/* Read the "ADP5360_REG_VBAT_READ_L" register */
	status = ADP5360_ReadRegister(dev, ADP5360_REG_VBAT_READ_L, &regData);
	if (status != ADP5360_OK){
		return status;
	}

	/* Write the lowest 5 bits of "batteryVoltage" */
	dev->batteryVoltage = dev->batteryVoltage | (regData >> 3);

	return status;
}


ADP5360_StatusTypeDef ADP5360_EnableBuckBoost(ADP5360_HandleTypeDef *dev){

	ADP5360_StatusTypeDef status = ADP5360_OK;
	uint8_t regData;

	/* Read the "ADP5360_REG_BUCK_BOOST_CONFIG" register */
	status = ADP5360_ReadRegister(dev, ADP5360_REG_BUCK_BOOST_CONFIG, &regData);
	if (status != ADP5360_OK){
		return status;
	}

	/* Set the "EN_BUCKBST" bit high */
	regData |= ADP5360_BIT_EN_BUCKBST;

	/* Write the "ADP5360_REG_BUCK_BOOST_CONFIG" register */
	status = ADP5360_WriteRegister(dev, ADP5360_REG_BUCK_BOOST_CONFIG, &regData);
	if (status != ADP5360_OK){
		return status;
	}

	/* Update the device struct */
	dev->buckBoostEnabled = true;

	return status;
}

ADP5360_StatusTypeDef ADP5360_DisableBuckBoost(ADP5360_HandleTypeDef *dev){

	ADP5360_StatusTypeDef status = ADP5360_OK;
	uint8_t regData;

	/* Read the "ADP5360_REG_BUCK_BOOST_CONFIG" register */
	status = ADP5360_ReadRegister(dev, ADP5360_REG_BUCK_BOOST_CONFIG, &regData);
	if (status != ADP5360_OK){
		return status;
	}

	/* Set the "EN_BUCKBST" bit low */
	regData &= ~ADP5360_BIT_EN_BUCKBST;

	/* Write the "ADP5360_REG_BUCK_BOOST_CONFIG" register */
	status = ADP5360_WriteRegister(dev, ADP5360_REG_BUCK_BOOST_CONFIG, &regData);
	if (status != ADP5360_OK){
		return status;
	}

	/* Update the device struct */
	dev->buckBoostEnabled = false;

	return status;
}

ADP5360_StatusTypeDef ADP5360_EnableInterrupts(ADP5360_HandleTypeDef *dev){

	ADP5360_StatusTypeDef status = ADP5360_OK;
	uint8_t regData = 0x00;

	/* Configure "ADP5360_REG_INTERRUPT_ENABLE1" */
	regData = ADP5360_VBUS_INT | ADP5360_CHG_INT | ADP5360_BAT_INT | ADP5360_THR_INT | ADP5360_BATPRO_INT | ADP5360_ADPICHG_INT | ADP5360_SOCACM_INT | ADP5360_SOCLOW_INT;

	/* Write the "ADP5360_REG_INTERRUPT_ENABLE1" register */
	status = ADP5360_WriteRegister(dev, ADP5360_REG_INTERRUPT_ENABLE1, &regData);
	if (status != ADP5360_OK){
		return status;
	}

	/* Configure "ADP5360_REG_INTERRUPT_ENABLE2" */
	regData = 0x00;
	regData = ADP5360_BUCKBSTPG_INT | ADP5360_BUCKPG_INT | ADP5360_WD_INT | ADP5360_MR_INT;

	/* Write the "ADP5360_REG_INTERRUPT_ENABLE2" register */
	status = ADP5360_WriteRegister(dev, ADP5360_REG_INTERRUPT_ENABLE2, &regData);

	return status;
}

ADP5360_StatusTypeDef ADP5360_DisableInterrupts(ADP5360_HandleTypeDef *dev){

	ADP5360_StatusTypeDef status = ADP5360_OK;
	uint8_t regData = 0x00;

	/* Write the "ADP5360_REG_INTERRUPT_ENABLE1" register */
	status = ADP5360_WriteRegister(dev, ADP5360_REG_INTERRUPT_ENABLE1, &regData);
	if (status != ADP5360_OK){
		return status;
	}

	/* Write the "ADP5360_REG_INTERRUPT_ENABLE2" register */
	status = ADP5360_WriteRegister(dev, ADP5360_REG_INTERRUPT_ENABLE2, &regData);

	return status;
}

ADP5360_StatusTypeDef ADP5360_HandleInterrupt(ADP5360_HandleTypeDef *dev){

	ADP5360_StatusTypeDef status = ADP5360_OK;
	uint8_t regData;

	/* Read the "ADP5360_REG_INTERRUPT_FLAG1" register */
	status = ADP5360_ReadRegister(dev, ADP5360_REG_INTERRUPT_FLAG1, &regData);
	if (status != ADP5360_OK){
		return status;
	}

	/* VBUS Change interrupt */
	if (regData & ADP5360_VBUS_INT){
		status = ADP5360_UpdateCharging(dev);
		if (status != ADP5360_OK){
			return status;
		}
	}

	/* Charging mode change interrupt */
	if (regData & ADP5360_CHG_INT){
		status = ADP5360_GetChargingStatus(dev);
		if (status != ADP5360_OK){
			return status;
		}
	}

	/* Battery voltage interrupt */
	if (regData & ADP5360_BAT_INT){
		status = ADP5360_GetBatteryCharge(dev);
		if (status != ADP5360_OK){
			return status;
		}
		status = ADP5360_GetBatteryVoltage(dev);
		if (status != ADP5360_OK){
			return status;
		}
	}

	/* SOCACM Counter overflow interrupt */
	if (regData & ADP5360_SOCACM_INT){
		dev->batterySOCACMOverflows++;
		status = ADP5360_SetBatteryCapacity(dev, dev->originalBatteryCapacity);
		/* TODO: Save "batterySOCACMOverflows" to EEPROM */
	}

	/* Low power interrupt */
	if (regData & ADP5360_SOCLOW_INT){
		/* TODO: Do something when power is low */
	}

	//	/* Read the "ADP5360_REG_INTERRUPT_FLAG2" register */
	//	status = ADP5360_ReadRegister(dev, ADP5360_REG_INTERRUPT_FLAG2, &regData);
	//	if (status != ADP5360_OK){
	//		return status;
	//	}

	return status;
}

ADP5360_StatusTypeDef ADP5360_EnterShipmentMode(ADP5360_HandleTypeDef *dev){

	ADP5360_StatusTypeDef status = ADP5360_OK;
	uint8_t regData = 0xFF;

	/* Write the "ADP5360_REG_SHIPMODE" register */
	status = ADP5360_WriteRegister(dev, ADP5360_REG_SHIPMODE, &regData);

	return status;
}

ADP5360_StatusTypeDef ADP5360_EnableMRShipmentMode(ADP5360_HandleTypeDef *dev){

	ADP5360_StatusTypeDef status = ADP5360_OK;
	uint8_t regData;

	/* Read the "ADP5360_REG_SUPERVISORY_SETTING" register */
	status = ADP5360_ReadRegister(dev, ADP5360_REG_SUPERVISORY_SETTING, &regData);
	if (status != ADP5360_OK){
		return status;
	}

	/* Set the */
	regData |= ADP5360_BIT_EN_MR_SD;

	/* Write the "ADP5360_REG_SUPERVISORY_SETTING" register */
	status = ADP5360_WriteRegister(dev, ADP5360_REG_SUPERVISORY_SETTING, &regData);

	return status;
}

ADP5360_StatusTypeDef ADP5360_ReadRegister(ADP5360_HandleTypeDef *dev, uint8_t reg, uint8_t *data){

	return HAL_I2C_Mem_Read(dev->i2cHandle, ADP5360_I2C_ADDR, reg, I2C_MEMADD_SIZE_8BIT, data, 1, HAL_MAX_DELAY);
}

ADP5360_StatusTypeDef ADP5360_WriteRegister(ADP5360_HandleTypeDef *dev, uint8_t reg, uint8_t *data){

	return HAL_I2C_Mem_Write(dev->i2cHandle, ADP5360_I2C_ADDR, reg, I2C_MEMADD_SIZE_8BIT, data, 1, HAL_MAX_DELAY);
}
