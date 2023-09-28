#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_


/*Prototypes UART DRIVERS*/
void MUART_voidInit(void);
void MUART_voidSendData(u8 Copy_u8Data);
u8   MUART_u8ReciveData(void);

void MUART_voidSendString(u8 *Ptr_u8PtrString);
void MUART_voidReciveString(u8 *Ptr_u8PtrString);

#define UART_TX     0
#define UART_RX     1


void UART_voidIntEnable(u8 Copy_u8INT_ID);
void UART_voidIntDisable(u8 Copy_u8INT_ID);
void MUART_voidAsyncSendData(u8 Copy_u8Data);
u8   MUART_u8AsyncReciveData(void);
void UART_voidSetCallBack(u8 Copy_u8INT_ID,void (*Copy_pvCallBackFunc)(void));

#endif
