/*
 * LCD.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: jo
 */

#ifndef LCD_H_
#define LCD_H_


/***************************************************************************************/
/* Description ! 16x2 Character LCD for chip LMB161A                                   */
/* Release Date! 28/6/2016                                                             */
/* Version     ! V01                                                                   */
/***************************************************************************************/

/*************************************************************************************************************/
/*************************************************************************************************************/
/*************************************************************************************************************/
/***********************************************MACROS********************************************************/


#define LCD_CLEAR           0x01          //replace all characters with ASCII 'space'
#define LCD_HOME           0x02           //return cursor to first position on first line
#define LCD_ENTRYMODE       0x06          // shift cursor from left to right on read/write
#define LCD_DISPLAYOFF      0x08          // turn display off
#define LCD_DISPLAYON      0x0C           // display on, cursor off, don't blink character
#define LCD_FUNCTIONRESET   0x30          // reset the LCD
#define LCD_FUNCTIONSET8BIT 0x38          // 8-bit data, 2-line display, 5 x 7 font
#define LCD_SETCURSOR  0x80               // set cursor position




void LCD_VidInit(void);
/***************************************************************************************/
/* Description! Apply initialization sequence for LCD module                           */
/* Input      ! Nothing                                                                */
/* Output     ! Nothing                                                                */
/***************************************************************************************/


void LCD_VidWriteChar(u8 data);
/***************************************************************************************/
/* Description! Interface to write character on LCD screen                             */
/* Input      ! Data to send                                                           */
/* Output     ! Nothing                                                                */
/***************************************************************************************/

void LCD_VidWriteCommand(u8 data);
/***************************************************************************************/
/* Description! Interface to send the configuration commands to the LCD Driver         */
/* Input      ! Command number                                                         */
/* Output     ! Nothing                                                                */
/***************************************************************************************/


void LCD_VidWriteNumber(u64 num);
/***************************************************************************************/
/* Description! Interface to write number on LCD screen                                */
/* Input      ! number to send                                                         */
/* Output     ! Nothing                                                                */
/***************************************************************************************/

void LCD_VidWriteString(u8 arr[]);

void LCD_VidSetPosition(u8 row , u8 col);




#endif /* LCD_H_ */
