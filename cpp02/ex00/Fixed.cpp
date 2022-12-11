/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:13:12 by skhali            #+#    #+#             */
/*   Updated: 2022/12/10 16:13:13 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

static const uint bits_number = 8;
Fixed::Fixed()
{
    std::cout << "Default constructor called." << std::endl;
    this->value = 0;
}

Fixed::Fixed(const Fixed &fixed) : value(fixed.value)
{
    std::cout << "Copy constructor called." << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called." << std::endl;
}

Fixed &Fixed::operator=(Fixed const &val)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->value = val.value;
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called." << std::endl;
    return this->value;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called." << std::endl;
    this->value = raw;
}
