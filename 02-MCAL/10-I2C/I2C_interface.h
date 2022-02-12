/*
 * I2C_Interface.h
 *
 *  Created on: Jun 25, 2021
 *      Author: Salsabeel Essam
 */

#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

void TWI_VoidInit(void);

void TWI_VoidSendStartCondition(void);
void TWI_VoidSendRepeatedStart(void);

void TWI_VoidSendStopCondition(void);

void TWI_VoidSendSlaveAddressWithWrite(u8 SlaveAddress);
void TWI_VoidSendSlaveAddressWithRead(u8 SlaveAddress);

void TWI_VoidSendSlaveAddressWithWriteAndNACK(u8 SlaveAddress);
void TWI_VoidSendSlaveAddressWithReadAndNACK(u8 SlaveAddress);

void TWI_VoidMasterSendDataByte(u8 DATA);
void TWI_VoidMasterReseiveReadByte(u8 DATA);

void TWI_VoidMasterSendDataByteAndNACK(u8 DATA);
void TWI_VoidMasterReseiveReadByteAndNACK(u8 DATA);

#endif /* I2C_INTERFACE_H_ */
