#include "RobotomyRequestForm.hpp"

//Créer un form et initialiser les attributs du sous forme
RobotomyRequestForm::RobotomyRequestForm() : Form(), _target("default target")
{
    std::cout << "Robotomy request form constructor has been called." << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("robotomy form", false, 72, 45), _target(target)
{
    std::cout << "Robotomy request form constructor has been called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : Form(src),
	_target(src._target)
{
    std::cout << "Robotomy request form copy constructor has been called." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout << "Robotomy request form destructor has been called." << std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &form)
{
    this->Form::operator=(form);
	this->_target = form._target;
	return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > this->getGradeExecute())
    {
		throw Form::GradeTooLowExceptionExcec();
    }
    else if (this->getIsSigned() != true)
    {
        throw Form::NotSigned();
    }
    std::cout << "* Drill noises *" << std::endl;
    //seed the random number generator with the current time
    srand(time(0));
    if ((std::rand() % 2) == 0)
		std::cout << this->_target << " has been robotomized !"<< std::endl;
	else
		std::cout << "The robotomy of " << this->_target << " failed :(" << std::endl;
}

