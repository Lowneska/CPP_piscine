/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:52:38 by skhali            #+#    #+#             */
/*   Updated: 2022/12/12 22:18:04 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "WrongCat.hpp"
int main()
{
    const Animal* meta = new Animal();
    Animal* j = new Dog();
    const WrongAnimal* i = new WrongCat();


    Animal j_copy(*j);
    
    std::cout << j_copy.getType() << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    j_copy.makeSound();
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    //virtual destructor
    delete meta;
    delete j;
    delete i;
    return 0;
}