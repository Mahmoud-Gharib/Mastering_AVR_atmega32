
/************ LIB  **********/
#include "../../../00-LIB/STD_TYPES.h"
#include "../../../00-LIB/BIT_MATH.h"
#include "avr/delay.h"

/************ MCAL **********/
#include "../../../03-MCAL/01-DIO/DIO_INTERFACE.h"

/************ HAL **********/
#include "../../../02-HAL/01-LED/LED_INTERFACE.h"
#include "../../../02-HAL/02-DIP_SWITCH/DIP_INTERFACE.h"

void APP_voidTestDIP(void)
{
	if(HDIP_u8GetPressedKey(DIO_u8_PORTB, DIO_u8_PIN3) == 1)
	{
		HLED_voidTurnOn  (DIO_u8_PORTB, DIO_u8_PIN4 );
	}
	else
	{
		HLED_voidTurnOff (DIO_u8_PORTB, DIO_u8_PIN4);
	}
}
