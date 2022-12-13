/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:31:52 by skhali            #+#    #+#             */
/*   Updated: 2022/12/12 21:52:27 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal default constructor created." << std::endl;
    this->type = "Animal";
}

Animal::Animal(std::string type)
{
    std::cout << "Animal constructor created." << std::endl;
    this->type = type;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called." << std::endl;
}

Animal::Animal(const Animal& copy)
{
    std::cout << "Animal copy constructor created." << std::endl;
    this->type = copy.type;
}

Animal &Animal::operator=(const Animal& animal)
{
    this->type = animal.type;
    return (*this);
}

std::string Animal::getType() const
{
    return (this->type);
}

void Animal::makeSound(void) const
{
    std::cout << "Animal sound is made !" << std::endl;
}