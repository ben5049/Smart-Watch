################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../TouchGFX/target/generated/OSWrappers.cpp \
../TouchGFX/target/generated/STM32DMA.cpp \
../TouchGFX/target/generated/TouchGFXConfiguration.cpp \
../TouchGFX/target/generated/TouchGFXGeneratedHAL.cpp 

C_SRCS += \
../TouchGFX/target/generated/nema_hal.c 

C_DEPS += \
./TouchGFX/target/generated/nema_hal.d 

OBJS += \
./TouchGFX/target/generated/OSWrappers.o \
./TouchGFX/target/generated/STM32DMA.o \
./TouchGFX/target/generated/TouchGFXConfiguration.o \
./TouchGFX/target/generated/TouchGFXGeneratedHAL.o \
./TouchGFX/target/generated/nema_hal.o 

CPP_DEPS += \
./TouchGFX/target/generated/OSWrappers.d \
./TouchGFX/target/generated/STM32DMA.d \
./TouchGFX/target/generated/TouchGFXConfiguration.d \
./TouchGFX/target/generated/TouchGFXGeneratedHAL.d 


# Each subdirectory must supply rules for building sources it contributes
TouchGFX/target/generated/%.o TouchGFX/target/generated/%.su TouchGFX/target/generated/%.cyclo: ../TouchGFX/target/generated/%.cpp TouchGFX/target/generated/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m33 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U5A9xx -DTX_INCLUDE_USER_DEFINE_FILE -DTX_SINGLE_MODE_NON_SECURE=1 -c -I../Core/Inc -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../Drivers/STM32U5xx_HAL_Driver/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/bens1/Documents/Other/Projects/Smart-Watch/Firmware/STM32/libraries/Inc" -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/generated/videos/include -I../TouchGFX/gui/include -I../AZURE_RTOS/App -I../Middlewares/ST/threadx/common/inc -I../Middlewares/ST/threadx/ports/cortex_m33/gnu/inc -I../Middlewares/ST/touchgfx_components/gpu2d/NemaGFX/include -I../Middlewares/ST/touchgfx_components/gpu2d/TouchGFXNema/include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
TouchGFX/target/generated/%.o TouchGFX/target/generated/%.su TouchGFX/target/generated/%.cyclo: ../TouchGFX/target/generated/%.c TouchGFX/target/generated/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U5A9xx -DTX_INCLUDE_USER_DEFINE_FILE -DTX_SINGLE_MODE_NON_SECURE=1 -c -I../Core/Inc -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../Drivers/STM32U5xx_HAL_Driver/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/bens1/Documents/Other/Projects/Smart-Watch/Firmware/STM32/libraries/Inc" -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/generated/videos/include -I../TouchGFX/gui/include -I../AZURE_RTOS/App -I../Middlewares/ST/threadx/common/inc -I../Middlewares/ST/threadx/ports/cortex_m33/gnu/inc -I../Middlewares/ST/touchgfx_components/gpu2d/NemaGFX/include -I../Middlewares/ST/touchgfx_components/gpu2d/TouchGFXNema/include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-TouchGFX-2f-target-2f-generated

clean-TouchGFX-2f-target-2f-generated:
	-$(RM) ./TouchGFX/target/generated/OSWrappers.cyclo ./TouchGFX/target/generated/OSWrappers.d ./TouchGFX/target/generated/OSWrappers.o ./TouchGFX/target/generated/OSWrappers.su ./TouchGFX/target/generated/STM32DMA.cyclo ./TouchGFX/target/generated/STM32DMA.d ./TouchGFX/target/generated/STM32DMA.o ./TouchGFX/target/generated/STM32DMA.su ./TouchGFX/target/generated/TouchGFXConfiguration.cyclo ./TouchGFX/target/generated/TouchGFXConfiguration.d ./TouchGFX/target/generated/TouchGFXConfiguration.o ./TouchGFX/target/generated/TouchGFXConfiguration.su ./TouchGFX/target/generated/TouchGFXGeneratedHAL.cyclo ./TouchGFX/target/generated/TouchGFXGeneratedHAL.d ./TouchGFX/target/generated/TouchGFXGeneratedHAL.o ./TouchGFX/target/generated/TouchGFXGeneratedHAL.su ./TouchGFX/target/generated/nema_hal.cyclo ./TouchGFX/target/generated/nema_hal.d ./TouchGFX/target/generated/nema_hal.o ./TouchGFX/target/generated/nema_hal.su

.PHONY: clean-TouchGFX-2f-target-2f-generated

