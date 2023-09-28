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


/*Prototypes LDR SENSOR DRIVERS*/
void HLDR_voidInit(void);
u16 HTEMP_u16GetAnalogLDRValue (u8 Copy_u8ChannelNum);

#endif
