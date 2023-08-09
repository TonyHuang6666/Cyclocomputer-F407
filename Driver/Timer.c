#include "stm32f10x.h"                  // Device header
//extern uint16_t Number;
/*
    void TIM_DeInit(TIM_TypeDef* TIMx);//将TIMx寄存器恢复到缺省值

    //时基单元
    初始化TIMx的时间基数，配置时基单元：
    void TIM_TimeBaseInit(TIM_TypeDef* TIMx, TIM_TimeBaseInitTypeDef* TIM_TimeBaseInitStruct);

    将TIM_TimeBaseInitStruct中的参数恢复到缺省值：
    void TIM_TimeBaseStructInit(TIM_TimeBaseInitTypeDef* TIM_TimeBaseInitStruct);

    //运行控制
    void TIM_Cmd(TIM_TypeDef* TIMx, FunctionalState NewState);//使能或者失能TIMx（对应框图的运行控制）

    //中断输出控制
    void TIM_ITConfig(TIM_TypeDef* TIMx, uint16_t TIM_IT, FunctionalState NewState);//使能或者失能TIMx的中断

    
    
    //时钟源选择
    void TIM_InternalClockConfig(TIM_TypeDef* TIMx);//将TIMx的时钟源设置为内部时钟

    将TIMx的时钟源设置为外部时钟:
    void TIM_ITRxExternalClockConfig(TIM_TypeDef* TIMx, uint16_t TIM_InputTriggerSource);

    void TIM_TIxExternalClockConfig(TIM_TypeDef* TIMx, uint16_t TIM_TIxExternalCLKSource,
                                    uint16_t TIM_ICPolarity, uint16_t ICFilter);//将TIMx的时钟源设置为TIx

    void TIM_ETRClockMode1Config(TIM_TypeDef* TIMx, uint16_t TIM_ExtTRGPrescaler, uint16_t TIM_ExtTRGPolarity,
                                uint16_t ExtTRGFilter);//将TIMx的时钟源设置为ETR

    void TIM_ETRClockMode2Config(TIM_TypeDef* TIMx, uint16_t TIM_ExtTRGPrescaler, 
                                uint16_t TIM_ExtTRGPolarity, uint16_t ExtTRGFilter);//将TIMx的时钟源设置为ETR

    void TIM_ETRConfig(TIM_TypeDef* TIMx, uint16_t TIM_ExtTRGPrescaler, uint16_t TIM_ExtTRGPolarity,
                    uint16_t ExtTRGFilter);

    void TIM_PrescalerConfig(TIM_TypeDef* TIMx, uint16_t Prescaler, uint16_t TIM_PSCReloadMode);//设置TIMx的预分频值

    void TIM_CounterModeConfig(TIM_TypeDef* TIMx, uint16_t TIM_CounterMode);//设置TIMx的计数模式

    void TIM_ARRPreloadConfig(TIM_TypeDef* TIMx, FunctionalState NewState);//使能或者失能TIMx的ARR预装载

    void TIM_SetCounter(TIM_TypeDef* TIMx, uint16_t Counter);//设置TIMx的计数器值

    void TIM_SetAutoreload(TIM_TypeDef* TIMx, uint16_t Autoreload);//设置TIMx的ARR值

    uint16_t TIM_GetCounter(TIM_TypeDef* TIMx);//获取TIMx的计数器值

    uint16_t TIM_GetPrescaler(TIM_TypeDef* TIMx);//获取TIMx的预分频值

    //以下四个函数是用来获取与清除标志位的
    FlagStatus TIM_GetFlagStatus(TIM_TypeDef* TIMx, uint16_t TIM_FLAG);
    void TIM_ClearFlag(TIM_TypeDef* TIMx, uint16_t TIM_FLAG);
    ITStatus TIM_GetITStatus(TIM_TypeDef* TIMx, uint16_t TIM_IT);
    void TIM_ClearITPendingBit(TIM_TypeDef* TIMx, uint16_t TIM_IT);
*/

void Timer_Init(void)
{
    //1.开启时钟
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE); //使能TIM2时钟。TIM2是APB1总线上的外设
    //2.选择时基单元的时钟源
    TIM_InternalClockConfig(TIM2);//即使不配置，TIM2的时钟源也是内部时钟
    //3.配置时基单元
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
    TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;//时钟分频因子
    TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;//计数模式

    //定时器为1秒，即1Hz。(预分频值+1)*(自动重装载值+1)/72MHz = 1Hz
    TIM_TimeBaseInitStructure.TIM_Prescaler = 7200 - 1;//预分频值
    TIM_TimeBaseInitStructure.TIM_Period = 10000 - 1;//自动重装载值

    TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;//重复计数器的值。高级计数器才有
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);
    TIM_ClearFlag(TIM2, TIM_FLAG_Update);//清除更新中断标志位,否则刚初始化完就立即进入中断
    //4.使能更新中断
    TIM_ITConfig(TIM2, TIM_IT_Update,ENABLE);

    //5.NVIC配置
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//优先级分组
    NVIC_InitTypeDef NVIC_InitStructure;
    NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;//中断源.TIM2_IRQn为定时器2在NVIC中的通道
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;//使能中断
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;//抢占优先级
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;//子优先级
    NVIC_Init(&NVIC_InitStructure);

    //6.使能定时器
    TIM_Cmd(TIM2, ENABLE);

}
/*
void TIM2_IRQHandler(void)
{
    //1.检查中断标志位
    if (TIM_GetITStatus(TIM2, TIM_IT_Update)==SET)
    {
        //执行用户代码
       
        //2.清除中断标志位
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
    }
}
*/
