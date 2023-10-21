/* ===============================================
 * File Name        : MPU6050_Private.h
 *
 * Project Name     : CarRobot_MC1
 *
 * Created on       : Sep 10, 2023
 *
 * Author           : Yousef Sami
 * ===============================================*/

#ifndef COTS_HAL_MPU6050_MPU6050_PRIVATE_H_
#define COTS_HAL_MPU6050_MPU6050_PRIVATE_H_

#define MPU6050_ADDR 0x68 // MPU6050 I2C address

// MPU6050 register addresses
#define MPU6050_REG_PWR_MGMT_1 0x6B
#define MPU6050_REG_GYRO_CONFIG 0x1B
#define MPU6050_REG_ACCEL_CONFIG 0x1C
#define MPU6050_REG_ACCEL_XOUT_H 0x3B
#define MPU6050_REG_TEMP_OUT_H 0x41
#define MPU6050_REG_GYRO_XOUT_H 0x43

#endif /* COTS_HAL_MPU6050_MPU6050_PRIVATE_H_ */
