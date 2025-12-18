#pragma once

#include <stdint.h>

#include <hal.h>

#define RS PIN_NUM(3)
#define R_W PIN_NUM(2)
#define DB0 PIN_NUM(10)
#define DB5 PIN_NUM(8)
#define DB6 PIN_NUM(9)
#define DB7 PIN_NUM(4)
#define ROHS_PORT_A 'A'

#define DB1 PIN_NUM(3)
#define DB2 PIN_NUM(5)
#define DB3 PIN_NUM(4)
#define DB4 PIN_NUM(10)
#define ROHS_PORT_B 'B'

void init_glcd_pins(void);
void display_set(void);
