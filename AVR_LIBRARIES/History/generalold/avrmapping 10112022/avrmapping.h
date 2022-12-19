/*********************************************************
	ATMEGA MAPPING
Author: Sergio Manuel Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: Atmega128 by ETT ET-BASE
Date: 10112022
Comment: 
	Virtual Image Atmega 128 and 328, mapping.
**********************************************************/
#ifndef _AVRMAPPING_H_
	#define _AVRMAPPING_H_

#if defined(__AVR_ATmega64__) || defined(__AVR_ATmega128__)
	#define AVR_ATMEGA_128_MAPPING

/**@{*/
#if (__GNUC__ * 100 + __GNUC_MINOR__) < 304
	#error "This library requires AVR-GCC 3.4 or later, update to newer AVR-GCC compiler !"
#endif

#include <inttypes.h>

/*********************************************************/
/***COMMON***/
// Low Byte High Byte
typedef struct {
	uint8_t H;
	uint8_t L;
} HighLowByte;

// Function Header
uint16_t ReadHLByte(HighLowByte reg);
uint16_t ReadLHByte(HighLowByte reg);
HighLowByte WriteHLByte(uint16_t val);
HighLowByte WriteLHByte(uint16_t val);
uint16_t SwapByte(uint16_t num);
/*********************************************************/
/*********************************************************
Comment out modules not being used
**********************************************************/
#include "atmega128.h"
#include "atmega128analog.h"
#include "atmega128interrupt.h"
#include "atmega128timer.h"
#include "atmega128i2c.h"
#include "atmega128uart.h"

/*********************************************************
***					SECOND LAYER					   ***
*********************************************************/
// GPWR
typedef struct {
	Atmega128GPWR_TypeDef* reg;
}Atmega128GPWR;

// Analog Comparator (AC)
typedef struct {
	Atmega128AnalogComparator_TypeDef* reg;
}Atmega128AnalogComparator;

// Analog to Digital Converter (ADC)
typedef struct {
	Atmega128AnalogToDigitalConverter_TypeDef* reg;
	#if defined(_ATMEGA128ANALOG_H_)
		ANALOG (*enable)( uint8_t Vreff, uint8_t Divfactor, int n_channel, ... );
	#endif
} Atmega128AnalogToDigitalConverter;

// Boot loader (BOOT_LOAD)
typedef struct {
	Atmega128BootLoader_TypeDef* reg;
} Atmega128BootLoader;

// CPU Register (CPU)
typedef struct {
	Atmega128CPURegister_TypeDef* reg;
} Atmega128CPURegister;

// EEPROM (EEPROM)
typedef struct {
	Atmega128Eeprom_TypeDef* reg;
} Atmega128Eeprom;

// External Interrupts (EXINT)
typedef struct {
	Atmega128ExternalInterrupts_TypeDef* reg;
	#if defined(_ATMEGA128INTERRUPT_H_)
		INTERRUPT (*enable)(void);
	#endif
} Atmega128ExternalInterrupts;

// I/O Port (PORTA)
typedef struct {
	Atmega128PORTA_TypeDef* reg;
}Atmega128PORTA;

// I/O Port (PORTB)
typedef struct {
	Atmega128PORTB_TypeDef* reg;
}Atmega128PORTB;

// I/O Port (PORTC)
typedef struct {
	Atmega128PORTC_TypeDef* reg;
}Atmega128PORTC;

// I/O Port (PORTD)
typedef struct {
	Atmega128PORTD_TypeDef* reg;
}Atmega128PORTD;

// I/O Port (PORTE)
typedef struct {
	Atmega128PORTE_TypeDef* reg;
}Atmega128PORTE;

// I/O Port (PORTF)
typedef struct {
	Atmega128PORTF_TypeDef* reg;
}Atmega128PORTF;

// I/O Port (PORTG)
typedef struct {
	Atmega128PORTG_TypeDef* reg;
} Atmega128PORTG;

// JTAG Interface (JTAG)
typedef struct {
	Atmega128JtagInterface_TypeDef* reg;
} Atmega128JtagInterface;

// Other Registers (MISC)
typedef struct {
	Atmega128OtherRegisters_TypeDef* reg;
} Atmega128OtherRegisters;

// Serial Peripheral Interface (SPI)
typedef struct {
	Atmega128SerialPeripherialInterface_TypeDef* reg;
	#if defined(_ATMEGA128SPI_H_)
		SPI enable(uint8_t master_slave_select, uint8_t data_order,  uint8_t data_modes, uint8_t prescaler);
	#endif
} Atmega128SerialPeripherialInterface;

// Timer/Counter, 16-bit (TC1)
typedef struct {
	Atmega128TimerCounter1_TypeDef* reg;
	#if defined(_ATMEGA128TIMER_H_)
		TIMER_COUNTER1 (*enable)(unsigned char wavegenmode, unsigned char interrupt);
	#endif
} Atmega128TimerCounter1;

// Timer/Counter, 16-bit (TC3)
typedef struct {
	Atmega128TimerCounter3_TypeDef* reg;
	#if defined(_ATMEGA128TIMER_H_)
		TIMER_COUNTER3 (*enable)(unsigned char wavegenmode, unsigned char interrupt);
	#endif
} Atmega128TimerCounter3;

// Timer/Counter, 8-bit (TC2)
typedef struct {
	Atmega128TimerCounter2_TypeDef* reg;
	#if defined(_ATMEGA128TIMER_H_)
		TIMER_COUNTER2 (*enable)(unsigned char wavegenmode, unsigned char interrupt);
	#endif
} Atmega128TimerCounter2;

// Timer/Counter, 8-bit A sync (TC0)
typedef struct {
	Atmega128TimerCounter0_TypeDef* reg;
	#if defined(_ATMEGA128TIMER_H_)
		TIMER_COUNTER0 (*enable)(unsigned char wavegenmode, unsigned char interrupt);
	#endif
} Atmega128TimerCounter0;

// Two Wire Serial Interface (TWI)
typedef struct {
	Atmega128TwoWireSerialInterface_TypeDef* reg;
	#if defined(_ATMEGA128I2C_H_)
		TWI (*enable)(uint8_t prescaler);
	#endif
} Atmega128TwoWireSerialInterface;

// USART (USART0)
typedef struct {
	Atmega128Usart0_TypeDef* reg;
	#if defined(_ATMEGA128UART_H_)
		UART (*enable)(unsigned int baudrate, unsigned int FDbits, unsigned int Stopbits, unsigned int Parity );
	#endif
} Atmega128Usart0;

// USART (USART1)
typedef struct {
	Atmega128Usart1_TypeDef* reg;
	#if defined(_ATMEGA128UART_H_)
		UART1 (*enable)(unsigned int baudrate, unsigned int FDbits, unsigned int Stopbits, unsigned int Parity );
	#endif
} Atmega128Usart1;

// Watchdog Timer (WDT)
typedef struct {
	Atmega128WatchdogTimer_TypeDef* reg;
} Atmega128WatchdogTimer;

/********ATMEGA 128 IMAGE*********/

typedef struct Atmega128{
	Atmega128GPWR gpwr;
	Atmega128AnalogComparator ac;
	Atmega128AnalogToDigitalConverter adc;
	Atmega128BootLoader boot_load;
	Atmega128CPURegister cpu;
	Atmega128Eeprom eeprom;
	Atmega128ExternalInterrupts exint;
	Atmega128PORTA porta;
	Atmega128PORTB portb;
	Atmega128PORTC portc;
	Atmega128PORTD portd;
	Atmega128PORTE porte;
	Atmega128PORTF portf;
	Atmega128PORTG portg;
	Atmega128JtagInterface jtag;
	Atmega128OtherRegisters misc;
	Atmega128SerialPeripherialInterface spi;
	Atmega128TimerCounter1 tc1;
	Atmega128TimerCounter3 tc3;
	Atmega128TimerCounter2 tc2;
	Atmega128TimerCounter0 tc0;
	Atmega128TwoWireSerialInterface twi;
	Atmega128Usart0 usart0;
	Atmega128Usart1 usart1;
	Atmega128WatchdogTimer wdt;
	/************************************/
	uint16_t (*readhlbyte)(HighLowByte reg);
	uint16_t (*readlhbyte)(HighLowByte reg);
	HighLowByte (*writehlbyte)(uint16_t val);
	HighLowByte (*writelhbyte)(uint16_t val);
	uint16_t (*swapbyte)(uint16_t num);
	/************************************/
}ATMEGA128;

ATMEGA128 ATMEGA128enable(void);

#elif defined(__AVR_ATmega328__) || defined(__AVR_ATmega328P__)
	#define AVR_ATMEGA_328_MAPPING

/**@{*/
#if (__GNUC__ * 100 + __GNUC_MINOR__) < 304
	#error "This library requires AVR-GCC 3.4 or later, update to newer AVR-GCC compiler !"
#endif

#include <inttypes.h>

/*************************************************************************************************/
/***COMMON***/
// Low Byte High Byte
typedef struct {
	uint8_t H;
	uint8_t L;
} HighLowByte;

// Function Header
uint16_t ReadHLByte(HighLowByte reg);
uint16_t ReadLHByte(HighLowByte reg);
HighLowByte WriteHLByte(uint16_t val);
HighLowByte WriteLHByte(uint16_t val);
uint16_t SwapByte(uint16_t num);
/*************************************************************************************************/

#include "atmega328.h"

typedef struct Atmega328{
	/***************HARDWARE MAPPING*************/
	Atmega328GPWR_TypeDef* gpwr;
	Atmega328AnalogComparator_TypeDef* ac;
	Atmega328AnalogToDigitalConverter_TypeDef* adc;
	Atmega328CPURegister_TypeDef* cpu;
	Atmega328Eeprom_TypeDef* eeprom;
	Atmega328ExternalInterrupts_TypeDef* exint;
	Atmega328PORTB_TypeDef* portb;
	Atmega328PORTC_TypeDef* portc;
	Atmega328PORTD_TypeDef* portd;
	Atmega328SerialPeripherialInterface_TypeDef* spi;
	Atmega328TimerCounter1_TypeDef* tc1;
	Atmega328TimerCounter0_TypeDef* tc0;
	Atmega328TimerCounter2_TypeDef* tc2;
	Atmega328TwoWireSerialInterface_TypeDef* twi;
	Atmega328Usart0_TypeDef* usart0;
	Atmega328WatchdogTimer_TypeDef* wdt;
	/********************************************/
	uint16_t (*readhlbyte)(HighLowByte reg);
	uint16_t (*readlhbyte)(HighLowByte reg);
	HighLowByte (*writehlbyte)(uint16_t val);
	HighLowByte (*writelhbyte)(uint16_t val);
	uint16_t (*swapbyte)(uint16_t num);
	/********************************************/
}ATMEGA328;

ATMEGA328 ATMEGA328enable(void);
#else
	#error "MCU not listed"
#endif

#endif
/***EOF***/
/*** COMMENT
I C U
***/
