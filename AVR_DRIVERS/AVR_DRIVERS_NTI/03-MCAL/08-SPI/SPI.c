#include <util/delay.h>
#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_MATH.h"
#include "../01-DIO/DIO.h"
#include "../REG.h"
#include "SPI_CFG.h"
#include "SPI.h"

void SPI_INIT(void)
{
	//SENT FROM LSB FIRST
	SET_BIT(SPCR,5);
	#if SPI_MODE == MASTER
	MDIO_voidSetDirectionPin(MOSI,OUTPUT);
	MDIO_voidSetDirectionPin(MISO,INPUT);
	MDIO_voidSetDirectionPin(SS,OUTPUT);
	MDIO_voidSetDirectionPin(SCK,OUTPUT);
	SET_BIT(SPCR,4);
	//
	SET_BIT(SPCR,2);
	//PRESCALER 128
	SET_BIT(SPCR,0);
	SET_BIT(SPCR,1);
	CLR_BIT(SPSR,0);
	_delay_ms(2000);
	#elif   SPI_MODE == SLAVE
	MDIO_voidSetDirectionPin(MOSI,INPUT);
	MDIO_voidSetDirectionPin(MISO,OUTPUT);
	MDIO_voidSetDirectionPin(SS,INPUT);
	MDIO_voidSetDirectionPin(SCK,INPUT);
	CLR_BIT(SPCR,4);
	#endif
	//ENABLE SPI
	SET_BIT(SPCR,6);
}
u8 SPI_TRANSIVE(u8 data)
{
	#if SPI_MODE == MASTER
	MDIO_voidSetLevelPin(SS,LOW);
	SPDR = data;
	while(GET_BIT(SPSR,7) == 0);
	MDIO_voidSetLevelPin(SS,HIGH);
	#elif   SPI_MODE == SLAVE
	SPDR = data;
	while(GET_BIT(SPSR,7) == 0);
	#endif
	return SPDR;
}
