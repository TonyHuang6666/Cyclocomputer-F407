#ifndef SPI_H_
#define SPI_H_
#include "stm32f4xx_conf.h"
#include "sys.h"

#define SPI_PORT SPI1
#define SPI_PORT_CLK RCC_APB2Periph_SPI1 

#define SPI_GPIOA_CS_Pin 4
#define SPI_CS_PIN GPIO_Pin_4   // SPI1引脚为PA4 SPI1_NSS，SPI2为PB12
#define SPI_SCK_PIN GPIO_Pin_5  // SPI1引脚为PA5 SPI1_SCK,SPI2为PB13
#define SPI_MISO_PIN GPIO_Pin_6 // SPI1引脚为PA6 SPI1_MISO,SPI2为PB14
#define SPI_MOSI_PIN GPIO_Pin_7 // SPI1引脚为PA7 SPI1_MOSI,SPI2为PB15
#define SPI_GPIO_PORT GPIOA
#define GPIO_SpeedRate GPIO_High_Speed
#define SPI_GPIO_CLK RCC_AHB1Periph_GPIOA

void SPI_Initilize(void);
void SPI_Start(void);
void SPI_Stop(void);
uint8_t SPI_ExchangeByte(uint8_t TxData);
#endif
