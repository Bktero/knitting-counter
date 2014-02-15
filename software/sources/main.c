// LICENSE

/** C O N F I G U R A T I O N   B I T S ******************************/
#pragma config FOSC = INTIO67 // will give a 1Mhz internal oscillator
#pragma config WDTEN = OFF

/** I N C L U D E S **************************************************/
//#include "p18f25k22.h"
// If the project is correctly configured, the compiler knows the target part number.
// So, it is better to include the generic header file.
#include <p18cxxx.h>

#include <delays.h>
// delay : 250 cycles == 1ms.

#include "counter.h"
#include "display.h"
#include "eeprom.h"
#include "io_port.h"
#include "on_off_state.h"
#include "seven_seg.h"


/*
SUMMARY FROM THE ELECTRONIC SCHEMATICS

RA[0:2] control the power of the seven segment displays
RB[0:2] receive the commands from the 3 buttons
RB[3:5] control the state of the 3 LEDs
RC[0:7] control the value of the seven segments displays

*/
// Private variables
static const IOPORT_t port_buttons = IOPORTB;
static const PORTBIT_t button_0 = BIT0;
static const PORTBIT_t button_1 = BIT1;
static const PORTBIT_t button_2 = BIT2;

static const IOPORT_t port_leds = IOPORTB;
/*
// Those two LEDs are not connected. Solder them if needed!
static const PORTBIT_t led_0 = BIT3;
static const PORTBIT_t led_1 = BIT4;
*/
static const PORTBIT_t green_led = BIT5;

// Global variables
const eeprom_addr_t COUNTER_VALUE_ADDRESS_IN_EEPROM = 0;


//--------------------------------------------------------------------
// Init and main
void __init(void)
{
	//---------------------------------------------------------
	// EEPROM
	EEPROM_init();


	//---------------------------------------------------------
	// GPIOs
	
	// Set ports A and B as digital, not analog
	ANSELA = 0x00;
	ANSELB = 0x00;
	
	// Disable PORTB internal pull-ups
	INTCON2bits.RBPU = 1;

	// Set port correclty for buttons and LEDs
	IOPORT_bit_dir(port_buttons, button_0, IODIR_INPUT);
	IOPORT_bit_dir(port_buttons, button_1, IODIR_INPUT);
	IOPORT_bit_dir(port_buttons, button_2, IODIR_INPUT);
	
	//IOPORT_bit_dir(port_leds, led_0, IODIR_OUTPUT);
	//IOPORT_bit_dir(port_leds, led_1, IODIR_OUTPUT);
	IOPORT_bit_dir(port_leds, green_led, IODIR_OUTPUT);
	
	// Init LEDs to off
	IOPORT_clear_bit(port_leds, green_led);

	// Init display
	DISPLAY_init();
	

	//---------------------------------------------------------
	// INTERRUPTS with this GPIOs
	
	// Clear the peripheral interrupt flags
	PIR1 = 0;

	// Enable external interrupts on RB[0:2] for button.
	// IMPORTANT: External interrupts always have high priority.
	// IMPORTANT: seems like these bits have no effect --> http://www.microchip.com/forums/m738982.aspx
	INTCONbits.INT0IE = 1;
	INTCON3bits.INT1IE = 1;
	INTCON3bits.INT2IE = 1;

	// Interrupt only on rising edges (= pressing)
	INTCON2bits.INTEDG0 = 1;
	INTCON2bits.INTEDG1 = 1;
	INTCON2bits.INTEDG2 = 1;

	// Clear external interrupt flags
	INTCONbits.INT0IF = 0;
	INTCON3bits.INT1IF = 0;
	INTCON3bits.INT2IF = 0;

	// Enable interrupt priority level mechanism
	RCONbits.IPEN = 1;

	// Enable interrupts
	INTCONbits.GIEH = 1;
	INTCONbits.GIEL = 1;


	//---------------------------------------------------------
	// TIMER0 for 7 segment display multiplexing

    // Clear TIMER0 overflow interrupt flag
    INTCONbits.TMR0IF = 0;

    // TIMER0 is high priority interrupt
    INTCON2bits.TMR0IP = 1;

    // Enable TIMER0 overflow interrupt
    INTCONbits.TMR0IE = 1; 

    /* Configure TIMER0:
    - stopped		(TMR0ON = 0)
    - 16 bits		(T08BIT = 0)
    - mode timer 	(TOCS = 0)
    - increment on low_to_high transition	(T0SE = 0) --> for mode counter
    - prescaler assigned	(PSA = 0)
    - 1:4 prescale  (T0PS<2:0> = 001)
    */
    //T0CON = 0b00000001;

    //T0CON = 0b01001000; // 8 bits with but no prescale

    //T0CON = 0b01000010; // good value
	T0CON = 0b01000001; // blink less

    // Reset timer value
    TMR0H = 0;
    TMR0L = 0;
    // WARNING: Always write the high byte first for correct timer value update

    // Finally, start TIMER0
    T0CONbits.TMR0ON = 1;

	//---------------------------------------------------------
	// TIMER2 for button deboucing and managing inactivity

	// Clear timer interrupt flag
	PIR1bits.TMR2IF = 0;

    // Set timer priority to high
    IPR1bits.TMR2IP = 1;

    // Enable interrupt
    PIE1bits.TMR2IE = 1;

    // Reset timer value
    TMR2 = 0;

    /* Configure TIMER2:
	- bit7 : unimplemented
	- bit6-3 : 0000 means postscaler = 1 (TxOUTPS<3:0>)
	- bit2 : 0 pour OFF (TMRxON)
    - bit1-0 : 00 means prescaler = 1  (TxCKPS<2:0>)
    */
    T2CON = 0b00001111; // postscaler 2 / on / prescaler 16

	// Timer period
	PR2 = 0x0FF;

    // Start TIMER2
    T2CONbits.TMR2ON = 1;
}

void main(void)
{
	// Retrieve counter value saved from previous execution
	unsigned int counter = EEPROM_read_int(COUNTER_VALUE_ADDRESS_IN_EEPROM);

	COUNTER_set(counter);
	COUNTER_set_minimum(0);
	COUNTER_set_maximum(999);

	// Display it
	DISPLAY_set_value(COUNTER_get());


    //*****************************************************************
	// Now, wait for interrupts. Everything is done in their handlers.
	while(1)
	{
		Nop();
	}
}


