/* ===============================================
 * File Name        : DIO.Interface.h
 *
 * Project Name     : CarRobot_MC1
 *
 * Created on       : Aug 30, 2023
 *  
 * Author           : Yousef Sami
 * ===============================================*/

#ifndef COTS_MCAL_DIO_DIO_INTERFACE_H_
#define COTS_MCAL_DIO_DIO_INTERFACE_H_

#define INPUT		0
#define OUTPUT		1
#define WRONG_INPUT 25

#define HIGH		1
#define LOW			0

#define PORT_A		0
#define PORT_B		1
#define PORT_C		2
#define PORT_D		3

#define PIN0		0
#define PIN1		1
#define PIN2		2
#define PIN3		3
#define PIN4		4
#define PIN5		5
#define PIN6		6
#define PIN7		7

/* Description: Set pin direction (Output / input)
 * Arguments  : A_u8PortNumber, A_u8PinNumber, A_u8Dir
 *	A_u8PortNumber : the number of the port (0 ===> Port A, 1 ===> Port B... 3 ===> Port D)
 *  A_u8PinNumber  : the number of the pin  (0 ===> Pin 0, 1 ===> Pin 1, ... 7 ===> Pin 7)
 *  A_u8Dir        : 0 ===> input , 1===> output
 * Return type: void (Nothing)
 * */
void MDIO_vSetPinDirection(u8 A_u8PortNumber ,u8 A_u8PinNumber , u8 A_u8Dir);
/* Description: Set port direction (Output / input)
 * Arguments  : A_u8PortNumber, A_u8Dir
 *	A_u8PortNumber : the number of the port (0 ===> Port A, 1 ===> Port B... 3 ===> Port D)
 *  A_u8Dir        : 0 - 255
 * Return type: void (Nothing)
 * */
void MDIO_vSetPortDirection(u8 A_u8PortNumber , u8 A_u8Dir);
/* Description: Set pin value/status (High / Low)
 * Arguments  : A_u8PortNumber, A_u8PinNumber, A_u8Value
 *	A_u8PortNumber : the number of the port (0 ===> Port A, 1 ===> Port B... 3 ===> Port D)
 *  A_u8PinNumber  : the number of the pin  (0 ===> Pin 0, 1 ===> Pin 1, ... 7 ===> Pin 7)
 *  A_u8Value      : 0 ===> Low , 1===> High
 * Return type: void (Nothing)
 * */
void MDIO_vWritePin(u8 A_u8PortNumber ,u8 A_u8PinNumber , u8 A_u8Value);
/* Description: Set port value (High / Low)
 * Arguments  : A_u8PortNumber, A_u8Value
 *	A_u8PortNumber : the number of the port (0 ===> Port A, 1 ===> Port B... 3 ===> Port D)
 *  A_u8Value        : 0 - 255
 * Return type: void (Nothing)
 * */
void MDIO_vWritePort(u8 A_u8PortNumber ,u8 A_u8Value);
/* Description: get pin value/status (High / Low)
 * Arguments  : A_u8PortNumber, A_u8PinNumber
 *	A_u8PortNumber : the number of the port (0 ===> Port A, 1 ===> Port B... 3 ===> Port D)
 *  A_u8PinNumber  : the number of the pin  (0 ===> Pin 0, 1 ===> Pin 1, ... 7 ===> Pin 7)
 * Return type: u8 (value of the pin (0 --> low / 1--> high ))
 * */
u8 MDIO_u8ReadPin(u8 A_u8PortNumber ,u8 A_u8PinNumber);
/* Description: get PORT value/status
 * Arguments  : A_u8PortNumber
 *	A_u8PortNumber : the number of the port (0 ===> Port A, 1 ===> Port B... 3 ===> Port D)
 * Return type: u8 (value of the port)
 * */
u8 MDIO_u8ReadPort(u8 A_u8PortNumber );
/* Description: toggle pin value/status (High / Low)
 * Arguments  : A_u8PortNumber, A_u8PinNumber
 *	A_u8PortNumber : the number of the port (0 ===> Port A, 1 ===> Port B... 3 ===> Port D)
 *  A_u8PinNumber  : the number of the pin  (0 ===> Pin 0, 1 ===> Pin 1, ... 7 ===> Pin 7)
 * Return type: void (Nothing)
 * */
void MDIO_vTogglePinValue(u8 A_u8PortNumber, u8 A_u8PinNumber);

#endif /* COTS_MCAL_DIO_DIO_INTERFACE_H_ */
