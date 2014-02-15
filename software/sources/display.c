// Display

/*
A display is made of seven-segment displays.
It knows the number of available SSEG displays
and what are the ports used to drive them (value port, control port and bit).

Conception notes :
- If dynamic memory allocation had been poindexble, we could have made a flexible array member in the structure.
*/

#include "display.h" // for prototype checking
#include "seven_seg.h"

// The unique display
DISPLAY_t display =
{
	456, ON,
	{{1, ON, IOPORTC, IOPORTA, BIT0},
	{2, ON, IOPORTC, IOPORTA, BIT1},
	{3, ON, IOPORTC, IOPORTA, BIT2}}
};

//***************************************************************************************************************************************************
// PUBLIC FUNCTION IMPLEMENTATIONS

void
 DISPLAY_init(void)
{
	int index = 0;

	for(index = 0; index < NUMBER_OF_SEVEN_SEG_DISPLAYS; index++)
	{
		SEVEN_SEG_init(&(display.ssds[index]));
	}
}


void
DISPLAY_set_value(int new_value)
{
	int index = 0;
	int digit = 0;
	int remaining = new_value;
	display.value = new_value;

	// Determine the digit for each segment
	if(display.value < 0)
	{
		for(index = 0; index < NUMBER_OF_SEVEN_SEG_DISPLAYS; index++)
		{
			SEVEN_SEG_set_value(&(display.ssds[index]), 0);
		}
	}
	else if(display.value > 999)
	{
		for(index = 0; index < NUMBER_OF_SEVEN_SEG_DISPLAYS; index++)
		{
			SEVEN_SEG_set_value(&(display.ssds[index]), 9);
		}
	}
	else
	{
		for(index = NUMBER_OF_SEVEN_SEG_DISPLAYS - 1; index >= 0; index--)
		{
			digit = remaining % 10;
			remaining = remaining / 10;
			SEVEN_SEG_set_value(&(display.ssds[index]), digit);
		}
	}
}


unsigned char
DISPLAY_get_value(void)
{
	return display.value;
}


void
DISPLAY_turn_on(void)
{	
	int index = 0;

	for(index = 0; index < NUMBER_OF_SEVEN_SEG_DISPLAYS; index++)
	{
		SEVEN_SEG_turn_on(&(display.ssds[index]));
	}
}


void
DISPLAY_turn_off(void)
{	
	int index = 0;

	for(index = 0; index < NUMBER_OF_SEVEN_SEG_DISPLAYS; index++)
	{
		SEVEN_SEG_turn_off(&(display.ssds[index]));
	}
}


void
DISPLAY_set_auto_off(unsigned int timeout)
{
	if(timeout == 0)
	{
		// Disable automatic turn off
	}
	else
	{
		// Enable automatic turn on
	}
}
