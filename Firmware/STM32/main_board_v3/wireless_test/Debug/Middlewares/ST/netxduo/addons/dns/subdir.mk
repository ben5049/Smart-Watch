################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/ST/netxduo/addons/dns/nxd_dns.c 

OBJS += \
./Middlewares/ST/netxduo/addons/dns/nxd_dns.o 

C_DEPS += \
./Middlewares/ST/netxduo/addons/dns/nxd_dns.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/ST/netxduo/addons/dns/%.o Middlewares/ST/netxduo/addons/dns/%.su Middlewares/ST/netxduo/addons/dns/%.cyclo: ../Middlewares/ST/netxduo/addons/dns/%.c Middlewares/ST/netxduo/addons/dns/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DTX_INCLUDE_USER_DEFINE_FILE -DTX_SINGLE_MODE_NON_SECURE=1 -DUSE_HAL_DRIVER -DSTM32U5G9xx -DNX_INCLUDE_USER_DEFINE_FILE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"Middlewares/ST/netxduo/addons/dns/nxd_dns.c_includes.args"

clean: clean-Middlewares-2f-ST-2f-netxduo-2f-addons-2f-dns

clean-Middlewares-2f-ST-2f-netxduo-2f-addons-2f-dns:
	-$(RM) ./Middlewares/ST/netxduo/addons/dns/nxd_dns.cyclo ./Middlewares/ST/netxduo/addons/dns/nxd_dns.d ./Middlewares/ST/netxduo/addons/dns/nxd_dns.o ./Middlewares/ST/netxduo/addons/dns/nxd_dns.su

.PHONY: clean-Middlewares-2f-ST-2f-netxduo-2f-addons-2f-dns
