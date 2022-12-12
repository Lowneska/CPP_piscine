/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:37:33 by skhali            #+#    #+#             */
/*   Updated: 2022/12/12 16:45:23 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	player1;
	FragTrap	player2("kenzy");
	FragTrap	player2_copy(player2);

	std::cout << std::endl;

	player1 = player2;
	player1.attack("a tree");
	ClapTrap	player3(player2);
	player3.attack("a flower");
	
	std::cout << std::endl;

	player2.attack("sofia");
	player2_copy.takeDamage(100);
	player2.attack("sofia");
	player2_copy.attack("sofia");

	std::cout << std::endl;
	
	player2.highFivesGuys();
	//player3.highFivesGuys();

	return 0;
}