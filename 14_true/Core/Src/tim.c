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
  htim3.Init.Period = 3999;
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
  sConfigOC.Pulse = 1999;
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
// key *****************************************************************
struct keys {
	uint8_t key_step;
	bool key_pin_state;
	bool key_is_down;
	uint32_t key_time;
	bool key_is_long;
};

struct keys key_buf[4] = {0};

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
			}
			break;
			case 2:
			if(key_buf[i].key_pin_state == 0)
			{
//				key_buf[i].key_step = 1;
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
			}
			break;
			
		}
	}
}

void key_init(void)
{
	HAL_TIM_Base_Start_IT(&htim4);
}

extern bool ld1_toggle, ld2_toggle, ld3_toggle;
extern uint8_t led_8bits;

uint8_t ld1_cnt, ld2_cnt, ld3_cnt;
uint8_t record_flag, review_flag;	// rcd:1，记录状�?    rev:0 非回放，2 回放脉冲�? 1 回放电压

struct _record {
	float r37_val;
	float pa1_fre;
	float pa1_duty;
};

struct _record rcd_buf[500] = {0};	// 200ms存一次，500条可以存200 * 500 = 100000ms = 100s
uint16_t rcd_index = 0;
uint32_t rcd_time_cnt = 0;
uint16_t review_power_index = 0;
uint32_t review_power_cnt = 0;	// 电压回放计数�?
uint16_t review_pwm_index = 0;
uint32_t review_pwm_cnt = 0;	// 脉冲回放计数�?
bool uart_flag = 0;
bool pwm_flag = 0;
float tmp_fre, tmp_duty;

float fre, duty;
bool device_lock = 0;

extern uint32_t FP, TT;
extern float r37_val;
extern float VP;

void pwm_set_fre_duty(float fre, float duty);

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIM4)
	{
		key_scan();
		if(record_flag == 1)
		{
			ld1_cnt++;
			if(ld1_cnt >= 10)
			{
				ld1_cnt = 0;
				led_8bits ^= (1 << 0);
			}
		}
		else
		{
			ld1_cnt = 0;
			led_8bits &= ~(1 << 0);
		}
		
		if(review_flag == 2)
		{
			ld2_cnt++;
			if(ld2_cnt >= 10)
			{
				ld2_cnt = 0;
				led_8bits ^= (1 << 1);
			}
		}
		else 
		{
			ld2_cnt = 0;
			led_8bits &= ~(1 << 1);
		}
		
		if(review_flag == 1)
		{
			ld3_cnt++;
			if(ld3_cnt >= 10)
			{
				ld3_cnt = 0;
				led_8bits ^= (1 << 2);
			}
		}
		else
		{
			ld3_cnt = 0;
			led_8bits &= ~(1 << 2);
		}
		
		// 记录
		if(record_flag == 1)
		{
			if((rcd_time_cnt % 50) == 0)
			{
				rcd_buf[rcd_index].r37_val = r37_val;
				rcd_buf[rcd_index].pa1_fre = fre;
				rcd_buf[rcd_index].pa1_duty = duty;
				
				rcd_index++;
				if(rcd_index >= 500)	// 有没有可能�?�成溢出�?
				{
					rcd_index = 499;
				}
			}
			rcd_time_cnt++;
			
			if(rcd_time_cnt >= TT * 100)
			{
				record_flag = 0;
				rcd_index = 0;
				rcd_time_cnt = 0;
				device_lock = 0;
				uart_flag = 1;
			}
		}
		// 回放
		if(review_flag == 1)
		{
			// 回放电压
			if((review_power_cnt % 50) == 0)
			{
			
				if(rcd_buf[review_power_index].r37_val < VP)
				{
					tmp_duty = 10;
				}
				else if(rcd_buf[review_power_index].r37_val >= 3.3f)
				{
					tmp_duty = 100;
				}
				else
				{
					float k = (90 / (3.3f - VP));
					float b = (100 - 3.3f * k);
					tmp_duty = rcd_buf[review_power_index].r37_val * k + b;
				}
				
				review_power_index++;
				if(review_power_index >= 500)	// 有没有可能�?�成溢出�?
				{
					review_power_index = 499;
				}
				
				tmp_fre = 1000;
				
//				pwm_set_fre_duty(tmp_fre, tmp_duty);
				pwm_flag = 1;
			}
			
			review_power_cnt++;
			if(review_power_cnt >= TT * 100)
			{
				review_flag = 0;
				review_power_cnt = 0;
				review_power_index = 0;
				pwm_flag = 0;
			}
		}
		
		if(review_flag == 2)
		{
			// 回放脉冲
			if((review_pwm_cnt % 50) == 0)
			{
			
				tmp_fre = rcd_buf[review_pwm_index].pa1_fre / FP;
				tmp_duty = rcd_buf[review_pwm_index].pa1_duty * 100;
				
				review_pwm_index++;
				if(review_pwm_index >= 500)	// 有没有可能�?�成溢出�?
				{
					review_pwm_index = 499;
				}
				
//				pwm_set_fre_duty(tmp_fre, tmp_duty);
				pwm_flag = 1;
			}
			
			review_pwm_cnt++;
			if(review_pwm_cnt >= TT * 100)
			{
				review_flag = 0;
				review_pwm_cnt = 0;
				review_pwm_index = 0;
				pwm_flag = 0;
			}
		}
	}
}

extern uint8_t lcd_num;
uint8_t para_select = 0;	// FH, AH, TH
uint8_t fset_select = 0;	// FP, VP, TT

uint8_t key3_flag, key4_flag;
bool reset = 1;

extern uint32_t FH, TH;
extern float AH;
uint32_t FH_raw, TH_raw;
float AH_raw;

uint32_t FP_raw, TT_raw;
float VP_raw;
bool fn_lock = 0, an_lock = 0;

extern uint32_t FN, AN, TN;
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
					if(!device_lock)
					{
						lcd_num++;
						if(lcd_num > 3)
						{
							lcd_num = 0;
						}
						
						if(lcd_num == 0)
						{
							// FP,VP,TT生效
							FP = FP_raw;
							VP = VP_raw;
							TT = TT_raw;
						}
						
						if(lcd_num == 1)
						{
							para_select = 0;
						}
						
						if(lcd_num == 2)
						{
							// FH,AH,TH生效
							FH = FH_raw;
							AH = AH_raw;
							TH = TH_raw;
						}
						
						if(lcd_num == 3)
						{
							fset_select = 0;
						}
					}
				break;
				case 1:
					key_buf[i].key_is_down = 0;	
					if(!device_lock)
					{
						if(lcd_num == 0)
						{
							// [记录]记录R37，PA1捕获，设备锁定不可按键操�?
							device_lock = 1;
							HAL_Delay(1000);	// 测评点感觉有延后
							record_flag = 1;
						}
						else if(lcd_num == 1)
						{
							// 切换选择按键
							para_select++;
							if(para_select > 2)
							{
								para_select = 0;
							}
						}
						else if(lcd_num == 3)
						{
							// 切换选择按键
							fset_select++;
							if(fset_select > 2)
							{
								fset_select = 0;
							}
						}
						else if(lcd_num == 2)
						{
							FN = 0;
							AN = 0;
							TN = 0;
						}
					}					
				break;
				case 2:
					// 应该是松�?了才生效
					key3_flag = 1;
				break;
				case 3:
					// 应该是松�?了才生效
					key4_flag = 1;
				break;
			}
		}
	}
	
	if(key_buf[2].key_is_down == 0)
	{
		if(key3_flag == 1)
		{
			key3_flag = 0;
			if(key_buf[2].key_is_long == 0)
			{
				// 短按
				if(!device_lock)
				{
					if(lcd_num == 1)
					{
						switch(para_select)
						{
							case 0:
								FH_raw += 1000;
								if(FH_raw > 10000)
								{
									FH_raw = 10000;
								}
							break;
							case 1:
								AH_raw += 0.3f;
								if(AH_raw > 3.3f)
								{
									AH_raw = 3.3f;
								}
							break;
							case 2:
								TH_raw += 1;
								if(TH_raw > 80)
								{
									TH_raw = 80;
								}
							break;
						}
					}
					else if(lcd_num == 3)
					{
						switch(fset_select)
						{
							case 0:
								FP_raw += 1;
								if(FP_raw > 10)
								{
									FP_raw = 10;
								}
							break;
							case 1:
								VP_raw += 0.3f;
								if(VP_raw > 3.3f)
								{
									VP_raw = 3.3f;
								}
							break;
							case 2:
								TT_raw += 2;
								if(TT_raw > 10)
								{
									TT_raw = 10;
								}
							break;
						}
					}
					else if(lcd_num == 0)
					{
						// [回放]若设备已完成数据记录，则通过PA7回放电压信号
//						HAL_Delay(2000);	// 测评点感觉有延后
						review_flag = 1;
					}
				}
			}
			else
			{
				// 长按
				if(key_buf[3].key_is_long == 1)
				{
					// 重置
					reset = 1;
				}
			}
		}
		
		
		key_buf[2].key_time = 0;
		key_buf[2].key_is_long = 0;
	}
	
	if(key_buf[3].key_is_down == 0)
	{
		if(key4_flag == 1)
		{
			key4_flag = 0;
			if(key_buf[3].key_is_long == 0)
			{
				// 短按
				if(!device_lock)
				{
					if(lcd_num == 1)
					{
						switch(para_select)
						{
							case 0:
								if(FH_raw == 1000)
								{
									FH_raw += 1000;
								}
								FH_raw -= 1000;
							break;
							case 1:
								if(AH_raw < 0.3f)
								{
									AH_raw += 0.3f;	// float是不准的，不能用== 0
								}
								AH_raw -= 0.3f;
							break;
							case 2:
								if(TH_raw == 0)
								{
									TH_raw += 1;
								}
								TH_raw -= 1;
							break;
						}
					}
					else if(lcd_num == 3)
					{
						switch(fset_select)
						{
							case 0:
								if(FP_raw == 1)
								{
									FP_raw += 1;
								}
								FP_raw -= 1;
							break;
							case 1:
								if(VP_raw < 0.3f)
								{
									VP_raw += 0.3f;
								}
								VP_raw -= 0.3f;
							break;
							case 2:
								if(TT_raw == 2)
								{
									TT_raw += 2;
								}
								TT_raw -= 2;
							break;
						}
					}
					else if(lcd_num == 0)
					{
						// [回放]若设备已完成数据记录，则通过PA7回放脉冲信号
//						HAL_Delay(2000);	// 测评点感觉有延后
						review_flag = 2;
					}
				}
			}
			else
			{
				// 长按
				if(key_buf[2].key_is_long == 1)
				{
					// 重置
					reset = 1;
				}
			}
			
		}
		
		key_buf[3].key_time = 0;
		key_buf[3].key_is_long = 0;
		
		if(reset == 1)
		{
			reset = 0;
			
			lcd_num = 0;
			
			FH = 2000;
			AH = 3.0;
			TH = 30;
			
			FH_raw = FH;
			AH_raw = AH;
			TH_raw = TH;
			
			FP = 1;
			VP = 0.9;
			TT = 6;
			
			FP_raw = FP;
			TT_raw = TT;
			VP_raw = VP;
			
			FN = 0;
			AN = 0;
			TN = 0;
			
			fn_lock = 0;
			an_lock = 0;
		}
	}
}

// pwm *****************************************************************
void pwm_init(void)
{
	HAL_TIM_IC_Start_IT(&htim2, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
//	pwm_set_fre_duty(1000, 50);
}

void pwm_set_fre_duty(float fre, float duty)
{
	uint32_t clk = 80000000;
	uint8_t div = 10;
	uint32_t period = clk / div / fre - 1;
	uint32_t pulse = period * duty / 100;
	
	if(pulse > period)
	{
		pulse = period - 1;
	}
	
	TIM3->ARR = period;
	TIM3->CCR2 = pulse;
	
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
}

float fre, duty;
bool is_first = 1, is_rising = 1;
uint32_t fre_cnt1, fre_cnt2, duty_cnt1, duty_cnt2;
uint32_t fre_cnt_sub, duty_cnt_sub;
// 待验�?
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIM2)
	{
		if(is_rising)
		{
			// 上升沿进�?
			if(is_first)
			{
				fre_cnt1 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_2);
				duty_cnt1 = fre_cnt1;
			}
			else
			{
				fre_cnt2 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_2);
				
				fre_cnt_sub = (fre_cnt2 > fre_cnt1) ? (fre_cnt2 - fre_cnt1) : (0xffffffff + fre_cnt2 - fre_cnt1);
				
				if(fre_cnt_sub != 0)
				{
					fre = 80000000 / 80 / fre_cnt_sub;
				}
			}
			
			is_first ^= 1;
			__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_2, TIM_INPUTCHANNELPOLARITY_FALLING);
		}
		else
		{
			// 下降沿进�?
			duty_cnt2 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_2);
			duty_cnt_sub = (duty_cnt2 > duty_cnt1) ? (duty_cnt2 - duty_cnt1) : (0xffff + duty_cnt2 - duty_cnt1);
			
			if(fre_cnt_sub != 0 && (fre_cnt_sub >= duty_cnt_sub))
			{
				duty = (float)duty_cnt_sub / (float)fre_cnt_sub;
			}
			
			__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_2, TIM_INPUTCHANNELPOLARITY_RISING);
		}
		
		is_rising ^= 1;
	}
}

void pwm_task(void)
{
	if(((uint32_t)fre > FH) && (fn_lock == 0))
	{
		fn_lock = 1;
		FN++;
	}
	else if((uint32_t)fre <= FH)
	{
		fn_lock = 0;
	}
	
	if((r37_val > AH ) && (an_lock == 0))
	{
		an_lock = 1;
		AN++;
	}
	else if((r37_val <= AH) && (an_lock == 1))
	{
		an_lock = 0;
	}
	
	// 回放
//	if(uart_flag == 1)
//	{
//		uart_flag = 0;
//		for(uint8_t i = 0;i < 60;i++)
//		{
//			printf("r37_val=%.1f, fre=%.1f, duty=%.1f\n", rcd_buf[i].r37_val, rcd_buf[i].pa1_fre, rcd_buf[i].pa1_duty);
//		}
//		printf("*************************************\n");
//	}
	
	if(review_flag == 0)
	{
		pwm_set_fre_duty(2000, 0);
	}
	
	if((pwm_flag == 1) && (review_flag != 0))
	{
		pwm_flag = 0;
		pwm_set_fre_duty(tmp_fre, tmp_duty);
//		printf("tmp_fre = %.1f, tmp_duty = %.1f\n", tmp_fre, tmp_duty);
	}
}
/* USER CODE END 1 */
