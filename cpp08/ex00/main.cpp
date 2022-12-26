/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:42:11 by skhali            #+#    #+#             */
/*   Updated: 2022/12/26 13:42:12 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main()
{
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	try {
		std::cout << *easyfind(v, 2) << std::endl;
	} catch (std::exception &e) { std::cout << e.what() << std::endl; }

	std::cout << "------------------------------" << std::endl;
	
	try {
		std::cout << *easyfind(v, 100) << std::endl;
	} catch (std::exception &e) { std::cout << e.what() << std::endl; }	
	
	std::cout << "------------------------------" << std::endl;
}