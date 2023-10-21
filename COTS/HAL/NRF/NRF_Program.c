/* ===============================================
 * File Name        : NRF_Program.c
 *
 * Project Name     : CarRobot_MC1
 *
 * Created on       : Sep 9, 2023
 *
 * Author           : Yousef Sami
 * ===============================================*/
#include "../../LIB/BIT_Math.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO.Interface.h"
#include "../../MCAL/SPI/SPI_Interface.h"

#include <util/delay.h>

#include "NRF_Config.h"
#include "NRF_Private.h"
#include "NRF_Interface.h"

static u8 rx_address[5] = { 0xe7, 0xe7, 0xe7, 0xe7, 0xe7 };	/* Read pipe address */
static u8 tx_address[5] = { 0xe7, 0xe7, 0xe7, 0xe7, 0xe7 };	/* Write pipe address */

void HNRF_vCSN_Select(void)
{
	MDIO_vWritePin(CSN_PORT ,CSN_PIN ,LOW);
}
void HNRF_vCSN_UnSelect(void)
{
	MDIO_vWritePin(CSN_PORT ,CSN_PIN ,HIGH);
}
void HNRF_vCE_Enable(void)
{
	MDIO_vWritePin(CE_PORT ,CE_PIN ,HIGH);
}
void HNRF_vCE_Disable(void)
{
	MDIO_vWritePin(CE_PORT ,CE_PIN ,LOW);
}
u8 HNRF_u8SendSpi(u8 A_u8RegAddress , void *A_u8Data ,u32 A_u32Bytes)
{
	u8 i,local_u8Status;
	HNRF_vCSN_Select();
	local_u8Status = SPI_sendReceiveByte(A_u8RegAddress);
	for(i=0 ; i<A_u32Bytes ;i++)
	{
		(((u8*)A_u8Data)[i]) = SPI_sendReceiveByte(((u8*)A_u8Data)[i]);
	}
	HNRF_vCSN_UnSelect();
	return local_u8Status;
}
u8 HNRF_u8WriteReg(u8 A_u8RegAddress , void *A_u8Data ,u32 A_u32Bytes)
{
	return HNRF_u8SendSpi((W_REGISTER |A_u8RegAddress) ,A_u8Data , A_u32Bytes);
}
u8 HNRF_u8ReadReg(u8 A_u8RegAddress , void *A_u8Data ,u32 A_u32Bytes)
{
	return HNRF_u8SendSpi((R_REGISTER |A_u8RegAddress) ,A_u8Data , A_u32Bytes);

}
void HNRF_vInit(void)
{
	u8 check,data;
	MDIO_vSetPinDirection(CE_PORT ,CE_PIN ,OUTPUT);
	MDIO_vSetPinDirection(CSN_PORT ,CSN_PIN ,OUTPUT);
	/* Unselect for Chip before configuration */
	HNRF_vCSN_UnSelect();
	HNRF_vCE_Disable();
	/* init SPI*/
	SPI_initMaster();
	_delay_ms(100);
	data =
			(!(RX_INTERRUPT) << MASK_RX_DR) |	/* IRQ interrupt on RX (0 = enabled) */
			(!(TX_INTERRUPT) << MASK_TX_DS) |	/* IRQ interrupt on TX (0 = enabled) */
			(!(RT_INTERRUPT) << MASK_MAX_RT) |	/* IRQ interrupt on auto retransmit counter overflow (0 = enabled) */
			(1 << EN_CRC) |						/* CRC enable */
			(1 << CRC0) |						/* CRC scheme 2 bytes */
			(1 << PWR_UP) |						/* Power up  */
			(1 << PRIM_RX);
	HNRF_u8WriteReg(CONFIG,&data,1);
	HNRF_u8ReadReg(CONFIG,&check,1);

	data =
			(AUTO_ACK << ENAA_P5) |
			(AUTO_ACK << ENAA_P4) |
			(AUTO_ACK << ENAA_P3) |
			(AUTO_ACK << ENAA_P2) |
			(AUTO_ACK << ENAA_P1) |
			(AUTO_ACK << ENAA_P0);

	HNRF_u8WriteReg(EN_AA,&data,1);
	HNRF_u8ReadReg(EN_AA,&check,1);

	data = 0xF0;		/* Delay 4000us with 1 retry */

	HNRF_u8WriteReg(SETUP_RETR,&data,1);
	HNRF_u8ReadReg(SETUP_RETR,&check,1);

	/* Disable RX addresses */
	data = 0;

	HNRF_u8WriteReg(EN_RXADDR,&data,1);
	HNRF_u8ReadReg(EN_RXADDR,&check,1);



	/* Set channel */
	data = CHANNEL;

	HNRF_u8WriteReg(RF_CH,&data,1);
	HNRF_u8ReadReg(RF_CH,&check,1);

	data =
				(CONTINUOUS << CONT_WAVE) |					/* Continuous carrier transmit */
				((DATARATE >> RF_DR_HIGH) << RF_DR_HIGH) |	/* Data rate */
				((POWER >> RF_PWR) << RF_PWR);				/* PA level */


	HNRF_u8WriteReg(RF_SETUP,&data,1);
	HNRF_u8ReadReg(RF_SETUP,&check,1);



		/* Status Clear */
		data =
				(1 << RX_DR) |
				(1 << TX_DS) |
				(1 << MAX_RT);


		HNRF_u8WriteReg(STATUS,&data,1);
		HNRF_u8ReadReg(STATUS,&check,1);

		/* Dynamic payload on all pipes */
		data =
				(DYN_PAYLOAD << DPL_P0) |
				(DYN_PAYLOAD << DPL_P1) |
				(DYN_PAYLOAD << DPL_P2) |
				(DYN_PAYLOAD << DPL_P3) |
				(DYN_PAYLOAD << DPL_P4) |
				(DYN_PAYLOAD << DPL_P5);


		HNRF_u8WriteReg(DYNPD,&data,1);
		HNRF_u8ReadReg(DYNPD,&check,1);

		HNRF_u8SendSpi(ACTIVATE,0,0);
		HNRF_u8SendSpi(POSTACTIVATE,0,0);
		/* Enable dynamic payload */
		data =
				(DYN_PAYLOAD << EN_DPL) |
				(AUTO_ACK << EN_ACK_PAY) |
				(!AUTO_ACK << EN_DYN_ACK);


		HNRF_u8WriteReg(FEATURE,&data,1);
		HNRF_u8ReadReg(FEATURE,&check,1);

		/* flush tx,rx */
		HNRF_u8WriteReg(FLUSH_RX,0,0);
		HNRF_u8WriteReg(FLUSH_TX,0,0);


		/* open pipes */
		HNRF_u8WriteReg(RX_ADDR_P0 + READ_PIPE,rx_address,5);
		HNRF_u8WriteReg(TX_ADDR,tx_address,5);
		HNRF_u8WriteReg(EN_RXADDR,&data,1);
		/* Enable Pipe */
		data = (1 << READ_PIPE);


		HNRF_u8WriteReg(EN_RXADDR,&data,1);
		HNRF_u8ReadReg(EN_RXADDR,&check,1);
}
void HNRF_vState(u8 A_u8State)
{
	u8 config_register,data;
	HNRF_u8ReadReg(CONFIG,&config_register,1);
		switch (A_u8State)
		{
		case POWERUP:
			data = config_register | (1 << PWR_UP);
			HNRF_u8WriteReg(CONFIG,&data,1);
			_delay_ms(2);
			break;
		case POWERDOWN:
			data = config_register & ~(1 << PWR_UP);
			HNRF_u8WriteReg(CONFIG,&data,1);
			break;
		case RECEIVE:
			data = config_register | (1 << PRIM_RX);
			HNRF_u8WriteReg(CONFIG,&data,1);
			data = (1 << RX_DR) | (1 << TX_DS) | (1 << MAX_RT);
			HNRF_u8WriteReg(STATUS,&data,1);
			break;
		case TRANSMIT:
			data = config_register & ~(1 << PRIM_RX);
			HNRF_u8WriteReg(CONFIG,&data,1);
			break;
		case STANDBY1:
			HNRF_vCE_Disable();
			break;
		case STANDBY2:
			data = config_register & ~(1 << PRIM_RX);
			HNRF_u8WriteReg(CONFIG,&data,1);
			MDIO_vSetPinDirection(CE_PORT,CE_PIN,HIGH);
			_delay_us(150);
			break;
		}
}
void HNRF_vStartListening(void)
{
	HNRF_vState(RECEIVE);				/* Receive mode */
	HNRF_vCE_Enable();
	_delay_us(150);
}
u8 HNRF_vAvailable(void)
{
	u8 config_register;
	HNRF_u8ReadReg(FIFO_STATUS,&config_register,1);
	if (!(config_register & (1 << RX_EMPTY))) return 1;
	return 0;
}
void HNRF_vWriteAck(void)
{
	const void *ack = "A";
	u8 length = 1;
	HNRF_vCSN_Select();
	SPI_sendReceiveByte(W_ACK_PAYLOAD);
	while (length--) SPI_sendReceiveByte(*(uint8_t *)ack++);
	HNRF_vCSN_UnSelect();
}
u8 HNRF_u8SendMessage(const void *tx_message,u8 length)
{
	HNRF_vState(TRANSMIT);

	HNRF_u8WriteReg(FLUSH_RX,0,0);
	HNRF_u8WriteReg(FLUSH_TX,0,0);
	u8 data = (1 << TX_DS);
	HNRF_u8WriteReg(STATUS,&data,1);

	/* Disable interrupt on RX */
	HNRF_u8ReadReg(CONFIG,&data,1);
	data |= (1 << MASK_RX_DR);
	HNRF_u8WriteReg(CONFIG,&data,1);

	HNRF_vCSN_Select();
	if (AUTO_ACK) SPI_sendReceiveByte(W_TX_PAYLOAD);
	else SPI_sendReceiveByte(W_TX_PAYLOAD_NOACK);

	while (length--) SPI_sendReceiveByte(*(uint8_t *)tx_message++);
	SPI_sendReceiveByte(0);
	HNRF_vCSN_UnSelect();

	HNRF_vCE_Enable();
	_delay_us(15);
	HNRF_vCE_Disable();
	HNRF_u8ReadReg(STATUS,&data,1);

	while(!(data & (1 << TX_DS))) HNRF_u8ReadReg(STATUS,&data,1);

	HNRF_u8ReadReg(CONFIG,&data,1);
	data &= ~(1 << MASK_RX_DR);
	HNRF_u8WriteReg(CONFIG,&data,1);


	return 1;
}
const char * NRF_vReadMessage(void)
{
	static char rx_message[32];
	for(u8 i=0;i<32;i++)rx_message[i]=0;
	if (AUTO_ACK) HNRF_vWriteAck();

	u8 data;
	HNRF_u8ReadReg(R_RX_PL_WID,&data,1);
	if (data > 0) HNRF_u8SendSpi(R_RX_PAYLOAD,&rx_message,data+1);

	u8 strlen=0;
	for(u8 i=0;rx_message[i]!=0;i++)
		strlen++;
	if (strlen > 0)
	{
		// Clear RX interrupt
		data = (1 << RX_DR);
		HNRF_u8WriteReg(STATUS,&data,1);


		return rx_message;
	}
	data = (1 << RX_DR);
	HNRF_u8WriteReg(STATUS,&data,1);

	return "failed";

}

