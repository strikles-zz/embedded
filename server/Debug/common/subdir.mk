################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/strikles/workspace/common/defines.c \
/home/strikles/workspace/common/net.c \
/home/strikles/workspace/common/sensors.c \
/home/strikles/workspace/common/xml.c 

OBJS += \
./common/defines.o \
./common/net.o \
./common/sensors.o \
./common/xml.o 

C_DEPS += \
./common/defines.d \
./common/net.d \
./common/sensors.d \
./common/xml.d 


# Each subdirectory must supply rules for building sources it contributes
common/defines.o: /home/strikles/workspace/common/defines.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/strikles/workspace/ezxml" -I"/home/strikles/workspace/common" -I"/home/strikles/workspace/CMock-master/src" -I"/home/strikles/workspace/Unity-master/src" -O0 -g3 -Wall -c -fmessage-length=0 -pthread -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

common/net.o: /home/strikles/workspace/common/net.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/strikles/workspace/ezxml" -I"/home/strikles/workspace/common" -I"/home/strikles/workspace/CMock-master/src" -I"/home/strikles/workspace/Unity-master/src" -O0 -g3 -Wall -c -fmessage-length=0 -pthread -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

common/sensors.o: /home/strikles/workspace/common/sensors.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/strikles/workspace/ezxml" -I"/home/strikles/workspace/common" -I"/home/strikles/workspace/CMock-master/src" -I"/home/strikles/workspace/Unity-master/src" -O0 -g3 -Wall -c -fmessage-length=0 -pthread -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

common/xml.o: /home/strikles/workspace/common/xml.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/strikles/workspace/ezxml" -I"/home/strikles/workspace/common" -I"/home/strikles/workspace/CMock-master/src" -I"/home/strikles/workspace/Unity-master/src" -O0 -g3 -Wall -c -fmessage-length=0 -pthread -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


