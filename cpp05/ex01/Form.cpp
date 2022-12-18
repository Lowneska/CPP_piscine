#include "Form.hpp"

Form::Form() :_name("default"), _isSigned(false), _gradeSign(150), _gradeExecute(150)
{
	if (this->_gradeSign < 1 || this->_gradeExecute < 1)
		throw Form::GradeTooHighException();
	if (this->_gradeSign > 150 || this->_gradeExecute > 150)
		throw Form::GradeTooLowException();
    std::cout << "Form default constructor called." << std::endl;
}

Form::Form(std::string const name, bool issigned, const unsigned int gradesign, const unsigned int gradeexecute ) :_name(name), _isSigned(issigned), _gradeSign(gradesign), _gradeExecute(gradeexecute)
{
	if (this->_gradeSign < 1 || this->_gradeExecute < 1)
		throw Form::GradeTooHighException();
	if (this->_gradeSign > 150 || this->_gradeExecute > 150)
		throw Form::GradeTooLowException();
    std::cout << "Form constructor called." << std::endl;
}

Form::Form(Form const &src) : _name(src._name), _isSigned(src._isSigned), _gradeSign(src._gradeSign), _gradeExecute(src._gradeExecute)
{
	if (this->_gradeSign < 1 || this->_gradeExecute < 1)
		throw Form::GradeTooHighException();
	if (this->_gradeSign > 150 || this->_gradeExecute > 150)
		throw Form::GradeTooLowException();
    std::cout << "Form copy constructor called." << std::endl;
}

Form::~Form()
{
    std::cout << "Form destructor called." << std::endl;
}

Form	&Form::operator=(Form const &bureaucrat)
{
    this->_isSigned = bureaucrat._isSigned;
    std::string *p = const_cast<std::string*>(&(this->_name));
    *p = bureaucrat._name;

    unsigned int *p1 = const_cast<unsigned int*>(&(this->_gradeSign));
    *p1 = bureaucrat._gradeSign;

    unsigned int *p2 = const_cast<unsigned int*>(&(this->_gradeExecute));
    *p2 = bureaucrat._gradeExecute;

	return *this;
}

std::ostream	&operator<<(std::ostream &COUT, Form const &form)
{
	COUT << "------------F o r m-----------" << std::boolalpha << std::endl
	<<"| Name: " << form.getName() << std::endl
	<< "| Is it signed ? " << form.getIsSigned() << std::endl
	<< "| Grade necessary to sign it : " << form.getGradeSign() << std::endl
	<< "| Grade necessary to excecute it : " << form.getGradeExecute() << std::endl;
	return COUT;
}

std::string const	&Form::getName() const {return this->_name;}

bool const	&Form::getIsSigned() const {return this->_isSigned;}

unsigned int const	&Form::getGradeSign() const {return this->_gradeSign;}

unsigned int const	&Form::getGradeExecute() const {return this->_gradeExecute;}

void	Form::beSigned(Bureaucrat const &bureaucrat)
{
    if (this->getIsSigned() == true)
    {
        throw Form::AlreadySigned();
    }
	else if (bureaucrat.getGrade() > this->_gradeSign)
    {
		throw Form::BureaucratGradeTooLow();
    }
	this->_isSigned = true;
}
