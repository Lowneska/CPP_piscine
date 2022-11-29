#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <string.h>
#include <string>
# include <iostream>
# include <iomanip>
# include <stdlib.h>

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();

		int add();
		void print_contacts();

	private:
		int	nb_contacts;
		int	index;
        Contact listContacts[8];
};


#endif