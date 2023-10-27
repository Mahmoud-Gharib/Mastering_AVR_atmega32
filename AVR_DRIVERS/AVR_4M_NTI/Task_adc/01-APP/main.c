#include "../00-LIB/STD_TYPES.h"
#include "../00-LIB/BIT_MATH.h"
#include "avr/delay.h"
/**************  APP_ADC_ADC_ADC_ADC_ADC_ADC_ADC_ADC_ADC_ADC  ********************/

#include "../03-MCAL/01-DIO/DIO_INTERFACE.h"
#include "../03-MCAL/02-EXT_INT/EXTI_INTERFACE.h"
#include "../03-MCAL/03-ADC/ADC_INTERFACE.h"

#include "../02-HAL/01-LED/LED_INTERFACE.h"
#include "../02-HAL/02-DIP_SWITCH/DIP_INTERFACE.h"
#include "../02-HAL/03-SSD/SSD_INTERFACE.h"
#include "../02-HAL/04-LCD/LCD_INTERFACE.h"
#include "../02-HAL/05-KEYPAD/KEYPAD_INTERFACE.h"

#define APP_ADC      	-1

#if APP_ADC      ==   	1
int main (void)
{
	HSWITCH_voidInit();
	HLED_voidInit();

	while(1)
	{
		if(HDIP_u8GetPressedKey(SWITCH_1_t) == 1)
		{
			HLED_voidTurnOn(LED_GREEN_t);
			HLED_voidTurnOn(LED_BLUE_t);
			HLED_voidTurnOn(LED_YELLOW_t);
			HLED_voidTurnOn(LED_RED_t);
		}
		else
		{
			HLED_voidTurnOff(LED_GREEN_t);
			HLED_voidTurnOff(LED_BLUE_t);
			HLED_voidTurnOff(LED_YELLOW_t);
			HLED_voidTurnOff(LED_RED_t);
		}
	}
	return 0;
}
#elif   APP_ADC   ==		2
int main (void)
{
	HSWITCH_voidInit();
	HLED_voidInit();
	HLED_voidTurnOn(LED_GREEN_t);
	HLED_voidTurnOn(LED_BLUE_t);
	HLED_voidTurnOn(LED_YELLOW_t);
	HLED_voidTurnOn(LED_RED_t);
	HSSD_voidInitSSD();

	while(1)
	{

		HSSD_voidCountDownSSD(9999);
		if(HDIP_u8GetPressedKey(SWITCH_1_t) == 1)
		{
			HLED_voidTurnOn(LED_GREEN_t);
			HLED_voidTurnOn(LED_BLUE_t);
			HLED_voidTurnOn(LED_YELLOW_t);
			HLED_voidTurnOn(LED_RED_t);
		}
		else
		{
			HLED_voidTurnOff(LED_GREEN_t);
			HLED_voidTurnOff(LED_BLUE_t);
			HLED_voidTurnOff(LED_YELLOW_t);
			HLED_voidTurnOff(LED_RED_t);
		}
	}
	return 0;
}
#elif   APP_ADC   ==		3
int main (void)
{
	HLCD_voidInit();
	HKEYPAD_voidInit();

	u8 value = 0;
	while(1)
	{
		value = HKEYPAD_u8GetPressedKey();
		if(value != 0xFF)
		{
			if(value == 7)
			{
				HLCD_voidGoToPosition(0,0);
				HLCD_voidSendString("Mahmoud");
			}
			else if(value == 8)
			{
				HLCD_voidGoToPosition(1,0);
				HLCD_voidSendString("Mustafa");
			}
			else if(value == 9)
			{
				HLCD_voidGoToPosition(2,0);
				HLCD_voidSendString("Gharib");
			}

		}
		else
		{

		}
	}
	return 0;
}

#elif   APP_ADC   ==		4

u8 flag = 0;
#define  GIFR      (*((volatile u8*)0x5A))
void TOG(void);
int main (void)
{
	HLED_voidInit();
	MDIO_voidSetPinDirection(DIO_u8_PORTD , DIO_u8_PIN3 ,DIO_u8_INPUT);
	MEXTI_voidEXTIEnable(EXT_INT_1 , FALLING_EDGE);
	//EXT_INT_1_SET_CALL_BACK(TOG);
	while(1)
	{
		if(GET_BIT(GIFR,7) == 1)
		{
			if(flag == 0)
			{
				HLED_voidTurnOn(LED_RED_t);
				HLED_voidTurnOn(LED_GREEN_t);
				HLED_voidTurnOn(LED_BLUE_t);
				HLED_voidTurnOn(LED_YELLOW_t);
				flag++;
			}
			else if(flag == 1)
			{
				HLED_voidTurnOff(LED_RED_t);
				HLED_voidTurnOff(LED_GREEN_t);
				HLED_voidTurnOff(LED_BLUE_t);
				HLED_voidTurnOff(LED_YELLOW_t);
				flag--;
			}
		}
		SET_BIT(GIFR,7);

	}
	return 0;
}



void TOG(void)
{

	if(flag == 0)
	{
		HLED_voidTurnOn(LED_RED_t);
		HLED_voidTurnOn(LED_GREEN_t);
		HLED_voidTurnOn(LED_BLUE_t);
		HLED_voidTurnOn(LED_YELLOW_t);
		flag++;
	}
	else if(flag == 1)
	{
		HLED_voidTurnOff(LED_RED_t);
		HLED_voidTurnOff(LED_GREEN_t);
		HLED_voidTurnOff(LED_BLUE_t);
		HLED_voidTurnOff(LED_YELLOW_t);		flag--;
	}
}

#elif   APP_ADC   ==		5

int main (void)
{
	MADC_voidInit();

	HLED_voidInit();
	HLCD_voidInit();

	while(1)
	{
		MADC_voidAdcStartConversion(CHANNEL_1);
		HLCD_voidGoToPosition(0,0);
		HLCD_voidDisplayNumber(((MADC_u16GetDigitalValue()*500UL)/1023));
		HLCD_voidSendString("         ");
	}
	return 0;
}
#elif   APP_ADC  ==		6

volatile u8 flag = 0;
void Int(void)
{
	MADC_voidAdcStartConversion(CHANNEL_1);
	flag = 1;
}

int main (void)
{
	MADC_voidInit();
	HLED_voidInit();
	HLCD_voidInit();
	MADC_voidAdcIntEnable();
	MADC_Adc_SET_CALL_BACK(Int);
	MADC_voidAdcStartConversion(CHANNEL_1);

	while(1)
	{
		if (flag == 1)
		{
			HLCD_voidGoToPosition(0,0);
			HLCD_voidDisplayNumber(((MADC_u16GetDigitalValue()*500UL)/1023));
			HLCD_voidSendData("         ");
			flag = 0;
		}
		HLED_voidTurnOn(LED_GREEN_t);
		HLED_voidTurnOn(LED_BLUE_t);
		HLED_voidTurnOn(LED_YELLOW_t);
		HLED_voidTurnOn(LED_RED_t);
		_delay_ms(1000);
		HLED_voidTurnOff(LED_GREEN_t);
		HLED_voidTurnOff(LED_BLUE_t);
		HLED_voidTurnOff(LED_YELLOW_t);
		HLED_voidTurnOff(LED_RED_t);
		_delay_ms(1000);

	}
	return 0;
}
#elif   APP_ADC   ==		7

void External_Int(void);
void Adc_Int(void);

int main (void)
{
	MADC_voidInit();
	MADC_voidAdcIntEnable();
	MADC_voidAdcStartConversion(CHANNEL_1);
	MADC_Adc_SET_CALL_BACK(Adc_Int);

	MEXTI_voidEXTIEnable(EXT_INT_0, RISING_EDGE);
	EXT_INT_0_SET_CALL_BACK(External_Int);

	HLED_voidInit();
	HLCD_voidInit();

	while(1)
	{
		HLED_voidTurnOn(LED_GREEN_t);
		HLED_voidTurnOn(LED_BLUE_t);
		HLED_voidTurnOn(LED_YELLOW_t);
		HLED_voidTurnOn(LED_RED_t);
		_delay_ms(1000);
		HLED_voidTurnOff(LED_GREEN_t);
		HLED_voidTurnOff(LED_BLUE_t);
		HLED_voidTurnOff(LED_YELLOW_t);
		HLED_voidTurnOff(LED_RED_t);
		_delay_ms(1000);
	}
	return 0;
}

void External_Int(void)
{

}

void Adc_Int(void)
{
	HLCD_voidGoToPosition(0,0);
	HLCD_voidDisplayNumber(((MADC_u16GetDigitalValue()*500UL)/1023));
	HLCD_voidSendData("         ");
}
#endif



#define APP_TIMER       1

#if   APP_TIMER   ==		1



int main (void)
{


	while(1)
	{

	}
	return 0;
}


#endif
