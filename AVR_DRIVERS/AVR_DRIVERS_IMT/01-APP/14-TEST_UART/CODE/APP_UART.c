
/************ LIB  **********/
#include "../../../00-LIB/STD_TYPES.h"
#include "../../../00-LIB/BIT_MATH.h"
#include "avr/delay.h"

/************ MCAL **********/
#include "../../../03-MCAL/01-DIO/DIO_INTERFACE.h"
#include "../../../03-MCAL/03-ADC/ADC_INTERFACE.h"
#include "../../../03-MCAL/05-UART/UART_INTERFACE.h"

/************ HAL **********/
#include "../../../02-HAL/01-LED/LED_INTERFACE.h"
#include "../../../02-HAL/02-DIP_SWITCH/DIP_INTERFACE.h"
#include "../../../02-HAL/04-LCD/LCD_INTERFACE.h"
#include "../../../02-HAL/05-KEYPAD/KEYPAD_INTERFACE.h"
#include "../../../02-HAL/06-DC_MOTOR/DCMOTOR_INTERFACE.h"
#include "../../../02-HAL/07-STEPPER_MOTOR/STEPPER_INTERFACE.h"
#include "../../../02-HAL/08-LM35_SENSOR/TEMP_INTERFACE.h"
#include "../../../02-HAL/09-LDR_SENSOR/LDR_INTERFACE.h"

void APP_voidTestUARTSend(void)
{
	HKEYPAD_voidInit();
	MUART_voidInit();

	u8 Local_u8Number = 0;

	while(1)
	{
		Local_u8Number = HKEYPAD_u8GetPressedKey() - 48;
		MUART_voidSendData(Local_u8Number);
		_delay_ms(1000);
	}
}
void APP_voidTestUARTRcv(void)
{
	HLCD_voidInit();
	MUART_voidInit();
	u8 Local_u8Number = 0;
	while(1)
	{
		Local_u8Number = MUART_u8RcvData();
		if(Local_u8Number != 0)
		{
			HLCD_voidGoToPosition(0,5);
			HLCD_voidDisplayNumber(Local_u8Number);
			_delay_ms(1000);
		}

		HLCD_voidGoToPosition(0,5);
		HLCD_voidSendString("   ");

	}
}
