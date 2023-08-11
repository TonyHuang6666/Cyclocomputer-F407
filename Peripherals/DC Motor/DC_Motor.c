#include "stm32f4xx.h"
#include "PWM.h"

void Motor_Init(void)
{
    PWM_Init();
    //要额外初始化方向控制的两个引脚
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
}

void Motor_SetSpeed(int8_t speed)//要用带符号的数，因为要控制正反转
{
    if (speed >= 0)
    {
       GPIO_SetBits(GPIOA, GPIO_Pin_4);
       GPIO_ResetBits(GPIOA, GPIO_Pin_5);
       PWM_SetDuty(speed);
    }
    else if (speed < 0)
    {
       GPIO_ResetBits(GPIOA, GPIO_Pin_4);
       GPIO_SetBits(GPIOA, GPIO_Pin_5);
       PWM_SetDuty(-speed);
    }  
}
