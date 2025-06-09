/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    usart.c
  * @brief   This file provides code for the configuration
  *          of the USART instances.
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
#include "usart.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

UART_HandleTypeDef huart1;

/* USART1 init function */

void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 9600;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart1.Init.ClockPrescaler = UART_PRESCALER_DIV1;
  huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetTxFifoThreshold(&huart1, UART_TXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetRxFifoThreshold(&huart1, UART_RXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_DisableFifoMode(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

void HAL_UART_MspInit(UART_HandleTypeDef* uartHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};
  if(uartHandle->Instance==USART1)
  {
  /* USER CODE BEGIN USART1_MspInit 0 */

  /* USER CODE END USART1_MspInit 0 */

  /** Initializes the peripherals clocks
  */
    PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART1;
    PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK2;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
    {
      Error_Handler();
    }

    /* USART1 clock enable */
    __HAL_RCC_USART1_CLK_ENABLE();

    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**USART1 GPIO Configuration
    PA9     ------> USART1_TX
    PA10     ------> USART1_RX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_9|GPIO_PIN_10;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART1;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* USART1 interrupt Init */
    HAL_NVIC_SetPriority(USART1_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(USART1_IRQn);
  /* USER CODE BEGIN USART1_MspInit 1 */

  /* USER CODE END USART1_MspInit 1 */
  }
}

void HAL_UART_MspDeInit(UART_HandleTypeDef* uartHandle)
{

  if(uartHandle->Instance==USART1)
  {
  /* USER CODE BEGIN USART1_MspDeInit 0 */

  /* USER CODE END USART1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_USART1_CLK_DISABLE();

    /**USART1 GPIO Configuration
    PA9     ------> USART1_TX
    PA10     ------> USART1_RX
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_9|GPIO_PIN_10);

    /* USART1 interrupt Deinit */
    HAL_NVIC_DisableIRQ(USART1_IRQn);
  /* USER CODE BEGIN USART1_MspDeInit 1 */

  /* USER CODE END USART1_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */
int fputc(int ch, FILE *f)
{
	HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, HAL_MAX_DELAY);
	return ch;
}

// 不定长接收
struct _uart_struct{
	char uart_rcv_buf[120];
	char uart_dat;
	uint8_t uart_ptr;
	
	bool uart_start_flag;
	bool uart_end_flag;
	uint32_t uart_time_cnt;
};

struct _uart_struct uart_struct = {0};

int16_t pos[400];
int16_t FP[2];	// 目的地坐标,始终为最后两个元素
void uart_init(void)
{
	memset(pos, -1, sizeof(pos));
	memset(FP, -1, sizeof(FP));
	HAL_UART_Receive_IT(&huart1, (uint8_t *)&uart_struct.uart_dat, 1);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if(uart_struct.uart_ptr >= 120)
	{
		// 溢出
		uart_struct.uart_ptr = 0;
		uart_struct.uart_end_flag = 0;
		uart_struct.uart_start_flag = 0;
		uart_struct.uart_time_cnt = 0;
	}
	else
	{
		uart_struct.uart_start_flag = 1;
		uart_struct.uart_time_cnt = 0;
		uart_struct.uart_end_flag = 0;
	}
	
	uart_struct.uart_rcv_buf[uart_struct.uart_ptr++] = uart_struct.uart_dat;
	HAL_UART_Receive_IT(&huart1, (uint8_t *)&uart_struct.uart_dat, 1);
}

void uart_tim(void)
{
	if(uart_struct.uart_start_flag == 1)
	{
		uart_struct.uart_time_cnt++;
		if(uart_struct.uart_time_cnt >= 10)
		{
			uart_struct.uart_end_flag = 1;
			uart_struct.uart_start_flag = 0;
			uart_struct.uart_time_cnt = 0;
		}
	}
}


uint16_t pos_ptr = 0;	// 指向pos中的最后一个空元素

uint8_t scene = 0;
extern int16_t CP[2];
extern uint8_t ST;
uint32_t tmp = 0;
extern uint32_t RN;
void uart_task(void)
{
	if(uart_struct.uart_end_flag == 1)
	{
		// 处理逻辑
		if((uart_struct.uart_rcv_buf[0] == '(' )&& (uart_struct.uart_ptr > 0) && (uart_struct.uart_rcv_buf[uart_struct.uart_ptr - 1] == ')'))
		{
			uint32_t count = 0;
			for(uint32_t i = 0;i < uart_struct.uart_ptr;i++)
			{
				if(uart_struct.uart_rcv_buf[i] == ',')
				{
					count++;
				}
			}
			
			if(count % 2 == 1)
			{
				if(ST == 0)
				{
					// 设置途径，目标点, 尚未检查中间数据格式不符合的情况
					for(uint32_t i = 1;i < uart_struct.uart_ptr;i++)
					{
						if((uart_struct.uart_rcv_buf[i] != ',') && ((uart_struct.uart_rcv_buf[i] != ')')))
						{
							tmp = tmp * 10 + uart_struct.uart_rcv_buf[i] - '0';
						}
						else if(uart_struct.uart_rcv_buf[i] == ',')
						{
							pos[pos_ptr] = tmp;
							tmp = 0;
							pos_ptr++;
						}
						else if(uart_struct.uart_rcv_buf[i] == ')')
						{
							pos[pos_ptr] = tmp;
							tmp = 0;
							pos_ptr++;
						}
					}
					
					if((pos_ptr % 2) == 0)
					{
						RN = pos_ptr / 2;
						FP[0] = pos[pos_ptr - 2];
						FP[1] = pos[pos_ptr - 1];
						
						printf("Got it");
					}
					else
					{
						pos[pos_ptr] = -1;
						pos_ptr--;
						printf("Error");
					}
					
				}
				else
				{
					printf("Busy");
				}
			}
			else
			{
				printf("Error");
			}
			
		}
		else if((uart_struct.uart_rcv_buf[0] == '{' )&& (uart_struct.uart_ptr > 0) && (uart_struct.uart_rcv_buf[uart_struct.uart_ptr - 1] == '}'))
		{
			uint32_t tmp[2] = {0}, tmp_ptr = 0, tmpX, tmpY;
			for(uint32_t i = 1;i < uart_struct.uart_ptr;i++)
			{
				if((uart_struct.uart_rcv_buf[i] != ',') && ((uart_struct.uart_rcv_buf[i] != '}')))
				{
					tmp[tmp_ptr] = tmp[tmp_ptr] * 10 + uart_struct.uart_rcv_buf[i] - '0';
				}
				else if(uart_struct.uart_rcv_buf[i] == ',')
				{
					tmp_ptr++;
				}
				else if(uart_struct.uart_rcv_buf[i] == ')')
				{
					tmp_ptr++;
				}
			}
			
			tmpX = tmp[0];
			tmpY = tmp[1];
			
			uint32_t i = 0;
			for(;i < pos_ptr - 1;i += 2)
			{
				if((pos[i] == tmpX) && (pos[i + 1] == tmpY))
				{
					pos[i] = -1;
					pos[i + 1] = -1;
					RN--;
					break;
				}
			}
			
			if(i < pos_ptr - 1)
			{
				printf("Got it");
			}
			else
			{
				printf("Nonexistent");
			}
		}
		else if((uart_struct.uart_rcv_buf[0] == '[' )&& (uart_struct.uart_ptr > 0) && (uart_struct.uart_rcv_buf[uart_struct.uart_ptr - 1] == ']'))		
		{
			if(ST == 1)
			{
				uint8_t tmp;
				tmp = uart_struct.uart_rcv_buf[1] - '0';
				if((tmp >= 1) && (tmp <= 4))
				{
					scene = tmp - 1;
					printf("Got it");
				}
				else
				{
					printf("Device offline");
				}
			}
			else
			{
				printf("Device offline");
			}
		}
		else if(uart_struct.uart_rcv_buf[0] == '?' )
		{
			switch(ST)
			{
				case 0:
					printf("Idle");
				break;
				case 1:
					printf("Busy");
				break;
				case 2:
					printf("Wait");
				break;
			}
		}
		else if(uart_struct.uart_rcv_buf[0] == '#' )
		{
			printf("(%d,%d)", CP[0], CP[1]);
		}
		else
		{
			printf("Error");
		}
		
		uart_struct.uart_ptr = 0;
		uart_struct.uart_end_flag = 0;
		uart_struct.uart_start_flag = 0;
		uart_struct.uart_time_cnt = 0;
		
		memset(uart_struct.uart_rcv_buf, 0 ,sizeof(uart_struct.uart_rcv_buf));
	}
}
// (48,92,90,100,200,3,20,60) {200,3}
/* USER CODE END 1 */
