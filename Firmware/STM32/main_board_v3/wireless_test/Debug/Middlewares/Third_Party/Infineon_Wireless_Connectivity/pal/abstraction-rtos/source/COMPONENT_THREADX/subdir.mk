################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/abstraction-rtos/source/COMPONENT_THREADX/cyabs_rtos_threadx.c 

OBJS += \
./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/abstraction-rtos/source/COMPONENT_THREADX/cyabs_rtos_threadx.o 

C_DEPS += \
./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/abstraction-rtos/source/COMPONENT_THREADX/cyabs_rtos_threadx.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/abstraction-rtos/source/COMPONENT_THREADX/%.o Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/abstraction-rtos/source/COMPONENT_THREADX/%.su Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/abstraction-rtos/source/COMPONENT_THREADX/%.cyclo: ../Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/abstraction-rtos/source/COMPONENT_THREADX/%.c Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/abstraction-rtos/source/COMPONENT_THREADX/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DTX_INCLUDE_USER_DEFINE_FILE -DTX_SINGLE_MODE_NON_SECURE=1 -DUSE_HAL_DRIVER -DSTM32U5G9xx -DNX_INCLUDE_USER_DEFINE_FILE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/abstraction-rtos/source/COMPONENT_THREADX/cyabs_rtos_threadx.c_includes.args"

clean: clean-Middlewares-2f-Third_Party-2f-Infineon_Wireless_Connectivity-2f-pal-2f-abstraction-2d-rtos-2f-source-2f-COMPONENT_THREADX

clean-Middlewares-2f-Third_Party-2f-Infineon_Wireless_Connectivity-2f-pal-2f-abstraction-2d-rtos-2f-source-2f-COMPONENT_THREADX:
	-$(RM) ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/abstraction-rtos/source/COMPONENT_THREADX/cyabs_rtos_threadx.cyclo ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/abstraction-rtos/source/COMPONENT_THREADX/cyabs_rtos_threadx.d ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/abstraction-rtos/source/COMPONENT_THREADX/cyabs_rtos_threadx.o ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/abstraction-rtos/source/COMPONENT_THREADX/cyabs_rtos_threadx.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-Infineon_Wireless_Connectivity-2f-pal-2f-abstraction-2d-rtos-2f-source-2f-COMPONENT_THREADX

