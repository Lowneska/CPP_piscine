/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:52:38 by skhali            #+#    #+#             */
/*   Updated: 2022/12/13 00:30:25 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
int main()
{
	{
		int n = 4;
		const Animal *tab[n];
		for (int i = 0; i < 2; i++)
			tab[i] = new Dog();
		for (int i = 2; i < n; i++)
            tab[i] = new Cat();
		
		std::cout << std::endl;

		tab[0]->getBrain().setIdea("Doggo tought 1", 0);
		tab[0]->getBrain().setIdea("Dog 2", 1);
		tab[0]->getBrain().setIdea("Dog 3", 2);

        tab[2]->getBrain().setIdea("Catto tought 1", 0);
		tab[2]->getBrain().setIdea("Cat 2", 1);
		tab[2]->getBrain().setIdea("Cat 3", 2);

		std::cout << tab[0]->getBrain().getIdea(0) << std::endl;
		std::cout << tab[0]->getBrain().getIdea(1) << std::endl;
        std::cout << tab[0]->getBrain().getIdea(2) << std::endl;

		std::cout << std::endl;

		const Animal *dog = tab[0];

        const Animal *cat(tab[2]);
        //const Cat *cat1 = new Cat();
        //const Cat *cat(cat1);

		std::cout << std::endl;
        std::cout << dog->getType() << std::endl;
		std::cout << dog->getBrain().getIdea(0) << std::endl;
		std::cout << dog->getBrain().getIdea(1) << std::endl;
        std::cout << dog->getBrain().getIdea(2) << std::endl;

        std::cout << std::endl;
        
        std::cout << cat->getType() << std::endl;
        std::cout << cat->getBrain().getIdea(0) << std::endl;
		std::cout << cat->getBrain().getIdea(1) << std::endl;
        std::cout << cat->getBrain().getIdea(2) << std::endl;

		std::cout << std::endl;

		for (int i = 0; i < n; i++)
			delete tab[i];
        //delete cat1;
	}
	return (0);
}