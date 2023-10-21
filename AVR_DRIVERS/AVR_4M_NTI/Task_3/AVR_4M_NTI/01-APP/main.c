#include "../00-LIB/STD_TYPES.h"
#include "../00-LIB/BIT_MATH.h"
#include "avr/delay.h"
/**************  APP  ********************/

#include "../03-MCAL/01-DIO/DIO_INTERFACE.h"
#include "../02-HAL/01-LED/LED_INTERFACE.h"
#include "../02-HAL/02-DIP_SWITCH/DIP_INTERFACE.h"
#include "../02-HAL/03-SSD/SSD_INTERFACE.h"
#include "../02-HAL/04-LCD/LCD_INTERFACE.h"


int main (void)
{
	HSSD_voidInitSSD();
	while(1)
	{
		for(u8 Counter1 = 99 , Counter2 = 0 ; Counter2 <= 99 || Counter1 >= 0 ; Counter2++ ,Counter1--)
		{
			for(u8 Local_u8Counter = 0 ; Local_u8Counter < 5 ; Local_u8Counter++)
			{
				u8 Local_u8Number4= (Counter1 / 10) % 10;
				u8 Local_u8Number3= Counter1 % 10;
				u8 Local_u8Number2= (Counter2 / 10) % 10;
				u8 Local_u8Number1=  Counter2 % 10;

				HSSD_voidDisplayDigitSSD(Local_u8Number4,THOUSANDS_T);
				_delay_ms(1);
				HSSD_voidDisplayDigitSSD(Local_u8Number3,HUNDREDS_T);
				_delay_ms(1);
				HSSD_voidDisplayDigitSSD(Local_u8Number2,TENS_T);
				_delay_ms(1);
				HSSD_voidDisplayDigitSSD(Local_u8Number1,ONES_T);
				_delay_ms(1);
			}
			MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN6, DIO_u8_LOW);
			MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN5, DIO_u8_LOW);
			MDIO_voidSetPinValue(DIO_u8_PORTA ,DIO_u8_PIN2, DIO_u8_LOW);
			MDIO_voidSetPinValue(DIO_u8_PORTA ,DIO_u8_PIN3, DIO_u8_LOW);
			_delay_ms(100);

		}
	}

	return 0;
}

