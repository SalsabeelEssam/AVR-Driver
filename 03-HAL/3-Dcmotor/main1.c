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
	//DIO_SetPinDirection(PORTA, PIN6, OUTPUT);
	DIO_SetPinDirection(PORTD, PIN7, OUTPUT);

	//DIO_SetPinDirection(PORTB, PIN7, INPUT);
	//DIO_SetPinValue(PORTB, PIN7, HIGH);


	//DIO_SetPinValue(PORTD, PIN7, HIGH);
// TWO TRANSISTOR
	while (1) {
		DIO_SetPinValue(PORTA, PIN7, HIGH);
		DIO_SetPinValue(PORTD, PIN7, HIGH);
		_delay_ms(2000);
		DIO_SetPinValue(PORTA, PIN7, LOW);
		DIO_SetPinValue(PORTD, PIN7, LOW);
		_delay_ms(2000);
	}

	return 0;

}
