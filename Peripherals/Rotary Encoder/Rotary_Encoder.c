#include "stm32f4xx.h"                  // Device header
int16_t Encoder_Count,Flag=0;
/*
写初始化函数：
1、配置RCC，把涉及的时钟打开
2、配置GPIO，把涉及的IO口配置成输入模式
3、配置AFIO，选择使用到的一路GPIO连接到后面的EXTI
4、配置EXTI，选择触发方式：上升沿、下降沿、上升下降（双边）沿；选择出发响应方式：中断、事件
5、配置NVIC，选择EXTI中断的优先级

*/
void Encoder_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;//定义GPIO初始化结构体变量
	EXTI_InitTypeDef EXTI_InitStructure;//定义EXTI初始化结构体变量
	NVIC_InitTypeDef NVIC_InitStructure;//定义NVIC初始化结构体变量


	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);


	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//只能配置一次，配置后不能修改

	NVIC_InitStructure.NVIC_IRQChannel=EXTI0_IRQn;//选择NVIC的中断通道
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;//使能NVIC的中断通道
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;//抢占优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;//子优先级
	NVIC_Init(&NVIC_InitStructure);//初始化NVIC

	NVIC_InitStructure.NVIC_IRQChannel=EXTI1_IRQn;//选择NVIC的中断通道
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;//使能NVIC的中断通道
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;//抢占优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=2;//子优先级
	NVIC_Init(&NVIC_InitStructure);//初始化NVIC

	EXTI_ClearITPendingBit(EXTI_Line0);     //清除中断标志位
    EXTI_ClearITPendingBit(EXTI_Line1);     //清除中断标志位

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);


	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource0);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource1);

	EXTI_InitStructure.EXTI_Line=EXTI_Line0|EXTI_Line1;//选择EXTI的中断线
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;//选择触发方式为下降沿触发
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;//使能EXTI中断线
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;//选择中断模式为中断
	EXTI_Init(&EXTI_InitStructure);//初始化EXTI

}

int16_t Encoder_Get(void)//带符号
{
	int16_t temp;
	temp=Encoder_Count;
	Encoder_Count=0;
	return temp;
}

int16_t Flag_Get(void)//带符号
{
	return Flag;
}

void EXTI0_IRQHandler(void)
{
	Flag=100;
	if (EXTI_GetITStatus(EXTI_Line0) == SET)
	{
		/*如果出现数据乱跳的现象，可再次判断引脚电平，以避免抖动*/
		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0) == 0)
		{
			if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 0)
			{
				Encoder_Count --;
			}
		}
		EXTI_ClearITPendingBit(EXTI_Line0);
	}
}

void EXTI1_IRQHandler(void)
{
	Flag=100;
	if (EXTI_GetITStatus(EXTI_Line1) == SET)
	{
		/*如果出现数据乱跳的现象，可再次判断引脚电平，以避免抖动*/
		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 0)
		{
			if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0) == 0)
			{
				Encoder_Count ++;
			}
		}
		EXTI_ClearITPendingBit(EXTI_Line1);
	}
}
