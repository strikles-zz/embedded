################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/strikles/workspace/CMock-master/src/cmock.c 

OBJS += \
./CMock/cmock.o 

C_DEPS += \
./CMock/cmock.d 


# Each subdirectory must supply rules for building sources it contributes
CMock/cmock.o: /home/strikles/workspace/CMock-master/src/cmock.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/strikles/workspace/common" -I"/home/strikles/workspace/ezxml" -I"/home/strikles/workspace/Unity-master/src" -I"/home/strikles/workspace/CMock-master/src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


