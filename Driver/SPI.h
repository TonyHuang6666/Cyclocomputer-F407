#ifndef SPI_H_
#define SPI_H_

#define SPI_PORT SPI1
#define SPI_PORT_CLK RCC_APB2Periph_SPI1 //SPI1为APB2外设，SPI2为APB1外设

#define SPI_CS_PIN GPIO_Pin_4   // SPI1引脚为PA4，SPI2为PB12
#define SPI_SCK_PIN GPIO_Pin_5  // SPI1引脚为PA5,SPI2为PB13
#define SPI_MISO_PIN GPIO_Pin_6 // SPI1引脚为PA6,SPI2为PB14
#define SPI_MOSI_PIN GPIO_Pin_7 // SPI1引脚为PA7,SPI2为PB15
#define SPI_GPIO_PORT GPIOA
#define SPI_GPIO_CLK RCC_APB2Periph_GPIOA

void SPI_Initilize(void);
void SPI_Start(void);
void SPI_Stop(void);
uint8_t SPI_ExchangeByte(uint8_t TxData);
#endif