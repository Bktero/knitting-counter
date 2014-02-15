#ifndef __IO_PORT_HEADER_H
#define __IO_PORT_HEADER_H

//***************************************************************************************************************************************************
// TYPES DEFINITIONS

typedef enum
{
	IOPORTA = 0,
	IOPORTB,
	IOPORTC,
	IOPORTD,
	IOPORTE,
	IOPORTF

} IOPORT_t;

typedef enum
{
	BIT0 = 0,
	BIT1,
	BIT2,
	BIT3,
	BIT4,
	BIT5,
	BIT6,
	BIT7

} PORTBIT_t;

typedef enum
{
	IODIR_OUTPUT = 0x00,
	IODIR_INPUT = 0x01

} IODIR_t;


//***************************************************************************************************************************************************
// PUBLIC API

// Set all the direction of a port to either input or ouput mode. All I/O are in the same mode (input or output).
void IOPORT_port_dir(IOPORT_t port, IODIR_t dir);

// Set the direction of a port the specified mode. The mode of each I/O can be specified.
void IOPORT_port_dir_precise(IOPORT_t port, unsigned char precise_dir);

// Write to the output port. It has no effect if port is in input mode.
void IOPORT_write(IOPORT_t port, unsigned char new_value);

// Read the input value of the port. Undefined value is returned if port is in output mode.
unsigned char IOPORT_read(IOPORT_t port);

// Read the value of a specific bit of a port. Returns 0 or 1.
unsigned char IOPORT_read_bit(IOPORT_t port, PORTBIT_t bit);

// Set the direction of a specific I/O of the port
void IOPORT_bit_dir(IOPORT_t port, PORTBIT_t bit, IODIR_t dir);

// Set or clear a specific bit of the output port. It has no effect if port is in input mode.
void IOPORT_set_bit(IOPORT_t port, PORTBIT_t bit);
void IOPORT_clear_bit(IOPORT_t port, PORTBIT_t bit);
void IOPORT_toggle_bit(IOPORT_t port, PORTBIT_t bit);




#endif // __IO_PORT_HEADER_H
