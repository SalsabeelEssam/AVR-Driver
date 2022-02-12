/*
 * SPI_Interface.h
 *
 *  Created on: Jun 21, 2021
 *      Author: Salsabeel Essam
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_


void SPI_INIT(void);

void SPI_SendData(u8 DATA);

u8 SPI_ReceiveData(void);

#endif /* SPI_INTERFACE_H_ */
