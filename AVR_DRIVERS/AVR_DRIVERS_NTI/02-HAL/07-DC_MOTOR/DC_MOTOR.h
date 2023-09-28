#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "../../00-LIB/STD_TYPES.h"

void DC_MOTOR_INIT(void);
void DC_MOTOR_SET_SPEED(u16);
void DC_MOTOR_DIRECTION(u8);
void DC_MOTOR_START(void);
void DC_MOTOR_STOP(void);

#define CLK 0
#define A_CLK 1

#endif 
