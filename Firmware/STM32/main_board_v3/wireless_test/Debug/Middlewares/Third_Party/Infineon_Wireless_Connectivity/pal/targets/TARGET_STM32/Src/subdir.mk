################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/targets/TARGET_STM32/Src/stm32_cyhal_gpio.c \
../Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/targets/TARGET_STM32/Src/stm32_cyhal_lptimer.c \
../Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/targets/TARGET_STM32/Src/stm32_cyhal_sdio.c \
../Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/targets/TARGET_STM32/Src/stm32_cyhal_spi.c \
../Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/targets/TARGET_STM32/Src/stm32_cyhal_syspm.c \
../Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/targets/TARGET_STM32/Src/stm32_cyhal_trng.c \
../Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/targets/TARGET_STM32/Src/stm32_cyhal_uart.c 

OBJS += \
./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/targets/TARGET_STM32/Src/stm32_cyhal_gpio.o \
./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/targets/TARGET_STM32/Src/stm32_cyhal_lptimer.o \
./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/targets/TARGET_STM32/Src/stm32_cyhal_sdio.o \
./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/targets/TARGET_STM32/Src/stm32_cyhal_spi.o \
./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/targets/TARGET_STM32/Src/stm32_cyhal_syspm.o \
./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/targets/TARGET_STM32/Src/stm32_cyhal_trng.o \
./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/targets/TARGET_STM32/Src/stm32_cyhal_uart.o 

C_DEPS += \
./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/targets/TARGET_STM32/Src/stm32_cyhal_gpio.d \
./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/targets/TARGET_STM32/Src/stm32_cyhal_lptimer.d \
./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/targets/TARGET_STM32/Src/stm32_cyhal_sdio.d \
./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/targets/TARGET_STM32/Src/stm32_cyhal_spi.d \
./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/targets/TARGET_STM32/Src/stm32_cyhal_syspm.d \
./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/targets/TARGET_STM32/Src/stm32_cyhal_trng.d \
./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/targets/TARGET_STM32/Src/stm32_cyhal_uart.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/targets/TARGET_STM32/Src/%.o Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/targets/TARGET_STM32/Src/%.su Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/targets/TARGET_STM32/Src/%.cyclo: ../Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/targets/TARGET_STM32/Src/%.c Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/targets/TARGET_STM32/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DTX_INCLUDE_USER_DEFINE_FILE -DTX_SINGLE_MODE_NON_SECURE=1 -DUSE_HAL_DRIVER -DSTM32U5G9xx -DNX_INCLUDE_USER_DEFINE_FILE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/targets/TARGET_STM32/Src/stm32_cyhal_gpio.c_includes.args"

clean: clean-Middlewares-2f-Third_Party-2f-Infineon_Wireless_Connectivity-2f-pal-2f-targets-2f-TARGET_STM32-2f-Src

clean-Middlewares-2f-Third_Party-2f-Infineon_Wireless_Connectivity-2f-pal-2f-targets-2f-TARGET_STM32-2f-Src:
	-$(RM) ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/targets/TARGET_STM32/Src/stm32_cyhal_gpio.cyclo ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/targets/TARGET_STM32/Src/stm32_cyhal_gpio.d ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/targets/TARGET_STM32/Src/stm32_cyhal_gpio.o ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/targets/TARGET_STM32/Src/stm32_cyhal_gpio.su ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/targets/TARGET_STM32/Src/stm32_cyhal_lptimer.cyclo ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/targets/TARGET_STM32/Src/stm32_cyhal_lptimer.d ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/targets/TARGET_STM32/Src/stm32_cyhal_lptimer.o ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/targets/TARGET_STM32/Src/stm32_cyhal_lptimer.su ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/targets/TARGET_STM32/Src/stm32_cyhal_sdio.cyclo ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/targets/TARGET_STM32/Src/stm32_cyhal_sdio.d ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/targets/TARGET_STM32/Src/stm32_cyhal_sdio.o ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/targets/TARGET_STM32/Src/stm32_cyhal_sdio.su ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/targets/TARGET_STM32/Src/stm32_cyhal_spi.cyclo ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/targets/TARGET_STM32/Src/stm32_cyhal_spi.d ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/targets/TARGET_STM32/Src/stm32_cyhal_spi.o ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/targets/TARGET_STM32/Src/stm32_cyhal_spi.su ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/targets/TARGET_STM32/Src/stm32_cyhal_syspm.cyclo ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/targets/TARGET_STM32/Src/stm32_cyhal_syspm.d ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/targets/TARGET_STM32/Src/stm32_cyhal_syspm.o ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/targets/TARGET_STM32/Src/stm32_cyhal_syspm.su ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/targets/TARGET_STM32/Src/stm32_cyhal_trng.cyclo ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/targets/TARGET_STM32/Src/stm32_cyhal_trng.d ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/targets/TARGET_STM32/Src/stm32_cyhal_trng.o ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/targets/TARGET_STM32/Src/stm32_cyhal_trng.su ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/targets/TARGET_STM32/Src/stm32_cyhal_uart.cyclo ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/targets/TARGET_STM32/Src/stm32_cyhal_uart.d ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/targets/TARGET_STM32/Src/stm32_cyhal_uart.o ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/targets/TARGET_STM32/Src/stm32_cyhal_uart.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-Infineon_Wireless_Connectivity-2f-pal-2f-targets-2f-TARGET_STM32-2f-Src

