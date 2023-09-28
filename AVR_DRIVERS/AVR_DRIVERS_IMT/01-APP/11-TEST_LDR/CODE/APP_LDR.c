
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
#include "../../../02-HAL/08-LM35_SENSOR/TEMP_INTERFACE.h"
#include "../../../02-HAL/09-LDR_SENSOR/LDR_INTERFACE.h"

void APP_voidTestLDR(void)
{
	HLCD_voidInit();
	HLDR_voidInit();


	while(1)
	{
		HLCD_voidGoToPosition(1,1);
		HLCD_voidDisplayNumber(HTEMP_u16GetAnalogLDRValue(CHANNEL_1));

	}
}
