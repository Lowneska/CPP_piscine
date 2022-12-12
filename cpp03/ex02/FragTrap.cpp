/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:40:17 by skhali            #+#    #+#             */
/*   Updated: 2022/12/12 16:32:15 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap default constructor called." << std::endl;
    this->_hp = 100;
    this->_ep = 100;
    this->_dp = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "FragTrap constructor called." << std::endl;
    this->_hp = 100;
    this->_ep = 100;
    this->_dp = 30;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called." << std::endl;
}

FragTrap::FragTrap(FragTrap const &copy) : ClapTrap(copy)
{
    std::cout << "FragTrap copy constructor called." << std::endl;
    
    this->_hp = copy._hp;
    this->_ep = copy._ep;
    this->_dp = copy._dp;
}
FragTrap &FragTrap::operator=(FragTrap const & ct)
{
    this->ClapTrap::operator=(ct);
    return (*this);
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << " wants to high five !" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
    if ((this->_ep > 0) && (this->_hp > 0))
    {
        this->_ep--;
        std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_dp << " point(s) of damage !" << std::endl;
    }
    else if (this->_ep <= 0)
        std::cout << "FragTrap " << this->_name << "'s energy is too low to attack." << std::endl;
    else
        std::cout  << "FragTrap " << this->_name << "'s hit points are null, no action can be permformed." << std::endl;
}