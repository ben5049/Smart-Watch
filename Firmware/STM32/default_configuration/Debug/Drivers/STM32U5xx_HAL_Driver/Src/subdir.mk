################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal.c \
../Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_comp.c \
../Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_cortex.c \
../Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_crc.c \
../Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_crc_ex.c \
../Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_dcache.c \
../Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_dma.c \
../Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_dma2d.c \
../Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_dma_ex.c \
../Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_dsi.c \
../Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_exti.c \
../Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_flash.c \
../Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_flash_ex.c \
../Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_gfxmmu.c \
../Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_gpio.c \
../Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_gpu2d.c \
../Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_gtzc.c \
../Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_i2c.c \
../Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_i2c_ex.c \
../Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_icache.c \
../Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_ltdc.c \
../Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_ltdc_ex.c \
../Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_ospi.c \
../Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_pwr.c \
../Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_pwr_ex.c \
../Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_rcc.c \
../Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_rcc_ex.c \
../Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_sd.c \
../Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_sd_ex.c \
../Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_spi.c \
../Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_spi_ex.c \
../Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_tim.c \
../Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_tim_ex.c \
../Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_uart.c \
../Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_uart_ex.c \
../Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_xspi.c \
../Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_ll_dlyb.c \
../Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_ll_sdmmc.c 

C_DEPS += \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal.d \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_comp.d \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_cortex.d \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_crc.d \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_crc_ex.d \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_dcache.d \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_dma.d \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_dma2d.d \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_dma_ex.d \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_dsi.d \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_exti.d \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_flash.d \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_flash_ex.d \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_gfxmmu.d \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_gpio.d \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_gpu2d.d \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_gtzc.d \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_i2c.d \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_i2c_ex.d \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_icache.d \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_ltdc.d \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_ltdc_ex.d \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_ospi.d \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_pwr.d \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_pwr_ex.d \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_rcc.d \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_rcc_ex.d \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_sd.d \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_sd_ex.d \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_spi.d \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_spi_ex.d \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_tim.d \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_tim_ex.d \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_uart.d \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_uart_ex.d \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_xspi.d \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_ll_dlyb.d \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_ll_sdmmc.d 

OBJS += \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal.o \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_comp.o \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_cortex.o \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_crc.o \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_crc_ex.o \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_dcache.o \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_dma.o \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_dma2d.o \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_dma_ex.o \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_dsi.o \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_exti.o \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_flash.o \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_flash_ex.o \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_gfxmmu.o \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_gpio.o \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_gpu2d.o \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_gtzc.o \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_i2c.o \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_i2c_ex.o \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_icache.o \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_ltdc.o \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_ltdc_ex.o \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_ospi.o \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_pwr.o \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_pwr_ex.o \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_rcc.o \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_rcc_ex.o \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_sd.o \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_sd_ex.o \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_spi.o \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_spi_ex.o \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_tim.o \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_tim_ex.o \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_uart.o \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_uart_ex.o \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_xspi.o \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_ll_dlyb.o \
./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_ll_sdmmc.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/STM32U5xx_HAL_Driver/Src/%.o Drivers/STM32U5xx_HAL_Driver/Src/%.su Drivers/STM32U5xx_HAL_Driver/Src/%.cyclo: ../Drivers/STM32U5xx_HAL_Driver/Src/%.c Drivers/STM32U5xx_HAL_Driver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DFX_INCLUDE_USER_DEFINE_FILE -DLX_INCLUDE_USER_DEFINE_FILE -DTX_INCLUDE_USER_DEFINE_FILE -DTX_SINGLE_MODE_NON_SECURE=1 -DUSE_HAL_DRIVER -DSTM32U5A9xx -c -I../FileX/App -I../FileX/Target -I../Core/Inc -I../LevelX/App -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../AZURE_RTOS/App -I../Drivers/STM32U5xx_HAL_Driver/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/threadx/common/inc -I../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../Middlewares/ST/filex/common/inc -I../Middlewares/ST/filex/ports/generic/inc -I../Middlewares/ST/levelx/common/inc -I../Middlewares/ST/threadx/ports/cortex_m33/gnu/inc -I../Drivers/CMSIS/Include -I../GNSS/Target -I../X-CUBE-ISPU/Target -I../Drivers/BSP/Components/lsm6dso16is -I../Middlewares/ST/lib_gnss/LibGNSS/Inc -I../Middlewares/ST/lib_gnss/LibNMEA/Inc -I../Middlewares/ST/lib_gnss/Template -I../Drivers/BSP/Components/teseo_liv3f -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/generated/videos/include -I../TouchGFX/gui/include -I../Middlewares/ST/touchgfx_components/gpu2d/NemaGFX/include -I../Middlewares/ST/touchgfx_components/gpu2d/TouchGFXNema/include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-STM32U5xx_HAL_Driver-2f-Src

clean-Drivers-2f-STM32U5xx_HAL_Driver-2f-Src:
	-$(RM) ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal.cyclo ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal.d ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal.o ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal.su ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_comp.cyclo ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_comp.d ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_comp.o ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_comp.su ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_cortex.cyclo ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_cortex.d ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_cortex.o ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_cortex.su ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_crc.cyclo ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_crc.d ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_crc.o ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_crc.su ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_crc_ex.cyclo ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_crc_ex.d ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_crc_ex.o ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_crc_ex.su ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_dcache.cyclo ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_dcache.d ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_dcache.o ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_dcache.su ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_dma.cyclo ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_dma.d ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_dma.o ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_dma.su ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_dma2d.cyclo ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_dma2d.d ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_dma2d.o ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_dma2d.su ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_dma_ex.cyclo ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_dma_ex.d ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_dma_ex.o ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_dma_ex.su ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_dsi.cyclo ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_dsi.d ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_dsi.o ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_dsi.su ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_exti.cyclo ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_exti.d ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_exti.o ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_exti.su ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_flash.cyclo ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_flash.d ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_flash.o ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_flash.su ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_flash_ex.cyclo ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_flash_ex.d ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_flash_ex.o ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_flash_ex.su ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_gfxmmu.cyclo ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_gfxmmu.d ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_gfxmmu.o ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_gfxmmu.su ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_gpio.cyclo ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_gpio.d ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_gpio.o ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_gpio.su ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_gpu2d.cyclo ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_gpu2d.d ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_gpu2d.o ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_gpu2d.su ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_gtzc.cyclo ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_gtzc.d ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_gtzc.o ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_gtzc.su ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_i2c.cyclo ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_i2c.d ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_i2c.o ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_i2c.su ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_i2c_ex.cyclo ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_i2c_ex.d ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_i2c_ex.o ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_i2c_ex.su ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_icache.cyclo ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_icache.d ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_icache.o ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_icache.su ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_ltdc.cyclo ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_ltdc.d ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_ltdc.o ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_ltdc.su ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_ltdc_ex.cyclo ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_ltdc_ex.d ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_ltdc_ex.o ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_ltdc_ex.su ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_ospi.cyclo ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_ospi.d ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_ospi.o ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_ospi.su ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_pwr.cyclo ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_pwr.d ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_pwr.o ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_pwr.su ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_pwr_ex.cyclo ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_pwr_ex.d ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_pwr_ex.o ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_pwr_ex.su ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_rcc.cyclo ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_rcc.d ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_rcc.o
	-$(RM) ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_rcc.su ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_rcc_ex.cyclo ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_rcc_ex.d ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_rcc_ex.o ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_rcc_ex.su ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_sd.cyclo ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_sd.d ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_sd.o ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_sd.su ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_sd_ex.cyclo ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_sd_ex.d ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_sd_ex.o ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_sd_ex.su ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_spi.cyclo ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_spi.d ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_spi.o ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_spi.su ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_spi_ex.cyclo ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_spi_ex.d ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_spi_ex.o ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_spi_ex.su ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_tim.cyclo ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_tim.d ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_tim.o ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_tim.su ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_tim_ex.cyclo ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_tim_ex.d ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_tim_ex.o ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_tim_ex.su ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_uart.cyclo ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_uart.d ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_uart.o ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_uart.su ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_uart_ex.cyclo ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_uart_ex.d ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_uart_ex.o ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_uart_ex.su ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_xspi.cyclo ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_xspi.d ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_xspi.o ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_xspi.su ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_ll_dlyb.cyclo ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_ll_dlyb.d ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_ll_dlyb.o ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_ll_dlyb.su ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_ll_sdmmc.cyclo ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_ll_sdmmc.d ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_ll_sdmmc.o ./Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_ll_sdmmc.su

.PHONY: clean-Drivers-2f-STM32U5xx_HAL_Driver-2f-Src

