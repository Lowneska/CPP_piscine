/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 10:53:57 by skhali            #+#    #+#             */
/*   Updated: 2022/12/24 10:53:58 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IDENTIFY_HPP
# define IDENTIFY_HPP

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

//convertis un pointeur ou un référence d'un type de base
//en un pointeur ou une référence de type hérité
//renvois null pour les pointeurs
//lève un exception bad::cast pour une ref
void	identify(Base *p)
{
    if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Not a known base." << std::endl;
}
//__attribute__((nonnull));
void	identify(Base &p)
{
    //int i = 0;
    try 
    {
        (void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
        //i = 1;
    }
    catch (std::exception const &e) {}
    //if (i == 1)
    //    return ;
    try 
    {
        (void)dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
     //   i = 1;
    }
    catch (std::exception const &e) {}
    //if (i == 1)
    //    return ;
    try 
    {
        (void)dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
    //    i = 1;
    }
    catch (std::exception const &e) {}
    //if (i == 1)
    //    return ;
}
Base	*generate(void)
{
    std::srand(std::time(0));
    int random = rand() % 3;

    switch (random)
    {
    case 0:
        return new A;
        break;
    case 1:
        return new B;
        break;
    case 2:
        return new C;
        break;
    }
    return NULL;
};

#endif