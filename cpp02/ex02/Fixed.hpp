/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:13:19 by skhali            #+#    #+#             */
/*   Updated: 2022/12/11 15:05:26 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FIXED_HPP_
# define _FIXED_HPP_

#include <cmath>
#include <iostream>

typedef unsigned int	uint;
class Fixed
{
    private :
        int value;
        static const uint bits_number = 8;
    public :
        Fixed();
        Fixed(const int val);
        Fixed(const float val);
        Fixed(const Fixed& fixed);
        ~Fixed();
        Fixed &operator=(Fixed const &val);
        Fixed operator+(Fixed const &val);
        Fixed operator-(Fixed const &val);
        Fixed operator*(Fixed const &val);
        Fixed operator/(Fixed const &val);
        bool operator<(Fixed const &val) const;
        bool operator>(Fixed const &val) const;
        bool operator<=(Fixed const &val) const;
        bool operator>=(Fixed const &val) const;
        bool operator==(Fixed const &val) const;
        bool operator!=(Fixed const &val) const;
        Fixed &operator++(void);
        Fixed operator++(int);
        Fixed &operator--(void);
        Fixed operator--(int);
        static Fixed &max(Fixed &val1, Fixed &val2);
        static Fixed &min(Fixed &val1, Fixed &val2);
        static Fixed const &max(Fixed const &val1, Fixed const &val2);
        static Fixed const &min(Fixed const &val1, Fixed const &val2);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat( void ) const;
        int toInt( void ) const;

};
std::ostream &operator<<(std::ostream& COUT, const Fixed &fixed);
#endif
