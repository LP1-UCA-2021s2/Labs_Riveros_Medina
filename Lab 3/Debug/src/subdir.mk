################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Lab\ 3.c 

OBJS += \
./src/Lab\ 3.o 

C_DEPS += \
./src/Lab\ 3.d 


# Each subdirectory must supply rules for building sources it contributes
src/Lab\ 3.o: ../src/Lab\ 3.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Lab 3.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


