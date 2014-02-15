// IO Port

#include "p18f25k22.h"
//#include <p18cxxx.h> --> is more generic but we need the exact list of ports

#include "io_port.h"


//***************************************************************************************************************************************************
// RESOURCES

static volatile near unsigned char * const io_read_ports[] =
{
    &PORTA,
    &PORTB,
    &PORTC,
    //&PORTD,
    &PORTE

};


static volatile near unsigned char * const io_write_ports[] =
{
    &LATA,
    &LATB,
    &LATC//,
    //&LATD,
    //&LATE

};

// It is maybe better to write to LAT than to PORT. 
// See http://www.developpez.net/forums/d1274221/general-developpement/programmation-systeme/embarque/soucis-carte-explorer-16-microchip/


static volatile near unsigned char * const io_dir_ports[] =
{
    &TRISA,
    &TRISB,
    &TRISC,
    //&TRISD,
    &TRISE

};
// TRIS set to 1 to disable output driver = set bit as input


//***************************************************************************************************************************************************
// FUNCTION IMPLEMENTATIONS

void IOPORT_port_dir(IOPORT_t port, IODIR_t dir)
{
	if(dir == IODIR_INPUT)
	{
		*io_dir_ports[port] = 0xFF;
	}
	else if (dir == IODIR_OUTPUT)
	{
		*io_dir_ports[port] = 0x00;
	}
}


void IOPORT_port_dir_precise(IOPORT_t port, unsigned char precise_dir)
{
	*io_dir_ports[port] = precise_dir;
}
	

void IOPORT_write(IOPORT_t port, unsigned char new_value)
{
	*io_write_ports[port] = new_value;
}


unsigned char IOPORT_read(IOPORT_t port)
{
	return *io_read_ports[port];
}

unsigned char IOPORT_read_bit(IOPORT_t port, PORTBIT_t bit)
{
	unsigned char port_value = IOPORT_read(port);
	return (port_value & (1U << bit)) >> bit;
}

// Set or unset a bit in C : 
// http://stackoverflow.com/questions/47981/how-do-you-set-clear-and-toggle-a-single-bit-in-c
void IOPORT_set_bit(IOPORT_t port, PORTBIT_t bit)
{
	*io_write_ports[port] |= (1U << bit);
}


void IOPORT_clear_bit(IOPORT_t port, PORTBIT_t bit)
{
	*io_write_ports[port]  &= ~(1U << bit);
}


void IOPORT_toggle_bit(IOPORT_t port, PORTBIT_t bit)
{
	*io_write_ports[port] ^= (1U << bit);
}


void IOPORT_bit_dir(IOPORT_t port, PORTBIT_t bit, IODIR_t dir)
{
	if(dir == IODIR_OUTPUT)
	{
		*io_dir_ports[port] &= ~(1U << bit);
	}
	else if(dir == IODIR_INPUT)
	{
		*io_dir_ports[port] |= 1U << bit;
	}
}