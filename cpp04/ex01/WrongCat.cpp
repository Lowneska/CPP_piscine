#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << "WrongCat default constructor created." << std::endl;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type)
{
    std::cout << "WrongCat constructor created." << std::endl;
    this->type = type;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy)
{
    std::cout << "WrongCat copy constructor created." << std::endl;
    this->type = copy.type;
}

WrongCat &WrongCat::operator=(const WrongCat& cat)
{
    this->type = cat.type;
    return (*this);
}

std::string WrongCat::getType() const
{
    return (this->type);
}

void WrongCat::makeSound(void) const
{
    std::cout << "/ᐠ. ｡.ᐟ\\ᵐᵉᵒʷˎˊ˗"  << std::endl;
}