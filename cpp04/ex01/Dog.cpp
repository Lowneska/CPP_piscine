/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:51:14 by skhali            #+#    #+#             */
/*   Updated: 2022/12/13 00:18:13 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog default constructor created." << std::endl;
    this->brain = new Brain();
}

Dog::Dog(std::string type) : Animal(type)
{
    std::cout << "Dog constructor created." << std::endl;
    this->type = type;
    this->brain = new Brain();
}

Dog::~Dog()
{
    std::cout << "Dog destructor called." << std::endl;
    delete this->brain;
}

Dog::Dog(const Dog& copy) : Animal(copy)
{
    std::cout << "Dog copy constructor created." << std::endl;
    this->type = copy.type;
    this->brain = new Brain(*copy.brain);
}

Dog &Dog::operator=(const Dog& dog)
{
    this->type = dog.type;
    return (*this);
}

std::string Dog::getType() const
{
    return (this->type);
}

void Dog::makeSound(void) const
{
    std::cout << "૮ ・ﻌ・ა woufˎˊ˗" << std::endl;
}

Brain	&Dog::getBrain(void) const
{
	return (*this->brain);
}