/*
 * File:    raydium_selftest.c
 * Author:  Valentine <valentine.hsu@rad-ic.com>
 * Brief:   rm31080 touch screen test tool.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <linux/delay.h>
#include <linux/mutex.h>
#include <linux/unistd.h>
#include <linux/kernel.h>
#include <linux/string.h>
#include <linux/timer.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <asm/uaccess.h>

#include "raydium_selftest.h"
#include "drv_interface.h"
#include "tpselftest.h"


unsigned char g_u8_normal_fw_version_buf[4];
unsigned int g_u32_wearable_test_result;
unsigned char g_u8_wearable_pin_map[MAX_IMAGE_BUFFER_SIZE];
unsigned short g_u16_uc_golden_cc_buf[MAX_IMAGE_BUFFER_SIZE];
unsigned short g_u16_uc_buf[MAX_IMAGE_BUFFER_SIZE + 1];//CC
unsigned int g_u32_test_result[MAX_IMAGE_BUFFER_SIZE]; // each node test result (bit[0]:open ng, bit[1]:short ng, bit[2]:uniformity ng..etc)
unsigned char g_u8_channel_x;
unsigned char g_u8_channel_y;

static int enable_ic_block_2x(void)
{
	unsigned int u32_read;

	if (handle_read_word(REG_SYSCON_BLKEN_ADDR, &u32_read) == ERROR) {
		return ERROR;
	}

	u32_read |= 0xc8000000;
	handle_write_word(REG_SYSCON_BLKEN_ADDR, u32_read);

	if (handle_read_word(REG_SYSCON_MISCIER_ADDR, &u32_read) == ERROR) {
		return ERROR;
	}

	u32_read |= 0x00000404;
	handle_write_word(REG_SYSCON_MISCIER_ADDR, u32_read);
	return SUCCESS;
}

static int stop_mcu_2x(unsigned char u8_is_tp_reset)
{
	unsigned short u16_time_out = 100;
	unsigned int u32_read_data;

	if (u8_is_tp_reset) {
		gpio_touch_hw_reset();
		msleep(2);
	}

	//Stop MCU
	if (handle_write_word(REG_FLASHCTL_FLASH_STATE_REG_ADDR, (MCU_HOLD | SKIP_LOAD)) == ERROR) {
		return ERROR;
	}

	//sw reset
	if (handle_write_word(REG_SYSCON_BLKRST_ADDR, BLKRST_SW_RST) == ERROR) {
		return ERROR;
	}

	msleep(2);

	if (handle_read_word(REG_FLASHCTL_FLASH_STATE_REG_ADDR, &u32_read_data) == ERROR) {
		return ERROR;
	}

	while ((u32_read_data & MCU_HOLD_STATUS) == 0 && u16_time_out-- > 0) {
		msleep(10);
		if (handle_read_word(REG_FLASHCTL_FLASH_STATE_REG_ADDR, &u32_read_data) == ERROR) {
			return ERROR;
		}
	}

	pr_info("[touch]Stop MCU=0x%X(0x%x)(%d)!!\r\n", u32_read_data, (u32_read_data & MCU_HOLD_STATUS), u16_time_out);

	if ((u32_read_data & MCU_HOLD_STATUS) == 0) {
		return ERROR;
	}
	return SUCCESS;
}

static int hardware_reset_2x(unsigned char u8_enable_ic_block)
{
	unsigned char u8_time_out = 30;
	pr_info("[touch]HW Reseting...\r\n");

	gpio_touch_hw_reset();
	msleep(20);

	if (u8_enable_ic_block) {
		if (enable_ic_block_2x() == ERROR) {
			pr_err("[touch]HW Reset NG!!\r\n");
			return ERROR;
		}
	}
	while (u8_time_out--) {
		if (gpio_touch_int_pin_state_access()) {
			break;
		}
		if (u8_time_out == 0) {
			return ERROR;
		}
		msleep(1);
	}
	return SUCCESS;
}

static int  ft_read_fw_version(unsigned char* p_u8_data_buf)
{
	 if(handle_read_pda(FW_FT_FW_VERSION, 4, p_u8_data_buf)== ERROR){
        		pr_err("[touch][GRD] Read FW version NG!\r\n");
		g_u32_wearable_test_result |= WEARABLE_FT_TEST_RESULT_I2C_NG;
		return ERROR;		
	}
	
	return SUCCESS;
}
static int  hw_int_pin_Test_2x(void)
{
	//Trigger INT to Low
	handle_write_word(REG_SYSCON_MISCIER_ADDR, 0x00000004);

	//Read Pin state
	if (!gpio_touch_int_pin_state_access()) {
		//DEBUGOUT("INT is LOW\r\n");
	} else {
		pr_err("[touch]INT Test NG!\r\n");
		g_u32_wearable_test_result |= WEARABLE_FT_TEST_RESULT_INT_NG;
		return ERROR;
	}

	//Trigger INT to High
	handle_write_word(REG_SYSCON_MISCIER_ADDR, 0x00000404);

	//Read Pin state
	if (gpio_touch_int_pin_state_access()) {
		//DEBUGOUT("INT is High\r\n");
	} else {
		pr_err("[touch]INT Test NG!\r\n");
		g_u32_wearable_test_result |= WEARABLE_FT_TEST_RESULT_INT_NG;
		return ERROR;
	}
	//gpio_touch_int_access(TRUE);
	pr_info("[touch]INT Test Pass\r\n");
	return SUCCESS;
}

static int  ft_test_reset_pin_test_2x(void)
{
	//set INT to high
	handle_write_word(REG_SYSCON_MISCIER_ADDR, 0x00000404); 

	// check INT in high state
	if (!gpio_touch_int_pin_state_access()) { 
		g_u32_wearable_test_result |= WEARABLE_FT_TEST_RESULT_INT_NG;
		return ERROR;
	}
	// set TP_reset to Low
	gpio_touch_reset_pin_control(FALSE);
	msleep(1);

	// check INT in low state
	if (gpio_touch_int_pin_state_access()) {
		g_u32_wearable_test_result |= WEARABLE_FT_TEST_RESULT_RESET_NG;
		pr_err("[touch]Reset Pin Test NG(Not High) !!!\r\n");
		return ERROR;
	}
	// set TP_reset to High
	gpio_touch_reset_pin_control(TRUE);
	msleep(25);
	pr_info("[touch]Reset Pin Test Pass !!!\r\n");
	return SUCCESS;
}

static int check_cc_flag_2x(void)
{
	unsigned char u8_read_buf[4];
	unsigned char u8_is_cc_ready = 0;
	short i16_time_out;

	pr_info("[touch][CCBF] Check CC Flag\r\n");

	i16_time_out = 20;
	while (i16_time_out--) {
		if (!u8_is_cc_ready) {
			if (handle_read_pda(PRAM_CC_TABLE_ADDR, 4, u8_read_buf) == ERROR)
				return ERROR;
			if (u8_read_buf[0] >= 1) {
				u8_is_cc_ready = 1;
			}
		}

		if (u8_is_cc_ready )
			break;
		msleep(1);
	}

	//Check flag
	if (i16_time_out == IC_TEST_TIME_OUT) {
		pr_err("[touch]CC Flag=%d NG!!\r\n", u8_is_cc_ready);
		return ERROR;
	}

	return SUCCESS;
}

int ft_test_read_cc_data(short* p_u16_data_buf)
{	
 	if(handle_read_pda(PRAM_CC_ACT_ADDR, MAX_IMAGE_BUFFER_SIZE*2, (unsigned char*)p_u16_data_buf)== ERROR){
        		pr_err("[touch][GRD] Read Raw Data NG!\r\n");
		return ERROR;		
	}
	
	return SUCCESS;
}

int ft_test_read_used_pin_infor(unsigned char *p_u8_infor)
{
	//unsigned char u8_i;
	unsigned char u8_r_buf[2];

	//get Pin remap
	if (handle_read_pda(FW_FT_PIN_ADDR, MAX_IMAGE_BUFFER_SIZE, p_u8_infor) == ERROR) {
		pr_err("[touch][RUPI] NG!\r\n");
		return ERROR;
	}
#if 0
	for (u8_i = 0; u8_i < 36; u8_i++) {
		DEBUGOUT("Pin[%d] remap=%d\r\n", u8_i, p_u8_infor[u8_i]);
	}
#endif

	if (handle_read_pda(FW_FT_CHANNEL_X_ADDR, 2, u8_r_buf) == ERROR) {
		pr_err("[touch][RUPI] NG!\r\n");
		return ERROR;
	}
	g_u8_channel_x = u8_r_buf[0];
	g_u8_channel_y = u8_r_buf[1];
	pr_err("[touch][RUPI] X:%d,Y:%d\r\n", g_u8_channel_x, g_u8_channel_y);


	return SUCCESS;
}


void ft_raw_data_remap(short *p_i16_source_buf, unsigned char u8_data_remap)
{
	short i16_raw_data_tmp[MAX_IMAGE_BUFFER_SIZE];
	unsigned char u8_idx;

	memset(i16_raw_data_tmp, 0, sizeof(i16_raw_data_tmp));
	memcpy(i16_raw_data_tmp, p_i16_source_buf, MAX_IMAGE_BUFFER_SIZE * 2);

	if (u8_data_remap == DATA_REMAP_TO_IC_PIN) {
		for (u8_idx = 0; u8_idx < MAX_IMAGE_BUFFER_SIZE; u8_idx++) {
			if (g_u8_wearable_pin_map[u8_idx] != NA_P) {
				p_i16_source_buf[u8_idx] = i16_raw_data_tmp[g_u8_wearable_pin_map[u8_idx]];
			} else {
				p_i16_source_buf[u8_idx] = 0;
			}
		}
	} else if (u8_data_remap == DATA_REMAP_TO_SENSOR_PAD) {
		for (u8_idx = 0; u8_idx < MAX_IMAGE_BUFFER_SIZE; u8_idx++) {
			if (g_u8_wearable_pin_map[u8_idx] != NA_P) {
				p_i16_source_buf[g_u8_wearable_pin_map[u8_idx]] = i16_raw_data_tmp[u8_idx];
			} else {
				p_i16_source_buf[g_u8_wearable_pin_map[u8_idx]] = 0;
			}
		}
	}
}
int ft_test_get_raw_data(short *p_i16_data_buf, unsigned char u8_data_remap)
{
	if (ft_test_read_cc_data((short *)p_i16_data_buf) == ERROR) {
		pr_err("[touch][GRD] Get CC Data  Error!!\r\n");
		return ERROR;
	}
	if (u8_data_remap)
		ft_raw_data_remap((short *)p_i16_data_buf, u8_data_remap);
	return SUCCESS;
}

static int turn_on_flash_2x(void)
{
	unsigned int u32_read = 0;
	//Turn on Flash
	if (handle_write_word(REG_I2C_I2CFLASHPRO, 0) == ERROR) {
		return ERROR;
	}

	u32_read = FLH_RELEASE_PD;
	if (handle_write_word(REG_FLASHCTL_FLASH_ISPCTL, u32_read) == ERROR) {
		return ERROR;
	}
	return SUCCESS;
}
static int read_fpc_flash_2x(unsigned int u32_addr, unsigned int *p_u32_data)
{
	unsigned int u32_read;

	//Turn on Flash
	if (turn_on_flash_2x() == ERROR) {
		return ERROR;
	}

	if (handle_read_word(REG_SYSCON_BLKEN_ADDR, &u32_read) == ERROR) {
		return ERROR;
	}

	u32_read |= 0x40;
	if (handle_write_word(REG_SYSCON_BLKEN_ADDR, u32_read) == ERROR) {
		return ERROR;
	}

	if (handle_write_word(REG_I2C_I2CFLASHPRO, 0) == ERROR) {
		return ERROR;
	}

	if (handle_write_word(REG_FLASHCTL_FLASH_ADDR, u32_addr) == ERROR) {
		return ERROR;
	}
	if (handle_write_word(REG_FLASHCTL_FLASH_ISPCTL, 0x40) == ERROR) {
		return ERROR;
	}
	msleep(1);

	if (handle_read_word(REG_FLASHCTL_FLASH_DATA, &u32_read) == ERROR) {
		return ERROR;
	}

	*p_u32_data = u32_read;
	return SUCCESS;
}
int ft_check_uc_test_result(void)
{
	int i32_test_result = SUCCESS;
	int i32_i;
	short i16_cc_diff;
	short uppder_thd =UC_UPPER_THD;
	short lower_thd = UC_LOWER_THD;
	// unsigned bitmask = 0x7ff;

	//Use FW CC to judge, not use single pin scan CC
	pr_info("[touch]** Start UC Test Result Check\r\n [Upper, Lower] THD = %d, %d **\r\n", uppder_thd, lower_thd);

	for (i32_i = 0; i32_i < MAX_IMAGE_BUFFER_SIZE; i32_i++) {
		if (g_u8_wearable_pin_map[i32_i] != NA_P) {

			i16_cc_diff = g_u16_uc_golden_cc_buf[i32_i] - g_u16_uc_buf[i32_i];

			if (i16_cc_diff > uppder_thd || i16_cc_diff < lower_thd) {
				pr_err("[touch]UC [%d] NG!! %d - % d= %d\r\n", i32_i,
					g_u16_uc_golden_cc_buf[i32_i],  g_u16_uc_buf[i32_i], i16_cc_diff);
				g_u32_test_result[i32_i] |= IC_TEST_NODE_STATE_UC_NG;
				i32_test_result = ERROR;
			}

		}
	}

	if (i32_test_result == SUCCESS) {
		pr_info("[touch]UC Test [Pass]\r\n");
	} else {
		pr_err("[touch]UC Test [NG]\r\n");
		g_u32_wearable_test_result |= WEARABLE_FT_TEST_RESULT_UC_NG;
	}

	return i32_test_result;
}

static int burn_cc_to_ic_flash_2x(void)
{
	unsigned int u32_cc_table;
	unsigned char u8_fw_value[4];
	unsigned int u32_read;

	if (sysfs_burn_cc_bl()) {
		//Read Flash CC Table
		if (read_fpc_flash_2x(FLASH_NORMAL_FW_CC_TABLE_ADDR, &u32_cc_table) == ERROR) {
			return ERROR;
		}
		pr_info("[touch]Flash Do CC FW Version=0x%04X\r\n", (u32_cc_table & 0xFFFF0000) >> 16);
		pr_info("[touch]Flash Do CC Flag=0x%X\r\n", (u32_cc_table & 0x0000FFFF));

		//Read PRAM FW Version
		if (handle_read_pda(FW_FT_FW_VERSION, 4, u8_fw_value) == ERROR) {
			return ERROR;
		}
		pr_info("[touch]PRAM FW Version=0x%02X,0x%02X\r\n", u8_fw_value[3], u8_fw_value[2]);

		if (((u32_cc_table & 0xFF000000) >> 24) != u8_fw_value[3] || ((u32_cc_table & 0x00FF0000) >> 16) != u8_fw_value[2]) {
			pr_err("[touch]Flash CC Table FW Version is not match!\r\n");
			if (handle_read_word(REG_FLASHCTL_FLASH_STATE_REG_ADDR, &u32_read) == ERROR) {
				pr_err("[touch]read 5000 0918 error\r\n");
			}
			pr_err("[touch]Flash 0x50000918=0x%08X\r\n", u32_read);
			return ERROR;
		}

		return SUCCESS;
	} else
		return ERROR;
}
static int raydium_do_calibration(void)
{
	unsigned char u8_value[4];
	short u8_time_out = 100;	
	u8_value[0] = SYS_CMD_DO_CC_CAL;
	if (handle_write_pda(FW_SYS_CMD_ADDR, 1, u8_value, I2C_BYTE_MODE) == ERROR) { //Trigger Calibration
		return ERROR;
	}

	u8_time_out = 200;

	// Wait calibration ready
	while (u8_time_out--) {
		msleep(10);//20
		if (handle_read_pda(FW_SYS_CMD_ADDR, 4, u8_value) == ERROR) {
			return ERROR;
		} else if (u8_value[0] == 0) {
			break;
		}
	}
	if (u8_time_out == IC_TEST_TIME_OUT) {
		g_u32_wearable_test_result |= WEARABLE_FT_TEST_RESULT_CC_CALIBRATION_NG;
		pr_err("[touch][DOCC] SYS CMD CC NG\r\n");
		return ERROR;
		
	} else {
		if (check_cc_flag_2x() == ERROR) {
			g_u32_wearable_test_result |= WEARABLE_FT_TEST_RESULT_CC_CALIBRATION_NG;
			pr_err("[touch][DOCC] CC Flag NG\r\n");
			return ERROR;
		} else //Calibration OK
			return SUCCESS;
	}	
}
static int ft_do_calibration(unsigned char u8_do_calibration_cmd, unsigned char u8_burn_flash)
{
	unsigned char u8_retry = 3;
	unsigned char u8_uc_result = FALSE, u8_i;
	
	//Clear previous test result
	memset(g_u32_test_result, 0, sizeof(g_u32_test_result));

	if (u8_do_calibration_cmd == TRUE) {
		while (u8_retry--) {
			if(raydium_do_calibration() == SUCCESS) 
				break;
		}
	//Get CC data
		if (ft_test_get_raw_data((short *)g_u16_uc_buf, FALSE) == ERROR) {
			pr_err("[touch][Uniformity] Get UC Data Error!!\r\n");
			g_u32_wearable_test_result |= WEARABLE_FT_TEST_RESULT_GET_DATA_NG | WEARABLE_FT_TEST_RESULT_UC_NG;
			goto EXIT;
		} else {
			for (u8_i = 0; u8_i < MAX_IMAGE_BUFFER_SIZE + 1; u8_i++) {
				if (g_u16_uc_buf[u8_i] != 0) {
					g_u16_uc_buf[u8_i] = (0x7FF & g_u16_uc_buf[u8_i]);
					if ((g_u16_uc_buf[u8_i] & 0x400) != 0) {
						g_u16_uc_buf[u8_i] = (g_u16_uc_buf[u8_i] - 1024 + 440);
					}
				}
			}
		}		
		if (u8_uc_result == FALSE && ft_check_uc_test_result() == SUCCESS)
			u8_uc_result = TRUE;
	}
	if(u8_uc_result == FALSE)
		goto EXIT;

	if (u8_burn_flash == FALSE) {
		pr_info("[touch][DOCC] Do Calibration Finish \r\n");
		return SUCCESS;
	}

	if (burn_cc_to_ic_flash_2x() == ERROR) {
		pr_err("[touch][DOCC] Burn to flash NG!\r\n");
		hardware_reset_2x(TRUE);
		g_u32_wearable_test_result |= WEARABLE_FT_TEST_RESULT_BURN_CC_NG;
		return ERROR;
	}
	pr_info("[touch][DOCC] Burn CC Finish \r\n");

EXIT:
	if (u8_uc_result == TRUE)
		return SUCCESS;
	else
		return ERROR;	
	

}


int raydium_system_test(void)
{
	int i32_ret = SUCCESS;

	//enable ic
	if (enable_ic_block_2x() == ERROR) {
		pr_info("[touch]enable_ic_block NG!!!\r\n");
		g_u32_wearable_test_result |= WEARABLE_FT_TEST_RESULT_I2C_NG;
		i32_ret = ERROR;
		goto ERROR_EXIT;
	}

	//stop fw
	stop_mcu_2x(1);
	//Read FW version to check I2C 
	if (ft_read_fw_version(g_u8_normal_fw_version_buf) == ERROR) {
		i32_ret = ERROR;
		goto ERROR_EXIT;
	}
	
	//INT Pin Test
	if (hw_int_pin_Test_2x() == ERROR) {
		i32_ret = ERROR;
		goto ERROR_EXIT;
	}

	//Reset Pin Test
	if (ft_test_reset_pin_test_2x() == ERROR) {
		i32_ret = ERROR;
		goto ERROR_EXIT;
	}
ERROR_EXIT:

	if (i32_ret == ERROR)
		pr_info("[touch]System Test NG!!\r\n");
	else
		pr_info("[touch]System Test PASS\r\n");

	return i32_ret;
}

unsigned char raydium_uc_test(void)
{
	unsigned char u8_retry = IC_TEST_RETRY_TIME;

	g_u32_wearable_test_result &= ~(WEARABLE_FT_TEST_RESULT_BURN_CC_NG
				| WEARABLE_FT_TEST_RESULT_CC_CALIBRATION_NG);

	if (ft_test_read_used_pin_infor(g_u8_wearable_pin_map) == ERROR) {
		return ERROR;
	}

	while (u8_retry--) {
	
		//Do CC
		pr_info("[touch][BC] Burn CC Start!!\r\n");

		//Burn CC to Flash
		if (ft_do_calibration(TRUE, TRUE) == SUCCESS) {
			pr_info("[touch][BC] Burn CC Pass!!(%d)\r\n", u8_retry);
			break;
		} else {
			if (u8_retry) {
				continue;
			} else {
				pr_err("[touch][BC] Burn CC NG!!\r\n");
				return ERROR;
			}
		}
	}

	return SUCCESS;
}


int self_test_save_to_file(char *file_name, char *p_string, short len)
{
	struct file *filp = NULL;
	mm_segment_t old_fs;
	filp = filp_open(file_name, O_RDWR | O_CREAT | O_APPEND, 0666);
	if (IS_ERR(filp)) {
		pr_err("[touch]can't open file:%s\n", RM_SELF_TEST_LOGFILE);
		return 0;
	}
	old_fs = get_fs();
	set_fs(KERNEL_DS);
	filp->f_op->write(filp, p_string, len, &filp->f_pos);
	set_fs(old_fs);
	filp_close(filp, NULL);

	return 1;
}

int self_test_save_test_raw_data_to_file(int i32_ng_type)
{
	char write_string[1000];
	unsigned char u8_i, u8_j;

	//FW Version
	memset(write_string, 0, strlen(write_string));
	sprintf(write_string, "FW Version=0x%.2X%.2X%.2X%.2X\n", 
		g_u8_normal_fw_version_buf[0], g_u8_normal_fw_version_buf[1],
		g_u8_normal_fw_version_buf[3], g_u8_normal_fw_version_buf[2]);
	self_test_save_to_file(RM_SELF_TEST_LOGFILE, write_string, strlen(write_string));
	
	//Test result
	memset(write_string, 0, strlen(write_string));
	sprintf(write_string, "Test Result = 0x%08X\n\n", i32_ng_type);
	self_test_save_to_file(RM_SELF_TEST_LOGFILE, write_string, strlen(write_string));

	if (i32_ng_type == 0) {
		memset(write_string, 0, strlen(write_string));
		sprintf(write_string, "All pass\n\n\n");
		self_test_save_to_file(RM_SELF_TEST_LOGFILE, write_string, strlen(write_string));
	} else {
		memset(write_string, 0, strlen(write_string));

		if (i32_ng_type & WEARABLE_FT_TEST_RESULT_SYSFS_NG) {
			sprintf(write_string + strlen(write_string), "System NG ");
		}

		if (i32_ng_type & WEARABLE_FT_TEST_RESULT_I2C_NG) {
			sprintf(write_string + strlen(write_string), "I2C NG ");
		}

		if (i32_ng_type & WEARABLE_FT_TEST_RESULT_INT_NG) {
			sprintf(write_string + strlen(write_string), "INT NG ");
		}

		if (i32_ng_type & WEARABLE_FT_TEST_RESULT_RESET_NG) {
			sprintf(write_string + strlen(write_string), "RESET NG ");
		}

		if (i32_ng_type & WEARABLE_FT_TEST_RESULT_BURN_CC_NG) {
			sprintf(write_string + strlen(write_string), "BURN CC NG ");
		}

		if (i32_ng_type & WEARABLE_FT_TEST_RESULT_GET_DATA_NG) {
			sprintf(write_string + strlen(write_string), "GET DATA NG ");
		}

		if (i32_ng_type & WEARABLE_FT_TEST_RESULT_UC_NG) {
			sprintf(write_string + strlen(write_string), "Uniformity CC NG ");
		}

		sprintf(write_string + strlen(write_string), "\n");
		self_test_save_to_file(RM_SELF_TEST_LOGFILE, write_string, strlen(write_string));
	}

	//Threshold
	
	for (u8_i = 0; u8_i < MAX_IMAGE_BUFFER_SIZE; u8_i++) {
		memset(write_string, 0, strlen(write_string));
		sprintf(write_string, "0x%2X,", g_u16_uc_golden_cc_buf[u8_i]);
		self_test_save_to_file(RM_SELF_TEST_LOGFILE, write_string, strlen(write_string));
	}

	memset(write_string, 0, strlen(write_string));
	sprintf(write_string, "\n");
	self_test_save_to_file(RM_SELF_TEST_LOGFILE, write_string, strlen(write_string));

	if ((i32_ng_type & 0xFFF8FBF8) < 4) {
		memset(write_string, 0, strlen(write_string));
		sprintf(write_string, "\r\n\n\n");
		self_test_save_to_file(RM_SELF_TEST_LOGFILE, write_string, strlen(write_string));

		//Raw data Uniformity CC
		memset(write_string, 0, strlen(write_string));
		sprintf(write_string, "Raw Data_UC\n");
		self_test_save_to_file(RM_SELF_TEST_LOGFILE, write_string, strlen(write_string));

		for (u8_i = 0; u8_i < MAX_IMAGE_BUFFER_SIZE; u8_i++) {
			if (u8_i % g_u8_channel_x== 0 && u8_i != 0) {
				memset(write_string, 0, strlen(write_string));
				sprintf(write_string, "\r\n");
				self_test_save_to_file(RM_SELF_TEST_LOGFILE, write_string, strlen(write_string));
			}

			if (u8_i == 0 || u8_i == 5 || u8_i == 30 || u8_i == 35) {
				memset(write_string, 0, strlen(write_string));
				sprintf(write_string, "%05d,", 0);
				self_test_save_to_file(RM_SELF_TEST_LOGFILE, write_string, strlen(write_string));
			} else {
				for (u8_j = 0; u8_j < MAX_IMAGE_BUFFER_SIZE; u8_j++) {
					if (g_u8_wearable_pin_map[u8_j] != NA_P && g_u8_wearable_pin_map[u8_j] == u8_i) {
						memset(write_string, 0, strlen(write_string));
						sprintf(write_string, "%05d,", g_u16_uc_buf[u8_j]);
						self_test_save_to_file(RM_SELF_TEST_LOGFILE, write_string, strlen(write_string));
						break;
					}
				}

				if (u8_j == MAX_IMAGE_BUFFER_SIZE) {
					memset(write_string, 0, strlen(write_string));
					sprintf(write_string, "%05d,", 0);
					self_test_save_to_file(RM_SELF_TEST_LOGFILE, write_string, strlen(write_string));
				}
			}
		}
	
	}

	memset(write_string, 0, strlen(write_string));
	sprintf(write_string, "\r\n\n\n");
	self_test_save_to_file(RM_SELF_TEST_LOGFILE, write_string, strlen(write_string));

	return 1;
}

void raydium_selftest_init(void)
{
	memcpy(g_u16_uc_golden_cc_buf, u8_raw_uc_cc, MAX_IMAGE_BUFFER_SIZE*2);
	g_u32_wearable_test_result = WEARABLE_FT_TEST_RESULT_PASS;
}

int raydium_do_selftest(void)
{
	int i32_ret = SUCCESS;

	g_u8_raydium_flag |= ENG_MODE;

	raydium_selftest_init();

	i32_ret = raydium_system_test();
	if (i32_ret < 0)
		goto  ERROR_EXIT;

	i32_ret = raydium_uc_test();
	if (i32_ret < 0)
		goto  ERROR_EXIT;
	
ERROR_EXIT:
	g_u8_raydium_flag &= ~ENG_MODE;	
	i32_ret = g_u32_wearable_test_result;
	
	if(i32_ret != WEARABLE_FT_TEST_RESULT_SYSFS_NG) {
		gpio_touch_hw_reset();
	}
	//raydium_irq_control(ENABLE);

	self_test_save_test_raw_data_to_file(i32_ret);
	if (i32_ret  != 0) {
		pr_info("[touch]Selftest Test Result=0x%x\n", i32_ret);
		pr_info("[touch]Selftest NG\n");
		i32_ret = ERROR;
	} else {
		i32_ret = SUCCESS;
		pr_info("[touch]Selftest Pass ^_^!!!\n");
	}

	return i32_ret;
}

