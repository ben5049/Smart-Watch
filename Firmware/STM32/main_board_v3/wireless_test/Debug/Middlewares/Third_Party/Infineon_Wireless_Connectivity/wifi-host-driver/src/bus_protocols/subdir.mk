################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-host-driver/src/bus_protocols/whd_bus.c \
../Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-host-driver/src/bus_protocols/whd_bus_common.c \
../Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-host-driver/src/bus_protocols/whd_bus_sdio_protocol.c \
../Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-host-driver/src/bus_protocols/whd_bus_spi_protocol.c 

OBJS += \
./Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-host-driver/src/bus_protocols/whd_bus.o \
./Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-host-driver/src/bus_protocols/whd_bus_common.o \
./Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-host-driver/src/bus_protocols/whd_bus_sdio_protocol.o \
./Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-host-driver/src/bus_protocols/whd_bus_spi_protocol.o 

C_DEPS += \
./Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-host-driver/src/bus_protocols/whd_bus.d \
./Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-host-driver/src/bus_protocols/whd_bus_common.d \
./Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-host-driver/src/bus_protocols/whd_bus_sdio_protocol.d \
./Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-host-driver/src/bus_protocols/whd_bus_spi_protocol.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-host-driver/src/bus_protocols/%.o Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-host-driver/src/bus_protocols/%.su Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-host-driver/src/bus_protocols/%.cyclo: ../Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-host-driver/src/bus_protocols/%.c Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-host-driver/src/bus_protocols/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DTX_INCLUDE_USER_DEFINE_FILE -DTX_SINGLE_MODE_NON_SECURE=1 -DUSE_HAL_DRIVER -DSTM32U5G9xx -DNX_INCLUDE_USER_DEFINE_FILE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-host-driver/src/bus_protocols/whd_bus.c_includes.args"

clean: clean-Middlewares-2f-Third_Party-2f-Infineon_Wireless_Connectivity-2f-wifi-2d-host-2d-driver-2f-src-2f-bus_protocols

clean-Middlewares-2f-Third_Party-2f-Infineon_Wireless_Connectivity-2f-wifi-2d-host-2d-driver-2f-src-2f-bus_protocols:
	-$(RM) ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-host-driver/src/bus_protocols/whd_bus.cyclo ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-host-driver/src/bus_protocols/whd_bus.d ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-host-driver/src/bus_protocols/whd_bus.o ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-host-driver/src/bus_protocols/whd_bus.su ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-host-driver/src/bus_protocols/whd_bus_common.cyclo ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-host-driver/src/bus_protocols/whd_bus_common.d ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-host-driver/src/bus_protocols/whd_bus_common.o ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-host-driver/src/bus_protocols/whd_bus_common.su ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-host-driver/src/bus_protocols/whd_bus_sdio_protocol.cyclo ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-host-driver/src/bus_protocols/whd_bus_sdio_protocol.d ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-host-driver/src/bus_protocols/whd_bus_sdio_protocol.o ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-host-driver/src/bus_protocols/whd_bus_sdio_protocol.su ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-host-driver/src/bus_protocols/whd_bus_spi_protocol.cyclo ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-host-driver/src/bus_protocols/whd_bus_spi_protocol.d ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-host-driver/src/bus_protocols/whd_bus_spi_protocol.o ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-host-driver/src/bus_protocols/whd_bus_spi_protocol.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-Infineon_Wireless_Connectivity-2f-wifi-2d-host-2d-driver-2f-src-2f-bus_protocols

