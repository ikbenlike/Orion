#include <stddef.h>

#define SERIAL_COM1_BASE                0x3F8      /* COM1 base port */
#define SERIAL_LINE_ENABLE_DLAB         0x80

#define serial_data_port(base)          (base)
#define serial_fifo_command_port(base)  (base + 2)
#define serial_line_command_port(base)  (base + 3)
#define serial_modem_command_port(base) (base + 4)
#define serial_line_status_port(base)   (base + 5)

void serial_set_baud(unsigned short com, unsigned short divisor);
void serial_configure_line(unsigned short com);
int serial_fifo_empty(unsigned int com);
void serial_write(const char *data, size_t size);
void serial_writestring(const char *data);
