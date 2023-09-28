/*==================================================================================*
 * File        : UART_INTERFACE.h     												*
 * Description : This file includes UART Driver prototypes and macros for Atmega32	*
 * Author      : Mahmoud Gharib Embedded SW Engineer 								*
 * Date        : 																	*
 * Git account : https://github.com/Mahmoud-Gharib									*
 * mail        : mahmoudgharib99999@gmail.com 										*
 *==================================================================================*/

#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

#include "../../00-LIB/STD_TYPES.h"

/******************* PARITY macros *******************/
#define NON     0
#define ODD     1
#define EVEN    2
/************** Prototypes USART DRIVERS ************/											
void MUART_voidInit(void);
void MUART_voidSendData(u8 Data);
u8	 MUART_u8RcvData(void);

#endif
