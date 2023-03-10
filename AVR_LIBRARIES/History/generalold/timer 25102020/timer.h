/*************************************************************************
	TIMER
Author: Sergio Manuel Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: Listed if timer.c file
Date: 25102020
Comment:
	Very Stable
*************************************************************************/
#ifndef _TIMER_H_
 	#define _TIMER_H_

#if (__GNUC__ * 100 + __GNUC_MINOR__) < 304
	#error "This library requires AVR-GCC 3.4 or later, update to newer AVR-GCC compiler !"
#endif
/***Constant & Macro***/
/***Global Variable***/
struct TIMER_COUNTER0{
	// prototype pointers
	void (*compoutmode)(unsigned char compoutmode);
	void (*compoutmodeA)(unsigned char compoutmode);
	void (*compoutmodeB)(unsigned char compoutmode);
	void (*compare)(unsigned char compare);
	void (*compareA)(unsigned char compare);
	void (*compareB)(unsigned char compare);
	void (*start)(unsigned int prescaler);
	void (*stop)(void);
};
typedef struct TIMER_COUNTER0 TIMER_COUNTER0;
/***/
struct TIMER_COUNTER1{
	// prototype pointers
	void (*compoutmodeA)(unsigned char compoutmode);
	void (*compoutmodeB)(unsigned char compoutmode);
	void (*compoutmodeC)(unsigned char compoutmode);
	void (*compareA)(uint16_t compareA);
	void (*compareB)(uint16_t compareB);
	void (*compareC)(uint16_t compareC);
	void (*start)(unsigned int prescaler);
	void (*stop)(void);
};
typedef struct TIMER_COUNTER1 TIMER_COUNTER1;
/***/
struct TIMER_COUNTER2{
	// prototype pointers
	void (*compoutmode)(unsigned char compoutmode);
	void (*compoutmodeA)(unsigned char compoutmode);
	void (*compoutmodeB)(unsigned char compoutmode);
	void (*compare)(unsigned char compare);
	void (*compareA)(unsigned char compare);
	void (*compareB)(unsigned char compare);
	void (*start)(unsigned int prescaler);
	void (*stop)(void);
};
typedef struct TIMER_COUNTER2 TIMER_COUNTER2;
/***/
struct TIMER_COUNTER3{
	// prototype pointers
	void (*compoutmodeA)(unsigned char compoutmode);
	void (*compoutmodeB)(unsigned char compoutmode);
	void (*compoutmodeC)(unsigned char compoutmode);
	void (*compareA)(uint16_t compareA);
	void (*compareB)(uint16_t compareB);
	void (*compareC)(uint16_t compareC);
	void (*start)(unsigned int prescaler);
	void (*stop)(void);
};
typedef struct TIMER_COUNTER3 TIMER_COUNTER3;
/***Header***/
TIMER_COUNTER0 TIMER_COUNTER0enable(unsigned char wavegenmode, unsigned char interrupt);
TIMER_COUNTER1 TIMER_COUNTER1enable(unsigned char wavegenmode, unsigned char interrupt);
TIMER_COUNTER2 TIMER_COUNTER2enable(unsigned char wavegenmode, unsigned char interrupt);
TIMER_COUNTER3 TIMER_COUNTER3enable(unsigned char wavegenmode, unsigned char interrupt);

#endif
/***EOF***/
