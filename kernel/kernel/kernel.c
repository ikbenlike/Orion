#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include "kernel/vga_driver.h"
 
#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif
 
#if !defined(__i386__)
#error "This needs to be compiled with a ix86-elf compiler"
#endif

void kernel_main(void){
	vga_initialize();

	vga_writestring("  _____ ______  _____  _____  _   _  \n"
                    " |  _  || ___ \\|_   _||  _  || \\ | | \n"
                    " | | | || |_/ /  | |  | | | ||  \\| | \n"
                    " | | | ||    /   | |  | | | || . ` | \n"
                    " \\ \\_/ /| |\\ \\  _| |_ \\ \\_/ /| |\\  | \n"
                    "  \\___/ \\_| \\_| \\___/  \\___/ \\_| \\_/  \n");
 
	vga_writestring("\n    v0.0 unstable\n\n");
	printf("Hello, Kernel World!\n");
    printf("This is a test.");
}
