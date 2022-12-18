/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 23:13:47 by skhali            #+#    #+#             */
/*   Updated: 2022/12/18 23:13:48 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <fstream>
# include "Form.hpp"
#include <cstdlib>


class RobotomyRequestForm : public Form
{
private:
	std::string	_target;

public:
	RobotomyRequestForm();
    RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const &src);
	virtual ~RobotomyRequestForm(void);

	// Member functions
	virtual void	execute(Bureaucrat const &executor) const;

	RobotomyRequestForm	&operator=(RobotomyRequestForm const &form);
};

#endif