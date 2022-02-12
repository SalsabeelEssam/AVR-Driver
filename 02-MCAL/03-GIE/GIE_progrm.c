/***************************************************************************************************
 *  File Name        : GIE_program.C
 *  Module           : GIE program
 *  Description      : public function
 *  Created on       : May 24, 2021
 *  version          : v 01
 *  Author           : Salsabeel_Essam
 ***************************************************************************************************/

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"GIE_Private.h"


void GIE_VoidEnable(void){
  SET_BIT(SREG,I_BIT);
}

void GIE_VoidDisable(void){
	CLR_BIT(SREG,I_BIT);
}
