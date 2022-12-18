/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 22:08:10 by skhali            #+#    #+#             */
/*   Updated: 2022/12/18 23:12:43 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	{
		try
		{
			Intern	intern;
			Form	*form;
			Bureaucrat person1("kenzy", 2);

			//form = intern.makeForm("shrubbery creation", "Bender");
			//form = intern.makeForm("presidential pardon", "Bender");
			//form = intern.makeForm("robotomy request", "Bender");
			form = intern.makeForm("other", "Bender");
			person1.signForm(*form);
			person1.executeForm(*form);
			std::cout << *form << std::endl;
			delete form;
		}
		catch (std::exception &e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}
	return 0;
}