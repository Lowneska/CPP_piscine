/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:51:14 by skhali            #+#    #+#             */
/*   Updated: 2022/12/12 21:55:08 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog default constructor created." << std::endl;
}

Dog::Dog(std::string type) : Animal(type)
{
    std::cout << "Dog constructor created." << std::endl;
    this->type = type;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called." << std::endl;
}

Dog::Dog(const Dog& copy) : Animal(copy)
{
    std::cout << "Dog copy constructor created." << std::endl;
    this->type = copy.type;
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