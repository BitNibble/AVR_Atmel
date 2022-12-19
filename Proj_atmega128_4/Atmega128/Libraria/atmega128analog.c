/*************************************************************************
	ATMEGA128ANALOG
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: ATmega128
Date: 25102020
Comment:
	Stable
*************************************************************************/
/*** File Library ***/
#include "atmega128mapping.h"
#include <stdarg.h>

/*** File Constant & Macro ***/
// if using differential channels this value has to be greater than one
#define MAX_CHANNEL 32

#if defined(__AVR_ATmega64__) || defined(__AVR_ATmega128__)	
	#define ATMEGA_128_ANALOG
	#define MUX_MASK 31
#else
 	#error "Not Atmega 128"
#endif

/*** File Variable ***/
ATMEGA128 m;
static volatile int ADC_VALUE[MAX_CHANNEL];
static volatile int ADC_CHANNEL_GAIN[MAX_CHANNEL];
int ADC_N_CHANNEL;
static volatile int ADC_SELECTOR;
static volatile int adc_sample;
uint16_t adc_tmp;
static volatile unsigned char adc_n_sample;

/*** File Header ***/
int ANALOG_read(int selection);

/*** Procedure & Function ***/
ANALOG ANALOGenable( uint8_t Vreff, uint8_t Divfactor, int n_channel, ... )
// Interrupt running mode setup, and list of channels to be probed
{
	// LOCAL VARIABLES
	va_list list;
	int i;
	// initialize variables
	// GLOBAL VARIABLES INICIALIZE
	ADC_N_CHANNEL = (n_channel & MUX_MASK);
	ADC_SELECTOR = 0;
	adc_n_sample = 0;
	// PROTOTIPOS
	// int ANALOG_read(int channel);
	// ALLOCAÇÂO MEMORIA PARA Estrutura
	ANALOG analog;
	m = ATMEGA128enable();
	// import parameters
	// initialize parameters
	// Direccionar apontadores para PROTOTIPOS
	analog.read = ANALOG_read;
		
		m.adc.reg->admux &= ~(3 << REFS0);
		switch( Vreff ){
			case 0:
				analog.VREFF = 0;
			break;
			case 1:
				m.adc.reg->admux |= (1 << REFS0);
				analog.VREFF = 1;
			break;
			case 3:
				m.adc.reg->admux |= (3 << REFS0);
				analog.VREFF = 3;
			break;
			default:
				analog.VREFF = 0;
			break;
		}
		
		m.adc.reg->admux &= ~(1 << ADLAR);
		// m.adc->admux |= (1 << ADLAR);
		
		va_start(list, n_channel);
		for(i = 0; i < n_channel; i++){
			ADC_CHANNEL_GAIN[i] = va_arg(list, int);
		}
		va_end(list);
		m.adc.reg->admux &= ~MUX_MASK;
		m.adc.reg->admux |= (MUX_MASK & ADC_CHANNEL_GAIN[ADC_SELECTOR]);
		
		m.adc.reg->adcsra |= (1 << ADEN);
		m.adc.reg->adcsra |= (1 << ADSC);
		m.adc.reg->adcsra &= ~(1 << ADFR);
		m.adc.reg->adcsra |= (1 << ADIE);
		
		m.adc.reg->adcsra &= ~(7 << ADPS0);
		switch( Divfactor ){
			case 2: // 1
				m.adc.reg->adcsra |= (1 << ADPS0);
				analog.DIVISION_FACTOR = 2;
			break;
			case 4: // 2
				m.adc.reg->adcsra |= (1 << ADPS1);
				analog.DIVISION_FACTOR = 4;
			break;
			case 8: // 3
				m.adc.reg->adcsra |= (3 << ADPS0);
				analog.DIVISION_FACTOR = 8;
				break;
			case 16: // 4
				m.adc.reg->adcsra |= (1 << ADPS2);
				analog.DIVISION_FACTOR = 16;
			break;
			case 32: // 5
				m.adc.reg->adcsra |= (5 << ADPS0);
				analog.DIVISION_FACTOR = 32;
			break;
			case 64: // 6
				m.adc.reg->adcsra |= (6 << ADPS0);
				analog.DIVISION_FACTOR = 64;
			break;
			case 128: // 7
				m.adc.reg->adcsra |= (7 << ADPS0);
				analog.DIVISION_FACTOR = 128;
			break;
			default:
				m.adc.reg->adcsra |= (7 << ADPS0);
				analog.DIVISION_FACTOR = 128;
			break;
		}
	
	m.cpu.reg->sreg |= (1 << GLOBAL_INTERRUPT_ENABLE);
	return analog;
}
int ANALOG_read(int selection)
// Returns selected Channel ADC_VALUE
{
	uint8_t ADSC_FLAG;
	ADSC_FLAG = (1 << ADSC);
	if( !(m.adc.reg->adcsra & ADSC_FLAG) ){
		// ADC_SELECT
		
		m.adc.reg->adcsra |= (1 << ADSC);
	}	
	return ADC_VALUE[selection];
}

/*** File Interrupt ***/
ISR(ADC_vect)
// Function: ANALOG interrupt
// Purpose:  Read Analog Input
{
	// adc_tmp = m.adc->adc.L; // ADCL
	// adc_tmp |= (m.adc->adc.H << 8); // (ADCH << 8);
	// adc_tmp = *((uint16_t*)&m.adc->adc); // more then one way to skin a rabbit.
	adc_tmp = ReadHLByte(m.adc.reg->adc);
	if(adc_n_sample < (1 << ADC_NUMBER_SAMPLE)){
		adc_n_sample++;
		adc_sample += adc_tmp;
	}else{
		ADC_VALUE[ADC_SELECTOR] = adc_sample >> ADC_NUMBER_SAMPLE;
		adc_n_sample = adc_sample = 0;
		
		if(ADC_SELECTOR < ADC_N_CHANNEL)
			ADC_SELECTOR++;
		else
			ADC_SELECTOR = 0;
		m.adc.reg->admux &= ~MUX_MASK;
		m.adc.reg->admux |= (ADC_CHANNEL_GAIN[ADC_SELECTOR] & MUX_MASK);
	}
}

/*** File Interrupt ***/
// ISR(ADC_vect){ }

/***EOF***/

