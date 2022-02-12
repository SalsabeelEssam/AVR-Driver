/***************************************************************************************************
 *  File Name        : INTERRUOT_private.h
 *  Module           : INTERRUOT PRIVATE
 *  Description      : save register and private function
 *  Created on       : May 24, 2021
 *  version          : v 01
 *  Author           : Salsabeel_Essam
 ***************************************************************************************************/

#ifndef INTERRUPT_PRIVATE_H_
#define INTERRUPT_PRIVATE_H_

#define MCUCR   (*(volatile u8*)  0x55)
#define MCUCSR  (*(volatile u8*)  0x54)
#define GICR    (*(volatile u8*)  0x5B)
#define GIFR    (*(volatile u8*)  0x5A)

// REGISTER MCUCR
// int1
#define ISC11  3
#define ISC10  2
// int0
#define ISC01  1
#define ISC00  0


// REGISTER MCUCSR
// int2
#define ISC2  6

// REGISTER GICR
#define INT1  7
#define INT0  6
#define INT2  5

// REGISTER GIFR
#define INTF1  7
#define INTF0  6
#define INTF2  5

// EXTERNL_INTERRUPT_0 =0   , EXTERNL_INTERRUPT_1 =1, EXTERNL_INTERRUPT_0 =3
#define EXTERNL_INTERRUPT_0  0
#define EXTERNL_INTERRUPT_1  1
#define EXTERNL_INTERRUPT_2  2


// AT_LOW_LEVEL =0   , AT_ANY_LOGICAL_CHANGE =1, AT_FALLING_EDGE=2, AT_RISING_EDGE=3
#define AT_LOW_LEVEL              0
#define AT_ANY_LOGICAL_CHANGE     1
#define AT_FALLING_EDGE           2
#define AT_RISING_EDGE            3


void __vector_1(void) __attribute__((signal));
void __vector_2(void) __attribute__((signal));
void __vector_3(void) __attribute__((signal));


#endif /* INTERRUPT_PRIVATE_H_ */
