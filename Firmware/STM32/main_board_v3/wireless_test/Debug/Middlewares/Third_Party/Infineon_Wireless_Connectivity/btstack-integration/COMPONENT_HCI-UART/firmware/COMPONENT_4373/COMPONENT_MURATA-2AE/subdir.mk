################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/firmware/COMPONENT_4373/COMPONENT_MURATA-2AE/w_bt_firmware_controller.c 

OBJS += \
./Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/firmware/COMPONENT_4373/COMPONENT_MURATA-2AE/w_bt_firmware_controller.o 

C_DEPS += \
./Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/firmware/COMPONENT_4373/COMPONENT_MURATA-2AE/w_bt_firmware_controller.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/firmware/COMPONENT_4373/COMPONENT_MURATA-2AE/%.o Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/firmware/COMPONENT_4373/COMPONENT_MURATA-2AE/%.su Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/firmware/COMPONENT_4373/COMPONENT_MURATA-2AE/%.cyclo: ../Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/firmware/COMPONENT_4373/COMPONENT_MURATA-2AE/%.c Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/firmware/COMPONENT_4373/COMPONENT_MURATA-2AE/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DTX_INCLUDE_USER_DEFINE_FILE -DTX_SINGLE_MODE_NON_SECURE=1 -DUSE_HAL_DRIVER -DSTM32U5G9xx -DNX_INCLUDE_USER_DEFINE_FILE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/firmware/COMPONENT_4373/COMPONENT_MURATA-2AE/w_bt_firmware_controller.c_includes.args"

clean: clean-Middlewares-2f-Third_Party-2f-Infineon_Wireless_Connectivity-2f-btstack-2d-integration-2f-COMPONENT_HCI-2d-UART-2f-firmware-2f-COMPONENT_4373-2f-COMPONENT_MURATA-2d-2AE

clean-Middlewares-2f-Third_Party-2f-Infineon_Wireless_Connectivity-2f-btstack-2d-integration-2f-COMPONENT_HCI-2d-UART-2f-firmware-2f-COMPONENT_4373-2f-COMPONENT_MURATA-2d-2AE:
	-$(RM) ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/firmware/COMPONENT_4373/COMPONENT_MURATA-2AE/w_bt_firmware_controller.cyclo ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/firmware/COMPONENT_4373/COMPONENT_MURATA-2AE/w_bt_firmware_controller.d ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/firmware/COMPONENT_4373/COMPONENT_MURATA-2AE/w_bt_firmware_controller.o ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/firmware/COMPONENT_4373/COMPONENT_MURATA-2AE/w_bt_firmware_controller.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-Infineon_Wireless_Connectivity-2f-btstack-2d-integration-2f-COMPONENT_HCI-2d-UART-2f-firmware-2f-COMPONENT_4373-2f-COMPONENT_MURATA-2d-2AE

