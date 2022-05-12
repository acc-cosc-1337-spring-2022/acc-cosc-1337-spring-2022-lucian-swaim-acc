#include "point_phase.h"

PointPhase::PointPhase(int p)
{
    point = p;
}

Phase::RollOutcome PointPhase::get_outcome(Roll* roll)
{   
    if (roll->roll_value() == point)
    {
        return Phase::RollOutcome::point;
    }
    else if (roll->roll_value() == 7)
    {
        return Phase::RollOutcome::seven_out;
    }
    else
    {
        return Phase::RollOutcome::nopoint;
    }
}