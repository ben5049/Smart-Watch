################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Middlewares/ST/touchgfx/framework/source/platform/driver/touch/SDL2TouchController.cpp 

OBJS += \
./Middlewares/ST/touchgfx/framework/source/platform/driver/touch/SDL2TouchController.o 

CPP_DEPS += \
./Middlewares/ST/touchgfx/framework/source/platform/driver/touch/SDL2TouchController.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/ST/touchgfx/framework/source/platform/driver/touch/%.o Middlewares/ST/touchgfx/framework/source/platform/driver/touch/%.su Middlewares/ST/touchgfx/framework/source/platform/driver/touch/%.cyclo: ../Middlewares/ST/touchgfx/framework/source/platform/driver/touch/%.cpp Middlewares/ST/touchgfx/framework/source/platform/driver/touch/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m33 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U5G9xx -DTX_INCLUDE_USER_DEFINE_FILE -DTX_SINGLE_MODE_NON_SECURE=1 -c -I../Core/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../Drivers/CMSIS/Include -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../AZURE_RTOS/App -I../Middlewares/ST/threadx/common/inc -I../Middlewares/ST/threadx/ports/cortex_m33/gnu/inc -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-ST-2f-touchgfx-2f-framework-2f-source-2f-platform-2f-driver-2f-touch

clean-Middlewares-2f-ST-2f-touchgfx-2f-framework-2f-source-2f-platform-2f-driver-2f-touch:
	-$(RM) ./Middlewares/ST/touchgfx/framework/source/platform/driver/touch/SDL2TouchController.cyclo ./Middlewares/ST/touchgfx/framework/source/platform/driver/touch/SDL2TouchController.d ./Middlewares/ST/touchgfx/framework/source/platform/driver/touch/SDL2TouchController.o ./Middlewares/ST/touchgfx/framework/source/platform/driver/touch/SDL2TouchController.su

.PHONY: clean-Middlewares-2f-ST-2f-touchgfx-2f-framework-2f-source-2f-platform-2f-driver-2f-touch

