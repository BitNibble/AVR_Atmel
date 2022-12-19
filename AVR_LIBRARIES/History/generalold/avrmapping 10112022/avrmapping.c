/*************************************************************************
	ATMEGA MAPPING
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: ATmega128 and ATmega328
Date: 10112022
Comment:
   Mapping
*************************************************************************/
#include"avrmapping.h"

#if defined(AVR_ATMEGA_128_MAPPING)
/**********************************************************/
#define GPWRaddr 0x0000
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

ATMEGA128 ATMEGA128enable(void){ 
	struct Atmega128 ret;
	// Assign
	ret.gpwr.reg = (Atmega128GPWR_TypeDef*) GPWRaddr;
	ret.ac.reg = (Atmega128AnalogComparator_TypeDef*) AnalogComparator;
	ret.adc.reg = (Atmega128AnalogToDigitalConverter_TypeDef*) AnalogToDigitalConverter;
	#if defined(_ATMEGA128ANALOG_H_)
		ret.adc.enable = ANALOGenable;
	#endif
	ret.boot_load.reg = (Atmega128BootLoader_TypeDef*) BootLoader;
	ret.cpu.reg = (Atmega128CPURegister_TypeDef*) CPURegister;
	ret.eeprom.reg = (Atmega128Eeprom_TypeDef*) Eeprom;
	ret.exint.reg = (Atmega128ExternalInterrupts_TypeDef*) ExternalInterrupts;
	#if defined(_ATMEGA128INTERRUPT_H_)
		ret.exint.enable = INTERRUPTenable;
	#endif
	ret.porta.reg = (Atmega128PORTA_TypeDef*) PORTAaddr;
	ret.portb.reg = (Atmega128PORTB_TypeDef*) PORTBaddr;
	ret.portc.reg = (Atmega128PORTC_TypeDef*) PORTCaddr;
	ret.portd.reg = (Atmega128PORTD_TypeDef*) PORTDaddr;
	ret.porte.reg = (Atmega128PORTE_TypeDef*) PORTEaddr;
	ret.portf.reg = (Atmega128PORTF_TypeDef*) PORTFaddr;
	ret.portg.reg = (Atmega128PORTG_TypeDef*) PORTGaddr;
	ret.jtag.reg = (Atmega128JtagInterface_TypeDef*) JtagInterface;
	ret.misc.reg = (Atmega128OtherRegisters_TypeDef*) OtherRegisters;
	ret.spi.reg = (Atmega128SerialPeripherialInterface_TypeDef*) SerialPeripherialInterface;
	#if defined(_ATMEGA128SPI_H_)
		ret.spi.enable = SPIenable;
	#endif
	ret.tc1.reg = (Atmega128TimerCounter1_TypeDef*) TimerCounter1;
	#if defined(_ATMEGA128TIMER_H_)
		ret.tc1.enable = TIMER_COUNTER1enable;
	#endif
	ret.tc3.reg = (Atmega128TimerCounter3_TypeDef*) TimerCounter3;
	#if defined(_ATMEGA128TIMER_H_)
		ret.tc3.enable = TIMER_COUNTER3enable;
	#endif
	ret.tc2.reg = (Atmega128TimerCounter2_TypeDef*) TimerCounter2;
	#if defined(_ATMEGA128TIMER_H_)
		ret.tc2.enable = TIMER_COUNTER2enable;
	#endif
	ret.tc0.reg = (Atmega128TimerCounter0_TypeDef*) TimerCounter0;
	#if defined(_ATMEGA128TIMER_H_)
		ret.tc0.enable = TIMER_COUNTER0enable;
	#endif
	ret.twi.reg = (Atmega128TwoWireSerialInterface_TypeDef*) TwoWireSerialInterface;
	#if defined(_ATMEGA128I2C_H_)
		ret.twi.enable = I2Cenable;
	#endif
	ret.usart0.reg = (Atmega128Usart0_TypeDef*) Usart0;
	#if defined(_ATMEGA128UART_H_)
		ret.usart0.enable = UARTenable;
	#endif
	ret.usart1.reg = (Atmega128Usart1_TypeDef*) Usart1;
	#if defined(_ATMEGA128UART_H_)
		ret.usart1.enable = UART1enable;
	#endif
	ret.wdt.reg = (Atmega128WatchdogTimer_TypeDef*) WatchdogTimer;
	/***func***/
	ret.readhlbyte = ReadHLByte;
	ret.readlhbyte = ReadLHByte;
	ret.writehlbyte = WriteHLByte;
	ret.writelhbyte = WriteLHByte;
	ret.swapbyte = SwapByte;
	return ret;
}

/*************************************************************************************************/
/***COMMON***/
// Function Definition
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
/*************************************************************************************************/

#elif defined(AVR_ATMEGA_328_MAPPING)
	
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

ATMEGA328 ATMEGA328enable(void){
	struct Atmega328 ret;
	// Assign
	ret.gpwr = (Atmega328GPWR_TypeDef*) GPWRaddr;
	ret.ac = (Atmega328AnalogComparator_TypeDef*) AnalogComparator;
	ret.adc = (Atmega328AnalogToDigitalConverter_TypeDef*) AnalogToDigitalConverter;
	ret.cpu = (Atmega328CPURegister_TypeDef*) CPURegister;
	ret.eeprom = (Atmega328Eeprom_TypeDef*) Eeprom;
	ret.exint = (Atmega328ExternalInterrupts_TypeDef*) ExternalInterrupts;
	ret.portb = (Atmega328PORTB_TypeDef*) PORTBaddr;
	ret.portc = (Atmega328PORTC_TypeDef*) PORTCaddr;
	ret.portd = (Atmega328PORTD_TypeDef*) PORTDaddr;
	ret.spi = (Atmega328SerialPeripherialInterface_TypeDef*) SerialPeripherialInterface;
	ret.tc1 = (Atmega328TimerCounter1_TypeDef*) TimerCounter1;
	ret.tc0 = (Atmega328TimerCounter0_TypeDef*) TimerCounter0;
	ret.tc2 = (Atmega328TimerCounter2_TypeDef*) TimerCounter2;
	ret.twi = (Atmega328TwoWireSerialInterface_TypeDef*) TwoWireSerialInterface;
	ret.usart0 = (Atmega328Usart0_TypeDef*) Usart0;
	ret.wdt = (Atmega328WatchdogTimer_TypeDef*) WatchdogTimer;
	ret.readhlbyte = ReadHLByte;
	ret.readlhbyte = ReadLHByte;
	ret.writehlbyte = WriteHLByte;
	ret.writelhbyte = WriteLHByte;
	ret.swapbyte = SwapByte;
	return ret;
}

/*************************************************************************************************/
/***COMMON***/
// Function Definition
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
/*************************************************************************************************/

#endif
/***EOF***/
/*** COMMENT
I C U
***/
