/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
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
#include "main.h"
#include "usb_device.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "usbd_hid.h"
extern USBD_HandleTypeDef hUsbDeviceFS;
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim3;

/* USER CODE BEGIN PV */
extern USBD_HandleTypeDef hUsbDeviceFS;

typedef struct
{
	uint8_t MODIFIER;
	uint8_t RESERVED;
	uint8_t KEYCODE1;
	uint8_t KEYCODE2;
	uint8_t KEYCODE3;
	uint8_t KEYCODE4;
	uint8_t KEYCODE5;
	uint8_t KEYCODE6;
}subKeyBoard;

subKeyBoard keyBoardHIDsub = {0,0,0,0,0,0,0,0};
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM3_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
//int rot_cnt = 0;
//uint8_t rot_new_state = 0;
//uint8_t rot_old_state = 0;
//
//uint16_t rot_a_pin = 4;
//uint16_t rot_b_pin = 5;
//
//uint8_t rot_get_state() {
//	return (uint8_t)((HAL_GPIO_ReadPin(GPIOB, rot_b_pin) << 1)
//                | (HAL_GPIO_ReadPin(GPIOB, rot_a_pin)));
//}
//
//// External interrupts from rotary encoder
//void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
//	if (GPIO_Pin == rot_a_pin || GPIO_Pin == rot_b_pin) {
//
//		rot_new_state = rot_get_state();
//
//		// DBG("%d:%d", rot_old_state, rot_new_state);
//
//		// Check transition
//		if (rot_old_state == 3 && rot_new_state == 2) {        // 3 -> 2 transition
//			rot_cnt++;
//		} else if (rot_old_state == 2 && rot_new_state == 0) { // 2 -> 0 transition
//			rot_cnt++;
//		} else if (rot_old_state == 0 && rot_new_state == 1) { // 0 -> 1 transition
//			rot_cnt++;
//		} else if (rot_old_state == 1 && rot_new_state == 3) { // 1 -> 3 transition
//			rot_cnt++;
//		} else if (rot_old_state == 3 && rot_new_state == 1) { // 3 -> 1 transition
//			rot_cnt--;
//		} else if (rot_old_state == 1 && rot_new_state == 0) { // 1 -> 0 transition
//			rot_cnt--;
//		} else if (rot_old_state == 0 && rot_new_state == 2) { // 0 -> 2 transition
//			rot_cnt--;
//		} else if (rot_old_state == 2 && rot_new_state == 3) { // 2 -> 3 transition
//			rot_cnt--;
//		}
//
//		rot_old_state = rot_new_state;
//	}
//}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USB_DEVICE_Init();
  MX_TIM3_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Encoder_Start_IT(&htim3, TIM_CHANNEL_ALL);
  uint32_t last_print = 0, now = 0;
  uint32_t rot_count = 0;
  now = HAL_GetTick();
  TIM3->CNT = 30000;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  now = HAL_GetTick();
	  //if (now - last_print >= 100) {
		  // DBG("Encoder counter = %lu", TIM3->CNT);
		  if (rot_count != TIM3->CNT) {
			  	  if (rot_count > TIM3->CNT) {
			  		  keyBoardHIDsub.KEYCODE1=0x04;  // Press A key
					  keyBoardHIDsub.KEYCODE2=0x05;  // Press B key
					  keyBoardHIDsub.KEYCODE3=0x06;  // Press C key
					  keyBoardHIDsub.KEYCODE4=0x80;	 // Volume up - only works on linux
			  	  } else {
			  		  keyBoardHIDsub.KEYCODE1=0x07;  // Press A key
					  keyBoardHIDsub.KEYCODE2=0x08;  // Press B key
					  keyBoardHIDsub.KEYCODE3=0x09;  // Press C key
					  keyBoardHIDsub.KEYCODE4=0x81;	 // Volume down - only works on linux
			  	  }
			  	  USBD_HID_SendReport(&hUsbDeviceFS,&keyBoardHIDsub,sizeof(keyBoardHIDsub));
			  	  HAL_Delay(20); 		       // Press all key for 50 milliseconds
			  	  //keyBoardHIDsub.MODIFIER=0x00;  // To release shift key
			  	  keyBoardHIDsub.KEYCODE1=0x00;  // Release A key
			  	  keyBoardHIDsub.KEYCODE2=0x00;  // Release B key
			  	  keyBoardHIDsub.KEYCODE3=0x00;  // Release C key
			  	  keyBoardHIDsub.KEYCODE4=0x00;	 // Clear buffer from volume up
			  	  USBD_HID_SendReport(&hUsbDeviceFS,&keyBoardHIDsub,sizeof(keyBoardHIDsub));
			  	  rot_count = TIM3->CNT;
		  }
		  last_print = now;
	  //}
	  if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6) == 0){
		  	  //keyBoardHIDsub.MODIFIER=0x02;  // To press shift key
		  	  keyBoardHIDsub.KEYCODE1=0x04;  // Press A key
		  	  keyBoardHIDsub.KEYCODE2=0x05;  // Press B key
		  	  keyBoardHIDsub.KEYCODE3=0x06;  // Press C key
		  	  keyBoardHIDsub.KEYCODE4=0x80;	 // Volume up - only works on linux
		  	  USBD_HID_SendReport(&hUsbDeviceFS,&keyBoardHIDsub,sizeof(keyBoardHIDsub));
		  	  HAL_Delay(50); 		       // Press all key for 50 milliseconds
		  	  //keyBoardHIDsub.MODIFIER=0x00;  // To release shift key
		  	  keyBoardHIDsub.KEYCODE1=0x00;  // Release A key
		  	  keyBoardHIDsub.KEYCODE2=0x00;  // Release B key
		  	  keyBoardHIDsub.KEYCODE3=0x00;  // Release C key
		  	  keyBoardHIDsub.KEYCODE4=0x00;	 // Clear buffer from volume up
		  	  USBD_HID_SendReport(&hUsbDeviceFS,&keyBoardHIDsub,sizeof(keyBoardHIDsub));
		  	  HAL_Delay(1000); 	       // Repeat this task on every 1 second
	  }
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_Encoder_InitTypeDef sConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 0;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 99;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  sConfig.EncoderMode = TIM_ENCODERMODE_TI1;
  sConfig.IC1Polarity = TIM_ICPOLARITY_RISING;
  sConfig.IC1Selection = TIM_ICSELECTION_DIRECTTI;
  sConfig.IC1Prescaler = TIM_ICPSC_DIV1;
  sConfig.IC1Filter = 0;
  sConfig.IC2Polarity = TIM_ICPOLARITY_RISING;
  sConfig.IC2Selection = TIM_ICSELECTION_DIRECTTI;
  sConfig.IC2Prescaler = TIM_ICPSC_DIV1;
  sConfig.IC2Filter = 0;
  if (HAL_TIM_Encoder_Init(&htim3, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();

  /*Configure GPIO pin : PB6 */
  GPIO_InitStruct.Pin = GPIO_PIN_6;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
