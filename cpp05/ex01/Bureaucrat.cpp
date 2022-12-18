/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 22:59:43 by skhali            #+#    #+#             */
/*   Updated: 2022/12/18 14:42:11 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/***********************************************************************/
/*                                                                     */
/*                Constructors & Destructors                           */
/*                                                                     */
/***********************************************************************/
Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
    std::cout << "Bureaucrat default constructor called." << std::endl;
}
//constructeur par copie pour le const string 
Bureaucrat::Bureaucrat(std::string const name, unsigned int grade) : _name(name)
{
    std::cout << "Bureaucrat constructor called." << std::endl;
    this->_grade = grade;
	if (this->_grade < 1)
		throw GradeTooHighException();
	if (this->_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &bureaucrat) : _name(bureaucrat._name)
{
	std::cout << "Bureaucrat copy constructor has been called." << std::endl;
	this->_grade = bureaucrat._grade;
	if (this->_grade < 1)
		throw GradeTooHighException();
	if (this->_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor has been called." << std::endl;
}

/***********************************************************************/
/*                                                                     */
/*                            Operators                                */
/*                                                                     */
/***********************************************************************/

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &bureaucrat)
{
	this->_grade = bureaucrat._grade;
    //utiliser un pointeur non const qui pointe sur mon const
    // utilise "const_cast" pour enlever la qualité "const" de "p"
    std::string *p = const_cast<std::string*>(&(this->_name));
    *p = bureaucrat._name;
	return (*this);
}

std::ostream    &operator<<(std::ostream &COUT, Bureaucrat const &bureaucrat)
{
	COUT << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return COUT;
}

/***********************************************************************/
/*                                                                     */
/*                       Getters & Setters                             */
/*                                                                     */
/***********************************************************************/
//type std::string, qui est une classe de chaîne de caractères qui utilise la copie par valeur
//retourne une référence pour éviter l'appel d'un construcetur par copie
//la chaîne de caractères stockée dans la propriété _name est copiée et renvoyée par la méthode
//on utilise const pour éviter qu'on ne modifie la variable à l'aide de la ref
std::string const &Bureaucrat::getName() const {return this->_name;};
unsigned int const &Bureaucrat::getGrade() const {return this->_grade;};

/***********************************************************************/
/*                                                                     */
/*                              Fonctions                              */
/*                                                                     */
/***********************************************************************/
void Bureaucrat::incrementGrade()
{
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade()
{
    if (this->_grade < 1)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}


void	Bureaucrat::signForm(Form &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}
