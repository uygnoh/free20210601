################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../YSH_RTOS/TASK/task.c 

OBJS += \
./YSH_RTOS/TASK/task.o 

C_DEPS += \
./YSH_RTOS/TASK/task.d 


# Each subdirectory must supply rules for building sources it contributes
YSH_RTOS/TASK/task.o: ../YSH_RTOS/TASK/task.c YSH_RTOS/TASK/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xE -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"/home/freeysh/Documents/GIT_HUB/FREE_RTOS/STM32F103ZET6_HAL/YSH_RTOS/LIST" -I"/home/freeysh/Documents/GIT_HUB/FREE_RTOS/STM32F103ZET6_HAL/YSH_RTOS/TASK" -I"/home/freeysh/Documents/GIT_HUB/FREE_RTOS/STM32F103ZET6_HAL/YSH_BSP" -I"/home/freeysh/Documents/GIT_HUB/FREE_RTOS/STM32F103ZET6_HAL/YSH_BSP/TIMER" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"YSH_RTOS/TASK/task.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

