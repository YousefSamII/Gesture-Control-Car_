/* ===============================================
 * File Name        : BUTTON_Program.c
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
#include "util/delay.h"
#include "BUTTON_Interface.h"
#include "BUTTON_Config.h"


u8 HBUTTON_u8ButtonIsPressed(void)
{
	u8 local_u8PinValue = 0;
	MDIO_vSetPinDirection(BUTTON_PORT_ID ,BUTTON_PIN_ID ,INPUT);
	if(MDIO_u8ReadPin(BUTTON_PORT_ID , BUTTON_PIN_ID) == PULL_DOWN_CONFIG_BUTTON_IS_PRESSED)
	{
		_delay_ms(30);		/* De-bounce Issue*/
		if(MDIO_u8ReadPin(BUTTON_PORT_ID, BUTTON_PIN_ID) == PULL_DOWN_CONFIG_BUTTON_IS_PRESSED)
		{
			local_u8PinValue = 1;
		}
	}
	return local_u8PinValue;
}
