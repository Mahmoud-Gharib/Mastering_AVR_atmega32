/*==================================================================================*
 * File        : LED_PROGRAM.c														*
 * Description : This file includes LED Driver implementations 				      	*
 * Author      : Mahmoud Gharib Embedded SW Engineer 								*
 * Date        : 																	*
 * Git account : https://github.com/Mahmoud-Gharib									*
 * mail        : mahmoudgharib99999@gmail.com 										*
 *==================================================================================*/

/************ LIB  **********/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/************ MCAL **********/
#include "../../MCAL/DIO/DIO_INTERFACE.h"

/************ HAL **********/
#include "LED_CONFIG.h"
#include "LED_PRIVATE.h"
#include "LED_INTERFACE.h"

/*============================================================================================================*
 * Prototype   : void HLED_voidTurnOn (u8 Copy_u8LedPortId, u8 Copy_u8LedPinId);	  	   					  *
 * Description : TURN ON LED													     						  *
 * Arguments   : PORT 																						  *
 * 				 PIN															 							  *
 * return      : void																					      *
 *============================================================================================================*/
void HLED_voidTurnOn (u8 Copy_u8LedPortId, u8 Copy_u8LedPinId)
{
	MDIO_voidSetPinDirection ( Copy_u8LedPortId, Copy_u8LedPinId ,DIO_OUTPUT);
	MDIO_voidSetPinValue     (Copy_u8LedPortId, Copy_u8LedPinId , DIO_HIGH);
}

/*============================================================================================================*
 * Prototype   : void HLED_voidTurnOff (u8 Copy_u8LedPortId, u8 Copy_u8LedPinId);	  	   					  *
 * Description : TURN OFF LED													     						  *
 * Arguments   : PORT 																						  *
 * 				 PIN															 							  *
 * return      : void																					      *
 *============================================================================================================*/
void HLED_voidTurnOff (u8 Copy_u8LedPortId, u8 Copy_u8LedPinId)
{
	MDIO_voidSetPinDirection ( Copy_u8LedPortId, Copy_u8LedPinId ,DIO_OUTPUT);
	MDIO_voidSetPinValue     (Copy_u8LedPortId, Copy_u8LedPinId , DIO_LOW);
}
