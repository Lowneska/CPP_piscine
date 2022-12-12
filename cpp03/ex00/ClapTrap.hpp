#ifndef _CLAPTRAP_HPP_
#define _CLAPTRAP_HPP_
#include <iostream>

class ClapTrap
{
private :
    std::string _name;
    int         _hp;
    int         _ep;
    int         _dp;
public :
	ClapTrap(std::string); // constructeur
	ClapTrap(ClapTrap const & copy); // constructeur par copie
	ClapTrap &operator=(ClapTrap const & rhs); // surcharge d'operateur =
	~ClapTrap(); //Destructeur

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};
#endif
