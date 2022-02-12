/*
 * SPI_Private.h
 *
 *  Created on: Jun 21, 2021
 *      Author: Salsabeel Essam
 */

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_


#define SPCR (*(volatile u8*)0x2D)
#define SPSR (*(volatile u8*)0x2E)
#define SPDR (*(volatile u8*)0x2F)


/******** SPCR REGISTER *****************/
#define SPIE  7
#define SPE   6
#define DORD  5
#define MSTR  4
#define CPOL  3
#define CPHA  2
#define SPR1  1
#define SPR0  0


/******** SPSR REGISTER *****************/
#define SPIF   7
#define WCOL   6
#define SPI2X  0

/******** SPDR REGISTER *****************/
#define MSB   7
#define LSB   0


#endif /* SPI_PRIVATE_H_ */
