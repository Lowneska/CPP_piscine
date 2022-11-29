#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <stdlib.h>

class Contact
{
	public:
		Contact();
		~Contact();

		void			setFirstName(std::string firstName);
		void			setLastName(std::string lastName);
		void			setNickname(std::string nickname);
		void			setPhoneNumber(std::string phoneNumber);
		void			setDarkestSecret(std::string darkestSecret);
		void			setIndex(int	index);
		void			put_infos();

        std::string		getFirstName(void) const;
		std::string		getLastName(void) const;
		std::string		getNickname(void) const;

		void			print();

	private:
        int         index;
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	darkestSecret;
};

#endif