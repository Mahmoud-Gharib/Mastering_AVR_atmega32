/*==================================================================================*
 * File        : ADC_PROGRAM.c														*
 * Description : This file includes ADC Driver implementations for Atmega32 		*
 * Author      : Mahmoud Gharib Embedded SW Engineer 								*
 * Date        : 																	*
 * Git account : https://github.com/Mahmoud-Gharib									*
 * mail        : mahmoudgharib99999@gmail.com 										*
 *==================================================================================*/

/************ LIB  **********/
#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_MATH.h"
#include <util/delay.h>

/************ MCAL **********/
#include "ADC_CONFIG.h"
#include "ADC_PRIVATE.h"
#include "ADC_INTERFACE.h"

void (*Adc_Int_CALL_BACK)(void);

/*==============================================================================*
 * Prototype   : void MADC_voidInit(void);										*
 * Description : Set initialization of ADC										*
 * Arguments   : void			 												*
 * return      : void															*
 *==============================================================================*/
void MADC_voidInit(void)
{
	#if VOLTAGE_REFERENCE    ==   AVCC_PIN
		CLR_BIT(ADMUX,7);
		SET_BIT(ADMUX,6);
	#elif VOLTAGE_REFERENCE  ==   AREF_PIN
		CLR_BIT(ADMUX,7);
		CLR_BIT(ADMUX,6);
	#elif VOLTAGE_REFERENCE  ==   INTERNAL2V
		SET_BIT(ADMUX,7);
		SET_BIT(ADMUX,6);
	#endif
	
	#if ADJUST   == RIGHT_ADJUST
		CLR_BIT(ADMUX,5);
	#elif ADJUST == LEFT_ADJUST
		SET_BIT(ADMUX,5);
	#endif
	
	#if PRESCALER_DIVISION_FACTOR == DIVISION_BY_2
		SET_BIT(ADCSRA,0);
		CLR_BIT(ADCSRA,1);
		CLR_BIT(ADCSRA,2);
	#elif PRESCALER_DIVISION_FACTOR == DIVISION_BY_4
		CLR_BIT(ADCSRA,0);
		SET_BIT(ADCSRA,1);
		CLR_BIT(ADCSRA,2);
	#elif PRESCALER_DIVISION_FACTOR == DIVISION_BY_8
		SET_BIT(ADCSRA,0);
		SET_BIT(ADCSRA,1);
		CLR_BIT(ADCSRA,2);
	#elif PRESCALER_DIVISION_FACTOR == DIVISION_BY_16
		CLR_BIT(ADCSRA,0);
		CLR_BIT(ADCSRA,1);
		SET_BIT(ADCSRA,2);
	#elif PRESCALER_DIVISION_FACTOR == DIVISION_BY_32
		SET_BIT(ADCSRA,0);
		CLR_BIT(ADCSRA,1);
		SET_BIT(ADCSRA,2);
	#elif PRESCALER_DIVISION_FACTOR == DIVISION_BY_64
		CLR_BIT(ADCSRA,0);
		SET_BIT(ADCSRA,1);
		SET_BIT(ADCSRA,2);
	#elif PRESCALER_DIVISION_FACTOR == DIVISION_BY_128
		SET_BIT(ADCSRA,0);
		SET_BIT(ADCSRA,1);
		SET_BIT(ADCSRA,2);
	#endif
	
	#if MODE_SELECTION  ==  AUTO_TRIGGER_MODE
		SET_BIT(ADCSRA,5);
	#elif MODE_SELECTION  ==  SINGLE_CONVERSION_MODE
		CLR_BIT(ADCSRA,5);
	#endif
	//ENABLE ADC
	SET_BIT(ADCSRA,7);
} 

/*==============================================================================*
 * Prototype   : u16 MADC_u16GetDigitalValue(void);								*
 * Description : Read value of ADC												*
 * Arguments   : void			 												*
 * return      : ADC Value														*
 *==============================================================================*/
u16 MADC_u16GetDigitalValue(void)
{
	while(GET_BIT(ADCSRA,4) == 0);
	return ADC_VALUE;
}

/*==============================================================================*
 * Prototype   : void MADC_voidAdcStartConversion(u8 Copy_u8ChannelNum );		*
 * Description : Start Conversion Process										*
 * Arguments   : CHANNEL			 											*
 * return      : void															*
 *==============================================================================*/
void MADC_voidAdcStartConversion(u8 Copy_u8ChannelNum )
{
	if (Copy_u8ChannelNum == CHANNEL_0)
	{
		CLR_BIT(ADMUX,4);
		CLR_BIT(ADMUX,3);
		CLR_BIT(ADMUX,2);
		CLR_BIT(ADMUX,1);
		CLR_BIT(ADMUX,0);
	}
	else if (Copy_u8ChannelNum == CHANNEL_1)
	{
		CLR_BIT(ADMUX,4);
		CLR_BIT(ADMUX,3);
		CLR_BIT(ADMUX,2);
		CLR_BIT(ADMUX,1);
		SET_BIT(ADMUX,0);
	}
	else if (Copy_u8ChannelNum == CHANNEL_2)

	{
		CLR_BIT(ADMUX,4);
		CLR_BIT(ADMUX,3);
		CLR_BIT(ADMUX,2);
		SET_BIT(ADMUX,1);
		CLR_BIT(ADMUX,0);
	}
	else if( Copy_u8ChannelNum == CHANNEL_3)
	{
		CLR_BIT(ADMUX,4);
		CLR_BIT(ADMUX,3);
		CLR_BIT(ADMUX,2);
		SET_BIT(ADMUX,1);
		SET_BIT(ADMUX,0);
	}
	else if (Copy_u8ChannelNum == CHANNEL_4)
	{
		CLR_BIT(ADMUX,4);
		CLR_BIT(ADMUX,3);
		SET_BIT(ADMUX,2);
		CLR_BIT(ADMUX,1);
		CLR_BIT(ADMUX,0);
	}
	else if (Copy_u8ChannelNum == CHANNEL_5)
	{
		CLR_BIT(ADMUX,4);
		CLR_BIT(ADMUX,3);
		SET_BIT(ADMUX,2);
		CLR_BIT(ADMUX,1);
		SET_BIT(ADMUX,0);
	}
	else if (Copy_u8ChannelNum == CHANNEL_6)
	{
		CLR_BIT(ADMUX,4);
		CLR_BIT(ADMUX,3);
		SET_BIT(ADMUX,2);
		SET_BIT(ADMUX,1);
		CLR_BIT(ADMUX,0);
	}
	else if (Copy_u8ChannelNum == CHANNEL_7)
	{
		CLR_BIT(ADMUX,4);
		CLR_BIT(ADMUX,3);
		SET_BIT(ADMUX,2);
		SET_BIT(ADMUX,1);
		SET_BIT(ADMUX,0);
	}
	SET_BIT(ADCSRA,6);
}

/*==============================================================================*
 * Prototype   : void MADC_voidAdcIntEnable(void);								*
 * Description : ENABLE INT OF ADC												*
 * Arguments   : void				 											*
 * return      : void															*
 *==============================================================================*/
void MADC_voidAdcIntEnable(void)
{
	//TO ENABLE GLOBAL INT
	SET_BIT(SREG,7);
	//TO ENABLE ADC_INT
	SET_BIT(ADCSRA,3);
}

/*==============================================================================*
 * Prototype   : void MADC_voidAdcIntDisable(void);								*
 * Description : DISABLE INT OF ADC												*
 * Arguments   : void				 											*
 * return      : void															*
 *==============================================================================*/
void MADC_voidAdcIntDisable(void)
{
	//TO Disable GLOBAL INT
	CLR_BIT(SREG,7);
	//TO Disable ADC_INT
	CLR_BIT(ADCSRA,3);     
}

void MADC_Adc_SET_CALL_BACK(void(*ptr)(void))
{
	Adc_Int_CALL_BACK = ptr;
}

/* Prototype for ADC ISR */
void __vector_16(void)     __attribute__((signal));
void __vector_16(void)
{
	Adc_Int_CALL_BACK();
}
