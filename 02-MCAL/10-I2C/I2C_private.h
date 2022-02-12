/*
 * I2C_Private.h
 *
 *  Created on: Jun 25, 2021
 *      Author: Salsabeel Essam
 */

#ifndef I2C_PRIVATE_H_
#define I2C_PRIVATE_H_
/*  REGISTER */
#define TWBR (*(volatile u8*)0x20)
#define TWCR (*(volatile u8*)0x56)
#define TWSR (*(volatile u8*)0x21)
#define TWDR (*(volatile u8*)0x23)
#define TWAR (*(volatile u8*)0x22)


/* TWCR REGISTER */
#define TWINT   7
#define TWEA    6
#define TWSTA   5
#define TWSTO   4
#define TWWC    3
#define TWEN    2

#define TWIE    0


/* TWSR REGISTER */
#define TWS7     7
#define TWS6     6
#define TWS5     5
#define TWS4     4
#define TWS3     3

#define TWPS1    1
#define TWPS0    0


/* TWAR REGISTER */
#define TWGCE    0
/*******************************************************************************
 *                      Status Code For Send Receive Mode                                   *
 *******************************************************************************/
/* I2C Status Bits in the TWSR Register */
#define TW_START              0x08 // start has been sent
#define TW_REP_START          0x10 // repeated start
#define TW_MT_SLA_W_ACK       0x18 // Master transmit ( slave address + Write request ) to slave + Ack received from slave
#define TW_MT_SLA_W_NACK      0x20 // Master transmit ( slave address + Write request ) to slave + NOT Ack received from slave
#define TW_MT_SLA_R_ACK       0x40 // Master transmit ( slave address + Read request ) to slave + Ack received from slave
#define TW_MT_SLA_R_NACK      0x48 // Master transmit ( slave address + Read request ) to slave + NOT Ack received from slave
#define TW_MT_DATA_ACK        0x28 // Master transmit data and ACK has been received from Slave.
#define TW_MT_DATA_NACK       0x30 // Master transmit data and NOT ACK has been received from Slave.
#define TW_MR_DATA_ACK        0x50 // Master received data and send ACK to slave
#define TW_MR_DATA_NACK       0x58 // Master received data but doesn't send ACK to slave


#endif /* I2C_PRIVATE_H_ */
