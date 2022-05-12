#include "die.h"
#include <time.h>
#include <stdlib.h>

void Die::roll() {
    const int MAX = sides;
    const int MIN = 1;
    int range = MAX - MIN + 1;
    roll_value = rand() % range + MIN;
}