/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:19:21 by skhali            #+#    #+#             */
/*   Updated: 2022/12/04 10:29:13 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
    std::string name = "HI THIS IS BRAIN";
    std::string *strPTR = &name;
    std::string &strREF = name;

    std::cout << "----- Adresses -----" << std::endl;
    std::cout << "adresse str: " << &name << std::endl;
    std::cout << "adresse strPTR: " << strPTR << std::endl;
    std::cout << "adresse strREF: " << &strREF << std::endl;
    
    std::cout << "----- Valeurs -----" << std::endl;
    std::cout << "valeur str: " << name << std::endl;
    std::cout << "valeur strPTR: " << *strPTR << std::endl;
    std::cout << "valeur strREF: " << strREF << std::endl;
}