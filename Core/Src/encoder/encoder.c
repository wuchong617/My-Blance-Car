/*
 * encoder.c
 *
 *  Created on: 2021年7月22日
 *      Author: fan
 */

#include "encoder.h"
#include <stdint.h>

float speed=0.0;
const uint16_t maxtime=5;

Encoder_struct encoder_t;

void    encoder_init(void)
{
	encoder_t.derition1=0;
	encoder_t.derition2=0;
	encoder_t.difftime_channel1=0;
	encoder_t.difftime_channel2=0;
	encoder_t.lasttime_channel1=0;
	encoder_t.lasttime_channel2=0;
	encoder_t.leasttime_channel1=0;
	encoder_t.leasttime_channel2=0;
	encoder_t.pulsesnow_channel1=0;
	encoder_t.pulsesnow_channel2=0;

	HAL_TIM_Encoder_Start(&encoder2_tim,TIM_CHANNEL_ALL);
}

//float	getspeed_channel1(Encoder_struct *encoder)
//{
//	encoder->leasttime_channel1=Get_ms();
//	encoder->difftime_channel1=encoder->leasttime_channel1-encoder->lasttime_channel1;
//
//	if(encoder->difftime_channel1>=maxtime)
//	{
//		encoder->derition1=__HAL_TIM_IS_TIM_COUNTING_DOWN(&encoder1_tim);
//		encoder->pulsesnow_channel1=__HAL_TIM_GET_COUNTER(&encoder1_tim);
//		__HAL_TIM_SET_COUNTER(&encoder1_tim,0);
//		encoder->lasttime_channel1=encoder->leasttime_channel1;
//		if(encoder->derition1==1)
//		{
//			speed=(65535-encoder->pulsesnow_channel1);
//		}else{
//			speed= - encoder->pulsesnow_channel1;
//		}
//		if(speed>=13090)
//		{
//			speed=0;
//		}
//	}
//	return speed;
//}


float	getspeed_channel2(Encoder_struct *encoder)
{
	encoder->leasttime_channel2=Get_ms();
	encoder->difftime_channel2=encoder->leasttime_channel2-encoder->lasttime_channel2;

	if(encoder->difftime_channel2>=maxtime)
	{
		encoder->derition2=__HAL_TIM_IS_TIM_COUNTING_DOWN(&encoder2_tim);
		encoder->pulsesnow_channel2=__HAL_TIM_GET_COUNTER(&encoder2_tim);
		__HAL_TIM_SET_COUNTER(&encoder2_tim,0);
		encoder->lasttime_channel2=encoder->leasttime_channel2;
		if(encoder->derition2==1)
		{
			speed=(65535-encoder->pulsesnow_channel2);
		}else{
			speed= - encoder->pulsesnow_channel2;
		}
		if(speed>=13090)
		{
			speed=0;
		}
	}
	return speed;
}
