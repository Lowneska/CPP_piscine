/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:11:59 by skhali            #+#    #+#             */
/*   Updated: 2022/12/12 16:11:22 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap default constructor called." << std::endl;
    this->_hp = 10;
    this->_ep = 10;
    this->_dp = 0;
    this->_name = "default";
}

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "ClapTrap constructor called." << std::endl;
    this->_hp = 10;
    this->_ep = 10;
    this->_dp = 0;
    this->_name = name;
}

ClapTrap::ClapTrap(ClapTrap const &copy)
{
    std::cout << "ClapTrap copy constructor called." << std::endl;
    this->_hp = copy._hp;
    this->_ep = copy._ep;
    this->_dp = copy._dp;
    this->_name = copy._name;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &ct)
{
    this->_dp = ct._dp;
    this->_ep = ct._ep;
    this->_hp = ct._hp;
    this->_name = ct._name;
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called." << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if ((this->_ep > 0) && (this->_hp > 0))
    {
        this->_ep--;
        std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_dp << " point(s) of damage !" << std::endl;
    }
    else if (this->_ep <= 0)
        std::cout << "ClapTrap " << this->_name << "'s energy is too low to attack." << std::endl;
    else
        std::cout  << "ClapTrap " << this->_name << "'s hit points are null, no action can be permformed." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
    this->_hp -= amount;
    if (this->_hp < 0)
    {
        this->_hp = 0;
        std::cout << "ClapTrap " << this->_name << " took " << amount << " damage point(s) and his hit points got to null."  << std::endl;
    }
    else
        std::cout << "ClapTrap " << this->_name << " took " << amount << " damage point(s)."  << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_ep > 0)
    {
        this->_ep--;
        this->_hp += amount;
        std::cout << "ClapTrap " << this->_name << " starts repairing itself ang gains " << amount << " hit point(s) !" << std::endl;
    }
    else if (this->_ep <= 0)
        std::cout << "ClapTrap " << this->_name << "'s energy is too low to attack." << std::endl;
    else
        std::cout  << "ClapTrap " << this->_name << "'s hit points are null, no action can be permformed." << std::endl;

}