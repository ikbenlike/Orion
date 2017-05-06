#include <kernel/vga_driver.h>
#include <stddef.h>

void isr0_handler(){
    vga_writestring("error: 0-division error");
    while(1){}
}

void isr1_handler(){
    vga_writestring("error: debug");
}

void isr2_handler(){
    vga_writestring("error: NMI error");
}

void isr3_handler(){
    vga_writestring("breakpoint");
}

void isr4_handler(){
    vga_writestring("error: overflow error");
}

void isr5_handler(){
    vga_writestring("error: out of bounds error");
}

void isr6_handler(){
    vga_writestring("error: invalid opcode");
}

void isr7_handler(){
    vga_writestring("error: device unavailable");
}

void isr8_handler(){
    vga_writestring("error: double fault");
}

void isr9_handler(){
    vga_writestring("error: coprocessor segment overrun");
}

void isr10_handler(){
    vga_writestring("error: invalid TSS");
}

void isr11_handler(){
    vga_writestring("error: segment not present");
}

void isr12_handler(){
    vga_writestring("error: stack segment fault");
}

void isr13_handler(){
    vga_writestring("error: protection fault");
}

void isr14_handler(){
    vga_writestring("error: page fault");
}

void isr15_handler(){
    return;
}

void isr16_handler(){
    vga_writestring("error: floating point error");
}

void isr17_handler(){
    vga_writestring("error: alignment check error");
}

void isr18_handler(){
    vga_writestring("error: machine check error");
}

void isr19_handler(){
    vga_writestring("error: SIMD floating point error");
}

void isr20_handler(){
    vga_writestring("error: virtualization error");
}

void isr21to29_handler(){
    return;
}

void isr30_handler(){
    vga_writestring("error: security error");
}

void isr31_handler(){
    return;
}
