################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/tests/test.c 

OBJS += \
./src/tests/test.o 

C_DEPS += \
./src/tests/test.d 


# Each subdirectory must supply rules for building sources it contributes
src/tests/%.o: ../src/tests/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/strikles/workspace/common" -I"/home/strikles/workspace/ezxml" -I"/home/strikles/workspace/Unity-master/src" -I"/home/strikles/workspace/CMock-master/src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


