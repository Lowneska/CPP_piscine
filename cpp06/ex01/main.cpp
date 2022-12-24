/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 10:54:23 by skhali            #+#    #+#             */
/*   Updated: 2022/12/24 10:54:24 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

int main(void)
{
    Data    *ptr = new Data;
    uintptr_t test;
    Data      *test2;
    
    ptr->data = "Is it working ?";
    test = serialize(ptr);
    test2 = deserialize(test);

    std::cout << "ptr->data : " << ptr->data << std::endl;
    std::cout << "serialize : " << test << std::endl;
    std::cout << "deserialize : " << test2->data << std::endl;

}