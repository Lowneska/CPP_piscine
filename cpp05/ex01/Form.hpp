/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 23:16:01 by skhali            #+#    #+#             */
/*   Updated: 2022/12/18 23:16:02 by skhali           ###   ########.fr       */
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

public:
	Form();
    Form(std::string const name, bool issigned, const unsigned int gradesign, const unsigned int gradeexecute );
	Form(Form const &src);
	~Form(void);
    Form	&operator=(Form const &form);

	std::string const	&getName() const;
    bool const			&getIsSigned() const;
	unsigned int const	&getGradeSign() const;
	unsigned int const	&getGradeExecute() const;

    void	beSigned(Bureaucrat const &bureaucrat);
};

std::ostream	&operator<<(std::ostream &COUT, Form const &form);

#endif