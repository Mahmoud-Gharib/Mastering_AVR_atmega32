/*==================================================================================*
 * File        : LED_INTERFACE.h     												*
 * Description : This file includes LED Driver prototypes and macros				*
 * Author      : Mahmoud Gharib Embedded SW Engineer 								*
 * Date        : 																	*
 * Git account : https://github.com/Mahmoud-Gharib									*
 * mail        : mahmoudgharib99999@gmail.com 										*
 *==================================================================================*/

#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

#include "../../00-LIB/STD_TYPES.h"

enum Led
{
	LED_GREEN_t = 1,
	LED_BLUE_t     ,
	LED_YELLOW_t   ,
	LED_RED_t

}LED_t;


/*Prototypes LED DRIVERS*/
void HLED_voidInit  (void);
void HLED_voidTurnOn  (u8 Copy_u8LedPinId);
void HLED_voidTurnOff (u8 Copy_u8LedPinId);

#endif
