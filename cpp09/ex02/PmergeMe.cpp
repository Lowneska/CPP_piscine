#include "PmergeMe.hpp"


/*-------------------------------------------------------------------------*/
/*-----------------------------  Utils      -------------------------------*/
/*-------------------------------------------------------------------------*/

int	is_integer(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	if (atol(str) < INT_MIN || atol(str) > INT_MAX)
		return (0);
	return (1);
}

int is_singleton(char **str)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while(str[++i])
	{
		while(str[++j])
			if(atoi(str[i]) == atoi(str[j]))
				return (0);
		j = i + 1;
	}
	return (1);
}
int PmergeMe::rechercheBinaire(const std::vector<int>& tableau, int valeur) {
    int gauche = 0;
    int droite = tableau.size() - 1;

    while (gauche <= droite) {
        int milieu = gauche + (droite - gauche) / 2;

        if (tableau[milieu] == valeur) {
            return milieu;
        } else if (tableau[milieu] < valeur) {
            gauche = milieu + 1;
        } else {
            droite = milieu - 1;
        }
    }

    return -1;
}

int PmergeMe::rechercheBinairedq(const std::deque<int>& tableau, int valeur) {
    int gauche = 0;
    int droite = tableau.size() - 1;

    while (gauche <= droite) {
        int milieu = gauche + (droite - gauche) / 2;

        if (tableau[milieu] == valeur) {
            return milieu;
        } else if (tableau[milieu] < valeur) {
            gauche = milieu + 1;
        } else {
            droite = milieu - 1;
        }
    }

    return -1;
}
/*-------------------------------------------------------------------------*/
/*-----------------------------  Vector     -------------------------------*/
/*-------------------------------------------------------------------------*/

void PmergeMe::insert(std::vector<int> draft, int struggler, std::vector<std::pair<int, int> > dd)
{

	std::cout << "Struggler " <<  struggler << std::endl;
	printVector(draft);
	std::vector<std::pair<int, int> >::iterator it4;
    for (it4 = dd.begin(); it4 != dd.end(); it4++) {
        std::cout << "First " << it4->first << " Second " << it4->second << std::endl;
	}
	if (main.empty())
		main.push_back(draft.back());
	std::vector<std::pair<int, int> >::iterator it2;
	for (it2 = dd.begin(); it2 != dd.end(); it2++) {
		std::vector<int>::iterator it3;
		it3 = main.begin();
		 std::cout << "it3 " << *it3 << std::endl;
		  std::cout << "it2 second " << it2->second << std::endl;
    	while ((*it3 < it2->second) && (it3 != main.end())) {
			it3++;
		}
		if (it3 != main.end())
		{
			int index = rechercheBinaire(main, *it3);
			main.insert(main.begin() + index, it2->second);
		}
		printVector(main);
    }
	if (struggler >= 0)
	{
		std::vector<int>::iterator it3;
		it3 = main.begin();
    	while ((*it3 < struggler) && (it3 != main.end())) {
			it3++;
		}
		if (it3 != main.end())
		{
			int index = rechercheBinaire(main, *it3);
			main.insert(main.begin() + index, struggler);
		}
		else
			main.push_back(struggler);
	}
	printVector(main);
	std::cout << "----------------------------------------" << std::endl;

}

std::vector<int> PmergeMe::sortLargestElement(std::vector<int> draft, std::vector<std::pair<int, int> > dd, int size)
{
    std::vector<std::pair<int, int> > new_dd;
	int struggler = -42;
	std::vector<int> new_draft;
	(void)dd;
    std::vector<int>::iterator it = draft.begin();
	if (draft.size() == 1)
		return (draft);

	if (size % 2 == 1)
	{
		struggler = draft.back();
		draft.pop_back();
	}
	while (it != draft.end())
	{
		int first = *it;
		++it;
		if (it != draft.end())
		{
			int second = *it;
			if (first > second)
			{
				new_draft.push_back(first);
				new_dd.push_back(std::make_pair(first, second));
				
			}
			else
			{
				new_dd.push_back(std::make_pair(second, first));
				new_draft.push_back(second);
			}
		}
		++it;
	}
	insert(sortLargestElement(new_draft, new_dd, new_draft.size()), struggler, new_dd);
	/*std::vector<int>::iterator it3;
    for (it3 = main.begin(); it3 != main.end(); it3++) {
        std::cout << "main " << *it3 << std::endl;
	}*/
	return draft;
}

void PmergeMe::printVector(std::vector<int> &v)
{
	std::vector<int>::iterator	it;

	for (it = v.begin(); it != v.end(); ++it)
		std::cout << " " << *it;
	std::cout << std::endl;
}

/*---------------------------------------------------------------------------------------------*/


void PmergeMe::insert_deque(std::deque<int> draft_deque, int struggler, std::deque<std::pair<int, int> > dd)
{

	if (main_deque.empty())
		main_deque.push_back(draft_deque.back());
	std::deque<std::pair<int, int> >::iterator it2;
	for (it2 = dd.begin(); it2 != dd.end(); ++it2) {
		std::deque<int>::iterator it3;
		it3 = main_deque.begin();
    	while ((*it3 < it2->second) && (it3 != main_deque.end())) {
			it3++;
		}
		if (it3 != main_deque.end())
		{
			int index = rechercheBinairedq(main_deque, *it3);
			main_deque.insert(main_deque.begin() + index, it2->second);
		}
    }
	if (struggler >= 0)
	{
		std::deque<int>::iterator it3;
		it3 = main_deque.begin();
    	while ((*it3 < struggler) && (it3 != main_deque.end())) {
			it3++;
		}
		if (it3 != main_deque.end())
		{
			int index = rechercheBinairedq(main_deque, *it3);
			main_deque.insert(main_deque.begin() + index, struggler);
		}
	}

}

std::deque<int> PmergeMe::sortLargestElement_deque(std::deque<int> draft_deque, std::deque<std::pair<int, int> > dd, int size)
{
    std::deque<std::pair<int, int> > new_dd;
	int struggler = -42;
	std::deque<int> new_draft;
	(void)dd;
    std::deque<int>::iterator it = draft_deque.begin();
	if (draft_deque.size() == 1)
		return (draft_deque);

	if (size % 2 == 1)
	{
		struggler = draft_deque.back();
		draft_deque.pop_back();
	}
	while (it != draft_deque.end())
	{
		int first = *it;
		++it;
		if (it != draft_deque.end())
		{
			int second = *it;
			if (first > second)
			{
				new_draft.push_back(first);
				new_dd.push_back(std::make_pair(first, second));
				
			}
			else
			{
				new_dd.push_back(std::make_pair(second, first));
				new_draft.push_back(second);
			}
		}
		++it;
	}
	insert_deque(sortLargestElement_deque(new_draft, new_dd, new_draft.size()), struggler, new_dd);
	/*std::deque<int>::iterator it3;
    for (it3 = new_draft.begin(); it3 != new_draft.end(); it3++) {
        std::cout << "main_deque " << *it3 << std::endl;
	}
	(void)struggler;*/
	return draft_deque;
}

void PmergeMe::printDq(std::deque<int> &d)
{
	std::deque<int>::iterator	it;
	for (it = d.begin(); it != d.end(); ++it)
		std::cout << " " << *it;
	std::cout << std::endl;
}

/*---------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/

int PmergeMe::parsing(char **str)
{
	clock_t	start, finish;
	double	time_v, time_d;
	int i = 1;
	while (str[i])
	{
		if (!is_integer(str[i]))
			return (0);
		i++;
	}
	if (!is_singleton(str++))
		return (0);
	this->size = i - 1;
	i = 1;
	str--;
	while (str[i] && i != (size + 1))
	{
		draft.push_back(atoi(str[i]));
		draft_deque.push_back(atoi(str[i]));
		i++;
	}

	//std::cout << "Before :";
	//printVector(draft);
	std::cout << "After :";

	std::vector<std::pair<int, int> > dd;
	start = clock();
	sortLargestElement(draft, dd, this->size);
	finish = clock();
	time_v = ((double) (finish - start)) / CLOCKS_PER_SEC;
	printVector(main);


	std::deque<std::pair<int, int> > dd_dq;
	start = clock();
	sortLargestElement_deque(draft_deque, dd_dq, this->size);
	finish = clock();
	time_d = ((double) (finish - start)) / CLOCKS_PER_SEC;
	//printDq(main_deque);
	std::cout << "Time to process a range of " << main.size() << " elements with std::vector is: " << std::fixed << time_v  * 1000000<< " us" << std::endl;
	std::cout << "Time to process a range of " << main_deque.size() << " elements with std::deque is: " << std::fixed << time_d * 1000000 << " us" << std::endl;

	
	return (1);
}


/*--------------------------------------------------*/
/*-------------------------------------------------*/
/*------------------------------------------------*/

PmergeMe::PmergeMe(char** unsorted)
{
	if (!parsing(unsorted))
	{
		std::cout << "Error." << std::endl;
	}
	return ;
}

PmergeMe::PmergeMe(PmergeMe const &src)
{
	*this = src;
	return ;
}

PmergeMe &	PmergeMe::operator=(const PmergeMe &src)
{
	*this = src;
	return (*this);
}

PmergeMe::~PmergeMe(void)
{
	return ;
}
