################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/ST/netxduo/addons/auto_ip/nx_auto_ip.c 

OBJS += \
./Middlewares/ST/netxduo/addons/auto_ip/nx_auto_ip.o 

C_DEPS += \
./Middlewares/ST/netxduo/addons/auto_ip/nx_auto_ip.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/ST/netxduo/addons/auto_ip/%.o Middlewares/ST/netxduo/addons/auto_ip/%.su Middlewares/ST/netxduo/addons/auto_ip/%.cyclo: ../Middlewares/ST/netxduo/addons/auto_ip/%.c Middlewares/ST/netxduo/addons/auto_ip/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DTX_INCLUDE_USER_DEFINE_FILE -DTX_SINGLE_MODE_NON_SECURE=1 -DUSE_HAL_DRIVER -DSTM32U5G9xx -DNX_INCLUDE_USER_DEFINE_FILE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"Middlewares/ST/netxduo/addons/auto_ip/nx_auto_ip.c_includes.args"

clean: clean-Middlewares-2f-ST-2f-netxduo-2f-addons-2f-auto_ip

clean-Middlewares-2f-ST-2f-netxduo-2f-addons-2f-auto_ip:
	-$(RM) ./Middlewares/ST/netxduo/addons/auto_ip/nx_auto_ip.cyclo ./Middlewares/ST/netxduo/addons/auto_ip/nx_auto_ip.d ./Middlewares/ST/netxduo/addons/auto_ip/nx_auto_ip.o ./Middlewares/ST/netxduo/addons/auto_ip/nx_auto_ip.su

.PHONY: clean-Middlewares-2f-ST-2f-netxduo-2f-addons-2f-auto_ip

