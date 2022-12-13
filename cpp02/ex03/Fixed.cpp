/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:13:12 by skhali            #+#    #+#             */
/*   Updated: 2022/12/11 15:17:18 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* Constructeurs et destructeur */

Fixed::Fixed()
{
    //std::cout << "Default constructor called." << std::endl;
    this->value = 0;
}

Fixed::Fixed(const int val)
{
    //std::cout << "Int constructor called." << std::endl;
    this->value = val << this->bits_number;
}

Fixed::Fixed(const float val)
{
    //std::cout << "Float constructor called." << std::endl;
    //roundf dans la consigne but why
    this->value = roundf(ldexpf(val, this->bits_number));
}

Fixed::Fixed(const Fixed &fixed) : value(fixed.value)
{
   // std::cout << "Copy constructor called." << std::endl;
}

Fixed::~Fixed()
{
    //std::cout << "Destructor called." << std::endl;
}

/* Opérateurs */

Fixed &Fixed::operator=(Fixed const &val)
{
   // std::cout << "Copy assignment operator called" << std::endl;
    this->value = val.value;
    return *this;
}

Fixed Fixed::operator+(Fixed const &val)
{
    Fixed new_fixed;
    new_fixed.setRawBits(this->getRawBits() + val.getRawBits());
    return (new_fixed);
}

Fixed Fixed::operator-(Fixed const &val)
{
    Fixed new_fixed;
    new_fixed.setRawBits(this->getRawBits() - val.getRawBits());
    return (new_fixed);
}

Fixed Fixed::operator*(Fixed const &val)
{
    Fixed new_fixed;
    //je divise l'extra bitshift
    //nos x et y peuvent overflow alors que le resultat final n'overflow pas !
    new_fixed.setRawBits(((long int)this->getRawBits() * (long int)val.getRawBits()) / (1 << this->bits_number));
    return (new_fixed);
}

Fixed Fixed::operator/(Fixed const &val)
{
    Fixed new_fixed;
    new_fixed.setRawBits(((long int)this->getRawBits() * (1 << this->bits_number))/ val.getRawBits());
    return (new_fixed);
}

bool Fixed::operator<(Fixed const &val) const
{
    return (this->getRawBits() < val.getRawBits());
}

bool Fixed::operator>(Fixed const &val) const
{
    return (this->getRawBits() > val.getRawBits());
}

bool Fixed::operator>=(Fixed const &val) const
{
     return (this->getRawBits() >= val.getRawBits());
}

bool Fixed::operator<=(Fixed const &val) const
{
     return (this->getRawBits() <= val.getRawBits());
}

std::ostream& operator<<(std::ostream& COUT, const Fixed &fixed)
{
    COUT << fixed.toFloat();
    return COUT;
}

bool Fixed::operator!=(Fixed const &val) const
{
     return (this->getRawBits() != val.getRawBits());
}

Fixed &Fixed::operator++(void)
{
    this->value++;
    return (*this);
}

//renvois la valeur de fixed et update l'autre
//int est ici pour aider le compilateur a differencier
Fixed Fixed::operator++(int)
{
    Fixed fixed(*this);
    this->value++;
    return fixed;
}

Fixed &Fixed::operator--(void)
{
    this->value--;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed fixed(*this);
    this->value--;
    return fixed;
}

Fixed &Fixed::max(Fixed &val1, Fixed &val2)
{
    if (val1 > val2)
        return (val1);
    else
        return (val2);
}

Fixed &Fixed::min(Fixed &val1, Fixed &val2)
{
    if (val1 < val2)
        return (val1);
    else
        return (val2);
}

Fixed const &Fixed::max(Fixed const &val1, Fixed const &val2)
{
    if (val1 > val2)
        return (val1);
    else
        return (val2);
}

Fixed const &Fixed::min(Fixed const &val1, Fixed const &val2)
{
    if (val1 < val2)
        return (val1);
    else
        return (val2);
}

bool Fixed::operator==(Fixed const &val) const
{
     return (this->getRawBits() == val.getRawBits());
}

/* Getter et setter */

int Fixed::getRawBits(void) const
{
    //std::cout << "getRawBits member function called." << std::endl;
    return this->value;
}

void Fixed::setRawBits(int const raw)
{
    //std::cout << "setRawBits member function called." << std::endl;
    this->value = raw;
}

/* Fonctions */

float Fixed::toFloat(void) const
{
    return (float)this->value / (float)(1 << this->bits_number);
}

int Fixed::toInt(void) const
{
    return this->value >> this->bits_number;
}
