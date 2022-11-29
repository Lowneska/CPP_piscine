#include "Phonebook.hpp"

int main()
{
    PhoneBook phonebook;
    std::string entry;

    while(1)
    {
        std::cout << "Welcome ! Please enter one of the following command: ADD, SEARCH, EXIT" << std::endl;
        getline(std::cin, entry);
        if (entry.compare("ADD") == 0)
            phonebook.add();
        else if (entry.compare("SEARCH") == 0)
            phonebook.print_contacts();
        else if (entry.compare("EXIT") == 0)
            break ;
        else
            std::cout << "Incorrect command. Please Try again." << std::endl;
    }
    return (1);
}