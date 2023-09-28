/*======================================================================================*
 * File        : EXT_INT.h     														    *
 * Description : This file includes EXT_INT Driver prototypes and macros for Atmega32	*
 * Author      : Mahmoud Gharib Embedded SW Engineer 								    *
 * Date        :																	    *
 * Git account : https://github.com/Mahmoud-Gharib									    *
 * mail        : mahmoudgharib99999@gmail.com 										    *
 *======================================================================================*/
#ifndef EXT_INT_H_
#define EXT_INT_H_
/*SENSE_CONTROL macros*/
#define FALLING_EDGE    1
#define RISING_EDGE     2
#define LOGICAL_CHANGE  3
#define LOW_LEVEL       4
/*Prototypes EXT_INT0 DRIVERS*/
void EXT_INT_0_INIT(void);
void EXT_INT_0_SET_CALL_BACK(void(*)(void));

#endif
/*
int main(void)
{
	EXT_INT_0_INIT();
	HLED_voidInitLed(B_LED);
	
	while (1)
	{
		HLED_voidLedOff(B_LED);
		_delay_ms(1000);
	}
}

ISR(INT0_vect)
{
	HLED_voidLedOn(B_LED);
}
*/
/*
void EXT_INT_0_ISRfunction(void);
int main(void)
{
	EXT_INT_0_INIT();
	HLED_voidInitLed(B_LED);
	EXT_INT_0_SET_CALL_BACK(EXT_INT_0_ISRfunction);
	while (1)
	{
		//HLED_voidLedOff(B_LED);
		//_delay_ms(1000);
	}
}

void EXT_INT_0_ISRfunction(void)
{
	HLED_voidLedTog(B_LED);
}
*/