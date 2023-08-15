#ifndef IIC_H_
#define IIC_H_
#include "stm32f4xx_conf.h"

#define I2C_PORT I2C1
#define I2C_PORT_CLK RCC_APB1Periph_I2C1 //I2C1和I2C2都是APB1总线上的外设
#define I2C_SCL_PIN GPIO_Pin_6//I2C1为PB6，I2C2为PB10
#define I2C_SDA_PIN GPIO_Pin_7//I2C1为PB7，I2C2为PB11
#define I2C_GPIO_PORT GPIOB
#define GPIO_SpeedRate GPIO_High_Speed
#define I2C_GPIO_CLK RCC_AHB1Periph_GPIOB

//以下为IIC.c文件中的6个函数的声明
void IIC_Initilize(void);
void IIC_Startup(void);
void IIC_Pause(void);
void IIC_SendByte(uint8_t Byte);
uint8_t IIC_ReceiveByte(void);
void IIC_SendACK(uint8_t ACK);
uint8_t IIC_ReceiveACK(void);
#endif