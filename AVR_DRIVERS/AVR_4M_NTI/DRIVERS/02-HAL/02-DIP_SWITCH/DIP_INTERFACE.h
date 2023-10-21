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
enum SWITCH
{
	SWITCH_1_t = 1,
	SWITCH_2_t    ,
	SWITCH_3_t    ,
	SWITCH_4_t

}SWITCH_t;
/*Prototypes DIP SWITCH DRIVERS*/
void HSWITCH_voidInit  (void);
u8 HDIP_u8GetPressedKey  ( u8 Copy_u8SwitchId);


#endif
