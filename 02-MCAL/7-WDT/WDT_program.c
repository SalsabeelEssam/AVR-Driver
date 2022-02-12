/*
 * WDT_Program.c
 *
 *  Created on: Jun 20, 2021
 *      Author: Salsabeel Essam
 */

#include "STD_TYPE.h"
#include "BIT_MATH.h"
#include "WDT_Private.h"
#include "WDT_Interface.h"

void WDT_TIMER_ENABLE(void) {

	CLR_BIT(WDTCR, WDP0);
	SET_BIT(WDTCR, WDP1);
	SET_BIT(WDTCR, WDP2);

	SET_BIT(WDTCR, WDE);

}
void WDT_TIMER_DISABLE(void) {
ASSIGN_REG(WDTCR,0x18);
//WDTCR = 0b00011000;
ASSIGN_REG(WDTCR,0x00);
//WDTCR = 0b00000000;
}
