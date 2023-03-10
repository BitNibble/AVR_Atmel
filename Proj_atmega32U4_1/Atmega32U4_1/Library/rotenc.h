/************************************************************************
	ROTENC
Author: Sergio Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: Rotary encoder Potentiometer
Date: 25102020
Comment:
	Stable
************************************************************************/
#ifndef _ROTENC_H_
	#define _ROTENC_H_

/*** Compiler ***/
#if (__GNUC__ * 100 + __GNUC_MINOR__) < 304
	#error "This library requires AVR-GCC 3.4 or later, update to newer AVR-GCC compiler !"
#endif

/*** Working Frequency ***/

/*** Global Library ***/
#include <inttypes.h>

/*** Global Constant & Macro ***/

/*** Global Variable ***/
struct rotenc{
	// VARIABLIES
	uint8_t PinChnA;
	uint8_t PinChnB;
	uint8_t pchn;
	uint8_t chn;
	uint16_t num;
	// PROTOTYPES VTABLE
	struct rotenc (*rte)(struct rotenc *self, uint8_t data);
};
typedef struct rotenc ROTENC;

/*** Global Header ***/
ROTENC ROTENCenable(uint8_t ChnApin, uint8_t ChnBpin);

#endif
/***EOF***/

