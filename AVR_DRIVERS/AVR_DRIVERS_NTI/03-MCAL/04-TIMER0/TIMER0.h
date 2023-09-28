#ifndef TIMER0_H_
#define TIMER0_H_

#include "../../00-LIB/STD_TYPES.h"

void MTIMER0_voidInitTimer0(void);
void MTIMER0_u32SetTimeTimer0(u32);
void MTIMER0_voidStartTimer0(void);
void MTIMER0_voidStopTimer0(void);
void MTIMER0_Timer0_SET_CALL_BACK(void(*ptr)(void));

void pwm_0_Init(void);
void pwm_0_SetDutyCycle(u8);
void pwm_0_Start(void);
void pwm_0_Stop(void);

#define  NORMAL_MODE    1
#define  CTC_MODE       2

#define FAST_PWM            3
#define PHASE_CORRECT_PWM   4
#define NON_INVERTED        5
#define INVERTED            6
 
 
#endif 

/*
void TIMER0_ISRfunction(void);

int main(void)
{
	HLED_voidInitLed(B_LED);
	MTIMER0_Timer0_SET_CALL_BACK(TIMER0_ISRfunction);
	MTIMER0_voidInitTimer0();
	MTIMER0_u32SetTimeTimer0(1000);
	MTIMER0_voidStartTimer0();
	while(1)
	{
		
	}
	
}
void TIMER0_ISRfunction(void)
{
	HLED_voidLedTog(B_LED);
}

*/