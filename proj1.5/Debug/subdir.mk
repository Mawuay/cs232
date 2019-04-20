################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../callTimer.cpp \
../cmdLineController.cpp \
../cmdLineInterface.cpp \
../main.cpp \
../model.cpp \
../textController.cpp \
../textInterface.cpp 

OBJS += \
./callTimer.o \
./cmdLineController.o \
./cmdLineInterface.o \
./main.o \
./model.o \
./textController.o \
./textInterface.o 

CPP_DEPS += \
./callTimer.d \
./cmdLineController.d \
./cmdLineInterface.d \
./main.d \
./model.d \
./textController.d \
./textInterface.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


