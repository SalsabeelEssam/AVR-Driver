/***************************************************************************************************
 *  File Name        : INTERRUOT_interface.h
 *  Module           : INTERRUOT INTERFACE
 *  Description      : to interface INTERRUPTT
 *  Created on       : may 24, 2021
 *  version          : v 01
 *  Author           : Salsabeel_Essam
 ***************************************************************************************************/

#ifndef INTERRUPT_INTERFACE_H_
#define INTERRUPT_INTERFACE_H_

void EXTERNL_INTERRUPT_VoidInti(void);

/****************************************/
void INTERRUPT0_Void_INT(void);
void INTERRUPT1_Void_INT(void);
void INTERRUPT2_Void_INT(void);
/******************************************/
// Set call BACK functions to all ISR interrupt 0, 1,2

//SEt  call back function to interrupt 0
void INT0_SET_Call_Back(void (* INT0_Ptr_to_fun)(void));

//SEt  call back function to interrupt 1
void INT1_SET_Call_Back(void (* INT1_Ptr_to_fun)(void));

//SEt  call back function to interrupt 2
void INT2_SET_Call_Back(void (* INT2_Ptr_to_fun)(void));

#endif /* INTERRUPT_INTERFACE_H_ */
