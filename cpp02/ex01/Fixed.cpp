/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:13:12 by skhali            #+#    #+#             */
/*   Updated: 2022/12/11 13:29:47 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//je mets tout dans le fixed pour ne rien perdre
//bitshifting de 8 du coup
//les conversions en int sont easy

Fixed::Fixed()
{
    std::cout << "Default constructor called." << std::endl;
    this->value = 0;
}

Fixed::Fixed(const int val)
{
    std::cout << "Int constructor called." << std::endl;
    this->value = val << this->bits_number;
}

Fixed::Fixed(const float val)
{
    std::cout << "Float constructor called." << std::endl;
    //multiplies the float by 2^exp
    this->value = roundf(ldexp(val, this->bits_number));
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

std::ostream& operator<<(std::ostream& COUT, const Fixed &fixed)
{
    COUT << fixed.toFloat();
    return COUT;
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

//on fait l'inverse et on divide by 2^exp
float Fixed::toFloat(void) const
{
    return (float)this->value / (float)(1 << this->bits_number);
}

int Fixed::toInt(void) const
{
    return this->value >> this->bits_number;
}
