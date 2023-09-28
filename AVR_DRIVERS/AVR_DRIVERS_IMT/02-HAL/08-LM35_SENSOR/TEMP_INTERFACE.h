/*==================================================================================*
 * File        : TEMP_INTERFACE.h     												*
 * Description : This file includes TEMP SENSOR Driver prototypes and macros		*
 * Author      : Mahmoud Gharib Embedded SW Engineer 								*
 * Date        : 																	*
 * Git account : https://github.com/Mahmoud-Gharib									*
 * mail        : mahmoudgharib99999@gmail.com 										*
 *==================================================================================*/

#ifndef TEMP_INTERFACE_H
#define TEMP_INTERFACE_H

#include "../../00-LIB/STD_TYPES.h"

/*Prototypes TEMP SENSOR DRIVERS*/
void HTEMP_voidInit(void);
u8 HTEMP_u8GetAnalogTempreatureDegree (u8 Copy_u8ChannelNum);

#endif
