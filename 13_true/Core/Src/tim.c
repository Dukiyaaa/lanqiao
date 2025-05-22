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
  if (HAL_TIM_IC_ConfigChannel(&htim2, &sConfigIC, TIM_CHANNEL_2) != HAL_OK)
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
  htim3.Init.Period = 65535;
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
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
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
    PA1     ------> TIM2_CH2
    */
    GPIO_InitStruct.Pin = GPIO_PIN_1;
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
    PA7     ------> TIM3_CH2
    */
    GPIO_InitStruct.Pin = GPIO_PIN_7;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF2_TIM3;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* USER CODE BEGIN TIM3_MspPostInit 1 */

  /* USER CODE END TIM3_MspPostInit 1 */
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
    PA1     ------> TIM2_CH2
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_1);

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
}

/* USER CODE BEGIN 1 */
struct key {
	uint8_t key_step;
	bool key_pin_state;
	bool key_is_down;
	uint32_t key_time;
	bool key_is_long;
};

struct key key_buffer[4] = {0};

void key_init(void)
{
	HAL_TIM_Base_Start_IT(&htim4);
}

void key_scan(void)
{
	key_buffer[0].key_pin_state = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0);
	key_buffer[1].key_pin_state = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1);
	key_buffer[2].key_pin_state = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_2);
	key_buffer[3].key_pin_state = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
	
	for(uint8_t i = 0; i < 4; i++)
	{
		switch(key_buffer[i].key_step)
		{
			case 0:
			if(key_buffer[i].key_pin_state == 0)
			{
				key_buffer[i].key_step = 1;
			}	
			else
			{
				key_buffer[i].key_step = 0;
			}
			break;
			case 1:
			if(key_buffer[i].key_pin_state == 0)
			{
				key_buffer[i].key_step = 2;
				key_buffer[i].key_is_down = 1;
			}	
			else
			{
				key_buffer[i].key_step = 0;
				key_buffer[i].key_is_down = 0;
			}
			break;
			case 2:
			if(key_buffer[i].key_pin_state == 0)
			{
				
				key_buffer[i].key_time++;
				
				if(key_buffer[i].key_time >= 100)
				{
					key_buffer[i].key_is_long = 1;
				}
			}	
			else
			{
				key_buffer[i].key_step = 0;
				key_buffer[i].key_is_down = 0;
			}
			break;
		}
	}
}

extern float A_4, A_5, T_4, T_5, H_4, H_5;
extern uint8_t led_8bits;
extern uint8_t X, Y;
extern float PA4, PA5;

uint32_t led3_count = 0;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIM4)
	{
		key_scan();
		
		// 10ms
		if(PA4 > PA5 * Y)
		{
			led3_count++;
			
			if(led3_count == 10)
			{
				led3_count = 0;
				led_8bits = led_8bits ^ (1 << 2);
			}
			
		}
		else
		{
			led3_count = 0;
			led_8bits = led_8bits & ~(1 << 2);
		}
	}	
}

#include "i2c_hal.h"
extern uint8_t show_num;
extern uint8_t pa5_lock, pa4_lock;
extern uint32_t N;
extern float A, T, H;
extern uint8_t pa_num;
extern uint32_t N_4, N_5;
extern float a4,a5,t4,t5,h4,h5;
extern double pa4_sum, pa5_sum;
extern uint8_t first4, first5;

uint8_t pwm_output_mode = 0;	// 0:倍频模式
uint8_t key4_flag = 0;
void key_task(void)
{
	for(uint8_t i = 0;i < 4;i++)
	{
		if(key_buffer[i].key_is_down == 1)
		{
			
			switch(i)
			{
				case 0:
				key_buffer[i].key_is_down = 0;
				show_num++;
				if(show_num > 2)
				{
					show_num = 0;
				}
				
				if(show_num == 2)
				{
					pa_num = 4;
				}
				break;
				case 1:
				key_buffer[i].key_is_down = 0;
				if(show_num == 1)
				{
					// 频率参数X
					X++;
					if(X > 4)
					{
						X = 1;
					}
					
					eeprom_write(1, X);
					HAL_Delay(10);
				}					
				break;
				case 2:
				key_buffer[i].key_is_down = 0;
				if(show_num == 1)
				{
					// 电压参数Y
					Y++;
					if(Y > 4)
					{
						Y = 1;
					}
					
					eeprom_write(0, Y);
					HAL_Delay(10);
				}					
				break;
				case 3:
				if(show_num == 0)
				{
					key4_flag = 0;
					key_buffer[i].key_is_down = 0;
					// 启动�?次电压测量功能，lcd显示的电压数据更新一�?
					pa5_lock = 0;
					pa4_lock = 0;
					
				}
				else if(show_num == 1)
				{
					key4_flag = 0;
					key_buffer[i].key_is_down = 0;
					// 切换pwm输出模式为分�?/倍频
					pwm_output_mode ^= 1;
				}
				else if(show_num == 2)
				{
					key4_flag = 1;
				}
				break;
			}
		}
		
		if(key_buffer[3].key_is_down == 0)
		{
			if(key4_flag == 1)
			{
				key4_flag = 0;
				if(key_buffer[3].key_is_long == 1)
				{
					// 清空				
					if(pa_num == 4)
					{
						first4 = 1;
						N_4 = 0;
						A_4 = 0;
						a4 = 0;
						T_4 = 0;
						t4 = 0;
						H_4 = 0;
						h4 = 0;
						pa4_sum = 0;
					}
					else
					{
						first5 = 1;
						N_5 = 0;
						A_5 = 0;
						a5 = 0;
						T_5 = 0;
						t5 = 0;
						H_5 = 0;
						h5 = 0;		
						pa5_sum = 0;
					}
					
				}
				else
				{
					if(pa_num == 4)
					{
						pa_num = 5;
					}
					else
					{
						pa_num = 4;
					}
				}
			}
			
			// 只要key4没按，都需要清0
			key_buffer[3].key_is_long = 0;
			key_buffer[3].key_time = 0;
		}
	}
}
/* pwm output*/
void pwm_init(void)
{
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);	// TIM3,ch2,pa7
	HAL_TIM_IC_Start_IT(&htim2, TIM_CHANNEL_2);	// TIM2, ch2, pa1
}

void pwm_out_set_fre_duty(uint32_t fre, uint32_t duty)
{
	uint32_t clock = 80000000;
	uint32_t div = 10;
	uint32_t period = clock / div / fre;
	uint32_t pulse = period * duty / 100;
	
	if(pulse > period)
	{
		pulse = period - 1;
	}
	
    TIM3->ARR = period;
	TIM3->CCR2 = pulse;
	
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
}


/* pwm ic */
float pa1_fre;
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIM2)
	{
		uint32_t tmp = HAL_TIM_ReadCapturedValue(&htim2, TIM_CHANNEL_2);
		if(tmp == 0) return;
		
		pa1_fre = 1000000.0 / (tmp + 1);
		
		__HAL_TIM_SET_COUNTER(&htim2, 0);
		HAL_TIM_IC_Start_IT(&htim2, TIM_CHANNEL_2);	// TIM2, ch2, pa1
	}
}

void pwm_task(void)
{
	if(pwm_output_mode == 0)
	{
		// 倍频模式
		pwm_out_set_fre_duty(pa1_fre * X, 50);
	}
	else
	{
		// 分频模式
		pwm_out_set_fre_duty(pa1_fre / X, 50);
	}
}
/* USER CODE END 1 */
