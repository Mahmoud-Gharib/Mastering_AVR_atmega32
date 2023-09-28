
/************ LIB  **********/
#include "../../../00-LIB/STD_TYPES.h"
#include "../../../00-LIB/BIT_MATH.h"
#include "avr/delay.h"

/************ MCAL **********/
#include "../../../03-MCAL/01-DIO/DIO_INTERFACE.h"

/************ HAL **********/
#include "../../../02-HAL/01-LED/LED_INTERFACE.h"
#include "../../../02-HAL/02-DIP_SWITCH/DIP_INTERFACE.h"

u8 GLOBAL_u8Number = 0;
void APP_voidTestSSD(void)
{
	HSSD_voidDisplayNumber(DIO_u8_PORTA,GLOBAL_u8Number);
	GLOBAL_u8Number++;
	_delay_ms(1000);
	if(GLOBAL_u8Number > 9)
	{
		GLOBAL_u8Number = 0;
	}

}
