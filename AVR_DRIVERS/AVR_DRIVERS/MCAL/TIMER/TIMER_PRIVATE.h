#ifndef  TIMER_PRIVATE_H_
#define  TIMER_PRIVATE_H_


#define  SREG_REG      (*((volatile u8*)0x5F))


#define TCNT0          *((volatile u8 *) 0x52)
#define TCCR0          *((volatile u8 *)0x53)
#define OCR0           *((volatile u8 *)0x5C)




#define TCNT1        *((volatile u8 *) 0x4C)

#define TCCR1A       *((volatile u8 *)0x4F)

#define TCCR1A       *((volatile u8 *)0x4F)
#define TCCR1B       *((volatile u8 *)0x4E)

#define TIMSK        *((volatile u8 *)0x59)

#define OCR1A        *((volatile u16 *)0x4A)
#define OCR1B        *((volatile u16 *)0x48)

#define ICR1         *((volatile u16 *)0x46)




#endif
