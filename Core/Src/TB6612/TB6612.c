/*
 * TB6612.c
 *
 *  Created on: Jul 22, 2021
 *      Author: fan
 */

#include "TB6612.h"

TB6612_t TB6612_IO;

void TB6612_IO_Iint(void)
{
	TB6612_IO.AIN1Pin=LL_GPIO_PIN_12;
	TB6612_IO.AIN1Port=GPIOB;
	TB6612_IO.AIN2Pin=LL_GPIO_PIN_13;
	TB6612_IO.AIN2Port=GPIOB;
	TB6612_IO.BIN1Pin=LL_GPIO_PIN_14;
	TB6612_IO.BIN1Port=GPIOB;
	TB6612_IO.BIN2Pin=LL_GPIO_PIN_15;
	TB6612_IO.BIN2Port=GPIOB;
	TB6612_IO.MaxPWM_Value=1000;
	TB6612_IO.PWMA_Channel=LL_TIM_CHANNEL_CH1;
	TB6612_IO.PWMB_Channel=LL_TIM_CHANNEL_CH2;
	TB6612_IO.TimPort=TIM4;
}

void TB6612_init(TB6612_t *TB6612)
{
	LL_TIM_CC_EnableChannel(TB6612->TimPort,TB6612->PWMA_Channel);
	LL_TIM_CC_EnableChannel(TB6612->TimPort,TB6612->PWMB_Channel);
	LL_TIM_EnableCounter(TB6612->TimPort);

	LL_GPIO_ResetOutputPin(TB6612->AIN1Port,TB6612->AIN1Pin);
	LL_GPIO_ResetOutputPin(TB6612->AIN2Port,TB6612->AIN2Pin);
	LL_GPIO_ResetOutputPin(TB6612->BIN1Port,TB6612->BIN1Pin);
	LL_GPIO_ResetOutputPin(TB6612->BIN2Port,TB6612->BIN2Pin);

}

void Set_Left_PWMValue(TB6612_t *TB6612,int16_t Value)
{
	uint32_t finalvalue=0;
	if(Value>0)
	{
		LL_GPIO_ResetOutputPin(TB6612->AIN1Port,TB6612->AIN1Pin);
		LL_GPIO_SetOutputPin(TB6612->AIN2Port,TB6612->AIN2Pin);
		if(Value>=TB6612->MaxPWM_Value)
		{
			finalvalue=TB6612->MaxPWM_Value;
			LL_TIM_OC_SetCompareCH1(TB6612->TimPort,finalvalue);
		}else{
			finalvalue=Value;
			LL_TIM_OC_SetCompareCH1(TB6612->TimPort,finalvalue);
		}
	}else if(Value==0){
		LL_GPIO_ResetOutputPin(TB6612->AIN1Port,TB6612->AIN1Pin);
		LL_GPIO_ResetOutputPin(TB6612->AIN2Port,TB6612->AIN2Pin);
	}else{
		LL_GPIO_SetOutputPin(TB6612->AIN1Port,TB6612->AIN1Pin);
		LL_GPIO_ResetOutputPin(TB6612->AIN2Port,TB6612->AIN2Pin);
		if(Value< - TB6612->MaxPWM_Value)
		{
			finalvalue=TB6612->MaxPWM_Value;
			LL_TIM_OC_SetCompareCH1(TB6612->TimPort,finalvalue);
		}else{
			finalvalue= - Value;
			LL_TIM_OC_SetCompareCH1(TB6612->TimPort,finalvalue);
		}
	}
}

void Set_Right_PWMValue(TB6612_t *TB6612,int16_t Value)
{
	uint32_t finalvalue=0;
	if(Value>0)
	{
		LL_GPIO_ResetOutputPin(TB6612->BIN1Port,TB6612->BIN1Pin);
		LL_GPIO_SetOutputPin(TB6612->BIN2Port,TB6612->BIN2Pin);
		if(Value>=TB6612->MaxPWM_Value)
		{
			finalvalue=TB6612->MaxPWM_Value;
			LL_TIM_OC_SetCompareCH2(TB6612->TimPort,finalvalue);
		}else{
			finalvalue=Value;
			LL_TIM_OC_SetCompareCH2(TB6612->TimPort,finalvalue);
		}
	}else if(Value==0){
		LL_GPIO_ResetOutputPin(TB6612->BIN1Port,TB6612->BIN1Pin);
		LL_GPIO_ResetOutputPin(TB6612->BIN2Port,TB6612->BIN2Pin);
	}else{
		LL_GPIO_SetOutputPin(TB6612->BIN1Port,TB6612->BIN1Pin);
		LL_GPIO_ResetOutputPin(TB6612->BIN2Port,TB6612->BIN2Pin);
		if(Value< - TB6612->MaxPWM_Value)
		{
			finalvalue=TB6612->MaxPWM_Value;
			LL_TIM_OC_SetCompareCH2(TB6612->TimPort,finalvalue);
		}else{
			finalvalue=-Value;
			LL_TIM_OC_SetCompareCH2(TB6612->TimPort,finalvalue);
		}
	}
}

void TB6612_Break(TB6612_t *TB6612)
{
	LL_GPIO_ResetOutputPin(TB6612->AIN1Port,TB6612->AIN1Pin);
	LL_GPIO_ResetOutputPin(TB6612->AIN2Port,TB6612->AIN2Pin);
	LL_GPIO_ResetOutputPin(TB6612->BIN1Port,TB6612->BIN1Pin);
	LL_GPIO_ResetOutputPin(TB6612->BIN2Port,TB6612->BIN2Pin);
}
