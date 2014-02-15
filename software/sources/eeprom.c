//#include <p18cxxx.h>
#include "p18f25k22.h"

/*
EEADR = range [0:255], that is 256 bytes
EEARRH = allows to address 1024 bytes

pic18f25k22 has 256 bytes of eeprom memory
*/
#include "eeprom.h"

void EEPROM_init(void)
{
	// unsigned char ee1 = EECON1;
	// EECON1bits.EEPGD		1 = flash program memory ; 0 = EEPROM data memory
	// EECON1bits.CFGS		1 = Configuration registers ; 0 = flash program or EEPROM data memory
	// EECON1bits.WRNE		1 = write operation are enable (clear on reset)
	// EECON1bits.WERR		1 = indicates an write error (during normal operation)
	// EECON1bits.WR		set by software to erase+start write operation ; cleared by hardware when done (see WERR)
							// There is also an interrupt when a write operation completes : EEIF of PIR2
	// EECON1bits.RD		same as WR but for read operation

	// unsigned char ee2 = EECON2;
	// Not a physical register, reads to 0

	// Nothing to initialize ?
}

unsigned char
EEPROM_read(eeprom_addr_t address)
{
	EEADR = address;		// address to write
	EECON1bits.EEPGD = 0;	// read EEPROM data memory, not flash program memory
	EECON1bits.CFGS = 0;	// access memory, not Configuration registers
	EECON1bits.RD = 1;		// start read operation
	return EEDATA;			// data is available at the very next instruction cycle
							// data will be available until next read or write operation

	// Extended : put to a part to EEADRH, mask value to EEARD. Check endianness.
}

void
EEPROM_write(eeprom_addr_t address, unsigned char data)
{
	EEADR = address;		// address to read
	EEDATA = data;			// data to write
	EECON1bits.EEPGD = 0;	// erase+write EEPROM data memory, not flash program memory
	EECON1bits.CFGS = 0;	// access memory, not Configuration registers
	EECON1bits.WREN = 1;	// enable erase+write operation

	INTCONbits.GIE = 0;		// recommanded to disable interrupts

	EECON2 = 0x55;			// Required sequence
	EECON2 = 0xAA;			// Required sequence

	EECON1bits.WR = 1;		// start erase+write operation

	while(PIR2bits.EEIF == 0)
	{}						// wait for the end of operation
	PIR2bits.EEIF = 0;		// clear interrupt flag

	INTCONbits.GIE = 1;		// enable interrupts again

	// Extended : put to a part to EEADRH, mask value to EEARD. Check endianness.
}

void
EEPROM_write_int(eeprom_addr_t address, unsigned int data)
{
	// C18 uses little-endian and int are 16 bit wide
	// Split data into 2 unsigned char and save them with the appropriate function
	unsigned char lsb = (data & 0x00FF);
	unsigned char msb = (data & 0xFF00) >> 8;
	EEPROM_write(address, lsb);
	EEPROM_write(address + 1, msb);
}

unsigned int
EEPROM_read_int(eeprom_addr_t address)
{
	unsigned char lsb = EEPROM_read(address);
	unsigned char msb = EEPROM_read(address + 1);
	unsigned int data = lsb + ((unsigned int)msb << 8);
	return data;
}