#ifndef __OLED_H
#define __OLED_H

#include "stm32f1xx_hal.h"

/*“˝Ω≈≈‰÷√*/
#define I2C_SDA_READ HAL_GPIO_ReadPin(OLED_SDA_GPIO_Port, OLED_SDA_Pin) // ∂¡»°SDA
#define OLED_W_SDA_HIGH HAL_GPIO_WritePin(OLED_SDA_GPIO_Port, OLED_SDA_Pin, GPIO_PIN_SET)
#define OLED_W_SCL_HIGH HAL_GPIO_WritePin(OLED_SCL_GPIO_Port, OLED_SCL_Pin, GPIO_PIN_SET)
#define OLED_W_SCL_LOW HAL_GPIO_WritePin(OLED_SCL_GPIO_Port, OLED_SCL_Pin, GPIO_PIN_RESET)
#define OLED_W_SDA_LOW HAL_GPIO_WritePin(OLED_SDA_GPIO_Port, OLED_SDA_Pin, GPIO_PIN_RESET)

void OLED_Init(void);
void OLED_Clear(void);
void OLED_ShowChar(uint8_t Line, uint8_t Column, char Char);
void OLED_ShowString(uint8_t Line, uint8_t Column, char *String);
void OLED_ShowNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);
void OLED_ShowSignedNum(uint8_t Line, uint8_t Column, int32_t Number, uint8_t Length);
void OLED_ShowHexNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);
void OLED_ShowBinNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);
void OLED_ShowCHinese(uint8_t Line,uint8_t Column,uint8_t no);
#endif
