#include "random.h"

/* Returns a random number contained between min and max.
 min: minimum number of ms
 max: maximum number of ms
*/
int getRandommsecs(int min, int max)
{   
    // Counts difference between min and max, check if its 0 or bigger than the modulo of max min, then if its bigger than max
    return esp_random()%(max-min+1)+min;
}