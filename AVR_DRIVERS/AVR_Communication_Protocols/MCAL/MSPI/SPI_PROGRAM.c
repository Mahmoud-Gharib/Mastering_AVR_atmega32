/************ LIB  **********/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/************ MCAL **********/
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

	SET_BIT(SPCR,4);                      //Set MSTR to Master Mode
	SET_BIT(SPCR,2);					  //Set CPOL to CPHA to Setup First
	SET_BIT(SPCR,0);					  //PRESCALER /128
	SET_BIT(SPCR,1);
	CLR_BIT(SPSR,0);                      // Clear SPI2X

#elif   SPI_MODE == SLAVE
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
	SPDR = Copy_u8Data;
	while(GET_BIT(SPSR,7) == 0);   // Check if Transmission is Complete
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




void MSPI_voidIntEnable(void)
{
	SET_BIT(SREG,7);
	SET_BIT(SPCR, 7);
}

void MSPI_voidIntDisable(void)
{
	CLR_BIT(SPCR, 7);
}

void MSPI_voidAsyncSendData(u8 Copy_u8Data)
{
	SPDR = Copy_u8Data;
}

u8   MSPI_u8AsyncReciveData(void)
{
	return SPDR;
}


void	(*SPI_pvCallBackFunc)(void);

void MSPI_voidSetCallBack(void (*Copy_pvCallBackFunc)(void))
{
	SPI_pvCallBackFunc = Copy_pvCallBackFunc;
}

void __vector_12 (void)   __attribute__((signal));
void __vector_12 (void)
{
	SPI_pvCallBackFunc();
}
