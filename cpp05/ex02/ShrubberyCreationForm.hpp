#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include "Form.hpp"


class ShrubberyCreationForm : public Form
{
private:
	std::string	_target;

public:
	ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm const &src);
	virtual ~ShrubberyCreationForm(void);

	// Member functions
	virtual void	execute(Bureaucrat const &executor) const;

	ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &form);
};

#endif