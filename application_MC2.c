/* ===============================================
 * File Name        : application.c
 *
 * Project Name     : CarRobot_MC1
 *
 * Created on       : Sep 10, 2023
 *
 * Author           : Yousef Sami
 * ===============================================*/
#include <avr/io.h>
#include <avr/interrupt.h>
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO.Interface.h"

#include "../HAL/NRF/NRF_Interface.h"
#include "../HAL/LCD/LCD_Interface.h"
#include "../HAL/LED/LED_Interface.h"
#include "../HAL/DC_MOTOR/MOTOR_Interface.h"
//#include "../HAL/MPU6050/MPU6050_Interface.h"
#include "../HAL/PUSH_BUTTON/BUTTON_Interface.h"

#include <util/delay.h>
#include "DFs.h"
u8 * message = '0';
int main(void)
{
	HNRF_vInit();
	HMOTOR_vMotorInit();
	HNRF_vStartListening();
	MDIO_vSetPinDirection(IR_PORT_ID,IR_PIN_ID ,INPUT);
	MDIO_vSetPinDirection(BUZZ_PORT_ID,BUZZ_PIN_ID ,OUTPUT);
	MDIO_vWritePin(BUZZ_PORT_ID ,BUZZ_PIN_ID,LOW);
	DDRA |=(1<<PA0);
	while(1)
	{
		if(!(PIND & (1<<PD3)))
		{
			MDIO_vWritePin(BUZZ_PORT_ID,BUZZ_PIN_ID,HIGH);
			HMOTOR_vMotorStop();
		}
		else
		{
			MDIO_vWritePin(BUZZ_PORT_ID,BUZZ_PIN_ID,LOW);
			if(HNRF_vAvailable())
			{
				message=NRF_vReadMessage();
				switch(message[0])
				{
				case 'l':
					message[0]='0';
					HMOTOR_vMotorLeft(125);
					break;
				case 'L':
					message[0]='0';
					HMOTOR_vMotorLeft(255);
					break;
				case 'r':
					message[0]='0';
					HMOTOR_vMotorRight(125);
					break;
				case 'R' :
					message[0]='0';
					HMOTOR_vMotorRight(255);
					break;
				case 'f' :
					message[0]='0';
					HMOTOR_vMotorForword(125);
					break;
				case 'F' :
					message[0]='0';
					HMOTOR_vMotorForword(255);
					break;
				case 'b' :
					message[0]='0';
					HMOTOR_vMotorBack(125);
					break;
				case 'B' :
					message[0]='0';
					HMOTOR_vMotorBack(255);
					break;
				case 'S' :
					HMOTOR_vMotorStop();
					break;
				case '0' :
					HMOTOR_vMotorStop();
					break;
				default :
					message[0]='0';
					HMOTOR_vMotorStop();
					break;
				}

			}
		}

		_delay_ms(10);
	}


	return 0;
}

