/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    app_netxduo.c
  * @author  MCD Application Team
  * @brief   NetXDuo applicative file
  ******************************************************************************
    * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "app_netxduo.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "cyhal.h"
#include "cybsp.h"
#include "cyabs_rtos.h"

#include "cy_wcm.h"
#include "cy_network_mw_core.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

#if  !defined(WIFI_SSID)
   #define WIFI_SSID                       "osa"
#endif /* (WIFI_SSID) */
#if  !defined(WIFI_PASSWORD)
   #define WIFI_PASSWORD                   "password"
#endif /* (WIFI_PASSWORD) */

#define MAX_WIFI_RETRY_COUNT     5

#define CY_RSLT_ERROR            ((cy_rslt_t)-1)

#define DEFAULT_PRIORITY         20
#define DEFAULT_MEMORY_SIZE      1024
#define ARP_MEMORY_SIZE          DEFAULT_MEMORY_SIZE

#define DEFAULT_PORT             6000
#define QUEUE_MAX_SIZE           512

/* LED blink timer period value */
#define LED_BLINK_PERIOD        (3000)

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
TX_THREAD AppMainThread;
UCHAR* pointer;

NX_UDP_SOCKET UDPSocket;
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
void application_start(ULONG id);


/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/***************************************************************************************************
 * test_connect_ap
 **************************************************************************************************/
static cy_rslt_t test_connect_ap(void)
{
    cy_rslt_t res;
    cy_wcm_connect_params_t connect_param;
    cy_wcm_config_t config;
    cy_wcm_ip_address_t ip_addr, gateway_addr, net_mask_addr;
    int retry_count = 0;
    /*
     * Initialize WCM.
     */

    config.interface = CY_WCM_INTERFACE_TYPE_STA;
    res = cy_wcm_init(&config);

    if (res != CY_RSLT_SUCCESS)
    {
//        printf("Error initializing WCM\n");
        return res;
    }

    memset(&connect_param, 0, sizeof(cy_wcm_connect_params_t));
    memcpy(connect_param.ap_credentials.SSID, WIFI_SSID, strlen(WIFI_SSID));
    memcpy(connect_param.ap_credentials.password, WIFI_PASSWORD, strlen(WIFI_PASSWORD));
    connect_param.ap_credentials.security = CY_WCM_SECURITY_WPA2_AES_PSK;

//    printf("Connecting to %s\n", WIFI_SSID);
    while (1)
    {
        /*
         * Join  cy_rtos_delay_milliseconds(500);to Wi-Fi AP
         */
//        printf("initiating cy_wcm_connect_ap\n");
        res = cy_wcm_connect_ap(&connect_param, &ip_addr);

//        printf("res = %x \n", (uint8_t)res);

//        printf("CY_RSLT TYPE = %lx MODULE = %lx CODE= %lx\n", CY_RSLT_GET_TYPE(
//                   res), CY_RSLT_GET_MODULE(res),
//               CY_RSLT_GET_CODE(res));
        if (res != CY_RSLT_SUCCESS)
        {
            retry_count++;
            if (retry_count >= MAX_WIFI_RETRY_COUNT)
            {
//                printf("Exceeded max Wi-Fi connection attempts\n");
                return CY_RSLT_ERROR;
            }
//            printf("Connection to Wi-Fi network failed. Retrying...\n");
            continue;
        }
        else
        {
//            printf("Successfully joined Wi-Fi network '%s'\n", connect_param.ap_credentials.SSID);
            cy_wcm_get_ip_addr(CY_WCM_INTERFACE_TYPE_STA, &ip_addr);
//            print_ip4(ip_addr.ip.v4);

//            printf("Get gateway IP address\n");
            cy_wcm_get_gateway_ip_address(CY_WCM_INTERFACE_TYPE_STA, &gateway_addr);
//            print_ip4(gateway_addr.ip.v4);

//            printf("Get gateway net mask address\n");
            cy_wcm_get_ip_netmask(CY_WCM_INTERFACE_TYPE_STA, &net_mask_addr);
//            print_ip4(net_mask_addr.ip.v4);
            break;
        }
    }

//    printf("\nNetwork is UP\n");
    return CY_RSLT_SUCCESS;
}


/***************************************************************************************************
 * test_ping
 **************************************************************************************************/
static cy_rslt_t test_ping(void)
{
    cy_rslt_t res;
    cy_wcm_ip_address_t gateway_addr;
    uint32_t elapsed_time_ms;

//    printf("\nPing test. ");
    cy_wcm_get_gateway_ip_address(CY_WCM_INTERFACE_TYPE_STA, &gateway_addr);
//    print_ip4(gateway_addr.ip.v4);

    for (uint32_t i = 0; i < 10; i++)
    {
        /* Send PING request with 3000ms ping timeout */
        res = cy_wcm_ping(CY_WCM_INTERFACE_TYPE_STA, &gateway_addr, 3000, &elapsed_time_ms);
        if (res == CY_RSLT_SUCCESS)
        {
//            printf("Ping was successful time elapsed = %lu ms\r\n", elapsed_time_ms);
        }
        else
        {
//            printf("Ping failed !! Module %lx Code %lx\r\n", CY_RSLT_GET_MODULE(res),
//                   CY_RSLT_GET_CODE(res));
        }

        HAL_Delay(500);
    }
    return CY_RSLT_SUCCESS;
}


/***************************************************************************************************
 * test_run_udp_server
 **************************************************************************************************/
static cy_rslt_t test_run_udp_server(void)
{
    UINT ret;
    ULONG bytes_read;
    UINT source_port;

    UCHAR data_buffer[512];
    ULONG source_ip_address;
    NX_PACKET* data_packet;

    /* create the UDP socket */
    ret = nx_udp_socket_create(cy_network_get_nw_interface(CY_NETWORK_WIFI_STA_INTERFACE,
                                                           0), &UDPSocket, "UDP Server Socket", NX_IP_NORMAL, NX_FRAGMENT_OKAY, NX_IP_TIME_TO_LIVE,
                               QUEUE_MAX_SIZE);

    if (ret != NX_SUCCESS)
    {
//        printf("nx_udp_socket_create return error: %x\n", ret);
        return CY_RSLT_ERROR;
    }

    /* bind the socket indefinitely on the required port */
    ret = nx_udp_socket_bind(&UDPSocket, DEFAULT_PORT, TX_WAIT_FOREVER);

    if (ret != NX_SUCCESS)
    {
//        printf("nx_udp_socket_bind return error: %x\n", ret);
        return CY_RSLT_ERROR;
    }
    else
    {
//        printf("UDP Server listening on PORT %d.. \n", DEFAULT_PORT);
    }

    while (1)
    {
        TX_MEMSET(data_buffer, '\0', sizeof(data_buffer));

        /* wait for data for 1 sec */
        ret = nx_udp_socket_receive(&UDPSocket, &data_packet, 100);

        if (ret == NX_SUCCESS)
        {
            /* data is available, read it into the data buffer */
            nx_packet_data_retrieve(data_packet, data_buffer, &bytes_read);

            /* get info about the client address and port */
            nx_udp_source_extract(data_packet, &source_ip_address, &source_port);

            /* print the client address, the remote port and the received data */
//            PRINT_DATA(source_ip_address, source_port, data_buffer);

            /* resend the same packet to the client */
            ret =  nx_udp_socket_send(&UDPSocket, data_packet, source_ip_address, source_port);
        }
    }
}



/* USER CODE END PFP */

/**
  * @brief  Application NetXDuo Initialization.
  * @param memory_ptr: memory pointer
  * @retval int
  */
UINT MX_NetXDuo_Init(VOID *memory_ptr)
{
  UINT ret = NX_SUCCESS;
  TX_BYTE_POOL *byte_pool = (TX_BYTE_POOL*)memory_ptr;

   /* USER CODE BEGIN App_NetXDuo_MEM_POOL */
  (void)byte_pool;
  /* USER CODE END App_NetXDuo_MEM_POOL */
  /* USER CODE BEGIN 0 */

  /* USER CODE END 0 */

  /* USER CODE BEGIN MX_NetXDuo_Init */
  /* Allocate the main thread pool. */
     ret = tx_byte_allocate(byte_pool, (VOID**)&pointer, 2 * DEFAULT_MEMORY_SIZE, TX_NO_WAIT);

     if (ret != TX_SUCCESS)
     {
         return NX_NOT_ENABLED;
     }

     /* Create the main thread */
     ret = tx_thread_create(&AppMainThread, "App Main thread", application_start, 0, pointer,
                            2 * DEFAULT_MEMORY_SIZE,
                            DEFAULT_PRIORITY, DEFAULT_PRIORITY, TX_NO_TIME_SLICE, TX_AUTO_START);

     if (ret != TX_SUCCESS)
     {
         return NX_NOT_ENABLED;
     }
  /* USER CODE END MX_NetXDuo_Init */

  return ret;
}

/* USER CODE BEGIN 1 */
void application_start(ULONG id)
{
    /* \x1b[2J\x1b[;H - ANSI ESC sequence to clear screen. */
    //printf("\x1b[2J\x1b[;H");
//    printf("===============================================================\n");
//    printf("    ThreadX NetXDuo Example Program\n");
//    printf("===============================================================\n\n");


    if (test_connect_ap() != CY_RSLT_SUCCESS)
    {
//        printf("Error connecting to AP\n");
        return;
    }

    if (test_ping() != CY_RSLT_SUCCESS)
    {
//        printf("Error in ping test\n");
        return;
    }

    if (test_run_udp_server() != CY_RSLT_SUCCESS)
    {
//        printf("Error in run_udp_server test\n");
        return;
    }

    while (1)
    {
        cy_rtos_delay_milliseconds(LED_BLINK_PERIOD);
    }
}


/* USER CODE END 1 */
