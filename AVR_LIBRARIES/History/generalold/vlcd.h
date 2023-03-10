/************************************************************************
Title:    LCD
Author:   Sergio Manuel Santos <sergio.salazar.santos@gmail.com>
File:     $Id: vlcd.h,v 0.2 2014/04/12 00:00:00 sergio Exp $
Software: AVR-GCC 4.1, AVR Libc 1.4
Hardware: AVR with built-in ADC, tested on ATmega128 at 16 Mhz
License:  GNU General Public License
Comment:
	  tested atemga 128 16Mhz, tested atemga 128 16Mhz, it works but not 
	  advised because it uses stdlib.h malloc for structure and microcontrollers 
	  do not like memory allocation, or mot e~well supported being glichy.
	  Rather use other library it is better and supports two lcd connected.  
************************************************************************/
#ifndef _VLCD_H_
	#define _VLCD_H_

/*
** constant and macro
*/
//ASIGN PORT PINS TO LCD (can be setup in any way)
#define RS 0
#define RW 1
#define EN 2
#define NC 3
#define DB0 4
#define DB1 5
#define DB2 6
#define DB3 7
/*
** variable
*/
struct parameter{
	volatile uint8_t *DDR;
	volatile uint8_t *PIN;
	volatile uint8_t *PORT;
	uint8_t detect;
};
struct vdisplay{
	struct parameter *parameter;
	/******/
	void (*write)(struct vdisplay this, char c, unsigned short D_I);
	char (*read)(struct vdisplay this, unsigned short D_I);
	void (*BF)(struct vdisplay this);
	void (*putch)(struct vdisplay this, char c);
	char (*getch)(struct vdisplay this);
	void (*string)(struct vdisplay this, const char *s);
	void (*clear)(struct vdisplay this);
	void (*gotoxy)(struct vdisplay this, unsigned int x, unsigned int y);
	void (*reboot)(struct vdisplay this);
};
typedef struct vdisplay VLCD;
/*
** procedure and function header
*/
VLCD VLCDenable(volatile uint8_t *ddr, volatile uint8_t *pin, volatile uint8_t *port);

#endif
/***EOF***/
