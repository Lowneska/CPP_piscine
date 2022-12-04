/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:49:57 by skhali            #+#    #+#             */
/*   Updated: 2022/12/03 18:49:58 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int main()
{
    //Pile
    Zombie z1("Kenzy");

    z1.announce();

    //Tas -> allocation dynamique
    Zombie *z2 = newZombie("Sofia");

    z2->announce();
    //Il faut delete ce qui est alloué dynamiquement
    delete z2;
}