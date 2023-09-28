/*==================================================================================*
 * File        : EXTI_PROGRAM.c														*
 * Description : This file includes EXTI Driver implementations for Atmega32     	*
 * Author      : Mahmoud Gharib Embedded SW Engineer 								*
 * Date        : 																	*
 * Git account : https://github.com/Mahmoud-Gharib									*
 * mail        : mahmoudgharib99999@gmail.com 										*
 *==================================================================================*/

/************ LIB  **********/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/************ MCAL **********/
#include "EXTI_CONFIG.h"
#include "EXTI_PRIVATE.h"
#include "EXTI_INTERFACE.h"

void (*EXT_INT_0_CALL_BACK)(void);
void (*EXT_INT_1_CALL_BACK)(void);
void (*EXT_INT_2_CALL_BACK)(void);

/*============================================================================================================*
 * Prototype   : void MEXTI_voidEXTIEnable(u8 Copy_u8EXTI_Num, u8 Copy_u8EXTI_Sense);	  	   				  *
 * Description : ENABLE EXT INTRRUPT													     				  *
 * Arguments   : EXTI_Num 																					  *
 * 				 EXTI_Sense															 						  *
 * return      : void																					      *
 *============================================================================================================*/
void MEXTI_voidEXTIEnable(u8 Copy_u8EXTI_Num, u8 Copy_u8EXTI_Sense)
{
	SET_BIT(SREG,7);               //TO ENABLE GLOBAL INT
	switch(Copy_u8EXTI_Num)
	{
		case EXT_INT_0:
		SET_BIT(GICR,6);           //TO ENABLE INT0 INT
		switch(Copy_u8EXTI_Sense)
		{
			case FALLING_EDGE:
			CLR_BIT(MCUCR,0);
			SET_BIT(MCUCR,1);
			break;
			case RISING_EDGE:
			SET_BIT(MCUCR,0);
			SET_BIT(MCUCR,1);
			break;
			case LOGICAL_CHANGE:
		    SET_BIT(MCUCR,0);
			CLR_BIT(MCUCR,1);
			break;
			case LOW_LEVEL:
			CLR_BIT(MCUCR,0);
			CLR_BIT(MCUCR,1);
			break;
			default:
			
			break;
		}
		break;
		case EXT_INT_1:
		SET_BIT(GICR,7);           //TO ENABLE INT1 INT
		switch(Copy_u8EXTI_Sense)
		{
			case FALLING_EDGE:
			CLR_BIT(MCUCR,2);
			SET_BIT(MCUCR,3);
			break;
			case RISING_EDGE:
			SET_BIT(MCUCR,2);
			SET_BIT(MCUCR,3);
			break;
			case LOGICAL_CHANGE:
		    SET_BIT(MCUCR,2);
			CLR_BIT(MCUCR,3);
			break;
			case LOW_LEVEL:
			CLR_BIT(MCUCR,2);
			CLR_BIT(MCUCR,3);
			break;
			default:
			
			break;
		}
		break;
		case EXT_INT_2:
		SET_BIT(GICR,5);           //TO ENABLE INT2 INT
		switch(Copy_u8EXTI_Sense)
		{
			case FALLING_EDGE:
			CLR_BIT(MCUCSR,6);
			break;
			case RISING_EDGE:
			SET_BIT(MCUCSR,6);
			break;
			default:
			
			break;
		}   	
	    break;
		default:
			
		break;
	}
}

/*============================================================================================================*
 * Prototype   : void MEXTI_voidEXTIDisable(u8 Copy_u8EXTI_Num);	  	   									  *
 * Description : DISABLE EXT INTRRUPT													     				  *
 * Arguments   : EXTI_Num 																					  *
 * 				 EXTI_Sense															 						  *
 * return      : void																					      *
 *============================================================================================================*/
void MEXTI_voidEXTIDisable(u8 Copy_u8EXTI_Num)
{
	CLR_BIT(SREG,7);               //TO ENABLE GLOBAL INT
	switch(Copy_u8EXTI_Num)
	{
		case EXT_INT_0:
		CLR_BIT(GICR,6);           //TO DISABLE INT0 INT
		break;                          
		case EXT_INT_1:                 
		CLR_BIT(GICR,7);           //TO DISABLE INT1 INT
		break;                          
		case EXT_INT_2:                 
		CLR_BIT(GICR,5);           //TO DISABLE INT2 INT
	    break;
		default:
			
		break;
	}
}


void EXT_INT_0_SET_CALL_BACK(void(*ptr)(void))
{
	EXT_INT_0_CALL_BACK = ptr;
}

void __vector_1(void)     __attribute__((signal));
void __vector_1(void)
{
	EXT_INT_0_CALL_BACK();
}


void EXT_INT_1_SET_CALL_BACK(void(*ptr)(void))
{
	EXT_INT_1_CALL_BACK = ptr;
}

void __vector_2(void)     __attribute__((signal));
void __vector_2(void)
{
	EXT_INT_1_CALL_BACK();
}


void EXT_INT_2_SET_CALL_BACK(void(*ptr)(void))
{
	EXT_INT_2_CALL_BACK = ptr;
}

void __vector_3(void)     __attribute__((signal));
void __vector_3(void)
{
	EXT_INT_2_CALL_BACK();
}
