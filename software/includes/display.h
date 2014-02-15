#ifndef __DISPLAY_HEADER_H
#define __DISPLAY_HEADER_H

#include "on_off_state.h"
#include "seven_seg.h"

//***************************************************************************************************************************************************
// MACRO DEFINITIONS
#define NUMBER_OF_SEVEN_SEG_DISPLAYS	3


//***************************************************************************************************************************************************
// TYPES DEFINITIONS
typedef struct
{
	int value;
	ON_OFF_STATE_t state;
	SEVEN_SEG_t ssds[NUMBER_OF_SEVEN_SEG_DISPLAYS];

} DISPLAY_t;

//***************************************************************************************************************************************************
// GLOBAL VARIABLE

// The unique display defined in display.c
extern DISPLAY_t display; 

//***************************************************************************************************************************************************
// PUBLIC API

void DISPLAY_init(void);

void DISPLAY_set_value(int new_value);

int DSIP_get_value(void);

void DISPLAY_turn_on(void);

void DISPLAY_turn_off(void);

void DISPLAY_set_auto_off(unsigned int timeout);

#endif // __DISPLAY_HEADER_H