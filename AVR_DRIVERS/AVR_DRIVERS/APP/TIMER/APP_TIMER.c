/************ LIB  **********/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "avr/delay.h"

/************ MCAL **********/
#include "../../MCAL/DIO/DIO_INTERFACE.h"

#include "../../MCAL/TIMER/TIMER_INTERFACE.h"

/************ HAL **********/
#include "../../HAL/LCD/LCD_INTERFACE.h"


#define    CODE               7

#if      CODE       ==        0
void main(void)
{
	HLCD_voidInit();
	TIMER0_voidInit(DISCONNECT , NORMAL_MODE , PRESCALER_DIV_BY_8);
	//TIMER0_voiduSetTimerValue(0);
	_delay_us(10);
	HLCD_voidDisplayNumber( TIMER0_u8ReadTimerValue() );
	while(1)
	{

	}
}
#elif      CODE       == 			1
void main(void)
{
	MDIO_voidSetPinDirection(DIO_PORTB,DIO_PIN3,DIO_OUTPUT);

	TIMER0_voidInit(NON_INVERTING , PHASECHORECT_MODE , PRESCALER_DIV_BY_8);
	u8 x = 0;
	while(1)
	{
		TIMER0_voidSetCompareMatchValue(x);
		_delay_ms(10);
		x++;
		if( x == 150)
			x = 0;
	}
}

#elif      CODE       == 			1
void main(void)
{
	MDIO_voidSetPinDirection(DIO_PORTD,DIO_PIN5,DIO_OUTPUT);

	TIMER1_voidInit(TIMER1_CHANNEL_A , NON_INVERTING , FASTPWM_MODE , PRESCALER_DIV_BY_8);
	u16 x = 0;
	while(1)
	{
		TIMER1_voidSetCompareMatchValue(TIMER1_CHANNEL_A , x);
		_delay_ms(10);
		x++;
		if( x == 150)
			x = 0;
	}
}

#elif   CODE			==   		2
void main(void)
{
	HLCD_voidInit();
	MDIO_voidSetPinDirection(DIO_PORTD,DIO_PIN5,DIO_OUTPUT);

	TIMER1_voidSetMode_14(TIMER1_CHANNEL_A , NON_INVERTING, PRESCALER_DIV_BY_8);
	TIMER1_voidSetTopValueMode_14(20000);
	u8 Angle = 0 ;
	while(1)
	{
		HLCD_voidGoToPosition(1,1);
		HLCD_voidSendString("Angle :");
		HLCD_voidDisplayNumber(Angle);
		TIMER1_voidSetCompareMatchValue(TIMER1_CHANNEL_A , (Angle * 1000UL / 180) + 1000);
		_delay_ms(1000);
		if(Angle == 180)
		{
           break;
		}
		Angle += 10;
	}
}

#elif   CODE			==   		3
static u16 Ttot    = 0;
static u16 Ton     = 0;

void ICU_HW(void);

void main(void)
{
	HLCD_voidInit();

	MDIO_voidSetPinDirection(DIO_PORTD,DIO_PIN6,DIO_INPUT);
	MDIO_voidSetPinDirection(DIO_PORTB,DIO_PIN3,DIO_OUTPUT);
	TIMER0_voidInit(NON_INVERTING , FASTPWM_MODE , PRESCALER_DIV_BY_8);
	TIMER0_voidSetCompareMatchValue(50);


	TIMER_voidSetCallBack(TIMER1_ICU_INT , &ICU_HW);
	ICU_voidInit();

	while(1)
	{

		while((Ttot == 0) && (Ton == 0));
		HLCD_voidGoToPosition(1,1);
		HLCD_voidSendString("Ttot :");
		HLCD_voidDisplayNumber(Ttot);
		HLCD_voidGoToPosition(2,1);
		HLCD_voidSendString("Ton :");
		HLCD_voidDisplayNumber(Ton);
		_delay_ms(100000);

	}
}

void ICU_HW(void)
{
	static u16 R1 , R2 , R3;
	static u8 Counter = 1;

	if(Counter == 1)
	{
		R1 = ICU_u16ReadICU();
		Counter = 2;
	}
	else if (Counter == 2)
	{
		R2 = ICU_u16ReadICU();
		Ttot = R2 - R1;
		ICU_SetTriggerEdge(ICU_FALLING_EDGE);
		Counter = 3;
	}
	else if(Counter == 3)
	{
		R3 = ICU_u16ReadICU();
		Ton = R3 - R2;
		Counter = 0;
	}
}

#elif   CODE			==   		4

static u16 Ttot    = 0;
static u16 Ton     = 0;

void ICU_SW(void);

void main(void)
{
	HLCD_voidInit();

	MDIO_voidSetPinDirection(DIO_PORTD,DIO_PIN2,DIO_INPUT);

	MDIO_voidSetPinDirection(DIO_PORTB,DIO_PIN3,DIO_OUTPUT);
	TIMER0_voidInit(NON_INVERTING , FASTPWM_MODE , PRESCALER_DIV_BY_8);
	TIMER0_voidSetCompareMatchValue(250);


	EXT_INT_0_SET_CALL_BACK(&ICU_SW);
	TIMER1_voidInit(TIMER1_CHANNEL_A,0,NORMAL_MODE,PRESCALER_DIV_BY_8);
	MEXTI_voidEXTIEnable(EXT_INT_0,RISING_EDGE);
	while(1)
	{

		while((Ttot == 0) && (Ton == 0));
		HLCD_voidGoToPosition(1,1);
		HLCD_voidSendString("Ttot :");
		HLCD_voidDisplayNumber(Ttot);
		HLCD_voidGoToPosition(2,1);
		HLCD_voidSendString("Ton :");
		HLCD_voidDisplayNumber(Ton);
		_delay_ms(100000);

	}
}

void ICU_SW(void)
{
	static u16 R1 , R2 , R3;
	static u8 Counter = 1;

	if(Counter == 1)
	{
		//R1 = TIMER1_voidu16ReadTimerValue();
		TIMER1_voiduSetTimerValue(0);
		Counter = 2;
	}
	else if (Counter == 2)
	{
		R2 = TIMER1_voidu16ReadTimerValue();
		Ttot = R2  ; //- R1
		TIMER1_voiduSetTimerValue(0);

		MEXTI_voidEXTIEnable(EXT_INT_0,FALLING_EDGE);
		Counter = 3;

	}
	else if(Counter == 3)
	{
		R3 = TIMER1_voidu16ReadTimerValue();
		Ton = R3; //- R2;
		MEXTI_voidEXTIDisable(EXT_INT_0);
		Counter = 0;
	}
}
#endif

