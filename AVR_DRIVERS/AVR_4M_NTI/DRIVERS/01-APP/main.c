#include "../00-LIB/STD_TYPES.h"
#include "../00-LIB/BIT_MATH.h"
#include "avr/delay.h"
/**************  APP  ********************/

#include "../03-MCAL/01-DIO/DIO_INTERFACE.h"
#include "../02-HAL/01-LED/LED_INTERFACE.h"
#include "../02-HAL/02-DIP_SWITCH/DIP_INTERFACE.h"
#include "../02-HAL/03-SSD/SSD_INTERFACE.h"

#define APP      	2

#if APP      ==   	1
int main (void)
{
	HSWITCH_voidInit();
	HLED_voidInit();

	while(1)
	{
		if(HDIP_u8GetPressedKey(SWITCH_1_t) == 1)
		{
			HLED_voidTurnOn(LED_GREEN_t);
			HLED_voidTurnOn(LED_BLUE_t);
			HLED_voidTurnOn(LED_YELLOW_t);
			HLED_voidTurnOn(LED_RED_t);
		}
		else
		{
			HLED_voidTurnOff(LED_GREEN_t);
			HLED_voidTurnOff(LED_BLUE_t);
			HLED_voidTurnOff(LED_YELLOW_t);
			HLED_voidTurnOff(LED_RED_t);
		}
	}
	return 0;
}
#elif   APP   ==		2
int main (void)
{
	HSWITCH_voidInit();
	HLED_voidInit();
	HLED_voidTurnOn(LED_GREEN_t);
	HLED_voidTurnOn(LED_BLUE_t);
	HLED_voidTurnOn(LED_YELLOW_t);
	HLED_voidTurnOn(LED_RED_t);
	HSSD_voidInitSSD();

	while(1)
	{

		HSSD_voidCountDownSSD(9999);
		if(HDIP_u8GetPressedKey(SWITCH_1_t) == 1)
		{
			HLED_voidTurnOn(LED_GREEN_t);
			HLED_voidTurnOn(LED_BLUE_t);
			HLED_voidTurnOn(LED_YELLOW_t);
			HLED_voidTurnOn(LED_RED_t);
		}
		else
		{
			HLED_voidTurnOff(LED_GREEN_t);
			HLED_voidTurnOff(LED_BLUE_t);
			HLED_voidTurnOff(LED_YELLOW_t);
			HLED_voidTurnOff(LED_RED_t);
		}
	}
	return 0;
}
#endif
