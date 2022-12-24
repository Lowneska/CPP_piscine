#include "iter.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

template<typename T>
void	print(T &a)
{
	std::cout << a << std::endl;
}

template<typename T>
void	incr(T &a)
{
	a++;
}

int main(void)
{
    char test[19] = "Merry Christmas !\n";
    std::cout << "--------------- Print test --------------- " << std::endl;
    iter(test, 19, &print);

    int test2[15] = {1, 2, 3, 4, 5};
    std::cout << "--------------- Incrementation test --------------- " << std::endl;
    iter(test2, 5, &incr);
    iter(test2, 5, &print);
 

}