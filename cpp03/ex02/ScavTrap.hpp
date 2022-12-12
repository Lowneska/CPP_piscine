#ifndef _SCAVTRAP_HPP_
#define _SCAVTRAP_HPP_
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(std::string);
        ~ScavTrap();
        ScavTrap(ScavTrap const &copy);
        ScavTrap &operator=(ScavTrap const & rhs);

        void guardGate();
        void attack(const std::string& target);
};
#endif