/*==================================================================================*
 * File        : SSD_PROGRAM.c														*
 * Description : This file includes SSD Driver implementations 						*
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
#include "../../03-MCAL/01-DIO/DIO_INTERFACE.h"

/************ HAL **********/
#include "SSD_CONFIG.h"
#include "SSD_PRIVATE.h"
#include "SSD_INTERFACE.h"

void HSSD_voidInitSSD(void)
{
	MDIO_voidSetPinDirection(DIO_u8_PORTB ,DIO_u8_PIN0, DIO_u8_OUTPUT);
	MDIO_voidSetPinDirection(DIO_u8_PORTB ,DIO_u8_PIN1, DIO_u8_OUTPUT);
	MDIO_voidSetPinDirection(DIO_u8_PORTB ,DIO_u8_PIN2, DIO_u8_OUTPUT);
	MDIO_voidSetPinDirection(DIO_u8_PORTB ,DIO_u8_PIN4, DIO_u8_OUTPUT);

	MDIO_voidSetPinDirection(DIO_u8_PORTB ,DIO_u8_PIN6, DIO_u8_OUTPUT);
	MDIO_voidSetPinDirection(DIO_u8_PORTB ,DIO_u8_PIN5, DIO_u8_OUTPUT);
	MDIO_voidSetPinDirection(DIO_u8_PORTA ,DIO_u8_PIN2, DIO_u8_OUTPUT);
	MDIO_voidSetPinDirection(DIO_u8_PORTA ,DIO_u8_PIN3, DIO_u8_OUTPUT);

}
void HSSD_voidDisplayDigitSSD(u8 Copy_u8Number,u8 Copy_u8SSD)
{
	switch(Copy_u8SSD)
	{
	case ONES_T:
		MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN6, DIO_u8_LOW);
		MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN5, DIO_u8_LOW);
		MDIO_voidSetPinValue(DIO_u8_PORTA ,DIO_u8_PIN2, DIO_u8_LOW);
		MDIO_voidSetPinValue(DIO_u8_PORTA ,DIO_u8_PIN3, DIO_u8_HIGH);
		switch(Copy_u8Number)
		{
		case 0:
			MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN0, DIO_u8_LOW);
			MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN1, DIO_u8_LOW);
			MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN2, DIO_u8_LOW);
			MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN4, DIO_u8_LOW);
			break;						 
		case 1:
			MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN0, DIO_u8_HIGH);
			MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN1, DIO_u8_LOW);
			MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN2, DIO_u8_LOW);
			MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN4, DIO_u8_LOW);
			break;						  
		case 2:
			MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN0, DIO_u8_LOW);
			MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN1, DIO_u8_HIGH);
			MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN2, DIO_u8_LOW);
			MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN4, DIO_u8_LOW);
			break;						 
		case 3:
			MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN0, DIO_u8_HIGH);
			MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN1, DIO_u8_HIGH);
			MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN2, DIO_u8_LOW);
			MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN4, DIO_u8_LOW);
			break;						  
		case 4:
			MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN0, DIO_u8_LOW);
			MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN1, DIO_u8_LOW);
			MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN2, DIO_u8_HIGH);
			MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN4, DIO_u8_LOW);
			break;						 
		case 5:
			MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN0, DIO_u8_HIGH);
			MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN1, DIO_u8_LOW);
			MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN2, DIO_u8_HIGH);
			MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN4, DIO_u8_LOW);
			break;						  
		case 6:
			MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN0, DIO_u8_LOW);
			MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN1, DIO_u8_HIGH);
			MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN2, DIO_u8_HIGH);
			MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN4, DIO_u8_LOW);
			break;						  
		case 7:
			MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN0, DIO_u8_HIGH);
			MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN1, DIO_u8_HIGH);
			MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN2, DIO_u8_HIGH);
			MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN4, DIO_u8_LOW);
			break;						  
		case 8:
			MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN0, DIO_u8_LOW);
			MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN1, DIO_u8_LOW);
			MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN2, DIO_u8_LOW);
			MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN4, DIO_u8_HIGH);
			break;						  
		case 9:
			MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN0, DIO_u8_HIGH);
			MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN1, DIO_u8_LOW);
			MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN2, DIO_u8_LOW);
			MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN4, DIO_u8_HIGH);
			break;
		default:
			break;
		}
		break;
		case TENS_T:
			MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN6, DIO_u8_LOW);
			MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN5, DIO_u8_LOW);
			MDIO_voidSetPinValue(DIO_u8_PORTA ,DIO_u8_PIN2, DIO_u8_HIGH);
			MDIO_voidSetPinValue(DIO_u8_PORTA ,DIO_u8_PIN3, DIO_u8_LOW);
			switch(Copy_u8Number)
			{
			case 0:
				MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN0, DIO_u8_LOW);
				MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN1, DIO_u8_LOW);
				MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN2, DIO_u8_LOW);
				MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN4, DIO_u8_LOW);
				break;
			case 1:						 
				MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN0, DIO_u8_HIGH);
				MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN1, DIO_u8_LOW);
				MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN2, DIO_u8_LOW);
				MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN4, DIO_u8_LOW);
				break;
			case 2:						  
				MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN0, DIO_u8_LOW);
				MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN1, DIO_u8_HIGH);
				MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN2, DIO_u8_LOW);
				MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN4, DIO_u8_LOW);
				break;
			case 3:						 
				MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN0, DIO_u8_HIGH);
				MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN1, DIO_u8_HIGH);
				MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN2, DIO_u8_LOW);
				MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN4, DIO_u8_LOW);
				break;
			case 4:						  
				MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN0, DIO_u8_LOW);
				MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN1, DIO_u8_LOW);
				MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN2, DIO_u8_HIGH);
				MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN4, DIO_u8_LOW);
				break;
			case 5:						 
				MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN0, DIO_u8_HIGH);
				MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN1, DIO_u8_LOW);
				MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN2, DIO_u8_HIGH);
				MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN4, DIO_u8_LOW);
				break;
			case 6:						  
				MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN0, DIO_u8_LOW);
				MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN1, DIO_u8_HIGH);
				MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN2, DIO_u8_HIGH);
				MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN4, DIO_u8_LOW);
				break;
			case 7:						  
				MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN0, DIO_u8_HIGH);
				MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN1, DIO_u8_HIGH);
				MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN2, DIO_u8_HIGH);
				MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN4, DIO_u8_LOW);
				break;
			case 8:						  
				MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN0, DIO_u8_LOW);
				MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN1, DIO_u8_LOW);
				MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN2, DIO_u8_LOW);
				MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN4, DIO_u8_HIGH);
				break;
			case 9:						  
				MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN0, DIO_u8_HIGH);
				MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN1, DIO_u8_LOW);
				MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN2, DIO_u8_LOW);
				MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN4, DIO_u8_HIGH);
				break;
			default:
				break;
			}
			break;
			case HUNDREDS_T:
				MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN6, DIO_u8_LOW);
				MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN5, DIO_u8_HIGH);
				MDIO_voidSetPinValue(DIO_u8_PORTA ,DIO_u8_PIN2, DIO_u8_LOW);
				MDIO_voidSetPinValue(DIO_u8_PORTA ,DIO_u8_PIN3, DIO_u8_LOW);
				switch(Copy_u8Number)
				{
				case 0:
					MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN0, DIO_u8_LOW);
					MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN1, DIO_u8_LOW);
					MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN2, DIO_u8_LOW);
					MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN4, DIO_u8_LOW);
					break;
				case 1:
					MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN0, DIO_u8_HIGH);
					MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN1, DIO_u8_LOW);
					MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN2, DIO_u8_LOW);
					MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN4, DIO_u8_LOW);
					break;
				case 2:
					MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN0, DIO_u8_LOW);
					MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN1, DIO_u8_HIGH);
					MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN2, DIO_u8_LOW);
					MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN4, DIO_u8_LOW);
					break;
				case 3:
					MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN0, DIO_u8_HIGH);
					MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN1, DIO_u8_HIGH);
					MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN2, DIO_u8_LOW);
					MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN4, DIO_u8_LOW);
					break;
				case 4:
					MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN0, DIO_u8_LOW);
					MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN1, DIO_u8_LOW);
					MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN2, DIO_u8_HIGH);
					MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN4, DIO_u8_LOW);
					break;
				case 5:
					MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN0, DIO_u8_HIGH);
					MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN1, DIO_u8_LOW);
					MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN2, DIO_u8_HIGH);
					MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN4, DIO_u8_LOW);
					break;
				case 6:
					MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN0, DIO_u8_LOW);
					MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN1, DIO_u8_HIGH);
					MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN2, DIO_u8_HIGH);
					MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN4, DIO_u8_LOW);
					break;
				case 7:
					MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN0, DIO_u8_HIGH);
					MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN1, DIO_u8_HIGH);
					MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN2, DIO_u8_HIGH);
					MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN4, DIO_u8_LOW);
					break;
				case 8:
					MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN0, DIO_u8_LOW);
					MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN1, DIO_u8_LOW);
					MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN2, DIO_u8_LOW);
					MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN4, DIO_u8_HIGH);
					break;
				case 9:
					MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN0, DIO_u8_HIGH);
					MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN1, DIO_u8_LOW);
					MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN2, DIO_u8_LOW);
					MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN4, DIO_u8_HIGH);
					break;
				default:
					break;
				}
				break;
				case THOUSANDS_T:
					MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN6, DIO_u8_HIGH);
					MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN5, DIO_u8_LOW);
					MDIO_voidSetPinValue(DIO_u8_PORTA ,DIO_u8_PIN2, DIO_u8_LOW);
					MDIO_voidSetPinValue(DIO_u8_PORTA ,DIO_u8_PIN3, DIO_u8_LOW);
					switch(Copy_u8Number)
					{
					case 0:
						MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN0, DIO_u8_LOW);
						MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN1, DIO_u8_LOW);
						MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN2, DIO_u8_LOW);
						MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN4, DIO_u8_LOW);
						break;
					case 1:
						MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN0, DIO_u8_HIGH);
						MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN1, DIO_u8_LOW);
						MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN2, DIO_u8_LOW);
						MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN4, DIO_u8_LOW);
						break;
					case 2:
						MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN0, DIO_u8_LOW);
						MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN1, DIO_u8_HIGH);
						MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN2, DIO_u8_LOW);
						MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN4, DIO_u8_LOW);
						break;
					case 3:
						MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN0, DIO_u8_HIGH);
						MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN1, DIO_u8_HIGH);
						MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN2, DIO_u8_LOW);
						MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN4, DIO_u8_LOW);
						break;
					case 4:
						MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN0, DIO_u8_LOW);
						MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN1, DIO_u8_LOW);
						MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN2, DIO_u8_HIGH);
						MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN4, DIO_u8_LOW);
						break;
					case 5:
						MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN0, DIO_u8_HIGH);
						MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN1, DIO_u8_LOW);
						MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN2, DIO_u8_HIGH);
						MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN4, DIO_u8_LOW);
						break;
					case 6:
						MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN0, DIO_u8_LOW);
						MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN1, DIO_u8_HIGH);
						MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN2, DIO_u8_HIGH);
						MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN4, DIO_u8_LOW);
						break;
					case 7:
						MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN0, DIO_u8_HIGH);
						MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN1, DIO_u8_HIGH);
						MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN2, DIO_u8_HIGH);
						MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN4, DIO_u8_LOW);
						break;
					case 8:
						MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN0, DIO_u8_LOW);
						MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN1, DIO_u8_LOW);
						MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN2, DIO_u8_LOW);
						MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN4, DIO_u8_HIGH);
						break;
					case 9:
						MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN0, DIO_u8_HIGH);
						MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN1, DIO_u8_LOW);
						MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN2, DIO_u8_LOW);
						MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN4, DIO_u8_HIGH);
						break;
					default:
						break;
					}
					break;
					default:
						break;
	}
}

void HSSD_voidDisplaySSD(u16 Copy_u16FullNumber)
{
	for(u8 Local_u8Counter = 0 ; Local_u8Counter < 5 ; Local_u8Counter++)
	{
		//		u8 Local_u8NumberThousands= Copy_u16FullNumber / 1000;
		//		u8 Local_u8NumberHundreds= (Copy_u16FullNumber / 100) % 10;
		u8 Local_u8NumberTens= (Copy_u16FullNumber / 10) % 10;
		u8 Local_u8NumberOnes= Copy_u16FullNumber % 10;

		//		HSSD_voidDisplayDigitSSD(Local_u8NumberThousands,THOUSANDS_T);
		//		_delay_ms(1);
		//		HSSD_voidDisplayDigitSSD(Local_u8NumberHundreds,HUNDREDS_T);
		//		_delay_ms(1);
		HSSD_voidDisplayDigitSSD(Local_u8NumberTens,TENS_T);
		_delay_ms(1);
		HSSD_voidDisplayDigitSSD(Local_u8NumberOnes,ONES_T);
		_delay_ms(1);
		//_delay_ms(500);
	}
	MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN6, DIO_u8_LOW);
	MDIO_voidSetPinValue(DIO_u8_PORTB ,DIO_u8_PIN5, DIO_u8_LOW);
	MDIO_voidSetPinValue(DIO_u8_PORTA ,DIO_u8_PIN2, DIO_u8_LOW);
	MDIO_voidSetPinValue(DIO_u8_PORTA ,DIO_u8_PIN3, DIO_u8_LOW);
}

void HSSD_voidCountDownSSD(u16 Copy_u16FullNumber)
{
	for(u16 Local_u16Counter = Copy_u16FullNumber ; Local_u16Counter >= 0 ; Local_u16Counter--)
	{
		HSSD_voidDisplaySSD(Local_u16Counter);
		if(Local_u16Counter == 0)
			break;
	}
}
void HSSD_voidCountUpSSD(u16 Copy_u16FullNumber)
{
	for(u16 Local_u16Counter = Copy_u16FullNumber ; Local_u16Counter <= 9999 ; Local_u16Counter++)
	{
		HSSD_voidDisplaySSD(Local_u16Counter);
		if(Local_u16Counter == 9999)
			break;
	}
}
