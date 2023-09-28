/*==================================================================================*
 * File        : DIP_INTERFACE.h     												*
 * Description : This file includes DIP SWITCH Driver prototypes and macros			*
 * Author      : Mahmoud Gharib Embedded SW Engineer 								*
 * Date        : 																	*
 * Git account : https://github.com/Mahmoud-Gharib									*
 * mail        : mahmoudgharib99999@gmail.com 										*
 *==================================================================================*/

#ifndef DIP_INTERFACE_H
#define DIP_INTERFACE_H

#include "../../00-LIB/STD_TYPES.h"

/*Prototypes DIP SWITCH DRIVERS*/
u8 HDIP_u8GetPressedKey  (u8 Copy_u8PortId , u8 Copy_u8PinId);
u8 HDIP_u8GetPressedKeys (u8 Copy_u8PortId, u8 Copy_u8NumberOfPortPins);

#endif
