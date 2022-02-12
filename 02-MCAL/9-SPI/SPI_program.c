/*
 * SPI_Program.c
 *
 *  Created on: Jun 21, 2021
 *      Author: Salsabeel Essam
 */

#include "STD_TYPE.h"
#include "BIT_MATH.h"
#include "DIO_INTERFACE.h"
#include "SPI_Private.h"
#include "SPI_Interface.h"

void SPI_INIT(void){
	//MASTER
	DIO_SetPinDirection(PORTB,PIN4,INPUT);
	DIO_SetPinDirection(PORTB,PIN5,OUTPUT);
	DIO_SetPinDirection(PORTB,PIN6,INPUT);
	DIO_SetPinDirection(PORTB,PIN7,OUTPUT);
// disable Interrupt
//	CLR_BIT(SPCR, SPIE); // config
	// Enable SPI
	SET_BIT(SPCR,SPE); // config
	// send data word lsb first
//	SET_BIT(SPCR,DORD); // config
	// set this spi as master or slave or twice
	SET_BIT(SPCR,MSTR); // config
	// select sck is idle in high
//	SET_BIT(SPCR,CPOL); // config
	// select if sample on leading
//	CLR_BIT(SPCR,CPHA);// config
	// select clock rate
//	SET_BIT(SPCR,SPR0); // config
//	CLR_BIT(SPCR,SPR1);
//	CLR_BIT(SPSR,SPI2X);
}

void SPI_SendData(u8 DATA){
//	ASSIGN_REG(SPDR,DATA);
	SPDR = DATA ;
	// WAIT UNTIL FLAG == 1
	while(!GET_BIT(SPSR,SPIF));

}

u8 SPI_ReceiveData(void){
	// WAIT UNTIL FLAG == 1
	while(!GET_BIT(SPSR,SPIF));
	return SPDR;
}
