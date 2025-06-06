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
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 1 - 1;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 19999;
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
  if (HAL_TIM_PWM_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 10000;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */
  HAL_TIM_MspPostInit(&htim2);

}
/* TIM3 init function */
void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_IC_InitTypeDef sConfigIC = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 80 - 1;
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
  if (HAL_TIM_IC_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigIC.ICPolarity = TIM_INPUTCHANNELPOLARITY_RISING;
  sConfigIC.ICSelection = TIM_ICSELECTION_DIRECTTI;
  sConfigIC.ICPrescaler = TIM_ICPSC_DIV1;
  sConfigIC.ICFilter = 0;
  if (HAL_TIM_IC_ConfigChannel(&htim3, &sConfigIC, TIM_CHANNEL_2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */

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
  /* USER CODE BEGIN TIM2_MspInit 1 */

  /* USER CODE END TIM2_MspInit 1 */
  }
  else if(tim_baseHandle->Instance==TIM3)
  {
  /* USER CODE BEGIN TIM3_MspInit 0 */

  /* USER CODE END TIM3_MspInit 0 */
    /* TIM3 clock enable */
    __HAL_RCC_TIM3_CLK_ENABLE();

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

    /* TIM3 interrupt Init */
    HAL_NVIC_SetPriority(TIM3_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(TIM3_IRQn);
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
  if(timHandle->Instance==TIM2)
  {
  /* USER CODE BEGIN TIM2_MspPostInit 0 */

  /* USER CODE END TIM2_MspPostInit 0 */

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

  /* USER CODE BEGIN TIM2_MspPostInit 1 */

  /* USER CODE END TIM2_MspPostInit 1 */
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
  /* USER CODE BEGIN TIM2_MspDeInit 1 */

  /* USER CODE END TIM2_MspDeInit 1 */
  }
  else if(tim_baseHandle->Instance==TIM3)
  {
  /* USER CODE BEGIN TIM3_MspDeInit 0 */

  /* USER CODE END TIM3_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_TIM3_CLK_DISABLE();

    /**TIM3 GPIO Configuration
    PA7     ------> TIM3_CH2
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_7);

    /* TIM3 interrupt Deinit */
    HAL_NVIC_DisableIRQ(TIM3_IRQn);
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
// key
void key_init(void)
{
	HAL_TIM_Base_Start_IT(&htim4);
}

struct _key {
	uint8_t key_step;
	bool key_pin_state;
	bool key_is_down;
	uint32_t key_time;
	bool key_is_long;
};

struct _key key_buf[4] = {0};
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
					key_buf[i].key_is_long = 0;
					key_buf[i].key_time = 0;
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
					key_buf[i].key_is_long = 0;
					key_buf[i].key_time = 0;
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
					key_buf[i].key_is_long = 0;
					key_buf[i].key_time = 0;
				}
			break;				
		}
	}
}

extern bool is_high;
extern float MH;
extern float ML;
extern uint8_t led_8bits;

float tmp_MH = 0, tmp_ML = 0;
uint32_t max_vh_cnt = 0, max_vl_cnt = 0;

bool switch_lock = 0;
uint32_t switch_lock_cnt = 0;
float fre_out = 4000.0f;
extern float duty;
extern float V;

bool mh_lock = 1, ml_lock = 1;
void pwm_set_fre_duty(uint32_t fre, uint32_t duty);
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIM4)
	{
		key_scan();
		
		if(switch_lock == 1)
		{
			switch_lock_cnt++;
			
			if((switch_lock_cnt % 10) == 0)
			{
				led_8bits = led_8bits ^ (1 << 1);
			}
			
			if((switch_lock_cnt % 25) == 0)
			{
				if(is_high == 1 && fre_out > 4000)
				{
					fre_out -= 200;
					if(fre_out < 4000) fre_out = 4000;
				}
				else if(is_high == 0 && fre_out < 8000)
				{
					fre_out += 200;
					if(fre_out > 8000) fre_out = 8000;
				}

				pwm_set_fre_duty(fre_out, duty);
			}

			
			if(switch_lock_cnt >= 500)
			{
				switch_lock_cnt = 0;
				switch_lock = 0;
				
				led_8bits &= ~(1 << 1);
				
				if(is_high == 1)
				{
					fre_out = 4000.0f;
					is_high = 0;
				}
				else if(is_high == 0)
				{
					fre_out = 8000.0f;
					is_high = 1;
				}
				
				pwm_set_fre_duty(fre_out, duty);
			}
		}
		else
		{
			switch_lock_cnt = 0;
		}
		
		if(mh_lock == 0)
		{
			max_vh_cnt++;
			if(max_vh_cnt >= 200)
			{
				mh_lock = 1;
				max_vh_cnt = 0;
				MH = tmp_MH;
			}
		}
		
		if(ml_lock == 0)
		{
			max_vl_cnt++;
			if(max_vl_cnt >= 200)
			{
				ml_lock = 1;
				max_vl_cnt = 0;
				ML = tmp_ML;
			}
		}
	}
}

extern uint8_t lcd_num ;

extern uint8_t R , K , tmp_R, tmp_K;
extern uint32_t N;

bool is_select_r = 1;
uint8_t duty_lock_step = 0;
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
					lcd_num++;
					if(lcd_num > 2)
					{
						lcd_num = 0;
					}
					
					if(lcd_num == 1)
					{
						is_select_r = 1;
					}
					
					if(lcd_num == 2)
					{
						R = tmp_R;
						K = tmp_K;
					}
				break;
				case 1:
					key_buf[i].key_is_down = 0;
					if(lcd_num == 0)
					{
						// 切换高低平，5s内锁定不可再触发
						if(switch_lock == 0)
						{
							switch_lock = 1;	
							N++;
						}
					}
					else if(lcd_num == 1)
					{
						// 切换选择的参数，�?出时才生�?
						is_select_r ^= 1;
					}
				break;
				case 2:
					key_buf[i].key_is_down = 0;
					if(lcd_num == 1)
					{
						if(is_select_r == 1)
						{
							tmp_R++;
							if(tmp_R > 10)
							{
								tmp_R = 1;
							}
						}
						else
						{
							tmp_K++;
							if(tmp_K > 10)
							{
								tmp_K = 1;
							}
						}
					}
				break;
				case 3:
					if(lcd_num == 1)
					{
						key_buf[i].key_is_down = 0;
						if(is_select_r == 1)
						{
							tmp_R--;
							if(tmp_R < 1)
							{
								tmp_R = 10;
							}
						}
						else
						{
							tmp_K--;
							if(tmp_K < 1)
							{
								tmp_K = 10;
							}
						}
					}
					else if(lcd_num == 0)
					{
						// 长按锁定占空�?,再次短按解锁
						if(duty_lock_step == 0)
						{
							// 长按进入锁定
							if(key_buf[3].key_is_long == 1)
							{
								duty_lock_step = 1;	// 松开后处�?
							}
						}
						else if(duty_lock_step == 2)
						{
							key_buf[i].key_is_down = 0;
							duty_lock_step = 0;
						}
					}
				break;
			}
		}
		
		if(duty_lock_step == 1)
		{
			if(key_buf[3].key_is_down == 0)
			{
				duty_lock_step = 2;	// 触发锁定，等待短按解�?
			}
		}
	}
}

// pwm
void pwm_init(void)
{
	HAL_TIM_IC_Start_IT(&htim3, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
	HAL_Delay(100);
}

void pwm_set_fre_duty(uint32_t fre, uint32_t duty)
{
    uint32_t clk = 80000000;
    uint32_t div = 1;
    uint32_t period = clk / div / fre - 1;
    uint32_t pulse  = period * duty / 100;
    if (pulse > period) pulse = period - 1; // 防止CCR超出ARR

    // 设置周期与占空比
    TIM2->ARR  = period;
    TIM2->CCR2 = pulse;

    // 强制立即更新（如果启用了预装载）
    TIM2->EGR |= TIM_EGR_UG;

    // 启动定时器
    TIM2->CR1 |= TIM_CR1_CEN;
}

float fre;
bool is_first = 1;
uint32_t tmp1, tmp2, tmp_sub;
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIM3)
	{
		if(is_first)
		{
			tmp1 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_2);
		}
		else
		{
			tmp2 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_2);
			tmp_sub = (tmp2 > tmp1) ? (tmp2 - tmp1) : (0xffff + tmp2 - tmp1);
			
			if(tmp_sub != 0)
			{
				fre = 1000000.0f / (tmp_sub);
			}
		}
		is_first ^= 1;
	}
	
}

bool is_switch = 0;

void pwm_task(void)
{
	V = fre * 2.0f * 3.14f * (float)R / (100.0f * (float)K);
	// 要加进任务调度才行，否则下面的if作比较会出问题
	if((V > MH) && (is_high == 1))
	{
		if(V != tmp_MH)
		{
			tmp_MH = V;	
			max_vh_cnt = 0;
			mh_lock = 0;
		}
	}
	
	if((V > ML) && (is_high == 0))
	{ 
		if(V != tmp_ML)
		{
			tmp_ML = V;
			max_vl_cnt = 0;
			ml_lock = 0;			
		}
	}
	
	// pwm_out
	// 尝试异步处理pwm输出
	pwm_set_fre_duty(fre_out, duty);
}

/* USER CODE END 1 */
