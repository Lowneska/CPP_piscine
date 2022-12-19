/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:13:19 by skhali            #+#    #+#             */
/*   Updated: 2022/12/19 14:18:43 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FIXED_HPP_
# define _FIXED_HPP_

#include <iostream>

class Fixed
{
    private :
        int value;
        static const unsigned int bits_number = 8;
    public :
        Fixed();
        Fixed(const Fixed& fixed);
        ~Fixed();
        Fixed &operator=(Fixed const &val);
        int getRawBits(void) const;
        void setRawBits(int const raw);

};
#endif