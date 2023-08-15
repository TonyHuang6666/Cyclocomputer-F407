#ifndef __DELAY_H
#define __DELAY_H 			   
#include <sys.h>	  
	 
void Delay_init(uint8_t SYSCLK);
void Delay_us(uint32_t nus);
void Delay_ms(uint16_t nms);

#endif
