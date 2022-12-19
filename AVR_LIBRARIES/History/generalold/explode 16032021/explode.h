/************************************************************************
	EXPLODE
Author: Sergio Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: all
Date: 16032021
Comment:
	Pin Analysis
************************************************************************/
#ifndef _EXPLODE_H_
	#define _EXPLODE_H_

/***Library***/
#include <inttypes.h>
/***Constant & Macro***/
/***Global Variable***/
/************************************************/
#if defined(__AVR_ATmega128__)
	#define ATMEGA_128_EXPLODE
struct atmega128explodedata{
	uint8_t XI;
	uint8_t XF;
	uint8_t HL;
	uint8_t LH;
	uint8_t HH;
	uint8_t LL;
};
struct atmega128expld{
	struct atmega128explodedata *a, *b, *c, *d, *e, *f, *g;
	struct atmega128expld (*update)(void);
};
typedef struct atmega128expld EXPLODE;
/***Header***/
EXPLODE EXPLODEenable(void);
/************************************************/
#else
	#define GENERIC_EXPLODE
struct expld{
	/***Variable***/
	unsigned int XI;
	unsigned int XF;
	unsigned int HL;
	unsigned int LH;
	unsigned int HH;
	unsigned int LL;
	/***PROTOTYPES VTABLE***/
	void (*update)(struct expld* self, uint8_t x);
};
typedef struct expld EXPLODE;
/***Header***/
EXPLODE EXPLODEenable(void);
/************************************************/
#endif

#endif
/***Comment***
note: not defining interrupt function, or initializing an object will block the program.
*************/
/***EOF***/
