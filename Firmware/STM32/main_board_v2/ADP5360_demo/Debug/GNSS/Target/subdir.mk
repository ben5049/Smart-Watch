################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../GNSS/Target/gnss_lib_config.c 

C_DEPS += \
./GNSS/Target/gnss_lib_config.d 

OBJS += \
./GNSS/Target/gnss_lib_config.o 


# Each subdirectory must supply rules for building sources it contributes
GNSS/Target/%.o GNSS/Target/%.su GNSS/Target/%.cyclo: ../GNSS/Target/%.c GNSS/Target/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DFX_INCLUDE_USER_DEFINE_FILE -DTX_INCLUDE_USER_DEFINE_FILE -DTX_SINGLE_MODE_NON_SECURE=1 -DUSE_HAL_DRIVER -DSTM32U5A9xx -c -I../FileX/App -I../FileX/Target -I../Core/Inc -I../GNSS/Target -I../X-CUBE-ISPU/Target -I../X-CUBE-MEMS1/Target -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../AZURE_RTOS/App -I../Drivers/STM32U5xx_HAL_Driver/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/threadx/common/inc -I../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../Middlewares/ST/filex/common/inc -I../Middlewares/ST/filex/ports/generic/inc -I../Middlewares/ST/threadx/ports/cortex_m33/gnu/inc -I../Drivers/CMSIS/Include -I../Drivers/BSP/Components/iis2mdc -I../Middlewares/ST/lib_gnss/LibGNSS/Inc -I../Middlewares/ST/lib_gnss/LibNMEA/Inc -I../Drivers/BSP/Components/teseo_liv3f -I../Drivers/BSP/Components/M24xx -I../Drivers/BSP/Components/lsm6dso16is -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-GNSS-2f-Target

clean-GNSS-2f-Target:
	-$(RM) ./GNSS/Target/gnss_lib_config.cyclo ./GNSS/Target/gnss_lib_config.d ./GNSS/Target/gnss_lib_config.o ./GNSS/Target/gnss_lib_config.su

.PHONY: clean-GNSS-2f-Target

