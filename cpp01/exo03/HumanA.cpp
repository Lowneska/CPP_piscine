#include "HumanA.hpp"

//une reference doit etre initialisé avant de se voir assigner une valeur
HumanA::HumanA(std::string name, Weapon& tweapon) : weapon(tweapon)
{
    this->name = name;
    //weapon = &tweapon;
}
HumanA::~HumanA()
{
    std::cout << "HumanA destroyed" << std::endl;
};
void HumanA::attack()
{
    std::cout << this->name << " attacks with their " << weapon.getType() << std::endl;
};