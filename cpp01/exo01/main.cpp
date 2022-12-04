/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:49:57 by skhali            #+#    #+#             */
/*   Updated: 2022/12/03 19:15:55 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int main(void)
{
    Zombie *z1 = zombieHorde(5, "miniax");
    for (int i = 0; i < 5; i++)
        z1->announce();
    //pour les tableaux
    delete[] z1;
}