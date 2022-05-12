#include "roll.h"

#ifndef ROLLOUTCOME_EC
#define ROLLOUTCOME_EC
enum class RollOutcome {natural, craps, point, seven_out, nopoint};
#endif

#ifndef PHASE_H
#define PHASE_H
class Phase
{
public:
    virtual RollOutcome get_outcome(Roll* roll){};
};
#endif