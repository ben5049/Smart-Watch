################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_hci_rx_task.c \
../Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_hci_tx_task.c \
../Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_host_stack_platform_interface.c \
../Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_patchram_download.c \
../Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_platform_main.c \
../Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_platform_task.c \
../Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_platform_trace.c \
../Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_prm.c 

OBJS += \
./Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_hci_rx_task.o \
./Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_hci_tx_task.o \
./Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_host_stack_platform_interface.o \
./Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_patchram_download.o \
./Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_platform_main.o \
./Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_platform_task.o \
./Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_platform_trace.o \
./Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_prm.o 

C_DEPS += \
./Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_hci_rx_task.d \
./Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_hci_tx_task.d \
./Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_host_stack_platform_interface.d \
./Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_patchram_download.d \
./Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_platform_main.d \
./Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_platform_task.d \
./Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_platform_trace.d \
./Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_prm.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/%.o Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/%.su Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/%.cyclo: ../Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/%.c Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DTX_INCLUDE_USER_DEFINE_FILE -DTX_SINGLE_MODE_NON_SECURE=1 -DUSE_HAL_DRIVER -DSTM32U5G9xx -DNX_INCLUDE_USER_DEFINE_FILE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_hci_rx_task.c_includes.args"

clean: clean-Middlewares-2f-Third_Party-2f-Infineon_Wireless_Connectivity-2f-btstack-2d-integration-2f-COMPONENT_HCI-2d-UART-2f-common

clean-Middlewares-2f-Third_Party-2f-Infineon_Wireless_Connectivity-2f-btstack-2d-integration-2f-COMPONENT_HCI-2d-UART-2f-common:
	-$(RM) ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_hci_rx_task.cyclo ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_hci_rx_task.d ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_hci_rx_task.o ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_hci_rx_task.su ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_hci_tx_task.cyclo ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_hci_tx_task.d ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_hci_tx_task.o ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_hci_tx_task.su ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_host_stack_platform_interface.cyclo ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_host_stack_platform_interface.d ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_host_stack_platform_interface.o ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_host_stack_platform_interface.su ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_patchram_download.cyclo ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_patchram_download.d ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_patchram_download.o ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_patchram_download.su ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_platform_main.cyclo ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_platform_main.d ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_platform_main.o ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_platform_main.su ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_platform_task.cyclo ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_platform_task.d ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_platform_task.o ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_platform_task.su ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_platform_trace.cyclo ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_platform_trace.d ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_platform_trace.o ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_platform_trace.su ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_prm.cyclo ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_prm.d ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_prm.o ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/cybt_prm.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-Infineon_Wireless_Connectivity-2f-btstack-2d-integration-2f-COMPONENT_HCI-2d-UART-2f-common

