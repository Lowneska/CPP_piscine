#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main()
{
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	try {
		std::cout << *easyfind(v, 2) << std::endl;
	} catch (std::exception &e) { std::cout << e.what() << std::endl; }

	std::cout << "------------------------------" << std::endl;
	
	try {
		std::cout << *easyfind(v, 100) << std::endl;
	} catch (std::exception &e) { std::cout << e.what() << std::endl; }	
	
	std::cout << "------------------------------" << std::endl;
}