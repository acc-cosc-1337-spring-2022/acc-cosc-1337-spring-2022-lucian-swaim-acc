#include "roll.h"

class Phase
{
public:
    enum class RollOutcome;
    virtual RollOutcome get_outcome(Roll* roll);
};