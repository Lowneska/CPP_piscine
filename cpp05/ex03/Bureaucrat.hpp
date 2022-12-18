/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 22:08:26 by skhali            #+#    #+#             */
/*   Updated: 2022/12/18 13:51:24 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BUREAUCRAT_HPP_
# define _BUREAUCRAT_HPP_

# include <iostream>
# include <string>
# include <exception>
# include "Form.hpp"

//retourne une chaîne de caractères contenant un message
//descriptif de l'exception, utilisée pour fournir des
//informations sur l'exception aux utilisateurs ou aux développeurs
class Form;

class Bureaucrat
{
    private :
        std::string const _name;
        unsigned int _grade;

        class GradeTooHighException : public std::exception
	    {
	        public:
			virtual const char *what() const throw(){return "Too high !";};
	    };

	    class GradeTooLowException : public std::exception
	    {
	    	public:
		    	virtual const char	*what() const throw(){return "Too low !";};
	    };

    public :
		Bureaucrat();
        Bureaucrat(std::string const name, unsigned int grade);
	    Bureaucrat(Bureaucrat const &src);
	    virtual ~Bureaucrat(void);
        Bureaucrat	&operator=(Bureaucrat const &bureaucrat);

		std::string const &getName() const ;
		unsigned int const &getGrade()const ;

		void incrementGrade();
		void decrementGrade();

		void	signForm(Form &form) const;
		void	executeForm(Form const & form);
};
std::ostream	&operator<<(std::ostream &COUT, Bureaucrat const &bureaucrat);
#endif