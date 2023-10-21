/* ===============================================
 * File Name        : LED_Program.c
 *
 * Project Name     : CarRobot_MC1
 *
 * Created on       : Sep 3, 2023
 *  
 * Author           : Yousef Sami
 * ===============================================*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_Math.h"
#include "../../MCAL/DIO/DIO.Interface.h"

#include "LED_Interface.h"
#include "LED_Config.h"

void HLED_vLedOn(void)
{
	MDIO_vSetPinDirection(LED_PORT_ID , LED_PIN_ID , OUTPUT);
	MDIO_vWritePin(LED_PORT_ID , LED_PIN_ID ,POSITIVE_LOGIC_CONFIG);
}

void HLED_vLedOff(void)
{
	MDIO_vSetPinDirection(LED_PORT_ID , LED_PIN_ID , OUTPUT);
	MDIO_vWritePin(LED_PORT_ID , LED_PIN_ID ,LED_OFF_VALUE);
}
void HLED_vToggle(void)
{
	MDIO_vSetPinDirection(LED_PORT_ID , LED_PIN_ID , OUTPUT);
	MDIO_vTogglePinValue(LED_PORT_ID , LED_PIN_ID );
}
