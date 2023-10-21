/*==================================================================================*
 * File        : SSD_INTERFACE.h     												*
 * Description : This file includes SSD Driver prototypes and macros				*
 * Author      : Mahmoud Gharib Embedded SW Engineer 								*
 * Date        : 																	*
 * Git account : https://github.com/Mahmoud-Gharib									*
 * mail        : mahmoudgharib99999@gmail.com 										*
 *==================================================================================*/

#ifndef SSD_INTERFACE_H
#define SSD_INTERFACE_H

#include "../../00-LIB/STD_TYPES.h"

enum DIGITS
{
	ONES_T = 1 ,
	TENS_T     ,
	HUNDREDS_T ,
	THOUSANDS_T
}DIGITS_t;

/*Prototypes SSD DRIVERS*/
void HSSD_voidInitSSD(void);
void HSSD_voidDisplayDigitSSD(u8 Copy_u8Number,u8 Copy_u8SSD);
void HSSD_voidDisplaySSD(u16 Copy_u16FullNumber);
void HSSD_voidCountDownSSD(u16 Copy_u16FullNumber);
void HSSD_voidCountUpSSD(u16 Copy_u16FullNumber);

#endif
