################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Middlewares/ST/touchgfx/os/OSWrappers.cpp \
../Middlewares/ST/touchgfx/os/OSWrappers_cmsis.cpp 

OBJS += \
./Middlewares/ST/touchgfx/os/OSWrappers.o \
./Middlewares/ST/touchgfx/os/OSWrappers_cmsis.o 

CPP_DEPS += \
./Middlewares/ST/touchgfx/os/OSWrappers.d \
./Middlewares/ST/touchgfx/os/OSWrappers_cmsis.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/ST/touchgfx/os/%.o Middlewares/ST/touchgfx/os/%.su Middlewares/ST/touchgfx/os/%.cyclo: ../Middlewares/ST/touchgfx/os/%.cpp Middlewares/ST/touchgfx/os/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m33 -std=gnu++14 -g3 -DDEBUG -DFX_INCLUDE_USER_DEFINE_FILE -DLX_INCLUDE_USER_DEFINE_FILE -DTX_INCLUDE_USER_DEFINE_FILE -DTX_SINGLE_MODE_NON_SECURE=1 -DUSE_HAL_DRIVER -DSTM32U5A9xx -c -I../FileX/App -I../FileX/Target -I../Core/Inc -I../LevelX/App -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../AZURE_RTOS/App -I../Drivers/STM32U5xx_HAL_Driver/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/threadx/common/inc -I../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../Middlewares/ST/filex/common/inc -I../Middlewares/ST/filex/ports/generic/inc -I../Middlewares/ST/levelx/common/inc -I../Middlewares/ST/threadx/ports/cortex_m33/gnu/inc -I../Drivers/CMSIS/Include -I../GNSS/Target -I../X-CUBE-ISPU/Target -I../Drivers/BSP/Components/lsm6dso16is -I../Middlewares/ST/lib_gnss/LibGNSS/Inc -I../Middlewares/ST/lib_gnss/LibNMEA/Inc -I../Middlewares/ST/lib_gnss/Template -I../Drivers/BSP/Components/teseo_liv3f -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-ST-2f-touchgfx-2f-os

clean-Middlewares-2f-ST-2f-touchgfx-2f-os:
	-$(RM) ./Middlewares/ST/touchgfx/os/OSWrappers.cyclo ./Middlewares/ST/touchgfx/os/OSWrappers.d ./Middlewares/ST/touchgfx/os/OSWrappers.o ./Middlewares/ST/touchgfx/os/OSWrappers.su ./Middlewares/ST/touchgfx/os/OSWrappers_cmsis.cyclo ./Middlewares/ST/touchgfx/os/OSWrappers_cmsis.d ./Middlewares/ST/touchgfx/os/OSWrappers_cmsis.o ./Middlewares/ST/touchgfx/os/OSWrappers_cmsis.su

.PHONY: clean-Middlewares-2f-ST-2f-touchgfx-2f-os
