################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/strikles/workspace/ezxml/ezxml.c 

OBJS += \
./ezxml/ezxml.o 

C_DEPS += \
./ezxml/ezxml.d 


# Each subdirectory must supply rules for building sources it contributes
ezxml/ezxml.o: /home/strikles/workspace/ezxml/ezxml.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/strikles/workspace/ezxml" -I"/home/strikles/workspace/common" -I"/home/strikles/workspace/CMock-master/src" -I"/home/strikles/workspace/Unity-master/src" -O0 -g3 -Wall -c -fmessage-length=0 -pthread -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


