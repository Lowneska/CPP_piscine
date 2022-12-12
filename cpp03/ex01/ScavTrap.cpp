/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:40:17 by skhali            #+#    #+#             */
/*   Updated: 2022/12/12 16:27:17 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap default constructor called." << std::endl;
    this->_hp = 100;
    this->_ep = 50;
    this->_dp = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap constructor called." << std::endl;
    this->_hp = 100;
    this->_ep = 50;
    this->_dp = 20;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &copy) : ClapTrap(copy)
{
    std::cout << "ScavTrap copy constructor called." << std::endl;
    
    this->_hp = copy._hp;
    this->_ep = copy._ep;
    this->_dp = copy._dp;
}
ScavTrap &ScavTrap::operator=(ScavTrap const & ct)
{
    this->ClapTrap::operator=(ct);
    return (*this);
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is on Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if ((this->_ep > 0) && (this->_hp > 0))
    {
        this->_ep--;
        std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_dp << " point(s) of damage !" << std::endl;
    }
    else if (this->_ep <= 0)
        std::cout << "ScavTrap " << this->_name << "'s energy is too low to attack." << std::endl;
    else
        std::cout  << "ScavTrap " << this->_name << "'s hit points are null, no action can be permformed." << std::endl;
}