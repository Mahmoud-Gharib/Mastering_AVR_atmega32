#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

#define  SREG     		  (*((volatile u8*)0x5F))

/***************************** UART Registers Macros **********************/
#define  UBRRL            (*(volatile u8 *)0x29)
#define  UCSRB            (*(volatile u8 *)0x2A)
#define  UCSRA            (*(volatile u8 *)0x2B)
#define  UDR              (*(volatile u8 *)0x2C)
#define  UBRRH            (*(volatile u8 *)0x40)
#define  UCSRC            (*(volatile u8 *)0x40)


#endif
