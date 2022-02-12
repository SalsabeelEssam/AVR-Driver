#include"TYPES.h"
#include"MACROS.h"
#include"I2C.h"
#include"REGISTERS.h"
#include"LCD.h"
#include"EEPROM.h"
#include<util/delay.h>
//EEPROM Code
int main(void){
	u8 x , y;
	LCD_VidInit();
	EEPROM_VidInit();
	_delay_ms(100);
	EEPROM_Write_Byte(0,10);
	_delay_ms(100);
	EEPROM_Write_Byte(1,20);
	_delay_ms(100);
	x = EEPROM_Read_Byte(0);
	y = EEPROM_Read_Byte(1);

	LCD_VidWriteNumber(x);
	LCD_VidWriteNumber(y);

	return 0;
}

/*//L Main Bta3t El Master
int main(void){
	I2C_ERROR_STATUS State;
	I2C_VidInitMaster();
	State = I2C_StartCondition();
	if(State == OK){
		State = I2C_Master_Send_Slave_Address_With_Write(1);
		if(State == OK){
			State = I2C_Maste_Write_Byte_To_Slave(25);
			if(State == OK){
				I2C_StopCondition();
			}else{
				LCD_VidWriteString((u8 *)"DataError");
			}
		}
		else{
			LCD_VidWriteString((u8 *)"AddressError");
		}
	}
	else{
		LCD_VidWriteString((u8 *)"StartError");
	}
	return 0;
}*/

/*
//L Main Bta3t El Slave
int main(void){
	I2C_ERROR_STATUS State;
	u8  x;
	LCD_VidInit();
	I2C_VidInitSlave();
	State = I2C_Slave_Check_About_His_Addr_With_Write();
	if( State == OK ){
		State = I2C_Slave_Read_Byte_From_Master(&x);
		if(State == OK){
			LCD_VidWriteNumber(x);
		}else{
			LCD_VidWriteString((u8 *)"Data_ERROR");
		}

	}else{
		LCD_VidWriteString((u8 *)"SLA+W_ERROR");
	}

	return 0;
}
 */
