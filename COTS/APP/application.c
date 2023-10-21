/* ===============================================
 * File Name        : application.c
 *
 * Project Name     : CarRobot_MC1
 *
 * Created on       : Sep 10, 2023
 *
 * Author           : Yousef Sami
 * ===============================================*/
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO.Interface.h"

#include "../HAL/NRF/NRF_Interface.h"
//#include "../HAL/LCD/LCD_Interface.h"
#include "../HAL/LED/LED_Interface.h"
//#include "../HAL/DC_MOTOR/MOTOR_Interface.h"
#include "../HAL/MPU6050/MPU6050_Interface.h"
#include "../HAL/PUSH_BUTTON/BUTTON_Interface.h"
#include <util/delay.h>

int main(void)
{
	s16 accX ,accY ,accZ,gyroX,gyroY,gyroZ;
	HNRF_vInit();
	HMPU6050_vInit();
	while(1)
	{
		HMPU6050_vReadData(&accX,&accY,&accZ,&gyroX,&gyroY,&gyroZ);
		if((accX > 11000) && (accX < 14000))
		{
			HNRF_u8SendMessage("l",1);
		}
		else if((accX >14000))
		{
			HNRF_u8SendMessage("L",1);
		}
		else if((accX < -11000) && (accX > -14000))
		{
			HNRF_u8SendMessage("r",1);
		}
		else if(accX <-14000)
		{
			HNRF_u8SendMessage("R",1);
		}
		else if((accY > 11000 )&& (accY <14000))
		{
			HNRF_u8SendMessage("b",1);
		}
		else if((accY >14000))
		{
			HNRF_u8SendMessage("B",1);
		}
		else if((accY < -11000) && (accY >-14000))
		{
			HNRF_u8SendMessage("f",1);
		}
		else if(accY <-14000)
		{
			HNRF_u8SendMessage("F",1);
		}
		else if((accZ > 11000) || (accZ <-11000))
		{
			HNRF_u8SendMessage("S",1);
		}
		else
		{
			HNRF_u8SendMessage("0",1);
		}
		_delay_ms(10);
	}
	return 0;
	}

