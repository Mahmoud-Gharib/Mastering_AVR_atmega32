/*==================================================================================*
 * File        : SPI_PROGRAM.c														*
 * Description : This file includes SPI Driver implementations for Atmega32     	*
 * Author      : Mahmoud Gharib Embedded SW Engineer 								*
 * Date        : 																	*
 * Git account : https://github.com/Mahmoud-Gharib									*
 * mail        : mahmoudgharib99999@gmail.com 										*
 *==================================================================================*/

/************ LIB  **********/
#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_MATH.h"
#include "avr/delay.h"

/************ MCAL **********/
#include "../01-DIO/DIO_PRIVATE.h"

#include "SPI_CONFIG.h"
#include "SPI_PRIVATE.h"
#include "SPI_INTERFACE.h"

/*==============================================================================*
 * Prototype   : void MSPI_voidInit(void);										*
 * Description : Set initialization of SPI										*
 * Arguments   : void			 												*
 * return      : void															*
 *==============================================================================*/
void MSPI_voidInit(void)
{
	SET_BIT(SPCR,5);                      //SENT FROM LSB FIRST
	#if SPI_MODE == MASTER
	SET_BIT(DIO_u8_DDRB_REG,5);           // MOSI ==> OUTPUT  
	CLR_BIT(DIO_u8_DDRB_REG,6);           // MISO ==> INPUT
	SET_BIT(DIO_u8_DDRB_REG,4);           // SS   ==> OUTPUT
	SET_BIT(DIO_u8_DDRB_REG,7);           // SCK  ==> OUTPUT

	SET_BIT(SPCR,4);                      //Set MSTR to Master Mode
	SET_BIT(SPCR,2);					  //Set CPOL to CPHA to Setup First
	SET_BIT(SPCR,0);					  //PRESCALER /128
	SET_BIT(SPCR,1);
	CLR_BIT(SPSR,0);                      // Clear SPI2X
	//_delay_ms(2000);
	#elif   SPI_MODE == SLAVE
	CLR_BIT(DIO_u8_DDRB_REG,5);           // MOSI ==> INPUT  
	SET_BIT(DIO_u8_DDRB_REG,6);           // MISO ==> OUTPUT
	CLR_BIT(DIO_u8_DDRB_REG,4);           // SS   ==> INPUT
	CLR_BIT(DIO_u8_DDRB_REG,7);           // SCK  ==> INPUT
	CLR_BIT(SPCR,4);                      //Set MSTR to Slave Mode
	#endif
	SET_BIT(SPCR,6);					  //ENABLE SPI
}
/*==============================================================================*
 * Prototype   : void MSPI_voidSendData(u8 Copy_u8Data);						*
 * Description : Send Data														*
 * Arguments   : Copy_u8Data			 										*
 * return      : void														    *
 *==============================================================================*/
void MSPI_voidSendData(u8 Copy_u8Data)
{
	CLR_BIT(DIO_u8_PORTB_REG,4);          // SS   ==> LOW
	SPDR = Copy_u8Data;
	while(GET_BIT(SPSR,7) == 0);   // Check if Transmission is Complete
	SET_BIT(DIO_u8_PORTB_REG,4);          // SS   ==> HIGH
}
/*==============================================================================*
 * Prototype   : u8   MSPI_u8ReciveData(void);									*
 * Description : Receive Data													*
 * Arguments   : void															*
 * return      : Value of SPDR													*
 *==============================================================================*/
u8   MSPI_u8ReciveData(void)
{
	while(GET_BIT(SPSR,7) == 0);   // Check if Transmission is Complete
	return SPDR;
}
/*==============================================================================*
 * Prototype   : u8   MSPI_u8SendReciveData(u8 Copy_u8Data);					*
 * Description : Send and Receive Data											*
 * Arguments   : Copy_u8Data													*
 * return      : Value of SPDR													*
 *==============================================================================*/
u8   MSPI_u8SendReciveData(u8 Copy_u8Data)
{
	SPDR = Copy_u8Data;
	while(GET_BIT(SPSR,7) == 0);   // Check if Transmission is Complete
    return SPDR;
}
