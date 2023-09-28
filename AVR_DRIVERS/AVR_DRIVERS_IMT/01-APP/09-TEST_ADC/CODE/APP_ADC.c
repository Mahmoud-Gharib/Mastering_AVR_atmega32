
/************ LIB  **********/
#include "../../../00-LIB/STD_TYPES.h"
#include "../../../00-LIB/BIT_MATH.h"
#include "avr/delay.h"

/************ MCAL **********/
#include "../../../03-MCAL/01-DIO/DIO_INTERFACE.h"
#include "../../../03-MCAL/03-ADC/ADC_INTERFACE.h"

/************ HAL **********/
#include "../../../02-HAL/01-LED/LED_INTERFACE.h"
#include "../../../02-HAL/02-DIP_SWITCH/DIP_INTERFACE.h"
#include "../../../02-HAL/04-LCD/LCD_INTERFACE.h"
#include "../../../02-HAL/05-KEYPAD/KEYPAD_INTERFACE.h"
#include "../../../02-HAL/06-DC_MOTOR/DCMOTOR_INTERFACE.h"
#include "../../../02-HAL/07-STEPPER_MOTOR/STEPPER_INTERFACE.h"
/*
void APP_voidTestADC(void)
{
	HLCD_voidInit();
	MADC_voidInit();


	while(1)
	{
		MADC_voidAdcStartConversion(CHANNEL_0);
		HLCD_voidGoToPosition(1,1);
		HLCD_voidDisplayNumber(MADC_u16GetDigitalValue());
		HLCD_voidSendData("       ");
	}
}
*/
void ADC_INT_ISRfunction(void);

void APP_voidTestADC(void)
{
	HLCD_voidInit();
	MADC_voidInit();

	MADC_voidAdcIntEnable();
	MADC_Adc_SET_CALL_BACK(ADC_INT_ISRfunction);

	while(1)
	{
		MADC_voidAdcStartConversion(CHANNEL_0);
	}
}
void ADC_INT_ISRfunction(void)
{
	HLCD_voidGoToPosition(1,1);
	HLCD_voidDisplayNumber(MADC_u16GetDigitalValue());
	HLCD_voidSendData("       ");
}

