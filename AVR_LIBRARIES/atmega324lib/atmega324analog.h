/************************************************************************
Title:    Interrupt ANALOG INPUT
Author:   Sergio Manuel Santos <sergio.salazar.santos@gmail.com>
File:     $Id: atmega324analog.h,v 0.2 2018/08/18 13:00:00 Sergio Exp $
Software: AVR-GCC 4.1, AVR Libc 1.4
Hardware: AVR with built-in ADC, tested on ATmega128 at 16 Mhz
License:  GNU General Public License
Comment:
	Very Stable
************************************************************************/
#ifndef ATMEGA324ANALOG_H
	#define ATMEGA324ANALOG_H

/*** Compiler ***/
#if (__GNUC__ * 100 + __GNUC_MINOR__) < 304
	#error "This library requires AVR-GCC 3.4 or later, update to newer AVR-GCC compiler !"
#endif

/*** Constant & Macro ***/
#define ADC_NUMBER_SAMPLE 2 // ADC_NUMBER_SAMPLE^2 gives number of samples, note values can only range from 0 to 4.

/*** Global Variable ***/
struct ANALOG{
	// Parameters
	uint8_t VREFF;
	uint8_t DIVISION_FACTOR;
	// prototype pointers
	int (*read)(int selection);
};
typedef struct ANALOG ANALOG;

/*** Global Header ***/
ANALOG ANALOGenable( uint8_t Vreff, uint8_t Divfactor, int n_channel, ... );

#endif
/***EOF***/

