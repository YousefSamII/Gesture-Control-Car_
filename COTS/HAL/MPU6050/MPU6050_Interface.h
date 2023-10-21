/* ===============================================
 * File Name        : MPU6050_Interface.h
 *
 * Project Name     : CarRobot_MC1
 *
 * Created on       : Sep 10, 2023
 *  
 * Author           : Yousef Sami
 * ===============================================*/

#ifndef COTS_HAL_MPU6050_MPU6050_INTERFACE_H_
#define COTS_HAL_MPU6050_MPU6050_INTERFACE_H_




// MPU6050 scale factor for converting raw data to degrees per second
#define MPU6050_GYRO_SCALE 131.0

void HMPU6050_vInit(void);
void HMPU6050_vReadData(s16 * A_u16AccelX ,s16 * A_u16AccelY ,s16 * A_u16AccelZ ,s16 * A_u16GyroX , s16 * A_u16GyroY , s16 * A_u16GyroZ);
#endif /* COTS_HAL_MPU6050_MPU6050_INTERFACE_H_ */
