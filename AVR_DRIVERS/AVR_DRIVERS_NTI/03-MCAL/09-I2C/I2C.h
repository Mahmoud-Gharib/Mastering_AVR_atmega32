#ifndef I2C_H_
#define I2C_H_

#include "../../00-LIB/STD_TYPES.h"
#define MASTER   1
#define SLAVE    2
/*_I2C_STATUS_REG_VALUES_*/
#define START_ACK                     0x08		// start condition has been sent
#define REP_START_ACK                 0x10		// repeated start
#define SLAVE_AD_AND_WR_ACK           0x18		// master transmit [ slave address + write request ] ACK
#define SLAVE_AD_AND_RD_ACK           0x40		// master transmit [ slave address + read  request ] ACK
#define WR_BYTE_ACK                   0x28		// master transmit data ACK
#define RD_BYTE_WITH_NACK			  0x58		// master received data with NACK
#define RD_BYTE_WITH_ACK			  0x50		// master received data with  ACK
#define SLAVE_ADD_REC_RD_REQ		  0xA8		// slave address received with write request
#define SLAVE_ADD_REC_WR_REQ          0x60		// slave address received with read  request
#define SLAVE_DATA_REC                0x80		// read  byte request received
#define SLAVE_BYTE_TRANSMITTED        0xC0		// write byte request received

void I2C_INIT(void);
void I2C_START_CONDITION(void);
void I2C_STOP_CONDITION(void);
void I2C_REPEATED_CONDITION(void);
void SEND_SLAVE_ADD_WRITE(u8);
void SEND_SLAVE_ADD_READ(u8);
void I2C_SEND_BYTE(u8);
u8   I2C_READ_BYTE(void);

#endif 