#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void hello_task(void *pvParameter) {
    int count = 0;

    while (1) {
        count++;
        printf("Day 2: Hello from FreeRTOS! Thong bao nay da hien thi %d lan.\n", count);
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}

void app_main(void) {
    xTaskCreate(hello_task, "hello_task", 2048, NULL, 5, NULL);
}