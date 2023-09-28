################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/MUART/subdir.mk
-include MCAL/MSPI/subdir.mk
-include MCAL/MI2C/subdir.mk
-include MCAL/MDIO/subdir.mk
-include HAL/HLCD/subdir.mk
-include HAL/HKEYPAD/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
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

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
AVR_Communication_Protocols.lss \

FLASH_IMAGE += \
AVR_Communication_Protocols.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: AVR_Communication_Protocols.elf secondary-outputs

# Tool invocations
AVR_Communication_Protocols.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,AVR_Communication_Protocols.map -mmcu=atmega32 -o "AVR_Communication_Protocols.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

AVR_Communication_Protocols.lss: AVR_Communication_Protocols.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S AVR_Communication_Protocols.elf  >"AVR_Communication_Protocols.lss"
	@echo 'Finished building: $@'
	@echo ' '

AVR_Communication_Protocols.hex: AVR_Communication_Protocols.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex AVR_Communication_Protocols.elf  "AVR_Communication_Protocols.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: AVR_Communication_Protocols.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 AVR_Communication_Protocols.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) AVR_Communication_Protocols.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
