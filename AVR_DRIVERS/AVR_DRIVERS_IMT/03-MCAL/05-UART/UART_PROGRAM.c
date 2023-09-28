/*==================================================================================*
 * File        : UART_PROGRAM.c														*
 * Description : This file includes UART Driver implementations for Atmega32     	*
 * Author      : Mahmoud Gharib Embedded SW Engineer 								*
 * Date        : 																	*
 * Git account : https://github.com/Mahmoud-Gharib									*
 * mail        : mahmoudgharib99999@gmail.com 										*
 *==================================================================================*/

/************ LIB  **********/
#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_MATH.h"

/************ MCAL **********/
#include "../01-DIO/DIO_PRIVATE.h"

#include "UART_CONFIG.h"
#include "UART_PRIVATE.h"
#include "UART_INTERFACE.h"

/*==============================================================================*
 * Prototype   : void MUART_voidInit(void);										*
 * Description : Set initialization of UART										*
 * Arguments   : void			 												*
 * return      : void															*
 *==============================================================================*/
void MUART_voidInit(void)
{
	u8 Local_u8UCSRC = 0b10000000;            
	SET_BIT(DIO_u8_DDRD_REG,1);    			// to make PD1 (Tx) -> output
	CLR_BIT(DIO_u8_DDRD_REG,0);    			// to make PD0 (Rx) -> intput
	
	#if CHARACTER_SIZE  ==  5  
	CLR_BIT(Local_u8UCSRC,1); 
	CLR_BIT(Local_u8UCSRC,2);
	CLR_BIT(UCSRB,2);
	#elif CHARACTER_SIZE == 6 
	SET_BIT(Local_u8UCSRC,1); 
	CLR_BIT(Local_u8UCSRC,2); 
	CLR_BIT(UCSRB,2);
	#elif CHARACTER_SIZE  ==  7
	CLR_BIT(Local_u8UCSRC,1); 
	SET_BIT(Local_u8UCSRC,2);
	CLR_BIT(UCSRB,2);
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
	CLR_BIT(Local_u8UCSRC,4); 
	SET_BIT(Local_u8UCSRC,5);
	#endif                    
 
	#if STOP_BITS == 1        
	CLR_BIT(Local_u8UCSRC,3); 
	#elif STOP_BITS == 2      
	SET_BIT(Local_u8UCSRC,3); 
	#endif                    
  
	UCSRC = Local_u8UCSRC;    
 
	#if   BUAD_RATE   == 9600 
	UBRRL = 103;	          
	#elif BUAD_RATE   == 115200
	UBRRL = 8;
	#elif BUAD_RATE   == 38400
	UBRRL = 25;
	#endif                    
	
	SET_BIT(UCSRB,3);  				//to enable uart rx
	SET_BIT(UCSRB,4);  				//to enable uart tx
}
/*==============================================================================*
 * Prototype   : void MUART_voidSendData(u8 Copy_u8Data);						*
 * Description : Send Data														*
 * Arguments   : Copy_u8Data			 										*
 * return      : void														    *
 *==============================================================================*/
void MUART_voidSendData(u8 Copy_u8Data)
{
	UDR = Copy_u8Data;
	while(GET_BIT(UCSRA,6) == 0);
}
/*==============================================================================*
 * Prototype   : u8	 MUART_u8RcvData(void);										*
 * Description : Receive Data													*
 * Arguments   : void															*
 * return      : Value of UDR													*
 *==============================================================================*/
u8	 MUART_u8RcvData(void)
{
	while(GET_BIT(UCSRA,7) == 0);
	return UDR;
}


