#include "usart.h"
#include "tim.h"
#include <string.h>

extern char buf[1];
uint8_t rec_flag;
uint8_t rec_buf[30];
uint8_t rec_cnt;

// intr callback
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if(huart != &huart1) return;
    TIM4->CNT = 0;
    rec_flag = 1;
    rec_buf[rec_cnt++] = buf[0];
    HAL_UART_Receive_IT(huart, (uint8_t*)buf, 1);
}




#include<stdio.h>
char send_buffer[30];
void duty_check(void)
{
    if(!rec_flag) return;
    if(TIM4->CNT <= 15) return;
    
    if(!strcmp((const char*)rec_buf, "Char")){
        snprintf(send_buffer, 30, "Got the command: %s\r\n", rec_buf);
        HAL_UART_Transmit(&huart1, (uint8_t*)send_buffer, strlen(send_buffer), HAL_MAX_DELAY);
    }else if(!strcmp((const char*)rec_buf, "chen")){
        snprintf(send_buffer, 30, "Got the command: %s\r\n", rec_buf);
        HAL_UART_Transmit(&huart1, (uint8_t*)send_buffer, strlen(send_buffer), HAL_MAX_DELAY);    
    }else {
        snprintf(send_buffer, 30, "Error Command!%s\r\n", rec_buf);
        HAL_UART_Transmit(&huart1, (uint8_t*)send_buffer, strlen(send_buffer), HAL_MAX_DELAY); 
    }
    memset(send_buffer, 0, 30);
    memset(rec_buf, 0, 30);
    rec_flag = 0;
    rec_cnt = 0;
}






