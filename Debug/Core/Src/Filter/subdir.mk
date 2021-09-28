################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Filter/Fliter.c 

OBJS += \
./Core/Src/Filter/Fliter.o 

C_DEPS += \
./Core/Src/Filter/Fliter.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Filter/Fliter.o: ../Core/Src/Filter/Fliter.c Core/Src/Filter/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32F103xB -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I"C:/Users/fan/Desktop/BALANCE/Core/Src/APP" -I"C:/Users/fan/Desktop/BALANCE/Core/Src/Clock" -I"C:/Users/fan/Desktop/BALANCE/Core/Src/Debug" -I"C:/Users/fan/Desktop/BALANCE/Core/Src/encoder" -I"C:/Users/fan/Desktop/BALANCE/Core/Src/FastMatch" -I"C:/Users/fan/Desktop/BALANCE/Core/Src/Filter" -I"C:/Users/fan/Desktop/BALANCE/Core/Src/JustFloat" -I"C:/Users/fan/Desktop/BALANCE/Core/Src/mpu6050/eMPL" -I"C:/Users/fan/Desktop/BALANCE/Core/Src/PID" -I"C:/Users/fan/Desktop/BALANCE/Core/Src/SerialPrintf" -I"C:/Users/fan/Desktop/BALANCE/Core/Src/SimpleProtocolPraise" -I"C:/Users/fan/Desktop/BALANCE/Core/Src/TB6612" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/Filter/Fliter.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

