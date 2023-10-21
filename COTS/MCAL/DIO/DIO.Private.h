/* ===============================================
 * File Name        : DIO.Private.h
 *
 * Project Name     : CarRobot_MC1
 *
 * Created on       : Aug 30, 2023
 *  
 * Author           : Yousef Sami
 * ===============================================*/

#ifndef COTS_MCAL_DIO_DIO_PRIVATE_H_
#define COTS_MCAL_DIO_DIO_PRIVATE_H_

/* Direction Registers */
#define DDRA		*((volatile u8 *)0x3A)
#define DDRB		*((volatile u8 *)0x37)
#define DDRC		*((volatile u8 *)0x34)
#define DDRD		*((volatile u8 *)0x31)

/* Output Registers */
#define PORTA		*((volatile u8 *)0x3B)
#define PORTB		*((volatile u8 *)0x38)
#define PORTC		*((volatile u8 *)0x35)
#define PORTD		*((volatile u8 *)0x32)

/* Input Registers */
#define PINA     	*((volatile u8 *)0x39)
#define PINB     	*((volatile u8 *)0x36)
#define PINC     	*((volatile u8 *)0x33)
#define PIND     	*((volatile u8 *)0x30)



#endif /* COTS_MCAL_DIO_DIO_PRIVATE_H_ */
