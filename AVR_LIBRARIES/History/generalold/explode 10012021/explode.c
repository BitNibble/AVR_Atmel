/********************************************************************
	EXPLODE
Author: Sergio Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: all
Date: 10012022
Comment:
    Pin Analysis
********************************************************************/
/***Library***/
#include "atmega128mapping.h"
#include "explode.h"
/*******************************************************************/
#if defined(ATMEGA_128_EXPLODE)
/***Constant & Macro***/
/***Global File Variable***/
ATMEGA128 m128explodemapping;
EXPLODE m128explode;
struct atmega128explodedata A, B, C, D, E, F, G;
/***Function File Header***/
EXPLODE ATMEGA128EXPLODEupdate(void);
void ATMEGA128EXPLODEhh(void);
void ATMEGA128EXPLODEll(void);
void ATMEGA128EXPLODElh(void);
void ATMEGA128EXPLODEhl(void);
//initialize
/***Procedure & Function***/
EXPLODE EXPLODEenable(void)
{
	// struct object
	m128explodemapping = ATMEGA128enable();
	// initialize VAR
	A.XI = B.XI = C.XI = D.XI = E.XI = F.XI = G.XI = 0;
	A.XF = B.XF = C.XF = D.XF = E.XF = F.XF = G.XF = 0;
	m128explode.a = &A; m128explode.b = &B; m128explode.c = &C; m128explode.d = &D;
	m128explode.e = &E; m128explode.f = &F; m128explode.g = &G;
	// function pointers
	m128explode.update = ATMEGA128EXPLODEupdate;
	return m128explode; // return a global file variable. (only one instance)
}
// boot
EXPLODE ATMEGA128EXPLODEupdate(void)
{
	m128explode.a->XI = m128explode.a->XF;
	m128explode.a->XF = m128explodemapping.porta.reg->pin;
	
	m128explode.b->XI = m128explode.b->XF;
	m128explode.b->XF = m128explodemapping.portb.reg->pin;
	
	m128explode.c->XI = m128explode.c->XF;
	m128explode.c->XF = m128explodemapping.portc.reg->pin;
	
	m128explode.d->XI = m128explode.d->XF;
	m128explode.d->XF = m128explodemapping.portd.reg->pin;
	
	m128explode.e->XI = m128explode.e->XF;
	m128explode.e->XF = m128explodemapping.porte.reg->pin;
	
	m128explode.f->XI = m128explode.f->XF;
	m128explode.f->XF = m128explodemapping.portf.reg->pin;
	
	m128explode.g->XI = m128explode.g->XF;
	m128explode.g->XF = m128explodemapping.portg.reg->pin;
	
	ATMEGA128EXPLODEhh();
	ATMEGA128EXPLODEll();
	ATMEGA128EXPLODElh();
	ATMEGA128EXPLODEhl();
	
	return m128explode;
}
// hh
void ATMEGA128EXPLODEhh(void)
{
	m128explode.a->HH = (m128explode.a->XI & m128explode.a->XF);
	
	m128explode.b->HH = (m128explode.b->XI & m128explode.b->XF);
	
	m128explode.c->HH = (m128explode.c->XI & m128explode.c->XF);
	
	m128explode.d->HH = (m128explode.d->XI & m128explode.d->XF);
	
	m128explode.e->HH = (m128explode.e->XI & m128explode.e->XF);
	
	m128explode.f->HH = (m128explode.f->XI & m128explode.f->XF);
	
	m128explode.g->HH = (m128explode.g->XI & m128explode.g->XF);
}
// ll
void ATMEGA128EXPLODEll(void)
{
	m128explode.a->LL = ~(m128explode.a->XI | m128explode.a->XF);
	
	m128explode.b->LL = ~(m128explode.b->XI | m128explode.b->XF);
	
	m128explode.c->LL = ~(m128explode.c->XI | m128explode.c->XF);
	
	m128explode.d->LL = ~(m128explode.d->XI | m128explode.d->XF);
	
	m128explode.e->LL = ~(m128explode.e->XI | m128explode.e->XF);
	
	m128explode.f->LL = ~(m128explode.f->XI | m128explode.f->XF);
	
	m128explode.g->LL = ~(m128explode.g->XI | m128explode.g->XF);
}
// lh
void ATMEGA128EXPLODElh(void)
{
	m128explode.a->LH = m128explode.a->XI ^ m128explode.a->XF;
	m128explode.a->LH &= m128explode.a->XF;
	
	m128explode.b->LH = m128explode.b->XI ^ m128explode.b->XF;
	m128explode.b->LH &= m128explode.b->XF;
	
	m128explode.c->LH = m128explode.c->XI ^ m128explode.c->XF;
	m128explode.c->LH &= m128explode.c->XF;
	
	m128explode.d->LH = m128explode.d->XI ^ m128explode.d->XF;
	m128explode.d->LH &= m128explode.d->XF;
	
	m128explode.e->LH = m128explode.e->XI ^ m128explode.e->XF;
	m128explode.e->LH &= m128explode.e->XF;
	
	m128explode.f->LH = m128explode.f->XI ^ m128explode.f->XF;
	m128explode.f->LH &= m128explode.f->XF;
	
	m128explode.g->LH = m128explode.g->XI ^ m128explode.g->XF;
	m128explode.g->LH &= m128explode.g->XF;
}
// hl
void ATMEGA128EXPLODEhl(void)
{
	m128explode.a->HL = m128explode.a->XF ^ m128explode.a->XI;
	m128explode.a->HL &= m128explode.a->XI;
	
	m128explode.b->HL = m128explode.b->XF ^ m128explode.b->XI;
	m128explode.b->HL &= m128explode.b->XI;
	
	m128explode.c->HL = m128explode.c->XF ^ m128explode.c->XI;
	m128explode.c->HL &= m128explode.c->XI;
	
	m128explode.d->HL = m128explode.d->XF ^ m128explode.d->XI;
	m128explode.d->HL &= m128explode.d->XI;
	
	m128explode.e->HL = m128explode.e->XF ^ m128explode.e->XI;
	m128explode.e->HL &= m128explode.e->XI;
	
	m128explode.f->HL = m128explode.f->XF ^ m128explode.f->XI;
	m128explode.f->HL &= m128explode.f->XI;
	
	m128explode.g->HL = m128explode.g->XF ^ m128explode.g->XI;
	m128explode.g->HL &= m128explode.g->XI;
}
/*******************************************************************/
#elif defined(ATMEGA_328_EXPLODE)
/***Constant & Macro***/
/***Global File Variable***/
ATMEGA328 m328explodemapping;
EXPLODE m328explode;
struct atmega328explodedata B, C, D;
/***Function File Header***/
EXPLODE ATMEGA328EXPLODEupdate(void);
void ATMEGA328EXPLODEhh(void);
void ATMEGA328EXPLODEll(void);
void ATMEGA328EXPLODElh(void);
void ATMEGA328EXPLODEhl(void);
//initialize
/***Procedure & Function***/
EXPLODE EXPLODEenable(void)
{
	// struct object
	m328explodemapping = ATMEGA328enable();
	// initialize VAR
	B.XI = C.XI = D.XI = 0;
	B.XF = C.XF = D.XF = 0;
	m328explode.b = &B; m328explode.c = &C; m328explode.d = &D;
	// function pointers
	m328explode.update = ATMEGA328EXPLODEupdate;
	return m328explode; // return a global file variable. (only one instance)
}
// boot
EXPLODE ATMEGA328EXPLODEupdate(void)
{
	m328explode.b->XI = m328explode.b->XF;
	m328explode.b->XF = m328explodemapping.portb->pin;
	
	m328explode.c->XI = m328explode.c->XF;
	m328explode.c->XF = m328explodemapping.portc->pin;
	
	m328explode.d->XI = m328explode.d->XF;
	m328explode.d->XF = m328explodemapping.portd->pin;
	
	ATMEGA328EXPLODEhh();
	ATMEGA328EXPLODEll();
	ATMEGA328EXPLODElh();
	ATMEGA328EXPLODEhl();
	
	return m328explode;
}
// hh
void ATMEGA328EXPLODEhh(void)
{
	m328explode.b->HH = (m328explode.b->XI & m328explode.b->XF);
	
	m328explode.c->HH = (m328explode.c->XI & m328explode.c->XF);
	
	m328explode.d->HH = (m328explode.d->XI & m328explode.d->XF);
}
// ll
void ATMEGA328EXPLODEll(void)
{
	m328explode.b->LL = ~(m328explode.b->XI | m328explode.b->XF);
	
	m328explode.c->LL = ~(m328explode.c->XI | m328explode.c->XF);
	
	m328explode.d->LL = ~(m328explode.d->XI | m328explode.d->XF);
}
// lh
void ATMEGA328EXPLODElh(void)
{
	m328explode.b->LH = m328explode.b->XI ^ m328explode.b->XF;
	m328explode.b->LH &= m328explode.b->XF;
	
	m328explode.c->LH = m328explode.c->XI ^ m328explode.c->XF;
	m328explode.c->LH &= m328explode.c->XF;
	
	m328explode.d->LH = m328explode.d->XI ^ m328explode.d->XF;
	m328explode.d->LH &= m328explode.d->XF;
}
// hl
void ATMEGA328EXPLODEhl(void)
{
	m328explode.b->HL = m328explode.b->XF ^ m328explode.b->XI;
	m328explode.b->HL &= m328explode.b->XI;
	
	m328explode.c->HL = m328explode.c->XF ^ m328explode.c->XI;
	m328explode.c->HL &= m328explode.c->XI;
	
	m328explode.d->HL = m328explode.d->XF ^ m328explode.d->XI;
	m328explode.d->HL &= m328explode.d->XI;
}
/*******************************************************************/
#elif defined(GENERIC_EXPLODE)
//Constant & Macro
//Global File Variable
//Function File Header
void EXPLODEupdate(EXPLODE *self, uint8_t x);
uint8_t EXPLODEhh(EXPLODE *self);
uint8_t EXPLODEll(EXPLODE *self);
uint8_t EXPLODElh(EXPLODE *self);
uint8_t EXPLODEhl(EXPLODE *self);
EXPLODE EXPLODEread(EXPLODE *self);
//Procedure & Function
EXPLODE EXPLODEenable( void )
{
	// struct object
	struct expld explode;
	// initialize VAR
	explode.XI = 0;
	explode.XF = 0;
	// function pointers
	explode.update = EXPLODEupdate;
	explode.read = EXPLODEread;
	return explode; //return copy
}
// boot
void EXPLODEupdate(EXPLODE *self, uint8_t x)
{
	self->XI = self->XF;
	self->XF = x;
	self->HL = EXPLODEhl(self);
	self->LH = EXPLODElh(self);
	self->HH = EXPLODEhh(self);
	self->LL = EXPLODEll(self);
}
// hh
uint8_t EXPLODEhh(EXPLODE *self)
{
	return (self->XI & self->XF);
}
// ll
uint8_t EXPLODEll(EXPLODE *self)
{
	return ~(self->XI | self->XF);
}
// lh
uint8_t EXPLODElh(EXPLODE *self)
{
	uint8_t i;
	i = self->XI ^ self->XF;
	i &= self->XF;
	return i;
}
// hl
uint8_t EXPLODEhl(EXPLODE *self)
{
	uint8_t i;
	i = self->XF ^ self->XI;
	i &= self->XI;
	return i;
}
// read
EXPLODE EXPLODEread(EXPLODE *self)
{
	return *self;
}
/********************************************************************/
#endif
/***Interrupt***/
/***EOF***/

