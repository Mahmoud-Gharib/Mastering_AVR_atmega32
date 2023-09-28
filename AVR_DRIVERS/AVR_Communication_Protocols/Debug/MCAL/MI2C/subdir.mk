################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/MI2C/I2C_PROGRAME.c 

OBJS += \
./MCAL/MI2C/I2C_PROGRAME.o 

C_DEPS += \
./MCAL/MI2C/I2C_PROGRAME.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/MI2C/%.o: ../MCAL/MI2C/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g3 -gdwarf-2 -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


