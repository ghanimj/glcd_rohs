#include <stdint.h>
#include <stdio.h>

#include <rcc.h>
#include <hal.h>
#include <uart.h>
#include <rohs.h>

int main() {
	uart2_init();
	systick_init();

	init_glcd_pins();
	display_set();

	for(;;) {
		delay(500);
	}
}

