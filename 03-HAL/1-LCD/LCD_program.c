/***************************************************************************************************
 *  File Name        : LCD_program.C
 *  Module           : LCD  PROGRAM
 *  Description      : public function
 *  Created on       : May 24, 2021
 *  version          : v 01
 *  Author           : Salsabeel_Essam
 ***************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "DIO_interface.h"

#include "LCD_interface.h"
#include "LCD_config.h"

static u8 Swap(u8 *Buffer, u8 start, u8 end);

void LCD_VoidInti(void) {

	DIO_SetPinDirection(PortControl, RS, OUTPUT);
	DIO_SetPinDirection(PortControl, RW, OUTPUT);
	DIO_SetPinDirection(PortControl, E, OUTPUT);

#if (DATA_BITS_MODE == 4)
	DIO_SetPinDirection(PortData, PIN4, OUTPUT);
	DIO_SetPinDirection(PortData, PIN5, OUTPUT);
	DIO_SetPinDirection(PortData, PIN6, OUTPUT);
	DIO_SetPinDirection(PortData, PIN7, OUTPUT);
	LCD_VoidSendCommand(FOUR_BITS_DATA_MODE);
	LCD_VoidSendCommand(TWO_LINE_LCD_Four_BIT_MODE);
#elif(DATA_BITS_MODE == 8)
	DIO_SetPortDirection(PortData, 0xFF);
	LCD_VoidSendCommand(TWO_LINE_LCD_Eight_BIT_MODE);
#endif

	LCD_VoidSendCommand(CLEAR_COMMAND);
	LCD_VoidSendCommand(CURSOR_OFF);
}

void LCD_VoidSendCommand(u8 Copy_U8Comand) {

	DIO_SetPinValue(PortControl, RS, LOW);
	DIO_SetPinValue(PortControl, RW, LOW);

	_delay_ms(1); /* delay for processing Tas = 50ns */
	DIO_SetPinValue(PortControl, E, HIGH);
	_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */

#if (DATA_BITS_MODE == 4)
	DIO_SetPinValue(PortData, PIN4, GET_BIT(Copy_U8Comand, 4));
	DIO_SetPinValue(PortData, PIN5, GET_BIT(Copy_U8Comand, 5));
	DIO_SetPinValue(PortData, PIN6, GET_BIT(Copy_U8Comand, 6));
	DIO_SetPinValue(PortData, PIN7, GET_BIT(Copy_U8Comand, 7));

	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	DIO_SetPinValue(PortControl, E, LOW);
	_delay_ms(1); /* delay for processing Th = 13ns */
	DIO_SetPinValue(PortControl, E, HIGH);
	_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */

	DIO_SetPinValue(PortData, PIN4, GET_BIT(Copy_U8Comand, 0));
	DIO_SetPinValue(PortData, PIN5, GET_BIT(Copy_U8Comand, 1));
	DIO_SetPinValue(PortData, PIN6, GET_BIT(Copy_U8Comand, 2));
	DIO_SetPinValue(PortData, PIN7, GET_BIT(Copy_U8Comand, 3));

	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	DIO_SetPinValue(PortControl, E, LOW);
	_delay_ms(1); /* delay for processing Th = 13ns */

#elif(DATA_BITS_MODE == 8)
	DIO_SetPortValue(PortData, Copy_U8Comand);
	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	DIO_SetPinValue(PortControl, E, LOW);
	_delay_ms(1); /* delay for processing Th = 13ns */
#endif

}

void LCD_VoidSendData(u8 Copy_U8Data) {
	DIO_SetPinValue(PortControl, RS, HIGH);
	DIO_SetPinValue(PortControl, RW, LOW);

	_delay_ms(1); /* delay for processing Tas = 50ns */
	DIO_SetPinValue(PortControl, E, HIGH);
	_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */

#if (DATA_BITS_MODE == 4)
	DIO_SetPinValue(PortData, PIN4, GET_BIT(Copy_U8Data, 4));
	DIO_SetPinValue(PortData, PIN5, GET_BIT(Copy_U8Data, 5));
	DIO_SetPinValue(PortData, PIN6, GET_BIT(Copy_U8Data, 6));
	DIO_SetPinValue(PortData, PIN7, GET_BIT(Copy_U8Data, 7));

	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	DIO_SetPinValue(PortControl, E, LOW);
	_delay_ms(1); /* delay for processing Th = 13ns */
	DIO_SetPinValue(PortControl, E, HIGH);
	_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */

	DIO_SetPinValue(PortData, PIN4, GET_BIT(Copy_U8Data, 0));
	DIO_SetPinValue(PortData, PIN5, GET_BIT(Copy_U8Data, 1));
	DIO_SetPinValue(PortData, PIN6, GET_BIT(Copy_U8Data, 2));
	DIO_SetPinValue(PortData, PIN7, GET_BIT(Copy_U8Data, 3));

	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	DIO_SetPinValue(PortControl, E, LOW);
	_delay_ms(1); /* delay for processing Th = 13ns */
#elif(DATA_BITS_MODE == 8)
	DIO_SetPortValue(PortData, Copy_U8Data);
	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	DIO_SetPinValue(PortControl, E, LOW);
	_delay_ms(1); /* delay for processing Th = 13ns */
#endif

}

void LCD_VoidSendString(u8 *Copy_U8Data) {
	while ((*Copy_U8Data) != '\0') {
		LCD_VoidSendData(*Copy_U8Data);
		Copy_U8Data++;
	}

	/*another Method*/
	/*
	 uint8 i = 0;
	 while (Copy_U8Data[i] != '\0') {
	 LCD_VoidSendData(Copy_U8Data[i]);
	 i++;
	 }
	 */
}

void LCD_SetPosition(u8 row, u8 col) {
	switch (row) {
	case 0:
		LCD_VoidSendCommand(128 + col);
		break;
	case 1:
		LCD_VoidSendCommand(192 + col);
		break;
	case 2:
		LCD_VoidSendCommand(256 + col);
		break;
	case 3:
		LCD_VoidSendCommand(320 + col);
		break;
	default:
		//
		break;

	}
}

void LCD_VoidSendStringToRowColumn(u8 Copy_u8Row, u8 Copy_u8Column,
		u8 *Copy_u8String) {
	LCD_SetPosition(Copy_u8Row, Copy_u8Column);
	LCD_VoidSendString(Copy_u8String);
}

void Lcd_VoidSendNumber(u32 Copy_U8Data) {
	u8 Buffer[17];
	u8 i = 0, LastNum;
	while (Copy_U8Data) {
		LastNum = (Copy_U8Data % 10);
		Buffer[i] = LastNum + 48;
		Copy_U8Data /= 10;
		i++;
	}
	Buffer[i] = '\0';
	Swap(Buffer, 0, (i - 1));
	LCD_VoidSendString(Buffer);
}

static u8 Swap(u8 *Buffer, u8 start, u8 end) {
	u8 temp;
	while (start < end) {
		temp = Buffer[start];
		Buffer[start] = Buffer[end];
		Buffer[end] = temp;
		start++;
		end--;
	}
	return 0;
}

void LCD_VoidCreateUserCharacter(u8 *Pattern, u8 Location) {
	u8 i;
	LCD_VoidSendCommand(0x40 + (Location * 8));
	for (i = 0; i < 8; i++) {
		LCD_VoidSendData(Pattern[i]);
	}
}

void LCD_VoidDisplayShift(u8 Copy_u8Direction) {
	if (Copy_u8Direction == 'R') {
		LCD_VoidSendCommand(SHIFT_RIGHT_COMMAND);
	} else if (Copy_u8Direction == 'L') {
		LCD_VoidSendCommand(SHIFT_LEFT_COMMAND);
	}
}


