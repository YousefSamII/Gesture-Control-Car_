/* ===============================================
 * File Name        : NRF_Interface.h
 *
 * Project Name     : CarRobot_MC1
 *
 * Created on       : Sep 9, 2023
 *
 * Author           : Yousef Sami
 * ===============================================*/

#ifndef COTS_HAL_NRF_NRF_INTERFACE_H_
#define COTS_HAL_NRF_NRF_INTERFACE_H_

void HNRF_vCSN_Select(void);
void HNRF_vCSN_UnSelect(void);
void HNRF_vCE_Disnable(void);
void HNRF_vCE_Disable(void);
u8 HNRF_u8SendSpi(u8 A_u8RegAddress , void *A_u8Data ,u32 A_u32Bytes);
u8 HNRF_u8WriteReg(u8 A_u8RegAddress , void *A_u8Data ,u32 A_u32Bytes);
u8 HNRF_u8ReadReg(u8 A_u8RegAddress , void *A_u8Data ,u32 A_u32Bytes);
void HNRF_vInit(void);
void HNRF_vState(u8 A_u8State);
void HNRF_vStartListening(void);
u8 HNRF_vAvailable(void);
void HNRF_vWriteAck(void);
u8 HNRF_u8SendMessage(const void *tx_message,u8 length);
const char * NRF_vReadMessage(void);





#endif /* COTS_HAL_NRF_NRF_INTERFACE_H_ */
