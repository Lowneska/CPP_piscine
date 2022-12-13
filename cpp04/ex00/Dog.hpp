/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:51:06 by skhali            #+#    #+#             */
/*   Updated: 2022/12/12 21:22:07 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _DOG_HPP_
#define _DOG_HPP_
#include <iostream>
#include "Animal.hpp"

class Dog : public Animal
{
protected :
    std::string type;
public :
    Dog();
    Dog(std::string type);
    virtual ~Dog();
    Dog(const Dog& copy);
    Dog &operator=(const Dog& dog);
    std::string getType() const;
    virtual void makeSound(void) const;

};
#endif