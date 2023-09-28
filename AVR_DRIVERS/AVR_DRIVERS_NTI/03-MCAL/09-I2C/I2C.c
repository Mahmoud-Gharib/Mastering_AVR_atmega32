#include "../../00-LIB/BIT_MATH.h"
#include "../REG.h"
#include "I2C_CFG.h"
#include "I2C.h" 

void I2C_INIT(void)
{
	#if   I2C_MODE == MASTER
	TWBR = ((((CRYSTAL_FREQ *1000) / SCL_FREQ)  - 16) / 2);
	
	#elif I2C_MODE == SLAVE
	TWAR = (SLAVE_ADDRESS << 1);
	#endif
	//ENABLE I2C 
	SET_BIT(TWCR,2);
}
void I2C_START_CONDITION(void)
{
	SET_BIT(TWCR,5);
	SET_BIT(TWCR,7); // CLEAR FLAG
	
	while(GET_BIT(TWCR,7) == 0);
	while(TWSR & 0xF8 != START_ACK);
}
void I2C_STOP_CONDITION(void)
{
	SET_BIT(TWCR,7); // CLEAR FLAG
	SET_BIT(TWCR,4);
	//while(GET_BIT(TWCR,7) == 0);

}
void I2C_REPEATED_CONDITION(void)
{
	SET_BIT(TWCR,5);
	SET_BIT(TWCR,7); // CLEAR FLAG
	
	while(GET_BIT(TWCR,7) == 0);
	while(TWSR & 0xF8 != REP_START_ACK);
}
void SEND_SLAVE_ADD_WRITE(u8 address)
{
	TWDR = (address << 1) ;
	SET_BIT(TWCR,7); // CLEAR FLAG
	
	while(GET_BIT(TWCR,7) == 0);
	while(TWSR & 0xF8 != SLAVE_AD_AND_WR_ACK);
}
void SEND_SLAVE_ADD_READ(u8 address)
{
	TWDR = ((address << 1) | 1) ;
	SET_BIT(TWCR,7); // CLEAR FLAG
	
	while(GET_BIT(TWCR,7) == 0);
	while(TWSR & 0xF8 != SLAVE_AD_AND_RD_ACK);
}
void I2C_SEND_BYTE(u8 byte)
{
	TWDR = byte;
	CLR_BIT(TWCR,5);
	SET_BIT(TWCR,7); // CLEAR FLAG
	while(GET_BIT(TWCR,7) == 0);
	while(TWSR & 0xF8 != WR_BYTE_ACK);
}
u8   I2C_READ_BYTE(void)
{
	
	SET_BIT(TWCR,7); // CLEAR FLAG
	while(GET_BIT(TWCR,7) == 0);
	while(TWSR & 0xF8 != RD_BYTE_WITH_ACK);
	return TWDR;
}
