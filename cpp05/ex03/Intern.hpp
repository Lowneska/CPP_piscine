#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"

/*typedef struct s_mkForm	t_mkForm;
typedef AForm *			(*t_fct)(std::string const &target);

struct s_mkForm
{
	std::string const	name;
	t_fct const			maker;
};*/

typedef Form* (*function)(std::string target);
typedef struct s_pair
{
	std::string type;
	function newForm;
} t_pair;


class Intern
{
private:
	static s_pair	hmap[];
	class NoType : public std::exception
	{
	private:
		virtual char const	*what(void) const throw() { return " No form of this type.";};
	};

public:
	Intern(void);
	Intern(Intern const &src);
	~Intern(void);

    Intern	&operator=(Intern const &intern);
	
	Form	*makeForm(std::string const name, std::string const target) const;
};

#endif