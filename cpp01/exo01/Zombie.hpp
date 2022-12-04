/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:50:27 by skhali            #+#    #+#             */
/*   Updated: 2022/12/03 19:13:21 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__
# include <string>

class Zombie {

private:
    std::string name;


public:

    void announce(void);
    Zombie();
    Zombie(std::string name);
    void setName(std::string name);
    ~Zombie();
    Zombie* zombieHorde( int N, std::string name );

};
#endif