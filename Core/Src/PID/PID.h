/*
 * PID.h
 *
 *  Created on: Jul 22, 2021
 *      Author: fan
 */

#ifndef SRC_PID_PID_H_
#define SRC_PID_PID_H_

#include "stm32f1xx_hal.h"

typedef struct{
	float	 proportion;
	float 	 integral;
	float 	 differential;
	uint16_t limitintegral;
	float    proportion_output;
	float    integral_output;
	float    differential_output;
	int16_t PID_Output;
	float    least_error;
	float    last_error;
	float    errorsum;
	float    target_value;
	float    current_value;
} PID_t;

void PID_Init(void);

void updatePID_Flag(void);
void waitPID_Flag(void);

int16_t speed_PID(PID_t *PID,float current_speed);
int16_t straight_PID(PID_t *PID,float current_anger,short current_gyro);
void PID_Handel(void);

#endif /* SRC_PID_PID_H_ */
