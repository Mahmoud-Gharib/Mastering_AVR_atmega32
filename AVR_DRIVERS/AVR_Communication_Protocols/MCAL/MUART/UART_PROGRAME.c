/********** LIB **********/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/********  MCAL *********/
#include "UART_CONFIG.h"
#include "UART_INTERFACE.h"
#include "UART_PRIVATE.h"

/*==============================================================================*
 * Prototype   : void MUART_voidInit(void);										*
 * Description : Set initialization of UART										*
 * Arguments   : void			 												*
 * return      : void															*
 *==============================================================================*/
void MUART_voidInit(void)
{
	u8 Local_u8UCSRC = 0b10000000;

#if CHARACTER_SIZE  ==  5
	CLR_BIT(Local_u8UCSRC,1);
	CLR_BIT(Local_u8UCSRC,2);
#elif CHARACTER_SIZE == 6
	SET_BIT(Local_u8UCSRC,1);
	CLR_BIT(Local_u8UCSRC,2);
#elif CHARACTER_SIZE == 7
	CLR_BIT(Local_u8UCSRC,1);
	SET_BIT(Local_u8UCSRC,2);
#elif CHARACTER_SIZE == 8
	SET_BIT(Local_u8UCSRC,1);
	SET_BIT(Local_u8UCSRC,2);
#endif


#if STOP_BITS == 1
	CLR_BIT(Local_u8UCSRC,3);
#elif STOP_BITS == 2
	SET_BIT(Local_u8UCSRC,3);
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

	// ASYNCHRONOUS
	CLR_BIT(Local_u8UCSRC , 6);

	UCSRC = Local_u8UCSRC;

#if   BUAD_RATE   == 9600
	UBRRL = 51;
#elif BUAD_RATE   == 38400
	UBRRL = 12;
#elif BUAD_RATE   == 115200
	UBRRL = 3;
#endif

	// ENABLE TX , RX
	SET_BIT(UCSRB, 3);
	SET_BIT(UCSRB, 4);
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
	while( GET_BIT(UCSRA , 5) == 0);
}


/*==============================================================================*
 * Prototype   : u8	 MUART_u8ReciveData(void);									*
 * Description : Receive Data													*
 * Arguments   : void															*
 * return      : Value of UDR													*
 *==============================================================================*/
u8   MUART_u8ReciveData(void)
{
	while( GET_BIT( UCSRA , 7 ) == 0);
	return UDR;
}


void MUART_voidSendString(u8 *Ptr_u8PtrString)
{
	u8 i = 0;
	while(Ptr_u8PtrString[i] != '\0')
	{
		MUART_voidSendData(Ptr_u8PtrString[i]);
		i++;
	}
}

void MUART_voidReciveString(u8 *Ptr_u8PtrString)
{
	u8 i = 0;
	Ptr_u8PtrString[i] =  MUART_u8ReciveData();
	while(Ptr_u8PtrString[i] != '#')
	{
		i++;
		Ptr_u8PtrString[i] =  MUART_u8ReciveData();
	}
	Ptr_u8PtrString[i] = '\0';
}



void UART_voidIntEnable(u8 Copy_u8INT_ID)
{
	SET_BIT(SREG,7);
	switch(Copy_u8INT_ID)
	{
	case UART_TX:
		SET_BIT(UCSRB, 6);
		break;
	case UART_RX:
		SET_BIT(UCSRB, 7);
		break;
	default :
		break;
	}
}

void UART_voidIntDisable(u8 Copy_u8INT_ID)
{
	switch(Copy_u8INT_ID)
	{
	case UART_TX:
		CLR_BIT(UCSRB, 6);
		break;
	case UART_RX:
		CLR_BIT(UCSRB, 7);
		break;
	default :
		break;
	}
}

void MUART_voidAsyncSendData(u8 Copy_u8Data)
{
	UDR = Copy_u8Data;
}


u8   MUART_u8AsyncReciveData(void)
{
	return UDR;
}

void	(*UART_pvCallBackFunc[2])(void);

void UART_voidSetCallBack(u8 Copy_u8INT_ID,void (*Copy_pvCallBackFunc)(void))
{
	UART_pvCallBackFunc[Copy_u8INT_ID] = Copy_pvCallBackFunc;
}


void __vector_13 (void)	__attribute__((signal));
void __vector_13 (void)
{
	UART_pvCallBackFunc[UART_RX]();
}

void __vector_15 (void)	__attribute__((signal));
void __vector_15 (void)
{
	UART_pvCallBackFunc[UART_TX]();
}






