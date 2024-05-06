################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/Infineon_Wireless_Connectivity/connectivity-utilities/cy_log/cy_log.c 

OBJS += \
./Middlewares/Third_Party/Infineon_Wireless_Connectivity/connectivity-utilities/cy_log/cy_log.o 

C_DEPS += \
./Middlewares/Third_Party/Infineon_Wireless_Connectivity/connectivity-utilities/cy_log/cy_log.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/Infineon_Wireless_Connectivity/connectivity-utilities/cy_log/%.o Middlewares/Third_Party/Infineon_Wireless_Connectivity/connectivity-utilities/cy_log/%.su Middlewares/Third_Party/Infineon_Wireless_Connectivity/connectivity-utilities/cy_log/%.cyclo: ../Middlewares/Third_Party/Infineon_Wireless_Connectivity/connectivity-utilities/cy_log/%.c Middlewares/Third_Party/Infineon_Wireless_Connectivity/connectivity-utilities/cy_log/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DTX_INCLUDE_USER_DEFINE_FILE -DTX_SINGLE_MODE_NON_SECURE=1 -DUSE_HAL_DRIVER -DSTM32U5G9xx -DNX_INCLUDE_USER_DEFINE_FILE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"Middlewares/Third_Party/Infineon_Wireless_Connectivity/connectivity-utilities/cy_log/cy_log.c_includes.args"

clean: clean-Middlewares-2f-Third_Party-2f-Infineon_Wireless_Connectivity-2f-connectivity-2d-utilities-2f-cy_log

clean-Middlewares-2f-Third_Party-2f-Infineon_Wireless_Connectivity-2f-connectivity-2d-utilities-2f-cy_log:
	-$(RM) ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/connectivity-utilities/cy_log/cy_log.cyclo ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/connectivity-utilities/cy_log/cy_log.d ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/connectivity-utilities/cy_log/cy_log.o ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/connectivity-utilities/cy_log/cy_log.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-Infineon_Wireless_Connectivity-2f-connectivity-2d-utilities-2f-cy_log

