#include "GLCD_ST7735.h"
#include "stdio.h"
#include "temperature.h"
#define YMAX 5000
#define YMIN 0
uint16_t temp;
char print[20];

void drawaxes(void){
ST7735_Drawaxes(AXISCOLOR, BGCOLOR, "Time", "ADC", LIGHTCOLOR, "", 0, YMAX, YMIN);
}


void drawInfoBar(void)
{
sprintf(print,"%u",temp);
ST7735_DrawString(1, 0, "CPU =", GREEN);
ST7735_DrawString(7, 0, "75%", BLUE );
ST7735_DrawString(11, 0, "ADC=", GREEN);
ST7735_DrawString(18, 0, print, BLUE );

}



void plot(void)
{

ST7735_PlotPoint(temp,GREEN);
ST7735_PlotIncrement();
}

int main(void)
{
start_adc();
LCD_CS0;
ST7735_Init();
ST7735_FillScreen(BLACK);
drawaxes();
drawInfoBar();
LCD_CS1;
	
while(1)
{
temp=get_temp();
LCD_CS0;
drawInfoBar();	
plot();
LCD_CS1;

}

}