#include "shooter.h"

Roll* Shooter::throw_die(Die& d1, Die& d2)
{
    Roll* rollObj = new Roll(d1, d2);

    rollObj->roll_die();

    rolls.push_back(rollObj);

    return rollObj;
}

std::ostream& operator<<(std::ostream& out, const Shooter& shooterObj)
{
    for (size_t i = 0; i < shooterObj.rolls.size(); i++)
    {
        out << shooterObj.rolls[i]->roll_value()<<"\n";
    }
    return out;
}

Shooter::~Shooter()
{
    for (size_t i = 0; i < rolls.size(); i++)
    {
        delete rolls[i];
    }
}
// Shooter::~Shooter()
// {}
/*--Shooter Deconstructor Issues--
    I could not get the step of deleting the contents of "vector<Roll*> rolls" to work.
    I tried for many hours to get the instructions for Shooter deconstructor to work.
    I tried half a dozen different ways of iterating through a vector of pointers and calling delete on its contents.

    I tried using std::unique_ptr instead of raw pointers, and letting std::unique_ptr delete itself, as is the safer way to manage things. 

    Everything I tried resulted in some kind of error, almost always a "SIGABRT - Abort (abnormal termination) signal" error or similar.

    The only way I could get Question 3 to work was by not writing code for a deconstructor. To my understanding, this leaves a memory leak because the pointers in the "rolls" vector are never deleted. I spent a good 6+ hours trying to fix this problem, and couldn't find a solution besides turning a blind eye to this potential memory leak.  
    
    I'm at a loss here, hopefully this is either a common problem on this final or it's only a few points off.
    Thank you for reading. */