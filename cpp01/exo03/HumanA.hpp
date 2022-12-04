#ifndef _HUMAN_A_
#define _HUMAN_A_
#include "Weapon.hpp"

class HumanA
{
public :
    Weapon &weapon;
    std::string name;

    HumanA(std::string name, Weapon& weapon);
    ~HumanA();
    void attack();
};
#endif