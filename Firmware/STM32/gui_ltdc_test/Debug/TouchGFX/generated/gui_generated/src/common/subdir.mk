################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../TouchGFX/generated/gui_generated/src/common/FrontendApplicationBase.cpp 

OBJS += \
./TouchGFX/generated/gui_generated/src/common/FrontendApplicationBase.o 

CPP_DEPS += \
./TouchGFX/generated/gui_generated/src/common/FrontendApplicationBase.d 


# Each subdirectory must supply rules for building sources it contributes
TouchGFX/generated/gui_generated/src/common/%.o TouchGFX/generated/gui_generated/src/common/%.su TouchGFX/generated/gui_generated/src/common/%.cyclo: ../TouchGFX/generated/gui_generated/src/common/%.cpp TouchGFX/generated/gui_generated/src/common/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m33 -std=gnu++14 -g3 -DDEBUG -DTX_INCLUDE_USER_DEFINE_FILE -DTX_SINGLE_MODE_NON_SECURE=1 -DUSE_HAL_DRIVER -DSTM32U5G9xx -c -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../Core/Inc -I../AZURE_RTOS/App -I../Drivers/STM32U5xx_HAL_Driver/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/threadx/common/inc -I../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../Middlewares/ST/threadx/ports/cortex_m33/gnu/inc -I../Drivers/CMSIS/Include -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/generated/videos/include -I../TouchGFX/gui/include -I../Middlewares/ST/touchgfx_components/gpu2d/NemaGFX/include -I../Middlewares/ST/touchgfx_components/gpu2d/TouchGFXNema/include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-TouchGFX-2f-generated-2f-gui_generated-2f-src-2f-common

clean-TouchGFX-2f-generated-2f-gui_generated-2f-src-2f-common:
	-$(RM) ./TouchGFX/generated/gui_generated/src/common/FrontendApplicationBase.cyclo ./TouchGFX/generated/gui_generated/src/common/FrontendApplicationBase.d ./TouchGFX/generated/gui_generated/src/common/FrontendApplicationBase.o ./TouchGFX/generated/gui_generated/src/common/FrontendApplicationBase.su

.PHONY: clean-TouchGFX-2f-generated-2f-gui_generated-2f-src-2f-common

