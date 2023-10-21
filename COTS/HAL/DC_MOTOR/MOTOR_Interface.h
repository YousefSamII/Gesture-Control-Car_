/* ===============================================
 * File Name        : MOTOR_Interface.h
 *
 * Project Name     : CarRobot_MC1
 *
 * Created on       : Sep 9, 2023
 *  
 * Author           : Yousef Sami
 * ===============================================*/

#ifndef COTS_HAL_DC_MOTOR_MOTOR_INTERFACE_H_
#define COTS_HAL_DC_MOTOR_MOTOR_INTERFACE_H_

/*
 * Function Name: HMOTOR_vMotorInit()
 * Description:
 * 	The Function responsible for setup the direction for the two
 *	motor pins through the GPIO driver.
 *	Stop at the DC-Motor at the beginning through the GPIO driver.
 */
void HMOTOR_vMotorInit(void);
/*
 * Description :
 * 		Set up direction of four wheel for RC car
 */
void HMOTOR_vMotorForword(void);
void HMOTOR_vMotorBack(void);
void HMOTOR_vMotorRight(void);
void HMOTOR_vMotorLeft(void);
void HMOTOR_vMotorBackRight(void);
void HMOTOR_vMotorBackLeft(void);


#endif /* COTS_HAL_DC_MOTOR_MOTOR_INTERFACE_H_ */
