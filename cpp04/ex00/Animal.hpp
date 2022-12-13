/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:31:01 by skhali            #+#    #+#             */
/*   Updated: 2022/12/12 21:52:32 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ANIMAL_HPP_
#define _ANIMAL_HPP_
#include <iostream>

class Animal
{
protected :
    std::string type;
public :
    Animal();
    Animal(std::string type);
    virtual ~Animal();
    Animal(const Animal& copy);
    Animal &operator=(const Animal& animal);
    std::string getType() const;
    virtual void makeSound(void) const;
};
#endif