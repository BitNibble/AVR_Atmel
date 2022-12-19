/********************************************************************
	EXPLODE
Author: Sergio Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: all
Date: 16032021
Comment:
    Pin Analysis
********************************************************************/
/***Library***/
#include "avrmapping.h"
#include "explode.h"
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
//inic
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
	m128explode.a->XF = m128explodemapping.porta->pin;
	
	m128explode.b->XI = m128explode.b->XF;
	m128explode.b->XF = m128explodemapping.portb->pin;
	
	m128explode.c->XI = m128explode.c->XF;
	m128explode.c->XF = m128explodemapping.portc->pin;
	
	m128explode.d->XI = m128explode.d->XF;
	m128explode.d->XF = m128explodemapping.portd->pin;
	
	m128explode.e->XI = m128explode.e->XF;
	m128explode.e->XF = m128explodemapping.porte->pin;
	
	m128explode.f->XI = m128explode.f->XF;
	m128explode.f->XF = m128explodemapping.portf->pin;
	
	m128explode.g->XI = m128explode.g->XF;
	m128explode.g->XF = m128explodemapping.portg->pin;
	
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
#elif defined(GENERIC_EXPLODE)

//Constant & Macro
//Global File Variable
//Function File Header
void EXPLODEupdate(EXPLODE* self, uint8_t x);
uint8_t EXPLODEhh(EXPLODE* self);
uint8_t EXPLODEll(EXPLODE* self);
uint8_t EXPLODElh(EXPLODE* self);
uint8_t EXPLODEhl(EXPLODE* self);
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
	return explode; //return copy
}
// boot
void EXPLODEupdate(EXPLODE* self, uint8_t x)
{
	self->XI = self->XF;
	self->XF = x;
	self->HL = EXPLODEhl(self);
	self->LH = EXPLODElh(self);
	self->HH = EXPLODEhh(self);
	self->LL = EXPLODEll(self);
}
// hh
uint8_t EXPLODEhh(EXPLODE* self)
{
	return (self->XI & self->XF);
}
// ll
uint8_t EXPLODEll(EXPLODE* self)
{
	return ~(self->XI | self->XF);
}
// lh
uint8_t EXPLODElh(EXPLODE* self)
{
	uint8_t i;
	i = self->XI ^ self->XF;
	i &= self->XF;
	return i;
}
// hl
uint8_t EXPLODEhl(EXPLODE* self)
{
	uint8_t i;
	i = self->XF ^ self->XI;
	i &= self->XI;
	return i;
}
****/
#endif
/***Interrupt***/
/***Comment***
note: not defining interrupt function, or initializing an object will block the program.
*************/
/***EOF***/
