################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/bens1/OneDrive/Documents/Projects/Smart-Watch/Firmware/STM32/libraries/Src/ADP5360.c 

C_DEPS += \
./libraries/Src/ADP5360.d 

OBJS += \
./libraries/Src/ADP5360.o 


# Each subdirectory must supply rules for building sources it contributes
libraries/Src/ADP5360.o: C:/Users/bens1/OneDrive/Documents/Projects/Smart-Watch/Firmware/STM32/libraries/Src/ADP5360.c libraries/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U5A9xx -c -I../Core/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/bens1/OneDrive/Documents/Projects/Smart-Watch/Firmware/STM32/libraries/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-libraries-2f-Src

clean-libraries-2f-Src:
	-$(RM) ./libraries/Src/ADP5360.cyclo ./libraries/Src/ADP5360.d ./libraries/Src/ADP5360.o ./libraries/Src/ADP5360.su

.PHONY: clean-libraries-2f-Src

