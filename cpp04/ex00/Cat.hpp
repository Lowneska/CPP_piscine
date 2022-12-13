/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:51:00 by skhali            #+#    #+#             */
/*   Updated: 2022/12/12 21:22:19 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CAT_HPP_
#define _CAT_HPP_
#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{
protected :
    std::string type;
public :
    Cat();
    Cat(std::string type);
    virtual ~Cat();
    Cat(const Cat& copy);
    Cat &operator=(const Cat& cat);
    std::string getType() const;
    virtual void makeSound(void) const;

};
#endif