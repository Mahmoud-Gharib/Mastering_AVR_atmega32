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

void MADC_voidInit(void)
{
	ADMUX_REG -> VOLTAGE_REFERENCE = AVCC_PIN ;
	ADMUX_REG -> ADJUST = RIGHT_ADJUST ;
	ADCSRA_REG -> PRESCALER_DIVISION_FACTOR = DIVISION_BY_128;
	ADCSRA_REG -> AutoTrigger = AUTO_TRIGGER_MODE;
	ADCSRA_REG -> Enable = 1;
} 
u16 MADC_u16GetDigitalValue(void)
{
#if     READING   == WITH_INTERRUPT
	return (MADC -> ADC_ADC_VALUE);
#elif   READING   == WITHOUT_INTERRUPT
	while(GET_BIT(MADC -> ADC_ADCSRA,4) == 0);
	return (MADC -> ADC_ADC_VALUE);
#endif
}
void MADC_voidAdcStartConversion(u8 Copy_u8ChannelNum )
{
	ADMUX_REG -> ChannelNum = Copy_u8ChannelNum;
#if   START_CONVERSION == FREE_RUNNING_MODE
	ADCSRA_REG -> StartConversion = 1;
	SFIOR_REG -> Auto_Trigger_Source = FREE_RUNNING_MODE;
#elif START_CONVERSION == AUTO_TRIGGER_MODE
	ADCSRA_REG -> StartConversion = 0;
	SFIOR_REG -> Auto_Trigger_Source = EXTERNAL_INT_0;
#endif
}
void MADC_voidAdcIntEnable(void)
{
	//TO ENABLE GLOBAL INT
	SET_BIT(SREG,7);
	//TO ENABLE ADC_INT
	ADCSRA_REG -> IntEnable = 1;
}
void MADC_voidAdcIntDisable(void)
{
	//TO Disable GLOBAL INT
	CLR_BIT(SREG,7);
	//TO Disable ADC_INT
	ADCSRA_REG -> IntEnable = 0;
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
