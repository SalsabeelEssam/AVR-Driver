/*
 * LCD.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: jo
 */

#include"TYPES.h"
#include"DIO.h"
#include"util/delay.h"
#include"LCD_CFG.h"
#include"LCD.h"



/***************************************************************************************/
/* Description! Apply initialization sequence for LCD module                           */
/* Input      ! Nothing                                                                */
/* Output     ! Nothing                                                                */
/***************************************************************************************/

void LCD_VidInit(void)
{
	DIO_VidSetPortDirection(LCD_DATA_PORT , 255);     //Making DATA_PORT output
	DIO_VidSetPinDirection(LCD_CONTROL_PORT , RS , 1);   //Making RS pin output
	DIO_VidSetPinDirection(LCD_CONTROL_PORT , RW , 1);   //Making RW pin output
	DIO_VidSetPinDirection(LCD_CONTROL_PORT , E , 1);   //Making E pin output
	_delay_ms(50);
	LCD_VidWriteCommand(0b00111000);  //Commands to set LCD configure  on page 13 on data sheet
	_delay_ms(1);
	LCD_VidWriteCommand(0b00001100);  //Commands to set LCD configure
	_delay_ms(1);
	LCD_VidWriteCommand(0b00000001);  //Commands to set LCD configure
	_delay_ms(1);

}





/***************************************************************************************/
/* Description! Interface to write character on LCD screen                             */
/* Input      ! Data to send                                                           */
/* Output     ! Nothing                                                                */
/***************************************************************************************/


void LCD_VidWriteChar(u8 data)
{

	DIO_VidSetPortValue(LCD_DATA_PORT, data);
	DIO_VidSetPinValue(LCD_CONTROL_PORT , RS , 1);  //RS = 1 to data
	DIO_VidSetPinValue(LCD_CONTROL_PORT , RW , 0);  //RW = 0 to write
	DIO_VidSetPinValue(LCD_CONTROL_PORT , E, 1);
	_delay_ms(1);   //delay between raising and falling edge
	DIO_VidSetPinValue(LCD_CONTROL_PORT , E , 0);
	_delay_ms(1);   //delay between every character
}






/***************************************************************************************/
/* Description! Interface to send the configuration commands to the LCD Driver         */
/* Input      ! Command number                                                         */
/* Output     ! Nothing                                                                */
/***************************************************************************************/


void LCD_VidWriteCommand(u8 data)
{

	DIO_VidSetPortValue(LCD_DATA_PORT , data);
	DIO_VidSetPinValue(LCD_CONTROL_PORT , RS , 0);  //RS = 0 to command
	DIO_VidSetPinValue(LCD_CONTROL_PORT , RW , 0);  //RW = 0 to write
	DIO_VidSetPinValue(LCD_CONTROL_PORT , E, 1);
	_delay_ms(1);  //delay between raising and falling edge
	DIO_VidSetPinValue(LCD_CONTROL_PORT , E , 0);
	_delay_ms(1);  //delay between every character
}








/***************************************************************************************/
/* Description! Interface to write string on LCD screen                                */
/* Input      ! Pointer to the string                                                  */
/* Output     ! Nothing                                                                */
/***************************************************************************************/


void LCD_VidWriteString(u8 arr[])
{
	u8 i = 0 ;
	while(arr[i]!= '\0')
	{

		LCD_VidWriteChar(arr[i]);
		i++;
	}

}



/***************************************************************************************/
/* Description! Interface to write number on LCD screen                                */
/* Input      ! number to send                                                         */
/* Output     ! Nothing                                                                */
/***************************************************************************************/

void LCD_VidWriteNumber(u64 num)
{

	if (num == 0)
	{
		LCD_VidWriteChar('0');
	}else
	{

		u64 reversed = 1 ;
		while(num != 0)
		{
			reversed = (reversed * 10 ) + (num % 10);
			num /=10;
		}

		while(reversed != 1)
		{
			LCD_VidWriteChar((reversed %10 ) + 48);
			reversed /= 10;


		}

	}
}



/***************************************************************************************/
/* Description! Interface to go to a specific position in LCD                          */
/* Input      ! Row number , Column number                                             */
/* Output     ! Nothing                                                                */
/***************************************************************************************/



void LCD_VidSetPosition(u8 row , u8 col)
{

	if(row == 0)
	{
		LCD_VidWriteCommand(128 + col);

	}
	else if(row == 1)
	{
		LCD_VidWriteCommand(128 + 64 + col);

	}

}



