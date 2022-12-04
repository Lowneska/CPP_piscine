#ifndef _HUMAN_B_
#define _HUMAN_B_
#include "Weapon.hpp"

class HumanB
{
private :
    Weapon *weapon;
    std::string name;
public :
        
    HumanB(std::string name);
    ~HumanB();
    void attack();
    void setWeapon(Weapon &club);
};
#endif