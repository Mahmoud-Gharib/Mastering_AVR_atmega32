/*==================================================================================*
 * File        : ADC.h     														    *
 * Description :This file includes ADC Driver prototypes and macros for Atmega32	*
 * Author      : Mahmoud Gharib Embedded SW Engineer 								*		
 * Date        :																	*		
 * Git account : https://github.com/Mahmoud-Gharib									*		
 * mail        : mahmoudgharib99999@gmail.com 										*		
 *==================================================================================*/
#ifndef ADC_H_
#define ADC_H_
#include "../../00-LIB/STD_TYPES.h"
/*voltage reference macros*/
#define  AVCC_PIN            1
#define  AREF_PIN            2
#define  INTERNAL2V          3
						     
#define RIGHT_ADJUST         0
#define LEFT_ADJUST          1
/*Channel macros*/		     
#define  CHANNEL_0           0
#define  CHANNEL_1           1
#define  CHANNEL_2           2
#define  CHANNEL_3           3
#define  CHANNEL_4           4
#define  CHANNEL_5           5
#define  CHANNEL_6           6
#define  CHANNEL_7           7
/*PRESCALER macro*/		     
#define  DIVISION_BY_2		 2
#define  DIVISION_BY_4		 4
#define  DIVISION_BY_8       8
#define  DIVISION_BY_16      16
#define  DIVISION_BY_32		 32
#define  DIVISION_BY_64		 64
#define  DIVISION_BY_128	 128

#define  AUTO_TRIGGER_MODE         1
#define  SINGLE_CONVERSION_MODE    2
/*Prototypes ADC DRIVERS*/
void MADC_voidInitAdc(void);
u16  MADC_u16ReadAdc(void);
void MADC_voidAdcStartConversion(void);
void MADC_voidAdcIntEnable(void);
void MADC_voidAdcIntDisable(void);
void MADC_Adc_SET_CALL_BACK(void(*)(void));
#endif 

/*
int main(void)
{
	HLCD_voidInitLcd();
	MADC_voidInitAdc();
	while(1)
	{
		HLCD_voidWriteNumber(MADC_u32ReadAdc());
		_delay_ms(100);
		HLCD_voidClearLcd();
	}
}
*/

/*
void ADC_INT_ISRfunction(void);
int main(void)
{
	HLCD_voidInitLcd();
	HLED_voidInitLed(B_LED);
	MADC_voidInitAdc();
	
	MADC_voidAdcIntEnable();
	MADC_voidAdcStartConversion();
	MADC_Adc_SET_CALL_BACK(ADC_INT_ISRfunction);
	
	while(1)
	{
		HLED_voidLedOn(B_LED);
	}
}
void ADC_INT_ISRfunction(void)
{
	HLCD_voidGotoPlace(0,0);
	HLCD_voidWriteString("TEMP : ");
	HLCD_voidGotoPlace(0,7);
	HLCD_voidWriteNumber(MADC_u16ReadAdc());
	HLCD_voidWriteString("       ");
}
*/