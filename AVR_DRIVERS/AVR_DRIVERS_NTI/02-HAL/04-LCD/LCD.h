/*==================================================================================*
 * File        : LCD.h     														    *
 * Description :This file includes LCD Driver prototypes and macros					*
 * Author      : Mahmoud Gharib Embedded SW Engineer 								*		
 * Date        : 7/2/2022															*		
 * Git account : https://github.com/Mahmoud-Gharib									*		
 * mail        : mahmoudgharib99999@gmil.com 										*		
 *==================================================================================*/
#ifndef LCD_H_
#define LCD_H_

#include "../../00-LIB/STD_TYPES.h"
/*Modes macros*/
#define _4_BIT_MODE  4
#define _8_BIT_MODE  8
/*Prototypes LCD DRIVERS*/
void HLCD_voidInitLcd(void);
void HLCD_voidWriteCommand(u8 Copy_u8Command);
void HLCD_voidWriteChar(u8 Copy_u8Char);
void HLCD_voidWriteString(u8 *P_u8String);

void HLCD_voidClearLcd(void);
void HLCD_voidGotoPlace(u8 Copy_u8Row,u8 Copy_u8Col); 
void HLCD_voidWriteNumber(s32 Copy_s32Number);
void HLCD_voidWriteRealNumber(f32 Copy_f32Number);
void HLCD_voidMoveString(u8 *P_u8String);

#endif 

/*
int main(void)
{
	HLCD_voidInitLcd();
	while (1)
	{
		for(u8 i = 0;i <= 15;i++)
		{
			for(u8 j = 0;j <= i;j++)
			{
				HLCD_u8WriteChar(' ');
			}
			HLCD_u8WriteString("GHARIB");
			_delay_ms(1000);
			HLCD_voidClearLcd();
		}
	}
}
*/

/*
int main(void)
{
	u8 x = 35;
	HLCD_voidInitLcd();
	while (1)
	{
		while(x>0)
		{
			if(x % 2 )
			{	HLCD_voidWriteNumber(x);
				_delay_ms(1000);
				HLCD_voidClearLcd();
			}
			x -= 2;
		}
		
	}
}
*/

/*
int main(void)
{
	u8 num1,num2,res;
	HKEYPAD_voidInitKeypad();
	HLCD_voidInitLcd();
	HLED_voidInitLed(B_LED);
	u8 x = 0;
	u8 loop = 0;
	while(1)
	{
		x = HKEYPAD_u8ReadKeypad();
		if(x)
		{
			switch(x)
			{
				case '+':
				
				HLCD_voidWriteChar('+');
				loop++;
				break;
				case '=':
				HLCD_voidWriteChar('=');
				res = num1 + num2  ;
				HLCD_voidGotoPlace(1,1);
				HLCD_voidWriteNumber(res);
				loop = 0;
				break;
				case 'C':
				HLCD_voidClearLcd();
				loop = 0;
				break;
				default:
				if(x>='0'&&x<='9')
				{
					HLCD_voidWriteChar(x);
					switch(loop)
					{
						case 0:
						num1 = x - 48;
						break;
						case 1:
						num2 = x -48;
						break;
						default:
						break;
					}
				}
				break;
			}
		}
	}
}*/