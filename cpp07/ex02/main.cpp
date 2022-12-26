#include "Array.hpp"

#define SIZE 5

int main()
{
	Array<int>		intA;
	Array<std::string>	stringA(SIZE);

	stringA[0] = "Look into my eyes child !";
	stringA[1] = "Are you my Nhaama?";
	
	std::cout << "intA size: " << intA.size() << std::endl;
	std::cout << "stringA size: " << stringA.size() << std::endl;
    std::cout << "réplique 01 : " << stringA[0] << std::endl;
    std::cout << "réplique 02 : " << stringA[1] << std::endl;

	Array<std::string>	cpyStringA;
	cpyStringA = stringA;
	cpyStringA[2] = "Indeed.";
	cpyStringA[0] = "Replace sentence.";

    std::cout << "réplique 01 : " << stringA[0] << std::endl;
    std::cout << "réplique 02 : " << cpyStringA[2] << std::endl;

	std::cout << "---------------------" << std::endl;

	try {
		std::cout << stringA[42] << std::endl;
	} catch (std::exception &e) { std::cout << e.what() << std::endl; }

	std::cout << "---------------------" << std::endl;
	
	try {
		std::cout << stringA[-42] << std::endl;
	} catch (std::exception &e) { std::cout << e.what() << std::endl; }
	
	std::cout << "---------------------" << std::endl;

	try {
		for (int i = 0; i < SIZE; i++)
			std::cout << stringA[i] << std::endl;
	} catch (std::exception &e) { std::cout << e.what() << std::endl; }

	std::cout << "---------------------" << std::endl;

	try {
		for (int i = 0; i < SIZE; i++)
			std::cout << cpyStringA[i] << std::endl;
	} catch (std::exception &e) { std::cout << e.what() << std::endl; }

	std::cout << "---------------------" << std::endl;

	try {
		for (int i = 0; i < 5; i++)
			std::cout << intA[i] << std::endl;
	} catch (std::exception &e) { std::cout << e.what() << std::endl; }
}