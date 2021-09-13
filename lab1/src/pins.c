#include "pins.h"
#include "driver/gpio.h"

/*
initialises the 4 pins
*/
void initPins()
{

    //inin the 2 LEDs pins as output and the 2 buttons pins as input
    //you will need to use gpio_config()
    //BITmask 12 = pin 12 (yellow), mask 14 = pin 14 (red)
    gpio_config_t config;
    config.pin_bit_mask = (u_int64_t)1 << 12 | (u_int64_t)1 << 14;
    config.mode = GPIO_MODE_OUTPUT;
    config.pull_down_en = GPIO_PULLDOWN_DISABLE;
    config.pull_up_en = GPIO_PULLUP_DISABLE;

    gpio_config(&config);
    //buttons
    config.pin_bit_mask = (u_int64_t)1 << 26 | (u_int64_t)1 << 27;
    config.mode = GPIO_MODE_INPUT;
    config.pull_down_en = GPIO_PULLDOWN_DISABLE;
    config.pull_up_en = GPIO_PULLUP_ENABLE;

    gpio_config(&config);
}

/*
switchs LED A on if level !=0 or if level ==0
*/

void setLEDA(uint8_t level)
{
    if (level)
    {
        gpio_set_level(12, 1);
        //set the pin of LED A to ON
        // you probably need to use gpio_set_level()
    }
    else
    {
        gpio_set_level(12, 0);
        // set the pin of LED A to OFF
    }
}
/* switches LED B on if level!=0 or off */

void setLEDB(uint8_t level)
{
    // same as setLEDA()
    if (level)
    {
        gpio_set_level(14, 1);
    }
    else
    {
        gpio_set_level(14, 0);
    }
}

/*
tells if buttom A is currently being pressed 
*/
uint8_t isButtonAPressed()
{ //read the value of button A
    // if using a pull-up, the button is pressed when the pin is LOW

    //gpio_get_level(27);


    return !gpio_get_level(27);
}

/*
tells if button A is currently being pressed
*/
uint8_t isButtonBPressed()
{
    //same as with buttom A but another pin
    
    return !gpio_get_level(26);

}