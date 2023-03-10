/************************************************************************
Title:    ATLFSM.h
Author:   Sergio Manuel Santos <sergio.salazar.santos@gmail.com>
File:     $Id: atlfsm.h,v 0.1 2016/08/21 14:00:00 Sergio Exp $
Software: GCC
Hardware:
License:  GNU General Public License
Comment:
	working on it
************************************************************************/
#ifndef _PCLFSM_H_
	#define _PCLFSM_H_

/*
** constant and macro
*/
/*
** variable
*/
struct lfsmdata{
uint8_t page;
uint8_t feedback;
uint8_t inhl;
uint8_t inlh;
uint8_t outhl;
uint8_t outlh;
};
typedef struct lfsmdata LFSMDATA;
/******/
struct lfsm{
	//Local Variables
	LFSMDATA *mem;
	uint16_t sizeeeprom;
	uint8_t page;
	uint8_t input;
	uint8_t output;
	//Function Pointers
	uint8_t (*read)(struct lfsm *r, uint8_t input);
	uint8_t (*learn)(struct lfsm *r, uint8_t input, uint8_t next, uint8_t page);
	uint16_t (*quant)(struct lfsm *r);
	uint8_t (*remove)(struct lfsm *r, uint8_t input);
	uint8_t (*deleteall)(struct lfsm *r);
	uint8_t (*get)(struct lfsm *r);
	void (*set)(struct lfsm *r, uint8_t output);
	uint8_t (*lh)(uint8_t xi, uint8_t xf);
	uint8_t (*hl)(uint8_t xi, uint8_t xf);
	uint8_t (*outputcalc)(uint8_t feeddback, uint8_t hl,uint8_t lh);
	uint8_t (*diff)(uint8_t xi, uint8_t xf);
};
typedef struct lfsm LFSM;
/*
** procedure and function header
*/
LFSM LFSMenable(LFSMDATA *eeprom, uint16_t sizeeeprom);

#endif
/***EOF***/
/***
***/
