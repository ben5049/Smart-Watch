################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/common/Src/cyhal_system.c \
../Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/common/Src/wifi_bt_if.c 

OBJS += \
./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/common/Src/cyhal_system.o \
./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/common/Src/wifi_bt_if.o 

C_DEPS += \
./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/common/Src/cyhal_system.d \
./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/common/Src/wifi_bt_if.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/common/Src/%.o Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/common/Src/%.su Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/common/Src/%.cyclo: ../Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/common/Src/%.c Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/common/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DTX_INCLUDE_USER_DEFINE_FILE -DTX_SINGLE_MODE_NON_SECURE=1 -DUSE_HAL_DRIVER -DSTM32U5G9xx -DNX_INCLUDE_USER_DEFINE_FILE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/common/Src/cyhal_system.c_includes.args"

clean: clean-Middlewares-2f-Third_Party-2f-Infineon_Wireless_Connectivity-2f-pal-2f-common-2f-Src

clean-Middlewares-2f-Third_Party-2f-Infineon_Wireless_Connectivity-2f-pal-2f-common-2f-Src:
	-$(RM) ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/common/Src/cyhal_system.cyclo ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/common/Src/cyhal_system.d ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/common/Src/cyhal_system.o ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/common/Src/cyhal_system.su ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/common/Src/wifi_bt_if.cyclo ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/common/Src/wifi_bt_if.d ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/common/Src/wifi_bt_if.o ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/common/Src/wifi_bt_if.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-Infineon_Wireless_Connectivity-2f-pal-2f-common-2f-Src

