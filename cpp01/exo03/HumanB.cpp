#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->name = name;
}
HumanB::~HumanB(){
    std::cout << "HumanB destroyed" << std::endl;
};
void HumanB::attack()
{
    std::cout << this->name << " attacks with their " << (*weapon).getType() << std::endl;
};

void HumanB::setWeapon(Weapon &club)
{
    this->weapon = &club;
};