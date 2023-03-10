/*************************************************************************
Title:    ATMEGA8535TIMER
Author:   Sergio Manuel Santos <sergio.salazar.santos@gmail.com>
File:     $Id: timer.h,v 0.1 2016/07/26 14:30:00 sergio Exp $
Software: AVR-GCC 4.1, AVR Libc 1.4.6 or higher 
License:  GNU General Public License
Comment:
	Very Stable
*************************************************************************/
#ifndef _ATMEGA8535TIMER_H_
  #define _ATMEGA8535TIMER_H_

#if (__GNUC__ * 100 + __GNUC_MINOR__) < 304
	#error "This library requires AVR-GCC 3.4 or later, update to newer AVR-GCC compiler !"
#endif
/*
** constant and macro
*/
/*
** variable
*/
struct TIMER_COUNTER0{
	// prototype pointers
	void (*compoutmode)(unsigned char compoutmode);
	void (*compare)(unsigned char compare);
	void (*start)(uint16_t prescaler);
	void (*stop)(void);
};
typedef struct TIMER_COUNTER0 TIMER_COUNTER0;
/**/
struct TIMER_COUNTER1{
	// prototype pointers
	void (*compoutmodeA)(unsigned char compoutmode);
	void (*compoutmodeB)(unsigned char compoutmode);
	void (*compareA)(uint16_t compareA);
	void (*compareB)(uint16_t compareB);
	void (*start)(uint16_t prescaler);
	void (*stop)(void);
};
typedef struct TIMER_COUNTER1 TIMER_COUNTER1;
/**/
struct TIMER_COUNTER2{
	// prototype pointers
	void (*compoutmode)(unsigned char compoutmode);
	void (*compare)(unsigned char compare);
	void (*start)(uint16_t prescaler);
	void (*stop)(void);
};
typedef struct TIMER_COUNTER2 TIMER_COUNTER2;
/*
** procedure and function header
*/
TIMER_COUNTER0 TIMER_COUNTER0enable(unsigned char wavegenmode, unsigned char interrupt);
TIMER_COUNTER1 TIMER_COUNTER1enable(unsigned char wavegenmode, unsigned char interrupt);
TIMER_COUNTER2 TIMER_COUNTER2enable(unsigned char wavegenmode, unsigned char interrupt);

#endif
/***EOF***/
