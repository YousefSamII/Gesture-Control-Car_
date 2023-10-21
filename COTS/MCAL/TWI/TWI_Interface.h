/* ===============================================
 * File Name        : TWI_Interface.h
 *
 * Project Name     : CarRobot_MC1
 *
 * Created on       : Sep 9, 2023
 *  
 * Author           : Yousef Sami
 * ===============================================*/

#ifndef COTS_MCAL_TWI_TWI_INTERFACE_H_
#define COTS_MCAL_TWI_TWI_INTERFACE_H_
#include "../../LIB/STD_TYPES.h"

typedef struct{

	u8 BAUD_RATE;
	u8 Address;
}TWI_ConfigType;
/*
 * Descritpion :
 * 		Initialization of TWI comm. protocol
 */
void MTWI_vInit(const TWI_ConfigType * Config_Ptr);
/*
 * Description :
 * 		Send Start Condition
 */
void MTWI_vStartCondition(void);
/*
 * Function Name : MTWI_vStop()
 * Description	 : send Stop Condition
 */
void MTWI_vStop(void);
/*
 * Function Name : MTWI_vWriteByte()
 * Description	 : send data using TWI
 */
void MTWI_vWriteByte(u8 A_u8Data);
/*
 * Function Name : MTWI_u8ReadByteWithACK()
 * Description:  return a byte with ACK bit (0)
 */
u8 MTWI_u8ReadByteWithACK(void);
/*
 * Function Name : MTWI_u8ReadByteWithNACK()
 * Description:  return a byte with No ACK bit ---idle state =1
 */
u8 MTWI_u8ReadByteWithNACK(void);
/*
 * Function Name : MTWI_u8ReadStatus()
 * Description:  return status register
 */
u8 MTWI_u8ReadStatus(void);

#endif /* COTS_MCAL_TWI_TWI_INTERFACE_H_ */
