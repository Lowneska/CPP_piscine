/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 23:14:00 by skhali            #+#    #+#             */
/*   Updated: 2022/12/18 23:14:01 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

//Créer un form et initialiser les attributs du sous forme
PresidentialPardonForm::PresidentialPardonForm() : Form(), _target("default target")
{
    std::cout << "Robotomy request form constructor has been called." << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("robotomy form", false, 25, 5), _target(target)
{
    std::cout << "Robotomy request form constructor has been called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : Form(src),
	_target(src._target)
{
    std::cout << "Robotomy request form copy constructor has been called." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << "Robotomy request form destructor has been called." << std::endl;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &form)
{
    this->Form::operator=(form);
	this->_target = form._target;
	return *this;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > this->getGradeExecute())
    {
		throw Form::GradeTooLowExceptionExcec();
    }
    else if (this->getIsSigned() != true)
    {
        throw Form::NotSigned();
    }
    std::cout << this->_target <<" a été pardonné par Zaphod Beeblebrox." << std::endl;

}