#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl harl;
	if (argc != 2)
		return (std::cout << "Invalid number of argument." << std::endl, 0);
	std::string	index[] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	int i;
	for (i = 0; i < 4; i++)
		if (index[i].compare(argv[1]) == 0)
			break;
	switch(i)
	{
		case 0 :
			harl.complain("DEBUG");
			// fall through
		case 1 :
			harl.complain("INFO");
			// fall through
		case 2 :
			harl.complain("WARNING");
			// fall through
		case 3:
			harl.complain("ERROR");
			break ;
		default :
			return (std::cout << "[ Probably complaining about insignificant problems ]" << std::endl, 0);
	}
	return (0);
}
