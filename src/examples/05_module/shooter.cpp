#include "shooter.h"

Roll* Shooter::throw_die(Die& die01, Die& die02)
{
    Roll* rollObjPtr;

    rollObjPtr->roll_die();

    rolls.push_back(rollObjPtr);

    return rollObjPtr;
}

Shooter::~Shooter()
{
    for(int i = 0; i < rolls.size(); i++)
    {
        delete rolls[i];
    }
}

std::ostream& operator<<(std::ostream& out, const Shooter& shooter) // cout overloader
{

    for (int i = 0; i < shooter.rolls.size(); i++)
    {
        std::cout << shooter.rolls[i];
    }
    return out;
    
/*     if      (game.pegs.size() == 9)
    {
        for(int i=0 ; i < 9 ; i+=3)
        {
            cout << game.pegs[i] << "|" << game.pegs[i+1] << "|" << game.pegs[i+2] << "\n";
        }    
    }
    else if (game.pegs.size() == 16)
    {
        for(int i=0 ; i < 16 ; i+=4)
        {
        cout << game.pegs[i] << "|" << game.pegs[i+1] << "|" << game.pegs[i+2] << "|" << game.pegs[i+3] << "\n";
        }    
    }
    return out; */
}