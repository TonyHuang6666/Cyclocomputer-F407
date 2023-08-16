#include "PWM.h"                  // Device header

uint32_t SystemClock = 168000000;	//时钟频率

void PWM_Init(void)
{
	//1.开启时钟
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);	//GPIOA
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);	//TIM1
	//2.配置GPIO
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_TIM2);//PA8复用了TIM1的OC1	
	GPIO_InitTypeDef GPIO_InitStructure;//定义结构体变量
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;	//复用
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;	//推挽输出。输出控制寄存器断开，输出由片上外设控制
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;	//不上下拉
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;	//PA3
	GPIO_InitStructure.GPIO_Speed = GPIO_High_Speed;	//100MHz
	GPIO_Init(GPIOA, &GPIO_InitStructure);	//初始化GPIOA
	//3.选择时基单元的时钟源
	TIM_InternalClockConfig(TIM2);	//内部时钟
	//4.配置时基单元
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;//定义结构体变量
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;	//时钟分频因子,不分频
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;	//计数模式为向上计数
	TIM_TimeBaseInitStructure.TIM_Period = 100 - 1;	//自动重装载值。ARR的值越大，频率越小
	TIM_TimeBaseInitStructure.TIM_Prescaler = 168 - 1;	//预分频值。PSC的值越大，频率越小
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;	//重复计数器的值
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);//初始化TIM1
	TIM_Cmd(TIM2, ENABLE);	//使能TIM1
	//5.配置输出比较单元
	TIM_OCInitTypeDef TIM_OCInitStructure;//定义结构体变量。TIM_OCInitStructure带N与Idle的参数高级定时器才用
	TIM_OCStructInit(&TIM_OCInitStructure);//将TIM_OCInitStructure中的参数恢复到缺省值，避免出现未知错误
	TIM_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM1;	//PWM模式1
	TIM_OCInitStructure.TIM_OutputState=ENABLE;	//输出使能
	TIM_OCInitStructure.TIM_OCPolarity=TIM_OCPolarity_High;	//输出极性
	TIM_OCInitStructure.TIM_Pulse=0;	//设置CCR。CCR16位，用来存放比较值。CCR的值越大，占空比越大
	TIM_OC4Init(TIM2, &TIM_OCInitStructure);//初始化TIM1的OC1
	TIM_OC4PreloadConfig(TIM2, TIM_OCPreload_Enable);//使能TIM1的OC1预装载寄存器
	
}

void PWM_SetPrescaler(uint16_t prescaler)
{
	//TIM_SetAutoreload(TIM2, freq);通过修改ARR来改变频率会影响到占空比，所以不用这个函数
	//TIM_SetIC1Prescaler(TIM2, freq);//通过修改PSC来改变频率，不会影响到占空比,但是会影响到占空比的精度，所以不用这个函数
	TIM_PrescalerConfig(TIM2, prescaler, TIM_PSCReloadMode_Immediate);//设置预分频值及更新模式
	//TIM_PSCReloadMode_Update：只有当产生更新事件时，PSC才会重新加载，保证一个周期的完整
	//TIM_PSCReloadMode_Immediate：立即重新加载PSC，不管是否产生更新事件
}

void PWM_Set(uint16_t freq, uint16_t duty)
{
	//预分频值+1=时钟频率/(频率*自动重装值+1)
	uint32_t PSC=SystemClock/(freq*(99+1));
	PWM_Init();
	PWM_SetPrescaler(PSC-1);//设置预分频值
	TIM_SetCompare4(TIM2, duty);//设置CCR。CCR16位，用来存放比较值。CCR的值越大，占空比越大
}