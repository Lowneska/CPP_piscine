/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:42:08 by skhali            #+#    #+#             */
/*   Updated: 2022/12/26 13:42:09 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>

class NotFoundException : public std::exception
{
	public:
		virtual const char *what() const throw() {
			return "Element not found.";
		}
};

//An iterator is an object that allows a programmer to traverse through
//the elements of a container, such as a list or a vector.
//It acts as a pointer to an element in a container and can be used to
//access and modify the element at the position it points to.
//typename T::iterator -> variable de type iterator
template<typename T>
typename T::iterator	easyfind(T cont, int element)
{
	typename T::iterator i = std::find(cont.begin(), cont.end(), element);
	if (i == cont.end())
		throw NotFoundException();
	else
		return i;
}

#endif