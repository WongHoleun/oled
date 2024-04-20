/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
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
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdio.h"
#include "OLED.h"
#include "stdio.h"
#include "gpio.h"
#include "GUI.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
extern GUI_CONST_STORAGE GUI_BITMAP bmhello;
extern GUI_FLASH const GUI_FONT GUI_FontHZ_SimSun_24;
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
float Average_Tr = 33.6;
float Average_Tw = 30.2;
float Average_He = 60;
float Average_Ts = 26.5;
float Average_HR = 80;
float Average_SPO2 = 98;
float MHC = 99.99;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

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
  MX_TIM3_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */

  GUI_Init(); // 初始化GUI图形库
              //	GUI_SetFont(&GUI_FontHZ_SimSun_24); // 设置 24 号宋体
              //	GUI_DispString("\nHello\nOLED\n");
              //	GUI_DispString("您好！\nOLED"); // 显示 LOGO 文本
              //	GUI_Update(); // 刷新OLED屏幕显示

  //	HAL_Delay(2000);
  //	GUI_Clear();
  //	GUI_DrawBitmap(&bmhello, 64, 0);  // 显示 OLED 图片
  //	GUI_Update(); // 刷新OLED屏幕显示

  GUI_SetFont(GUI_DEFAULT_FONT); // 设置 ASCII 字体
                                 //  Average_HR = (int32_t)(temp * 10);
  char str[30];
  // sprintf(str, "HR: %.1f", Average_HR);
  // 			GUI_ClearRect(0, 0, 14, 10);
  // GUI_DispStringAt(str, 0, 0);
  // GUI_Update();

  // sprintf(str, "SPO2: %.1f", Average_SPO2);
  // 			GUI_ClearRect(0, 10, 14, 10);
  // GUI_DispStringAt(str, 0, 10);
  // GUI_Update();

  // OLED_Init();

  //  	OLED_ShowString(1,1,"HR:");//显示字符
  //  OLED_ShowNum(1,5,80, 2);//显示字符串

  //    	OLED_ShowString(2,1,"SpO2:");//显示字符
  //  OLED_ShowString(2,7,"99%");

  //     	OLED_ShowString(3,1,"E_humidity:");//显示字符
  // OLED_ShowString(3,13,"60.5%");

  //     	OLED_ShowString(4,1,"E_temperature:");//显示字符
  // OLED_ShowString(4,15,"33.4");

  //       	OLED_ShowString(5,1,"S_temperature:");//显示字符
  // OLED_ShowString(5,15,"36.5");

  //       	OLED_ShowString(6,0,"AR_temperature:");//显示字符
  // OLED_ShowString(6,16,"38.5");

  //  OLED_ShowChar(1,1,'A');//显示字符
  //  OLED_ShowString(1,5,"AMH");//显示字符串

  // //最后一个参数，是显示长度，
  // //小于最高位就依次没有，大于最高位补0
  // OLED_ShowNum(2,1,12345,5);//显示无符号数

  // OLED_ShowSignedNum(2,7,66,2);//显示符号
  // OLED_ShowSignedNum(2,12,-66,2);//显示符号

  // OLED_ShowHexNum(3,1,0xAA55,4);//显示16进制的数

  //   OLED_ShowCHinese(6, 0, 0);							//西
  // OLED_ShowCHinese(6, 16, 1); 						//安

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    sprintf(str, "HR: %.1f", Average_HR);
    GUI_ClearRect(0, 0, 128, 8);
    GUI_DispStringAt(str, 0, 0);
    GUI_Update();

    sprintf(str, "SPO2: %.1f", Average_SPO2);
    GUI_ClearRect(0, 9, 128, 8);
    GUI_DispStringAt(str, 0, 9);
    GUI_Update();

    sprintf(str, "Env. humidity: %.1f", Average_He);
    GUI_ClearRect(0, 18, 128, 8);
    GUI_DispStringAt(str, 0, 18);
    GUI_Update();
    sprintf(str, "Env. temperature: %.1f", Average_Ts);
    GUI_ClearRect(0, 27, 128, 8);
    GUI_DispStringAt(str, 0, 27);
    GUI_Update();

    sprintf(str, "Skin temperature: %.1f", Average_Tw);
    GUI_ClearRect(0, 36, 128, 8);
    GUI_DispStringAt(str, 0, 36);
    GUI_Update();

    sprintf(str, "Abs. rad. temp.: %.1f", Average_Tr);
    GUI_ClearRect(0, 45, 128, 8);
    GUI_DispStringAt(str, 0, 45);
    GUI_Update();

    sprintf(str, "Met. heat prod.: %.1f", MHC);
    GUI_ClearRect(0, 54, 128, 8);
    GUI_DispStringAt(str, 0, 54);
    GUI_Update();

    HAL_Delay(1000);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
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

  /** Initializes the RCC Oscillators according to the specified parameters
   * in the RCC_OscInitTypeDef structure.
   */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
   */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
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

#ifdef USE_FULL_ASSERT
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
