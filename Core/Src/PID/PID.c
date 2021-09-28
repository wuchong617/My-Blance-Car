/*
 * PID.c
 *
 *  Created on: Jul 22, 2021
 *      Author: fan
 */
#include "PID.h"
#include "inv_mpu.h"
#include "Filter.h"
#include "encoder.h"
#include "TB6612.h"

extern TB6612_t TB6612_IO;
extern Encoder_struct encoder_t;

PID_t Speed_PID;
PID_t Straight_PID;

static uint8_t flag = 0;
float pitch = 0, roll = 0, yaw = 0;
short gx = 0, gy = 0, gz = 0;

float fianl_speed=0;
int16_t speed_out=0,straught_out=0;

void PID_Init(void)
{
	Speed_PID.differential=0;
	Speed_PID.target_value=0.0;
	Speed_PID.proportion=-0.825;//-0.918;
	Speed_PID.limitintegral=3;
	Speed_PID.integral=Speed_PID.proportion/200;

	Straight_PID.target_value=-2.3;
	Straight_PID.proportion=68.68;//73.06;
	Straight_PID.limitintegral=200;
	Straight_PID.integral=0;
	Straight_PID.differential=0.18;//0.21;
}

int16_t speed_PID(PID_t *PID,float current_speed)
{
	PID->least_error=PID->target_value-current_speed;
	PID->errorsum+=PID->least_error;

	PID->proportion_output=PID->proportion*PID->least_error;
	Speed_PID.integral=Speed_PID.proportion/200;
	PID->integral_output=PID->integral*PID->errorsum;
	PID->differential_output=PID->differential*(PID->least_error-PID->last_error);

	if(PID->integral_output>=PID->limitintegral)
	{
		PID->integral_output=PID->limitintegral;
		PID->errorsum=0;
	}else if(PID->integral_output< - PID->limitintegral)
	{
		PID->integral_output=-PID->limitintegral;
		PID->errorsum=0;
	}

	PID->PID_Output=PID->differential_output+PID->integral_output+PID->proportion_output;

	return PID->PID_Output;
}

int16_t straight_PID(PID_t *PID,float current_anger,short current_gyro)
{
	PID->least_error=current_anger-PID->target_value;

	PID->proportion_output=PID->proportion*PID->least_error;
	PID->differential_output=PID->differential*current_gyro;
	PID->errorsum+=PID->least_error;
	PID->integral_output=PID->integral*PID->errorsum;

	if(PID->integral_output>=PID->limitintegral)
	{
		PID->integral_output=PID->limitintegral;
		PID->errorsum=0;
	}else if(PID->integral_output< - PID->limitintegral)
	{
		PID->integral_output=-PID->limitintegral;
		PID->errorsum=0;
	}

	PID->PID_Output=PID->differential_output+PID->proportion_output+PID->integral_output;

	return PID->PID_Output;
}

void updatePID_Flag(void)
{
	flag = 1;
}

void waitPID_Flag(void)
{
	while(!flag);
	flag = 0;
}

void PID_Handel(void)
{
	MPU_DMP_GetEularAngle(&pitch, &roll, &yaw);  //pitch
	MPU_GetGyroscope(&gx, &gy, &gz);   		     //gy

	static LowPassFilter_t filter = {0, 0.25};
	fianl_speed = LowPassFilterCalc(&filter, getspeed_channel2(&encoder_t));

	speed_out = speed_PID(&Speed_PID, fianl_speed);
	Straight_PID.target_value = -2.3 + speed_out;
	straught_out = straight_PID(&Straight_PID, pitch, gy);

	Set_Left_PWMValue(&TB6612_IO,straught_out);
	Set_Right_PWMValue(&TB6612_IO,-straught_out);

	updatePID_Flag();
}
