/*
 * encoder.h
 *
 *  Created on: 2021年7月22日
 *      Author: fan
 */

#ifndef SRC_ENCODER_ENCODER_H_
#define SRC_ENCODER_ENCODER_H_

#include "Clock.h"
#include "stm32f1xx_hal.h"

#define	Time_t	mtime_t
#define Get_ms  GetCurrentTimeMillisecond

extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;

#define encoder1_tim htim2
#define encoder2_tim htim3

typedef	struct
{
	Time_t   lasttime_channel1;
	Time_t   leasttime_channel1;
	Time_t   difftime_channel1;

	Time_t   lasttime_channel2;
	Time_t   leasttime_channel2;
	Time_t   difftime_channel2;

	uint16_t pulsesnow_channel1;

	uint16_t pulsesnow_channel2;

	uint16_t  derition1;
	uint16_t  derition2;
} Encoder_struct;

void    encoder_init(void);
//float	getspeed_channel1(Encoder_struct *encoder);
float	getspeed_channel2(Encoder_struct *encoder);

#endif /* SRC_ENCODER_ENCODER_H_ */
