/* ===============================================
 * File Name        : BIT_Math.h
 *
 * Project Name     : CarRobot_MC1
 *
 * Created on       : Aug 30, 2023
 *
 * Author           : Yousef Sami
 * ===============================================*/

#ifndef COTS_LIB_BIT_MATH_H_
#define COTS_LIB_BIT_MATH_H_

/* Set a certain bit in any register */
#define SET_BIT(REG,BIT_NUM)		(REG = REG | (1<<BIT_NUM))
/* Clear a certain bit in any register */
#define CLEAR_BIT(REG,BIT_NUM)		(REG = REG & (~(1<<BIT_NUM)))
/* Toggle a certain bit in any register */
#define TOGGLE_BIT(REG,BIT_NUM)		(REG = REG ^(1<<BIT_NUM))
/* Rotate right the register value with specific number of rotates */
#define ROR(REG,num)			(REG=  (REG>>num)   |   (  REG<<  (sizeof(REG)*8)-num) )
/* Rotate left the register value with specific number of rotates */
#define ROL(REG,num)			(REG=  (REG<<num)   |   (	REG>> (sizeof(REG)*8)-num) )
/* Check if a specific bit is set in any register and return true if yes */
#define BIT_IS_SET(REG,BIT_NUM)		(REG & (1<<BIT_NUM))
/* Check if a specific bit is cleared in any register and return true if yes */
#define BIT_IS_CLEAR(REG,BIT_NUM)	(! (REG & (1<<BIT_NUM)))

#define GET_BIT(REG,BIT) ( ( REG & (1<<BIT) ) >> BIT )
#endif /* COTS_LIB_BIT_MATH_H_ */
