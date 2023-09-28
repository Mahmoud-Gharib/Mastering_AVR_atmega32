#ifndef TIMER1_H_
#define TIMER1_H_

#include "../../00-LIB/STD_TYPES.h"

void MTIMER1_voidInitTimer1(void);
void MTIMER1_u32SetTimeTimer1(u32);
void MTIMER1_voidStartTimer1(void);
void MTIMER1_voidStopTimer1(void);
void MTIMER1_Timer1_SET_CALL_BACK(void(*ptr)(void));


void pwm_1_Init(void);
void pwm_1_SetDutyCycle(u8);
void pwm_1_SetFreqancy(u16);
void pwm_1_Start(void);
void pwm_1_Stop(void);



#endif 