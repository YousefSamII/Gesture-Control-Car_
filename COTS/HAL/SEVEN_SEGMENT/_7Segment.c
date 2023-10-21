/* ===============================================
 * File Name        : _7Segment.c
 *
 * Project Name     : LAB1
 *
 * Created on       : Aug 31, 2023
 *  
 * Author           : Yousef Sami
 * ===============================================*/

#include "_7Segment.h"
void H7SEG_vDisplayNumber(u8 A_u8PortNumber,u8 A_u8Number)
{
	MDIO_vSetPortDirection(A_u8PortNumber,255);
	switch(A_u8Number)
	{
	case 0:
		MDIO_vWritePort(A_u8PortNumber,ZERO);
		break;
	case 1:
		MDIO_vWritePort(A_u8PortNumber,ONE);
		break;
	case 2:
		MDIO_vWritePort(A_u8PortNumber,TWO);
		break;
	case 3 :
		MDIO_vWritePort(A_u8PortNumber,THREE);
		break;
	case 4 :
		MDIO_vWritePort(A_u8PortNumber,FOUR);
		break;
	case 5:
		MDIO_vWritePort(A_u8PortNumber,FIVE);
		break;
	case 6:
		MDIO_vWritePort(A_u8PortNumber,SIX);
		break;
	case 7 :
		MDIO_vWritePort(A_u8PortNumber,SEVEN);
		break;
	case 8:
		MDIO_vWritePort(A_u8PortNumber,EIGHT);
		break;
	case 9:
		MDIO_vWritePort(A_u8PortNumber,NINE);
		break;

	}
}
