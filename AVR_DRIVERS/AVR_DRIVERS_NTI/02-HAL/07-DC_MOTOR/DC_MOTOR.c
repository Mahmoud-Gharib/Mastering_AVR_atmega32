

#include "../07-DC_MOTOR/DC_MOTOR.h"

#include "../../03-MCAL/01-DIO/DIO.h"
#include "../../03-MCAL/04-TIMER0/TIMER0.h"
#include "../07-DC_MOTOR/DC_MOTOR_CFG.h"

void DC_MOTOR_INIT(void)
{
	MDIO_voidSetDirectionPin(DC_MOTOR_PINA,OUTPUT);
	MDIO_voidSetDirectionPin(DC_MOTOR_PINB,OUTPUT);
	pwm_0_Init();
}
void DC_MOTOR_SET_SPEED(u16 speed)
{
	pwm_0_SetDutyCycle(speed);
}
void DC_MOTOR_DIRECTION(u8 dir)
{
	if(dir == CLK)
	{
		MDIO_voidSetLevelPin(DC_MOTOR_PINA,HIGH);
		MDIO_voidSetLevelPin(DC_MOTOR_PINB,LOW);
	}
	else if(dir == A_CLK)
	{
		MDIO_voidSetLevelPin(DC_MOTOR_PINA,LOW);
		MDIO_voidSetLevelPin(DC_MOTOR_PINB,HIGH);
	}
}
void DC_MOTOR_START(void)
{
	pwm_0_Start();
}
void DC_MOTOR_STOP(void)
{
	pwm_0_Stop();
}
