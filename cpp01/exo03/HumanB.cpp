#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->name = name;
    this->weapon =  NULL;
}
HumanB::~HumanB(){
    std::cout << "HumanB destroyed" << std::endl;
};
void HumanB::attack()
{
    if (weapon != NULL)
        std::cout << this->name << " attacks with their " << (*weapon).getType() << std::endl;
    else
        std::cout << this->name << " has no weapon an cannot attack." << std::endl;
};

void HumanB::setWeapon(Weapon &club)
{
    this->weapon = &club;
};