/*
 * DIO.c
 *
 *  Created on:
 *      Author: El-ahmady
 */

#include "TYPES.h"
#include"REGISTERS.h"
#include"MACROS.h"




/***************************************************************************************/
/* Description! Setting Port Direction :---- input or output                           */
/* Input      ! PortNumber , PortDirection                                             */
/* Output     ! Nothing                                                                */
/***************************************************************************************/


void DIO_VidSetPortDirection(u8 LOC_u8Port, u8 LOC_u8Value)
{

	switch(LOC_u8Port)
	{
	case 0 : DDRA = LOC_u8Value ; break ;
	case 1 : DDRB = LOC_u8Value ; break ;
	case 2 : DDRC = LOC_u8Value ; break ;
	case 3 : DDRD = LOC_u8Value ; break ;

	}

}






/***************************************************************************************/
/* Description! Setting Port Value :---- 1 or 0                                   */
/* Input      ! PortNumber , PortValue                                                 */
/* Output     ! Nothing                                                                */
/***************************************************************************************/


void DIO_VidSetPortValue(u8 LOC_u8Port, u8 LOC_u8Value)
{

	switch(LOC_u8Port)
	{
	case 0 : PORTA = LOC_u8Value ; break ;
	case 1 : PORTB = LOC_u8Value ; break ;
	case 2 : PORTC = LOC_u8Value ; break ;
	case 3 : PORTD = LOC_u8Value ; break ;

	}

}








/***************************************************************************************/
/* Description! Setting Pin Direction :---- input or output                            */
/* Input      ! PortNumber ,PinNumber ,  PinDirection                                  */
/* Output     ! Nothing                                                                */
/***************************************************************************************/

void DIO_VidSetPinDirection(u8 LOC_u8Port , u8 LOC_u8Pin , u8 LOC_u8Value)
{

	switch(LOC_u8Port)
	{

	case 0 :
		if(LOC_u8Value == 1)
		{
			SET_BIT( DDRA ,  LOC_u8Pin);
			break;
		}
		else if(LOC_u8Value == 0)
		{
			CLR_BIT( DDRA ,  LOC_u8Pin);
			break;
		}break;


	case 1 :
		if(LOC_u8Value == 1)
		{
			SET_BIT( DDRB ,  LOC_u8Pin);
			break;
		}
		else if(LOC_u8Value == 0)
		{
			CLR_BIT( DDRB ,  LOC_u8Pin);
			break;
		}break;

	case 2 :
		if(LOC_u8Value == 1)
		{
			SET_BIT( DDRC ,  LOC_u8Pin);
			break;
		}
		else if(LOC_u8Value == 0)
		{
			CLR_BIT( DDRC ,  LOC_u8Pin);
			break;
		}break;

	case 3 :
		if(LOC_u8Value == 1)
		{
			SET_BIT( DDRD ,  LOC_u8Pin);
			break;
		}
		else if(LOC_u8Value == 0)
		{
			CLR_BIT( DDRD ,  LOC_u8Pin);
			break;
		}break;

	}
}







/***************************************************************************************/
/* Description! Setting Pin Value :---- 1 or 0                                    */
/* Input      ! PortNumber , PinNumber ,  PinValue                                     */
/* Output     ! Nothing                                                                */
/***************************************************************************************/


void DIO_VidSetPinValue(u8 LOC_u8Port , u8 LOC_u8Pin , u8 LOC_u8Value)
{

	switch(LOC_u8Port)
	{

	case 0 :
		if(LOC_u8Value == 1)
		{
			SET_BIT( PORTA ,  LOC_u8Pin);
			break;
		}
		else if(LOC_u8Value == 0)
		{
			CLR_BIT( PORTA ,  LOC_u8Pin);
			break;
		}break;


	case 1 :
		if(LOC_u8Value == 1)
		{
			SET_BIT( PORTB ,  LOC_u8Pin);
			break;
		}
		else if(LOC_u8Value == 0)
		{
			CLR_BIT( PORTB ,  LOC_u8Pin);
			break;
		}break;

	case 2 :
		if(LOC_u8Value == 1)
		{
			SET_BIT( PORTC ,  LOC_u8Pin);
			break;
		}
		else if(LOC_u8Value == 0)
		{
			CLR_BIT( PORTC ,  LOC_u8Pin);
			break;
		}break;

	case 3 :
		if(LOC_u8Value == 1)
		{
			SET_BIT( PORTD ,  LOC_u8Pin);
			break;
		}
		else if(LOC_u8Value == 0)
		{
			CLR_BIT( PORTD ,  LOC_u8Pin);
			break;
		}break;




	}
}









/***************************************************************************************/
/* Description! Reading Port Value :---- HIGH or LOW                                   */
/* Input      ! PortNumber                                                             */
/* Output     ! PortValue                                                              */
/***************************************************************************************/

u8 DIO_u8ReadPort(u8 LOC_u8Port)
{
	u8 value ;
	switch(LOC_u8Port)
	{

	case 0 : value = PINA ; break ;
	case 1 : value = PINB ; break ;
	case 2 : value = PINC ; break ;
	case 3 : value = PIND ; break ;

	}

	return value ;
}









/***************************************************************************************/
/* Description! Reading Pin Value :---- HIGH or LOW                                    */
/* Input      ! PortNumber , PinNumber                                                 */
/* Output     ! PinValue                                                               */
/***************************************************************************************/

u8 DIO_u8ReadPin(u8 LOC_u8Port , u8 LOC_u8Pin )
{
	u8 value ;
	switch(LOC_u8Port)
	{

	case 0 : value = GET_BIT(PINA , LOC_u8Pin); break ;
	case 1 : value = GET_BIT(PINB , LOC_u8Pin); break ;
	case 2 : value = GET_BIT(PINC , LOC_u8Pin); break ;
	case 3 : value = GET_BIT(PIND , LOC_u8Pin); break ;

	}

	return value ;
}
