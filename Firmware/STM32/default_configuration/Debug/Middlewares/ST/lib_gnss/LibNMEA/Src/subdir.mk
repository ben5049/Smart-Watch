################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/ST/lib_gnss/LibNMEA/Src/NMEA_parser.c 

C_DEPS += \
./Middlewares/ST/lib_gnss/LibNMEA/Src/NMEA_parser.d 

OBJS += \
./Middlewares/ST/lib_gnss/LibNMEA/Src/NMEA_parser.o 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/ST/lib_gnss/LibNMEA/Src/%.o Middlewares/ST/lib_gnss/LibNMEA/Src/%.su Middlewares/ST/lib_gnss/LibNMEA/Src/%.cyclo: ../Middlewares/ST/lib_gnss/LibNMEA/Src/%.c Middlewares/ST/lib_gnss/LibNMEA/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DFX_INCLUDE_USER_DEFINE_FILE -DLX_INCLUDE_USER_DEFINE_FILE -DTX_INCLUDE_USER_DEFINE_FILE -DTX_SINGLE_MODE_NON_SECURE=1 -DUSE_HAL_DRIVER -DSTM32U5A9xx -c -I../FileX/App -I../FileX/Target -I../Core/Inc -I../LevelX/App -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../AZURE_RTOS/App -I../Drivers/STM32U5xx_HAL_Driver/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/threadx/common/inc -I../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../Middlewares/ST/filex/common/inc -I../Middlewares/ST/filex/ports/generic/inc -I../Middlewares/ST/levelx/common/inc -I../Middlewares/ST/threadx/ports/cortex_m33/gnu/inc -I../Drivers/CMSIS/Include -I../GNSS/Target -I../X-CUBE-ISPU/Target -I../Drivers/BSP/Components/lsm6dso16is -I../Middlewares/ST/lib_gnss/LibGNSS/Inc -I../Middlewares/ST/lib_gnss/LibNMEA/Inc -I../Middlewares/ST/lib_gnss/Template -I../Drivers/BSP/Components/teseo_liv3f -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/generated/videos/include -I../TouchGFX/gui/include -I../Middlewares/ST/touchgfx_components/gpu2d/NemaGFX/include -I../Middlewares/ST/touchgfx_components/gpu2d/TouchGFXNema/include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-ST-2f-lib_gnss-2f-LibNMEA-2f-Src

clean-Middlewares-2f-ST-2f-lib_gnss-2f-LibNMEA-2f-Src:
	-$(RM) ./Middlewares/ST/lib_gnss/LibNMEA/Src/NMEA_parser.cyclo ./Middlewares/ST/lib_gnss/LibNMEA/Src/NMEA_parser.d ./Middlewares/ST/lib_gnss/LibNMEA/Src/NMEA_parser.o ./Middlewares/ST/lib_gnss/LibNMEA/Src/NMEA_parser.su

.PHONY: clean-Middlewares-2f-ST-2f-lib_gnss-2f-LibNMEA-2f-Src

