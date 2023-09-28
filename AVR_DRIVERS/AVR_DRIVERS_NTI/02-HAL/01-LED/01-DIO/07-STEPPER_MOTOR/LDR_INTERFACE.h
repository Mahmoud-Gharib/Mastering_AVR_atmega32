/*==================================================================================*
 * File        : LDR_INTERFACE.h     												*
 * Description : This file includes LDR SENSOR Driver prototypes and macros			*
 * Author      : Mahmoud Gharib Embedded SW Engineer 								*
 * Date        : 																	*
 * Git account : https://github.com/Mahmoud-Gharib									*
 * mail        : mahmoudgharib99999@gmail.com 										*
 *==================================================================================*/

#ifndef LDR_INTERFACE_H
#define LDR_INTERFACE_H

#include "../../00-LIB/STD_TYPES.h"

/*Prototypes LDR SENSOR DRIVERS*/
void HLDR_voidInit(void);
u8 HTEMP_u8GetAnalogLDRValue (u8 Copy_u8ChannelNum);

#endif
