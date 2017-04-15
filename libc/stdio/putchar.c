#include <stdio.h>
#include <kernel/vga_driver.h>

int putchar(int ca){
    char c = (char)ca;
    vga_write(&c, sizeof(c));
    return ca;
}
