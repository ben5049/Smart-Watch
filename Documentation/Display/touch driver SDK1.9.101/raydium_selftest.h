#define RM_SELF_TEST_LOGFILE			"/sdcard/selftest.csv"

#define IC_TEST_RETRY_TIME               					3
#define IC_TEST_TIME_OUT                   					(-1)

//TEST RESULT CODE
#define WEARABLE_FT_TEST_RESULT_PASS        			0x00000000
#define WEARABLE_FT_TEST_RESULT_I2C_NG			0x00000008
#define WEARABLE_FT_TEST_RESULT_INT_NG      			0x00000010
#define WEARABLE_FT_TEST_RESULT_RESET_NG			0x00000040
#define WEARABLE_FT_TEST_RESULT_BURN_CC_NG			0x00000400
#define WEARABLE_FT_TEST_RESULT_GET_DATA_NG		0x00001000
#define WEARABLE_FT_TEST_RESULT_UC_NG 			0x00010000
#define WEARABLE_FT_TEST_RESULT_CC_CALIBRATION_NG		0x00080000
#define WEARABLE_FT_TEST_RESULT_SYSFS_NG			0x04000000

#define WEARABLE_FT_TEST_RESULT_UNUSE_FLAG			0x80000000

#define FW_SYS_CMD_ADDR             				0x20000288
#define FW_FT_CMD_ADDR					0x20000289

//REG
#define REG_SYSCON_BLKEN_ADDR				0x40000000
#define REG_SYSCON_BLKRST_ADDR				0x40000004
#define REG_SYSCON_MISCIER_ADDR				0x40000014

#define REG_FLASHCTL_FLASH_ADDR				0X50000910
#define REG_FLASHCTL_FLASH_STATE_REG_ADDR			0x50000918
#define REG_FLASHCTL_FLASH_ISPCTL				0X50000914
#define REG_FLASHCTL_FLASH_DATA				0x5000093C
#define REG_FLASHCTL_DEVID_ADDR				0x500009BC
#define REG_I2C_I2CFLASHPRO					0x50000624

//
#define PRAM_PARA_START	               		 (0x6A00)

#define FW_FT_FW_VERSION				(PRAM_PARA_START + 4)
#define FW_FT_CHANNEL_X_ADDR				(PRAM_PARA_START + 20)
#define FW_FT_CHANNEL_Y_ADDR				(PRAM_PARA_START + 21)
#define FW_FT_PIN_ADDR					(PRAM_PARA_START + 24)
#define FW_FT_PWR_MODE_ADDR				(PRAM_PARA_START + 22)

#define PRAM_CC_ACT_ADDR				(0x6B60)
#define PRAM_CC_TABLE_ADDR				(0x6CC8)

#define FLASH_NORMAL_FW_CC_TABLE_ADDR		0x8168


#define MCU_HOLD                    	(0x00000001<<5)		// [0] (R/W) MCU hold
#define SKIP_LOAD                   	(0x00000001<<4)		// [0] (R/W) Skip all load flash action
#define BLKRST_SW_RST               (0x00000001<<0)      	// [0] (R/W) 1: Software reset, all digital block will be reset
#define MCU_HOLD_STATUS           (0x00000001<<13)	// [0] (R) MCU_HOLD status
#define FLH_RELEASE_PD             	(0x00000001<<5)      	// [0] (R/W) Release from deep power down mode
#define BL_CRC_CHK		(0x00000001<<11)	// [0] (R/W) boot-loader area CRC check
#define IC_TEST_NODE_STATE_UC_NG	0x40


#define MAX_IMAGE_BUFFER_SIZE				36
#define NA_P						36
#define DO_CC_CMD					1
#define NOT_DO_CC_CMD					0
#define BURN_TO_FLASH					1
#define NOT_BURN_TO_FLASH				0
#define DATA_REMAP_TO_IC_PIN    			1
#define DATA_REMAP_TO_SENSOR_PAD			2

#define SYS_CMD_DO_CC_CAL				0x5C
#define SYS_CMD_CAL_WAIT				0x5D


extern unsigned char g_u8_wearable_pin_map[MAX_IMAGE_BUFFER_SIZE];
extern unsigned short g_u16_uc_golden_cc_buf[MAX_IMAGE_BUFFER_SIZE];
extern unsigned short g_u16_uc_buf[MAX_IMAGE_BUFFER_SIZE + 1];//CC
extern unsigned int g_u32_test_result[MAX_IMAGE_BUFFER_SIZE];

extern unsigned char g_u8_channel_x;
extern unsigned char g_u8_channel_y;
extern unsigned int g_u32_wearable_test_result;

