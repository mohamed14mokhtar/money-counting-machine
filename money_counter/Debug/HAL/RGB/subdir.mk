################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/RGB/rgb.c 

OBJS += \
./HAL/RGB/rgb.o 

C_DEPS += \
./HAL/RGB/rgb.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/RGB/%.o HAL/RGB/%.su HAL/RGB/%.cyclo: ../HAL/RGB/%.c HAL/RGB/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -IC:/Users/Lenovo/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.2/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/Lenovo/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.2/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/Lenovo/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.2/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/Lenovo/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.2/Drivers/CMSIS/Include -I"F:/ARM_PROJECTS/money_counter/HAL/Common" -I"F:/ARM_PROJECTS/money_counter/HAL/LCD" -I"F:/ARM_PROJECTS/money_counter/HAL/RGB" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-HAL-2f-RGB

clean-HAL-2f-RGB:
	-$(RM) ./HAL/RGB/rgb.cyclo ./HAL/RGB/rgb.d ./HAL/RGB/rgb.o ./HAL/RGB/rgb.su

.PHONY: clean-HAL-2f-RGB

