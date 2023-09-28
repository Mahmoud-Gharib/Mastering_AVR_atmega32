#include <avr/interrupt.h>
#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_MATH.h"
#include "../REG.h"
#include "TIMER0_CFG.h"
#include "TIMER0.h"
#include "../01-DIO/DIO.h"

static u32 num_of_ov = 0,num_of_cm = 0;
u32 total_ticks = 0;
void (*Timer0_CALL_BACK)(void);

void MTIMER0_voidInitTimer0(void)
{
	#if   TIMER_0_MODE  ==  NORMAL_MODE
	CLR_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);
	SET_BIT(TIMSK,0);
	#elif TIMER_0_MODE  ==  CTC_MODE
	SET_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);
	SET_BIT(TIMSK,1);
	#endif
	SET_BIT(SREG,7);
	
}
void MTIMER0_voidStartTimer0(void)
{
	#if TIMER_0_DIVISION_FACTOR      ==     1024
	SET_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	SET_BIT(TCCR0,2);
	#elif TIMER_0_DIVISION_FACTOR      ==     256
	CLR_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	SET_BIT(TCCR0,2);
	#endif
	
}
void MTIMER0_voidStopTimer0(void)
{
	CLR_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);
}
void MTIMER0_u32SetTimeTimer0(u32 desired_time)
{
	u32 tick_time = (TIMER_0_DIVISION_FACTOR/CRYSTAL_FREQ);
	total_ticks = ((desired_time*1000) / tick_time);
	
	#if TIMER_0_MODE  == NORMAL_MODE
	//u32 tick_time = (1/(16000000/1024));
    num_of_ov = total_ticks / 256;
	if(total_ticks % 256 != 0)
	{
		TCNT0 = 256 - (total_ticks % 256);
	    num_of_ov++;
	}
	#elif TIMER_0_MODE  == CTC_MODE
	u8 ocr_value = 255;
	while((total_ticks % ocr_value) != 0)
	{
		ocr_value--;
	}
	num_of_cm = total_ticks / ocr_value;
	OCR0 = ocr_value - 1;
	#endif
}
void MTIMER0_Timer0_SET_CALL_BACK(void(*ptr)(void))
{
	Timer0_CALL_BACK = ptr;
}
ISR(TIMER_0_ISR_VECT)
{
	static u32 counter = 0;
	counter++;
	#if TIMER_0_MODE  ==  NORMAL_MODE
	if(counter == num_of_ov)
	{
		Timer0_CALL_BACK();
		counter = 0;
		TCNT0 = 256 - (total_ticks % 256);
	}
	#elif TIMER_0_MODE  ==  CTC_MODE
	if(counter == num_of_cm)
	{
		Timer0_CALL_BACK();
		counter = 0;
	}
	#endif
}

void pwm_0_Init(void)
{
	MDIO_voidSetDirectionPin(PB3,OUTPUT);
	#if PWM_0_MODE   == FAST_PWM
	SET_BIT(TCCR0,3);
	SET_BIT(TCCR0,6);
		#if COMPARE_OUTPUT_MODE  == NON_INVERTED
		CLR_BIT(TCCR0,4);
		SET_BIT(TCCR0,5);
		#elif COMPARE_OUTPUT_MODE  == INVERTED
		SET_BIT(TCCR0,4);
		SET_BIT(TCCR0,5);
		#endif
	#elif PWM_0_MODE == PHASE_CORRECT_PWM
	CLR_BIT(TCCR0,3);
	SET_BIT(TCCR0,6);
		#if COMPARE_OUTPUT_MODE  == NON_INVERTED
		CLR_BIT(TCCR0,4);
		SET_BIT(TCCR0,5);
		#elif COMPARE_OUTPUT_MODE  == INVERTED
		SET_BIT(TCCR0,4);
		SET_BIT(TCCR0,5);
		#endif
	#endif
	
}
void pwm_0_SetDutyCycle(u8 duty_cycle)
{
	#if PWM_0_MODE   == FAST_PWM
		#if COMPARE_OUTPUT_MODE  == NON_INVERTED
		OCR0 = (((duty_cycle * 256)/100) - 1);
		#elif COMPARE_OUTPUT_MODE  == INVERTED
		OCR0 = (255 - ((duty_cycle * 256)/100));
		#endif
	#elif PWM_0_MODE == PHASE_CORRECT_PWM
		#if COMPARE_OUTPUT_MODE  == NON_INVERTED
		OCR0 = ((duty_cycle * 255 )/100);
		#elif COMPARE_OUTPUT_MODE  == INVERTED
		OCR0 = 255 - ((255*duty_cycle)/100);
		#endif
	#endif
	
	
	
}
void pwm_0_Start(void)
{
	MTIMER0_voidStartTimer0();
}
void pwm_0_Stop(void)
{
	MTIMER0_voidStopTimer0();
}