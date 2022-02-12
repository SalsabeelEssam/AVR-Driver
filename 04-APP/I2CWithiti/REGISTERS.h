/*
 * REGISTERS.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: jo
 */

#ifndef REGISTERS_H_
#define REGISTERS_H_


                                                  /****DIO Registers***/


/* Group A Registers */
#define PORTA  *((volatile u8*)0x3B)
#define DDRA   *((volatile u8*)0x3A)
#define PINA   *((volatile u8*)0x39)

/* Group B Registers */
#define PORTB  *((volatile u8*)0x38)
#define DDRB  *((volatile u8*)0x37)
#define PINB   *((volatile u8*)0x36)

/* Group C Registers */
#define PORTC  *((volatile u8*)0x35)
#define DDRC   *((volatile u8*)0x34)
#define PINC   *((volatile u8*)0x33)

/* Group D Registers */
#define PORTD  *((volatile u8*)0x32)
#define DDRD   *((volatile u8*)0x31)
#define PIND  *((volatile u8*)0x30)



/*External interrupts */
#define MCUCR *((volatile u8 *)0x55)
#define MCUCSR *((volatile u8 *)0x54)
#define GICR *((volatile u8 *)0x5B)
#define GIFR *((volatile u8 *)0x5A)
#define SREG *((volatile u8 *)0x5F)


/* Analoge to digital converter */

#define ADMUX *((volatile u8 *)0x27)
#define ADCSRA *((volatile u8 *)0x26)
#define ADCH *((volatile u8 *)0x25)
#define ADCL *((volatile u8 *)0x24)
#define SFIOR *((volatile u8 *)0x50)


/*timer 0*/
#define TCCR0 *((volatile u8 *)0x53)
#define TCNT0 *((volatile u8 *)0x52)
#define TIMSK *((volatile u8 *)0x59)
#define TIFR  *((volatile u8 *)0x58)
#define OCR0  *((volatile u8 *)0x5C)

/*Timer 1*/
#define TCCR1A *((volatile u8 *)0x4F)
#define TCCR1B *((volatile u8 *)0x4E)
#define OCR1A  *((volatile u16 *)0x4A)
#define ICR1A  *((volatile u16 *)0x46)
#define TCNT1  *((volatile u16 *)0x4C)
#define OCR1B  *((volatile u16 *)0x48)
#define ICR1   *((volatile u16 *)0x46)



/*Timer 2*/
#define TCCR2 *((volatile u8 *)0x45)
#define TCNT2 *((volatile u8 *)0x44)
#define ASSR  *((volatile u8 *)0x42)
#define OCR2  *((volatile u8 *)0x43)



/*UART*/
#define UDR   *((volatile u8 *)0x2C)
#define UCSRA *((volatile u8 *)0x2B)
#define UCSRB *((volatile u8 *)0x2A)
#define UCSRC *((volatile u8 *)0x40)
#define UBRRL *((volatile u8 *)0x29)
#define UBRRH *((volatile u8 *)0x40)


/*SPI*/
#define SPCR *((volatile u8 *)0x2D)
#define SPSR *((volatile u8 *)0x2E)
#define SPDR *((volatile u8 *)0x2F)

/*I2C*/
#define TWBR *((volatile u8 *)0x20)
#define TWCR *((volatile u8 *)0x56)
#define TWSR *((volatile u8 *)0x21)
#define TWDR *((volatile u8 *)0x23)
#define TWAR *((volatile u8 *)0x22)

/*WDT*/
#define WDTCR *((volatile u8 *)0x41)

#endif /* REGISTERS_H_ */
