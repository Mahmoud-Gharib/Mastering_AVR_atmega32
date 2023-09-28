#include <avr/interrupt.h>
#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_MATH.h"
#include "TIMER1_CFG.h"
#include "TIMER1.h"
#include "../REG.h"
#include "../01-DIO/DIO.h"

static u32 num_of_ov = 0,num_of_cm = 0;
static total_ticks = 0;
void (*Timer1_CALL_BACK)(void);

void MTIMER1_voidInitTimer1(void)
{
	//
	SET_BIT(TCCR1A,4);
	SET_BIT(TCCR1A,5);
	
	CLR_BIT(TCCR1A,0);
	CLR_BIT(TCCR1A,1);
	//Timer/Counter1, Output Compare B Match Interrupt Enable
	SET_BIT(TIMSK,3);
	//SET GIE
	SET_BIT(SREG,7);
}
void MTIMER1_u32SetTimeTimer1(u32 desired_time)
{
	u32 tick_time = (TIMER1_D_FACTOR/CRYSTAL_FREQ);
	total_ticks = ((desired_time*1000) / tick_time);
	
	#if TIMER_1_MODE  == NORMAL_MODE
	//u32 tick_time = (1/(16000000/1024));
	num_of_ov = total_ticks / 65536;
	if(total_ticks % 65536 != 0)
	{
		TCNT1 = 65536 - (total_ticks % 65536);
		num_of_ov++;
	}
	#elif TIMER_1_MODE  == CTC_MODE
	u8 ocr_value = 65536;
	while((total_ticks % ocr_value) != 0)
	{
		ocr_value--;
	}
	num_of_cm = total_ticks / ocr_value;
	OCR1A_VALUE = ocr_value - 1;
	#endif
}
void MTIMER1_voidStartTimer1(void)
{
		#if TIMER_1_DIVISION_FACTOR      ==     1024
		SET_BIT(TCCR1B,0);
		CLR_BIT(TCCR1B,1);
		SET_BIT(TCCR1B,2);
		#elif TIMER_1_DIVISION_FACTOR      ==     256
		CLR_BIT(TCCR1B,0);
		CLR_BIT(TCCR1B,1);
		SET_BIT(TCCR1B,2);
		#endif
		
}
void MTIMER1_voidStopTimer1(void)
{
	CLR_BIT(TCCR1B,0);
	CLR_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,2);
}
void MTIMER1_Timer1_SET_CALL_BACK(void(*ptr)(void))
{
	Timer1_CALL_BACK = ptr;
}
ISR(TIMER_1_ISR_VECT)
{
	static u32 counter = 0;
	counter++;
	#if TIMER_1_MODE  ==  NORMAL_MODE
	if(counter == num_of_ov)
	{
		Timer0_CALL_BACK();
		counter = 0;
		TCNT1 = 65536 - (total_ticks % 65536);
	}
	#elif TIMER_1_MODE  ==  CTC_MODE
	if(counter == num_of_cm)
	{
		Timer0_CALL_BACK();
		counter = 0;
	}
	#endif
}
void pwm_1_Init(void)
{
	//MDIO_voidSetDirectionPin(PD5,OUTPUT);
	SET_BIT(DDRD,5);
	//TO SELECT FAST PWM MODE WITH ICR1 TOP
	CLR_BIT(TCCR1A,0);
	SET_BIT(TCCR1A,1);
	SET_BIT(TCCR1B,3);
	SET_BIT(TCCR1B,4);
	//TO SELECT NON INVERTED MODE
	CLR_BIT(TCCR1A,6);
	SET_BIT(TCCR1A,7);
	//ICR1_VALUE =312;
}
void pwm_1_SetFreqancy(u16 frequency)
{
	ICR1_VALUE = ((CRYSTAL_FREQ * 1000000)/(TIMER1_D_FACTOR*frequency));
}
void pwm_1_SetDutyCycle(u8 duty_cycle)
{
	OCR1A_VALUE = ((((u32)duty_cycle * ICR1_VALUE)/100) - 1);
}
void pwm_1_Start(void)
{
	//1024_PRESCALER
	SET_BIT(TCCR1A,0);
	CLR_BIT(TCCR1B,1);
	SET_BIT(TCCR1B,2);
}
void pwm_1_Stop(void)
{
		CLR_BIT(TCCR1A,0);
		CLR_BIT(TCCR1B,1);
		CLR_BIT(TCCR1B,2);
}