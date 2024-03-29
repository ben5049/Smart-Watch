/*
 * M24256X.h
 *
 *  Created on: Jan 18, 2024
 *      Author: bens1
 */

#ifndef INC_M24256X_H_
#define INC_M24256X_H_

/* Defines*/

/* Device Address (p.11) */
#define M24256X_DEFAULT_CE_ADDR (0x00 << 1)
#define M24256X_CE_ADDR (0x00 << 1) /* Can be set between 0x00 and 0x07 (don't use 0x02 or 0x07 since they will clash with other devices on the bus)*/

#define M24256X_MEM_DEV_ADDR			(0xA0 | M24256X_CE_ADDR)
#define M24256X_ID_PAGE_DEV_ADDR		(0xB0 | M24256X_CE_ADDR)
#define M24256X_ID_PAGE_LOCK_DEV_ADDR	(0xB0 | M24256X_CE_ADDR)
#define M24256X_CFG_DEV_ADDR_DEV_ADDR	(0xA0 | M24256X_CE_ADDR)
#define M24256X_WP_DEV_ADDR				(0xA0 | M24256X_CE_ADDR)

/* First Byte (p.11) */
#define M24256X_ID_PAGE_FIRST_BYTE_ADDR			0x00
#define M24256X_ID_PAGE_LOCK_FIRST_BYTE_ADDR	0x04
#define M24256X_CFG_DEV_ADDR_FIRST_BYTE_ADDR	0xC0
#define M24256X_WP_DEV_ADDR_FIRST_BYTE_ADDR		0xA0

/* Second Byte (p.11) */
#define M24256X_ID_PAGE_LOCK_SECOND_BYTE_ADDR	0x00
#define M24256X_CFG_DEV_ADDR_SECOND_BYTE_ADDR	0x00
#define M24256X_WP_DEV_ADDR_SECOND_BYTE_ADDR	0x00

#define M24256X_MAX_ATTEMPTS 100 /* Maximum access attempts (in case M24256X is busy writing) */

#endif /* INC_M24256X_H_ */
