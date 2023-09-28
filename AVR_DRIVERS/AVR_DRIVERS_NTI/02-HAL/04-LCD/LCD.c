/*==================================================================================*
 * File        : LCD.c																*
 * Description : This file includes LCD Driver implementations				      	*
 * Author      : Mahmoud Gharib Embedded SW Engineer 								*		
 * Date        : 7/2/2022															*		
 * Git account : https://github.com/Mahmoud-Gharib									*		
 * mail        : mahmoudgharib99999@gmil.com 										*		
 *==================================================================================*/
//#define F_CPU 16000000UL
#include "../04-LCD/LCD.h"

#include <util/delay.h>
#include "../../00-LIB/BIT_MATH.h"
#include "../../03-MCAL/01-DIO/DIO.h"
#include "../04-LCD/LCD_CFG.h"
/*==============================================================================*
 * Prototype   : void HLCD_voidInitLcd(void);									*
 * Description : Set initialization direction of LCD							*
 * Arguments   : void			 												*
 * return      : void															*
 *==============================================================================*/
void HLCD_voidInitLcd(void)
{
	MDIO_voidSetDirectionPin(LCD_EN_PIN,OUTPUT);
	MDIO_voidSetDirectionPin(LCD_RS_PIN,OUTPUT);
	
	#if (LCD_MODE == _8_BIT_MODE)
	MDIO_voidSetDirectionPort(LCD_DATA_PORT,OUTPUT);
	_delay_ms(100);
	HLCD_voidWriteCommand(0x38);			/*select 8-bit Mode*/
	
	#elif (LCD_MODE == _4_BIT_MODE)
	MDIO_voidSetDirectionPin(LCD_DATA_PIN_4,OUTPUT);
	MDIO_voidSetDirectionPin(LCD_DATA_PIN_5,OUTPUT);
	MDIO_voidSetDirectionPin(LCD_DATA_PIN_6,OUTPUT);
	MDIO_voidSetDirectionPin(LCD_DATA_PIN_7,OUTPUT);
	_delay_ms(100);
	HLCD_voidWriteCommand(0x33);		   /*select 4-bit Mode*/
	HLCD_voidWriteCommand(0x32);
	HLCD_voidWriteCommand(0x28);
	#endif
	
	HLCD_voidWriteCommand(0x0C);		/*TURN LCD DISPLAY		  */	
	HLCD_voidWriteCommand(0x02);		/*RETURN HOME			  */
	HLCD_voidWriteCommand(0x01);		/*CLEAR	LCD DISPLAY		  */
	HLCD_voidWriteCommand(0x06);		/*MOVE FROM LEFT TO RIGHT */
}
/*==============================================================================*
 * Prototype   : void HLCD_u8WriteCommand(u8 Copy_u8Command);					*
 * Description : Send Command to LCD											*
 * Arguments   : Command : takes Command 										*
 * return      : void															*
 *==============================================================================*/
void HLCD_voidWriteCommand(u8 Copy_u8Command)
{
	#if (LCD_MODE == _8_BIT_MODE)
	MDIO_voidSetLevelPin(LCD_RS_PIN,LOW);
	MDIO_voidSetLevelPort(LCD_DATA_PORT,Copy_u8Command);
	MDIO_voidSetLevelPin(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	MDIO_voidSetLevelPin(LCD_EN_PIN,LOW);
	_delay_ms(5);
	
	#elif (LCD_MODE == _4_BIT_MODE)
	//to select command register
	MDIO_voidSetLevelPin(LCD_RS_PIN,LOW);
	MDIO_voidSetLevelPin(LCD_DATA_PIN_4, GET_BIT(Copy_u8Command,4));
	MDIO_voidSetLevelPin(LCD_DATA_PIN_5, GET_BIT(Copy_u8Command,5));
	MDIO_voidSetLevelPin(LCD_DATA_PIN_6, GET_BIT(Copy_u8Command,6));
	MDIO_voidSetLevelPin(LCD_DATA_PIN_7, GET_BIT(Copy_u8Command,7));

	MDIO_voidSetLevelPin(LCD_EN_PIN,HIGH); //EN
	_delay_ms(1);
	MDIO_voidSetLevelPin(LCD_EN_PIN,LOW);
	
	MDIO_voidSetLevelPin(LCD_DATA_PIN_4, GET_BIT(Copy_u8Command,0));
	MDIO_voidSetLevelPin(LCD_DATA_PIN_5, GET_BIT(Copy_u8Command,1));
	MDIO_voidSetLevelPin(LCD_DATA_PIN_6, GET_BIT(Copy_u8Command,2));
	MDIO_voidSetLevelPin(LCD_DATA_PIN_7, GET_BIT(Copy_u8Command,3));
	
	MDIO_voidSetLevelPin(LCD_EN_PIN,HIGH); //EN
	_delay_ms(1);
	MDIO_voidSetLevelPin(LCD_EN_PIN,LOW);
	_delay_ms(5);
	#endif
}
/*==============================================================================*
 * Prototype   : void HLCD_u8WriteChar(u8 Copy_u8Char);							*
 * Description : Send Char to LCD												*
 * Arguments   : Char : takes Char		 										*
 * return      : void															*
 *==============================================================================*/
void HLCD_voidWriteChar(u8 Copy_u8Char)
{
	#if (LCD_MODE ==  _8_BIT_MODE)
	MDIO_voidSetLevelPin(LCD_RS_PIN,HIGH);
	MDIO_voidSetLevelPort(LCD_DATA_PORT,Copy_u8Char);
	MDIO_voidSetLevelPin(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	MDIO_voidSetLevelPin(LCD_EN_PIN,LOW);
	_delay_ms(5);
	
	#elif (LCD_MODE ==  _4_BIT_MODE)
	//to select command register
	MDIO_voidSetLevelPin(LCD_RS_PIN,HIGH);
	MDIO_voidSetLevelPin(LCD_DATA_PIN_4, GET_BIT(Copy_u8Char,4));
	MDIO_voidSetLevelPin(LCD_DATA_PIN_5, GET_BIT(Copy_u8Char,5));
	MDIO_voidSetLevelPin(LCD_DATA_PIN_6, GET_BIT(Copy_u8Char,6));
	MDIO_voidSetLevelPin(LCD_DATA_PIN_7, GET_BIT(Copy_u8Char,7));

	MDIO_voidSetLevelPin(LCD_EN_PIN,HIGH); //EN
	_delay_ms(1);
	MDIO_voidSetLevelPin(LCD_EN_PIN,LOW);
	
	MDIO_voidSetLevelPin(LCD_DATA_PIN_4, GET_BIT(Copy_u8Char,0));
	MDIO_voidSetLevelPin(LCD_DATA_PIN_5, GET_BIT(Copy_u8Char,1));
	MDIO_voidSetLevelPin(LCD_DATA_PIN_6, GET_BIT(Copy_u8Char,2));
	MDIO_voidSetLevelPin(LCD_DATA_PIN_7, GET_BIT(Copy_u8Char,3));
	
	MDIO_voidSetLevelPin(LCD_EN_PIN,HIGH); //EN
	_delay_ms(1);
	MDIO_voidSetLevelPin(LCD_EN_PIN,LOW);
	_delay_ms(5);
	#endif
}
/*==============================================================================*
 * Prototype   : void HLCD_u8WriteString(u8 *P_u8String);						*
 * Description : Send String to LCD												*
 * Arguments   : String : takes String		 									*
 * return      : void															*
 *==============================================================================*/
void HLCD_voidWriteString(u8 *P_u8String)
{
	while(*P_u8String != 0)
	{
		HLCD_voidWriteChar(*P_u8String);
		P_u8String++;
	}
}
/*==============================================================================*
 * Prototype   : void HLCD_voidClearLcd(void);									*
 * Description : Clear LCD Display												*
 * Arguments   : void						 									*
 * return      : void															*
 *==============================================================================*/
void HLCD_voidClearLcd(void)
{
	HLCD_voidWriteCommand(0x01);
}
void HLCD_voidGotoPlace(u8 Copy_u8Row,u8 Copy_u8Col)
{
	u8 arr[4] ={0x80,0xC0,0x90,0xD0};
	HLCD_voidWriteCommand(arr[Copy_u8Row] + Copy_u8Col);
		
}
void HLCD_voidWriteNumber(s32 Copy_s32Number)
{
	if(Copy_s32Number == 0)
		HLCD_voidWriteChar('0');
	else if(Copy_s32Number > 0  )
	{
		s8 i=0;
	    u8 remander = 0;
	    u8 arr[10] = {0};
	    while(Copy_s32Number != 0)
	    {
	    	remander = Copy_s32Number % 10;
	    	arr[i]=remander;
	    	i++;
	    	Copy_s32Number /= 10;
	    }
	    i--;
	    while(i >= 0)
	    {
	    	HLCD_voidWriteChar(arr[i] + 48);
	    	i--;	
	    }
	    
	}
	

}
void HLCD_voidWriteRealNumber(f32 Copy_f32Number)
{
	if(Copy_f32Number == 0)
		HLCD_voidWriteChar(48);
	else 
	{
		s8 i=0;
		u8 remander = 0;
		u8 arr[10] = {0};
		u32 Copy_u32Number = (u32) Copy_f32Number;
		u32 y = Copy_u32Number;
		while(Copy_u32Number != 0)
		{
			remander = Copy_u32Number % 10;
			arr[i]=remander;
			i++;
			Copy_u32Number /= 10;
		}
		i--;
		while(i >= 0)
		{
			HLCD_voidWriteChar(arr[i] + 48);
			i--;
		}
		HLCD_voidWriteChar('.');
		u32 x = (Copy_f32Number - y)*1000.0;
		while(x != 0)
		{
			remander =  x % 10;
			arr[i]=remander;
			i++;
			x /= 10;
		}
		i--;
		while(i >= 0)
		{
			HLCD_voidWriteChar(arr[i] + 48);
			i--;
		}
		
	}
}
void HLCD_voidMoveString(u8 *P_u8String)
{
	for(u8 i = 0;i <= 15;i++)
	{
		for(u8 j = 0;j <= i;j++)
		{
			HLCD_voidWriteChar(' ');
		}
		HLCD_voidWriteString(*P_u8String);
		_delay_ms(100);
		HLCD_voidClearLcd();
	}
}
