




/************ LIB  **********/
#include "../../../00-LIB/STD_TYPES.h"
#include "../../../00-LIB/BIT_MATH.h"
#include "avr/delay.h"

/************ MCAL **********/
#include "../../../03-MCAL/01-DIO/DIO_INTERFACE.h"

/************ HAL **********/
#include "../../../02-HAL/01-LED/LED_INTERFACE.h"

void APP_voidTestLed(void)
{
	HLED_voidTurnOn  (DIO_u8_PORTB, DIO_u8_PIN4 );
	_delay_ms(1000);
    HLED_voidTurnOff (DIO_u8_PORTB, DIO_u8_PIN4);
    _delay_ms(1000);
}
