#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "vga_driver.h"
 
/* Check if the compiler thinks we are targeting the wrong operating system. */
#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif
 
/* This tutorial will only work for the 32-bit ix86 targets. */
#if !defined(__i386__)
#error "This tutorial needs to be compiled with a ix86-elf compiler"
#endif
 
/* Hardware text mode color constants.
enum vga_color {
    VGA_COLOR_BLACK = 0,
    VGA_COLOR_BLUE = 1,
    VGA_COLOR_GREEN = 2,
    VGA_COLOR_CYAN = 3,
    VGA_COLOR_RED = 4,
    VGA_COLOR_MAGENTA = 5,
    VGA_COLOR_BROWN = 6,
    VGA_COLOR_LIGHT_GREY = 7,
    VGA_COLOR_DARK_GREY = 8,
    VGA_COLOR_LIGHT_BLUE = 9,
    VGA_COLOR_LIGHT_GREEN = 10,
    VGA_COLOR_LIGHT_CYAN = 11,
    VGA_COLOR_LIGHT_RED = 12,
    VGA_COLOR_LIGHT_MAGENTA = 13,
    VGA_COLOR_LIGHT_BROWN = 14,
    VGA_COLOR_WHITE = 15,
};*/
 
static inline uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg){
    return fg | bg << 4;
}
 
static inline uint16_t vga_entry(unsigned char uc, uint8_t color){
    return (uint16_t) uc | (uint16_t) color << 8;
}
 
size_t strlen(const char* str){
    size_t len = 0;
    while(str[len]){
        len++;
    }
    return len;
}
 
static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;
 
size_t vga_row;
size_t vga_column;
uint8_t vga_color;
uint16_t* vga_buffer;
 
void vga_initialize(void){
    vga_row = 0;
    vga_column = 0;
    vga_color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
    vga_buffer = (uint16_t*) 0xB8000;
    for(size_t y = 0; y < VGA_HEIGHT; y++){
        for(size_t x = 0; x < VGA_WIDTH; x++){
            const size_t index = y * VGA_WIDTH + x;
            vga_buffer[index] = vga_entry(' ', vga_color);
        }
    }
}
 
void vga_setcolor(uint8_t color){
    vga_color = color;
}
 
void vga_putentryat(char c, uint8_t color, size_t x, size_t y){
    const size_t index = y * VGA_WIDTH + x;
    vga_buffer[index] = vga_entry(c, color);
}
 
void vga_putchar(char c){
    if(c == '\n'){
        vga_row++;
        vga_column = 0;
    }
    else if(c == '\t'){
        for(int i = 0; i <= 4; i++){
            vga_putchar(' ');
        }
    }
    else{
        vga_putentryat(c, vga_color, vga_column, vga_row);
    }
    if(++vga_column == VGA_WIDTH){
        vga_column = 0;
        if(++vga_row == VGA_HEIGHT){
            vga_row = 0;
        }
    }
}
 
void vga_write(const char* data, size_t size){
    for(size_t i = 0; i < size; i++){
        vga_putchar(data[i]);
    }
}
 
void vga_writestring(const char* data){
    vga_write(data, strlen(data));
}
