/***************************************************************************************************
 *  File Name        : INTERRUOT_program.C
 *  Module           : INTERRUOT_program
 *  Description      : public function
 *  Created on       : May 24, 2021
 *  version          : v 01
 *  Author           : Salsabeel_Essam
 ***************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "INTERRUPT_config.h"
#include "INTERRUPT_private.h"
#include "INTERRUPT_interface.h"

static  void (*Call_Back_INT0_Ptr)(void) = NULL;
static  void (*Call_Back_INT1_Ptr)(void) = NULL;
static  void (*Call_Back_INT2_Ptr)(void) = NULL;

void EXTERNL_INTERRUPT_VoidInti(void) {
#if EXTERNAL_INTERRUPT_NUMBER_PIN == EXTERNL_INTERRUPT_0
	SET_BIT(GICR, INT0);
#if EXTERNAL_INTERRUPT_MODE_SELECTION == AT_LOW_LEVEL
	CLR_BIT(MCUCR, ISC00);
	CLR_BIT(MCUCR, ISC01);
#elif EXTERNAL_INTERRUPT_MODE_SELECTION == AT_ANY_LOGICAL_CHANGE
	SET_BIT(MCUCR,ISC00);
	CLR_BIT(MCUCR,ISC01);
#elif EXTERNAL_INTERRUPT_MODE_SELECTION == AT_FALLING_EDGE
	CLR_BIT(MCUCR,ISC00);
	SET_BIT(MCUCR,ISC01);
#elif EXTERNAL_INTERRUPT_MODE_SELECTION == AT_RISING_EDGE
	SET_BIT(MCUCR,ISC00);
	SET_BIT(MCUCR,ISC01);
#else
#warning "Wrong Input"
#endif
#elif EXTERNAL_INTERRUPT_NUMBER_PIN == EXTERNL_INTERRUPT_1
	SET_BIT(GICR, INT1);
#if EXTERNAL_INTERRUPT_MODE_SELECTION == AT_LOW_LEVEL
	CLR_BIT(MCUCR, ISC10);
	CLR_BIT(MCUCR, ISC11);
#elif EXTERNAL_INTERRUPT_MODE_SELECTION == AT_ANY_LOGICAL_CHANGE
	SET_BIT(MCUCR,ISC10);
	CLR_BIT(MCUCR,ISC11);
#elif EXTERNAL_INTERRUPT_MODE_SELECTION == AT_FALLING_EDGE
	CLR_BIT(MCUCR, ISC10);
	SET_BIT(MCUCR, ISC11);
#elif EXTERNAL_INTERRUPT_MODE_SELECTION == AT_RISING_EDGE
	SET_BIT(MCUCR,ISC10);
	SET_BIT(MCUCR,ISC11);
#else
#warning "Wrong Input"
#endif
#elif EXTERNAL_INTERRUPT_NUMBER_PIN == EXTERNL_INTERRUPT_2
	SET_BIT(GICR, INT2);
#if EXTERNAL_INTERRUPT_MODE_SELECTION == AT_FALLING_EDGE
	CLR_BIT(MCUCSR, ISC2);
#elif EXTERNAL_INTERRUPT_MODE_SELECTION == AT_RISING_EDGE
	SET_BIT(MCUCSR,ISC2);
#else
#warning "Wrong Input"
#endif
#else
#warning "Wrong Input"
#endif
}

void INTERRUPT0_Void_INT(void) {
#if EXTERNAL_INTERRUPT0_NUMBER_PIN == EXTERNL_INTERRUPT_0
	SET_BIT(GICR, INT0);
#if EXTERNAL_INTERRUPT0_MODE_SELECTION == AT_LOW_LEVEL
	CLR_BIT(MCUCR, ISC00);
	CLR_BIT(MCUCR, ISC01);
#elif EXTERNAL_INTERRUPT0_MODE_SELECTION == AT_ANY_LOGICAL_CHANGE
	SET_BIT(MCUCR,ISC00);
	CLR_BIT(MCUCR,ISC01);
#elif EXTERNAL_INTERRUPT0_MODE_SELECTION == AT_FALLING_EDGE
	CLR_BIT(MCUCR,ISC00);
	SET_BIT(MCUCR,ISC01);
#elif EXTERNAL_INTERRUPT0_MODE_SELECTION == AT_RISING_EDGE
	SET_BIT(MCUCR,ISC00);
	SET_BIT(MCUCR,ISC01);
#else
#warning "Wrong Input"
#endif
#endif
}

void INTERRUPT1_Void_INT(void) {
#if EXTERNAL_INTERRUPT1_NUMBER_PIN == EXTERNL_INTERRUPT_1
	SET_BIT(GICR, INT1);
#if EXTERNAL_INTERRUPT1_MODE_SELECTION == AT_LOW_LEVEL
	CLR_BIT(MCUCR, ISC10);
	CLR_BIT(MCUCR, ISC11);
#elif EXTERNAL_INTERRUPT1_MODE_SELECTION == AT_ANY_LOGICAL_CHANGE
	SET_BIT(MCUCR,ISC10);
	CLR_BIT(MCUCR,ISC11);
#elif EXTERNAL_INTERRUPT1_MODE_SELECTION == AT_FALLING_EDGE
	CLR_BIT(MCUCR, ISC10);
	SET_BIT(MCUCR, ISC11);
#elif EXTERNAL_INTERRUPT1_MODE_SELECTION == AT_RISING_EDGE
	SET_BIT(MCUCR,ISC10);
	SET_BIT(MCUCR,ISC11);
#else
#warning "Wrong Input"
#endif
#endif
}

void INTERRUPT2_Void_INT(void) {
#if EXTERNAL_INTERRUPT2_NUMBER_PIN == EXTERNL_INTERRUPT_2
	SET_BIT(GICR, INT2);
#if EXTERNAL_INTERRUPT2_MODE_SELECTION == AT_FALLING_EDGE
	CLR_BIT(MCUCSR, ISC2);
#elif EXTERNAL_INTERRUPT2_MODE_SELECTION == AT_RISING_EDGE
	SET_BIT(MCUCSR,ISC2);
#else
#warning "Wrong Input"
#endif
#else
#warning "Wrong Input"
#endif
}


/*******************************************************/
//SEt  call back function to interrupt 0
void INT0_SET_Call_Back(void (*INT0_Ptr_to_fun)(void)) {
	Call_Back_INT0_Ptr = INT0_Ptr_to_fun;
}

//SEt  call back function to interrupt 1
void INT1_SET_Call_Back(void (*INT1_Ptr_to_fun)(void)) {
	Call_Back_INT1_Ptr = INT1_Ptr_to_fun;
}

//SEt  call back function to interrupt 2
void INT2_SET_Call_Back(void (*INT2_Ptr_to_fun)(void)) {
	Call_Back_INT2_Ptr = INT2_Ptr_to_fun;
}

/********************************************************/
//ISR INT0
void __vector_1(void) {
	if (Call_Back_INT0_Ptr != NULL) {
		Call_Back_INT0_Ptr();
		// (*Call_Back_INT0_Ptr)();
	}
}
//ISR INT1
void __vector_2(void) {
	if (Call_Back_INT1_Ptr != NULL) {
		Call_Back_INT1_Ptr();
		//(*Call_Back_INT1_Ptr)();
	}
}
//ISR INT2
void __vector_3(void) {
	if (Call_Back_INT2_Ptr != NULL) {
		Call_Back_INT2_Ptr();
		//(*Call_Back_INT2_Ptr)();
	}
}
