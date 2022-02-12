/*
 * UART_Program.c
 *
 *  Created on: Jun 14, 2021
 *      Author: Salsabeel Essam
 */

/*SET_BIT(REG,BIT)
 * CLR_BIT(REG,BIT)
 */
#include"STD_TYPE.h"
#include"BIT_MATH.h"
#include"UART_Private.h"
#include"UART_Interface.h"
void USART_VoidInt(void) {
	u8 UCSRC_HELP = 0;
	//u8 VALUE_BAUD_RATE = (((F_CPU / (9600 * 8UL))) - 1);

	SET_BIT(UCSRB, RXEN); //ENABLE Receiver
	SET_BIT(UCSRB, TXEN); //ENABLE Transmitter

	/*we cant do this because we need to select wich register we wann to change
	 * then chage as byte acces not bit access
	 * SET_BIT(UCSRC,URSEL); //must be one when writing in this reg
	 CLR_BIT(UCSRC,UMSEL); // asynchronous
	 CLR_BIT(UCSRC,UPM0); //parity disable
	 CLR_BIT(UCSRC,UPM1); //parity disable
	 CLR_BIT(UCSRC,USBS); //1 stop bit*/

	/* UCSRC UCSZ0 UCSZ1 */

	/* USE HELP REGISTER THEN ASSIGN IT AS ONE TIME*/

	SET_BIT(UCSRC_HELP, URSEL); //must be one when writing in this reg
	CLR_BIT(UCSRC_HELP, UMSEL); // asynchronous
	CLR_BIT(UCSRC_HELP, UPM0); //parity disable
	CLR_BIT(UCSRC_HELP, UPM1); //parity disable
	CLR_BIT(UCSRC_HELP, USBS); //1 stop bit*/

	SET_BIT(UCSRC_HELP, UCSZ0); //8 bit
	SET_BIT(UCSRC_HELP, UCSZ1); //8bit
	CLR_BIT(UCSRC_HELP, UCPOL); //
	CLR_BIT(UCSRB, UCSZ2); //8 bit
	ASSIGN_REG(UCSRC, UCSRC_HELP);

	/* baud rate*/
	UBRRL = 51;

}

void USART_VoidSendData(u8 DATA) {
//	while(GET_BIT(UCSRA,TXC));
	while (!GET_BIT(UCSRA, UDRE))
		;
	UDR = DATA;
}
u8 USART_VoidReseiveData(void) {
	while (!GET_BIT(UCSRA, RXC))
		;
	return UDR;
}

void USART_sendString(const u8 *Str) {

	while (*Str != '\0') {
		USART_VoidSendData(*Str);
		Str++;
	}
}

void USART_ReseiveString(u8 *Str) {
	u8 i=0;
	Str[i] = USART_VoidReseiveData();
	while (Str[i] != '#') {
		i++;
		Str[i] = USART_VoidReseiveData();
	}
	Str[i] = '\0';
}
