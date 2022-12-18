/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 23:15:29 by skhali            #+#    #+#             */
/*   Updated: 2022/12/18 23:15:30 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	std::string const	_name;
	bool				_isSigned;
	unsigned int const			_gradeSign;
	unsigned int const			_gradeExecute;

protected :

	class GradeTooLowExceptionExcec : public std::exception
	{
    	public:
	    	virtual const char	*what() const throw(){return "the grade to excecute is too low to excecute.";};
    };
    class GradeTooHighException : public std::exception
	{
        public:
			virtual const char *what() const throw(){return "The grade to sign or to excecute is too high.";};
	};

	class GradeTooLowException : public std::exception
	{
    	public:
	    	virtual const char	*what() const throw(){return "The grade to sign or to excecute is too low.";};
    };
    class AlreadySigned : public std::exception
	{
    	public:
	    	virtual const char	*what() const throw(){return "the form is already signed.";};
    };
	class BureaucratGradeTooLow : public std::exception
	{
    	public:
	    	virtual const char	*what() const throw(){return "the Bureaucrat's grade is too low.";};
    };
	class NotSigned : public std::exception
	{
    	public:
	    	virtual const char	*what() const throw(){return "The form needs to be signed first.";};
    };

public:
	Form();
    Form(std::string const name, bool issigned, const unsigned int gradesign, const unsigned int gradeexecute );
	Form(Form const &src);
	virtual ~Form(void);
    Form	&operator=(Form const &form);

	std::string const	&getName() const;
    bool const			&getIsSigned() const;
	unsigned int const	&getGradeSign() const;
	unsigned int const	&getGradeExecute() const;

    void	beSigned(Bureaucrat const &bureaucrat);
	virtual void	execute(Bureaucrat const &executor) const = 0;
};

std::ostream	&operator<<(std::ostream &COUT, Form const &form);

#endif