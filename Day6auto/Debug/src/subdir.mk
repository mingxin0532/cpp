################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/InterfaceHW.cpp \
../src/InterfaceHWArdupi.cpp \
../src/InterfaceHWHall.cpp \
../src/InterfaceHWSpeed.cpp \
../src/Maneuver.cpp \
../src/PIDController.cpp \
../src/PosEstimation.cpp \
../src/RobotControl.cpp \
../src/main.cpp 

OBJS += \
./src/InterfaceHW.o \
./src/InterfaceHWArdupi.o \
./src/InterfaceHWHall.o \
./src/InterfaceHWSpeed.o \
./src/Maneuver.o \
./src/PIDController.o \
./src/PosEstimation.o \
./src/RobotControl.o \
./src/main.o 

CPP_DEPS += \
./src/InterfaceHW.d \
./src/InterfaceHWArdupi.d \
./src/InterfaceHWHall.d \
./src/InterfaceHWSpeed.d \
./src/Maneuver.d \
./src/PIDController.d \
./src/PosEstimation.d \
./src/RobotControl.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-linux-gnueabihf-g++ -I/home/pi/RaspberryLibs/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


