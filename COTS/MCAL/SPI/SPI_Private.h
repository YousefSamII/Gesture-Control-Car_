/* ===============================================
 * File Name        : SPI_Private.h
 *
 * Project Name     : CarRobot_MC1
 *
 * Created on       : Sep 9, 2023
 *  
 * Author           : Yousef Sami
 * ===============================================*/

#ifndef COTS_MCAL_SPI_SPI_PRIVATE_H_
#define COTS_MCAL_SPI_SPI_PRIVATE_H_

/********* SPI Register ***********/
#define SPCR  (*(volatile u8 *) 0x2D)
#define SPSR  (*(volatile u8 *) 0x2E)
#define SPDR  (*(volatile u8 *) 0x2F)

/*********   SPI PINS 	***********/
#define SPIF 		PIN7
#define WCOL		PIN6
#define SPI2X		PIN0
#define SPE			PIN6
#define MSTR		PIN4
#define SPR0		PIN0



#endif /* COTS_MCAL_SPI_SPI_PRIVATE_H_ */
