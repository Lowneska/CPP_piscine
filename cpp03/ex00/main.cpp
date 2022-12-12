/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:37:33 by skhali            #+#    #+#             */
/*   Updated: 2022/12/11 20:41:25 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap player1("Sofia");
	ClapTrap player2("Kenzy");

	player1.attack("Kenzy");
	player2.takeDamage(10); //juste pour test
    player2.attack("Sofia");
	player2.beRepaired(10);
    player2.attack("Sofia");
	return (0);
}