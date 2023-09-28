/************ LIB  **********/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/************ MCAL **********/
#include "I2C_CONFIG.h"
#include "I2C_PRIVATE.h"
#include "I2C_INTERFACE.h"

void MI2C_voidInit(void)
{
	TWBR = 0x02;
	CLR_BIT(TWSR , 0);
	CLR_BIT(TWSR , 1);
	SET_BIT(TWCR , 6);
	SET_BIT(TWCR , 2);
}
void MI2C_SendStartCondition(void)
{
	TWCR = (1 << 7) | (1 << 5) | (1 << 2);
	while(GET_BIT(TWCR,7)==0);
}
void MI2C_SendRepeatedStartCondition(void)
{
	TWCR = (1 << 7) | (1 << 5) | (1 << 2);
	while(GET_BIT(TWCR,7)==0);
}
void MI2C_SendStopCondition(void)
{
	SET_BIT(TWCR , 4);
	SET_BIT(TWCR , 7);
	SET_BIT(TWCR , 2);
}

void MI2C_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress)
{
	TWDR = (Copy_u8SlaveAddress);
	CLR_BIT(TWDR , 0);
	SET_BIT(TWCR , 7);
	while(GET_BIT(TWCR , 7) == 0);
}
void MI2C_SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress)
{
	TWDR = (Copy_u8SlaveAddress);
	SET_BIT(TWDR , 0);
	SET_BIT(TWCR , 7);
	while(GET_BIT(TWCR , 7) == 0);
}

void MI2C_MasterWriteDataByte(u8 Copy_u8DataByte)
{
	TWDR = Copy_u8DataByte;
	TWCR = (1 << 7) | (1 << 2);
	while(GET_BIT(TWCR,7)==0);
}
u8 MI2C_MasterReadDataByte(void)
{
	TWCR = (1 << 7) | (1 << 2) ;
	while(GET_BIT(TWCR,7)==0);
	return TWDR;
}

void EEPROM_voidInit(void)
{
	MI2C_voidInit();
}
void EEPROM_voidWrite_Byte(u8 Copy_u8AddressSlave ,u8 Copy_u8AddressLocation,u8 Copy_u8Data)
{
	MI2C_SendStartCondition();
	//write the device address and so we need to get A2 A1 A0 address bits and R/W=0 (write)
	//I2C_voidMasterWriteDataByte(Copy_u8AddressSlave);   // 1010 A2 A1 A0  W
	MI2C_SendSlaveAddressWithWrite(Copy_u8AddressSlave);

	//send the required location address
	MI2C_MasterWriteDataByte(Copy_u8AddressLocation);  // 0000 0000

	//write byte to eeprom
	MI2C_MasterWriteDataByte(Copy_u8Data);

	MI2C_SendStopCondition();
}
void EEPROM_u8Read_Byte(u8 Copy_u8AddressSlave ,u8 Copy_u8AddressLocation, u8 *Copy_u8Data)
{

	MI2C_SendStartCondition();

	//write the device address and so we need to get A2 A1 A0 address bits and R/W=0 (write)
	MI2C_SendSlaveAddressWithWrite(Copy_u8AddressSlave);  //1010 A2 A1 A0 W  // 1010 0000

	//send the required location address
	MI2C_MasterWriteDataByte(Copy_u8AddressLocation); // 0000 0000

	//send a repeated start
	MI2C_SendRepeatedStartCondition();                 // REPEATED START

	//write the device address and so we need to get A2 A1 A0 address bits and R/W=1 (Read)
	//SET_BIT(Copy_u8AddressSlave,0);                  //
	//I2C_voidMasterWriteDataByte(Copy_u8AddressSlave);   //1010 0001
	MI2C_SendSlaveAddressWithRead(Copy_u8AddressSlave);

	 *Copy_u8Data = MI2C_MasterReadDataByte();  //NACK

	MI2C_SendStopCondition();
}


