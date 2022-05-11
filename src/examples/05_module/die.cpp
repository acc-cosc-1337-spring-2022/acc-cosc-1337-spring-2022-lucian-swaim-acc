#include "die.h"
#include <time.h>
#include <stdlib.h>

void Die::roll() {


    roll_value = rand() % (6 + 1);
}