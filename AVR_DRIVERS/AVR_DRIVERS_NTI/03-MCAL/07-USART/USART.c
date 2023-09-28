/*==================================================================================*
 * File        : USART.c															*
 * Description : This file includes USART Driver implementations for Atmega32     	*
 * Author      : Mahmoud Gharib Embedded SW Engineer 								*		
 * Date        : 1/2/2022															*		
 * Git account : https://github.com/Mahmoud-Gharib									*		
 * mail        : mahmoudgharib99999@gmail.com 										*		
 *==================================================================================*/
#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_MATH.h"
#include "../REG.h"
#include "USART_CFG.h"
#include "USART.h"
/*==============================================================================*
 * Prototype   : void MUSART_voidInitUsart(void);								*
 * Description : Set initialization of USART									*
 * Arguments   : void			 												*
 * return      : void															*
 *==============================================================================*/
void MUSART_voidInitUsart(void)
{
	u8 Local_u8UCSRC = 0b10000000;
	SET_BIT(DDRD,1);
	CLR_BIT(DDRD,0);
	
	#if CHARACTER_SIZE  == 7
	
	#elif CHARACTER_SIZE == 8
	SET_BIT(Local_u8UCSRC,1);
	SET_BIT(Local_u8UCSRC,2);
	CLR_BIT(UCSRB,2);
	#endif
	
	#if PARITY_CHECK  == NON 
	CLR_BIT(Local_u8UCSRC,4);
	CLR_BIT(Local_u8UCSRC,5);
	#elif PARITY_CHECK == ODD
	SET_BIT(Local_u8UCSRC,4);
	SET_BIT(Local_u8UCSRC,5);
	#elif PARITY_CHECK == EVEN
	
	#endif
	
	#if STOP_BITS == 1
	CLR_BIT(Local_u8UCSRC,3);
	#elif STOP_BITS == 2
	SET_BIT(Local_u8UCSRC,3);
	#endif
	
	UCSRC = Local_u8UCSRC;
	
	#if   BUAD_RATE   == 9600
	SPDR = 103;	
	#elif BUAD_RATE   == 115200 
	
	#elif BUAD_RATE   == 38400 
	
	#endif
	
	SET_BIT(UCSRB,3);
	SET_BIT(UCSRB,4);
}
/*==============================================================================*
 * Prototype   : void MUSART_voidSendData(u8 Copy_u8Data);						*
 * Description : Send Data														*
 * Arguments   : Copy_u8Data			 										*
 * return      : void														    *
 *==============================================================================*/
void MUSART_voidSendData(u8 Copy_u8Data)
{
	UDR = Copy_u8Data;
	while(GET_BIT(UCSRA,6) == 0);
}
/*==============================================================================*
 * Prototype   : u8	 MUSART_u8RcvData(void);									*
 * Description : Receive Data													*
 * Arguments   : void															*
 * return      : Value of UDR													*
 *==============================================================================*/
u8	 MUSART_u8RcvData(void)
{
	while(GET_BIT(UCSRA,7) == 0);
	return UDR;
}


