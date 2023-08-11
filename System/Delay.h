#ifndef __DELAY_H
#define __DELAY_H

#include "stm32f4xx_conf.h"

void Delay_ms(uint16_t nms);
void Delay_us(uint32_t nus);
void Delay(uint32_t count);

#endif
