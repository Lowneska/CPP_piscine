#ifndef _WRONGANIMAL_HPP_
#define _WRONGANIMAL_HPP_
#include <iostream>

class WrongAnimal
{
protected :
    std::string type;
public :
    WrongAnimal();
    WrongAnimal(std::string type);
    virtual ~WrongAnimal();
    WrongAnimal(const WrongAnimal& copy);
    WrongAnimal &operator=(const WrongAnimal& animal);
    std::string getType() const;
    void makeSound(void) const;
};
#endif