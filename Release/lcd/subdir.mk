################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lcd/lcd.c 

OBJS += \
./lcd/lcd.o 

C_DEPS += \
./lcd/lcd.d 


# Each subdirectory must supply rules for building sources it contributes
lcd/%.o: ../lcd/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"/Users/nicolasdubus/Downloads/CEG4166FreeRTOSProjects/FreeRTOS801/include" -I"/Users/nicolasdubus/Downloads/CEG4166FreeRTOSProjects/CEG4166_RTS_Lib/include" -DGCC_MEGA_AVR -Wall -O2 -ffunction-sections -fdata-sections -mcall-prologues -mrelax -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega2560 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


