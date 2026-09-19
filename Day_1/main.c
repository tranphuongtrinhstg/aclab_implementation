// ESP-IDF Blink Example
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define LED_PIN GPIO_NUM_4
void blinkledtask(void* parameter ){
    bool state = 0;
    while(1){
        gpio_set_level(LED_PIN, state);
        vTaskDelay(pdMS_TO_TICKS(500));
        state = !state;
    }
}

void app_main(void)
{
    gpio_reset_pin(LED_PIN);
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);
    xTaskCreate(
        blinkledtask,       // Task function
        "HelloTask",      // Name
        2048,             // Stack size
        NULL,             // Parameters
        5,                // Priority
        NULL              // Task handle
    );

}
