/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 22:08:10 by skhali            #+#    #+#             */
/*   Updated: 2022/12/18 10:47:02 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat person1 = Bureaucrat("kenzy", 30);
		//Bureaucrat person1 = Bureaucrat("kenzy", 0);
		Form form1 = Form("form", false, 30, 58);
		//Form form1 = Form("form", false, 50, 151);
		//Form form1 = Form("form", false, 151, 0);
		
		std::cout << std::endl;

		std::cout << person1 << std::endl;
		person1.decrementGrade();
		std::cout << person1 << std::endl;
		person1.signForm(form1);
		std::cout << form1 << std::endl;
		person1.signForm(form1);

		std::cout << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return (0);
}