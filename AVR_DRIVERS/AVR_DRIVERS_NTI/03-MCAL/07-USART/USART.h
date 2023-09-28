/*====================================================================================*
 * File        : USART.h     														  *
 * Description : This file includes USART Driver prototypes and macros for Atmega32	  *
 * Author      : Mahmoud Gharib Embedded SW Engineer 								  *		
 * Date        : 1/2/2022															  *		
 * Git account : https://github.com/Mahmoud-Gharib									  *		
 * mail        : mahmoudgharib99999@gmail.com 										  *		
 *====================================================================================*/
#ifndef USART_H_
#define USART_H_

#include "../../00-LIB/STD_TYPES.h"
/******************* PARITY macros *******************/
#define NON     0
#define ODD     1
#define EVEN    2
/************** Prototypes USART DRIVERS ************/											
void MUSART_voidInitUsart(void);
void MUSART_voidSendData(u8 Data);
u8	 MUSART_u8RcvData(void);

#endif

