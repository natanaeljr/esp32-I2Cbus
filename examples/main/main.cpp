#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "driver/i2c.h"
#include "esp_log.h"
#include <stdint.h>

#include "I2Cbus.hpp"

#ifdef __cplusplus
extern "C" {
    void app_main();
}
#endif



void app_main() {
    printf(LOG_BOLD("97") "\n[APP_MAIN]" LOG_RESET_COLOR "\n");
    
    I2Cbus0.begin(GPIO_NUM_21, GPIO_NUM_22, 400000U);
    I2Cbus0.setTimeout(10);
    I2Cbus0.scanner();

    I2Cbus0.writeBit(0x69, 0x6B, 6, false);
    
    while(true) {
        uint8_t buffer[2];
        I2Cbus0.readBytes(0x68, 0x6F, 6, buffer);

        vTaskDelay(pdMS_TO_TICKS(1000));
    }
    
    vTaskDelay(portMAX_DELAY);
}
