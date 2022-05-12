#include "roll.h"

#ifndef PHASE_H
#define PHASE_H
class Phase
{
public:
    enum class RollOutcome {natural, craps, point, seven_out, nopoint};
    virtual RollOutcome get_outcome(Roll* roll);
};
#endif