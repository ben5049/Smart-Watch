################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-connection-manager/source/cy_wcm.c 

OBJS += \
./Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-connection-manager/source/cy_wcm.o 

C_DEPS += \
./Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-connection-manager/source/cy_wcm.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-connection-manager/source/%.o Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-connection-manager/source/%.su Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-connection-manager/source/%.cyclo: ../Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-connection-manager/source/%.c Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-connection-manager/source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DTX_INCLUDE_USER_DEFINE_FILE -DTX_SINGLE_MODE_NON_SECURE=1 -DUSE_HAL_DRIVER -DSTM32U5G9xx -DNX_INCLUDE_USER_DEFINE_FILE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-connection-manager/source/cy_wcm.c_includes.args"

clean: clean-Middlewares-2f-Third_Party-2f-Infineon_Wireless_Connectivity-2f-wifi-2d-connection-2d-manager-2f-source

clean-Middlewares-2f-Third_Party-2f-Infineon_Wireless_Connectivity-2f-wifi-2d-connection-2d-manager-2f-source:
	-$(RM) ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-connection-manager/source/cy_wcm.cyclo ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-connection-manager/source/cy_wcm.d ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-connection-manager/source/cy_wcm.o ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-connection-manager/source/cy_wcm.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-Infineon_Wireless_Connectivity-2f-wifi-2d-connection-2d-manager-2f-source

