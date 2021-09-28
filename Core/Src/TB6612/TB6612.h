/*
 * TB6612.h
 *
 *  Created on: Jul 22, 2021
 *      Author: fan
 */

#ifndef SRC_TB6612_TB6612_H_
#define SRC_TB6612_TB6612_H_

#include "stm32f1xx_ll_tim.h"
#include "stm32f1xx_ll_gpio.h"

typedef struct
{
		TIM_TypeDef *TimPort;
		uint32_t PWMA_Channel;
		uint32_t PWMB_Channel;

		GPIO_TypeDef *AIN1Port;
		uint32_t AIN1Pin;
		GPIO_TypeDef *AIN2Port;
		uint32_t AIN2Pin;
		GPIO_TypeDef *BIN1Port;
		uint32_t BIN1Pin;
		GPIO_TypeDef *BIN2Port;
		uint32_t BIN2Pin;

		uint16_t MaxPWM_Value;
} TB6612_t;

void TB6612_IO_Iint(void);
void TB6612_init(TB6612_t *TB6612);
void Set_Left_PWMValue(TB6612_t *TB6612,int16_t Value);
void Set_Right_PWMValue(TB6612_t *TB6612,int16_t Value);
void TB6612_Break(TB6612_t *TB6612);

#endif /* SRC_TB6612_TB6612_H_ */
