################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Lab\ 7.c 

OBJS += \
./src/Lab\ 7.o 

C_DEPS += \
./src/Lab\ 7.d 


# Each subdirectory must supply rules for building sources it contributes
src/Lab\ 7.o: ../src/Lab\ 7.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Lab 7.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


