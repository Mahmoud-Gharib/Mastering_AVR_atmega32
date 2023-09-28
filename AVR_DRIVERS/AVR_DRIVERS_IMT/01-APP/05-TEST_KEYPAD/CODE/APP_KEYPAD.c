
/************ LIB  **********/
#include "../../../00-LIB/STD_TYPES.h"
#include "../../../00-LIB/BIT_MATH.h"
#include "avr/delay.h"

/************ MCAL **********/
#include "../../../03-MCAL/01-DIO/DIO_INTERFACE.h"

/************ HAL **********/
#include "../../../02-HAL/01-LED/LED_INTERFACE.h"
#include "../../../02-HAL/02-DIP_SWITCH/DIP_INTERFACE.h"
#include "../../../02-HAL/04-LCD/LCD_INTERFACE.h"
#include "../../../02-HAL/05-KEYPAD/KEYPAD_INTERFACE.h"


void APP_voidTestKEYPAD(void)
{
	HLCD_voidInit();
	HKEYPAD_voidInit();
	u8 Local_u8Number = 0;
	while(1)
	{
		Local_u8Number = HKEYPAD_u8GetPressedKey();
		if(Local_u8Number != 0)
		{
		HLCD_voidGoToPosition(1,1);
		HLCD_voidDisplayNumber(Local_u8Number - 48);
		}

	}
}
