/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:41:51 by skhali            #+#    #+#             */
/*   Updated: 2022/12/26 13:41:52 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	srand(time(0));

	{
		try {
			
			Span sp = Span(1);

			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);

			sp.affValues();
			std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
			std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		
		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "----------------------------------------------" << std::endl;

	{
		try {
		
			Span sp = Span(6);
			std::vector<int> v;

			v.push_back(19);
			/*v.push_back(9);
			v.push_back(1);
			v.push_back(40);
			v.push_back(48);
			v.push_back(8);*/

			sp.rangeOfIter(v.begin(), v.end(), v);

			sp.affValues();

			std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
			std::cout << "Longest span: " << sp.longestSpan() << std::endl;

		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
	}

	return 0;
}