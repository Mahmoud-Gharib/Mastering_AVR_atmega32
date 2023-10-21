################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../01-APP/01-TEST_LED/CODE/APP_LED.c 

OBJS += \
./01-APP/01-TEST_LED/CODE/APP_LED.o 

C_DEPS += \
./01-APP/01-TEST_LED/CODE/APP_LED.d 


# Each subdirectory must supply rules for building sources it contributes
01-APP/01-TEST_LED/CODE/%.o: ../01-APP/01-TEST_LED/CODE/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


