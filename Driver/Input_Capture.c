#include "Input_Capture.h"

// 配置输入捕获单元
void IC_Init(void)
{
    // 开启时钟
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
    // 2.配置GPIO
    GPIO_InitTypeDef GPIO_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource7, GPIO_AF_TIM4); // PB8复用了TIM4的CH3

    /* Enable the TIM4 global Interrupt */
    NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    /*
    //3.配置时基单元
    TIM_InternalClockConfig(TIM4);//内部时钟。漏了！！！！！！！！！！
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;//定义结构体变量
    TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInitStructure.TIM_Period = 0xffff;//设置自动重装载寄存器的值,一般设为最大值65535。
    TIM_TimeBaseInitStructure.TIM_Prescaler = 168-1;//测量频率最低值为72MHz/72/65535=15Hz。增大分频系数可测量更低频率
                                                    //上限就是分频后的标准频率
    TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM4,&TIM_TimeBaseInitStructure);
    */

    //4.配置输入捕获单元
    TIM_ICInitTypeDef TIM_ICInitStructure;
    TIM_ICInitStructure.TIM_Channel = TIM_Channel_2;
    TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;
    TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;
    TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;
    TIM_ICInitStructure.TIM_ICFilter = 0x0;
    /*
    方法1
    TIM_ICInit(TIM4, &TIM_ICInitStructure);
    TIM_ICInitStructure.TIM_Channel = TIM_Channel_2;
    TIM_ICInitStructure.TIM_ICFilter = 0x0;
    TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Falling;
    TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;//不分频，每次都捕获
    TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_IndirectTI;
    TIM_ICInit(TIM4, &TIM_ICInitStructure);
    */

    /*
    方法2：传入一个通道的结构体变量，在函数里自动把剩下的一个通道初始化成相反的配置
    通道一：直连、上升沿捕获，函数则配置通道二为交叉、下降沿捕获；传入通道二则相反
    */
    TIM_PWMIConfig(TIM4, &TIM_ICInitStructure);
    // 5.选择从模式的触发源
    TIM_SelectInputTrigger(TIM4, TIM_TS_TI2FP2); // 选择输入捕获2作为触发源
    // 6.选择触发后执行的操作
    TIM_SelectSlaveMode(TIM4, TIM_SlaveMode_Reset);              // 触发后复位计数器
    TIM_SelectMasterSlaveMode(TIM4, TIM_MasterSlaveMode_Enable); // 开启主从模式
    // 7.开启
    TIM_Cmd(TIM4, ENABLE); // 开启定时器。漏了！！！！！！！！！！
    TIM_ITConfig(TIM4, TIM_IT_CC2, ENABLE);
}

uint32_t Get_Frequency(void)
{
    return 1000000 / (TIM_GetCapture2(TIM4) + 1);
}

uint8_t Get_Duty(void)
{
    return (TIM_GetCapture1(TIM4) + 1) * 100 / (TIM_GetCapture2(TIM4) + 1);
}
    