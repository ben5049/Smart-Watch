################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../NetXDuo/App/app_netxduo.c 

OBJS += \
./NetXDuo/App/app_netxduo.o 

C_DEPS += \
./NetXDuo/App/app_netxduo.d 


# Each subdirectory must supply rules for building sources it contributes
NetXDuo/App/%.o NetXDuo/App/%.su NetXDuo/App/%.cyclo: ../NetXDuo/App/%.c NetXDuo/App/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DTX_INCLUDE_USER_DEFINE_FILE -DTX_SINGLE_MODE_NON_SECURE=1 -DUSE_HAL_DRIVER -DSTM32U5G9xx -DNX_INCLUDE_USER_DEFINE_FILE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"NetXDuo/App/app_netxduo.c_includes.args"

clean: clean-NetXDuo-2f-App

clean-NetXDuo-2f-App:
	-$(RM) ./NetXDuo/App/app_netxduo.cyclo ./NetXDuo/App/app_netxduo.d ./NetXDuo/App/app_netxduo.o ./NetXDuo/App/app_netxduo.su

.PHONY: clean-NetXDuo-2f-App

