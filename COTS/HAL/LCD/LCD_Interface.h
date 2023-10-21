/* ===============================================
 * File Name        : LCD_Interface.h
 *
 * Project Name     : CarRobot_MC1
 *
 * Created on       : Aug 31, 2023
 *  
 * Author           : Yousef Sami
 * ===============================================*/
#ifndef COTS_HAL_LCD_LCD_INTERFACE_H_
#define COTS_HAL_LCD_LCD_INTERFACE_H_

/* LCD Commands */
#define LCD_CLEAR_COMMAND                    0x01
#define LCD_GO_TO_HOME                       0x02
#define LCD_TWO_LINES_EIGHT_BITS_MODE        0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE         0x28
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT1   0x33
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT2   0x32
#define LCD_CURSOR_OFF                       0x0C
#define LCD_CURSOR_ON                        0x0E
#define LCD_SET_CURSOR_LOCATION              0x80
#define DISPLAY_ON_OFF						 0x0F
#define ENTRY_MODE_SET  					 0x03
#define SET_CGRAM_ADDRESS					 0x40

void HLCD_vInit(void);
void HLCD_vSendCommand(u8 A_u8Command);
void HLCD_vSendData(u8 A_u8Data);
void HLCD_vSendString(const s8 * A_u8string);
void HLCD_vMoveTo(u8 A_u8Row, u8 A_u8Col);
void HLCD_vDisplayClear(void);
void HLCD_vSaveInCGRAM(void);
#endif /* COTS_HAL_LCD_LCD_INTERFACE_H_ */
