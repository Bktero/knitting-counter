// Seven-Segment Display

// Prefix for functions : SEVEN_SEG
// Short for "Seven-Segment Display" : ssd

#include "io_port.h"
#include "seven_seg.h"


//***************************************************************************************************************************************************
// MACRO DEFINITIONS

// Hexadecimal value corresponding to each of the seven segments
#define SEVEN_SEG_seg_a 	0b00000010
#define SEVEN_SEG_seg_b		0b00000001
#define SEVEN_SEG_seg_c		0b01000000
#define SEVEN_SEG_seg_d 	0b00100000
#define SEVEN_SEG_seg_e 	0b00010000
#define SEVEN_SEG_seg_f 	0b00000100
#define SEVEN_SEG_seg_g 	0b00001000
#define SEVEN_SEG_seg_dp 	0b10000000


// Combine segments to get digits
#define SEVEN_SEG_DIGIT_0	(SEVEN_SEG_seg_a | SEVEN_SEG_seg_b | SEVEN_SEG_seg_c | SEVEN_SEG_seg_d | SEVEN_SEG_seg_e | SEVEN_SEG_seg_f)
#define SEVEN_SEG_DIGIT_1	(SEVEN_SEG_seg_b | SEVEN_SEG_seg_c ) 
#define SEVEN_SEG_DIGIT_2	(SEVEN_SEG_seg_a | SEVEN_SEG_seg_b | SEVEN_SEG_seg_d | SEVEN_SEG_seg_e | SEVEN_SEG_seg_g)
#define SEVEN_SEG_DIGIT_3	(SEVEN_SEG_seg_a | SEVEN_SEG_seg_b | SEVEN_SEG_seg_c | SEVEN_SEG_seg_d | SEVEN_SEG_seg_g)
#define SEVEN_SEG_DIGIT_4	(SEVEN_SEG_seg_b | SEVEN_SEG_seg_c | SEVEN_SEG_seg_f | SEVEN_SEG_seg_g)
#define SEVEN_SEG_DIGIT_5	(SEVEN_SEG_seg_a | SEVEN_SEG_seg_c | SEVEN_SEG_seg_d | SEVEN_SEG_seg_f | SEVEN_SEG_seg_g)
#define SEVEN_SEG_DIGIT_6	(SEVEN_SEG_seg_a | SEVEN_SEG_seg_c | SEVEN_SEG_seg_d | SEVEN_SEG_seg_e | SEVEN_SEG_seg_f | SEVEN_SEG_seg_g)
#define SEVEN_SEG_DIGIT_7	(SEVEN_SEG_seg_a | SEVEN_SEG_seg_b | SEVEN_SEG_seg_c )
#define SEVEN_SEG_DIGIT_8	(SEVEN_SEG_seg_a | SEVEN_SEG_seg_b | SEVEN_SEG_seg_c | SEVEN_SEG_seg_d | SEVEN_SEG_seg_e | SEVEN_SEG_seg_f | SEVEN_SEG_seg_g)
#define SEVEN_SEG_DIGIT_9	(SEVEN_SEG_seg_a | SEVEN_SEG_seg_b | SEVEN_SEG_seg_c | SEVEN_SEG_seg_d | SEVEN_SEG_seg_f | SEVEN_SEG_seg_g)

// Combine segments to get additional caracters
#define SEVEN_SEG_DASH		(SEVEN_SEG_seg_g)

// TODO add new macro and use them in translate()

#define SEVEN_SEG_INVALID	SEVEN_SEG_DASH

//***************************************************************************************************************************************************
// PRIVATE FUNCTION IMPLEMENTATIONS
static unsigned char translate(unsigned char value)
{
	unsigned char converted = SEVEN_SEG_DASH;

	switch(value)
	{
		case 0:
			converted = SEVEN_SEG_DIGIT_0;
			break;
		case 1:
			converted = SEVEN_SEG_DIGIT_1;
			break;
		case 2:
			converted = SEVEN_SEG_DIGIT_2;
			break;
		case 3:
			converted = SEVEN_SEG_DIGIT_3;
			break;
		case 4:
			converted = SEVEN_SEG_DIGIT_4;
			break;
		case 5:
			converted = SEVEN_SEG_DIGIT_5;
			break;
		case 6:
			converted = SEVEN_SEG_DIGIT_6;
			break;
		case 7:
			converted = SEVEN_SEG_DIGIT_7;
			break;
		case 8:
			converted = SEVEN_SEG_DIGIT_8;
			break;
		case 9:
			converted = SEVEN_SEG_DIGIT_9;
			break;

		default:
			break;
	}

	return converted; // TODO implementation
}


//***************************************************************************************************************************************************
// PUBLIC FUNCTION IMPLEMENTATIONS

void SEVEN_SEG_init(SEVEN_SEG_t *ssd)
{
	// Initialize the value port
	IOPORT_port_dir(ssd->value_port, IODIR_OUTPUT);
	
	// Initialize the control pin
	IOPORT_bit_dir(ssd->control_port, ssd->control_bit, IODIR_OUTPUT);

	// Put it in the described state
	SEVEN_SEG_set_value(ssd, 0);
	
	if(ssd->state == ON)
	{
		SEVEN_SEG_turn_on(ssd);
	}
	else
	{
		SEVEN_SEG_turn_off(ssd);
	}
}

void SEVEN_SEG_set_value(SEVEN_SEG_t *ssd, unsigned char new_value)
{
	ssd->value = new_value;
}

unsigned char SEVEN_SEG_get_value(SEVEN_SEG_t *ssd)
{
	return ssd->value;
}


void SEVEN_SEG_turn_on(SEVEN_SEG_t *ssd)
{
	ssd->state = ON;
	IOPORT_write(ssd->value_port, translate(ssd->value));
	IOPORT_set_bit(ssd->control_port, ssd->control_bit); 
}

void SEVEN_SEG_turn_off(SEVEN_SEG_t *ssd)
{
	ssd->state = OFF;
	IOPORT_clear_bit(ssd->control_port, ssd->control_bit);
}

ON_OFF_STATE_t SEVEN_SEG_get_state(SEVEN_SEG_t *ssd)
{
	return ssd->state;
}


// Functions for decimal point ?

