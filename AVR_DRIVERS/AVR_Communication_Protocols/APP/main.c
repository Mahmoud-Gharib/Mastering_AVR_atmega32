#include "avr/delay.h"

#include "../MCAL/MDIO/DIO_INTERFACE.h"
#include "../MCAL/MUART/UART_INTERFACE.h"
#include "../MCAL/MSPI/SPI_INTERFACE.h"
#include "../MCAL/MI2C/I2C_INTERFACE.h"

#include "../HAL/HLCD/LCD_INTERFACE.h"
#include "../HAL/HKEYPAD/KEYPAD_INTERFACE.h"

#define UART       -1

#if     UART            ==         1
void main(void)
{
	MDIO_voidSetPinDirection(DIO_PORTD,DIO_PIN0,DIO_INPUT);    //RX PIN ==> PD0
	HLCD_voidInit();
	MUART_voidInit();
	while(1)
	{
		HLCD_voidSendData(MUART_u8ReciveData());
	}

}
#elif   UART            ==         2
void main(void)
{
	MDIO_voidSetPinDirection(DIO_PORTD,DIO_PIN1,DIO_OUTPUT);    //TX PIN ==> PD1

	HLCD_voidInit();
	MUART_voidInit();
	u8 str[20]  = { 0 };
	MUART_voidSendString((u8 *)"MAHMOUD GHARIB");

	while(1)
	{
		MUART_voidReciveString(str);
		HLCD_voidSendString(str);
	}

}
#elif   UART            ==         3
void Func_UART_RX(void)
{
	switch( MUART_u8AsyncReciveData() )
	{
	case '1':
		MDIO_voidSetPortValue(DIO_PORTB , 0b00000011);
		break;
	case '2':
		MDIO_voidSetPortValue(DIO_PORTB , 0b00001111);
		break;
	case '3':
		MDIO_voidSetPortValue(DIO_PORTB , 0b00111111);
		break;
	default:
		MDIO_voidSetPortValue(DIO_PORTB , 0b00000000);
		break;
	}
}
void main(void)
{
	MDIO_voidSetPinDirection(DIO_PORTD , DIO_PIN1,DIO_OUTPUT);  // TX
	MDIO_voidSetPinDirection(DIO_PORTD , DIO_PIN0,DIO_INPUT);   // RX

	MDIO_voidSetPinDirection(DIO_PORTB , DIO_PIN0,DIO_OUTPUT);
	MDIO_voidSetPinDirection(DIO_PORTB , DIO_PIN1,DIO_OUTPUT);
	MDIO_voidSetPinDirection(DIO_PORTB , DIO_PIN2,DIO_OUTPUT);

	MDIO_voidSetPortDirection(DIO_PORTB , 0xFF);

	MUART_voidInit();
	UART_voidIntEnable(UART_RX);
	UART_voidSetCallBack(UART_RX , Func_UART_RX);

	while(1)
	{

		MDIO_voidSetPinValue(DIO_PORTB , DIO_PIN0 , DIO_HIGH);
		MDIO_voidSetPinValue(DIO_PORTB , DIO_PIN1 , DIO_HIGH);
		MDIO_voidSetPinValue(DIO_PORTB , DIO_PIN2 , DIO_HIGH);
		_delay_ms(1000);

		MDIO_voidSetPinValue(DIO_PORTB , DIO_PIN0 , DIO_LOW);
		MDIO_voidSetPinValue(DIO_PORTB , DIO_PIN1 , DIO_LOW);
		MDIO_voidSetPinValue(DIO_PORTB , DIO_PIN2 , DIO_LOW);
		_delay_ms(1000);
	}
}

#elif   UART            ==         4
volatile u8 x = 0;
void Func_UART_TX(void)
{
	x += 10;
	MUART_voidAsyncSendData(x);
	HLCD_voidDisplayNumber(x);
	if(x == 255)
	{
		x = 1;
	}
}
void main(void)
{
	MDIO_voidSetPinDirection(DIO_PORTD , DIO_PIN1,DIO_OUTPUT);  // TX
	MDIO_voidSetPinDirection(DIO_PORTD , DIO_PIN0,DIO_INPUT);   // RX

	MDIO_voidSetPinDirection(DIO_PORTB , DIO_PIN0,DIO_OUTPUT);
	MDIO_voidSetPinDirection(DIO_PORTB , DIO_PIN1,DIO_OUTPUT);
	MDIO_voidSetPinDirection(DIO_PORTB , DIO_PIN2,DIO_OUTPUT);

	HLCD_voidInit();

	MUART_voidInit();
	UART_voidIntEnable(UART_TX);
	UART_voidSetCallBack(UART_TX , Func_UART_TX);


	while(1)
	{
		MUART_voidAsyncSendData(x);
		MDIO_voidSetPinValue(DIO_PORTB , DIO_PIN0 , DIO_HIGH);
		MDIO_voidSetPinValue(DIO_PORTB , DIO_PIN1 , DIO_HIGH);
		MDIO_voidSetPinValue(DIO_PORTB , DIO_PIN2 , DIO_HIGH);
		_delay_ms(1000);

		MDIO_voidSetPinValue(DIO_PORTB , DIO_PIN0 , DIO_LOW);
		MDIO_voidSetPinValue(DIO_PORTB , DIO_PIN1 , DIO_LOW);
		MDIO_voidSetPinValue(DIO_PORTB , DIO_PIN2 , DIO_LOW);
		_delay_ms(1000);
	}
}

#elif   UART            ==         5
void main(void)
{
	HKEYPAD_voidInit();
	HLCD_voidInit();
	MUART_voidInit();

	u8 Local_u8Number = 0;

	while(1)
	{
		Local_u8Number = HKEYPAD_u8GetPressedKey();
		MUART_voidSendData(Local_u8Number);

		Local_u8Number = MUART_u8ReciveData();
		if(Local_u8Number != 0)
		{
			HLCD_voidGoToPosition(0,5);
			HLCD_voidDisplayNumber(Local_u8Number);
		}
	}
}
#endif


#define SPI       -1

#if     SPI            ==         1
void main(void)    //MASTER
{
	MSPI_voidInit();
	MDIO_voidSetPinDirection(DIO_PORTB,DIO_PIN4,DIO_OUTPUT);   // SS
	MDIO_voidSetPinDirection(DIO_PORTB,DIO_PIN5,DIO_OUTPUT);   // MOSI
	MDIO_voidSetPinDirection(DIO_PORTB,DIO_PIN6,DIO_INPUT);   // MISO
	MDIO_voidSetPinDirection(DIO_PORTB,DIO_PIN7,DIO_OUTPUT);   //CLK

	MDIO_voidSetPinDirection(DIO_PORTD,DIO_PIN0,DIO_INPUT);
	MDIO_voidSetPinValue(DIO_PORTB , DIO_PIN4 , DIO_HIGH);
	while(1)
	{
		if( MDIO_u8GetPinValue(DIO_PORTD,DIO_PIN0) == 0)
		{
			MDIO_voidSetPinValue(DIO_PORTB , DIO_PIN4 , DIO_LOW);
			MSPI_voidSendData(5);
			MDIO_voidSetPinValue(DIO_PORTB , DIO_PIN4 , DIO_HIGH);
		}
		else
		{
			MDIO_voidSetPinValue(DIO_PORTB , DIO_PIN4 , DIO_LOW);
			MSPI_voidSendData(6);
			MDIO_voidSetPinValue(DIO_PORTB , DIO_PIN4 , DIO_HIGH);
		}

	}

}
#elif   SPI            ==         2
void main(void)    //SLAVE
{
	MSPI_voidInit();
	MDIO_voidSetPinDirection(DIO_PORTB,DIO_PIN4,DIO_INPUT);
	MDIO_voidSetPinDirection(DIO_PORTB,DIO_PIN5,DIO_INPUT);   // MOSI
	MDIO_voidSetPinDirection(DIO_PORTB,DIO_PIN6,DIO_OUTPUT);   // MISO
	MDIO_voidSetPinDirection(DIO_PORTB,DIO_PIN7,DIO_INPUT);   //CLK

	MDIO_voidSetPinDirection(DIO_PORTD,DIO_PIN0,DIO_OUTPUT);
	MDIO_voidSetPinDirection(DIO_PORTD,DIO_PIN1,DIO_OUTPUT);

	while(1)
	{
		if( MSPI_u8ReciveData() == 5)
		{
			MDIO_voidSetPinValue(DIO_PORTD , DIO_PIN0 , DIO_HIGH);
			MDIO_voidSetPinValue(DIO_PORTD , DIO_PIN1 , DIO_LOW);
		}
		else if( MSPI_u8ReciveData() == 6 )
		{
			MDIO_voidSetPinValue(DIO_PORTD , DIO_PIN1 , DIO_HIGH);
			MDIO_voidSetPinValue(DIO_PORTD , DIO_PIN0 , DIO_LOW);
		}

	}

}

#elif   SPI            ==         3
void main(void)    //MASTER
{
	MSPI_voidInit();
	MDIO_voidSetPinDirection(DIO_PORTB,DIO_PIN4,DIO_OUTPUT);   // SS
	MDIO_voidSetPinDirection(DIO_PORTB,DIO_PIN5,DIO_OUTPUT);   // MOSI
	MDIO_voidSetPinDirection(DIO_PORTB,DIO_PIN6,DIO_INPUT);   // MISO
	MDIO_voidSetPinDirection(DIO_PORTB,DIO_PIN7,DIO_OUTPUT);   //CLK

	MDIO_voidSetPinValue(DIO_PORTB , DIO_PIN4 , DIO_HIGH);
	while(1)
	{

		MDIO_voidSetPinValue(DIO_PORTB , DIO_PIN4 , DIO_LOW);
		MSPI_voidSendData(5);
		MDIO_voidSetPinValue(DIO_PORTB , DIO_PIN4 , DIO_HIGH);
		_delay_ms(5000);
		MDIO_voidSetPinValue(DIO_PORTB , DIO_PIN4 , DIO_LOW);
		MSPI_voidSendData(6);
		MDIO_voidSetPinValue(DIO_PORTB , DIO_PIN4 , DIO_HIGH);
		_delay_ms(5000);
		MDIO_voidSetPinValue(DIO_PORTB , DIO_PIN4 , DIO_LOW);
		MSPI_voidSendData(7);
		MDIO_voidSetPinValue(DIO_PORTB , DIO_PIN4 , DIO_HIGH);
		_delay_ms(5000);
	}

}
#elif   SPI            ==         4
#include "../MCAL/MSPI/SPI_PRIVATE.h"
void Func_SPI_RX(void)
{
	switch( MSPI_u8AsyncReciveData() )
	{
	case 5:
		MDIO_voidSetPortValue(DIO_PORTD , 0b00000011);
		break;
	case 6:
		MDIO_voidSetPortValue(DIO_PORTD , 0b00001111);
		break;
	case 7:
		MDIO_voidSetPortValue(DIO_PORTD , 0b00111111);
		break;
	default:
		MDIO_voidSetPortValue(DIO_PORTD , 0b00000000);
		break;
	}
	// Clear the interrupt flag
	u8 dummy = SPSR;
	dummy = SPDR;
}
void main(void)
{


	MDIO_voidSetPinDirection(DIO_PORTC , DIO_PIN0,DIO_OUTPUT);
	MDIO_voidSetPinDirection(DIO_PORTC , DIO_PIN1,DIO_OUTPUT);
	MDIO_voidSetPinDirection(DIO_PORTC , DIO_PIN2,DIO_OUTPUT);

	MDIO_voidSetPortDirection(DIO_PORTD , 0xFF);

	MDIO_voidSetPinDirection(DIO_PORTB,DIO_PIN4,DIO_OUTPUT);   // SS
	MDIO_voidSetPinDirection(DIO_PORTB,DIO_PIN5,DIO_OUTPUT);   // MOSI
	MDIO_voidSetPinDirection(DIO_PORTB,DIO_PIN6,DIO_INPUT);   // MISO
	MDIO_voidSetPinDirection(DIO_PORTB,DIO_PIN7,DIO_OUTPUT);   //CLK

	MSPI_voidInit();
	MSPI_voidIntEnable();
	MSPI_voidSetCallBack(Func_SPI_RX);

	while(1)
	{
		MDIO_voidSetPinValue(DIO_PORTC , DIO_PIN0 , DIO_HIGH);
		MDIO_voidSetPinValue(DIO_PORTC , DIO_PIN1 , DIO_HIGH);
		MDIO_voidSetPinValue(DIO_PORTC , DIO_PIN2 , DIO_HIGH);
		_delay_ms(1000);

		MDIO_voidSetPinValue(DIO_PORTC , DIO_PIN0 , DIO_LOW);
		MDIO_voidSetPinValue(DIO_PORTC , DIO_PIN1 , DIO_LOW);
		MDIO_voidSetPinValue(DIO_PORTC , DIO_PIN2 , DIO_LOW);
		_delay_ms(1000);
	}
}
#endif





#define I2C       -1

#if     I2C            ==         1
void main (void)
{
	MDIO_voidSetPinDirection(DIO_PORTA,DIO_PIN0,DIO_OUTPUT);    //LED
	EEPROM_voidInit();
	_delay_ms(1000);
	EEPROM_voidWrite_Byte(0b10100000,0b00000001,4);
	_delay_ms(1000);
	EEPROM_voidWrite_Byte(0b10100000,0b00000010,5);
	_delay_ms(1000);

	u8 STATE = 0;
	u8 Address = 0b00000001;
	while(1)
	{
		_delay_ms(1000);
		EEPROM_u8Read_Byte(0b10100000,Address, &STATE);
		_delay_ms(1000);
		if(STATE == 4)
		{
			MDIO_voidSetPinValue(DIO_PORTA,DIO_PIN0,DIO_HIGH);
			Address++;
		}
		else if(STATE == 5)
		{
			MDIO_voidSetPinValue(DIO_PORTA,DIO_PIN0,DIO_LOW);
			Address--;
		}

	}
}
#endif


#define COM       1

#if     COM            ==         1
void main(void)
{
	MDIO_voidSetPinDirection(DIO_PORTD,DIO_PIN0,DIO_INPUT);    //RX PIN ==> PD0
	MUART_voidInit();

	EEPROM_voidInit();
	//_delay_ms(1000);

	HLCD_voidInit();
	u8 Local_Data = 0,Address = 0b00000000;
	while(1)
	{
		//		Local_Data = MUART_u8ReciveData();
		//		EEPROM_voidWrite_Byte(0b10100000,Address,Local_Data);
		//		HLCD_voidSendData(Local_Data);
		EEPROM_u8Read_Byte(0b10100000,Address, &Local_Data);
		HLCD_voidGoToPosition(0,1);
		HLCD_voidSendData(Local_Data);
		_delay_ms(10);
		Address++;
	}

}

#endif





