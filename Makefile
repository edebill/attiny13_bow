chip="attiny13a"
avrdude_part="t13"

bow.o: bow.c
	avr-gcc -g -Os -mmcu=$(chip) -c bow.c

bow.elf: bow.o
	avr-gcc -g -mmcu=$(chip) -o bow.elf bow.o

bow.hex: bow.elf
	avr-objcopy -j .text -j.data -O ihex bow.elf bow.hex


clean:
	rm bow.elf bow.o

burn: bow.hex
	sudo avrdude -c usbtiny -p $(avrdude_part) -U flash:w:bow.hex