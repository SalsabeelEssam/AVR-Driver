/*
 * LCD_CFG.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: jo
 */

#ifndef LCD_CFG_H_
#define LCD_CFG_H_


/*
 -----------                   ----------
 | ATmega32  |                 |   LCD    |
 |           |                 |          |
 |        PD7|---------------->|D7        |
 |        PD6|---------------->|D6        |
 |        PD5|---------------->|D5        |
 |        PD4|---------------->|D4        |
 |        PD3|---------------->|D3        |
 |        PD2|---------------->|D2        |
 |        PD1|---------------->|D1        |
 |        PD0|---------------->|D0        |
 |           |                 |          |
 |        PA2|---------------->|E         |
 |        PA1|---------------->|RW        |
 |        PA0|---------------->|RS        |
 -----------                   ----------
 */

#define LCD_DATA_PORT A
#define LCD_CONTROL_PORT D
#define RS PIN7
#define RW PIN6
#define E PIN5





#endif /* LCD_CFG_H_ */
