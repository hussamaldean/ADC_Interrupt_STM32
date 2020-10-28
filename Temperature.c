#include "temperature.h"
uint16_t tempo; 
//double voltage,degree;


void ADC_Init(void){
__disable_irq();
	
RCC->AHB1ENR|=RCC_AHB1ENR_GPIOAEN; 
	
RCC->APB2ENR|=RCC_APB2ENR_ADC1EN; 
	
GPIOA->MODER|=(1<<0)|(1<<1);  
	
ADC1->CR2=0;

ADC1->SMPR2|=(1<<0)|(1<<1)|(1<<2);
	
ADC1->SQR3=0;
	
ADC1->CR1|=(1<<5);
	
ADC1->CR2|=ADC_CR2_CONT;
	
ADC1->CR2|=1;
	
NVIC_EnableIRQ(ADC_IRQn);



ADC1->CR2|=ADC_CR2_SWSTART;
__enable_irq();
}

void start_adc(void)
{

ADC_Init();

}

uint16_t get_temp(void)
{

return tempo;
} 

void  ADC_IRQHandler(void)
{
tempo=ADC1->DR;
//CLEAR_BIT(ADC1->SR, ADC_SR_EOC);
}