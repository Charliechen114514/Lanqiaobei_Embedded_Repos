#include "lcd.h"
#include <stdio.h>
char text[20];
extern int value;
void lcddisp(void)
{
    snprintf(text, 20, "    DATA     ");
    LCD_DisplayStringLine(Line1, (uint8_t*)text);
    snprintf(text, 20, "    Value: %d     ", value);
    LCD_DisplayStringLine(Line2, (uint8_t*)text);
}
