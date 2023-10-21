/* ===============================================
 * File Name        : DIO.Program.c
 *
 * Project Name     : CarRobot_MC1
 *
 * Created on       : Aug 30, 2023
 *  
 * Author           : Yousef Sami
 * ===============================================*/

/* Libraries included*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_Math.h"
#include "DIO.Interface.h"
#include "DIO.Private.h"
#include "DIO.Config.h"

void MDIO_vSetPinDirection(u8 A_u8PortNumber ,u8 A_u8PinNumber , u8 A_u8Dir)
{
	if(A_u8PortNumber >= PORTs_NUMBER || A_u8PinNumber >= PINs_NUMBER)
	{
		/* Do nothing*/
	}
	else
	{
		if(A_u8Dir == INPUT)
		{
			switch(A_u8PortNumber)
			{
			case PORT_A: CLEAR_BIT(DDRA,A_u8PinNumber);break;
			case PORT_B: CLEAR_BIT(DDRB,A_u8PinNumber);break;
			case PORT_C: CLEAR_BIT(DDRC,A_u8PinNumber);break;
			case PORT_D: CLEAR_BIT(DDRD,A_u8PinNumber);break;
			}
		}
		else if(A_u8Dir == OUTPUT)
		{
			switch(A_u8PortNumber)
			{
			case PORT_A: SET_BIT(DDRA,A_u8PinNumber);break;
			case PORT_B: SET_BIT(DDRB,A_u8PinNumber);break;
			case PORT_C: SET_BIT(DDRC,A_u8PinNumber);break;
			case PORT_D: SET_BIT(DDRD,A_u8PinNumber);break;
			}
		}
		else
		{
			/* Do nothing */
		}
	}
}
void MDIO_vSetPortDirection(u8 A_u8PortNumber , u8 A_u8Dir)
{
	if(A_u8PortNumber >= PORTs_NUMBER)
	{
		/* Do nothing */
	}
	else
	{
		switch(A_u8PortNumber)
		{
		case PORT_A : DDRA = A_u8Dir;break;
		case PORT_B : DDRB = A_u8Dir;break;
		case PORT_C : DDRC = A_u8Dir;break;
		case PORT_D : DDRD = A_u8Dir;break;
		}
	}
}

void MDIO_vWritePin(u8 A_u8PortNumber ,u8 A_u8PinNumber , u8 A_u8Value)
{
	if(A_u8PortNumber >= PORTs_NUMBER || A_u8PinNumber >= PINs_NUMBER)
	{
		/* Do nothing */
	}
	else
	{
		if(A_u8Value == HIGH)
		{
			switch(A_u8PortNumber)
			{
			case PORT_A : SET_BIT(PORTA,A_u8PinNumber);break;
			case PORT_B : SET_BIT(PORTB,A_u8PinNumber);break;
			case PORT_C : SET_BIT(PORTC,A_u8PinNumber);break;
			case PORT_D : SET_BIT(PORTD,A_u8PinNumber);break;
			}
		}
		else if(A_u8Value == LOW)
		{
			switch(A_u8PortNumber)
			{
			case PORT_A : CLEAR_BIT(PORTA,A_u8PinNumber);break;
			case PORT_B : CLEAR_BIT(PORTB,A_u8PinNumber);break;
			case PORT_C : CLEAR_BIT(PORTC,A_u8PinNumber);break;
			case PORT_D : CLEAR_BIT(PORTD,A_u8PinNumber);break;
			}
		}
	}
}

void MDIO_vWritePort(u8 A_u8PortNumber ,u8 A_u8Value)
{
	if(A_u8PortNumber >= PORTs_NUMBER)
	{
		/* Do nothing */
	}
	else
	{
		switch(A_u8PortNumber)
		{
		case PORT_A: PORTA =A_u8Value;break;
		case PORT_B: PORTB =A_u8Value;break;
		case PORT_C: PORTC =A_u8Value;break;
		case PORT_D: PORTD =A_u8Value;break;
		}
	}
}

u8 MDIO_u8ReadPin(u8 A_u8PortNumber ,u8 A_u8PinNumber)
{
	u8 Local_u8PinValue =WRONG_INPUT;
	if(A_u8PortNumber >= PORTs_NUMBER || A_u8PinNumber >= PINs_NUMBER)
	{
		/* Do nothing */
	}
	else
	{
		switch(A_u8PortNumber)
		{
		case PORT_A :
			if(BIT_IS_SET(PINA,A_u8PinNumber))
				Local_u8PinValue=HIGH;
			else
				Local_u8PinValue =LOW;
			break;
		case PORT_B :
			if(BIT_IS_SET(PINB,A_u8PinNumber))
				Local_u8PinValue=HIGH;
			else
				Local_u8PinValue =LOW;
			break;
		case PORT_C :
			if(BIT_IS_SET(PINC,A_u8PinNumber))
				Local_u8PinValue=HIGH;
			else
				Local_u8PinValue =LOW;
			break;
		case PORT_D :
			if(BIT_IS_SET(PIND,A_u8PinNumber))
				Local_u8PinValue=HIGH;
			else
				Local_u8PinValue =LOW;
			break;
		}
	}
	return Local_u8PinValue;
}

u8 MDIO_u8ReadPort(u8 A_u8PortNumber )
{
	u8 Local_PortValue =WRONG_INPUT;
	if(A_u8PortNumber >= PORTs_NUMBER)
	{
		/* Do nothing */
	}
	else
	{
		switch(A_u8PortNumber)
		{
		case PORT_A : Local_PortValue=PINA; break;
		case PORT_B : Local_PortValue=PINB; break;
		case PORT_C : Local_PortValue=PINC; break;
		case PORT_D : Local_PortValue=PIND; break;
		}
	}
	return Local_PortValue;
}
void MDIO_vTogglePinValue(u8 A_u8PortNumber, u8 A_u8PinNumber)
{
	switch(A_u8PortNumber)
	{
	case PORT_A: TOGGLE_BIT(PORTA ,A_u8PinNumber);break;
	case PORT_B: TOGGLE_BIT(PORTB ,A_u8PinNumber);break;
	case PORT_C: TOGGLE_BIT(PORTC ,A_u8PinNumber);break;
	case PORT_D: TOGGLE_BIT(PORTD ,A_u8PinNumber);break;
	}
}
