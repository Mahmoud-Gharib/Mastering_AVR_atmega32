/*==================================================================================*
 * File        : LED_PROGRAM.c														*
 * Description : This file includes LED Driver implementations 				      	*
 * Author      : Mahmoud Gharib Embedded SW Engineer 								*
 * Date        : 																	*
 * Git account : https://github.com/Mahmoud-Gharib									*
 * mail        : mahmoudgharib99999@gmail.com 										*
 *==================================================================================*/

/************ LIB  **********/
#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_MATH.h"

/************ MCAL **********/
#include "../../03-MCAL/01-DIO/DIO_INTERFACE.h"

/************ HAL **********/
#include "LED_CONFIG.h"
#include "LED_PRIVATE.h"
#include "LED_INTERFACE.h"

void HLED_voidInit  (void)
{
	MDIO_voidSetPinDirection (DIO_u8_PORTA , LED_GREEN ,DIO_u8_OUTPUT);
	MDIO_voidSetPinDirection (DIO_u8_PORTA , LED_BLUE ,DIO_u8_OUTPUT);
	MDIO_voidSetPinDirection (DIO_u8_PORTA , LED_YELLOW ,DIO_u8_OUTPUT);
	MDIO_voidSetPinDirection (DIO_u8_PORTB , LED_RED ,DIO_u8_OUTPUT);
}

void HLED_voidTurnOn ( u8 Copy_u8LedPinId)
{
	switch(Copy_u8LedPinId)
	{
		case LED_GREEN_t:
			MDIO_voidSetPinValue(DIO_u8_PORTA , LED_GREEN ,DIO_u8_HIGH);
			break;
		case LED_BLUE_t:
			MDIO_voidSetPinValue(DIO_u8_PORTA , LED_BLUE ,DIO_u8_HIGH);
			break;
		case LED_YELLOW_t:
			MDIO_voidSetPinValue(DIO_u8_PORTA , LED_YELLOW ,DIO_u8_HIGH);
			break;
		case LED_RED_t:
			MDIO_voidSetPinValue(DIO_u8_PORTB , LED_RED ,DIO_u8_HIGH);
			break;
		default :
			break;
	}
}

void HLED_voidTurnOff ( u8 Copy_u8LedPinId)
{
	switch(Copy_u8LedPinId)
		{
			case LED_GREEN_t:
				MDIO_voidSetPinValue(DIO_u8_PORTA , LED_GREEN ,DIO_u8_LOW);
				break;
			case LED_BLUE_t:
				MDIO_voidSetPinValue(DIO_u8_PORTA , LED_BLUE ,DIO_u8_LOW);
				break;
			case LED_YELLOW_t:
				MDIO_voidSetPinValue(DIO_u8_PORTA , LED_YELLOW ,DIO_u8_LOW);
				break;
			case LED_RED_t:
				MDIO_voidSetPinValue(DIO_u8_PORTB , LED_RED ,DIO_u8_LOW);
				break;
			default :
				break;
		}
}
