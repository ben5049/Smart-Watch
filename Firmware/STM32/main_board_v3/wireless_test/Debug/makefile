################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include NetXDuo/App/subdir.mk
-include Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-host-driver/src/bus_protocols/subdir.mk
-include Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-host-driver/src/subdir.mk
-include Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-host-driver/resources/resource_imp/subdir.mk
-include Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-host-driver/resources/firmware/COMPONENT_4373/COMPONENT_MURATA-2AE/subdir.mk
-include Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-host-driver/resources/clm/COMPONENT_4373/COMPONENT_MURATA-2AE/subdir.mk
-include Middlewares/Third_Party/Infineon_Wireless_Connectivity/wifi-connection-manager/source/subdir.mk
-include Middlewares/Third_Party/Infineon_Wireless_Connectivity/whd-bsp-integration/COMPONENT_NETXDUO/subdir.mk
-include Middlewares/Third_Party/Infineon_Wireless_Connectivity/whd-bsp-integration/subdir.mk
-include Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/targets/TARGET_STM32/Src/subdir.mk
-include Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/common/Src/subdir.mk
-include Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/abstraction-rtos/source/COMPONENT_THREADX/subdir.mk
-include Middlewares/Third_Party/Infineon_Wireless_Connectivity/pal/abstraction-rtos/source/subdir.mk
-include Middlewares/Third_Party/Infineon_Wireless_Connectivity/netxduo-network-interface-integration/source/subdir.mk
-include Middlewares/Third_Party/Infineon_Wireless_Connectivity/connectivity-utilities/network/COMPONENT_NETXDUO/subdir.mk
-include Middlewares/Third_Party/Infineon_Wireless_Connectivity/connectivity-utilities/network/subdir.mk
-include Middlewares/Third_Party/Infineon_Wireless_Connectivity/connectivity-utilities/linked_list/subdir.mk
-include Middlewares/Third_Party/Infineon_Wireless_Connectivity/connectivity-utilities/cy_string/subdir.mk
-include Middlewares/Third_Party/Infineon_Wireless_Connectivity/connectivity-utilities/cy_log/subdir.mk
-include Middlewares/Third_Party/Infineon_Wireless_Connectivity/connectivity-utilities/JSON_parser/subdir.mk
-include Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/freertos/subdir.mk
-include Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/firmware/COMPONENT_4373/COMPONENT_MURATA-2AE/subdir.mk
-include Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/debug/subdir.mk
-include Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack-integration/COMPONENT_HCI-UART/common/subdir.mk
-include Middlewares/ST/threadx/ports/cortex_m33/gnu/src/subdir.mk
-include Middlewares/ST/threadx/common/src/subdir.mk
-include Middlewares/ST/netxduo/common/src/subdir.mk
-include Middlewares/ST/netxduo/addons/dns/subdir.mk
-include Middlewares/ST/netxduo/addons/dhcp/subdir.mk
-include Middlewares/ST/netxduo/addons/auto_ip/subdir.mk
-include Drivers/STM32U5xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include AZURE_RTOS/App/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := wireless_test
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
wireless_test.elf \

MAP_FILES += \
wireless_test.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
wireless_test.list \


# All Target
all:
	+@$(MAKE) --no-print-directory pre-build && $(MAKE) --no-print-directory main-build

# Main-build Target
main-build: wireless_test.elf secondary-outputs

# Tool invocations
wireless_test.elf wireless_test.map: $(OBJS) $(USER_OBJS) C:\Users\bens1\Documents\Other\Projects\Smart-Watch\Firmware\STM32\main_board_v3\wireless_test\STM32U5G9ZJJXQ_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "wireless_test.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m33 -T"C:\Users\bens1\Documents\Other\Projects\Smart-Watch\Firmware\STM32\main_board_v3\wireless_test\STM32U5G9ZJJXQ_FLASH.ld" --specs=nosys.specs -Wl,-Map="wireless_test.map" -Wl,--gc-sections -static -L../Middlewares/Third_Party/Infineon_Wireless_Connectivity/btstack/stack/COMPONENT_WICED_BLE/COMPONENT_CM33/COMPONENT_HARDFP/TOOLCHAIN_GCC_ARM --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

wireless_test.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "wireless_test.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) default.size.stdout wireless_test.elf wireless_test.list wireless_test.map
	-@echo ' '

pre-build:
	@python "..\..\..\..\Scripts\add_target.py"
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified pre-build

-include ../makefile.targets
