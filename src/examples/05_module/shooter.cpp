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
    for (auto i = 0; i < shooterObj.rolls.size(); i++)
    {
        out << shooterObj.rolls[i]->roll_value()<<"\n";
    }
    return out;
}

Shooter::~Shooter()
{
    for (auto ptr : rolls)
    {
        delete ptr;
    }
}