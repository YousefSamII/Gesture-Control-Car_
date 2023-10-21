/* ===============================================
 * File Name        : _7Segment.h
 *
 * Project Name     : LAB1
 *
 * Created on       : Aug 31, 2023
 *  
 * Author           : Yousef Sami
 * ===============================================*/

#ifndef COTS_HAL__7SEGMENT_H_
#define COTS_HAL__7SEGMENT_H_
#include "../../LIB/STD_TYPES.h"

#define ZERO		0b00111111
#define ONE			0b00000110
#define TWO			0b01011011
#define THREE		0b01001111
#define FOUR 		0b01100110
#define FIVE		0b01101101
#define SIX			0b01111101
#define SEVEN		0b00000111
#define EIGHT		0b01111111
#define NINE		0b01101111

void H7SEG_vDisplayNumber(u8 A_u8PortNumber,u8 A_u8Number);
#endif /* COTS_HAL__7SEGMENT_H_ */
