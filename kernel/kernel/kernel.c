#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "vga/vga_driver.h"
 
/* Check if the compiler thinks we are targeting the wrong operating system. */
#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif
 
/* This tutorial will only work for the 32-bit ix86 targets. */
#if !defined(__i386__)
#error "This tutorial needs to be compiled with a ix86-elf compiler"
#endif

void kernel_main(void){
	/* Initialize terminal interface */
	vga_initialize();

	vga_writestring("   _____ ______  _____  _____  _   _  \n"
                    " |  _  || ___ \\|_   _||  _  || \\ | | \n"
                    " | | | || |_/ /  | |  | | | ||  \\| | \n"
                    " | | | ||    /   | |  | | | || . ` | \n"
                    " \\ \\_/ /| |\\ \\  _| |_ \\ \\_/ /| |\\  | \n"
                    "  \\___/ \\_| \\_| \\___/  \\___/ \\_| \\_/  \n");
 
	vga_writestring("\n\tv0.0 unstable\n\n");
	vga_writestring("Hello, kernel World!\n");
}
