/*
 * main.c
 *
 *  Created on: May 31, 2021
 *      Author: Salsabeel Essam
 */

#include "STD_TYPE.h"
#include "BIT_MATH.h"
#include "DIO_INTERFACE.h"

#include <util/delay.h>

int main(void) {

	/*pin 1&4*/
	DIO_SetPinDirection(PORTA, PIN7, OUTPUT);
	DIO_SetPinDirection(PORTB, PIN7, OUTPUT);

	/*pin 2&3*/
	DIO_SetPinDirection(PORTC, PIN7, OUTPUT);
	DIO_SetPinDirection(PORTD, PIN7, OUTPUT);

	/* SWITCHS INPUT + PULL RESISTOR */
	DIO_SetPinDirection(PORTC, PIN0, INPUT);
	DIO_SetPinDirection(PORTD, PIN0, INPUT);

	DIO_SetPinValue(PORTC, PIN0, HIGH);
	DIO_SetPinValue(PORTD, PIN0, HIGH);
// TWO TRANSISTOR
	while (1) {
		DIO_SetPinValue(PORTA, PIN7, HIGH);
		DIO_SetPinValue(PORTB, PIN7, HIGH);

		DIO_SetPinValue(PORTC, PIN7, LOW);
		DIO_SetPinValue(PORTD, PIN7, LOW);
		_delay_ms(2000);

		DIO_SetPinValue(PORTB, PIN7, LOW);
		DIO_SetPinValue(PORTA, PIN7, LOW);
		DIO_SetPinValue(PORTC, PIN7, LOW);
		DIO_SetPinValue(PORTD, PIN7, LOW);
		_delay_ms(2000);

		DIO_SetPinValue(PORTA, PIN7, LOW);
		DIO_SetPinValue(PORTB, PIN7, LOW);

		DIO_SetPinValue(PORTC, PIN7, HIGH);
		DIO_SetPinValue(PORTD, PIN7, HIGH);

		_delay_ms(2000);
		DIO_SetPinValue(PORTB, PIN7, LOW);
		DIO_SetPinValue(PORTA, PIN7, LOW);
		DIO_SetPinValue(PORTC, PIN7, LOW);
		DIO_SetPinValue(PORTD, PIN7, LOW);
		_delay_ms(2000);
	}

	return 0;

}
