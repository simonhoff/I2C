###################################
# Makefile, for AVR Programming


# Target name:
TARGET = out

# Target type
CMCU=atmega324pa
UMCU=atmega324pb
PROGRAMMER=xplainedpro


SRC = main.c
OBJ = $(SRC:.c=.o)


# Compiler / Linker flags:
CFLAGS = -mmcu=$(CMCU) -Wall -Os -std=gnu99 -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums -fexec-charset=LATIN1
LDFLAGS = -mmcu=$(CMCU) -Wl,-Map=$(TARGET).map

SUBSYSTEM="usb", ATTRS{idVendor}=="1d6b", ATTRS{idProduct}=="0002", GROUP="users", MODE="0666"

###################################
# Makerules:


.PHONY: compile flash clean

compile: $(TARGET).hex $(TARGET).eep $(TARGET).lss

flash: compile
	avrdude -c $(PROGRAMMER) -P usb -p $(UMCU) -U flash:w:$(TARGET).hex

clean:
	rm -f $(OBJ) $(TARGET).{elf,hex,lss,map,eep}



###################################
# Psudorules:

%.eep: %.hex
	avr-objcopy -j .eeprom --set-section-flags=.eeprom="alloc,load" --change-section-lma .eeprom=0 --no-change-warnings -O ihex $< $@

%.hex: %.elf
	avr-objcopy -O ihex -R .eeprom -R .fuse -R .lock -R .signature $< $@

%.lss: %.elf
	avr-objdump -h -S $< > $@

%.elf: $(OBJ)
	avr-gcc $^ $(LDFLAGS) -o $@

%.o : %.c
	avr-gcc $(CFLAGS) -c $< -o $@
