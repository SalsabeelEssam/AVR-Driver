/*
 * TIMER_Interface.h
 *
 *  Created on: Jun 8, 2021
 *      Author: Salsabeel Essam
 */

#ifndef ICU_INTERFACE_H_
#define ICU_INTERFACE_H_



void SWICU_VoidInit(void);

void SWICU_U8GetTotalPeriod(u32 * Copy_U8TotalPeriod);
void SWICU_U8GetDutyCycle(u8 * Copy_U8DutyCycle);

#endif /* ICU_INTERFACE_H_ */
