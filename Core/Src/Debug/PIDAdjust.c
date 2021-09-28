/*
 * PIDAdjust.c
 *
 *  Created on: 2021, 6, 30.
 *      Author: h13
 */
#ifdef DEBUG

#include "PIDAdjust.h"
#include "FastMatch.h"
#include "PID.h"

extern PID_t Speed_PID;
extern PID_t Straight_PID;

void PIDAdjust(uint8_t *data, uint8_t len)
{
	MatchKeyFloat(data, len, "AP:", 3, Straight_PID.proportion);
	MatchKeyFloat(data, len, "AI:", 3, Straight_PID.integral);
	MatchKeyFloat(data, len, "AD:", 3, Straight_PID.differential);
	MatchKeyFloat(data, len, "AT:", 3, Straight_PID.target_value);
//	MatchKeyFloat(data, len, "AMI:", 4, Straight_PID.maximumAbsValueOfIntegrationOutput);

	MatchKeyFloat(data, len, "SP:", 3, Speed_PID.proportion);
	MatchKeyFloat(data, len, "SI:", 3, Speed_PID.integral);
	MatchKeyFloat(data, len, "SD:", 3, Speed_PID.differential);
	MatchKeyFloat(data, len, "SL:", 3, Speed_PID.limitintegral);
}

#endif
