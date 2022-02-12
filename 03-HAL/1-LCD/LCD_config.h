/***************************************************************************************************
 *  File Name        : LCD_config.h
 *  Module           : LCD configuration
 *  Description      : save some of command and to control in data flow
 *  Created on       : May 24, 2021
 *  version          : v 01
 *  Author           : Salsabeel_Essam
 ***************************************************************************************************/

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

// JUST put number of bin b bit mode or 8 bit mode
#define DATA_BITS_MODE   							 8

//if with four should match with the last 4 pin in hardware 4, 5, 6 ,7


/* LCD HW Pins */
#define PortControl  								 PORTD
#define PortData       								 PORTC

#define RS    										 4
#define RW     										 5
#define E      										 6

/* LCD Commands */

#define CLEAR_COMMAND                            	0x01
#define TWO_LINE_LCD_Eight_BIT_MODE              	0x38
#define TWO_LINE_LCD_Four_BIT_MODE 					0x28
#define FOUR_BITS_DATA_MODE 						0x02
#define CURSOR_OFF 									0x0C
#define CURSOR_ON									0x0E
#define SET_CURSOR_LOCATION 						0x80
#define SHIFT_RIGHT_COMMAND 						0x18
#define SHIFT_LEFT_COMMAND 							0x1C


#endif /* LCD_CONFIG_H_ */
