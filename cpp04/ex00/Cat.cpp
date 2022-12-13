/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:51:11 by skhali            #+#    #+#             */
/*   Updated: 2022/12/12 21:54:34 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat default constructor created." << std::endl;
}

Cat::Cat(std::string type) : Animal(type)
{
    std::cout << "Cat constructor created." << std::endl;
    this->type = type;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called." << std::endl;
}

Cat::Cat(const Cat& copy) : Animal(copy)
{
    std::cout << "Cat copy constructor created." << std::endl;
    this->type = copy.type;
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