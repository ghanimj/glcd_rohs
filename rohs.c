#include <hal.h>

#include <rohs.h>

/* 128x64 graphical LCD time */

void init_glcd_pins(void) {
	gpio_set_mode(RS|R_W|DB0|DB5|DB6|DB7, GPIO_MODE_OUTPUT, ROHS_PORT_A);
	gpio_set_mode(DB1|DB2|DB3|DB4, GPIO_MODE_OUTPUT, ROHS_PORT_B);	
}

void display_set(void) {
	gpio_write_pin(RS|R_W|DB7|DB6, GPIO_PIN_RESET, ROHS_PORT_A);
	gpio_write_pin(DB5, GPIO_PIN_SET, ROHS_PORT_A);
	gpio_write_pin(DB4|DB3|DB2|DB1, GPIO_PIN_SET, ROHS_PORT_B);
	gpio_write_pin(DB0, GPIO_PIN_SET, ROHS_PORT_A);
}
