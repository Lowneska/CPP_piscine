/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:31:01 by skhali            #+#    #+#             */
/*   Updated: 2022/12/13 00:58:36 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ANIMAL_HPP_
#define _ANIMAL_HPP_
#include <iostream>
#include "Brain.hpp"

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
    virtual Brain &getBrain(void) const = 0;
};
#endif