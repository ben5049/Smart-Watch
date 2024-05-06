################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-host-driver/resources/resource_imp/whd_resources.c 

OBJS += \
./Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-host-driver/resources/resource_imp/whd_resources.o 

C_DEPS += \
./Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-host-driver/resources/resource_imp/whd_resources.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-host-driver/resources/resource_imp/%.o Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-host-driver/resources/resource_imp/%.su Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-host-driver/resources/resource_imp/%.cyclo: ../Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-host-driver/resources/resource_imp/%.c Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-host-driver/resources/resource_imp/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DTX_INCLUDE_USER_DEFINE_FILE -DTX_SINGLE_MODE_NON_SECURE=1 -DUSE_HAL_DRIVER -DSTM32U5G9xx -DNX_INCLUDE_USER_DEFINE_FILE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-host-driver/resources/resource_imp/whd_resources.c_includes.args"

clean: clean-Middlewares-2f-Third_Party-2f-Infineon_Wireless_Connectivity-2f-wifi-2d-host-2d-driver-2f-resources-2f-resource_imp

clean-Middlewares-2f-Third_Party-2f-Infineon_Wireless_Connectivity-2f-wifi-2d-host-2d-driver-2f-resources-2f-resource_imp:
	-$(RM) ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-host-driver/resources/resource_imp/whd_resources.cyclo ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-host-driver/resources/resource_imp/whd_resources.d ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-host-driver/resources/resource_imp/whd_resources.o ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-host-driver/resources/resource_imp/whd_resources.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-Infineon_Wireless_Connectivity-2f-wifi-2d-host-2d-driver-2f-resources-2f-resource_imp

