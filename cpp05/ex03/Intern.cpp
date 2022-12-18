/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 21:57:19 by skhali            #+#    #+#             */
/*   Updated: 2022/12/18 22:53:57 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"


Intern::Intern()
{
    std::cout << "Intern default constructor called." << std::endl;
}

Intern::Intern(Intern const &src __attribute__((unused)))
{
    // pour dire au compiler que la variable n'est pas utilisé
    std::cout << "Intern copy constructor called." << std::endl;
}

Intern::~Intern()
{
    std::cout << "Intern destructor called." << std::endl;
}

Intern	&Intern::operator=(Intern const & intern __attribute__((unused)))
{
	std::cout << "Intern copy constructor called." << std::endl;
	return *this;
}

Form *newPresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
};

Form *newRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
};

Form *newShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
};

s_pair	Intern::hmap[] = {
	{"robotomy request", &newRobotomyRequestForm},
	{ "presidential pardon", &newPresidentialPardonForm},
	{ "shrubbery creation", &newShrubberyCreationForm}
};

Form	*Intern::makeForm(std::string const name, std::string const target) const
{
	int	i;
    for(i = 0; i < 3; i++)
    {
        if (this->hmap[i].type.compare(name) == 0)
            return (this->hmap[i].newForm)(target);
    }
    throw Intern::NoType();
}