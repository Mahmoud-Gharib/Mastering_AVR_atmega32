
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

void APP_voidTestLCD(void)
{
	HLCD_voidInit();
	while(1)
	{
		HLCD_voidGoToPosition(1,1);
		HLCD_voidSendData('A');
		_delay_ms(1000);
		HLCD_voidClearDisplay();
		HLCD_voidGoToPosition(1,1);
		HLCD_voidSendString("GHARIB");
		_delay_ms(1000);
		HLCD_voidClearDisplay();
		HLCD_voidGoToPosition(1,1);
		HLCD_voidDisplayNumber(55);
		_delay_ms(1000);
		HLCD_voidClearDisplay();
	}
}
