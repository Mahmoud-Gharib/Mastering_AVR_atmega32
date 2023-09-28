#ifndef TIMER0_CFG_H_
#define TIMER0_CFG_H_

#define TIMER_0_DIVISION_FACTOR    1024
#define   CRYSTAL_FREQ             16

#define TIMER_0_MODE               CTC_MODE
//TIMER0_OVF_vect,TIMER0_COMP_vect
#define TIMER_0_ISR_VECT        TIMER0_COMP_vect

#define  PWM_0_MODE     FAST_PWM
#define  COMPARE_OUTPUT_MODE  NON_INVERTED
 

#endif