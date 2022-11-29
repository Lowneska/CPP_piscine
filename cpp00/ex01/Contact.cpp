#include "Contact.hpp"

Contact::Contact(void){};

Contact::~Contact(void){};

void		Contact::print(void)
{
	std::cout << "|" << std::setw(10) << this->index << "|"; 
	if (this->firstName.length() > 10)
		std::cout << this->firstName.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << this->firstName << "|";
	if (this->lastName.length() > 10)
		std::cout << this->lastName.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << this->lastName << "|";
	if (this->nickname.length() > 10)
		std::cout << this->nickname.substr(0, 9) << ".|" << std::endl;
	else
		std::cout << std::setw(10) << this->nickname << "|" << std::endl;

}

void	Contact::put_infos()
{
		std::cout << "Firstname: " << this->firstName << std::endl;
		std::cout << "Lastname: " << this->lastName << std::endl;
		std::cout << "Nickname: " << this->nickname << std::endl;
		std::cout << "Phone number: " << this->phoneNumber << std::endl;
		std::cout << "Darkest secret: " << this->darkestSecret << std::endl;
}

void		Contact::setFirstName(std::string firstName)
{
	this->firstName = firstName;
}

void		Contact::setLastName(std::string lastName)
{
	this->lastName = lastName;
}

void		Contact::setNickname(std::string nickname)
{
	this->nickname = nickname;
}

void		Contact::setPhoneNumber(std::string phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

void		Contact::setDarkestSecret(std::string darkestSecret)
{
	this->darkestSecret = darkestSecret;
}

std::string	Contact::getFirstName(void) const
{
	return (this->firstName);
}

std::string	Contact::getLastName(void) const
{
	return (this->lastName);
}

std::string	Contact::getNickname(void) const
{
	return (this->nickname);
}

void		Contact::setIndex(int	index)
{
	this->index = index;
}