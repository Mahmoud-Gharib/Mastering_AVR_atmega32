/*==============================================================================*
 * File        : EXTI_PRIVATE.h													*
 * Description : This file includes macros for EXTI of Atmega32          	 	*
 * Author      : Mahmoud Gharib Embedded SW Engineer 							*
 * Date        : 																*
 * Git account : https://github.com/Mahmoud-Gharib								*
 * mail        : mahmoudgharib99999@gmail.com 									*
 *==============================================================================*/
#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

/************************** EXT INT Registers macros ***************************/
#define  SREG      (*((volatile u8*)0x5F))
#define  MCUCR     (*((volatile u8*)0x55))
#define  MCUCSR    (*((volatile u8*)0x54))
#define  GICR      (*((volatile u8*)0x5B))
#define  GIFR      (*((volatile u8*)0x5A))

#endif
