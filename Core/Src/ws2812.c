#include "ws2812.h"
#include "stm32f1xx_hal_tim.h"
#include "tim.h"
#include <stdint.h>

#define Code0   30
#define Code1   60
#define Reset   0  

void Ws2812_Update(){
    static uint16_t data[]={
        Code0,Code0,Code0,Code0,Code0,Code0,Code0,Code0,
        Code0,Code0,Code0,Code0,Code0,Code0,Code0,Code0,
        Code1,Code1,Code1,Code1,Code1,Code1,Code1,Code1,
  

        Reset
    };

    HAL_TIM_PWM_Start_DMA(&htim3, TIM_CHANNEL_1, (uint32_t*)data, sizeof(data)/sizeof(uint16_t));

}