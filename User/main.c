#include "main.h"


int main(void)
{
	//LCD_Init();
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);//使能GPIOA时钟
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin =GPIO_Pin_8;//SCK、MOSI、MISO引脚
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//复用功能
    GPIO_InitStructure.GPIO_Speed = GPIO_SpeedRate;//速率
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
    GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIOA
    GPIO_SetBits(GPIOA, GPIO_Pin_8);
  	Delay_ms(1000);
    GPIO_ResetBits(GPIOA, GPIO_Pin_8);

	while (1)
	{
	
    
    
	}
}