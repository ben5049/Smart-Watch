################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Core/Startup/startup_stm32g071g8ux.s 

OBJS += \
./Core/Startup/startup_stm32g071g8ux.o 

S_DEPS += \
./Core/Startup/startup_stm32g071g8ux.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Startup/%.o: ../Core/Startup/%.s Core/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m0plus -g3 -DDEBUG -c -I"C:/Users/bens1/Documents/Other/Projects/Smart-Watch/Firmware/STM32/rfid_module_firmware/Application" -I"C:/Users/bens1/Documents/Other/Projects/Smart-Watch/Firmware/STM32/rfid_module_firmware/Application/Inc" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"

clean: clean-Core-2f-Startup

clean-Core-2f-Startup:
	-$(RM) ./Core/Startup/startup_stm32g071g8ux.d ./Core/Startup/startup_stm32g071g8ux.o

.PHONY: clean-Core-2f-Startup
