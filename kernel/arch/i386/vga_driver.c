#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include "vga_driver.h"
#include "io.h"
 
/* Check if the compiler thinks we are targeting the wrong operating system. */
#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif
 
/* This tutorial will only work for the 32-bit ix86 targets. */
#if !defined(__i386__)
#error "This tutorial needs to be compiled with a ix86-elf compiler"
#endif
 
 
static inline uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg){
    return fg | bg << 4;
}
 
static inline uint16_t vga_entry(unsigned char uc, uint8_t color){
    return (uint16_t) uc | (uint16_t) color << 8;
}
 
 
static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;
 
size_t vga_row;
size_t vga_column;
uint8_t vga_color;
uint16_t* vga_buffer;

void vga_move_cursor(unsigned short pos){
//    static unsigned short cur_pos = 0;
//    if(vga_column == 0 && vga_row == 0){
//        cur_pos = 0;
//    }
//    cur_pos += pos;
    outb(0x3D4, 14);                     //0x3D4 is the address of the port, 14 is the high_byte_command
    outb(0x3D5, ((pos >> 8) & 0x00FF));  //0x3D5 is the address of the data port    
    outb(0x3D4, 15);                     //15 is the low_byte_command
    outb(0x3D5, pos & 0x00FF);           //pos is the position to move the cursor to
}

void vga_initialize(void){
    //vga_move_cursor(0);
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
    //static char pc = '\0';
    if(c == '\n'){
        vga_row++;
        vga_column = -1;
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
    //pc = c;
}
 
void vga_write(const char* data, size_t size){
    for(size_t i = 0; i < size; i++){
        vga_putchar(data[i]);
    }
    vga_move_cursor(vga_row*VGA_WIDTH + vga_column);
}
 
void vga_writestring(const char *data){
    vga_write(data, strlen(data));
}
