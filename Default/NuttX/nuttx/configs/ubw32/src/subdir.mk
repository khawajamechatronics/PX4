################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../NuttX/nuttx/configs/ubw32/src/up_boot.c \
../NuttX/nuttx/configs/ubw32/src/up_buttons.c \
../NuttX/nuttx/configs/ubw32/src/up_leds.c \
../NuttX/nuttx/configs/ubw32/src/up_nsh.c \
../NuttX/nuttx/configs/ubw32/src/up_usbdev.c \
../NuttX/nuttx/configs/ubw32/src/up_usbterm.c 

OBJS += \
./NuttX/nuttx/configs/ubw32/src/up_boot.o \
./NuttX/nuttx/configs/ubw32/src/up_buttons.o \
./NuttX/nuttx/configs/ubw32/src/up_leds.o \
./NuttX/nuttx/configs/ubw32/src/up_nsh.o \
./NuttX/nuttx/configs/ubw32/src/up_usbdev.o \
./NuttX/nuttx/configs/ubw32/src/up_usbterm.o 

C_DEPS += \
./NuttX/nuttx/configs/ubw32/src/up_boot.d \
./NuttX/nuttx/configs/ubw32/src/up_buttons.d \
./NuttX/nuttx/configs/ubw32/src/up_leds.d \
./NuttX/nuttx/configs/ubw32/src/up_nsh.d \
./NuttX/nuttx/configs/ubw32/src/up_usbdev.d \
./NuttX/nuttx/configs/ubw32/src/up_usbterm.d 


# Each subdirectory must supply rules for building sources it contributes
NuttX/nuttx/configs/ubw32/src/%.o: ../NuttX/nuttx/configs/ubw32/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


