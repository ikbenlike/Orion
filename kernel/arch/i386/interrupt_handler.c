#include "interrupt_handler.h"

isr_t handlers[256];

void set_idt_handler(int n, unsigned int handler) {
    idt[n].low_offset = (unsigned short)((handler) & 0xFFFF);
    idt[n].sel = 0x08;
    idt[n].zero = 0;
    idt[n].flags = 0x8E;
    idt[n].high_offset = (unsigned short)(((handler) >> 16) & 0xFFFF);
}

void set_idt() {
    idt_reg.base = (unsigned int)&idt;
    idt_reg.limit = 256 * sizeof(idt_handler_t) - 1;
    __asm__ __volatile__("lidtl (%0)" : : "r" (&idt_reg));
}

void isr_init(){
    set_idt_handler(0, (unsigned int)isr0);
    set_idt_handler(1, (unsigned int)isr1);
    set_idt_handler(2, (unsigned int)isr2);
    set_idt_handler(3, (unsigned int)isr3);
    set_idt_handler(4, (unsigned int)isr4);
    set_idt_handler(5, (unsigned int)isr5);
    set_idt_handler(6, (unsigned int)isr6);
    set_idt_handler(7, (unsigned int)isr7);
    set_idt_handler(8, (unsigned int)isr8);
    set_idt_handler(9, (unsigned int)isr9);
    set_idt_handler(10, (unsigned int)isr10);
    set_idt_handler(11, (unsigned int)isr11);
    set_idt_handler(12, (unsigned int)isr12);
    set_idt_handler(13, (unsigned int)isr13);
    set_idt_handler(14, (unsigned int)isr14);
    set_idt_handler(15, (unsigned int)isr15);
    set_idt_handler(16, (unsigned int)isr16);
    set_idt_handler(17, (unsigned int)isr17);
    set_idt_handler(18, (unsigned int)isr18);
    set_idt_handler(19, (unsigned int)isr19);
    set_idt_handler(20, (unsigned int)isr20);
    set_idt_handler(21, (unsigned int)isr21);
    set_idt_handler(22, (unsigned int)isr22);
    set_idt_handler(23, (unsigned int)isr23);
    set_idt_handler(24, (unsigned int)isr24);
    set_idt_handler(25, (unsigned int)isr25);
    set_idt_handler(26, (unsigned int)isr26);
    set_idt_handler(27, (unsigned int)isr27);
    set_idt_handler(28, (unsigned int)isr28);
    set_idt_handler(29, (unsigned int)isr29);
    set_idt_handler(30, (unsigned int)isr30);
    set_idt_handler(31, (unsigned int)isr31);

    set_idt(); // Load with ASM
}

void register_interrupt(int n, isr_t handler){
    handlers[n] = handler;
}
