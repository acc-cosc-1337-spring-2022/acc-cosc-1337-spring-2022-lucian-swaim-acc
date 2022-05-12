#include "come_out_phase.h"

Phase::RollOutcome get_outcome(Roll* roll)
{
    if ((roll->roll_value() == 7) || (roll->roll_value() == 11))
    {
        return Phase::RollOutcome::natural;
    }
    else if ((roll->roll_value() == 2) || (roll->roll_value() == 3) || (roll->roll_value() == 12))
    {
        return Phase::RollOutcome::craps;
    }
    else
    {
        return Phase::RollOutcome::point;
    }
}