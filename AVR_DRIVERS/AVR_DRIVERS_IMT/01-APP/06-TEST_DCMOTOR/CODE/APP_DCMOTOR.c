
/************ LIB  **********/
#include "../../../00-LIB/STD_TYPES.h"
#include "../../../00-LIB/BIT_MATH.h"
#include "avr/delay.h"

/************ MCAL **********/
#include "../../../03-MCAL/01-DIO/DIO_INTERFACE.h"

/************ HAL **********/
#include "../../../02-HAL/01-LED/LED_INTERFACE.h"
#include "../../../02-HAL/02-DIP_SWITCH/DIP_INTERFACE.h"
#include "../../../02-HAL/04-LCD/LCD_INTERFACE.h"
#include "../../../02-HAL/05-KEYPAD/KEYPAD_INTERFACE.h"
#include "../../../02-HAL/06-DC_MOTOR/DCMOTOR_INTERFACE.h"

void APP_voidTestDCMOTOR(void)
{
	HDCMOTOR_voidRotateMotor(DIO_u8_PORTB,DIO_u8_PIN6,DIO_u8_PORTB,DIO_u8_PIN7,CLOCKWISE);
	_delay_ms(3000);
	HDCMOTOR_voidRotateMotor(DIO_u8_PORTB,DIO_u8_PIN6,DIO_u8_PORTB,DIO_u8_PIN7,COUNTERCLOCKWISE);
	_delay_ms(3000);
}
