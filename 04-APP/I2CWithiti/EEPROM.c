#include"TYPES.h"
#include"I2C.h"

void EEPROM_VidInit(void){
	I2C_VidInitMaster();
}

void EEPROM_Write_Byte(u16 Address , u8 Data){

	I2C_ERROR_STATUS State = NOK;
	State = I2C_StartCondition();
	if(State == OK){
		State = I2C_Master_Send_Slave_Address_With_Write( 0x50 | ( ( Address & 0x0700 ) >> 8 ) );
		if(State == OK){
			State = I2C_Maste_Write_Byte_To_Slave((u8)Address);
			if(State == OK){
				State = I2C_Maste_Write_Byte_To_Slave(Data);
				if(State == OK){
					I2C_StopCondition();
				}
			}
		}
	}

}

u8 EEPROM_Read_Byte(u16 Address){
	u8 LOC_u8Data;
	I2C_ERROR_STATUS State = NOK;
	State = I2C_StartCondition();
	if(State == OK){
		State = I2C_Master_Send_Slave_Address_With_Write( 0x50 | ( ( Address & 0x0700 ) >> 8 ) );
		if(State == OK){
			State = I2C_Maste_Write_Byte_To_Slave((u8)Address);
			if(State == OK){
				State = I2C_RepeatedStart();
				if(State == OK){
					State = I2C_Master_Send_Slave_Address_With_Read( 0x50 | ( ( Address & 0x0700 ) >> 8 ) );
					if( State == OK ){
						State = I2C_Master_Read_Byte_From_Slave_NACK(&LOC_u8Data);
						if(State == OK){
							I2C_StopCondition();
						}
					}
				}
			}
		}
	}
	return LOC_u8Data;
}
