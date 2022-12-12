/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:37:33 by skhali            #+#    #+#             */
/*   Updated: 2022/12/12 16:37:14 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	player1;
	ScavTrap	player2("kenzy");
	ScavTrap	player2_copy(player2);

	std::cout << std::endl;
	
	player1.attack("sofia");
	player1 = player2;
	player1.attack("sofia");
	
	std::cout << std::endl;
	
	player2.attack("sofia");
	player2_copy.takeDamage(100);

	std::cout << std::endl;
	
	player1.takeDamage(100);

	std::cout << std::endl;
	
	player2.attack("sofia");
	player2_copy.attack("sofia");
	player2.guardGate();
	std::cout << std::endl;

	return 0;
}