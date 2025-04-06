#include "ui.h"
#include "lcd.h"
#include "pwm_settings.h"
#include <stdio.h>
#include "adc.h"
#include "gpio.h"
static void led_settings_data()
{
    set_led_status(GPIO_PIN_8, 1);
    set_led_status(GPIO_PIN_9, 0);
}

static void led_settings_para()
{
    set_led_status(GPIO_PIN_8, 0);
    set_led_status(GPIO_PIN_9, 1);
}

char buffers[20];
static void auto_page()
{

    double vol = get_adc_value();
    snprintf(buffers, 20, "      Data");
    LCD_DisplayStringLine(Line0, (u8*)buffers);
    snprintf(buffers, 20, "    V:%.2fV", vol);
    LCD_DisplayStringLine(Line2, (u8*)buffers);
    snprintf(buffers, 20, "    Mode:AUTO");
    LCD_DisplayStringLine(Line4, (u8*)buffers);    
}

static void manual_page()
{
    double vol = get_adc_value();
    snprintf(buffers, 20, "      Data");
    LCD_DisplayStringLine(Line0, (u8*)buffers);
    snprintf(buffers, 20, "    V:%.2fV", vol);
    LCD_DisplayStringLine(Line2, (u8*)buffers);
    snprintf(buffers, 20, "    Mode:MANU");
    LCD_DisplayStringLine(Line4, (u8*)buffers);  
}

void display_data_page(Mode mode)
{
    led_settings_data();
    switch(mode)
    {
        case Auto:
            auto_page();
            break;
        case Manual:
            manual_page();
        break;
    }
}

void display_para_page()
{
    led_settings_para();
    snprintf(buffers, 20, "      Para");
    LCD_DisplayStringLine(Line0, (u8*)buffers);
    snprintf(buffers, 20, "    PA5:%d%% ", percentage_pwm1());
    LCD_DisplayStringLine(Line2, (u8*)buffers);
    snprintf(buffers, 20, "    PA6:%d%% ", percentage_pwm2());
    LCD_DisplayStringLine(Line4, (u8*)buffers);     
}

void display_as_page(Page page, Mode mode)
{
    switch(page)
    {
        case Data:
            display_data_page(mode);
        break;
        case Para:
            display_para_page();
        break;
    }
}


