#include "raydium_driver.h"

#define I2C_INTERFACE			0

#define M_RX_BUF				1
#define M_TX_BUF				0

#define     __I     volatile
#define     __O     volatile
#define     __IO    volatile

#define FALSE					0x00
#define TRUE					0x01

#define WORD					4

#define I2C_BYTE_MODE 				(0x80|0x20)
#define I2C_WORD_MODE 			(0xc0|0x20)
#define I2C_MCU_MODE				0x40

extern unsigned char g_u8_m_buf[2][128];

extern int sysfs_burn_cc_bl(void);

extern void gpio_touch_reset_pin_control(unsigned char u8_high);
extern void gpio_touch_hw_reset(void);
extern unsigned char  gpio_touch_int_pin_state_access(void);
 
extern int handle_read_word(unsigned int addr, unsigned int *p_data);
extern int handle_write_word(unsigned int u32_addr, unsigned int u32_data);
extern int handle_read_pda(unsigned int u32_addr, unsigned char u8_read_len, unsigned char *p_u8_output_buf);
extern int handle_write_pda(unsigned int u32_addr, unsigned char u8_write_len , unsigned char *bValue, unsigned char u8_trans_mode);

