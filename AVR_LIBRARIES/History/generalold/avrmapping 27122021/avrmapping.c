/*************************************************************************
	ATMEGA MAPPING
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: ATmega128
Date: 27122021
Comment:
   Mapping
*************************************************************************/
#include "avrmapping.h"
/*
***
COMMON
***
*/

#define GPWRaddr 0x0000

/*
***
*/

/*
***
*/

#if defined(__AVR_ATmega64__) || defined(__AVR_ATmega128__)
	#define ATMEGA_128_MAPPING
	
/**********************************************************/
#define AnalogComparator 0x0028
#define AnalogToDigitalConverter 0x0024
#define BootLoader 0x0068;
#define CPURegister 0x0054
#define Eeprom 0x003C
#define ExternalInterrupts 0x0058
#define PORTAaddr 0x0039
#define PORTBaddr 0x0036
#define PORTCaddr 0x0033
#define PORTDaddr 0x0030
#define PORTEaddr 0x0021
#define PORTFaddr 0x0020
#define PORTGaddr 0x0063
#define JtagInterface 0x0042
#define OtherRegisters 0x0040
#define SerialPeripherialInterface 0x002D
#define TimerCounter1 0x0040
#define TimerCounter3 0x0040
#define TimerCounter2 0x0043
#define TimerCounter0 0X0040
#define TwoWireSerialInterface 0x0070
#define Usart0 0x0029
#define Usart1 0x0098
#define WatchdogTimer 0x0041

/*
***
*/

/*
***
*/

ATMEGA128 ATMEGA128enable(void){ 
	struct Atmega128 ret;
	// Assign
	ret.gpwr = (Atmega128GPWR*) GPWRaddr;
	ret.ac = (Atmega128AnalogComparator*) AnalogComparator;
	ret.adc = (Atmega128AnalogToDigitalConverter*) AnalogToDigitalConverter;
	ret.boot_load = (Atmega128BootLoader*) BootLoader;
	ret.cpu = (Atmega128CPURegister*) CPURegister;
	ret.eeprom = (Atmega128Eeprom*) Eeprom;
	ret.exint = (Atmega128ExternalInterrupts*) ExternalInterrupts;
	ret.porta = (Atmega128PORTA*) PORTAaddr;
	ret.portb = (Atmega128PORTB*) PORTBaddr;
	ret.portc = (Atmega128PORTC*) PORTCaddr;
	ret.portd = (Atmega128PORTD*) PORTDaddr;
	ret.porte = (Atmega128PORTE*) PORTEaddr;
	ret.portf = (Atmega128PORTF*) PORTFaddr;
	ret.portg = (Atmega128PORTG*) PORTGaddr;
	ret.jtag = (Atmega128JtagInterface*) JtagInterface;
	ret.misc = (Atmega128OtherRegisters*) OtherRegisters;
	ret.spi = (Atmega128SerialPeripherialInterface*) SerialPeripherialInterface;
	ret.tc1 = (Atmega128TimerCounter1*) TimerCounter1;
	ret.tc3 = (Atmega128TimerCounter3*) TimerCounter3;
	ret.tc2 = (Atmega128TimerCounter2*) TimerCounter2;
	ret.tc0 = (Atmega128TimerCounter0*) TimerCounter0;
	ret.twi = (Atmega128TwoWireSerialInterface*) TwoWireSerialInterface;
	ret.usart0 = (Atmega128Usart0*) Usart0;
	ret.usart1 = (Atmega128Usart1*) Usart1;
	ret.wdt = (Atmega128WatchdogTimer*) WatchdogTimer;
	ret.readhlbyte = ReadHLByte;
	ret.readlhbyte = ReadLHByte;
	ret.writehlbyte = WriteHLByte;
	ret.writelhbyte = WriteLHByte;
	ret.swapbyte = SwapByte;
	return ret;
}

/*
***
*/

/**********************************************************/
#elif defined(__AVR_ATmega328__) || defined(__AVR_ATmega328P__)
	#define ATMEGA_328_MAPPING
	
/**********************************************************/
#define GPWRaddr 0x0000
#define AnalogComparator 0x0050
#define AnalogToDigitalConverter 0x0078
#define CPURegister 0x003E
#define Eeprom 0x003F
#define ExternalInterrupts 0x003B
#define PORTBaddr 0x0023
#define PORTCaddr 0x0026
#define PORTDaddr 0x0029
#define SerialPeripherialInterface 0x004C
#define TimerCounter1 0x0036
#define TimerCounter2 0x0037
#define TimerCounter0 0X0035
#define TwoWireSerialInterface 0x00B8
#define Usart0 0x00C0
#define WatchdogTimer 0x0060

/*
***
*/

/*
***
*/

ATMEGA328 ATMEGA328enable(void){
	struct Atmega328 ret;
	// Assign
	ret.gpwr = (Atmega128GPWR*) GPWRaddr;
	ret.ac = (Atmega328AnalogComparator*) AnalogComparator;
	ret.adc = (Atmega328AnalogToDigitalConverter*) AnalogToDigitalConverter;
	ret.cpu = (Atmega328CPURegister*) CPURegister;
	ret.eeprom = (Atmega328Eeprom*) Eeprom;
	ret.exint = (Atmega328ExternalInterrupts*) ExternalInterrupts;
	ret.portb = (Atmega328PORTB*) PORTBaddr;
	ret.portc = (Atmega328PORTC*) PORTCaddr;
	ret.portd = (Atmega328PORTD*) PORTDaddr;
	ret.spi = (Atmega328SerialPeripherialInterface*) SerialPeripherialInterface;
	ret.tc1 = (Atmega328TimerCounter1*) TimerCounter1;
	ret.tc0 = (Atmega328TimerCounter0*) TimerCounter0;
	ret.tc2 = (Atmega328TimerCounter2*) TimerCounter2;
	ret.twi = (Atmega328TwoWireSerialInterface*) TwoWireSerialInterface;
	ret.usart0 = (Atmega328Usart0*) Usart0;
	ret.wdt = (Atmega328WatchdogTimer*) WatchdogTimer;
	ret.readhlbyte = ReadHLByte;
	ret.readlhbyte = ReadLHByte;
	ret.writehlbyte = WriteHLByte;
	ret.writelhbyte = WriteLHByte;
	ret.swapbyte = SwapByte;
	return ret;
}

/*
***
*/

/**********************************************************/
#else
	#error "No mapping lib available for this chip"
#endif

/*
***
*/

/***COMMON***/
// always read or write the low byte last.
uint16_t ReadHLByte(HighLowByte reg)
{
	return (reg.H << 8) | reg.L;
}
uint16_t ReadLHByte(HighLowByte reg)
{
	return (reg.L << 8) | reg.H;
}
HighLowByte WriteHLByte(uint16_t val)
{
	HighLowByte reg; reg.H = (val >> 8); reg.L = val;
	return reg;
}
HighLowByte WriteLHByte(uint16_t val)
{
	HighLowByte reg; reg.L = (val >> 8); reg.H = val; 
	return reg;
}
uint16_t SwapByte(uint16_t num)
{
	uint16_t tp;
	tp = (num << 8);
	return (num >> 8) | tp;
}
/***EOF***/
/*** COMMENT
I C U
***/
