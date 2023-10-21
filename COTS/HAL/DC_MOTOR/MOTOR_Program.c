/* ===============================================
 * File Name        : MOTOR_Program.c
 *
 * Project Name     : CarRobot_MC1
 *
 * Created on       : Sep 9, 2023
 *  
 * Author           : Yousef Sami
 * ===============================================*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_Math.h"
#include "../../MCAL/DIO/DIO.Interface.h"

#include "../../MCAL/TIMER0/TIMER0_Interface.h"
#include "MOTOR_Interface.h"
#include "MOTOR_Config.h"

void HMOTOR_vMotorInit(void)
{
	/* Make Pins which connected to motor O/P pins*/
	MDIO_vSetPinDirection(DC_MOTORT_PORT_ID , DC_MOTOR_LEFT_SIDE_FIRST_PIN_ID, OUTPUT);
	MDIO_vSetPinDirection(DC_MOTORT_PORT_ID , DC_MOTOR_LEFT_SIDE_SECOND_PIN_ID, OUTPUT);
	MDIO_vSetPinDirection(DC_MOTORT_PORT_ID , DC_MOTOR_RIGHT_SIDE_FIRST_PIN_ID, OUTPUT);
	MDIO_vSetPinDirection(DC_MOTORT_PORT_ID , DC_MOTOR_RIGHT_SIDE_SECOND_PIN_ID, OUTPUT);
	/*	Write LOW to make motor in Stop mode*/
	MDIO_vWritePin(DC_MOTORT_PORT_ID , DC_MOTOR_LEFT_SIDE_FIRST_PIN_ID ,LOW);
	MDIO_vWritePin(DC_MOTORT_PORT_ID , DC_MOTOR_LEFT_SIDE_SECOND_PIN_ID ,LOW);
	MDIO_vWritePin(DC_MOTORT_PORT_ID , DC_MOTOR_RIGHT_SIDE_FIRST_PIN_ID ,LOW);
	MDIO_vWritePin(DC_MOTORT_PORT_ID , DC_MOTOR_RIGHT_SIDE_SECOND_PIN_ID ,LOW);
	/****Choose Configuration of Timer0 in DcMotor ,Beacuse in Main i'm Just deal with HAL*****/
	/*
	 * 1.Fast PWM MODE
	 * 2.Non Inverting
	 * 3.Prescaler 8
	 */
	ConfigTimer0 timer0_config ={PWM_Fast, Non_Inverting , N_8};
	MTIMER0_vInit(&timer0_config);
}
void HMOTOR_vMotorForword(void)
{
	/* A= 1 , B= 0 --> Motor rotate cw for LEFT SIDE*/
	MDIO_vWritePin(DC_MOTORT_PORT_ID , DC_MOTOR_LEFT_SIDE_FIRST_PIN_ID,HIGH);
	MDIO_vWritePin(DC_MOTORT_PORT_ID , DC_MOTOR_LEFT_SIDE_SECOND_PIN_ID,LOW);
	/* A= 1 , B= 0 --> Motor rotate cw for RIGHT SIDE*/
	MDIO_vWritePin(DC_MOTORT_PORT_ID , DC_MOTOR_RIGHT_SIDE_FIRST_PIN_ID,HIGH);
	MDIO_vWritePin(DC_MOTORT_PORT_ID , DC_MOTOR_RIGHT_SIDE_SECOND_PIN_ID,LOW);
	/* Turn on Motor with Maximum Speed */
	MTIMER0_vStartPWM(255);
}
void HMOTOR_vMotorBack(void)
{
	/* A= 0 , B= 1 --> Motor rotate ccw for LEFT SIDE*/
	MDIO_vWritePin(DC_MOTORT_PORT_ID , DC_MOTOR_LEFT_SIDE_FIRST_PIN_ID,LOW);
	MDIO_vWritePin(DC_MOTORT_PORT_ID , DC_MOTOR_LEFT_SIDE_SECOND_PIN_ID,HIGH);
	/* A= 0 , B= 1 --> Motor rotate ccw for RIGHT SIDE*/
	MDIO_vWritePin(DC_MOTORT_PORT_ID , DC_MOTOR_RIGHT_SIDE_FIRST_PIN_ID,LOW);
	MDIO_vWritePin(DC_MOTORT_PORT_ID , DC_MOTOR_RIGHT_SIDE_SECOND_PIN_ID,HIGH);
	/* Turn on Motor with Maximum Speed */
	MTIMER0_vStartPWM(255);
}
void HMOTOR_vMotorRight(void)
{

	/* A= 1 , B= 0 --> Motor rotate cw for LEFT SIDE*/
	MDIO_vWritePin(DC_MOTORT_PORT_ID , DC_MOTOR_LEFT_SIDE_FIRST_PIN_ID,HIGH);
	MDIO_vWritePin(DC_MOTORT_PORT_ID , DC_MOTOR_LEFT_SIDE_SECOND_PIN_ID,LOW);
	/* A= 0 , B= 0 --> Motor stop for RIGHT SIDE*/
	MDIO_vWritePin(DC_MOTORT_PORT_ID , DC_MOTOR_RIGHT_SIDE_FIRST_PIN_ID,LOW);
	MDIO_vWritePin(DC_MOTORT_PORT_ID , DC_MOTOR_RIGHT_SIDE_SECOND_PIN_ID,LOW);
	/* Turn on Motor with 200 from 255 Speed */
	MTIMER0_vStartPWM(200);
}
void HMOTOR_vMotorLeft(void)
{
	/* A= 0 , B= 0 --> Motor Stop for LEFT SIDE*/
	MDIO_vWritePin(DC_MOTORT_PORT_ID , DC_MOTOR_LEFT_SIDE_FIRST_PIN_ID,LOW);
	MDIO_vWritePin(DC_MOTORT_PORT_ID , DC_MOTOR_LEFT_SIDE_SECOND_PIN_ID,LOW);
	/* A= 1 , B=0  --> Motor CW for RIGHT SIDE*/
	MDIO_vWritePin(DC_MOTORT_PORT_ID , DC_MOTOR_RIGHT_SIDE_FIRST_PIN_ID,HIGH);
	MDIO_vWritePin(DC_MOTORT_PORT_ID , DC_MOTOR_RIGHT_SIDE_SECOND_PIN_ID,LOW);
	/* Turn on Motor with 200 from 255 Speed */
	MTIMER0_vStartPWM(200);
}
void HMOTOR_vMotorBackRight(void)
{
	/* A= 0 , B= 0 --> Motor Stop for LEFT SIDE*/
	MDIO_vWritePin(DC_MOTORT_PORT_ID , DC_MOTOR_LEFT_SIDE_FIRST_PIN_ID,LOW);
	MDIO_vWritePin(DC_MOTORT_PORT_ID , DC_MOTOR_LEFT_SIDE_SECOND_PIN_ID,LOW);
	/* A= 0 , B=1  --> Motor CCW for RIGHT SIDE*/
	MDIO_vWritePin(DC_MOTORT_PORT_ID , DC_MOTOR_RIGHT_SIDE_FIRST_PIN_ID,LOW);
	MDIO_vWritePin(DC_MOTORT_PORT_ID , DC_MOTOR_RIGHT_SIDE_SECOND_PIN_ID,HIGH);
	/* Turn on Motor with 200 from 255 Speed */
	MTIMER0_vStartPWM(200);
}
void HMOTOR_vMotorBackLeft(void)
{
	/* A= 0 , B= 1 --> Motor rotate ccw for LEFT SIDE*/
	MDIO_vWritePin(DC_MOTORT_PORT_ID , DC_MOTOR_LEFT_SIDE_FIRST_PIN_ID,LOW);
	MDIO_vWritePin(DC_MOTORT_PORT_ID , DC_MOTOR_LEFT_SIDE_SECOND_PIN_ID,HIGH);
	/* A= 0 , B= 0 --> Motor stop for RIGHT SIDE*/
	MDIO_vWritePin(DC_MOTORT_PORT_ID , DC_MOTOR_RIGHT_SIDE_FIRST_PIN_ID,LOW);
	MDIO_vWritePin(DC_MOTORT_PORT_ID , DC_MOTOR_RIGHT_SIDE_SECOND_PIN_ID,LOW);
	/* Turn on Motor with 200 from 255 Speed */
	MTIMER0_vStartPWM(200);
}
