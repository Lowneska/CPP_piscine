#include "Phonebook.hpp"
#include  <iostream>
#include  <bits/stdc++.h>
#include <cstring>
PhoneBook::PhoneBook(void){
    this->nb_contacts = 0;
	this->index = 0;
};
PhoneBook::~PhoneBook(void){};

int	checkEntry(std::string entry)
{
	int i = 0;

	if (entry == "")
		return (1);
	while (entry[i])
	{
		std::cout << "Hello :" << entry[0]  << std::endl;
		if ((entry[i] != '\n') && (entry[i] != '\0') && (entry[i] != '\t') && (entry[i] != ' '))
			return (0);
		i++;
	}
	return (1);
}

int	checkIndex(std::string entry, int tabsize)
{
	int number = atoi(entry.c_str());

	if ((number < 0) || (number >= tabsize))
		return(std::cout << "Oups, wrong range of numbers ! Please try again : " << std::endl, 0);
	return (1);
}

int PhoneBook::add()
{
	Contact			c;
	std::string	entry;

	std::cout << "First name: ";
	std::getline(std::cin, entry);
	if (checkEntry(entry))
		return (0);
	c.setFirstName(entry);
	std::cout << "Last name: ";
	std::getline(std::cin, entry);
	if (checkEntry(entry))
		return (0);
	c.setLastName(entry);
	std::cout << "Nickname: ";
	std::getline(std::cin, entry);
	if (checkEntry(entry))
		return (0);
	c.setNickname(entry);
	std::cout << "Phone: ";
	std::getline(std::cin, entry);
	if (checkEntry(entry))
		return (0);
	c.setPhoneNumber(entry);
	std::cout << "Darkest secret: ";
	std::getline(std::cin, entry);
	if (checkEntry(entry))
		return (0);
	c.setDarkestSecret(entry);
	c.setIndex(this->index);
	this->listContacts[this->index] = c;
	(this->nb_contacts)++;
	if ((nb_contacts % 8 == 0) && (nb_contacts != 0))
		this->index = 0;
	else
		(this->index)++;
	return (1);
}

void PhoneBook::print_contacts()
{
	std::string	entry;
	int	tabsize;

	(this->nb_contacts > 8) ? (tabsize = 8) : (tabsize = this->nb_contacts);
	int j = 0;
	if (this->nb_contacts == 0)
		std::cout << "The phonebook is empty." << std::endl << std::endl;
	else
	{
		std::cout << std::setw(10) << "---------------------------------------------" << std::endl;
		std::cout << std::setw(10) << "|   index  " << "|" << std::setw(10) << "first name|"
			<< std::setw(10) << "last name |" << std::setw(10) << " nickname |" << std::endl;
		std::cout << std::setw(10) << "---------------------------------------------" << std::endl;
		for (int i = 0; i < tabsize; i++)
			this->listContacts[i].print();
		std::cout << std::setw(10) << "---------------------------------------------" << std::endl;
		std::cout << "Could you please enter the index of a chosen contact ?";
		while (j == 0)
		{
			std::getline(std::cin, entry);
			j = checkIndex(entry, tabsize);
		}
		this->listContacts[atoi(entry.c_str())].put_infos();
	}
}

//vérifier que l'index entrée est un int
//vérifier que le numéro de téléphone est un int
//gerer les arrow up down left right