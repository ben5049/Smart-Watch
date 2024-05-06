################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/Infineon_Wireless_Connectivity/connectivity-utilities/JSON_parser/cy_json_parser.c 

OBJS += \
./Middlewares/Third_Party/Infineon_Wireless_Connectivity/connectivity-utilities/JSON_parser/cy_json_parser.o 

C_DEPS += \
./Middlewares/Third_Party/Infineon_Wireless_Connectivity/connectivity-utilities/JSON_parser/cy_json_parser.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/Infineon_Wireless_Connectivity/connectivity-utilities/JSON_parser/%.o Middlewares/Third_Party/Infineon_Wireless_Connectivity/connectivity-utilities/JSON_parser/%.su Middlewares/Third_Party/Infineon_Wireless_Connectivity/connectivity-utilities/JSON_parser/%.cyclo: ../Middlewares/Third_Party/Infineon_Wireless_Connectivity/connectivity-utilities/JSON_parser/%.c Middlewares/Third_Party/Infineon_Wireless_Connectivity/connectivity-utilities/JSON_parser/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DTX_INCLUDE_USER_DEFINE_FILE -DTX_SINGLE_MODE_NON_SECURE=1 -DUSE_HAL_DRIVER -DSTM32U5G9xx -DNX_INCLUDE_USER_DEFINE_FILE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"Middlewares/Third_Party/Infineon_Wireless_Connectivity/connectivity-utilities/JSON_parser/cy_json_parser.c_includes.args"

clean: clean-Middlewares-2f-Third_Party-2f-Infineon_Wireless_Connectivity-2f-connectivity-2d-utilities-2f-JSON_parser

clean-Middlewares-2f-Third_Party-2f-Infineon_Wireless_Connectivity-2f-connectivity-2d-utilities-2f-JSON_parser:
	-$(RM) ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/connectivity-utilities/JSON_parser/cy_json_parser.cyclo ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/connectivity-utilities/JSON_parser/cy_json_parser.d ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/connectivity-utilities/JSON_parser/cy_json_parser.o ./Middlewares/Third_Party/Infineon_Wireless_Connectivity/connectivity-utilities/JSON_parser/cy_json_parser.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-Infineon_Wireless_Connectivity-2f-connectivity-2d-utilities-2f-JSON_parser

