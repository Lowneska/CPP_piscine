/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:13:19 by skhali            #+#    #+#             */
/*   Updated: 2022/12/10 22:36:01 by skhali           ###   ########.fr       */
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
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat( void ) const;
        int toInt( void ) const;

};
std::ostream &operator<<(std::ostream& COUT, const Fixed &fixed);
#endif
