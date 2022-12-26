/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:41:57 by skhali            #+#    #+#             */
/*   Updated: 2022/12/26 13:41:58 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm> // Pour utiliser std::copy
#include <iterator>  // Pour utiliser les itérateurs
#include <vector> 

Span::Span(Span const & span) : _vector(span._vector)
{
	this->_size = span._size;
	this->_sizeMax = span._sizeMax;
}

Span	&Span::operator=(Span const & span)
{
    this->_sizeMax = span._sizeMax;
	this->_size = span._size;
	return *this;
}

Span::~Span() {}

void	Span::addNumber(int number)
{
	if (this->_size == this->_sizeMax)
		throw FullVectorException();
	this->_vector.push_back(number);
    (this->_size)++;
}

int	Span::shortestSpan()
{
	if (this->_vector.size() < 2)
		throw NotEnoughElementsException();

    std::vector<int> copy(this->_vector);
    std::sort(copy.begin(), copy.end());

	int shortest = copy[1] - copy[0];
	for (size_t i = 1; i < copy.size() - 1; ++i)
    {
        int span = copy[i + 1] - copy[i];
        if (span < shortest) {
            shortest = span;
        }
    }
	return shortest;
}

int	Span::longestSpan()
{
	if (this->_vector.size() < 2)
		throw NotEnoughElementsException();

    std::vector<int> copy(this->_vector);
    std::sort(copy.begin(), copy.end());

	int longest = copy.back() - copy.front();
	return longest;
}

unsigned int	Span::getSize()
{
	return this->_size;
}

unsigned int	Span::getSizeMax()
{
	return this->_sizeMax;
}

void	Span::rangeOfIter(std::vector<int>::iterator start, std::vector<int>::iterator end, std::vector<int> v)
{
	if (this->_sizeMax < (this->_size + v.size()))
		throw FullVectorException();
	copy(start, end, std::back_inserter(this->_vector));
}

void	Span::affValues()
{
	std::cout << "Values: " << std::endl;
	for (std::vector<int>::iterator it = this->_vector.begin(); it != this->_vector.end(); it++)
		std::cout << "\t-> " << *it << std::endl;
}