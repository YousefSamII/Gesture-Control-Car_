/* ===============================================
 * File Name        : SPI_Interface.h
 *
 * Project Name     : CarRobot_MC1
 *
 * Created on       : Sep 9, 2023
 *  
 * Author           : Yousef Sami
 * ===============================================*/

#ifndef COTS_MCAL_SPI_SPI_INTERFACE_H_
#define COTS_MCAL_SPI_SPI_INTERFACE_H_

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
/*
 * Default SPI data value used in case we need to receive a byte from the other device,
 * without need to send a data to it
 */
#define SPI_DEFAULT_DATA_VALUE 0xFF

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Initialize the SPI device as Master.
 */
void SPI_initMaster(void);

/*
 * Description :
 * Initialize the SPI device as Slave.
 */
void SPI_initSlave(void);

/*
 * Description :
 * Send the required data through SPI to the other SPI device.
 * In the same time data will be received from the other device.
 */
u8 SPI_sendReceiveByte(u8  data);

/*
 * Description :
 * Send the required string through SPI to the other SPI device.
 */
void SPI_sendString(const u8 *str);

/*
 * Description :
 * Receive the required string until the '#' symbol through SPI from the other SPI device.
 */
void SPI_receiveString(u8 *str);



#endif /* COTS_MCAL_SPI_SPI_INTERFACE_H_ */
