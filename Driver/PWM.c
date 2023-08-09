#include "stm32f10x.h"                  // Device header

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

/*
	//重要：配置输出比较单元
	void TIM_OC1Init(TIM_TypeDef* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct);//PA0口对应
	void TIM_OC2Init(TIM_TypeDef* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct);
	void TIM_OC3Init(TIM_TypeDef* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct);
	void TIM_OC4Init(TIM_TypeDef* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct);

	//将TIM_OCInitStruct中的参数恢复到缺省值
	void TIM_OCStructInit(TIM_OCInitTypeDef* TIM_OCInitStruct);

	//配置强制输出模式，例如运行中暂停输出波形并强制输出高电平或者低电平
	void TIM_ForcedOC1Config(TIM_TypeDef* TIMx, uint16_t TIM_ForcedAction);
	void TIM_ForcedOC2Config(TIM_TypeDef* TIMx, uint16_t TIM_ForcedAction);
	void TIM_ForcedOC3Config(TIM_TypeDef* TIMx, uint16_t TIM_ForcedAction);
	void TIM_ForcedOC4Config(TIM_TypeDef* TIMx, uint16_t TIM_ForcedAction);

	//配置输出比较单元的预装载（影子寄存器）。写入值被缓存到影子寄存器，下一次更新事件发生时才写入到比较寄存器中
	void TIM_OC1PreloadConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPreload);
	void TIM_OC2PreloadConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPreload);
	void TIM_OC3PreloadConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPreload);
	void TIM_OC4PreloadConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPreload);

	//配置快速使能
	void TIM_OC1FastConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCFast);
	void TIM_OC2FastConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCFast);
	void TIM_OC3FastConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCFast);
	void TIM_OC4FastConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCFast);

	//清除输出比较单元的OCxREF标志位
	void TIM_ClearOC1Ref(TIM_TypeDef* TIMx, uint16_t TIM_OCClear);
	void TIM_ClearOC2Ref(TIM_TypeDef* TIMx, uint16_t TIM_OCClear);
	void TIM_ClearOC3Ref(TIM_TypeDef* TIMx, uint16_t TIM_OCClear);
	void TIM_ClearOC4Ref(TIM_TypeDef* TIMx, uint16_t TIM_OCClear);

	//配置输出比较单元的极性
	void TIM_OC1PolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPolarity);
	void TIM_OC1NPolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCNPolarity);//带N的是互补输出
	void TIM_OC2PolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPolarity);
	void TIM_OC2NPolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCNPolarity);
	void TIM_OC3PolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPolarity);
	void TIM_OC3NPolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCNPolarity);
	void TIM_OC4PolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPolarity);

	//单独修改输出使能参数
	void TIM_CCxCmd(TIM_TypeDef* TIMx, uint16_t TIM_Channel, uint16_t TIM_CCx);
	void TIM_CCxNCmd(TIM_TypeDef* TIMx, uint16_t TIM_Channel, uint16_t TIM_CCxN);

	//选择输出比较单元的模式
	void TIM_SelectOCxM(TIM_TypeDef* TIMx, uint16_t TIM_Channel, uint16_t TIM_OCMode);

	//重要：这四个函数是用来设置输出比较单元的比较值的（单独更改RCC寄存器的值）
	void TIM_SetCompare1(TIM_TypeDef* TIMx, uint16_t Compare1);//单独用来设置CCR1的值
	void TIM_SetCompare2(TIM_TypeDef* TIMx, uint16_t Compare2);
	void TIM_SetCompare3(TIM_TypeDef* TIMx, uint16_t Compare3);
	void TIM_SetCompare4(TIM_TypeDef* TIMx, uint16_t Compare4);

	//以下函数仅高级定时器输出PWM时使用来使能主输出，否则PWM波形不会输出
	void TIM_CtrlPWMOutputs(TIM_TypeDef* TIMx, FunctionalState NewState);
*/
void PWM_Init(void)
{
	//1.开启时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	//GPIOA
	//RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);	//AFIO
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);	//TIM2
	//1.1配置AFIO
	//GPIO_PinRemapConfig(GPIO_PartialRemap1_TIM2, ENABLE);	//部分重映射，TIM2_CH1->PA0
	//GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);	//关闭JTAG，释放PA15、PB3、PB4,变为GPIO
	//2.选择时基单元的时钟源
	TIM_InternalClockConfig(TIM2);	//内部时钟
	//3.配置时基单元
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;//定义结构体变量
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;	//时钟分频因子
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;	//计数模式
	TIM_TimeBaseInitStructure.TIM_Period = 100 - 1;	//自动重装载值。ARR的值越大，频率越小
	TIM_TimeBaseInitStructure.TIM_Prescaler = 720 - 1;	//预分频值。PSC的值越大，频率越小
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;	//重复计数器的值
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);//初始化TIM2
	//4.配置输出比较单元
	TIM_OCInitTypeDef TIM_OCInitStructure;//定义结构体变量。TIM_OCInitStructure带N与Idle的参数高级定时器才用

	TIM_OCStructInit(&TIM_OCInitStructure);//将TIM_OCInitStructure中的参数恢复到缺省值，避免出现未知错误

	TIM_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM1;	//PWM模式1
	TIM_OCInitStructure.TIM_OutputState=ENABLE;	//输出使能
	TIM_OCInitStructure.TIM_OCPolarity=TIM_OCPolarity_High;	//输出极性
	TIM_OCInitStructure.TIM_Pulse=0;	//设置CCR。CCR16位，用来存放比较值。CCR的值越大，占空比越大
	TIM_OC1Init(TIM2, &TIM_OCInitStructure);//初始化TIM2的OC1
	//5.配置GPIO
	GPIO_InitTypeDef GPIO_InitStructure;//定义结构体变量
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//复用推挽输出。输出控制寄存器断开，输出由片上外设控制
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;	//PA0复用了TIM2的OC1
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//50MHz
	GPIO_Init(GPIOA, &GPIO_InitStructure);	//初始化GPIOA
	//6.运行控制，开启定时器
	TIM_Cmd(TIM2, ENABLE);	//使能TIM2
}

void PWM_SetDuty(uint16_t duty)
{
	TIM_SetCompare1(TIM2, duty);
}

void PWM_SetPrescaler(uint16_t prescaler)
{
	//TIM_SetAutoreload(TIM2, freq);通过修改ARR来改变频率会影响到占空比，所以不用这个函数
	//TIM_SetIC1Prescaler(TIM2, freq);//通过修改PSC来改变频率，不会影响到占空比,但是会影响到占空比的精度，所以不用这个函数
	TIM_PrescalerConfig(TIM2, prescaler, TIM_PSCReloadMode_Immediate);//设置预分频值及更新模式
	//TIM_PSCReloadMode_Update：只有当产生更新事件时，PSC才会重新加载，保证一个周期的完整
	//TIM_PSCReloadMode_Immediate：立即重新加载PSC，不管是否产生更新事件
}

