#ifndef __temperature__h
#define __temperature__h
#include "stdint.h"
#include "stm32f4xx.h"                  // Device header
void start_adc(void);
uint16_t get_temp(void);



#endif