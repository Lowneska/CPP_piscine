/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 22:08:10 by skhali            #+#    #+#             */
/*   Updated: 2022/12/17 22:08:11 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"

int main()
{
	try
	{
        Bureaucrat person1 = Bureaucrat("kenzy", 149);
		//Bureaucrat person1 = Bureaucrat("kenzy", 0);
        //Bureaucrat person1 = Bureaucrat();
		Bureaucrat person2 = Bureaucrat("sofia", 1);
	
		std::cout << std::endl;

		std::cout << person1 << std::endl;
		std::cout << person2 << std::endl;

		std::cout << std::endl;	
	
		//for (int i = 0; i < 25; i++)
		//	person2.incrementGrade();
            //person1.decrementGrade();

		std::cout << "Hello " << person2 << std::endl;
        std::cout << person1 << std::endl;

		std::cout << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	return (0);
}