ARMCFLAGS ?=  -W -Wall -Wextra -Wundef -Wshadow -Wdouble-promotion \
            -Wformat-truncation -fno-common -Wconversion -Iinclude \
	    -ffunction-sections -fdata-sections \
	    -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16
CFLAGS ?= -W -Wall -Wextra -Wundef -Wshadow -Wdouble-promotion \
	-Wformat-truncation -fno-common -Wconversion -I.
LDFLAGS ?= -nostartfiles -nostdlib --specs nano.specs -lc -lgcc -Wl,--gc-sections -Wl,-Map=$@.map

FIRMWARE_LD ?= boot/f411re.ld
FIRMWARE_SOURCES = stm32_main.c rcc.c boot/startup_f411re.c uart.c \
		   syscalls.c rohs.c
FIRMWARE_HEADER = include/rcc.h include/hal.h include/uart.h 
FIRMWARE_ADDR = 0x08000000

ifeq ($(OS),WINDOWS_NT)
	RM = cmd /C del /Q /F *.elf *~ *.o *.bin ota_upload_raspi
else
	RM = rm -f *.bin *.elf *.o ota_upload_raspi *.map
endif

build: firmware.elf 

flash: firmware.bin
	st-flash --reset write $< $(FIRMWARE_ADDR)

firmware.bin: firmware.elf
	arm-none-eabi-objcopy -O binary $< $@

firmware.elf: $(FIRMWARE_SOURCES) $(FIRMWARE_HEADER)
	arm-none-eabi-gcc $(FIRMWARE_SOURCES) $(ARMCFLAGS) -T $(FIRMWARE_LD) $(LDFLAGS) -o $@

clean:
	$(RM)
