#include "die.h"
#include <time.h>
#include <stdlib.h>

void Die::roll() {

    srand(time(0));

    roll_value = rand() % (6 + 1);
}