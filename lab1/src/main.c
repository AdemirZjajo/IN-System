#include "driver/gpio.h"
#include <esp32/rom/ets_sys.h>
#include "pins.h"
#include <esp_task_wdt.h>
#include "random.h"

/*
 Waits for "millis" milliseconds without upsetting the watchdog timer
*/
void waitMs(unsigned int millis)
{
    TickType_t delay = millis / portTICK_PERIOD_MS;
    vTaskDelay(delay);
}
void app_main()
{
    initPins();

    while (1)
    {
        for (int x = 0; x < 5; x++)
        {
            setLEDA(1);
            setLEDB(0);
            waitMs(50);
            setLEDA(0);
            setLEDB(1);
            waitMs(50);

            int r = getRandommsecs(1000, 5000);
            setLEDB(0);
            setLEDA(0);
            waitMs(r);
            setLEDA(1);
            setLEDB(1);
        }

        uint8_t winner = 0;
        while (!winner)
        {
            if (isButtonAPressed())
            {
                winner = 1;
                setLEDB(0);
            }
            else if (isButtonBPressed())
            {
                winner = 1;
                setLEDA(0);
            }
        }
        waitMs(3000);
    }
}
