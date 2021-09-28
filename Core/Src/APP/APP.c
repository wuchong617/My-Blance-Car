/*
 * APP.c
 *
 *  Created on: Jul 22, 2021
 *      Author: fan
 */
#include "APP.h"
#include "stm32f1xx.h"
#include "inv_mpu.h"
#include "clock.h"
#include "JustFloat.h"
#include "PID.h"
#include "SerialPrintf.h"
#include "TB6612.h"
#include "encoder.h"

extern I2C_HandleTypeDef hi2c1;
extern TB6612_t TB6612_IO;
extern float pitch;
extern short gy;
extern int16_t straught_out;
extern PID_t Speed_PID;
extern PID_t Straight_PID;
extern Encoder_struct encoder_t;
extern float fianl_speed;

void APP_Init(void)
{
	ClockInit();

	SetJustFloatPort(USART1);
	SetSerialPrintfTarget(USART1);

	TB6612_IO_Iint();
	TB6612_init(&TB6612_IO);

	encoder_init();
	PID_Init();

	printf("Start.\r\n");
	MPU_Error_t ret = MPU_DMP_Init(&hi2c1, 100);
	while(ret != MPU_OK)
	{
		printf("MPU Init error with code: %d\r\n", ret);
		SleepMillisecond(400);
		ret = MPU_DMP_Init(&hi2c1, 100);
	}
	printf("MPU OK\r\n");
	set_int_enable(1);

	while(1)
	{
		waitPID_Flag();
		float data[] = {Speed_PID.proportion,Speed_PID.integral,Speed_PID.integral_output,fianl_speed,Speed_PID.differential,Speed_PID.PID_Output,straught_out,pitch};
		SendJustFloatFrame(data, 8);
	}
}
