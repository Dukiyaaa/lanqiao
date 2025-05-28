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
  htim2.Init.Prescaler = 10 - 1;
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
  TIM_IC_InitTypeDef sConfigIC = {0};

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
  if (HAL_TIM_IC_ConfigChannel(&htim3, &sConfigIC, TIM_CHANNEL_1) != HAL_OK)
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

    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**TIM3 GPIO Configuration
    PB4     ------> TIM3_CH1
    */
    GPIO_InitStruct.Pin = GPIO_PIN_4;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF2_TIM3;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

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

    /**TIM3 GPIO Configuration
    PB4     ------> TIM3_CH1
    */
    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_4);

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
struct _key {
	uint8_t key_step;
	bool key_pin_state;
	bool key_is_down;
	uint32_t key_time;
	bool key_is_long;
};

struct _key key_buf[4] = {0};

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
				key_buf[i].key_time = 0;
				key_buf[i].key_is_long = 0;
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
				key_buf[i].key_time = 0;
				key_buf[i].key_is_long = 0;
			}
			break;
			case 2:
			if(key_buf[i].key_pin_state == 0)
			{
					key_buf[i].key_time++;
					if(key_buf[i].key_time >= 100)
					{
						key_buf[i].key_is_long = 1;
					}					
			}			
			else
			{
				key_buf[i].key_step = 0;
				key_buf[i].key_is_down = 0;
				key_buf[i].key_time = 0;
				key_buf[i].key_is_long = 0;
			}
			break;
		}
	}
}

bool is_3s = 0;	// 1,已到3s
uint32_t is_3s_cnt = 0;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIM4)
	{
		key_scan();
		is_3s_cnt++;
		if((is_3s == 0) && (is_3s_cnt >= 300))
		{
			is_3s = 1;
			is_3s_cnt = 0;
		}
	}
}

extern int32_t PX;
extern int32_t PD, PH;
extern uint8_t lcd_num;
extern bool is_fre;
extern uint32_t NDA, NDB, NHA, NHB;

uint8_t is_select = 0;	// 0:PD, 1:PH, 2:PX;
bool key3_flag = 0;		// 1时表示被按下
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
					if(lcd_num == 1)
					{
						switch(is_select)
						{
							case 0:
								PD += 100;
								if(PD > 1000)
								{
									PD = 1000;
								}
							break;
							case 1:
								PH += 100;
								if(PH > 10000)
								{
									PH = 10000;
								}
							break;
							case 2:
								PX += 100;
								if(PX > 1000)
								{
									PX = 1000;
								}
							break;
						}
					}
				break;
				case 1:
					key_buf[i].key_is_down = 0;
					if(lcd_num == 1)
					{
						switch(is_select)
						{
							case 0:
								PD -= 100;
								if(PD < 100)
								{
									PD = 100;
								}
							break;
							case 1:
								PH -= 100;
								if(PH < 1000)
								{
									PH = 1000;
								}
							break;
							case 2:
								PX -= 100;
								if(PX < -1000)
								{
									PX = -1000;
								}
							break;
						}
					}
				break;
				case 2:
					// 短按
					if(lcd_num == 1)
					{
						key_buf[i].key_is_down = 0;
						is_select++;
						if(is_select > 2)
						{
							is_select = 0;
						}
					}
					else if(lcd_num == 0)
					{
						key_buf[i].key_is_down = 0;
						is_fre ^= 1;	// 切换显示模式
					}
					else if(lcd_num == 2)
					{
						if(key_buf[2].key_is_long == 1)
						{
							key3_flag = 1;
						}
					}
				break;
				case 3:
					key_buf[i].key_is_down = 0;
					lcd_num++;
					if(lcd_num > 2)
					{
						lcd_num = 0;
					}
					
					if(lcd_num == 0)
					{
						is_fre = 1;
					}
					
					if(lcd_num == 1)
					{
						is_select = 0;
					}
				break;
			}
		}
		
		if(key3_flag == 1)
		{
			if(key_buf[2].key_is_long == 0)
			{
				key3_flag = 0;
				if(lcd_num == 2)
				{
					NHA = 0;
					NHB = 0;
					NDA = 0;
					NDB = 0;
				}
			}
		}
	}
}

// pwm
float freA, freB;
void pwm_init(void)
{
	HAL_TIM_IC_Start_IT(&htim2, TIM_CHANNEL_1);	// PA15, freA
	HAL_TIM_IC_Start_IT(&htim3, TIM_CHANNEL_1);	// PB4 , freB
}

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIM2)
	{
		uint32_t tmp = HAL_TIM_ReadCapturedValue(&htim2, TIM_CHANNEL_1);
		
		if(tmp != 0)
		{
			freA = 8000000.0f / (float)tmp;
		}
		
		if(freA > 20000)
		{
			freA = 20000;
		}
		
		if(freA < 400)
		{
			freA = 400;
		}
		
		freA += PX;

		__HAL_TIM_SET_COUNTER(&htim2, 0);
		HAL_TIM_IC_Start_IT(&htim2, TIM_CHANNEL_1);
	}
	
	if(htim->Instance == TIM3)
	{
		uint32_t tmp = HAL_TIM_ReadCapturedValue(&htim3, TIM_CHANNEL_1);
		
		if(tmp != 0)
		{
			freB = 8000000.0f / (float)tmp;
		}
		
		if(freB > 20000)
		{
			freB = 20000;
		}
		
		if(freB < 400)
		{
			freB = 400;
		}
		
		freB += PX;
		
		__HAL_TIM_SET_COUNTER(&htim3, 0);
		HAL_TIM_IC_Start_IT(&htim3, TIM_CHANNEL_1);
	}
}
float faMAX, fbMAX, faMIN, fbMIN;

bool NHA_lock = 1, NHB_lock = 1;
void pwm_task(void)
{	
	// 超限
	if((NHA_lock == 0) && ((freA - (float)PH) > 10))
	{
		NHA++;
		NHA_lock = 1;
	}
	else if((NHA_lock == 1) && (((float)PH - freA) > 10))
	{
		NHA_lock = 0;
	}
	
	if((NHB_lock == 0) && ((freB - (float)PH) > 10))
	{
		NHB++;
		NHB_lock = 1;
	}
	else if((NHB_lock == 1) && (((float)PH - freB) > 10))
	{
		NHB_lock = 0;
	}
	
	// 突变,3s判断一次
	if(freA > faMAX)
	{
		faMAX = freA;
	}
	
	if(freB > fbMAX)
	{
		fbMAX = freB;
	}
	
	if((freA >= 0) && (freA < faMIN))
	{
		faMIN = freA;
	}
	
	if((freB >= 0) && (freB < fbMIN))
	{
		fbMIN = freB;
	}
	
	if(is_3s == 1)
	{
		if(((faMAX - faMIN) - PD) >= 5)
		{
			NDA++;
		}
		
		if(((fbMAX - fbMIN) - PD) >= 5)
		{
			NDB++;
		}
		
		faMAX = -1;
		faMIN = 40000;
		fbMAX = -1;
		fbMIN = 40000;
		is_3s = 0;
	}
	
}
/* USER CODE END 1 */
