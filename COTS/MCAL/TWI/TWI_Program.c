/* ===============================================
 * File Name        : TWI_Program.c
 *
 * Project Name     : CarRobot_MC1
 *
 * Created on       : Sep 9, 2023
 *  
 * Author           : Yousef Sami
 * ===============================================*/
#include "../../LIB/BIT_Math.h"
#include "../../LIB/STD_TYPES.h"

#include "../DIO/DIO.Interface.h"

#include "TWI_Interface.h"
#include "TWI_Config.h"
#include "TWI_Private.h"

void MTWI_vInit(const TWI_ConfigType * Config_Ptr)
{
	/* Select Baud Rate*/
	TWBR = Config_Ptr->BAUD_RATE;
	/*Enable Module*/
	TWCR |= (1<<TWEN);
	/**********************************************
	 * 1.Prescaler used in equation of baud rate = 0
	 * 2.Status bits = 0 , because ,they are read only
	 **********************************************/
	TWSR =0x00;
	/**********************************************************************************
	 * 1.Select address , Note 7-bit address in the seven most significant bits of TWAR
	 * 2.Disable recognition of the general call address
	 **********************************************************************************/
	TWAR = (TWAR & 0x00) | (Config_Ptr->Address << 1);
}

void MTWI_vStartCondition(void)
{
    /*************************************************************
	 * 1.Clear the TWINT flag before sending the start bit TWINT=1
	 * 2.send the start bit by TWSTA=1
	 * 3.Enable TWI Module TWEN=1
	 *************************************************************/
	TWCR = (1<<TWINT) | (1<<TWEN)  | (1<<TWSTA);

	/* wait for flag set */
    while(BIT_IS_CLEAR(TWCR,TWINT));
}
void MTWI_vStop(void)
{
    /*************************************************************
	 * 1.Clear the TWINT flag before sending the start bit TWINT=1
	 * 2.send the start bit by TWSTO=1
	 * 3.Enable TWI Module TWEN=1
	 *************************************************************/
	TWCR = (1<<TWINT) | (1<<TWEN)  | (1<<TWSTO);
}
void MTWI_vWriteByte(u8 A_u8Data)
{
	/* Move Data to TWDR register*/
	TWDR =A_u8Data;
    /*************************************************************
	 * 1.Clear the TWINT flag before sending the start bit TWINT=1
	 * 2.Enable TWI Module TWEN=1
	 *************************************************************/
	TWCR = (1<<TWINT) | (1<<TWEN);
	/* wait for flag set */
    while(BIT_IS_CLEAR(TWCR,TWINT));
}
u8 MTWI_u8ReadByteWithACK(void)
{
	/*************************************************************
	 * 1.Clear the TWINT flag before reading the data TWINT=1
	 * 2.Enable sending ACK after reading or receiving data TWEA=1
	 * 3.Enable TWI Module TWEN=1
	 **************************************************************/
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
    /* Wait for TWINT flag set in TWCR Register (data received successfully) */
    while(BIT_IS_CLEAR(TWCR,TWINT));
    /* Read Data */
    return TWDR;
}
u8 MTWI_u8ReadByteWithNACK(void)
{
	/*****************************************************
	 * 1.Clear the TWINT flag before reading the data TWINT=1
	 * 2.Enable TWI Module TWEN=1
	 *****************************************************/
    TWCR = (1 << TWINT) | (1 << TWEN);
    /* Wait for TWINT flag set in TWCR Register (data received successfully) */
    while(BIT_IS_CLEAR(TWCR,TWINT));
    /* Read Data */
    return TWDR;
}
u8 MTWI_u8ReadStatus(void)
{
	u8 status;
	/* Get only last 5 bits*/
    status = TWSR & 0xF8;
    return status;
}
