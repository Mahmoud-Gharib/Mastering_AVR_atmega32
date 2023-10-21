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
	HLED_voidInit();
	while(1)
	{
		HSSD_voidDisplaySSD(0);
		HLED_voidTurnOff(LED_RED_t);
		HLED_voidTurnOff(LED_GREEN_t);
		HLED_voidTurnOff(LED_BLUE_t);
		HLED_voidTurnOff(LED_YELLOW_t);
		_delay_ms(500);

		HSSD_voidDisplaySSD(1);
		HLED_voidTurnOn(LED_RED_t);
		HLED_voidTurnOff(LED_GREEN_t);
		HLED_voidTurnOff(LED_BLUE_t);
		HLED_voidTurnOff(LED_YELLOW_t);
		_delay_ms(500);

		HSSD_voidDisplaySSD(2);
		HLED_voidTurnOff(LED_RED_t);
		HLED_voidTurnOn(LED_GREEN_t);
		HLED_voidTurnOff(LED_BLUE_t);
		HLED_voidTurnOff(LED_YELLOW_t);
		_delay_ms(500);

		HSSD_voidDisplaySSD(3);
		HLED_voidTurnOn(LED_RED_t);
		HLED_voidTurnOn(LED_GREEN_t);
		HLED_voidTurnOff(LED_BLUE_t);
		HLED_voidTurnOff(LED_YELLOW_t);
		_delay_ms(500);

		HSSD_voidDisplaySSD(4);
		HLED_voidTurnOff(LED_RED_t);
		HLED_voidTurnOff(LED_GREEN_t);
		HLED_voidTurnOn(LED_BLUE_t);
		HLED_voidTurnOff(LED_YELLOW_t);
		_delay_ms(500);

		HSSD_voidDisplaySSD(5);
		HLED_voidTurnOn(LED_RED_t);
		HLED_voidTurnOff(LED_GREEN_t);
		HLED_voidTurnOn(LED_BLUE_t);
		HLED_voidTurnOff(LED_YELLOW_t);
		_delay_ms(500);

		HSSD_voidDisplaySSD(6);
		HLED_voidTurnOff(LED_RED_t);
		HLED_voidTurnOn(LED_GREEN_t);
		HLED_voidTurnOn(LED_BLUE_t);
		HLED_voidTurnOff(LED_YELLOW_t);
		_delay_ms(500);

		HSSD_voidDisplaySSD(7);
		HLED_voidTurnOn(LED_RED_t);
		HLED_voidTurnOn(LED_GREEN_t);
		HLED_voidTurnOn(LED_BLUE_t);
		HLED_voidTurnOff(LED_YELLOW_t);
		_delay_ms(500);

		HSSD_voidDisplaySSD(8);
		HLED_voidTurnOff(LED_RED_t);
		HLED_voidTurnOff(LED_GREEN_t);
		HLED_voidTurnOff(LED_BLUE_t);
		HLED_voidTurnOn(LED_YELLOW_t);
		_delay_ms(500);

		HSSD_voidDisplaySSD(9);
		HLED_voidTurnOn(LED_RED_t);
		HLED_voidTurnOff(LED_GREEN_t);
		HLED_voidTurnOff(LED_BLUE_t);
		HLED_voidTurnOn(LED_YELLOW_t);
		_delay_ms(500);

		HSSD_voidDisplaySSD(10);
		HLED_voidTurnOff(LED_RED_t);
		HLED_voidTurnOn(LED_GREEN_t);
		HLED_voidTurnOff(LED_BLUE_t);
		HLED_voidTurnOn(LED_YELLOW_t);
		_delay_ms(500);

		HSSD_voidDisplaySSD(11);
		HLED_voidTurnOn(LED_RED_t);
		HLED_voidTurnOn(LED_GREEN_t);
		HLED_voidTurnOff(LED_BLUE_t);
		HLED_voidTurnOn(LED_YELLOW_t);
		_delay_ms(500);

		HSSD_voidDisplaySSD(12);
		HLED_voidTurnOff(LED_RED_t);
		HLED_voidTurnOff(LED_GREEN_t);
		HLED_voidTurnOn(LED_BLUE_t);
		HLED_voidTurnOn(LED_YELLOW_t);
		_delay_ms(500);

		HSSD_voidDisplaySSD(13);
		HLED_voidTurnOn(LED_RED_t);
		HLED_voidTurnOff(LED_GREEN_t);
		HLED_voidTurnOn(LED_BLUE_t);
		HLED_voidTurnOn(LED_YELLOW_t);
		_delay_ms(500);

		HSSD_voidDisplaySSD(14);
		HLED_voidTurnOff(LED_RED_t);
		HLED_voidTurnOn(LED_GREEN_t);
		HLED_voidTurnOn(LED_BLUE_t);
		HLED_voidTurnOn(LED_YELLOW_t);
		_delay_ms(500);

		HSSD_voidDisplaySSD(15);
		HLED_voidTurnOn(LED_RED_t);
		HLED_voidTurnOn(LED_GREEN_t);
		HLED_voidTurnOn(LED_BLUE_t);
		HLED_voidTurnOn(LED_YELLOW_t);
		_delay_ms(500);
	}
	return 0;
}
