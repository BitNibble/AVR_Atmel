/************************************************************************
	ATMEGA MAPPING
Author: Sergio Manuel Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: Atmega128 by ETT ET-BASE
Date: 27122021
Comment: 
	Virtual Image Atmega 128 and 328, mapping.
************************************************************************/
#ifndef _AVRMAPPING_H_
	#define _AVRMAPPING_H_
/**@{*/
#if (__GNUC__ * 100 + __GNUC_MINOR__) < 304
	#error "This library requires AVR-GCC 3.4 or later, update to newer AVR-GCC compiler !"
#endif

/*
***
*/

#include <inttypes.h>

/*
*** COMMON
*/

// Low Byte High Byte
typedef struct HighLowByte{
	uint8_t H;
	uint8_t L;
} HighLowByte;

// GPWR
typedef struct Atmega128GPWR{
	uint8_t r0;
	uint8_t r1;
	uint8_t r2;
	uint8_t r3;
	uint8_t r4;
	uint8_t r5;
	uint8_t r6;
	uint8_t r7;
	uint8_t r8;
	uint8_t r9;
	uint8_t r10;
	uint8_t r11;
	uint8_t r12;
	uint8_t r13;
	uint8_t r14;
	uint8_t r15;
	uint8_t r16;
	uint8_t r17;
	uint8_t r18;
	uint8_t r19;
	uint8_t r20;
	uint8_t r21;
	uint8_t r22;
	uint8_t r23;
	uint8_t r24;
	uint8_t r25;
	uint8_t xl;
	uint8_t xh;
	uint8_t yl;
	uint8_t yh;
	uint8_t zl;
	uint8_t zh;
}Atmega128GPWR;

/*
***
*/

// Analog Comparator (AC)
typedef struct Atmega128AnalogComparator{
	uint8_t acsr;
	uint8_t fill[23]; // (0x40 - 0x28) - 1
	uint8_t sfior;
}Atmega128AnalogComparator;

// Analog to Digital Converter (ADC)
typedef struct Atmega128AnalogToDigitalConverter{
	HighLowByte adc;
	uint8_t adcsra;
	uint8_t admux;
} Atmega128AnalogToDigitalConverter;

// Boot loader (BOOT_LOAD)
typedef struct Atmega128BootLoader{
	uint8_t spmcsr;
} Atmega128BootLoader;

// CPU Register (CPU)
typedef struct Atmega128CPURegister{
	uint8_t mcucsr;
	uint8_t mcucr;
	uint8_t fill1[5]; // (5b - 55) - 1
	uint8_t rampz;
	uint8_t xdiv;
	HighLowByte sp;
	uint8_t sreg;
	uint8_t fill2[12]; // (6c - 5f) - 1
	uint8_t xmcrb;
	uint8_t xmcra;
	uint8_t fill3[1]; // (6f - 6d) - 1
	uint8_t osccal;	
} Atmega128CPURegister;

// EEPROM (EEPROM)
typedef struct Atmega128Eeprom{
	uint8_t eecr;
	uint8_t eedr;
	HighLowByte eear;
} Atmega128Eeprom;

// External Interrupts (EXINT)
typedef struct Atmega128ExternalInterrupts{
	uint8_t eifr;
	uint8_t eimsk;
	uint8_t eicrb;
	uint8_t fill[15]; // (6a - 5a) - 1
	uint8_t eicra;
} Atmega128ExternalInterrupts;

// I/O Port (PORTA)
typedef struct Atmega128PORTA{
	uint8_t pin;
	uint8_t ddr;
	uint8_t port;
}Atmega128PORTA;

// I/O Port (PORTB)
typedef struct Atmega128PORTB{
	uint8_t pin;
	uint8_t ddr;
	uint8_t port;
}Atmega128PORTB;

// I/O Port (PORTC)
typedef struct Atmega128PORTC{
	uint8_t pin;
	uint8_t ddr;
	uint8_t port;
}Atmega128PORTC;

// I/O Port (PORTD)
typedef struct Atmega128PORTD{
	uint8_t pin;
	uint8_t ddr;
	uint8_t port;
}Atmega128PORTD;

// I/O Port (PORTE)
typedef struct Atmega128PORTE{
	uint8_t pin;
	uint8_t ddr;
	uint8_t port;
}Atmega128PORTE;

// I/O Port (PORTF)
typedef struct Atmega128PORTF{
	uint8_t pin;
	uint8_t fill[64]; // (0x61 - 0x20) - 1
	uint8_t ddr;
	uint8_t port;
}Atmega128PORTF;

// I/O Port (PORTG)
typedef struct Atmega128PORTG{
	uint8_t pin;
	uint8_t ddr;
	uint8_t port;
} Atmega128PORTG;

// JTAG Interface (JTAG)
typedef struct Atmega128JtagInterface{
	uint8_t ocdr;
	uint8_t fill[17]; // (54 - 42) - 1
	uint8_t mcucsr;
} Atmega128JtagInterface;

// Other Registers (MISC)
typedef struct Atmega128OtherRegisters{
	uint8_t sfior;
} Atmega128OtherRegisters;

// Serial Peripheral Interface (SPI)
typedef struct Atmega128SerialPeripherialInterface{
	uint8_t spcr;
	uint8_t spsr;
	uint8_t spdr;
} Atmega128SerialPeripherialInterface;

// Timer/Counter, 16-bit (TC1)
typedef struct Atmega128TimerCounter1{
	uint8_t sfior;
	uint8_t fill1[5]; // (46 - 40) - 1
	HighLowByte icr1;
	HighLowByte ocr1b;
	HighLowByte ocr1a;
	HighLowByte tcnt1;
	uint8_t tccr1b;
	uint8_t tccr1a;
	uint8_t fill2[6]; // (56 - 4f) - 1
	uint8_t tifr;
	uint8_t timsk;
	uint8_t fill3[32]; // (78 - 57) - 1
	HighLowByte ocr1c;
	uint8_t tccr1c;
	uint8_t fill4; // (7c - 7a) - 1
	uint8_t etifr;
	uint8_t etimsk;
} Atmega128TimerCounter1;

// Timer/Counter, 16-bit (TC3)
typedef struct Atmega128TimerCounter3{
	uint8_t sfior;
	uint8_t fill1[59]; // (7c - 40) - 1
	uint8_t etifr;
	uint8_t etimsk;
	uint8_t fill2[2]; // (80 - 7d) - 1
	HighLowByte icr3;
	HighLowByte ocr3c;
	HighLowByte ocr3b;
	HighLowByte ocr3a;
	HighLowByte tcnt3;
	uint8_t tccr3b;
	uint8_t tccr3a;
	uint8_t tccr3c;
} Atmega128TimerCounter3;

// Timer/Counter, 8-bit (TC2)
typedef struct Atmega128TimerCounter2{
	uint8_t ocr2;
	uint8_t tcnt2;
	uint8_t tccr2;
	uint8_t fill[16]; // (56-45) - 1
	uint8_t tifr;
	uint8_t timsk;
} Atmega128TimerCounter2;

// Timer/Counter, 8-bit A sync (TC0)
typedef struct Atmega128TimerCounter0{
	uint8_t sfior;
	uint8_t fill1[15]; // (50 - 40) - 1
	uint8_t assr;
	uint8_t ocr0;
	uint8_t tcnt0;
	uint8_t tccr0;
	uint8_t fill2[2]; // (56-53) - 1
	uint8_t tifr;
	uint8_t timsk;
} Atmega128TimerCounter0;

// Two Wire Serial Interface (TWI)
typedef struct Atmega128TwoWireSerialInterface{
	uint8_t twbr;
	uint8_t twsr;
	uint8_t twar;
	uint8_t twdr;
	uint8_t twcr;
} Atmega128TwoWireSerialInterface;

// USART (USART0)
typedef struct Atmega128Usart0{
	uint8_t ubrr0l;
	uint8_t ucsr0b;
	uint8_t ucsr0a;
	uint8_t udr0;
	uint8_t fill[99]; // (90 - 2c) - 1
	uint8_t ubrr0h;
	uint8_t ucsr0c;
} Atmega128Usart0;

// USART (USART1)
typedef struct Atmega128Usart1{
	uint8_t ubrr1h;
	uint8_t ubrr1l;
	uint8_t ucsr1b;
	uint8_t ucsr1a;
	uint8_t udr1;
	uint8_t ucsr1c;
} Atmega128Usart1;

// Watchdog Timer (WDT)
typedef struct Atmega128WatchdogTimer{
	uint8_t wdtcr;
} Atmega128WatchdogTimer;

/*
***
ATMEGA 128 IMAGE
***
*/

typedef struct Atmega128{
	/***************HARDWARE MAPPING*************/
	Atmega128GPWR* gpwr;
	Atmega128AnalogComparator* ac;
	Atmega128AnalogToDigitalConverter* adc;
	Atmega128BootLoader* boot_load;
	Atmega128CPURegister* cpu;
	Atmega128Eeprom* eeprom;
	Atmega128ExternalInterrupts* exint;
	Atmega128PORTA* porta;
	Atmega128PORTB* portb;
	Atmega128PORTC* portc;
	Atmega128PORTD* portd;
	Atmega128PORTE* porte;
	Atmega128PORTF* portf;
	Atmega128PORTG* portg;
	Atmega128JtagInterface* jtag;
	Atmega128OtherRegisters* misc;
	Atmega128SerialPeripherialInterface* spi;
	Atmega128TimerCounter1* tc1;
	Atmega128TimerCounter3* tc3;
	Atmega128TimerCounter2* tc2;
	Atmega128TimerCounter0* tc0;
	Atmega128TwoWireSerialInterface* twi;
	Atmega128Usart0* usart0;
	Atmega128Usart1* usart1;
	Atmega128WatchdogTimer* wdt;
	/********************************************/
	uint16_t (*readhlbyte)(HighLowByte reg);
	uint16_t (*readlhbyte)(HighLowByte reg);
	HighLowByte (*writehlbyte)(uint16_t val);
	HighLowByte (*writelhbyte)(uint16_t val);
	uint16_t (*swapbyte)(uint16_t num);
	/********************************************/
}ATMEGA128;

/*
***
*/

ATMEGA128 ATMEGA128enable(void);
/*************************************************************************************************/
// Analog Comparator (AC)
typedef struct Atmega328AnalogComparator{
	uint8_t acsr;
	uint8_t fill[46]; // (0x7F - 0x50) - 1
	uint8_t didr1;
}Atmega328AnalogComparator;

// Analog to Digital Converter (ADC)
typedef struct Atmega328AnalogToDigitalConverter{
	HighLowByte adc;
	uint8_t adcsra;
	uint8_t adscrb;
	uint8_t admux;
	uint8_t fill; // (7E - 7c) - 1
	uint8_t didr0;
} Atmega328AnalogToDigitalConverter;

// CPU Register (CPU)
typedef struct Atmega328CPURegister{
	uint8_t gpior0;
	uint8_t fill1[11]; // (4a - 3e) - 1
	uint8_t gpior1;
	uint8_t gpior2;
	uint8_t fill2[7]; // (53 4b) - 1
	uint8_t smcr;
	uint8_t mcusr;
	uint8_t mcucr;
	uint8_t fill3; // (57 - 55) - 1
	uint8_t spmcsr;
	uint8_t fill4[5]; // (5d - 57) - 1
	HighLowByte sp;
	uint8_t sreg;
	uint8_t fill5; // (61 - 5F) - 1
	uint8_t clkpr;
	uint8_t fill6[2]; // (64 - 61) - 1
	uint8_t prr;
	uint8_t fill7; // (66 - 64) - 1
	uint8_t osccal;
} Atmega328CPURegister;

// EEPROM (EEPROM)
typedef struct Atmega328Eeprom{
	uint8_t eecr;
	uint8_t eedr;
	uint16_t eear;
} Atmega328Eeprom;

// External Interrupts (EXINT)
typedef struct Atmega328ExternalInterrupts{
	uint8_t pcifr;
	uint8_t eifr;
	uint8_t eimsk;
	uint8_t fill1[42]; // (68 - 3d) - 1
	uint8_t pcicr;
	uint8_t eicra;
	uint8_t fill2;
	uint8_t pcmsk0;
	uint8_t pcmsk1;
	uint8_t pcmsk2;
} Atmega328ExternalInterrupts;

// I/O Port (PORTB)
typedef struct Atmega328PORTB{
	uint8_t pin;
	uint8_t ddr;
	uint8_t port;
}Atmega328PORTB;

// I/O Port (PORTC)
typedef struct Atmega328PORTC{
	uint8_t pin;
	uint8_t ddr;
	uint8_t port;
}Atmega328PORTC;

// I/O Port (PORTD)
typedef struct Atmega328PORTD{
	uint8_t pin;
	uint8_t ddr;
	uint8_t port;
}Atmega328PORTD;

// Serial Peripheral Interface (SPI)
typedef struct Atmega328SerialPeripherialInterface{
	uint8_t spcr;
	uint8_t spsr;
	uint8_t spdr;
} Atmega328SerialPeripherialInterface;

// Timer/Counter, 16-bit (TC1)
typedef struct Atmega328TimerCounter1{
	uint8_t tifr1;
	uint8_t fill1[12]; // (43 - 36) - 1
	uint8_t gtccr;
	uint8_t fill2[43]; // (6f - 43) - 1
	uint8_t timsk1;
	uint8_t fill3[16]; // (80 - 6f) - 1
	uint8_t tccr1a;
	uint8_t tccr1b;
	uint8_t tccr1c;
	uint8_t fill4; // (84 - 82) - 1
	HighLowByte tcnt1;
	HighLowByte icr1;
	HighLowByte ocr1a;
	HighLowByte ocr1b;
} Atmega328TimerCounter1;

// Timer/Counter, 8-bit A sync (TC0)
typedef struct Atmega328TimerCounter0{
	uint8_t tifr0;
	uint8_t fill1[13]; // (43 - 35) - 1
	uint8_t gtccr;
	uint8_t tccr0a;
	uint8_t tccr0b;
	uint8_t tcnt0;
	uint8_t ocr0a;
	uint8_t ocr0b;
	uint8_t fill2[37]; // (6e - 48) - 1
	uint8_t timsk0;
} Atmega328TimerCounter0;

// Timer/Counter, 8-bit (TC2)
typedef struct Atmega328TimerCounter2{
	uint8_t tifr2;
	uint8_t fill1[11]; // (43 - 37) - 1
	uint8_t gtccr;
	uint8_t fill2[44]; // (70 - 43) - 1
	uint8_t timsk2;
	uint8_t fill3[63]; // (b0 - 70) - 1
	uint8_t tccr2a;
	uint8_t tccr2b;
	uint8_t tcnt2;
	uint8_t ocr2a;
	uint8_t ocr2b;
	uint8_t fill4; // (b6 - b4) - 1
	uint8_t assr;
} Atmega328TimerCounter2;

// Two Wire Serial Interface (TWI)
typedef struct Atmega328TwoWireSerialInterface{
	uint8_t twbr;
	uint8_t twsr;
	uint8_t twar;
	uint8_t twdr;
	uint8_t twcr;
	uint8_t twamr;
} Atmega328TwoWireSerialInterface;

// USART (USART0)
typedef struct Atmega328Usart0{
	uint8_t ucsr0a;
	uint8_t ucsr0b;
	uint8_t ucsr0c;
	uint8_t fill; // (c4 - c2) - 1
	HighLowByte ubrr0;
	uint8_t udr0;
} Atmega328Usart0;

// Watchdog Timer (WDT)
typedef struct Atmega328WatchdogTimer{
	uint8_t wdtcr;
} Atmega328WatchdogTimer;

/*
***
ATMEGA 328 IMAGE
***
*/

typedef struct Atmega328{
	/***************HARDWARE MAPPING*************/
	Atmega128GPWR* gpwr;
	Atmega328AnalogComparator* ac;
	Atmega328AnalogToDigitalConverter* adc;
	Atmega328CPURegister* cpu;
	Atmega328Eeprom* eeprom;
	Atmega328ExternalInterrupts* exint;
	Atmega328PORTB* portb;
	Atmega328PORTC* portc;
	Atmega328PORTD* portd;
	Atmega328SerialPeripherialInterface* spi;
	Atmega328TimerCounter1* tc1;
	Atmega328TimerCounter0* tc0;
	Atmega328TimerCounter2* tc2;
	Atmega328TwoWireSerialInterface* twi;
	Atmega328Usart0* usart0;
	Atmega328WatchdogTimer* wdt;
	/********************************************/
	uint16_t (*readhlbyte)(HighLowByte reg);
	uint16_t (*readlhbyte)(HighLowByte reg);
	HighLowByte (*writehlbyte)(uint16_t val);
	HighLowByte (*writelhbyte)(uint16_t val);
	uint16_t (*swapbyte)(uint16_t num);
	/********************************************/
}ATMEGA328;

/*
***
*/

ATMEGA328 ATMEGA328enable(void);
/*************************************************************************************************/
/***COMMON***/
uint16_t ReadHLByte(HighLowByte reg);
uint16_t ReadLHByte(HighLowByte reg);
HighLowByte WriteHLByte(uint16_t val);
HighLowByte WriteLHByte(uint16_t val);
uint16_t SwapByte(uint16_t num);
/*************************************************************************************************/
#endif
/***EOF***/
/*** COMMENT
I C U
***/
