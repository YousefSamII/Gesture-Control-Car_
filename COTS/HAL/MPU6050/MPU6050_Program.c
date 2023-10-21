/* ===============================================
 * File Name        : MPU6050_Program.c
 *
 * Project Name     : CarRobot_MC1
 *
 * Created on       : Sep 10, 2023
 *  
 * Author           : Yousef Sami
 * ===============================================*/

#include <stdint.h>
#include <math.h>
#include "../../MCAL/TWI/TWI_Interface.h"

#include "MPU6050_Config.h"
#include "MPU6050_Private.h"
#include "MPU6050_Interface.h"


void HMPU6050_vInit(void)
{
	/*******************************************************
	 * 				I2C Configuration
	 * 				1.use 400k bit rate -- TWB=2
	 * 				2.Choice address number ()
	 *******************************************************/
	TWI_ConfigType twi_configurations={0x02,0x68};
	MTWI_vInit(&twi_configurations);
	// Set clock source to internal oscillator
	MTWI_vStartCondition();
	MTWI_vWriteByte(MPU6050_ADDR << 1);
	MTWI_vWriteByte(MPU6050_REG_PWR_MGMT_1);
	MTWI_vWriteByte(0x00);
	MTWI_vStop();
	// Set gyroscope full-scale range to ±250 degrees per second
	MTWI_vStartCondition();
	MTWI_vWriteByte(MPU6050_ADDR << 1);
	MTWI_vWriteByte(MPU6050_REG_GYRO_CONFIG);
	MTWI_vWriteByte(0x00);
	MTWI_vStop();
	// Set accelerometer full-scale range to ±2g
	MTWI_vStartCondition();
	MTWI_vWriteByte(MPU6050_ADDR << 1);
	MTWI_vWriteByte(MPU6050_REG_ACCEL_CONFIG);
	MTWI_vWriteByte(0x00);
	MTWI_vStop();
}
void HMPU6050_vReadData(s16 * A_u16AccelX ,s16 * A_u16AccelY ,s16 * A_u16AccelZ ,s16 * A_u16GyroX , s16 * A_u16GyroY , s16 * A_u16GyroZ)
{
	// Read accelerometer data
	MTWI_vStartCondition();
	MTWI_vWriteByte(MPU6050_ADDR << 1);
	MTWI_vWriteByte(MPU6050_REG_ACCEL_XOUT_H);
	MTWI_vStartCondition();
	MTWI_vWriteByte((MPU6050_ADDR << 1) | 0x01);
	*A_u16AccelX = ((s16)MTWI_u8ReadByteWithACK() << 8) |MTWI_u8ReadByteWithACK();
	*A_u16AccelY = ((s16)MTWI_u8ReadByteWithACK() << 8) |MTWI_u8ReadByteWithACK();
	*A_u16AccelZ = ((s16)MTWI_u8ReadByteWithACK() << 8) |MTWI_u8ReadByteWithNACK();
	MTWI_vStop();
	// Read gyroscope data
	MTWI_vStartCondition();
	MTWI_vWriteByte(MPU6050_ADDR << 1);
	MTWI_vWriteByte(MPU6050_REG_GYRO_XOUT_H);
	MTWI_vStartCondition();
	MTWI_vWriteByte((MPU6050_ADDR << 1) | 0x01);
	*A_u16GyroX = ((s16)MTWI_u8ReadByteWithACK() << 8) |MTWI_u8ReadByteWithACK();
	*A_u16GyroY = ((s16)MTWI_u8ReadByteWithACK() << 8) |MTWI_u8ReadByteWithACK();
	*A_u16GyroZ = ((s16)MTWI_u8ReadByteWithACK() << 8) |MTWI_u8ReadByteWithNACK();
	MTWI_vStop();
}
