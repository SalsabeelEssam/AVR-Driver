/***************************************************************************************************
 *  File Name        : LCD_interface.h
 *  Module           : LCD  INTERFACE
 *  Description      : to interface LCD
 *  Created on       : may 24, 2021
 *  version          : v 01
 *  Author           : Salsabeel_Essam
 ***************************************************************************************************/


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_


void LCD_VoidInti(void);
void LCD_VoidSendCommand(u8 Copy_U8Comand);
void LCD_VoidSendData(u8 Copy_U8Data);
void LCD_VoidSendString(u8 *Copy_U8Data);
void LCD_SetPosition(u8 row, u8 col);
void LCD_VoidSendStringToRowColumn(u8 Copy_u8Row , u8 Copy_u8Column ,  u8 *Copy_u8String);
void LCD_VoidSendNumber(u32 Copy_U8Data);
void LCD_VoidCreateUserCharacter(u8 *Pattern, u8 Location);
void LCD_VoidDisplayShift(u8 Copy_u8Direction);
void LCD_ClearScreen(void);


#endif /* LCD_INTERFACE_H_ */
