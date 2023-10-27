/*==================================================================================*
 * File        : EXTI_INTERFACE.h     												*
 * Description : This file includes EXTI Driver prototypes and macros for Atmega32	*
 * Author      : Mahmoud Gharib Embedded SW Engineer 								*
 * Date        : 																	*
 * Git account : https://github.com/Mahmoud-Gharib									*
 * mail        : mahmoudgharib99999@gmail.com 										*
 *==================================================================================*/

#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#include "../../00-LIB/STD_TYPES.h"

#define EXT_INT_0      	   0
#define EXT_INT_1      	   1
#define EXT_INT_2      	   2

#define FALLING_EDGE       0
#define RISING_EDGE        1
#define LOGICAL_CHANGE     2
#define LOW_LEVEL          3


/*********** Prototypes EXTI DRIVERS **************/
void MEXTI_voidEXTIEnable(u8 Copy_u8EXTI_Num, u8 Copy_u8EXTI_Sense);
void MEXTI_voidEXTIDisable(u8 Copy_u8EXTI_Num);

void EXT_INT_0_SET_CALL_BACK(void(*ptr)(void));
void EXT_INT_1_SET_CALL_BACK(void(*ptr)(void));
void EXT_INT_2_SET_CALL_BACK(void(*ptr)(void));


#endif
