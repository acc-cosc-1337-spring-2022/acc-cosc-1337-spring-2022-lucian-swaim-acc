#include "come_out_phase.h"

RollOutcome ComeOutPhase::get_outcome(Roll* roll)
{
    if ((roll->roll_value() == 7) || (roll->roll_value() == 11))
    {
        return RollOutcome::natural;
    }
    else if ((roll->roll_value() == 2) || (roll->roll_value() == 3) || (roll->roll_value() == 12))
    {
        return RollOutcome::craps;
    }
    else
    {
        return RollOutcome::point;
    }
}