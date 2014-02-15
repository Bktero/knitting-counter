#ifndef __SEVEN_SEG_HEADER_H
#define __SEVEN_SEG_HEADER_H

#include "io_port.h"
#include "on_off_state.h"

//***************************************************************************************************************************************************
// TYPE DEFINITIONS

// A Seven Segment Display has a current value, a state (ON/OFF), a port where the current value and a pin (port+bit) to control ON/OFF state
typedef struct
{
	unsigned char value;
	ON_OFF_STATE_t state;
	IOPORT_t value_port;
	// decimal point state?
	IOPORT_t control_port;
	PORTBIT_t control_bit;

} SEVEN_SEG_t;

//***************************************************************************************************************************************************
// PUBLIC API

void SEVEN_SEG_init(SEVEN_SEG_t *ssd);

void SEVEN_SEG_set_value(SEVEN_SEG_t *ssd, unsigned char new_value);

unsigned char SEVEN_SEG_get_value(SEVEN_SEG_t *ssd);

void SEVEN_SEG_turn_on(SEVEN_SEG_t *ssd);

void SEVEN_SEG_turn_off(SEVEN_SEG_t *ssd);


ON_OFF_STATE_t SEVEN_SEG_get_state(SEVEN_SEG_t *ssd);

#endif // __SEVEN_SEG_HEADER_H
