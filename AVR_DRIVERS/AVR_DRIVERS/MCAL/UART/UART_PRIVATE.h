/*==============================================================================*
 * File        : UART_PRIVATE.h													*
 * Description : This file includes macros for UART of Atmega32          	 	*
 * Author      : Mahmoud Gharib Embedded SW Engineer 							*
 * Date        : 																*
 * Git account : https://github.com/Mahmoud-Gharib								*
 * mail        : mahmoudgharib99999@gmail.com 									*
 *==============================================================================*/
#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

/***************************** UART Registers macros **********************/
#define UCSRA        (*((volatile u8*)0x2B))
#define UCSRB        (*((volatile u8*)0x2A))
#define UCSRC        (*((volatile u8*)0x40))
#define UBRRL        (*((volatile u8*)0x29))
#define UBRRH        (*((volatile u8*)0x40))
#define UDR          (*((volatile u8*)0x2C))

#endif
