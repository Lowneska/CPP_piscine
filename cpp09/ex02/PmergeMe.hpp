#ifndef PMERGEME_CLASS_HPP
# define PMERGEME_CLASS_HPP

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <vector>
#include <deque>
#include <time.h>
#include <bits/types/clock_t.h>
#include <cctype>
#include <ctime>
#include <ios>
#include <limits.h>
#include <utility>


class PmergeMe
{
	private:

		int struggler;
		int size;
		std::vector<int> draft;
		std::vector<int> main;

		std::deque<int> draft_deque;
		std::deque<int> main_deque;
		int	parsing(char **str);
		int rechercheBinaire(const std::vector<int>& tableau, int valeur);

		std::vector<int> sortLargestElement(std::vector<int> draft, std::vector<std::pair<int, int> > dd, int size);
		void insert(std::vector<int> draft, int struggler, std::vector<std::pair<int, int> > dd);
		void printVector(std::vector<int> &v);

		std::deque<int> sortLargestElement_deque(std::deque<int> draft, std::deque<std::pair<int, int> > dd, int size);
		void insert_deque(std::deque<int> draft_deque, int struggler, std::deque<std::pair<int, int> > dd);
		void printDq(std::deque<int> &d);
		int rechercheBinairedq(const std::deque<int>& tableau, int valeur);


	public:

        PmergeMe();
		PmergeMe(char** input);
		PmergeMe(PmergeMe const &src);
		PmergeMe&	operator=(PmergeMe const &assign);
		~PmergeMe(void);
};

#endif
