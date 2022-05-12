#include <vector>
#include <iostream>
#include <memory>

#include "roll.h"

#ifndef SHOOTER_H
#define SHOOTER_H

class Shooter
{
public:
    std::unique_ptr<Roll> throw_die(Die&, Die&);
    friend std::ostream& operator<<(std::ostream&, const Shooter&);
    //~Shooter();
private:
    std::vector<std::unique_ptr<Roll>> rolls;
};

#endif

// class Shooter{
// public:
//     std::unique_ptr<Roll> throw_die (Die&, Die&);
//     friend std::ostream& operator<<(std::ostream&, const Shooter&);
//     //~Shooter();
// private:
//     std::vector<std::unique_ptr<Roll>> rolls;
//     // or is it supposed to be
//     // std::vector<Roll*> rolls;
// };