/*==================================================================================*
 * File        : RTO_INTERFACE.h     												*
 * Description : This file includes RTO Driver prototypes and macros for Atmega32	*
 * Author      : Mahmoud Gharib Embedded SW Engineer 								*		
 * Date        : 																	*		
 * Git account : https://github.com/Mahmoud-Gharib									*		
 * mail        : mahmoudgharib99999@gmail.com 										*		
 *==================================================================================*/

#ifndef RTO_INTERFACE_H_
#define RTO_INTERFACE_H_


void RTO_voidInit(void);
u8   RTO_u8CreateTask(u8 Copy_u8Priority,u16 Copy_u16Periodicity,u16 Copy_u16FirstDelay,void (*Copy_pF)(void));


#endif 