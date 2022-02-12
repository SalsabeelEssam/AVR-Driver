/*
 * UART_Interface.h
 *
 *  Created on: Jun 14, 2021
 *      Author: Salsabeel Essam
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void USART_VoidInt(void);

void USART_VoidSendData(u8 DATA);
u8 USART_VoidReseiveData(void);

void USART_sendString(const u8 *Str);
void USART_ReseiveString(u8 *Str);

#endif /* UART_INTERFACE_H_ */
