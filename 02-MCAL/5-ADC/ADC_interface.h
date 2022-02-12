/*
 * ADC_Interface.h
 *
 *  Created on: Jun 8, 2021
 *      Author: Salsabeel Essam
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

 void ADC_VoidInit(void);

 void ADC_EnableInterrupt(void);
 void ADC_DisableInterrupt(void);

 void ADC_GetDigitalValue(u8 Copy_u8Channel, u16 *Copy_DigitalValue);


#endif /* ADC_INTERFACE_H_ */
