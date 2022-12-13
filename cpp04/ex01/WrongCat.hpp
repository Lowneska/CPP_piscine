#ifndef _WRONGCAT_HPP_
#define _WRONGCAT_HPP_
#include <iostream>
#include"WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
protected :
    std::string type;
public :
    WrongCat();
    WrongCat(std::string type);
    virtual ~WrongCat();
    WrongCat(const WrongCat& copy);
    WrongCat &operator=(const WrongCat& cat);
    std::string getType() const;
    void makeSound(void) const;

};
#endif