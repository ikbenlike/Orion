#!/bin/sh

i686-elf-as src/boot.s -o builds/boot.o 
i686-elf-gcc -c src/vga/vga_driver.c -o builds/vga_driver.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
i686-elf-gcc -c src/kernel.c -o builds/kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
i686-elf-gcc -T src/linker.ld -o builds/orion.bin -ffreestanding -O2 -nostdlib builds/boot.o builds/kernel.o builds/vga_driver.o -lgcc 
cp builds/orion.bin isodir/boot/orion.bin
