#include "Key.h"
#include "Delay.h"

void KEY_Init(void)
{
	
	GPIO_InitTypeDef GPIO_InitStructure;

 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOC,ENABLE);//??PORTA,PORTC??

	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);//??jtag,??SWD,???SWD????
	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_15;//PA15
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //???????
 	GPIO_Init(GPIOA, &GPIO_InitStructure);//???GPIOA15
	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_5;//PC5
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //???????
 	GPIO_Init(GPIOC, &GPIO_InitStructure);//???GPIOC5
 
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0;//PA0
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; //PA0?????,????	  
	GPIO_Init(GPIOA, &GPIO_InitStructure);//???GPIOA.0
	
} 
u8 KEY_Scan(void)
{	 	  
	if((KEY0==0||KEY1==0||WK_UP==1))
	{
		Delay_ms(10);//??? 
		if(KEY0==0)return KEY0_PRES;
		else if(KEY1==0)return KEY1_PRES;
		else if(WK_UP==1)return WKUP_PRES; 
	}	     
	return 0;// ?????
}
