#ifndef __EEPROM_H
#define __EEPROM_H


#define EEPROM_SIZE_IN_BYTES	256

// Check EEPROM memory size to determine an equivalent to a 'uintptr_t' type
#ifndef EEPROM_SIZE_IN_BYTES
	#error Please define EEPROM memory size
#else
	#if EEPROM_SIZE_IN_BYTES <= 256
		#warning Use reduced range for EEPROM memory addressing
		#undef EEPROM_USE_EXTENDED_MEMORY_ADDRESSING
		typedef unsigned char eeprom_addr_t;
	
	#elif (EEPROM_SIZE_IN_BYTES > 256 && EEPROM_SIZE_IN_BYTES <= 1024)
		#warning Use extended range for EEPROM memory addressing
		#define EEPROM_USE_EXTENDED_MEMORY_ADDRESSING
		typedef unsigned short eeprom_addr_t;

		#error Not implemented yet
	
	#elif EEPROM_SIZE_IN_BYTES > 1024
		#error EEPROM memory size is too big (should be in range [0:1024])

	#else
		#error Please define EEPROM memory size correctly
	#endif
#endif

void EEPROM_init(void);
void EEPROM_write(eeprom_addr_t address, unsigned char data);
unsigned char EEPROM_read(eeprom_addr_t address);

#endif