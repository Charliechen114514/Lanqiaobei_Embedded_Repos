#include "pwm_settings.h"
#include "tim.h"
#include "adc.h"
void set_pwm_init_status(void)
{
    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
    htim2.Instance->CCR1 = 10;
    htim3.Instance->CCR1 = 10;
}

void set_pwm1_per(uint8_t percent)
{
    htim2.Instance->CCR1 = percent;
}

void set_pwm2_per(uint8_t percent)
{
    htim3.Instance->CCR1 = percent;
}

uint32_t single_fetch(void){
    HAL_ADC_Start(&hadc2);
    uint32_t value = HAL_ADC_GetValue(&hadc2);
    return value;
}

extern uint32_t old;
static char flags;

static uint8_t in_scope(uint32_t percentage_cal)
{
    return old >= percentage_cal - 10 &&  old <= percentage_cal + 10;
}

void auto_mode(void)
{
    uint32_t percentage_cal = single_fetch() * 100 / 4096;
    if(!in_scope(percentage_cal) && !flags){
        flags = 1;
    }else{
        if(flags){
            set_pwm1_per(percentage_cal);
            set_pwm2_per(percentage_cal);
            return;
        }
        return; // don't set the value
    }
    // then things changing

}

void mode_rollings_pwm1(void)
{
    uint32_t per = percentage_pwm1();
    
    per+=10;
    if(per > 90){
        per = 10;
    }
    
    set_pwm1_per(per);
}

void mode_rollings_pwm2(void)
{
    uint32_t per = percentage_pwm2();
    per+=10;
    if(per > 90){
        per = 10;
    }
    
    
    set_pwm2_per(per);
}
    
uint32_t percentage_pwm1(void){
    return htim2.Instance->CCR1;
}

uint32_t percentage_pwm2(void){
    return htim3.Instance->CCR1;
}








