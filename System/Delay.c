#include "Delay.h"

__IO uint16_t ntime;								    

void Delay_ms(uint16_t nms)
{	 		  	  
	ntime=nms;
	SysTick_Config(168000);//1ms产生一次中断
	while(ntime);
	SysTick->CTRL=0x00;			  	    
}   
		    								   
void Delay_us(uint32_t nus)
{		
	ntime=nus;
	SysTick_Config(168);//1us产生一次中断
	while(ntime);
	SysTick->CTRL=0x00;
}

void Delay(uint32_t count)
{
	while(count--);
} 
