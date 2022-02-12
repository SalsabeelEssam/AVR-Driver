/*
 * I2C_Program.c
 *
 *  Created on: Jun 25, 2021
 *      Author: Salsabeel Essam
 */

#include "STD_TYPE.h"
#include "BIT_MATH.h"
#include "I2C_Private.h"
#include "I2C_Interface.h"

void TWI_VoidInit(void){
	/* Bit Rate: 400.000 kbps using zero pre-scaler TWPS=00 and F_CPU=8Mhz */
	CLR_BIT(TWSR,TWPS0);
	CLR_BIT(TWSR,TWPS1);
	ASSIGN_REG(TWBR,0x02);

	/*Two Wire Bus address my address if any master device want to call me: 0x1
	*(used in case this MC is a slave device)
	*General Call Recognition: on */
	 ASSIGN_REG(TWAR,0x03); // my address = 0x01

	 /*Enable twi */
	 SET_BIT(TWCR,TWEN);

}

void TWI_VoidSendStartCondition(void){
	/* to send start condition should set three bits enable and start bit and interrupt flag */
	SET_BIT(TWCR,TWINT);
	SET_BIT(TWCR,TWSTA);
	SET_BIT(TWCR,TWEN);
	/* Wait unit the flag is set */
	while(!GET_BIT(TWCR,TWINT));
	/* check TWI Status Register. if not start bit go to error*/
	if ((TWSR & 0xF8) != TW_START){
		// error
	}

}
void TWI_VoidSendRepeatedStart(void){
	/* to send repeated start condition should set three bits enable and start bit and interrupt flag */
	SET_BIT(TWCR,TWINT);
	SET_BIT(TWCR,TWSTA);
	SET_BIT(TWCR,TWEN);
	/* Wait unit the flag is set */
	while(!GET_BIT(TWCR,TWINT));
	/* check TWI Status Register. if not start bit go to error*/
	if ((TWSR & 0xF8) != TW_REP_START){
		// error
	}
}

void TWI_VoidSendStopCondition(void){
	/* to send stop condition should set three bits enable and stop bit and interrupt flag */
	SET_BIT(TWCR,TWINT);
	SET_BIT(TWCR,TWEN);
	SET_BIT(TWCR,TWSTO);

}

void TWI_VoidSendSlaveAddressWithWrite(u8 SlaveAddress){
	/* clear 7 bit and add last bit with zero to write*/
	SlaveAddress = SlaveAddress & 0xFE;
	ASSIGN_REG(TWDR,SlaveAddress);
	/*Clear TWINT bit in TWCR to start transmission of address*/
	SET_BIT(TWCR,TWINT);
	SET_BIT(TWCR,TWEN);
	/*wait until slave address is send and flag = 1*/
	while(!GET_BIT(TWCR,TWINT));
	/*Check value of TWI Status Register if not send slave with write send error*/
	if ((TWSR & 0xF8) != TW_MT_SLA_W_ACK){
		// error
	}
}
void TWI_VoidSendSlaveAddressWithRead(u8 SlaveAddress){
	/* clear 7 bit and add last bit with one to read*/
	SlaveAddress = SlaveAddress & 0xFF;
	ASSIGN_REG(TWDR,SlaveAddress);
	/*Clear TWINT bit in TWCR to start transmission of address*/
	SET_BIT(TWCR,TWINT);
	SET_BIT(TWCR,TWEA);
	SET_BIT(TWCR,TWEN);
	/*wait until slave address is send and flag = 1*/
	while(!GET_BIT(TWCR,TWINT));
	/*Check value of TWI Status Register if not send slave with write send error*/
	if ((TWSR & 0xF8) != TW_MT_SLA_R_ACK){
		// error
	}

}

void TWI_VoidSendSlaveAddressWithWriteAndNACK(u8 SlaveAddress){
	/* clear 7 bit and add last bit with zero to write*/
	SlaveAddress = SlaveAddress & 0xFE;
	ASSIGN_REG(TWDR,SlaveAddress);
	/*Clear TWINT bit in TWCR to start transmission of address*/
	SET_BIT(TWCR,TWINT);
	SET_BIT(TWCR,TWEN);
	/*wait until slave address is send and flag = 1*/
	while(!GET_BIT(TWCR,TWINT));
	/*Check value of TWI Status Register if not send slave with write send error*/
	if ((TWSR & 0xF8) != TW_MT_SLA_W_NACK){
		// error
	}
}
void TWI_VoidSendSlaveAddressWithReadAndNACK(u8 SlaveAddress){
	/* clear 7 bit and add last bit with one to read*/
		SlaveAddress = SlaveAddress & 0xFF;
		ASSIGN_REG(TWDR,SlaveAddress);
		/*Clear TWINT bit in TWCR to start transmission of address*/
		SET_BIT(TWCR,TWINT);
		SET_BIT(TWCR,TWEN);
		/*wait until slave address is send and flag = 1*/
		while(!GET_BIT(TWCR,TWINT));
		/*Check value of TWI Status Register if not send slave with write send error*/
		if ((TWSR & 0xF8) != TW_MT_SLA_R_NACK){
			// error
		}

}

void TWI_VoidMasterSendDataByte(u8 DATA){
	/* Put data On TWI data Register*/
	ASSIGN_REG(TWDR,DATA);
	/*Clear TWINT bit in TWCR to start transmission of address*/
	SET_BIT(TWCR,TWINT);
	SET_BIT(TWCR,TWEN);
	/*wait until slave address is send and flag = 1*/
	while(!GET_BIT(TWCR,TWINT));
	/*Check value of TWI Status Register if not send slave with write send error*/
	if ((TWSR & 0xF8) != TW_MT_DATA_ACK){
		// error
	}
}
void TWI_VoidMasterReseiveReadByte(u8 DATA){
	/*Clear TWINT bit in TWCR to start transmission of address*/
	SET_BIT(TWCR,TWINT);
	SET_BIT(TWCR,TWEA);
	SET_BIT(TWCR,TWEN);
	/*wait until slave address is send and flag = 1*/
	while(!GET_BIT(TWCR,TWINT));
	/*Check value of TWI Status Register if not send slave with write send error*/
	if ((TWSR & 0xF8) != TW_MR_DATA_ACK){
		// error
	}
	/* take data from TWI data Register*/
	ASSIGN_REG(DATA,TWDR);
}

void TWI_VoidMasterSendDataByteAndNACK(u8 DATA){
	/* Put data On TWI data Register*/
	ASSIGN_REG(TWDR,DATA);
	/*Clear TWINT bit in TWCR to start transmission of address*/
	SET_BIT(TWCR,TWINT);
	SET_BIT(TWCR,TWEN);
	/*wait until slave address is send and flag = 1*/
	while(!GET_BIT(TWCR,TWINT));
	/*Check value of TWI Status Register if not send slave with write send error*/
	if ((TWSR & 0xF8) != TW_MT_DATA_NACK){
		// error
	}
}
void TWI_VoidMasterReseiveReadByteAndNACK(u8 DATA){
	/*Clear TWINT bit in TWCR to start transmission of address*/
	SET_BIT(TWCR,TWINT);
	SET_BIT(TWCR,TWEN);
	/*wait until slave address is send and flag = 1*/
	while(!GET_BIT(TWCR,TWINT));
	/*Check value of TWI Status Register if not send slave with write send error*/
	if ((TWSR & 0xF8) != TW_MR_DATA_NACK){
		// error
	}
	/* take data from TWI data Register*/
	ASSIGN_REG(DATA,TWDR);
}
