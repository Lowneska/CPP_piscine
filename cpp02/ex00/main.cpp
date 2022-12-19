/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:13:23 by skhali            #+#    #+#             */
/*   Updated: 2022/12/19 15:55:43 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
int main(void)
{
    Fixed a;
   
    //Fixed c;
    //c.setRawBits(12);
    //a.setRawBits(27);
    
    Fixed c;
    Fixed b(a);
    c = b;
     
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    return 0;
}