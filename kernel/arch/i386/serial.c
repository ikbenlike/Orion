#include <stddef.h>
#include <string.h>
#include "serial.h"
#include "io.h" 

void serial_set_baud(unsigned short com, unsigned short divisor){
    outb(serial_line_command_port(com), SERIAL_LINE_ENABLE_DLAB);
    outb(serial_data_port(com), (divisor >> 8) & 0x00FF);
    outb(serial_data_port(com), divisor & 0x00FF);
}

void serial_configure_line(unsigned short com){
    outb(serial_line_command_port(com), 0x03);
}

int serial_fifo_empty(unsigned int com){
    return inb(serial_line_status_port(com)) & 0x20;
}

void serial_write(const char *data, size_t size){
    for(size_t i = 0; i < size; i++){
        outb(serial_data_port(SERIAL_COM1_BASE), (unsigned char)data[i]);
    }
}   

void serial_writestring(const char *data){
    serial_write(data, strlen(data));
}
