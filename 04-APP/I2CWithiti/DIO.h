/*
 * DIO.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: jo
 */

#ifndef DIO_H_
#define DIO_H_

/* Port Defines */
#define A    0
#define B    1
#define C    2
#define D    3

/* PIN Defines */
#define PIN0   0
#define PIN1   1
#define PIN2   2
#define PIN3   3
#define PIN4   4
#define PIN5   5
#define PIN6   6
#define PIN7   7


/* PIN Directions */
#define INPUT  0
#define OUTPUT 1

/* PIN Value Options */
#define HIGH   1
#define LOW    0


/* I/O Ports */
void DIO_VidSetPortDirection(u8 LOC_u8Port, u8 LOC_u8Value);

/***************************************************************************************/
/* Description! Setting Port Direction :---- input or output                           */
/* Input      ! PortNumber , PortDirection                                             */
/* Output     ! Nothing                                                                */
/***************************************************************************************/



void DIO_VidSetPortValue(u8 LOC_u8Port, u8 LOC_u8Value);
/***************************************************************************************/
/* Description! Setting Port Value :---- High or Low                                   */
/* Input      ! PortNumber , PortValue                                                 */
/* Output     ! Nothing                                                                */
/***************************************************************************************/



u8 DIO_u8ReadPort(u8 LOC_u8Port);
/***************************************************************************************/
/* Description! Reading Port Value :---- High or Low                                   */
/* Input      ! PortNumber                                                             */
/* Output     ! PortValue                                                              */
/***************************************************************************************/


/* I/O Pins */
void DIO_VidSetPinDirection(u8 LOC_u8Port , u8 LOC_u8Pin , u8 LOC_u8Value);
/***************************************************************************************/
/* Description! Setting Pin Direction :---- input or output                            */
/* Input      ! PortNumber ,PinNumber ,  PinDirection                                  */
/* Output     ! Nothing                                                                */
/***************************************************************************************/

void DIO_VidSetPinValue(u8 LOC_u8Port , u8 LOC_u8Pin , u8 LOC_u8Value);
/***************************************************************************************/
/* Description! Setting Pin Value :---- High or Low                                    */
/* Input      ! PortNumber , PinNumber ,  PinValue                                     */
/* Output     ! Nothing                                                                */
/***************************************************************************************/



u8 DIO_u8ReadPin(u8 LOC_u8Port , u8 LOC_u8Pin );
/***************************************************************************************/
/* Description! Reading Pin Value :---- High or Low                                    */
/* Input      ! PortNumber , PinNumber                                                 */
/* Output     ! PinValue                                                               */
/***************************************************************************************/

#endif /* DIO_H_ */
