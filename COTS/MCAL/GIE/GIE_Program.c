/* ===============================================
 * File Name        : GIE_Program.c
 * 
 * Created on       : Sep 3, 2023
 *  
 * Time  			: 9:58:21 AM
 *
 * Author           : Yousef Sami
 * ===============================================*/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_Math.h"
#include "GIE_Interface.h"
#include "GIE_Private.h"

void MGIE_vInterruptEnable(void)
{
	SET_BIT(SREG , I_Bit );
	/*  sei() */
}
void MGIE_vInterruptDisable(void)
{
	CLEAR_BIT(SREG , I_Bit);
	/* cli() */
}
