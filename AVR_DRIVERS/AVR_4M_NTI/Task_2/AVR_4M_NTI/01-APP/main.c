#include "../00-LIB/STD_TYPES.h"
#include "../00-LIB/BIT_MATH.h"
#include "avr/delay.h"
/**************  APP  ********************/

#include "../03-MCAL/01-DIO/DIO_INTERFACE.h"
#include "../02-HAL/01-LED/LED_INTERFACE.h"
#include "../02-HAL/02-DIP_SWITCH/DIP_INTERFACE.h"
#include "../02-HAL/03-SSD/SSD_INTERFACE.h"
#include "../02-HAL/04-LCD/LCD_INTERFACE.h"


void Traffic_Light(void);
void Count(void);
int main (void)
{
	Traffic_Light();
	return 0;
}

void Traffic_Light(void)
{
	HSSD_voidInitSSD();
	HLED_voidInit();

	while(1)
	{
		Count();
	}
}
void Count(void)
{
	for(u16 Local_u16Counter = 10 ; Local_u16Counter >= 0 ; Local_u16Counter--)
	{
		HSSD_voidDisplaySSD(Local_u16Counter);
		HLED_voidTurnOn(LED_RED_t);
		_delay_ms(100);
		if(Local_u16Counter == 0)
			break;
	}
	HLED_voidTurnOff(LED_RED_t);

	for(u16 Local_u16Counter = 5 ; Local_u16Counter >= 0 ; Local_u16Counter--)
	{
		HSSD_voidDisplaySSD(Local_u16Counter);
		HLED_voidTurnOn(LED_YELLOW_t);
		_delay_ms(100);
		if(Local_u16Counter == 0)
			break;
	}
	HLED_voidTurnOff(LED_YELLOW_t);

	for(u16 Local_u16Counter = 15 ; Local_u16Counter >= 0 ; Local_u16Counter--)
	{
		HSSD_voidDisplaySSD(Local_u16Counter);
		HLED_voidTurnOn(LED_GREEN_t);
		_delay_ms(100);
		if(Local_u16Counter == 0)
			break;
	}
	HLED_voidTurnOff(LED_GREEN_t);
}

