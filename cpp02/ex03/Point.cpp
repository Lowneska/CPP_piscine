/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:27:37 by skhali            #+#    #+#             */
/*   Updated: 2022/12/13 12:34:51 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point()
{
	std::cout << "Point default constructor called." << std::endl;
	this->x = Fixed();
	this->y = Fixed();
}

Point::Point(const float val1, const float val2)
{
	std::cout << "Point constructor called." << std::endl;
	this->x = Fixed(val1);
	this->y = Fixed(val2);
}

Point::~Point()
{
	std::cout << "Point destructor called." << std::endl;
}

Point::Point(Point const &point)
{
	this->x = Fixed();
}