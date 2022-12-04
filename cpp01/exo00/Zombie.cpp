/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:22:32 by skhali            #+#    #+#             */
/*   Updated: 2022/12/03 18:50:20 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

std::string name = "";

Zombie::Zombie(std::string name)
{
    this->name = name;
}

Zombie::~Zombie()
{
    std::cout << Zombie::name << " has been destroyed." << std::endl;
};

void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}