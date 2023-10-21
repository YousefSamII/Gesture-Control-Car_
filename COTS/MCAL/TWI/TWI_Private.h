/* ===============================================
 * File Name        : TWI_Private.h
 *
 * Project Name     : CarRobot_MC1
 *
 * Created on       : Sep 9, 2023
 *  
 * Author           : Yousef Sami
 * ===============================================*/

#ifndef COTS_MCAL_TWI_TWI_PRIVATE_H_
#define COTS_MCAL_TWI_TWI_PRIVATE_H_

#define TWDR 	(*(volatile u8 *)0x23)
#define TWAR    (*(volatile u8 *)0x22)
#define TWSR    (*(volatile u8 *)0x21)
#define TWBR    (*(volatile u8 *)0x20)
#define TWCR    (*(volatile u8 *)0x56)

#define TWEN		2
#define TWINT		7
#define TWSTA		5
#define TWSTO		4
#define TWEA		6

#endif /* COTS_MCAL_TWI_TWI_PRIVATE_H_ */
