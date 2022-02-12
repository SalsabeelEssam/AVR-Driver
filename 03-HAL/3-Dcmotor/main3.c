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
	DIO_SetPinDirection(PORTA, PIN0, OUTPUT);
	DIO_SetPinDirection(PORTB, PIN0, OUTPUT);
	/* SWITCHS INPUT + PULL RESISTOR */
	DIO_SetPinDirection(PORTC, PIN0, INPUT);
	DIO_SetPinDirection(PORTD, PIN0, INPUT);

	DIO_SetPinValue(PORTC, PIN0, HIGH);
	DIO_SetPinValue(PORTD, PIN0, HIGH);
// TWO TRANSISTOR
	while (1) {
		if ((DIO_GetPinValue(PORTD, PIN0) == 0)
				&& (DIO_GetPinValue(PORTC, PIN0) == 0)) {
			DIO_SetPinValue(PORTB, PIN0, LOW);
			DIO_SetPinValue(PORTA, PIN0, LOW);
			//	_delay_ms(200);
		} else if (DIO_GetPinValue(PORTC, PIN0) == 0) {
			DIO_SetPinValue(PORTA, PIN0, HIGH);
			DIO_SetPinValue(PORTB, PIN0, LOW);
			//_delay_ms(200);
		} else if (DIO_GetPinValue(PORTD, PIN0) == 0) {
			DIO_SetPinValue(PORTB, PIN0, HIGH);
			DIO_SetPinValue(PORTA, PIN0, LOW);
			//	_delay_ms(200);
		} else {
			DIO_SetPinValue(PORTA, PIN0, HIGH);
			DIO_SetPinValue(PORTB, PIN0, HIGH);
			//	_delay_ms(200);
		}
		_delay_ms(200);
	}

	return 0;

}
