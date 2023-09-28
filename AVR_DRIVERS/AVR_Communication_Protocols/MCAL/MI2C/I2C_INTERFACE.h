#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_


/*********** Prototypes I2C DRIVERS **************/

void MI2C_voidInit(void);
void MI2C_SendStartCondition(void);
void MI2C_SendRepeatedStartCondition(void);
void MI2C_SendStopCondition(void);

void MI2C_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress);
void MI2C_SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress);

void MI2C_MasterWriteDataByte(u8 Copy_u8DataByte);
u8   MI2C_MasterReadDataByte(void);


/*Initialize EEPROM*/
void EEPROM_voidInit(void);
/*Send byte to EEPROM*/
void EEPROM_voidWrite_Byte(u8 Copy_u8AddressSlave ,u8 Copy_u8AddressLocation,u8 Copy_u8Data);
/*Read byte to EEPROM*/
void EEPROM_u8Read_Byte(u8 Copy_u8AddressSlave ,u8 Copy_u8AddressLocation, u8 *Copy_u8Data);



#endif
