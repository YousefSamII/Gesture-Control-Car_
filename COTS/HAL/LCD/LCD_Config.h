/* ===============================================
 * File Name        : LCD_Config.h
 *
 * Project Name     : CarRobot_MC1
 *
 * Created on       : Aug 31, 2023
 *  
 * Author           : Yousef Sami
 * ===============================================*/
#ifndef COTS_HAL_LCD_LCD_CONFIG_H_
#define COTS_HAL_LCD_LCD_CONFIG_H_

#define LCD_DATA_BITS_MODE		8

#if((LCD_DATA_BITS_MODE != 4) && (LCD_DATA_BITS_MODE != 8))

#error "Data bits should be 4 or 8 only"

#endif

#define DATA_PORT 			PORT_A

#if(LCD_DATA_BITS_MODE == 4)

#define LCD_DB4_PIN_ID                 PIN3
#define LCD_DB5_PIN_ID                 PIN4
#define LCD_DB6_PIN_ID                 PIN5
#define LCD_DB7_PIN_ID                 PIN6

#endif


#define LCD_E_PORT_ID		PORT_C
#define LCD_E_PIN_ID		PIN1

#define LCD_RS_PORT_ID		PORT_C
#define LCD_RS_PIN_ID		PIN0

#endif /* COTS_HAL_LCD_LCD_CONFIG_H_ */
