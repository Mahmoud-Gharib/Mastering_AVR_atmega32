#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H


/*********** MODES macros ***********/
#define MASTER   1
#define SLAVE    2

/*********** Prototypes SPI DRIVERS **************/
void MSPI_voidInit(void);
void MSPI_voidSendData(u8 Copy_u8Data);
u8   MSPI_u8ReciveData(void);
u8   MSPI_u8SendReciveData(u8 Copy_u8Data);


void MSPI_voidIntEnable(void);
void MSPI_voidIntDisable(void);
void MSPI_voidAsyncSendData(u8 Copy_u8Data);
u8   MSPI_u8AsyncReciveData(void);
void MSPI_voidSetCallBack(void (*Copy_pvCallBackFunc)(void));


#endif
