/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:42:00 by skhali            #+#    #+#             */
/*   Updated: 2022/12/26 13:42:01 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <cstdlib>

class Span
{
    private:
		std::vector<int>	_vector;
		unsigned int		_size;
        unsigned int        _sizeMax;

		class FullVectorException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "The vector is full.";
				}
		};

		class NotEnoughElementsException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Not enough elements.";
				}
		};
	public:
        Span() : _size(0) {};
		Span(unsigned int N) : _size(0), _sizeMax(N) {};
		Span(Span const & span);
		Span &operator=(Span const & rhs);
		~Span();

		void	addNumber(int number);
        int		shortestSpan();
		int		longestSpan();
        unsigned int	getSize();
        unsigned int	getSizeMax();
        void    rangeOfIter(std::vector<int>::iterator start, std::vector<int>::iterator end, std::vector<int> v);
		void	affValues();
};

#endif