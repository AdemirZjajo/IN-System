#ifndef PINS_H_
#define PINS_H_

#include <stdint.h>

/*
initialises the 4 pins
*/
void initPins();

/*
switches LED A on if level!=0 or off if level ==0
*/
void setLEDA(uint8_t level);

/*
switches LED B on if level !=0 or off if level ==0
*/

void setLEDB(uint8_t level);

/*
tru if button A is currrently being pressed
*/
uint8_t isButtonAPressed();

/*
true if button B is currently being pressed
*/

uint8_t isButtonBPressed();

#endif3