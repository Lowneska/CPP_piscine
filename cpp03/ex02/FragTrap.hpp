/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:24:25 by skhali            #+#    #+#             */
/*   Updated: 2022/12/12 16:28:06 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FRAGTRAP_HPP_
#define _FRAGTRAP_HPP_
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap();
        FragTrap(std::string);
        ~FragTrap();
        FragTrap(FragTrap const &copy);
        FragTrap &operator=(FragTrap const & rhs);

        void highFivesGuys(void);
        void attack(const std::string& target);
};
#endif