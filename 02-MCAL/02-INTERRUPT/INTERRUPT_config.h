/***************************************************************************************************
 *  File Name        : INTERRUOT_config.h
 *  Module           : INTERRUOT CONFIG
 *  Description      : to interface INTERRUPTT
 *  Created on       : may 24, 2021
 *  version          : v 01
 *  Author           : Salsabeel_Essam
 ***************************************************************************************************/

#ifndef INTERRUPT_CONFIG_H_
#define INTERRUPT_CONFIG_H_

// EXTERNL_INTERRUPT_0 =0   , EXTERNL_INTERRUPT_1 =1, EXTERNL_INTERRUPT_2 =3
#define EXTERNAL_INTERRUPT_NUMBER_PIN   EXTERNL_INTERRUPT_2

// AT_LOW_LEVEL =0   , AT_ANY_LOGICAL_CHANGE =1, AT_FALLING_EDGE=2, AT_RISING_EDGE=3
#define EXTERNAL_INTERRUPT_MODE_SELECTION   AT_FALLING_EDGE
/*********************************************************************/

// EXTERNL_INTERRUPT_0 =0   , EXTERNL_INTERRUPT_1 =1, EXTERNL_INTERRUPT_2 =3
#define EXTERNAL_INTERRUPT0_NUMBER_PIN   EXTERNL_INTERRUPT_0

// AT_LOW_LEVEL =0   , AT_ANY_LOGICAL_CHANGE =1, AT_FALLING_EDGE=2, AT_RISING_EDGE=3
#define EXTERNAL_INTERRUPT0_MODE_SELECTION   AT_FALLING_EDGE

/****************************************************************/

// EXTERNL_INTERRUPT_0 =0   , EXTERNL_INTERRUPT_1 =1, EXTERNL_INTERRUPT_2 =3
#define EXTERNAL_INTERRUPT1_NUMBER_PIN   EXTERNL_INTERRUPT_1

// AT_LOW_LEVEL =0   , AT_ANY_LOGICAL_CHANGE =1, AT_FALLING_EDGE=2, AT_RISING_EDGE=3
#define EXTERNAL_INTERRUPT1_MODE_SELECTION   AT_FALLING_EDGE

/*****************************************************************/

// EXTERNL_INTERRUPT_0 =0   , EXTERNL_INTERRUPT_1 =1, EXTERNL_INTERRUPT_2 =3
#define EXTERNAL_INTERRUPT2_NUMBER_PIN   EXTERNL_INTERRUPT_2

//  AT_FALLING_EDGE  , AT_RISING_EDGE
#define EXTERNAL_INTERRUPT2_MODE_SELECTION   AT_FALLING_EDGE

#endif /* INTERRUPT_CONFIG_H_ */
