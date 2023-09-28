/*==================================================================================*
 * File        : EXT_INT.c															*
 * Description : This file includes EXT_INT Driver implementations for Atmega32     *
 * Author      : Mahmoud Gharib Embedded SW Engineer 								*		
 * Date        : 1/2/2022															*		
 * Git account : https://github.com/Mahmoud-Gharib									*		
 * mail        : mahmoudgharib99999@gmail.com 										*		
 *==================================================================================*/
#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_MATH.h"
#include "../REG.h"
#include "../../03-MCAL/01-DIO/DIO.h"
#include <avr/interrupt.h>
#include "EXT_INT_CFG.h"
#include "EXT_INT.h"

void (*EXT_INT_0_CALL_BACK)(void);
/*==============================================================================*
 * Prototype   : void EXT_INT_0_INIT(void);						     			*
 * Description : Set initialization of EXT_INT_0								*
 * Arguments   : void			 												*
 * return      : void															*
 *==============================================================================*/
void EXT_INT_0_INIT(void)
{
	//MDIO_voidSetDirectionPin(PB7,OUTPUT);
	//MDIO_voidSetLevelPin(PB7,LOW);
	#if (SENSE_CONTROL  ==  FALLING_EDGE)
	CLR_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);
	#elif (SENSE_CONTROL  ==  RISING_EDGE)
	SET_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);
	#elif (SENSE_CONTROL  ==  LOGICAL_CHANGE)
	SET_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);
	#elif (SENSE_CONTROL  ==  LOW_LEVEL)
	CLR_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);
	#endif
	//TO ENABLE GLOBAL INT
	SET_BIT(SREG,7);
	//TO ENABLE INT0 INT
	SET_BIT(GICR,6);
}

void EXT_INT_0_SET_CALL_BACK(void(*ptr)(void))
{
	EXT_INT_0_CALL_BACK = ptr;
}

ISR(INT0_vect)
{
	EXT_INT_0_CALL_BACK();
}