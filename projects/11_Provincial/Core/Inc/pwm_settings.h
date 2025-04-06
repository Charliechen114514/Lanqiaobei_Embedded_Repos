#ifndef PWM_SETTINGS
#define PWM_SETTINGS

#include <stdint.h>

void set_pwm_init_status(void);
void set_pwm1_per(uint8_t percent);
void set_pwm2_per(uint8_t percent);
uint32_t percentage_pwm2(void);
uint32_t percentage_pwm1(void);
void mode_rollings_pwm2(void);
void mode_rollings_pwm1(void);
uint32_t single_fetch(void);
void auto_mode(void);
#endif
