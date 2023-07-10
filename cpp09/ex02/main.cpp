#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 3)
	{
		std::cout <<"Invalid number of arguments." << std::endl;
	}
	PmergeMe	sort(argv);
	return (0);
}
