################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/Components/teseo_liv3f/teseo_liv3f.c \
../Drivers/BSP/Components/teseo_liv3f/teseo_liv3f_i2c.c \
../Drivers/BSP/Components/teseo_liv3f/teseo_liv3f_queue.c \
../Drivers/BSP/Components/teseo_liv3f/teseo_liv3f_uart.c 

C_DEPS += \
./Drivers/BSP/Components/teseo_liv3f/teseo_liv3f.d \
./Drivers/BSP/Components/teseo_liv3f/teseo_liv3f_i2c.d \
./Drivers/BSP/Components/teseo_liv3f/teseo_liv3f_queue.d \
./Drivers/BSP/Components/teseo_liv3f/teseo_liv3f_uart.d 

OBJS += \
./Drivers/BSP/Components/teseo_liv3f/teseo_liv3f.o \
./Drivers/BSP/Components/teseo_liv3f/teseo_liv3f_i2c.o \
./Drivers/BSP/Components/teseo_liv3f/teseo_liv3f_queue.o \
./Drivers/BSP/Components/teseo_liv3f/teseo_liv3f_uart.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/Components/teseo_liv3f/%.o Drivers/BSP/Components/teseo_liv3f/%.su Drivers/BSP/Components/teseo_liv3f/%.cyclo: ../Drivers/BSP/Components/teseo_liv3f/%.c Drivers/BSP/Components/teseo_liv3f/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DFX_INCLUDE_USER_DEFINE_FILE -DTX_INCLUDE_USER_DEFINE_FILE -DTX_SINGLE_MODE_NON_SECURE=1 -DUSE_HAL_DRIVER -DSTM32U5A9xx -c -I../FileX/App -I../FileX/Target -I../Core/Inc -I../GNSS/Target -I../X-CUBE-ISPU/Target -I../X-CUBE-MEMS1/Target -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../AZURE_RTOS/App -I../Drivers/STM32U5xx_HAL_Driver/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/threadx/common/inc -I../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../Middlewares/ST/filex/common/inc -I../Middlewares/ST/filex/ports/generic/inc -I../Middlewares/ST/threadx/ports/cortex_m33/gnu/inc -I../Drivers/CMSIS/Include -I../Drivers/BSP/Components/iis2mdc -I../Middlewares/ST/lib_gnss/LibGNSS/Inc -I../Middlewares/ST/lib_gnss/LibNMEA/Inc -I../Drivers/BSP/Components/teseo_liv3f -I../Drivers/BSP/Components/M24xx -I../Drivers/BSP/Components/lsm6dso16is -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-Components-2f-teseo_liv3f

clean-Drivers-2f-BSP-2f-Components-2f-teseo_liv3f:
	-$(RM) ./Drivers/BSP/Components/teseo_liv3f/teseo_liv3f.cyclo ./Drivers/BSP/Components/teseo_liv3f/teseo_liv3f.d ./Drivers/BSP/Components/teseo_liv3f/teseo_liv3f.o ./Drivers/BSP/Components/teseo_liv3f/teseo_liv3f.su ./Drivers/BSP/Components/teseo_liv3f/teseo_liv3f_i2c.cyclo ./Drivers/BSP/Components/teseo_liv3f/teseo_liv3f_i2c.d ./Drivers/BSP/Components/teseo_liv3f/teseo_liv3f_i2c.o ./Drivers/BSP/Components/teseo_liv3f/teseo_liv3f_i2c.su ./Drivers/BSP/Components/teseo_liv3f/teseo_liv3f_queue.cyclo ./Drivers/BSP/Components/teseo_liv3f/teseo_liv3f_queue.d ./Drivers/BSP/Components/teseo_liv3f/teseo_liv3f_queue.o ./Drivers/BSP/Components/teseo_liv3f/teseo_liv3f_queue.su ./Drivers/BSP/Components/teseo_liv3f/teseo_liv3f_uart.cyclo ./Drivers/BSP/Components/teseo_liv3f/teseo_liv3f_uart.d ./Drivers/BSP/Components/teseo_liv3f/teseo_liv3f_uart.o ./Drivers/BSP/Components/teseo_liv3f/teseo_liv3f_uart.su

.PHONY: clean-Drivers-2f-BSP-2f-Components-2f-teseo_liv3f

