/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:51:11 by skhali            #+#    #+#             */
/*   Updated: 2022/12/13 00:17:31 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat default constructor created." << std::endl;
    this->brain = new Brain;
}

Cat::Cat(std::string type) : Animal(type)
{
    std::cout << "Cat constructor created." << std::endl;
    this->type = type;
    this->brain = new Brain;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called." << std::endl;
    delete this->brain;
}

Cat::Cat(const Cat& copy) : Animal(copy)
{
    std::cout << "Cat copy constructor created." << std::endl;
    this->type = copy.type;
    this->brain = new Brain(*copy.brain);
}

Cat &Cat::operator=(const Cat& cat)
{
    this->type = cat.type;
    return (*this);
}

std::string Cat::getType() const
{
    return (this->type);
}

void Cat::makeSound(void) const
{
    std::cout << "/ᐠ. ｡.ᐟ\\ᵐᵉᵒʷˎˊ˗"  << std::endl;
}

Brain	&Cat::getBrain(void) const
{
	return (*this->brain);
}