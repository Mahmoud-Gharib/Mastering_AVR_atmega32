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
	HLCD_voidInit();

	while(1)
	{
		for(int i = 0 ; i <= 3 ; i++)
		{
			for(int j = 0 ; j <= 3 ; j++)
			{
				if (i == j)
				{
					HLCD_voidGoToPosition(i,j);
					HLCD_voidSendData('M');
					_delay_ms(100);
					HLCD_voidClearDisplay();
				}
			}
		}
		for(int i = 3 ; i >= 0 ; i--)
		{
			for(int j = 4 ; j <= 6 ; j++)
			{
				if (i + j == 6)
				{
					HLCD_voidGoToPosition(i,j);
					HLCD_voidSendData('M');
					_delay_ms(100);
					HLCD_voidClearDisplay();
				}
			}
		}

		for(int i = 0 ; i <= 3 ; i++)
		{
			for(int j = 7 ; j <= 9 ; j++)
			{
				if (j - i == 6)
				{
					HLCD_voidGoToPosition(i,j);
					HLCD_voidSendData('M');
					_delay_ms(100);
					HLCD_voidClearDisplay();
				}
			}
		}
		for(int i = 3 ; i >= 0 ; i--)
		{
			for(int j = 10 ; j <= 12 ; j++)
			{
				if ( j + i == 12)
				{
					HLCD_voidGoToPosition(i,j);
					HLCD_voidSendData('M');
					_delay_ms(100);
					HLCD_voidClearDisplay();
				}
			}
		}

		for(int i = 0 ; i <= 3 ; i++)
		{
			for(int j = 13 ; j <= 15 ; j++)
			{
				if (j - i == 12)
				{
					HLCD_voidGoToPosition(i,j);
					HLCD_voidSendData('M');
					_delay_ms(100);
					HLCD_voidClearDisplay();
				}
			}
		}
		for(int i = 3 ; i >= 0 ; i--)
		{
			for(int j = 16 ; j <= 18 ; j++)
			{
				if ( j + i == 18)
				{
					HLCD_voidGoToPosition(i,j);
					HLCD_voidSendData('M');
					_delay_ms(100);
					HLCD_voidClearDisplay();
				}
			}
		}


	}
	return 0;
}

