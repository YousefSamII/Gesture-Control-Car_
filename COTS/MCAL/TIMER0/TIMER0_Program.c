/* ===============================================
 * File Name        : TIMER0_Program.c
 *
 * Project Name     : CarRobot_MC1
 *
 * Created on       : Sep 9, 2023
 *  
 * Author           : Yousef Sami
 * ===============================================*/
#include "../../LIB/BIT_Math.h"
#include "../../LIB/STD_TYPES.h"

#include "../DIO/DIO.Interface.h"

#include "TIMER0_Interface.h"
#include "TIMER0_Private.h"
#include "TIMER0_Config.h"

void MTIMER0_vInit(const ConfigTimer0 * Confige_Ptr )
{
	/***********************************************************
	 * 1.Set up Timer in Fast PWM Mode
	 * 2.Because WGM01 and WGM00 ,They're Not in Order
	 * 3.WGM01 BIT NUM 3 in TCCR0
	 * 4.WGM00 BIT NUM 6 in TCCR0
	 ************************************************************/
	TCCR0= (TCCR0 & 0xB7) | ((GET_BIT(Confige_Ptr ->Config_Mode,0))<<6) | (( GET_BIT(Confige_Ptr->Config_Mode,1))<<3);
	/* Non-Inverting PWM Mode Start from HIGH*/
	TCCR0 = ( TCCR0 & 0xCF) | (( Confige_Ptr->PWM_Mode)<<4);
	/*Choose PreScaler*/
	TCCR0 = ( TCCR0 & 0xF8 ) | (Confige_Ptr->Config_Prescaler);
	/*initial value 0 to timer register*/
	TCNT0=0;
	OCR0= 0;
}
void MTIMER0_vStartPWM(u8 A_u8DutyCycle)
{
	OCR0=A_u8DutyCycle;
	/* make OCR0 output pin */
	MDIO_vSetPinDirection(PORT_B , PIN3 , OUTPUT);

}
