#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include "kernel/vga_driver.h"
#include "kernel/serial.h"
#include "kernel/interrupt_handler.h"
 
#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif
 
#if !defined(__i386__)
#error "This needs to be compiled with a ix86-elf compiler"
#endif

void kernel_main(void){

    isr_init();

	vga_initialize();

	vga_writestring("  _____ ______  _____  _____  _   _  \n"
                    " |  _  || ___ \\|_   _||  _  || \\ | | \n"
                    " | | | || |_/ /  | |  | | | ||  \\| | \n"
                    " | | | ||    /   | |  | | | || . ` | \n"
                    " \\ \\_/ /| |\\ \\  _| |_ \\ \\_/ /| |\\  | \n"
                    "  \\___/ \\_| \\_| \\___/  \\___/ \\_| \\_/  \n");
 
	vga_writestring("\n    v0.0 unstable\n\n");
    serial_writestring("Hello, Serial World!");
	printf("Hello, Kernel World!\n");
    printf("This is a test.");
    __asm__ __volatile__("mov $1, %%eax" : :);
    __asm__ __volatile__("mov $0, %%ebx" : :);
    __asm__ __volatile__("div %%ebx" : :);
    //while(1){}
}
