#include "Weapon.hpp"

Weapon::Weapon(){};
Weapon::Weapon(std::string type)
{
    this->type = type;
};
Weapon::~Weapon(){
    std::cout << "Weapon destroyed" << std::endl;
};

const std::string& Weapon::getType()
{
    return this->type;
}
void Weapon::setType(std::string type)
{
    this->type = type;
}
