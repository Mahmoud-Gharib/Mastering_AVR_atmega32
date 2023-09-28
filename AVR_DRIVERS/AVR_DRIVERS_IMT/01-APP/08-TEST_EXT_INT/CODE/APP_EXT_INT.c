
/************ LIB  **********/
#include "../../../00-LIB/STD_TYPES.h"
#include "../../../00-LIB/BIT_MATH.h"
#include "avr/delay.h"

/************ MCAL **********/
#include "../../../03-MCAL/01-DIO/DIO_INTERFACE.h"
#include "../../../03-MCAL/02-EXT_INT/EXTI_INTERFACE.h"
#include "../../../03-MCAL/03-ADC/ADC_INTERFACE.h"

/************ HAL **********/
#include "../../../02-HAL/01-LED/LED_INTERFACE.h"
#include "../../../02-HAL/02-DIP_SWITCH/DIP_INTERFACE.h"
#include "../../../02-HAL/04-LCD/LCD_INTERFACE.h"
#include "../../../02-HAL/05-KEYPAD/KEYPAD_INTERFACE.h"
#include "../../../02-HAL/06-DC_MOTOR/DCMOTOR_INTERFACE.h"
#include "../../../02-HAL/07-STEPPER_MOTOR/STEPPER_INTERFACE.h"

void EXT_INT_0_ISRfunction(void);
void EXT_INT_1_ISRfunction(void);
void EXT_INT_2_ISRfunction(void);

void APP_voidTestEXT_INT(void)
{

	MEXTI_voidEXTIEnable(EXT_INT_0,FALLING_EDGE);
	MEXTI_voidEXTIEnable(EXT_INT_1,LOGICAL_CHANGE);
	MEXTI_voidEXTIEnable(EXT_INT_2,RISING_EDGE);

	EXT_INT_0_SET_CALL_BACK(EXT_INT_0_ISRfunction);
	EXT_INT_1_SET_CALL_BACK(EXT_INT_1_ISRfunction);
	EXT_INT_2_SET_CALL_BACK(EXT_INT_2_ISRfunction);
	while (1)
	{

	}
}

void EXT_INT_0_ISRfunction(void)
{
	HLED_voidTurnOn  (DIO_u8_PORTB, DIO_u8_PIN5 );
}

void EXT_INT_1_ISRfunction(void)
{
	HLED_voidTurnOn  (DIO_u8_PORTB, DIO_u8_PIN6 );
}

void EXT_INT_2_ISRfunction(void)
{
	HLED_voidTurnOn  (DIO_u8_PORTB, DIO_u8_PIN7 );
}
