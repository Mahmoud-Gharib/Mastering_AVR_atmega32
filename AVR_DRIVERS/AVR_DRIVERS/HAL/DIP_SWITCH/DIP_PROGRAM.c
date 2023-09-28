/*==================================================================================*
 * File        : DIP_PROGRAM.c														*
 * Description : This file includes DIP SWITCH Driver implementations 				*
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
#include "DIP_CONFIG.h"
#include "DIP_PRIVATE.h"
#include "DIP_INTERFACE.h"

/*============================================================================================================*
 * Prototype   : u8 HDIP_u8GetPressedKey  (u8 Copy_u8PortId , u8 Copy_u8PinId);	  	   						  *
 * Description : Read SWITCH Value													     					  *
 * Arguments   : PORT 																						  *
 * 				 PIN															 							  *
 * return      : SWITCH VALUE																			      *
 *============================================================================================================*/
u8 HDIP_u8GetPressedKey  (u8 Copy_u8PortId , u8 Copy_u8PinId)
{
	u8 Local_u8VALUE = MDIO_u8GetPinValue( Copy_u8PortId , Copy_u8PinId);
	return Local_u8VALUE;
}

/*============================================================================================================*
 * Prototype   : u8 HDIP_u8GetPressedKeys (u8 Copy_u8PortId, u8 Copy_u8NumberOfPortPins);	  	   			  *
 * Description : Read SWITCHS Value													     					  *
 * Arguments   : PORT 																						  *
 * 				 N. OF PINs															 						  *
 * return      : SWITCHS VALUE																			      *
 *============================================================================================================*/
u8 HDIP_u8GetPressedKeys (u8 Copy_u8PortId, u8 Copy_u8NumberOfPortPins)
{
	/*         */ 
}
