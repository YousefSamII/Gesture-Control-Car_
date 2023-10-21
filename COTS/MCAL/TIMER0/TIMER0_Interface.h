/* ===============================================
 * File Name        : TIMER0_Interface.h
 *
 * Project Name     : CarRobot_MC1
 *
 * Created on       : Sep 9, 2023
 *  
 * Author           : Yousef Sami
 * ===============================================*/

#ifndef COTS_MCAL_TIMER0_TIMER0_INTERFACE_H_
#define COTS_MCAL_TIMER0_TIMER0_INTERFACE_H_
/************************************************************
 * 					Definitions
 ***********************************************************/
typedef enum{
 No_Clk , N_1 , N_8 ,N_64 ,N_256 , N_1024 ,Extrenla_Falling , Extrenal_Rising
}Config_Prescaler;

typedef enum{
	PWM_Normal ,Timer_Reserved , Non_Inverting ,Inverting
}Config_Mode_Fast_PWM;

typedef enum{
	Timer_Normal , PWM_Phase ,CTC , PWM_Fast
}Config_Timer_Mode;

typedef struct{
	Config_Timer_Mode Config_Mode;
	Config_Mode_Fast_PWM PWM_Mode;
	Config_Prescaler Config_Prescaler;
}ConfigTimer0;

/*
 * Description :
 * 	Initialization for timer0 and select mode of operation and it's prescaler
 */
void MTIMER0_vInit(const ConfigTimer0 * Confige_Ptr );
/*
 * Description :
 * 	Generate Waveform from timer 0 on OCR0 pin with frequency 488.28HZ
 */
void MTIMER0_vStartPWM(u8 A_u8DutyCycle);


#endif /* COTS_MCAL_TIMER0_TIMER0_INTERFACE_H_ */
