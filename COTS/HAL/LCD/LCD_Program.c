/* ===============================================
 * File Name        : LCD_Program.c
 *
 * Project Name     : CarRobot_MC1
 *
 * Created on       : Aug 31, 2023
 *  
 * Author           : Yousef Sami
 * ===============================================*/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_Math.h"
#include <util/delay.h>
/* MCAL */
#include "../../MCAL/DIO/DIO.Interface.h"
/* Component */
#include "LCD_Interface.h"
#include "LCD_Config.h"
#include "LCD_Private.h"


void HLCD_vInit(void){
	/* Output  */
	MDIO_vSetPinDirection(LCD_RS_PORT_ID,LCD_RS_PIN_ID,OUTPUT);
	MDIO_vSetPinDirection(LCD_E_PORT_ID,LCD_E_PIN_ID,OUTPUT);
	/* Wait for powering > 15 */
	_delay_ms(20);
#if(LCD_DATA_BITS_MODE == 4)
	/* Data port pins as output pins */
	MDIO_vSetPinDirection(DATA_PORT,LCD_DB4_PIN_ID,OUTPUT);
	MDIO_vSetPinDirection(DATA_PORT,LCD_DB5_PIN_ID,OUTPUT);
	MDIO_vSetPinDirection(DATA_PORT,LCD_DB6_PIN_ID,OUTPUT);
	MDIO_vSetPinDirection(DATA_PORT,LCD_DB7_PIN_ID,OUTPUT);
	/* Send for 4-bit initialization of LCD */
	HLCD_vSendCommand(LCD_TWO_LINES_FOUR_BITS_MODE_INIT1);
	HLCD_vSendCommand(LCD_TWO_LINES_FOUR_BITS_MODE_INIT2);
	/* use 2-lines LCD + 4-bits Data Mode + 5*7 dot display Mode */
	HLCD_vSendCommand(LCD_TWO_LINES_FOUR_BITS_MODE);
#elif(LCD_DATA_BITS_MODE == 8)
	/* Data port as output port*/
	MDIO_vSetPortDirection(DATA_PORT,255);
	/* use 2-lines LCD + 8-bits Data Mode + 5*7 dot display Mode */
	HLCD_vSendCommand(LCD_TWO_LINES_EIGHT_BITS_MODE);

#endif
	HLCD_vSendCommand(LCD_CLEAR_COMMAND);
	HLCD_vSendCommand(LCD_CURSOR_OFF);
	HLCD_vSendCommand(ENTRY_MODE_SET);
}

void HLCD_vSendCommand(u8 A_u8Command){
	/* RS = 0 (command mode) */
	MDIO_vWritePin(LCD_RS_PORT_ID,LCD_RS_PIN_ID,LOW);
	_delay_ms(1);		/* delay for processing Tas = 50ns */
	/* EN ==> High */
	MDIO_vWritePin(LCD_E_PORT_ID,LCD_E_PIN_ID,HIGH);
	_delay_ms(1);		/* delay for processing Tpw - Tdws = 190ns */
#if(LCD_DATA_BITS_MODE == 4)
	MDIO_vWritePin(DATA_PORT,LCD_DB4_PIN_ID,GET_BIT(A_u8Command,4));
	MDIO_vWritePin(DATA_PORT,LCD_DB5_PIN_ID,GET_BIT(A_u8Command,5));
	MDIO_vWritePin(DATA_PORT,LCD_DB6_PIN_ID,GET_BIT(A_u8Command,6));
	MDIO_vWritePin(DATA_PORT,LCD_DB7_PIN_ID,GET_BIT(A_u8Command,7));
	_delay_ms(1);	/* delay for processing Tdsw = 100ns */
	/* EN ==> Low */
	MDIO_vSetPinValue(LCD_E_PORT_ID,LCD_E_PIN_ID,LOW);
	_delay_ms(1); /* delay for processing Th = 13ns */
	/* EN ==> High */
	MDIO_vSetPinValue(LCD_E_PORT_ID,LCD_E_PIN_ID,HIGH);
	_delay_ms(1);  /* delay for processing Th = 13ns */
#elif(LCD_DATA_BITS_MODE == 8)
	/* Send command on data port */
	MDIO_vWritePort(DATA_PORT,A_u8Command);
	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	MDIO_vWritePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOW);
	_delay_ms(1); /* delay for processing Th = 13ns */
#endif

}

void HLCD_vSendData(u8 A_u8Data){
	/* RS = 1 (command mode) */
	MDIO_vWritePin(LCD_RS_PORT_ID,LCD_RS_PIN_ID,HIGH);
	_delay_ms(1);		/* delay for processing Tas = 50ns */
	/* EN ==> High */
	MDIO_vWritePin(LCD_E_PORT_ID,LCD_E_PIN_ID,HIGH);
	_delay_ms(1);		/* delay for processing Tpw - Tdws = 190ns */
#if(LCD_DATA_BITS_MODE == 4)
	MDIO_vWritePin(DATA_PORT,LCD_DB4_PIN_ID,GET_BIT(A_u8Data,4));
	MDIO_vWritePin(DATA_PORT,LCD_DB5_PIN_ID,GET_BIT(A_u8Data,5));
	MDIO_vWritePin(DATA_PORT,LCD_DB6_PIN_ID,GET_BIT(A_u8Data,6));
	MDIO_vWritePin(DATA_PORT,LCD_DB7_PIN_ID,GET_BIT(A_u8Data,7));
	_delay_ms(1);	/* delay for processing Tdsw = 100ns */
	/* EN ==> Low */
	MDIO_vSetPinValue(LCD_E_PORT_ID,LCD_E_PIN_ID,LOW);
	_delay_ms(1); /* delay for processing Th = 13ns */
	/* EN ==> High */
	MDIO_vSetPinValue(LCD_E_PORT_ID,LCD_E_PIN_ID,HIGH);
	_delay_ms(1);  /* delay for processing Th = 13ns */
#elif(LCD_DATA_BITS_MODE == 8)
	/* Send command on data port */
	MDIO_vWritePort(DATA_PORT,A_u8Data);
	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	MDIO_vWritePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOW);
	_delay_ms(1); /* delay for processing Th = 13ns */
#endif
}
void HLCD_vSendString(const s8 * A_u8string){
	u8 local_u8Index;
	for (local_u8Index = 0;A_u8string[local_u8Index]!='\0'; local_u8Index++){
		HLCD_vSendData(A_u8string[local_u8Index]);
	}
}
void HLCD_vMoveTo(u8 A_u8Row, u8 A_u8Col){
	u8 local_u8LcdMemorAddress;
	switch(A_u8Row){
	case 0: local_u8LcdMemorAddress = A_u8Col      ;break;
	case 1: local_u8LcdMemorAddress = A_u8Col+0x40 ;break;
	case 3: local_u8LcdMemorAddress = A_u8Col+0x10 ;break;
	case 4: local_u8LcdMemorAddress = A_u8Col+0x50 ;break;
	}
	HLCD_vSendCommand(local_u8LcdMemorAddress | LCD_SET_CURSOR_LOCATION) ;
}
void HLCD_vDisplayClear(void){
	HLCD_vSendCommand(LCD_CLEAR_COMMAND);
}
s32 HLCD_s32ReverseInt(s32 A_s32Number){
	s32 rev = 1;
	while (A_s32Number != 0){
		rev = rev*10 + A_s32Number%10;
		A_s32Number/=10;
	}
	return rev;
}
/* HLCD_vSendIntNumber(5454); */
void HLCD_vSendIntNumber(s32 A_s32Number){
	if (A_s32Number == 0){
		HLCD_vSendData('0');
		return;
	}
	if (A_s32Number < 0){
		HLCD_vSendData('-');
		A_s32Number *= -1;
	}
	s32 tmp = HLCD_s32ReverseInt(A_s32Number);
	while (tmp != 1){
		HLCD_vSendData(tmp%10 + '0');
		tmp/=10;
	}
}
void HLCD_vSaveInCGRAM(void)
{
	/* Send Command for save in CGRAM */
	HLCD_vSendCommand(SET_CGRAM_ADDRESS);

	/* Send first Saved character in CGRAM in first empty address 0x00
	 * and auto increment with add another characters
	 * and get first 3 bits 000 from SET_CGRAM_ADDRESS 0b01000000
	 *  */
	HLCD_vSendData(0b00000);
	HLCD_vSendData(0b00000);
	HLCD_vSendData(0b00000);
	HLCD_vSendData(0b00001);
	HLCD_vSendData(0b00010);
	HLCD_vSendData(0b00100);
	HLCD_vSendData(0b01000);
	HLCD_vSendData(0b10000);


	HLCD_vSendData(0b00000);
	HLCD_vSendData(0b00000);
	HLCD_vSendData(0b00000);
	HLCD_vSendData(0b10000);
	HLCD_vSendData(0b01000);
	HLCD_vSendData(0b00100);
	HLCD_vSendData(0b00010);
	HLCD_vSendData(0b00001);

	HLCD_vSendData(0b00000);
	HLCD_vSendData(0b00000);
	HLCD_vSendData(0b10101);
	HLCD_vSendData(0b10101);
	HLCD_vSendData(0b11111);
	HLCD_vSendData(0b00000);
	HLCD_vSendData(0b00000);
	HLCD_vSendData(0b00000);


	HLCD_vSendData(0b00010);
	HLCD_vSendData(0b00000);
	HLCD_vSendData(0b00111);
	HLCD_vSendData(0b10101);
	HLCD_vSendData(0b10111);
	HLCD_vSendData(0b11111);
	HLCD_vSendData(0b00000);
	HLCD_vSendData(0b00000);

}
