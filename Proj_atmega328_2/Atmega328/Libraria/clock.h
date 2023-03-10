/************************************************************************
	CLOCK
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
Hardware: all
Date: 25102020
Comment:
	Stable
************************************************************************/
#ifndef _CLOCK_H_
	#define _CLOCK_H_

/*** Compiler ***/
#if (__GNUC__ * 100 + __GNUC_MINOR__) < 304
	#error "This library requires AVR-GCC 3.4 or later, update to newer AVR-GCC compiler !"
#endif

/*** Working Frequency ***/

/*** Global Library ***/
#include <inttypes.h>

/*** Global Constant & Macro ***/
#define HORA 24

/*** Global Variable ***/
struct CLOCKTIME{
	int8_t hour;
	int8_t minute;
	int8_t second;
};
struct clck{
	void (*set)(uint8_t hour, uint8_t minute, uint8_t second);
	void (*increment)(void);
	void (*decrement)(void);
	uint8_t (*alarm)(uint8_t hour, uint8_t minute, uint8_t second);
	uint8_t (*second_count)(uint16_t second);
	void (*second_count_reset)(void);
	void (*second_count_stop)(void);
	void (*alarm_reset)(void);
	void (*alarm_stop)(void);
	char* (*show)(void);
};
typedef struct clck CLOCK;

/*** Global Header ***/
CLOCK CLOCKenable(uint8_t hour, uint8_t minute, uint8_t second);

#endif
/***EOF***/

