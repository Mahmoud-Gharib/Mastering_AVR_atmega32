#ifndef I2C_PRIVATE_H_
#define I2C_PRIVATE_H_


/***************************** I2C Registers macros **********************/

#define  TWBR 		(*((volatile u8 *)0x20))
#define  TWSR 		(*((volatile u8 *)0x21))
#define  TWAR 		(*((volatile u8 *)0x22))
#define  TWDR 		(*((volatile u8 *)0x23))
#define  TWCR 		(*((volatile u8 *)0x56))

#define  START_ACK    				0x08
#define  REP_START_ACK    			0x10
#define  SLAVE_ADD_AND_WR_ACK    	0x18
#define  SLAVE_ADD_AND_RD_ACK       0x40
#define  MATR_WR_BYTE_ACK    		0x28
#define  MATR_RD_BYTE_WITH_ACK      0x50
#define  MATR_RD_BYTE_WITH_NACK     0x58
#define  SLAVE_ADD_RCVD_RD_REQ    	0xA8
#define  SLAVE_ADD_RCVD_WR_REQ    	0x60
#define  SLAVE_DATA_RCVD    		0x80
#define  SLAVE_BYTE_TRANS    		0xB8


#define EEPROM_FIRST_4BITS          0x50
#define     EEPROM_A2               0x00

#endif
