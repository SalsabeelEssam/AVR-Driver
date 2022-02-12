/*
 * TIMER_Program.c
 *
 *  Created on: Jun 8, 2021
 *      Author: Salsabeel Essam
 */

#include"STD_TYPE.h" // LIB
#include"BIT_MATH.h"  // LIB
#include"DIO_INTERFACE.h" // DIO
#include "TIMER_INTERFACE.h"
#include "INTERRUPT_Interface.h"
#include "ICU_Interface.h"
#include "ICU_Private.h"
#include "ICU_Config.h"

static u16 SWICU_ONPeriod;
static u16 SWICU_OffPeroid;
void SWICU_VoidInit(void){
	/* INIT TIMER 1*/
	TIMER1_VoidINT();

	/* SET CALL BACK FUNCTION*/
	INT0_SET_Call_Back(&SWICU_VoidcallBack);

	/*INIT EXTERNAL INTERRUPT*/
	INTERRUPT0_Void_INT();

	/* start edge detect rising or falling*/
#if SWICU_U8_STARTING_EDGE == RISIGN_EDGE
	set_int0_raising();
#elif  SWICU_U8_STARTING_EDGE == FALLING_EDGE
	set_int0_falling();
#endif
}

void SWICU_U8GetTotalPeriod(u32 * Copy_U8TotalPeriod){
	(*Copy_U8TotalPeriod) = (u32)(SWICU_ONPeriod + SWICU_OffPeroid);
}
void SWICU_U8GetDutyCycle(u8 * Copy_U8DutyCycle){
	// for no overflow = UL for no point in value *100
	(*Copy_U8DutyCycle) = (u8)(SWICU_ONPeriod * 100UL / (SWICU_ONPeriod + SWICU_OffPeroid));
}


static void SWICU_VoidcallBack(void) {
	static u8 flag = SWICU_U8_STARTING_EDGE;
	static u16 value_of_timer1_new = 0;
	static u16 value_of_timer1_old = 0;
	TIMER1_GET_COUNTER_VALUE(&value_of_timer1_new);
	if (flag == RISIGN_EDGE) {
		//Rising Edge
		// just number of  1 us tick we multible in time of one time
		SWICU_OffPeroid = value_of_timer1_new - value_of_timer1_old;
		set_int0_falling();
		flag = FALLING_EDGE;
	} else if (flag == FALLING_EDGE) {
		// falling edge
		SWICU_ONPeriod = value_of_timer1_new - value_of_timer1_old;
		set_int0_raising();
		flag = RISIGN_EDGE;
	}

	value_of_timer1_old = value_of_timer1_new;
}
