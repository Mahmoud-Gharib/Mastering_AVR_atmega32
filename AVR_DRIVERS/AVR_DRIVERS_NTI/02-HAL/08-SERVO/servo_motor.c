/*
 * servo_motor.c
 *
 *  Created on: May 25, 2022
 *      Author: Abd El-Rahman
 */

#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_MATH.h"
#include <util/delay.h>

#include "../../03-MCAL/01-DIO/DIO.h"



/*
u16 Local_u16ServoMotorValue = 1000;

void servoInt(void)
{
	//Timer_voidSetPWM(Local_u16ServoMotorValue);
	//Timer_voidInit();
	PWM1_voidSetDutyCycle(Local_u16ServoMotorValue);
	TIMER1_voidInit();
}

void servoStart(void)
{
	while(Local_u16ServoMotorValue < 2000)
	{
		Timer_voidSetPWM(Local_u16ServoMotorValue );
		/* increase the servo motor value by 10 *
		Local_u16ServoMotorValue += 10;
		/* if the servo motor reach the angle 180
		 * then move the servo again at angle 0 *
		if(Local_u16ServoMotorValue > 2000)
		{
			Local_u16ServoMotorValue = 1000;
		}
		_delay_ms(100);
	}
}
*/
void SERVO_MOTOR_INIT(void)
{
	MDIO_voidSetDirectionPin(PD5,OUTPUT);
}

void SERVO_MOTOR_OnOff(void)
{
	MDIO_voidSetLevelPin(PD5,HIGH);
	_delay_us(1000);
	MDIO_voidSetLevelPin(PD5,LOW);
	_delay_ms (1000);

	MDIO_voidSetLevelPin(PD5,HIGH);
	_delay_us(2000);
	MDIO_voidSetLevelPin(PD5,LOW);
	_delay_ms (1000);

	MDIO_voidSetLevelPin(PD5,HIGH);
	_delay_us(1000);
	MDIO_voidSetLevelPin(PD5,LOW);
	_delay_ms (1000);
}
