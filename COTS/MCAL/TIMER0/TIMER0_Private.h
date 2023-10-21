/* ===============================================
 * File Name        : TIMER0_Private.h
 *
 * Project Name     : CarRobot_MC1
 *
 * Created on       : Sep 9, 2023
 *  
 * Author           : Yousef Sami
 * ===============================================*/

#ifndef COTS_MCAL_TIMER0_TIMER0_PRIVATE_H_
#define COTS_MCAL_TIMER0_TIMER0_PRIVATE_H_

/* Define Timer0 Registers */
#define TCCR0  *((volatile u8 *)0x53)
#define TCNT0  *((volatile u8 *)0x52)
#define OCR0   *((volatile u8 *)0x5C)
#define TIMSK  *((volatile u8 *)0x59)
#define TIFR   *((volatile u8 *)0x58)
/* Define Pins number */
#define WGM01  PIN6
#define WGM00  PIN3
#define CS02   PIN2
#define CS01   PIN1
#define CS00   PIN0
#define TOIE0  PIN0

#define COM01  PIN5
#define COM00  PIN4

#define OCIE0  PIN1


#endif /* COTS_MCAL_TIMER0_TIMER0_PRIVATE_H_ */
