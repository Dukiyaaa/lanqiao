/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    tim.c
  * @brief   This file provides code for the configuration
  *          of the TIM instances.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "tim.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim3;
TIM_HandleTypeDef htim4;
TIM_HandleTypeDef htim17;

/* TIM2 init function */
void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_IC_InitTypeDef sConfigIC = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 80 - 1;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 4.294967295E9;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_IC_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigIC.ICPolarity = TIM_INPUTCHANNELPOLARITY_RISING;
  sConfigIC.ICSelection = TIM_ICSELECTION_DIRECTTI;
  sConfigIC.ICPrescaler = TIM_ICPSC_DIV1;
  sConfigIC.ICFilter = 0;
  if (HAL_TIM_IC_ConfigChannel(&htim2, &sConfigIC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}
/* TIM3 init function */
void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 10 - 1;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 1999;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 1000;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */
  HAL_TIM_MspPostInit(&htim3);

}
/* TIM4 init function */
void MX_TIM4_Init(void)
{

  /* USER CODE BEGIN TIM4_Init 0 */

  /* USER CODE END TIM4_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM4_Init 1 */

  /* USER CODE END TIM4_Init 1 */
  htim4.Instance = TIM4;
  htim4.Init.Prescaler = 80 - 1;
  htim4.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim4.Init.Period = 9999;
  htim4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim4.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim4) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim4, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim4, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM4_Init 2 */

  /* USER CODE END TIM4_Init 2 */

}
/* TIM17 init function */
void MX_TIM17_Init(void)
{

  /* USER CODE BEGIN TIM17_Init 0 */

  /* USER CODE END TIM17_Init 0 */

  TIM_OC_InitTypeDef sConfigOC = {0};
  TIM_BreakDeadTimeConfigTypeDef sBreakDeadTimeConfig = {0};

  /* USER CODE BEGIN TIM17_Init 1 */

  /* USER CODE END TIM17_Init 1 */
  htim17.Instance = TIM17;
  htim17.Init.Prescaler = 10 - 1;
  htim17.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim17.Init.Period = 1999;
  htim17.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim17.Init.RepetitionCounter = 0;
  htim17.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim17) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim17) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 1000;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCNPolarity = TIM_OCNPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
  sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
  if (HAL_TIM_PWM_ConfigChannel(&htim17, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  sBreakDeadTimeConfig.OffStateRunMode = TIM_OSSR_DISABLE;
  sBreakDeadTimeConfig.OffStateIDLEMode = TIM_OSSI_DISABLE;
  sBreakDeadTimeConfig.LockLevel = TIM_LOCKLEVEL_OFF;
  sBreakDeadTimeConfig.DeadTime = 0;
  sBreakDeadTimeConfig.BreakState = TIM_BREAK_DISABLE;
  sBreakDeadTimeConfig.BreakPolarity = TIM_BREAKPOLARITY_HIGH;
  sBreakDeadTimeConfig.BreakFilter = 0;
  sBreakDeadTimeConfig.AutomaticOutput = TIM_AUTOMATICOUTPUT_DISABLE;
  if (HAL_TIMEx_ConfigBreakDeadTime(&htim17, &sBreakDeadTimeConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM17_Init 2 */

  /* USER CODE END TIM17_Init 2 */
  HAL_TIM_MspPostInit(&htim17);

}

void HAL_TIM_Base_MspInit(TIM_HandleTypeDef* tim_baseHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(tim_baseHandle->Instance==TIM2)
  {
  /* USER CODE BEGIN TIM2_MspInit 0 */

  /* USER CODE END TIM2_MspInit 0 */
    /* TIM2 clock enable */
    __HAL_RCC_TIM2_CLK_ENABLE();

    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**TIM2 GPIO Configuration
    PA15     ------> TIM2_CH1
    */
    GPIO_InitStruct.Pin = GPIO_PIN_15;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF1_TIM2;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* TIM2 interrupt Init */
    HAL_NVIC_SetPriority(TIM2_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(TIM2_IRQn);
  /* USER CODE BEGIN TIM2_MspInit 1 */

  /* USER CODE END TIM2_MspInit 1 */
  }
  else if(tim_baseHandle->Instance==TIM3)
  {
  /* USER CODE BEGIN TIM3_MspInit 0 */

  /* USER CODE END TIM3_MspInit 0 */
    /* TIM3 clock enable */
    __HAL_RCC_TIM3_CLK_ENABLE();
  /* USER CODE BEGIN TIM3_MspInit 1 */

  /* USER CODE END TIM3_MspInit 1 */
  }
  else if(tim_baseHandle->Instance==TIM4)
  {
  /* USER CODE BEGIN TIM4_MspInit 0 */

  /* USER CODE END TIM4_MspInit 0 */
    /* TIM4 clock enable */
    __HAL_RCC_TIM4_CLK_ENABLE();

    /* TIM4 interrupt Init */
    HAL_NVIC_SetPriority(TIM4_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(TIM4_IRQn);
  /* USER CODE BEGIN TIM4_MspInit 1 */

  /* USER CODE END TIM4_MspInit 1 */
  }
  else if(tim_baseHandle->Instance==TIM17)
  {
  /* USER CODE BEGIN TIM17_MspInit 0 */

  /* USER CODE END TIM17_MspInit 0 */
    /* TIM17 clock enable */
    __HAL_RCC_TIM17_CLK_ENABLE();
  /* USER CODE BEGIN TIM17_MspInit 1 */

  /* USER CODE END TIM17_MspInit 1 */
  }
}
void HAL_TIM_MspPostInit(TIM_HandleTypeDef* timHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(timHandle->Instance==TIM3)
  {
  /* USER CODE BEGIN TIM3_MspPostInit 0 */

  /* USER CODE END TIM3_MspPostInit 0 */
    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**TIM3 GPIO Configuration
    PA6     ------> TIM3_CH1
    */
    GPIO_InitStruct.Pin = GPIO_PIN_6;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF2_TIM3;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* USER CODE BEGIN TIM3_MspPostInit 1 */

  /* USER CODE END TIM3_MspPostInit 1 */
  }
  else if(timHandle->Instance==TIM17)
  {
  /* USER CODE BEGIN TIM17_MspPostInit 0 */

  /* USER CODE END TIM17_MspPostInit 0 */

    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**TIM17 GPIO Configuration
    PA7     ------> TIM17_CH1
    */
    GPIO_InitStruct.Pin = GPIO_PIN_7;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF1_TIM17;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* USER CODE BEGIN TIM17_MspPostInit 1 */

  /* USER CODE END TIM17_MspPostInit 1 */
  }

}

void HAL_TIM_Base_MspDeInit(TIM_HandleTypeDef* tim_baseHandle)
{

  if(tim_baseHandle->Instance==TIM2)
  {
  /* USER CODE BEGIN TIM2_MspDeInit 0 */

  /* USER CODE END TIM2_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_TIM2_CLK_DISABLE();

    /**TIM2 GPIO Configuration
    PA15     ------> TIM2_CH1
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_15);

    /* TIM2 interrupt Deinit */
    HAL_NVIC_DisableIRQ(TIM2_IRQn);
  /* USER CODE BEGIN TIM2_MspDeInit 1 */

  /* USER CODE END TIM2_MspDeInit 1 */
  }
  else if(tim_baseHandle->Instance==TIM3)
  {
  /* USER CODE BEGIN TIM3_MspDeInit 0 */

  /* USER CODE END TIM3_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_TIM3_CLK_DISABLE();
  /* USER CODE BEGIN TIM3_MspDeInit 1 */

  /* USER CODE END TIM3_MspDeInit 1 */
  }
  else if(tim_baseHandle->Instance==TIM4)
  {
  /* USER CODE BEGIN TIM4_MspDeInit 0 */

  /* USER CODE END TIM4_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_TIM4_CLK_DISABLE();

    /* TIM4 interrupt Deinit */
    HAL_NVIC_DisableIRQ(TIM4_IRQn);
  /* USER CODE BEGIN TIM4_MspDeInit 1 */

  /* USER CODE END TIM4_MspDeInit 1 */
  }
  else if(tim_baseHandle->Instance==TIM17)
  {
  /* USER CODE BEGIN TIM17_MspDeInit 0 */

  /* USER CODE END TIM17_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_TIM17_CLK_DISABLE();
  /* USER CODE BEGIN TIM17_MspDeInit 1 */

  /* USER CODE END TIM17_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */
/* key */
struct key {
	uint8_t key_step;
	bool key_pin_state;
	bool key_is_down;
	uint32_t key_time;
	bool key_is_long;
};

struct key key_buf[4] = {0};
void key_init(void)
{
	HAL_TIM_Base_Start_IT(&htim4);
}

void key_scan(void)
{
	key_buf[0].key_pin_state = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0);
	key_buf[1].key_pin_state = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1);
	key_buf[2].key_pin_state = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_2);
	key_buf[3].key_pin_state = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
	
	for(uint8_t i = 0;i < 4;i++)
	{
		switch(key_buf[i].key_step)
		{
			case 0:
				if(key_buf[i].key_pin_state == 0)
				{
					key_buf[i].key_step = 1;
				}
				else
				{
					key_buf[i].key_step = 0;
					key_buf[i].key_is_down = 0;
//					key_buf[i].key_time = 0;
//					key_buf[i].key_is_long = 0;
				}
			break;
			case 1:
				if(key_buf[i].key_pin_state == 0)
				{
					key_buf[i].key_step = 2;
					key_buf[i].key_is_down = 1;
				}
				else
				{
					key_buf[i].key_step = 0;
					key_buf[i].key_is_down = 0;
//					key_buf[i].key_time = 0;
//					key_buf[i].key_is_long = 0;
				}
			break;
			case 2:
				if(key_buf[i].key_pin_state == 0)
				{
//					key_buf[i].key_step = 1;
					key_buf[i].key_time++;
					if(key_buf[i].key_time >= 200)
					{
						key_buf[i].key_is_long = 1;
					}
				}
				else
				{
					key_buf[i].key_step = 0;
					key_buf[i].key_is_down = 0;
//					key_buf[i].key_time = 0;
//					key_buf[i].key_is_long = 0;
				}
			break;
		}
	}
}

extern bool ld1_toggle;
extern uint8_t led_8bits;
uint32_t ld1_cnt = 0;
uint32_t second_flag_cnt = 0;

bool second_flag = 0;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIM4)
	{
		key_scan();
		
		if(ld1_toggle == 1)
		{
			ld1_cnt++;
			if(ld1_cnt >= 20)
			{
				ld1_cnt = 0;
				led_8bits ^= (1 << 0);
			}
		}
		else
		{
			ld1_cnt = 0;
		}
		
		if(second_flag == 0)
		{
			second_flag_cnt++;
			if(second_flag_cnt >= 125)
			{
				second_flag_cnt = 0;
				second_flag = 1;
			}
		}
		else
		{
			second_flag_cnt = 0;
		}
	}
}

extern uint8_t ST;
extern int16_t pos[400];
extern uint16_t pos_ptr;
extern int16_t FP[2];

extern uint8_t lcd_num;
bool is_select_R = 1;

extern float R;
extern uint32_t B;	
uint8_t key3_step = 0;
uint8_t key4_step = 0;

extern float TS;
extern uint32_t TT;
void key_task(void)
{
	for(uint8_t i = 0;i < 4;i++)
	{
		if(key_buf[i].key_is_down == 1)
		{
			switch(i)
			{
				case 0:
					key_buf[i].key_is_down = 0;
					if(ST == 0)
					{
						// 收到了目的地坐标，切换为运行，否则不变
						if((FP[0] != -1) && (FP[1] != -1))
						{
							ST = 1;
						}
						else
						{
							ST = 0;
						}
					}
					else if(ST == 1)
					{
						ST = 2;
					}
					else if(ST == 2)
					{
						ST = 1;
					}
				break;
				case 1:
					key_buf[i].key_is_down = 0;
					lcd_num++;
					if(lcd_num > 2)
					{
						lcd_num = 0;
					}
					
					if(lcd_num == 1)
					{
						is_select_R = 1;
					}
				break;
				case 2:
					key3_step = 1;
				break;
				case 3:
					key4_step = 1;
				break;
			}
		}
		
		
		if(key_buf[2].key_is_down == 0)
		{
			if(key3_step == 1)
			{
				key3_step = 0;
				// 按下了
				if(key_buf[2].key_is_long == 0)
				{
					// 短按
					// 参数界面起作用
					if(lcd_num == 1)
					{
						is_select_R ^= 1;
					}
				}
				else if(key_buf[2].key_is_long == 1)
				{
					// 长按
					if(lcd_num == 0)
					{
						if(ST == 0)
						{
							if(key_buf[3].key_is_long == 1)
							{
								// 清0:TS和TT
								TS = 0;
								TT = 0;
							}
						}
					}
				}
			}
			
			key_buf[2].key_time = 0;
			key_buf[2].key_is_long = 0;
		}
		
		if(key_buf[3].key_is_down == 0)
		{
			if(key4_step == 1)
			{
				key4_step = 0;
				// 按下了
				if(key_buf[3].key_is_long == 0)
				{
					// 短按
					// 参数界面起作用
					if(lcd_num == 1)
					{
						if(is_select_R == 1)
						{
							R += 0.1f;
							if(R > 2.09f)
							{
								R = 1.0f;
							}
						}
						else if(is_select_R == 0)
						{
							B += 10;
							if(B > 100)
							{
								B = 10;
							}
						}
					}
				}
				else if(key_buf[3].key_is_long == 1)
				{
					// 长按
					if(lcd_num == 0)
					{
						if(ST == 0)
						{
							if(key_buf[2].key_is_long == 1)
							{
								// 清0:TS和TT
								TS = 0;
								TT = 0;
							}
						}
					}
				}
			}
			
			key_buf[3].key_time = 0;
			key_buf[3].key_is_long = 0;
		}
	}
}

/* pwm */
void pwm_init(void)
{
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);	// pa6, 10
	HAL_TIM_PWM_Start(&htim17, TIM_CHANNEL_1);	// pa7, 10
	HAL_TIM_IC_Start_IT(&htim2, TIM_CHANNEL_1);	// pa15, 80
}

void pwm_set_fre_duty(TIM_HandleTypeDef *htim, float fre, float duty)
{
	uint32_t clk = 80000000;
	uint32_t div = 10;
	uint32_t period = clk / div / fre - 1;
	uint32_t pulse = period * duty / 100.0f;
	if(pulse > period)
	{
		pulse = period - 1;
	}
	
	if(htim->Instance == TIM3)
	{
		TIM3->ARR = period;
		TIM3->CCR1 = pulse;
		TIM3->EGR = TIM_EGR_UG;		// 立即刷新?
		
		HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);	// A:pa6, 10
	}
	else if(htim->Instance == TIM17)
	{
		TIM17->ARR = period;
		TIM17->CCR1 = pulse;
		TIM17->EGR = TIM_EGR_UG;	// 立即刷新?
		
		HAL_TIM_PWM_Start(&htim17, TIM_CHANNEL_1);	// B:pa7, 10
	}
}

float fre;
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIM2)
	{
		uint32_t tmp = HAL_TIM_ReadCapturedValue(&htim2, TIM_CHANNEL_1);
		if(tmp != 0)
		{
			fre = 1000000.0f / (float)tmp;
		}
		
		if(fre < 400.0f)
		{
			fre = 400.0f;
		}
		else if(fre > 20000.0f)
		{
			fre = 20000.0f;
		}
		__HAL_TIM_SET_COUNTER(&htim2, 0);
		HAL_TIM_IC_Start_IT(&htim2, TIM_CHANNEL_1);	// pa15, 80
	}
}

extern float SE;
extern uint8_t dutyA, dutyB;
extern uint8_t scene;
uint32_t fre_sceneA[4] = {1000, 4000, 1000, 4000};
uint32_t fre_sceneB[4] = {1000, 1000, 4000, 4000};

void pwm_task(void)
{
	// pwm ic
	if(ST == 1)
	{
		SE = 3.14f * R * fre / 100.0f + (float)B;	// 运行状态下的速度值，cm/s
	}
	else
	{
		SE = 0.0f;
	}
	
	// pwm out
	if(ST == 1)
	{
		pwm_set_fre_duty(&htim3, fre_sceneA[scene], dutyA);
		pwm_set_fre_duty(&htim17, fre_sceneB[scene], dutyB);
	}
	else	
	{
		pwm_set_fre_duty(&htim3, fre_sceneA[scene], 0);
		pwm_set_fre_duty(&htim17, fre_sceneB[scene], 0);
	}
	
}


extern int16_t CP[2];	// 当前位置
extern int16_t TP[2];	// 下一个目标点
uint32_t TP_ptr = 0;	// 下一个目标点的第一个元素位置
float distance,left_distance;
bool check_distance_flag = 0;
extern uint32_t TT;
extern float TS;
extern int16_t pos[400];
extern uint16_t pos_ptr;
extern uint32_t RN;

float cos_theta, sin_theta;
bool first_flag = 1;
void work_task(void)
{	
	if((pos[TP_ptr] == -1) && (pos[TP_ptr + 1] == -1))
	{
		if(pos_ptr == 0)
		{
			
		}
		else
		{
			TP_ptr += 2;
			if(TP_ptr >= 399)
			{
				TP_ptr = 0;
			}
		}
	}
	else
	{
		TP[0] = pos[TP_ptr];
		TP[1] = pos[TP_ptr + 1];
	}
	
	if(ST == 1)
	{
		if(check_distance_flag == 0)
		{
			check_distance_flag = 1;
			distance = sqrt((TP[0] - CP[0]) * (TP[0] - CP[0]) + (TP[1] - CP[1]) * (TP[1] - CP[1]));
			cos_theta = (TP[0] - CP[0]) /  distance;
			sin_theta = (TP[1] - CP[1]) /  distance;
			left_distance = distance;
			second_flag = 0;
		}
		
		if(second_flag == 1)
		{
			second_flag = 0;
			left_distance = left_distance - SE;
			TT++;
			TS += SE;
			if(left_distance < 0)
			{
				CP[0] = TP[0];
				CP[1] = TP[1];
				pos[TP_ptr] = -1;
				pos[TP_ptr + 1] = -1;
				TP_ptr += 2;
				if(TP_ptr >= 399)
				{
					TP_ptr = 0;
				}
				TP[0] = pos[TP_ptr];
				TP[1] = pos[TP_ptr + 1];
				RN--;
				
				if(RN == 0)
				{
					CP[0] = FP[0];
					CP[1] = FP[1];
					TS += left_distance;
				}

				check_distance_flag = 0;
				if((CP[0] == FP[0]) && (CP[1] == FP[1]))
				{
					ST = 0;
					FP[0] = -1;
					FP[1] = -1;
					TP_ptr = 0;
					pos_ptr = 0;
					RN = 0;
				}
			}
			else
			{
				CP[0] += (SE * cos_theta);
				CP[1] += (SE * sin_theta);
			}
			
//			if(CP[0] == 400 && CP[1] == 300)
//			{
//				CP[0] = 168;
//				CP[1] = 126;
//			}
		}
	}
	else
	{
		second_flag = 0;
	}
}
/* USER CODE END 1 */
