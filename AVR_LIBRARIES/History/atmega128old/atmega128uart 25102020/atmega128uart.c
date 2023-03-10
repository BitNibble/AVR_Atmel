/*************************************************************************
	ATMEGA128UART
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: ATmega128
Date: 25102020
Comment:
   Stable
*************************************************************************/
/***Library***/
#include "atmega128mapping.h"
/***Constant & Macro***/
/***size of RX/TX buffers***/
#define UART_RX_BUFFER_MASK ( UART_RX_BUFFER_SIZE - 1)
#define UART_TX_BUFFER_MASK ( UART_TX_BUFFER_SIZE - 1)
#if ( UART_RX_BUFFER_SIZE & UART_RX_BUFFER_MASK )
	#error "RX buffer size is not a power of 2"
#endif
#if ( UART_TX_BUFFER_SIZE & UART_TX_BUFFER_MASK )
	#error "TX buffer size is not a power of 2"
#endif
#if defined(__AVR_ATmega64__) || defined(__AVR_ATmega128__) 
	/***ATmega with two USART***/
	 #define ATMEGA_128_USART
	 #define UART0_RECEIVE_INTERRUPT   USART0_RX_vect
	 #define UART1_RECEIVE_INTERRUPT   USART1_RX_vect
	 #define UART0_TRANSMIT_INTERRUPT  USART0_UDRE_vect
	 #define UART1_TRANSMIT_INTERRUPT  USART1_UDRE_vect
#else
	#error "Not Atmega 128"
#endif
/***Global File Variable***/
ATMEGA128 m;

unsigned char UART_TxBuf[UART_TX_BUFFER_SIZE];
unsigned char UART_RxBuf[UART_RX_BUFFER_SIZE];
uint8_t UART_TxHead;
uint8_t UART_TxTail;
uint8_t UART_RxHead;
uint8_t UART_RxTail;
uint8_t UART_LastRxError;
unsigned char UART1_TxBuf[UART_TX_BUFFER_SIZE];
unsigned char UART1_RxBuf[UART_RX_BUFFER_SIZE];
uint8_t UART1_TxHead;
uint8_t UART1_TxTail;
uint8_t UART1_RxHead;
uint8_t UART1_RxTail;
uint8_t UART1_LastRxError;
uint8_t uart_index;
char uart_msg[UART_RX_BUFFER_SIZE];
int uart1_index;
char uart1_msg[UART_RX_BUFFER_SIZE];
/***Header***/
char* uart_read(void);
uint8_t uart_getc(void);
void uart_putc(const char data);
void uart_puts(const char *s );
int8_t uart_available(void);
void uart_flush(void);
unsigned char UART_Rx_pop(void);
void UART_Tx_push(unsigned char data);
/***/
char* uart1_read(void);
uint8_t uart1_getc(void);
void uart1_putc(const char data);
void uart1_puts(const char *s );
int8_t uart1_Rxavailable(void);
void uart1_Rxflush(void);
void uart1_Txflush(void);
unsigned char UART1_Rx_pop(void);
void UART1_Tx_push(const char data);
/***Procedure & Function***/
UART UARTenable(unsigned int baudrate, unsigned int FDbits, unsigned int Stopbits, unsigned int Parity )
{
	/***LOCAL VARIABLES***/
	/***INIC GLOBAL VARIABLES***/
    UART_TxHead = 0;
    UART_TxTail = 0;
    UART_RxHead = 0;
    UART_RxTail = 0;
	uart_index = 0;
	uart_msg[0] = '\0';
	/***struct***/
	UART uart;
	m = ATMEGA128enable();
	//local variables
	uart.ubrr = baudrate;
	/***FUNCTION POINTER***/
	uart.read = uart_read;
	uart.getc = uart_getc;
	uart.putc = uart_putc;
	uart.puts = uart_puts;
	uart.available = uart_available;
	uart.flush = uart_flush;
	/***Set baud rate***/
	if ( baudrate & 0x8000 ) 
	{
   		m.usart0.reg->ucsr0a = (1 << U2X0);  //Enable 2x speed 
   		baudrate &= ~0x8000;
   	}
	m.usart0.reg->ubrr0h = (unsigned char)(baudrate >> 8);
	m.usart0.reg->ubrr0l = (unsigned char) baudrate;
	/***Enable USART receiver and transmitter and receive complete interrupt***/
	m.usart0.reg->ucsr0b = _BV(RXCIE0) | (1 << RXEN0) | (1 << TXEN0);
	/***Set frame format: asynchronous, 8 data, no parity, 1 stop bit***/
	#ifdef URSEL0
		m.usart0->ucsr0c = (1 << URSEL0) | (3 << UCSZ00);
		uart.FDbits = 8;
		uart.Stopbits = 1;
		uart.Parity = 0;
	#else
		switch(FDbits){
			case 9:
				m.usart0.reg->ucsr0b |= (1 << UCSZ02);
				m.usart0.reg->ucsr0c |= (3 << UCSZ00);
				uart.FDbits = 9;
				break;
			case 8:
				m.usart0.reg->ucsr0b &= ~(1 << UCSZ02);
				m.usart0.reg->ucsr0c |= (3 << UCSZ00);
				uart.FDbits = 8;
				break;
			case 7:	
				m.usart0.reg->ucsr0b &= ~(1 << UCSZ02);
				m.usart0.reg->ucsr0c |= (1 << UCSZ01);
				m.usart0.reg->ucsr0c &= ~(1 << UCSZ00);
				uart.FDbits = 7;
				break;
			case 6:	
				m.usart0.reg->ucsr0b &= ~(1 << UCSZ02);
				m.usart0.reg->ucsr0c &= ~(1 << UCSZ01);
				m.usart0.reg->ucsr0c |= (1 << UCSZ00);
				uart.FDbits = 6;
				break;
			case 5:	
				m.usart0.reg->ucsr0b &= ~(1 << UCSZ02);
				m.usart0.reg->ucsr0c &= ~(3 << UCSZ00);
				uart.FDbits = 5;
				break;
			default:
				m.usart0.reg->ucsr0b &= ~(1 << UCSZ02);
				m.usart0.reg->ucsr0c |= (3 << UCSZ00);
				uart.FDbits = 8;
				break;
		}
		switch(Stopbits){
			case 1:
				m.usart0.reg->ucsr0c &= ~(1 << USBS0);
				uart.Stopbits = 1;
				break;
			case 2:
				m.usart0.reg->ucsr0c |= (1 << USBS0);
				uart.Stopbits = 2;
				break;	
			default:
				m.usart0.reg->ucsr0c &= ~(1 << USBS0);
				uart.Stopbits = 1;
				break;
		}
		switch(Parity){
			case 0:
				m.usart0.reg->ucsr0c &= ~(3 << UPM00);
				uart.Parity = 0;
				break;
			case 2:
				m.usart0.reg->ucsr0c |= (1 << UPM01);
				m.usart0.reg->ucsr0c &= ~(1 << UPM00);
				uart.Parity = 2;
				break;
			case 3:
				m.usart0.reg->ucsr0c |= (3 << UPM00);
				uart.Parity = 3;
				break;	
			default:
				m.usart0.reg->ucsr0c &= ~(3 << UPM00);
				uart.Parity = 0;
				break;
		}
	#endif
	m.cpu.reg->sreg |= _BV(GLOBAL_INTERRUPT_ENABLE);
	return uart;
}
/***unsigned int uart_getc(void)***/
uint8_t uart_getc(void)
{
    unsigned char data;
    if ( UART_RxHead == UART_RxTail ) {
        return (unsigned char)UART_NO_DATA;   /***no data available***/
    }
    /***calculate /store buffer index***/
    UART_RxTail = (UART_RxTail + 1) & UART_RX_BUFFER_MASK;
    /***get data from receive buffer***/
    data = UART_RxBuf[UART_RxTail];
    return (UART_LastRxError << 8) + data;
}
/***void uart_putc(unsigned char data)***/
void uart_putc(const char data)
{
	uint8_t head = UART_TxHead;
	UART_TxBuf[head] = data;
	UART_TxHead = (UART_TxHead + 1) & UART_TX_BUFFER_MASK;
	//while( UART_TxHead == UART_TxTail )
	//	;
	if ( UART_TxHead != UART_TxTail ){
		UART_TxBuf[UART_TxHead] = '\0';
	}else{
		//UART_TxHead=head;
		_delay_ms(30);
	}
	m.usart0.reg->ucsr0b |= _BV(UDRIE0);
}
/***void uart_puts(const char *s )***/
void uart_puts(const char *s )
{
    while (*s) 
      uart_putc(*s++);
}
/***int uart_available(void)***/
int8_t uart_available(void)
{
	return (UART_RX_BUFFER_MASK + UART_RxHead - UART_RxTail) % UART_RX_BUFFER_MASK;
}
/***void uart_flush(void)***/
void uart_flush(void)
{
	uart_msg[0] = '\0';
	uart_msg[1] = '\0';
	uart_msg[2] = '\0';
	UART_RxHead = UART_RxTail;
}
/***char* uart_read(void)***/
char* uart_read(void)
{
	char* ret;
	ret = "\0";
	if((UART_RxTail != UART_RxHead) && (uart_index < UART_RX_BUFFER_MASK)){
		uart_msg[uart_index] = UART_Rx_pop();
		uart_index++;
		uart_msg[uart_index] = '\0';
	//max index = UART_RX_BUFFER_MASK therefore UART_RX_BUFFER_MASK-1 max characters more implies overflow.
	}else{	
		uart_index = 0;
		ret = uart_msg;
	}
	return ret;
}
/***unsigned char UART_Rx_pop(void)***/
unsigned char UART_Rx_pop(void)
{
	if( UART_RxHead == UART_RxTail )
		return (unsigned char)UART_NO_DATA;
	UART_RxTail = (UART_RxTail + 1) & UART_RX_BUFFER_MASK;
	return UART_RxBuf[UART_RxTail];
}
/***void UART_Tx_push(unsigned char data)***/
void UART_Tx_push(unsigned char data)
{
    UART_TxHead = (UART_TxHead + 1) & UART_TX_BUFFER_MASK;
    while ( UART_TxHead == UART_TxTail ){
		; /***wait for free space in buffer, Tx interrupt will send to free space [Poll]***/
	}	
    UART_TxBuf[UART_TxHead] = data;
}
/***Interrupt***/
/***ISR(UART0_RECEIVE_INTERRUPT)***/
ISR(UART0_RECEIVE_INTERRUPT)
{
    unsigned char tmphead;
	unsigned char data;
	unsigned char bit9;
    unsigned char usr;
    /***read UART status register and UART data register***/
	usr  = m.usart0.reg->ucsr0a;
    bit9 = m.usart0.reg->ucsr0b;
    bit9 = 0x01 & (bit9 >> 1);
    /***/
    UART_LastRxError = (usr & (_BV(FE0) | _BV(DOR0)));
	/***calculate buffer index***/ 
    tmphead = ( UART_RxHead + 1) & UART_RX_BUFFER_MASK;
    if ( tmphead == UART_RxTail ) {	
        /***error: receive buffer overflow***/
        UART_LastRxError = UART_BUFFER_OVERFLOW >> 8; 
	}else{
		data = m.usart0.reg->udr0;
        /***store new index***/
        UART_RxHead = tmphead;
		if(UART_LastRxError){
			/***store indication data error in buffer***/
			UART_RxBuf[tmphead] = 'X';
		}else{
			/***store received data in buffer***/
			UART_RxBuf[tmphead] = data;
		}
    }
}
/***ISR(UART0_TRANSMIT_INTERRUPT)***/
ISR(UART0_TRANSMIT_INTERRUPT)
{
	uint8_t tail = UART_TxTail;
	m.usart0.reg->udr0 = UART_TxBuf[tail];
	UART_TxBuf[tail] = '\0';
	UART_TxTail = (UART_TxTail + 1) & UART_TX_BUFFER_MASK;
	if ( UART_TxTail != UART_TxHead )
		;
	else
		m.usart0.reg->ucsr0b &= ~_BV(UDRIE0);
}
/***these functions are only for ATmegas with two USART***/
/***UART1 UART1enable(unsigned int baudrate, unsigned int FDbits, unsigned int Stopbits, unsigned int Parity )***/
UART1 UART1enable(unsigned int baudrate, unsigned int FDbits, unsigned int Stopbits, unsigned int Parity )
{
	/***LOCAL VARIABLES***/
	/***GLOBAL VARIABLES INIC***/
    UART1_TxHead = 0;
    UART1_TxTail = 0;
    UART1_RxHead = 0;
    UART1_RxTail = 0;
	uart1_index = 0;
	uart1_msg[0] = '\0';
	/***struct***/
	UART1 uart;
	//local variables
	uart.ubrr = baudrate;
	/***FUNCTION POINTER***/
	uart.read = uart1_read;
	uart.getc = uart1_getc;
	uart.putc = uart1_putc;
	uart.puts = uart1_puts;
	uart.Rxavailable = uart1_Rxavailable;
	uart.Rxflush = uart1_Rxflush;
	uart.Txflush = uart1_Txflush;
    /***Set baud rate***/
    if ( baudrate & 0x8000 ) 
    {
    	m.usart1.reg->ucsr1a = (1 << U2X1);  //Enable 2x speed 
		baudrate &= ~0x8000;
    }
    m.usart1.reg->ubrr1h = (unsigned char)(baudrate >> 8);
    m.usart1.reg->ubrr1l = (unsigned char) baudrate;
    /***Enable USART receiver and transmitter and receive complete interrupt***/
    m.usart1.reg->ucsr1b = _BV(RXCIE1) | (1 << RXEN1)|(1 << TXEN1);
    /***Set frame format: asynchronous, 8data, no parity, 1stop bit***/
    #ifdef URSEL1
    	UCSR1C = (1 << URSEL1) | (3 << UCSZ10);
		uart.FDbits = 8;
		uart.Stopbits = 1;
		uart.Parity = 0;
    #else
    /***Parameters***/
    	switch(FDbits){
			case 9:
				m.usart1.reg->ucsr1b |= (1 << UCSZ12);
				m.usart1.reg->ucsr1c |= (3 << UCSZ10);
				uart.FDbits = 9;
				break;
			case 8:
				m.usart1.reg->ucsr1b &= ~(1 << UCSZ12);
				m.usart1.reg->ucsr1c |= (3 << UCSZ10);
				uart.FDbits = 8;
				break;
			case 7:	
				m.usart1.reg->ucsr1b &= ~(1 << UCSZ12);
				m.usart1.reg->ucsr1c |= (1 << UCSZ11);
				m.usart1.reg->ucsr1c &= ~(1 << UCSZ10);
				uart.FDbits = 7;
				break;
			case 6:	
				m.usart1.reg->ucsr1b &= ~(1 << UCSZ12);
				m.usart1.reg->ucsr1c &= ~(1 << UCSZ11);
				m.usart1.reg->ucsr1c |= (1 << UCSZ10);
				uart.FDbits = 6;
				break;
			case 5:	
				m.usart1.reg->ucsr1b &= ~(1 << UCSZ12);
				m.usart1.reg->ucsr1c &= ~(3 << UCSZ10);
				uart.FDbits = 5;
				break;
			default:
				m.usart1.reg->ucsr1b &= ~(1 << UCSZ12);
				m.usart1.reg->ucsr1c |= (3 << UCSZ10);
				uart.FDbits = 8;
				break;
		}
		switch(Stopbits){
				case 1:
					m.usart1.reg->ucsr1c &= ~(1 << USBS1);
					uart.Stopbits = 1;
					break;
				case 2:
					m.usart1.reg->ucsr1c |= (1 << USBS1);
					uart.Stopbits = 2;
					break;
				default:
					m.usart1.reg->ucsr1c &= ~(1 << USBS1);
					uart.Stopbits = 1;
					break;
		}
		switch(Parity){
			case 0://NONE
				m.usart1.reg->ucsr1c &= ~(3 << UPM10);
				uart.Parity = 0;
				break;
			case 2://EVEN
				m.usart1.reg->ucsr1c |= (1 << UPM11);
				m.usart1.reg->ucsr1c &= ~(1 << UPM10);
				uart.Parity = 2;
				break;
			case 3://ODD
				m.usart1.reg->ucsr1c |= (3 << UPM10);
				uart.Parity = 3;
				break;	
			default:
				m.usart1.reg->ucsr1c &= ~(3 << UPM10);
				uart.Parity = 0;
				break;
		}
    #endif
	//UART1_CONTROL &= ~_BV(UART1_UDRIE);
	m.cpu.reg->sreg |= _BV(GLOBAL_INTERRUPT_ENABLE);
	return uart;
}
/***void uart1_putc(unsigned char data)***/
void uart1_putc(const char data)
{
	uint8_t head = UART1_TxHead;
	UART1_TxBuf[head] = data;
	UART1_TxHead = (UART1_TxHead + 1) & UART_TX_BUFFER_MASK;
    //while( UART1_TxHead == UART1_TxTail )
	//	;
	if ( UART1_TxHead != UART1_TxTail ){
		UART1_TxBuf[UART1_TxHead] = '\0';
	}else{
		//UART1_TxHead=head;
		_delay_ms(30);
	}
	m.usart1.reg->ucsr1b |= _BV(UDRIE1);
}
/***void uart1_puts(const char *s )***/
void uart1_puts(const char *s )
{
    while (*s) 
      uart1_putc(*s++);
}
/***char* uart1_read(void)***/
char* uart1_read(void)
{
	char* ret;
	ret = "\0";
	if((UART1_RxTail != UART1_RxHead) && (uart1_index < UART_RX_BUFFER_MASK)){
		uart1_msg[uart1_index] = UART1_Rx_pop();
		uart1_index++;
		uart1_msg[uart1_index] = '\0';
	}else{
		uart1_index = 0;
		ret = uart1_msg;
	}
	return ret;
}
/***unsigned int uart1_getc(void)***/
uint8_t uart1_getc(void)
{
	unsigned char data;
	if ( UART1_RxHead == UART1_RxTail )
		return (unsigned char)UART_NO_DATA;   /***no data available***/
	/***calculate /store buffer index***/
	UART1_RxTail = (UART1_RxTail + 1) & UART_RX_BUFFER_MASK;
	/***get data from receive buffer***/
	data = UART1_RxBuf[UART1_RxTail];
	return (UART1_LastRxError << 8) + data;
}
/***unsigned char UART1_Rx_pop(void)***/
unsigned char UART1_Rx_pop(void)
{
	if( UART1_RxTail == UART1_RxHead )
		return (unsigned char)UART_NO_DATA;
	UART1_RxTail = (UART1_RxTail + 1) & UART_RX_BUFFER_MASK;
	return UART1_RxBuf[UART1_RxTail];
}
/***int uart1_Rxavailable(void)***/
int8_t uart1_Rxavailable(void)
{
	return (UART_RX_BUFFER_MASK + UART1_RxHead - UART1_RxTail) % UART_RX_BUFFER_MASK;
}
/***void uart1_Rxflush(void)***/
void uart1_Rxflush(void)
{
	uart1_msg[0] = '\0';
	uart1_msg[1] = '\0';
	uart1_msg[2] = '\0';
	UART1_RxHead = UART1_RxTail;
}
/***void uart1_Txflush(void)***/
void uart1_Txflush(void)
{
	UART1_TxHead = UART1_TxTail;
}
/***Interrupt***/
/***SIGNAL(UART1_RECEIVE_INTERRUPT)***/
SIGNAL(UART1_RECEIVE_INTERRUPT)
{
    unsigned char tmphead;
	unsigned char data;
	unsigned char bit9;
    unsigned char usr;
    /***read UART status register and UART data register***/
	usr  = m.usart1.reg->ucsr1a;
    bit9 = m.usart1.reg->ucsr1b;
    bit9 = 0x01 & (bit9 >> 1);
    /***/
    UART1_LastRxError = (usr & (_BV(FE1) | _BV(DOR1)));
	/***calculate buffer index***/
    tmphead = ( UART1_RxHead + 1) & UART_RX_BUFFER_MASK;
    if ( tmphead == UART1_RxTail ) {	
        /***error: receive buffer overflow, caracter is lost***/
        UART1_LastRxError = UART_BUFFER_OVERFLOW >> 8; 
	}else{
		data = m.usart1.reg->udr1;
        /***store new index***/
        UART1_RxHead = tmphead;
		if(UART1_LastRxError){
			/***store indication data error in buffer***/
			UART1_RxBuf[tmphead] = 'X';
		}else{
			/***store received data in buffer***/
			UART1_RxBuf[tmphead] = data;
		}
    }
}
/***SIGNAL(UART1_TRANSMIT_INTERRUPT)***/
SIGNAL(UART1_TRANSMIT_INTERRUPT)
{
	uint8_t tail = UART1_TxTail;
	m.usart1.reg->udr1 = UART1_TxBuf[tail];
	UART1_TxBuf[tail] = '\0';
	UART1_TxTail = (UART1_TxTail + 1) & UART_TX_BUFFER_MASK;
	if ( UART1_TxTail != UART1_TxHead )
        ;
    else
		m.usart1.reg->ucsr1b &= ~_BV(UDRIE1);
}
/***EOF***/
