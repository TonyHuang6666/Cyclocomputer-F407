#include "stm32f4xx.h"                  // Device header

/*
写初始化函数：
1、配置RCC，把涉及的时钟打开
2、配置GPIO，把涉及的IO口配置成输入模式
3、配置AFIO，选择使用到的一路GPIO连接到后面的EXTI
4、配置EXTI，选择触发方式：上升沿、下降沿、上升下降（双边）沿；选择出发响应方式：中断、事件
5、配置NVIC，选择EXTI中断的优先级

*/
void CountSensor_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	//EXTI虽然是外设，但不需要开启时钟；NVIC也不需要开启时钟，因为NVIC不是外设，是内核的一部分

	//配置GPIO
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//上拉输入，默认为高电平
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);//初始化GPIOB外设

	/*
	与AFIO有关的库函数：
	void GPIO_AFIODeInit(void);//复位AFIO
	void GPIO_PinLockConfig(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);//锁定GPIO的某个引脚，防止误操作
	void GPIO_EventOutputConfig(uint8_t GPIO_PortSource, uint8_t GPIO_PinSource);//配置GPIO的某个引脚作为事件输出
	void GPIO_EventOutputCmd(FunctionalState NewState);//使能或失能GPIO的事件输出

	GPIO_PinRemapConfig()函数用于重映射GPIO的引脚，重映射后，GPIO的引脚号会发生变化，但是GPIO的端口号不变
	第一个参数为重映射的方式，第二个参数为新的状态
	void GPIO_PinRemapConfig(uint32_t GPIO_Remap, FunctionalState NewState);

	配置AFIO的数据选择器，选择GPIO的某个引脚连接到某个外设
	void GPIO_EXTILineConfig(uint8_t GPIO_PortSource, uint8_t GPIO_PinSource);

	与以太网有关，但F103C8T6无以太网外设
	void GPIO_ETH_MediaInterfaceConfig(uint32_t GPIO_ETH_MediaInterface);
	*/
	//配置AFIO
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource14);

	/*
	与EXTI有关的库函数：
	void EXTI_DeInit(void);//复位EXTI
	void EXTI_Init(EXTI_InitTypeDef* EXTI_InitStruct);//初始化EXTI
	void EXTI_GenerateSWInterrupt(uint32_t EXTI_Line);//软件触发外部中断
	以下均为库函数的模板函数
	void EXTI_StructInit(EXTI_InitTypeDef* EXTI_InitStruct);//给参数传递的结构体变量赋默认值

	在主程序里查看和清除标志位：
	FlagStatus EXTI_GetFlagStatus(uint32_t EXTI_Line);//获取EXTI的标志位
	void EXTI_ClearFlag(uint32_t EXTI_Line);//清除EXTI的标志位

	//在中断程序里查看和清除标志位：
	ITStatus EXTI_GetITStatus(uint32_t EXTI_Line);//获取EXTI的中断状态
	void EXTI_ClearITPendingBit(uint32_t EXTI_Line);//清除EXTI的中断状态
	*/
	//配置EXTI
	EXTI_InitTypeDef EXTI_InitStructure;//定义EXTI初始化结构体变量
	EXTI_InitStructure.EXTI_Line=EXTI_Line14;//选择EXTI的中断线
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;//选择触发方式为下降沿触发
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;//使能EXTI中断线
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;//选择中断模式为中断
	EXTI_Init(&EXTI_InitStructure);//初始化EXTI

	/*
	与NVIC有关的库函数：
	void NVIC_PriorityGroupConfig(uint32_t NVIC_PriorityGroup);//配置NVIC的中断优先级分组
	void NVIC_Init(NVIC_InitTypeDef* NVIC_InitStruct);//初始化NVIC
	void NVIC_SetVectorTable(uint32_t NVIC_VectTab, uint32_t Offset);//设置NVIC的向量表
	void NVIC_SystemLPConfig(uint8_t LowPowerMode, FunctionalState NewState);//配置NVIC的低功耗模式
	void SysTick_CLKSourceConfig(uint32_t SysTick_CLKSource);//配置SysTick的时钟源
	*/
	//配置NVIC
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//只能配置一次，配置后不能修改
	NVIC_InitTypeDef NVIC_InitStruct;//定义NVIC初始化结构体变量
	NVIC_InitStruct.NVIC_IRQChannel=EXTI15_10_IRQn;//选择NVIC的中断通道
	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;//使能NVIC的中断通道
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&NVIC_InitStruct);//初始化NVIC
}

//中断程序不需要在头文件里声明，因为中断程序不是由主程序调用的，而是由硬件自动调用的
uint16_t Count = 0;
void EXTI15_10_IRQHandler(void)//名字格式固定，在startup_stm32f10x_md.s的中断向量表里定义了，如果写错了则无法进入中断程序
{
	//进行中断标志位的判断
	if (EXTI_GetITStatus(EXTI_Line14)==SET)
	{
        Count++;
		EXTI_ClearITPendingBit(EXTI_Line14);//每次调用完中断程序后都要清除中断标志位，否则会一直进入中断程序
	}
}

uint16_t Get_Count(void)
{
    return Count;
}

