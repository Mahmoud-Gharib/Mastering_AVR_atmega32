#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H


#define  SREG     		  (*((volatile u8*)0x5F))

/***************************** SPI Registers macros **********************/
#define SPCR		(*((volatile u8*)0x2D))
#define SPSR		(*((volatile u8*)0x2E))
#define SPDR		(*((volatile u8*)0x2F))

#endif
