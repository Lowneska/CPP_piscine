/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 23:13:55 by skhali            #+#    #+#             */
/*   Updated: 2022/12/18 23:13:56 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <fstream>
# include "Form.hpp"
#include <cstdlib>


class PresidentialPardonForm : public Form
{
private:
	std::string	_target;

public:
	PresidentialPardonForm();
    PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const &src);
	virtual ~PresidentialPardonForm(void);

	// Member functions
	virtual void	execute(Bureaucrat const &executor) const;

	PresidentialPardonForm	&operator=(PresidentialPardonForm const &form);
};

#endif