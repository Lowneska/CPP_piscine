/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 23:14:35 by skhali            #+#    #+#             */
/*   Updated: 2022/12/18 23:14:36 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

//Créer un form et initialiser les attributs du sous forme
ShrubberyCreationForm::ShrubberyCreationForm() : Form(), _target("default target")
{
    std::cout << "Shrubbery form constructor has been called." << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("shrubbery form", false, 145, 137), _target(target)
{
    std::cout << "Shrubbery form constructor has been called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : Form(src),
	_target(src._target)
{
    std::cout << "Shrubbery form copy constructor has been called." << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << "Shrubbery form destructor has been called." << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &form)
{
    this->Form::operator=(form);
	this->_target = form._target;
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::ofstream		file;

	if (executor.getGrade() > this->getGradeExecute())
    {
		throw Form::GradeTooLowExceptionExcec();
    }
    else if (this->getIsSigned() != true)
    {
        throw Form::NotSigned();
    }

	file.open((this->_target + std::string("_shrubbery.txt")).c_str());
	file << "        &&& &&  & &&\n"
    << "   && &\\/&\\|& ()|/ @, &&\n"
    << "   &\\/(/&/&||/& /_/)_&/_&\n"
    << "  &() &\\/&|()|/&\\/ '%\" & ()\n"
    << " &_\\_&&_\\ |& |&&/&__%_/_& &&\n"
    << "&&   && & &| &| /& & % ()& /&&\n"
    << "()&_---()&\\&\\|&&-&&--%---()~\n"
    << "     &&     \\|||\n"
    << "              |||\n"
    << "              |||\n"
    << "              |||\n"
    << "        , -=-~  .-^- _\n" << std::endl;
	file.close();
}

