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
    // for (size_t i=0; i < rolls.size(); i++)
    // {
    //     Roll* rollRef = rolls.at(i);
    //     delete rollRef;
    // }
    for (std::vector<Roll *>::iterator i = rolls.begin(); i != rolls.end(); ++i) 
    {
        delete *i;
    }
    rolls.clear();
}