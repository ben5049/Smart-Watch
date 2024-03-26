
//#include "Config.h"

#include <linux/timer.h>
#include <linux/delay.h>
#include <linux/unistd.h>
#include <linux/string.h>
#include <linux/of_gpio.h>
#include "drv_interface.h"
#include "raydium_selftest.h"

unsigned char g_u8_m_buf[2][128];

unsigned char gpio_touch_int_pin_state_access(void)
{
	return gpio_get_value(g_raydium_ts->irq_gpio);
}


int sysfs_burn_cc_bl(void)
{
	int ret = ERROR;

	pr_info("[touch]start sysfs_burn_cc_bl\r\n");
	ret = raydium_burn_comp(g_raydium_ts->client);
	return ret;
}

void gpio_touch_reset_pin_control(unsigned char u8_high)
{

	if (u8_high)
		gpio_set_value(g_raydium_ts->rst_gpio, 1);
	else
		gpio_set_value(g_raydium_ts->rst_gpio, 0);

	return;

}


void gpio_touch_hw_reset(void)
{
	gpio_touch_reset_pin_control(0);
	msleep(10);
	gpio_touch_reset_pin_control(1);

}

int i2c_burst_read(unsigned int u32_addr, unsigned char u8_read_len, unsigned char *p_u8_output_buf)
{

	int bResult = ERROR;
	unsigned char u8_rx_len = u8_read_len;
	unsigned char *p_u8_i2c_read_buf;
	unsigned char u8_len = 0;

	if (p_u8_output_buf == NULL)
		p_u8_i2c_read_buf = g_u8_m_buf[M_RX_BUF];
	else
		p_u8_i2c_read_buf = p_u8_output_buf;

	if (u8_read_len == 0) {
		pr_info("[touch][I2CBR] Length(%d) of I2C read is error!!\r\n", u8_read_len);
		return ERROR;
	}


	while (u8_len < u8_read_len) {
		if ((u8_len + MAX_READ_PACKET_SIZE) < u8_read_len)
			u8_rx_len = MAX_READ_PACKET_SIZE;
		else
			u8_rx_len = (u8_read_len - u8_len);
		if (raydium_i2c_pda_read(g_raydium_ts->client, u32_addr + u8_len, g_u8_m_buf[M_RX_BUF], u8_rx_len)  < 0) {
			bResult = ERROR;
			break;
		} else {
			memcpy(&p_u8_i2c_read_buf[u8_len], g_u8_m_buf[M_RX_BUF], u8_rx_len);
			//DEBUGOUT("[I2CBR]read len%d data0x%2x%2x%2x%2x \r\n",u8_rx_len,p_u8_i2c_read_buf[u8_len],p_u8_i2c_read_buf[u8_len+1],p_u8_i2c_read_buf[u8_len+2],p_u8_i2c_read_buf[u8_len+3]);
			u8_len += u8_rx_len;
			bResult = SUCCESS;
		}
	}



	return bResult;
}


int i2c_burst_write(unsigned int u32_addr, unsigned char u8_write_len, unsigned char *bValue)
{

	int bResult = ERROR;
	unsigned char u8_tx_len = u8_write_len;
	unsigned char u8_len = 0;

	if (u8_write_len == 0) {
		pr_info("[touch][I2CBW] Length(%d) of I2C write is error!!\r\n", u8_write_len);
		return ERROR;
	}

	while (u8_len < u8_write_len) {
		if ((u8_len + MAX_WRITE_PACKET_SIZE) < u8_write_len)
			u8_tx_len = MAX_WRITE_PACKET_SIZE;
		else
			u8_tx_len = (u8_write_len - u8_len);
		if (raydium_i2c_pda_write(g_raydium_ts->client, u32_addr + u8_len, bValue + u8_len, u8_tx_len)  < 0) {
			bResult = ERROR;
			break;
		} else {
			u8_len += u8_tx_len;
			//DEBUGOUT("[I2CBW]write len%d data0x%2x%2x%2x%2x \r\n",u8_tx_len,bValue[u8_len],bValue[u8_len +1], bValue[u8_len +2] ,bValue[u8_len + 3]);

			bResult = SUCCESS;
		}
	}


	return bResult;
}

int handle_read_word(unsigned int u32_addr, unsigned int *p_u32_data)
{

	if (u32_addr  & 0x00000003) {
		pr_info("[touch][HRW] Handle Read Word ADDR Not Word Align!!\r\n");
		return ERROR;
	}

	if (raydium_i2c_pda_read(g_raydium_ts->client, u32_addr, (unsigned char *)p_u32_data, 4) < 0) {
		*p_u32_data = 0;
		pr_info("[touch][I2CRW] I2C Read Word NG (0x%x)\r\n", u32_addr);
		return ERROR;
	}

	return SUCCESS;
}


int handle_write_word(unsigned int u32_addr, unsigned int u32_data)
{

	if (u32_addr  & 0x00000003) {
		pr_info("[touch][I2CRW] Handle Write Word ADDR Not Word Align!!\r\n");
		return ERROR;
	}

	if (raydium_i2c_pda_write(g_raydium_ts->client, u32_addr, (unsigned char *)&u32_data, 4) < 0) {
		pr_info("[touch][I2CWW] Write I2C NG (0x%x:0x%x) \r\n", u32_addr, u32_data);
		return ERROR;
	}
	return SUCCESS;
}


int handle_read_pda(unsigned int u32_addr, unsigned char u8_read_len,
				unsigned char *p_u8_output_buf)
{
	if (i2c_burst_read(u32_addr, u8_read_len, p_u8_output_buf) == ERROR) {
		pr_info("[touch][HRP] handle_read_pda I2C NG!\r\n");
		return ERROR;
	}

	return SUCCESS;
}

int handle_write_pda(unsigned int u32_addr, unsigned char u8_write_len ,
				unsigned char *bValue, unsigned char u8_trans_mode)
{
	if (i2c_burst_write(u32_addr, u8_write_len, bValue) == ERROR) {
		pr_info("[touch][HWP] handle_write_pda I2C NG!\r\n");
		return ERROR;
	}

	return SUCCESS;
}
