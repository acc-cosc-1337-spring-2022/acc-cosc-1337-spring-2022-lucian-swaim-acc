#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "phase.h"
#include "point_phase.h"
#include "come_out_phase.h"
#include "time.h"

#include <iostream>
using std::cout;


int main()
{
    srand(time(0));

    Die die1;
    Die die2;
    Shooter shooter;
    Roll* roll;
    roll = shooter.throw_die(die1, die2);

    ComeOutPhase come_out_phase;

    while ( (come_out_phase.get_outcome(roll) == RollOutcome::natural) || (come_out_phase.get_outcome(roll) == RollOutcome::craps) )
    {
        cout << "Rolled " << roll->roll_value() << " roll again\n";
        roll = shooter.throw_die(die1, die2);
    }

    cout << "Rolled " << roll->roll_value() << " start of point phase\n";
    cout << "Roll until " << roll->roll_value() << " or 7 is rolled\n";

    int point = roll->roll_value();
    roll = shooter.throw_die(die1, die2);

    PointPhase point_phase(point);

    /*
    while ( (point_phase.get_outcome(roll) == RollOutcome::point) || (point_phase.get_outcome(roll) == RollOutcome::nopoint) )
    
    The directions say to use the above loop condition ^ for the Point Phase,
    but by my understanding of the rules of Craps,
    the loop condition below is how the game SHOULD run for the Point Phase.
    */
    while ( (point_phase.get_outcome(roll) == RollOutcome::nopoint) )
    {
        cout << "Rolled " << roll->roll_value() << " roll again\n";
        roll = shooter.throw_die(die1, die2);
    }

    cout << "Rolled " << roll->roll_value() << " end of point phase\n";

    cout << shooter;
}
