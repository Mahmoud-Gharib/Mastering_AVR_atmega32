/*==================================================================================*
 * File        : LCD_PROGRAM.c														*
 * Description : This file includes LCD Driver implementations 						*
 * Author      : Mahmoud Gharib Embedded SW Engineer 								*
 * Date        : 																	*
 * Git account : https://github.com/Mahmoud-Gharib									*
 * mail        : mahmoudgharib99999@gmail.com 										*
 *==================================================================================*/

/************ LIB  **********/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include <util/delay.h>

/************ MCAL **********/
#include "../../MCAL/MDIO/DIO_INTERFACE.h"

/************ HAL **********/
#include "LCD_CONFIG.h"
#include "LCD_PRIVATE.h"
#include "LCD_INTERFACE.h"

/*==============================================================================*
 * Prototype   : void HLCD_voidInit(void);										*
 * Description : Set initialization direction of LCD							*
 * Arguments   : void			 												*
 * return      : void															*
 *==============================================================================*/
void HLCD_voidInit(void)
{
	MDIO_voidSetPinDirection(LCD_DATA_PORT,LCD_EN_PIN,DIO_OUTPUT);
	MDIO_voidSetPinDirection(LCD_DATA_PORT,LCD_RS_PIN,DIO_OUTPUT);
	
	#if (LCD_MODE == _8_BIT_MODE)
	MDIO_voidSetPortDirection(LCD_DATA_PORT,0xFF);
	_delay_ms(100);
	HLCD_voidSendCommand(0x38);			/*select 8-bit Mode*/
	#elif (LCD_MODE == _4_BIT_MODE)
	MDIO_voidSetPinDirection(LCD_DATA_PORT,LCD_DATA_PIN_4,DIO_OUTPUT);
	MDIO_voidSetPinDirection(LCD_DATA_PORT,LCD_DATA_PIN_5,DIO_OUTPUT);
	MDIO_voidSetPinDirection(LCD_DATA_PORT,LCD_DATA_PIN_6,DIO_OUTPUT);
	MDIO_voidSetPinDirection(LCD_DATA_PORT,LCD_DATA_PIN_7,DIO_OUTPUT);
	_delay_ms(100);
	HLCD_voidSendCommand(0x33);		   /*select 4-bit Mode*/
	HLCD_voidSendCommand(0x32);
	HLCD_voidSendCommand(0x28);
	#endif
	
	HLCD_voidSendCommand(0x0C);		/*TURN LCD DISPLAY		  */	
	HLCD_voidSendCommand(0x02);		/*RETURN HOME			  */
	HLCD_voidSendCommand(0x01);		/*CLEAR	LCD DISPLAY		  */
	HLCD_voidSendCommand(0x06);		/*MOVE FROM LEFT TO RIGHT */
}

/*==============================================================================*
 * Prototype   : void HLCD_voidSendCommand(u8 Copy_u8Cmd);						*
 * Description : Send Command to LCD											*
 * Arguments   : Command : takes Command 										*
 * return      : void															*
 *==============================================================================*/
void HLCD_voidSendCommand(u8 Copy_u8Cmd)
{
	#if (LCD_MODE == _8_BIT_MODE)
	MDIO_voidSetPinValue (LCD_DATA_PORT,LCD_RS_PIN,DIO_LOW);
	MDIO_voidSetPortValue(LCD_DATA_PORT,Copy_u8Cmd);
	MDIO_voidSetPinValue (LCD_DATA_PORT,LCD_EN_PIN,DIO_HIGH);
	_delay_ms(1);
	MDIO_voidSetPinValue(LCD_DATA_PORT,LCD_EN_PIN,DIO_LOW);
	_delay_ms(5);
	
	#elif (LCD_MODE == _4_BIT_MODE)
	//to select command register
	MDIO_voidSetPinValue(LCD_DATA_PORT,LCD_RS_PIN,DIO_LOW);
	MDIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN_4, GET_BIT(Copy_u8Cmd,4));
	MDIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN_5, GET_BIT(Copy_u8Cmd,5));
	MDIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN_6, GET_BIT(Copy_u8Cmd,6));
	MDIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN_7, GET_BIT(Copy_u8Cmd,7));

	MDIO_voidSetPinValue(LCD_DATA_PORT,LCD_EN_PIN,DIO_HIGH); //EN
	_delay_ms(1);
	MDIO_voidSetPinValue(LCD_DATA_PORT,LCD_EN_PIN,DIO_LOW);
	
	MDIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN_4, GET_BIT(Copy_u8Cmd,0));
	MDIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN_5, GET_BIT(Copy_u8Cmd,1));
	MDIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN_6, GET_BIT(Copy_u8Cmd,2));
	MDIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN_7, GET_BIT(Copy_u8Cmd,3));
	
	MDIO_voidSetPinValue(LCD_DATA_PORT,LCD_EN_PIN,DIO_HIGH); //EN
	_delay_ms(1);
	MDIO_voidSetPinValue(LCD_DATA_PORT,LCD_EN_PIN,DIO_LOW);
	_delay_ms(5);
	#endif
}

/*==============================================================================*
 * Prototype   : void HLCD_voidSendData(u8 Copy_u8Data);						*
 * Description : Send Char to LCD												*
 * Arguments   : Char : takes Char		 										*
 * return      : void															*
 *==============================================================================*/
void HLCD_voidSendData(u8 Copy_u8Data)
{
	#if (LCD_MODE == _8_BIT_MODE)
	MDIO_voidSetPinValue (LCD_DATA_PORT,LCD_RS_PIN,DIO_HIGH);
	MDIO_voidSetPortValue(LCD_DATA_PORT,Copy_u8Data);
	MDIO_voidSetPinValue (LCD_DATA_PORT,LCD_EN_PIN,DIO_HIGH);
	_delay_ms(1);
	MDIO_voidSetPinValue(LCD_DATA_PORT,LCD_EN_PIN,DIO_LOW);
	_delay_ms(5);
	
	#elif (LCD_MODE == _4_BIT_MODE)
	//to select command register
	MDIO_voidSetPinValue(LCD_DATA_PORT,LCD_RS_PIN,DIO_HIGH);
	MDIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN_4, GET_BIT(Copy_u8Data,4));
	MDIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN_5, GET_BIT(Copy_u8Data,5));
	MDIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN_6, GET_BIT(Copy_u8Data,6));
	MDIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN_7, GET_BIT(Copy_u8Data,7));

	MDIO_voidSetPinValue(LCD_DATA_PORT,LCD_EN_PIN,DIO_HIGH); //EN
	_delay_ms(1);
	MDIO_voidSetPinValue(LCD_DATA_PORT,LCD_EN_PIN,DIO_LOW);
	
	MDIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN_4, GET_BIT(Copy_u8Data,0));
	MDIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN_5, GET_BIT(Copy_u8Data,1));
	MDIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN_6, GET_BIT(Copy_u8Data,2));
	MDIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN_7, GET_BIT(Copy_u8Data,3));
	
	MDIO_voidSetPinValue(LCD_DATA_PORT,LCD_EN_PIN,DIO_HIGH); //EN
	_delay_ms(1);
	MDIO_voidSetPinValue(LCD_DATA_PORT,LCD_EN_PIN,DIO_LOW);
	_delay_ms(5);
	#endif
}

/*==============================================================================*
 * Prototype   : void HLCD_voidClearDisplay(void);								*
 * Description : Clear LCD Display												*
 * Arguments   : void						 									*
 * return      : void															*
 *==============================================================================*/
void HLCD_voidClearDisplay(void)
{
	HLCD_voidSendCommand(0x01);
}

/*==============================================================================*
 * Prototype   : void HLCD_voidSendString(u8 *Ptr_u8PtrString);					*
 * Description : Send String to LCD												*
 * Arguments   : String : takes String		 									*
 * return      : void															*
 *==============================================================================*/
void HLCD_voidSendString(u8 *Ptr_u8PtrString)
{
	while(*Ptr_u8PtrString != 0)
	{
		HLCD_voidSendData(*Ptr_u8PtrString);
		Ptr_u8PtrString++;
	}
}

/*==============================================================================*
 * Prototype   : void HLCD_voidGoToPosition(u8 Copy_u8RowNum,u8 Copy_u8ColNum);	*
 * Description : Send Position to LCD											*
 * Arguments   : N.OF ROW AND N.OF COL											*
 * return      : void															*
 *==============================================================================*/
void HLCD_voidGoToPosition(u8 Copy_u8RowNum,u8 Copy_u8ColNum)
{
	u8 arr[4] ={0x80,0xC0,0x90,0xD0};
	HLCD_voidSendCommand(arr[Copy_u8RowNum] + Copy_u8ColNum);
}

/*==============================================================================*
 * Prototype   : void HLCD_voidDisplayNumber(s32 Copy_s32Number);				*
 * Description : Send NUMBER to LCD												*
 * Arguments   : NUMBER															*
 * return      : void															*
 *==============================================================================*/
void HLCD_voidDisplayNumber(s32 Copy_s32Number)
{
	if(Copy_s32Number == 0)
	{
		HLCD_voidSendData('0');
	}
	else if(Copy_s32Number > 0  )
	{
		s8 i=0;
	    u8 Copy_u8Remander = 0;
	    u8 arr[10] = {0};
	    while(Copy_s32Number != 0)
	    {
	    	Copy_u8Remander = Copy_s32Number % 10;
	    	arr[i] = Copy_u8Remander;
	    	i++;
	    	Copy_s32Number /= 10;
	    }
	    i--;
	    while(i >= 0)
	    {
	    	HLCD_voidSendData(arr[i] + 48);
	    	i--;	
	    }
	    
	}
}

/*=======================================================================================================================*
 * Prototype   : void HLCD_voidDisplaySpecialChar(u8* Ptr_u8PtrChar,u8 CGRam_index,u8 Copy_u8RowNum,u8 Copy_u8ColNum);	 *
 * Description : Send SpecialChar to LCD																				 *
 * Arguments   : SpecialChar ,	CGRam_index ,N.OF ROW , N.OF COL														 *
 * return      : void																									 *
 *=======================================================================================================================*/
void HLCD_voidDisplaySpecialChar(u8* Ptr_u8PtrChar,u8 CGRam_index,u8 Copy_u8RowNum,u8 Copy_u8ColNum)
{
	HLCD_voidGoToPosition( Copy_u8RowNum, Copy_u8ColNum);
	HLCD_voidSendData(CGRam_index);
	u8 Local_u8address;
	u8 Local_u8Index;
	if (CGRam_index < 8)
	{
		Local_u8address= CGRam_index * 8;
		Local_u8address= SET_BIT(Local_u8address,6);
		HLCD_voidSendCommand(Local_u8address);
		for(Local_u8Index = 0;Local_u8Index < 8;Local_u8Index++)
		{
			HLCD_voidSendData(Ptr_u8PtrChar[Local_u8Index]);
		}
	}
	HLCD_voidSendCommand(0x02);

}
