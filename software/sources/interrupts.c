
#include <p18cxxx.h>
#include <delays.h>

#include "counter.h"
#include "display.h"
#include "eeprom.h"

// Extern global  variables
extern DISPLAY_t display;
extern const eeprom_addr_t COUNTER_VALUE_ADDRESS_IN_EEPROM;

// ConvenienttTypedef to define ID for buttons
typedef enum {BUTTON_INCREASE = 0, BUTTON_RESET = 1, BUTTON_DECREASE = 2} BUTTON_t;

// Counter for inactivty and the value it must reach before going to low power mode
static const unsigned int MAX_INACTIVITY = 400;
static unsigned int inactivity = 0;

// Flags set to 1 when low power mode must be activated; 0 otherwise
static unsigned char low_power_mode = 0;

// Flags for button deboucing
static unsigned char debounce_needed[3] = {0, 0, 0};
static unsigned char debounce_counters[3] = {0, 0, 0};
static unsigned char DEBOUNCE_COUNTER_MAX = 5;

// Convenient function to indicate that a particular button must be debounced
static void debounce_ask(BUTTON_t button)
{
	debounce_needed[button] = 1;
	// Timer2 ISR will take care of deboucing
}

// Convenient function for housekeeping once debouncing is done for a button
static void debounce_done(BUTTON_t button)
{
	debounce_needed[button] = 0;
	debounce_counters[button] = 0;

	switch(button)
	{
		case BUTTON_INCREASE:
			INTCONbits.INT0IE = 1;
			break;
		case BUTTON_RESET:
			INTCON3bits.INT1IE = 1;
			break;
		case BUTTON_DECREASE:
			INTCON3bits.INT2IE = 1;
			break;
		default:
			break;
	}
}

//--------------------------------------------------------------------
// Actions for interrupts

// Actions when a button is pressed
//
// If normal mode, manage counter; otherwise, switch from low power mode to normal mode
// It resets the inactivity counter
static void button_action(BUTTON_t button)
{
	int counterValue;

	// Reset inactivity counter
	inactivity = 0;

	if(low_power_mode == 1)
	{
		// Display is off, turn if on
		low_power_mode = 0;
		T0CONbits.TMR0ON = 1;
		T2CONbits.TMR2ON = 1;
		DISPLAY_turn_on();
	}
	else
	{
		// Display is on, buttons have their normal actions
		switch(button)
		{
			case BUTTON_INCREASE :			
				COUNTER_increase();
				break;

			case BUTTON_RESET :
				COUNTER_reset();
				break;

			case BUTTON_DECREASE :
				COUNTER_decrease();
				break;

			default:
				// No way to handle this error case, do nothing
				break; // The label must not be empty to avoid compiler error
		}

		DISPLAY_set_value(COUNTER_get());

		// Save new counter
		counterValue = COUNTER_get();
		EEPROM_write_int(COUNTER_VALUE_ADDRESS_IN_EEPROM, counterValue);
	}
}

// Periodic action associated with Timer 1
//
// Dedicated to multiplex the 7 segment display
static void timer1_action(void)
{
	static unsigned int active_ssd = 0;

    switch(active_ssd)
    {
    	case 0:
	    	SEVEN_SEG_turn_on(&(display.ssds[0]));
	    	SEVEN_SEG_turn_off(&(display.ssds[1]));
	    	SEVEN_SEG_turn_off(&(display.ssds[2]));
	    	active_ssd = 1;
	    	break;
    	case 1:
	    	SEVEN_SEG_turn_off(&(display.ssds[0]));
	    	SEVEN_SEG_turn_on(&(display.ssds[1]));
	    	SEVEN_SEG_turn_off(&(display.ssds[2]));
	    	active_ssd = 2;
	    	break;
    	default:
	    	SEVEN_SEG_turn_off(&(display.ssds[0]));
	    	SEVEN_SEG_turn_off(&(display.ssds[1]));
	    	SEVEN_SEG_turn_on(&(display.ssds[2]));
	    	active_ssd = 0;
	    	break;
    }
}

// Periodic action associated with Timer 1
//
// Debounce buttons, manage inactivty to go to low power mode
static void timer2_action(void)
{
	// Deboucing the buttons that need it
	int i = 0;
	for(i = 0; i <= 2; i++)
	{
		if(debounce_needed[i] == 1)
		{
			if(++debounce_counters[i] > DEBOUNCE_COUNTER_MAX)
			{
				// Reset deboucing
				debounce_done(i);
			}
		}		
	}
/*
	if(debounce_needed[BUTTON_INCREASE] == 1)
	{
		if(++debounce_counters[BUTTON_INCREASE] > DEBOUNCE_COUNTER_MAX)
		{
			// Reset deboucing
			debounce_done(BUTTON_INCREASE);
		}
	}

	if(debounce_needed[BUTTON_RESET] == 1)
	{
		if(++debounce_counters[BUTTON_RESET] > DEBOUNCE_COUNTER_MAX)
		{

			// Reset deboucing
			debounce_done(BUTTON_RESET);
		}
	}

	if(debounce_needed[BUTTON_DECREASE] == 1)
	{
		if(++debounce_counters[BUTTON_DECREASE] > DEBOUNCE_COUNTER_MAX)
		{
			// Reset deboucing
			debounce_done(BUTTON_DECREASE);
		}
	}
*/

	// Inactivity manager
	if(inactivity < MAX_INACTIVITY)
	{
		inactivity++;
	}
	else
	{
		// Go low power
		low_power_mode = 1;
		T0CONbits.TMR0ON = 0;
		T2CONbits.TMR2ON = 0;
		DISPLAY_turn_off();
	}
}

//--------------------------------------------------------------------
// Interrupt routine implementations

/*
 * ISR for Timer 1, Timer2 and external interrupts (which are triggered when pressing the buttons)
 * Don't modify, instead modify the timer1_action(), timer2_action() and button_action() function.
 */

#pragma interrupt isr_timer_0
void isr_timer_0(void)
{
	// Action
    timer1_action();

	// Clear interrupt flag
    INTCONbits.TMR0IF = 0;
}

#pragma interrupt isr_timer_2
void isr_timer_2(void)
{
	// Action
	timer2_action();

	// Clear timer interrupt flag
	PIR1bits.TMR2IF = 0;
}

#pragma interrupt isr_button_0 // This pgrama tells the compiler to generate a RETFIE rather than a RETURN
void isr_button_0(void)
{
	// Reset INT0IE doesn't stop interrupts, so we need to check it manually
	if(INTCONbits.INT0IE == 1)
	{
		// Disable interrupt
		INTCONbits.INT0IE = 0;

		// Action
		button_action(BUTTON_INCREASE);
		
		// Ask for deboucing
		debounce_ask(BUTTON_INCREASE);
	}

	// Clear interrupt flag
	INTCONbits.INT0IF = 0;
}

#pragma interrupt isr_button_1
void isr_button_1(void)
{
	if(INTCON3bits.INT1IE == 1)
	{
		// Disable interrupt
		INTCON3bits.INT1IE = 0;

		// Action
		button_action(BUTTON_RESET);

		// Ask for deboucing
		debounce_ask(BUTTON_RESET);
	}

	// Clear interrupt flag
	INTCON3bits.INT1IF = 0;
}

#pragma interrupt isr_button_2
void isr_button_2(void)
{
	if(INTCON3bits.INT2IE == 1)
	{
		// Disable interrupt
		INTCON3bits.INT2IE = 0;

		// Action
		button_action(BUTTON_DECREASE);

		// Ask for deboucing
		debounce_ask(BUTTON_DECREASE);
	}

	// Clear interrupt flag
	INTCON3bits.INT2IF = 0;
}

//--------------------------------------------------------------------
// Connect interrupts to routines
#define ASM_GOTO(symbol) {_asm GOTO (symbol) _endasm}

// Place the following code in the specified section
#pragma code high_vector=0x08
void high_interrupt_vector(void)
{
	// Check what is the source of the interrupt and jump to the appropriate routine
	if(INTCONbits.INT0IF == 1)
		ASM_GOTO(isr_button_0);

	if(INTCON3bits.INT1IF == 1)
		ASM_GOTO(isr_button_1);

	if(INTCON3bits.INT2IF == 1)
		ASM_GOTO(isr_button_2);	

    if(INTCONbits.TMR0IF == 1)
    	ASM_GOTO(isr_timer_0);

	if(PIR1bits.TMR2IF == 1)
		ASM_GOTO(isr_timer_2);
}

// Return to compiler's default section
#pragma code
