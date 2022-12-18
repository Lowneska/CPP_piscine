/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 22:08:10 by skhali            #+#    #+#             */
/*   Updated: 2022/12/18 15:03:02 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	{
	try
		{
			//Bureaucrat				person1("kenzy", 130);
			//ShrubberyCreationForm	form("garden");
			//Bureaucrat			person1("kenzy", 1);
			//RobotomyRequestForm	form("an apple");
			Bureaucrat				person1("kenzy", 2);
			PresidentialPardonForm	form("sofia");
			
			std::cout << std::endl;
			
			std::cout << person1 << std::endl;
			std::cout << form << std::endl;

			person1.signForm(form);
			person1.executeForm(form);
			
			std::cout << std::endl;
		}
		catch (std::exception const &e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}
	return 0;
}