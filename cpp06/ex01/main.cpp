#include "Data.hpp"

int main(void)
{
    Data    *ptr = new Data;
    uintptr_t test;
    Data      *test2;
    
    std::cout << "\033[1;34mPlease enter a value : ";
    if (!(getline(std::cin, ptr->data)))
    {
        std::cout << "EOF" << std::endl;
        return (1);
    }
    test = serialize(ptr);
    test2 = deserialize(test);

    std::cout << "\033[m=========================" << std::endl;
    std::cout << "TEST OF REINTERPRETATION" << std::endl;
    std::cout << "=========================" << std::endl;

    std::cout << "ptr->data : " << ptr->data << std::endl;
    std::cout << "serialize : " << test << std::endl;
    std::cout << "deserialize : " << test2->data << std::endl;

}