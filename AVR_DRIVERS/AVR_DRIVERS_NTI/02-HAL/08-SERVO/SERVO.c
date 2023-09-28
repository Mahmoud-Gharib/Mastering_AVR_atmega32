/*
 * SERVO.c
 *
 * Created: 2/23/2022 10:53:04 AM
 *  Author: aaa
 */ 

#include "../../00-LIB/BIT_MATH.h"
#include "../../00-LIB/STD_TYPES.h"
#include "SERVO_CFG.h"
#include "SERVO.h"
#include "../../03-MCAL/REG.h"
void SERVO_INIT(u16 angle)
{
	SET_BIT(TCCR1A,1);
	CLR_BIT(TCCR1A,0);
	SET_BIT(TCCR1B,4);
	SET_BIT(TCCR1B,3);

	SET_BIT(TCCR1A,7);
	CLR_BIT(TCCR1A,6);

	ICR1_VALUE = 19999;

	OCR1A_VALUE = angle;

	CLR_BIT(TCCR1B,2);
	SET_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,0);
}


