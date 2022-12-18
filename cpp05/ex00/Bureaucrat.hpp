/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 22:08:26 by skhali            #+#    #+#             */
/*   Updated: 2022/12/18 12:15:02 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

//retourne une chaîne de caractères contenant un message
//descriptif de l'exception, utilisée pour fournir des
//informations sur l'exception aux utilisateurs ou aux développeurs

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
	    ~Bureaucrat(void);
        Bureaucrat	&operator=(Bureaucrat const &bureaucrat);

		std::string const &getName() const ;
		unsigned int const &getGrade()const ;

		void incrementGrade();
		void decrementGrade();
};
std::ostream	&operator<<(std::ostream &COUT, Bureaucrat const &bureaucrat);
#endif