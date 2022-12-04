/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:50:27 by skhali            #+#    #+#             */
/*   Updated: 2022/12/03 18:50:28 by skhali           ###   ########.fr       */
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
    Zombie(std::string name);
    ~Zombie();
    Zombie* newZombie( std::string name );
    void randomChump( std::string name );

};
#endif