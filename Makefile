# put your *.o targets here, make should handle the rest!

SRCS = start.c main.c 

LD_SCRIPT = stm-baremetal.ld

# all the files will be generated with this name (main.elf, main.bin, main.hex, etc)

TARGET=main

# that's it, no need to change anything below this line!

###################################################

CC=arm-none-eabi-gcc
OBJCOPY=arm-none-eabi-objcopy
LD=arm-none-eabi-ld

CFLAGS  = -g3 -c -Wall --std=gnu99
CFLAGS += -mlittle-endian -mthumb -mcpu=cortex-m4 -mthumb-interwork
CFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16 -nostdlib -ffreestanding
CFLAGS += -save-temps

###################################################

ROOT=$(shell pwd)

OBJS = $(SRCS:.c=.o)

###################################################

.PHONY: proj

all: proj

again: clean all

# Flash the STM32F4
burn:
	st-flash write $(TARGET).bin 0x8000000

# Create tags; assumes ctags exists
ctags:
	ctags -R .


.c.o:
	$(CC) $(CFLAGS) $*.c

proj: 	$(TARGET).elf

$(TARGET).elf: $(OBJS)
	$(LD) -T$(LD_SCRIPT) $(OBJS) -o $(TARGET).elf
	$(OBJCOPY) -O ihex $(TARGET).elf $(TARGET).hex
	$(OBJCOPY) -O binary $(TARGET).elf $(TARGET).bin

clean:
	rm -f *.o *.i *.s
	rm -f $(TARGET).elf
	rm -f $(TARGET).hex
	rm -f $(TARGET).bin
