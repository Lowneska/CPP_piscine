/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:13:19 by skhali            #+#    #+#             */
/*   Updated: 2022/12/11 15:30:09 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FIXED_HPP_
# define _FIXED_HPP_

#include <iostream>

typedef unsigned int	uint;
class Fixed
{
    private :
        int value;
        static const uint bits_number;
    public :
        Fixed();
        Fixed(const Fixed& fixed);
        ~Fixed();
        Fixed &operator=(Fixed const &val);
        int getRawBits(void) const;
        void setRawBits(int const raw);

};
#endif