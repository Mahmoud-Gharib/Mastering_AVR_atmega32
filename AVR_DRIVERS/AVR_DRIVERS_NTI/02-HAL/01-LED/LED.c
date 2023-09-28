/*==================================================================================*
 * File        : LED.c																*
 * Description : This file includes LED Driver implementations				     	*
 * Author      : Mahmoud Gharib Embedded SW Engineer 								*		
 * Date        : 																	*
 * Git account : https://github.com/Mahmoud-Gharib									*		
 * mail        : mahmoudgharib99999@gmail.com 										*		
 *==================================================================================*/
#include "LED.h"
#include "../../03-MCAL/01-DIO/DIO.h"
#include "LED_CFG.h"


/*==============================================================================*
 * Prototype   : void HLED_voidInitLed(u8 Copy_u8Led);							*
 * Description : Set initialization direction of Leds							*
 * Arguments   : void															*
 * return      : void															*
 *==============================================================================*/
void HLED_voidInitLed(void)
{
	MDIO_voidSetDirectionPin(LED_1,OUTPUT);
	MDIO_voidSetDirectionPin(LED_2,OUTPUT);
	MDIO_voidSetDirectionPin(LED_3,OUTPUT);
	MDIO_voidSetDirectionPin(LED_4,OUTPUT);
}
/*==============================================================================*
 * Prototype   : void HLED_voidLedState(u8 Copy_u8Value);						*
 * Description : turn on and off Leds											*
 * Arguments   : Value															*
 * return      : void															*
 *==============================================================================*/
void HLED_voidLedState(u8 Copy_u8Value)
{
	if(Copy_u8Value <= 25)
	{
		MDIO_voidSetLevelPin(LED_1,HIGH);
		MDIO_voidSetLevelPin(LED_2,LOW);
		MDIO_voidSetLevelPin(LED_3,LOW);
		MDIO_voidSetLevelPin(LED_4,LOW);
	}
	else if(Copy_u8Value <= 50)
	{
		MDIO_voidSetLevelPin(LED_1,HIGH);
		MDIO_voidSetLevelPin(LED_2,HIGH);
		MDIO_voidSetLevelPin(LED_3,LOW);
		MDIO_voidSetLevelPin(LED_4,LOW);
	}
	else if(Copy_u8Value <= 75)
	{
		MDIO_voidSetLevelPin(LED_1,HIGH);
		MDIO_voidSetLevelPin(LED_2,HIGH);
		MDIO_voidSetLevelPin(LED_3,HIGH);
		MDIO_voidSetLevelPin(LED_4,LOW);
	}
	else if(Copy_u8Value <= 100)
	{
		MDIO_voidSetLevelPin(LED_1,HIGH);
		MDIO_voidSetLevelPin(LED_2,HIGH);
		MDIO_voidSetLevelPin(LED_3,HIGH);
		MDIO_voidSetLevelPin(LED_4,HIGH);
	}
}
