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
	DIO_SetPinDirection(PORTA, PIN7, OUTPUT);
	DIO_SetPinDirection(PORTA, PIN6, OUTPUT);

	DIO_SetPinDirection(PORTB, PIN7, INPUT);
	DIO_SetPinValue(PORTB, PIN7, HIGH);

	DIO_SetPinDirection(PORTD, PIN7, INPUT);
	DIO_SetPinValue(PORTD, PIN7, HIGH);

	while (1) {
		if (DIO_GetPinValue(PORTB, PIN7) == 0) {
			DIO_SetPinValue(PORTA, PIN7, HIGH);
			DIO_SetPinValue(PORTA, PIN6, LOW);
		} else if (DIO_GetPinValue(PORTD, PIN7) == 0) {
			DIO_SetPinValue(PORTA, PIN7, LOW);
			DIO_SetPinValue(PORTA, PIN6, HIGH);
		} else if ((DIO_GetPinValue(PORTD, PIN7) == 0)
				&& (DIO_GetPinValue(PORTB, PIN7) == 0)) {
			DIO_SetPinValue(PORTA, PIN7, LOW);
			DIO_SetPinValue(PORTA, PIN6, LOW);
		} else if ((DIO_GetPinValue(PORTD, PIN7) == 1)
				&& (DIO_GetPinValue(PORTB, PIN7) == 1)) {
			DIO_SetPinValue(PORTA, PIN7, LOW);
			DIO_SetPinValue(PORTA, PIN6, LOW);
		} else {
			DIO_SetPinValue(PORTA, PIN7, LOW);
			DIO_SetPinValue(PORTA, PIN6, LOW);
		}
		//_delay_ms(200);
	}

	return 0;

}
