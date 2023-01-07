################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/STM324xG_EVAL/stm324xg_eval.c \
../Drivers/BSP/STM324xG_EVAL/stm324xg_eval_camera.c \
../Drivers/BSP/STM324xG_EVAL/stm324xg_eval_eeprom.c \
../Drivers/BSP/STM324xG_EVAL/stm324xg_eval_io.c \
../Drivers/BSP/STM324xG_EVAL/stm324xg_eval_lcd.c \
../Drivers/BSP/STM324xG_EVAL/stm324xg_eval_sram.c \
../Drivers/BSP/STM324xG_EVAL/stm324xg_eval_ts.c 

OBJS += \
./Drivers/BSP/STM324xG_EVAL/stm324xg_eval.o \
./Drivers/BSP/STM324xG_EVAL/stm324xg_eval_camera.o \
./Drivers/BSP/STM324xG_EVAL/stm324xg_eval_eeprom.o \
./Drivers/BSP/STM324xG_EVAL/stm324xg_eval_io.o \
./Drivers/BSP/STM324xG_EVAL/stm324xg_eval_lcd.o \
./Drivers/BSP/STM324xG_EVAL/stm324xg_eval_sram.o \
./Drivers/BSP/STM324xG_EVAL/stm324xg_eval_ts.o 

C_DEPS += \
./Drivers/BSP/STM324xG_EVAL/stm324xg_eval.d \
./Drivers/BSP/STM324xG_EVAL/stm324xg_eval_camera.d \
./Drivers/BSP/STM324xG_EVAL/stm324xg_eval_eeprom.d \
./Drivers/BSP/STM324xG_EVAL/stm324xg_eval_io.d \
./Drivers/BSP/STM324xG_EVAL/stm324xg_eval_lcd.d \
./Drivers/BSP/STM324xG_EVAL/stm324xg_eval_sram.d \
./Drivers/BSP/STM324xG_EVAL/stm324xg_eval_ts.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/STM324xG_EVAL/%.o Drivers/BSP/STM324xG_EVAL/%.su: ../Drivers/BSP/STM324xG_EVAL/%.c Drivers/BSP/STM324xG_EVAL/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/HID/Inc -I"/home/japaw/Codes/CubeIde/whaat/Drivers/BSP/STM324xG_EVAL" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-STM324xG_EVAL

clean-Drivers-2f-BSP-2f-STM324xG_EVAL:
	-$(RM) ./Drivers/BSP/STM324xG_EVAL/stm324xg_eval.d ./Drivers/BSP/STM324xG_EVAL/stm324xg_eval.o ./Drivers/BSP/STM324xG_EVAL/stm324xg_eval.su ./Drivers/BSP/STM324xG_EVAL/stm324xg_eval_camera.d ./Drivers/BSP/STM324xG_EVAL/stm324xg_eval_camera.o ./Drivers/BSP/STM324xG_EVAL/stm324xg_eval_camera.su ./Drivers/BSP/STM324xG_EVAL/stm324xg_eval_eeprom.d ./Drivers/BSP/STM324xG_EVAL/stm324xg_eval_eeprom.o ./Drivers/BSP/STM324xG_EVAL/stm324xg_eval_eeprom.su ./Drivers/BSP/STM324xG_EVAL/stm324xg_eval_io.d ./Drivers/BSP/STM324xG_EVAL/stm324xg_eval_io.o ./Drivers/BSP/STM324xG_EVAL/stm324xg_eval_io.su ./Drivers/BSP/STM324xG_EVAL/stm324xg_eval_lcd.d ./Drivers/BSP/STM324xG_EVAL/stm324xg_eval_lcd.o ./Drivers/BSP/STM324xG_EVAL/stm324xg_eval_lcd.su ./Drivers/BSP/STM324xG_EVAL/stm324xg_eval_sram.d ./Drivers/BSP/STM324xG_EVAL/stm324xg_eval_sram.o ./Drivers/BSP/STM324xG_EVAL/stm324xg_eval_sram.su ./Drivers/BSP/STM324xG_EVAL/stm324xg_eval_ts.d ./Drivers/BSP/STM324xG_EVAL/stm324xg_eval_ts.o ./Drivers/BSP/STM324xG_EVAL/stm324xg_eval_ts.su

.PHONY: clean-Drivers-2f-BSP-2f-STM324xG_EVAL

