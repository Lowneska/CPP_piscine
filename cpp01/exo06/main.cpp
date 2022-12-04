#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl harl;
	if (argc != 2)
		return (std::cout << "Invalid number of argument." << std::endl, 0);
	std::map<std::string, int> index;
	index["DEBUG"] = 4;
	index["INFO"] = 3;
	index["WARNING"] = 2;
	index["ERROR"] = 1;
	if (harl.function.find(argv[1]) == harl.function.end())
        return (std::cout << "[ Probably complaining about insignificant problems ]" << std::endl, 0);
	switch(index[argv[1]])
	{
		case 4 :
			harl.complain("DEBUG");
			// fall through
		case 3 :
			harl.complain("INFO");
			// fall through
		case 2 :
			harl.complain("WARNING");
			// fall through
		case 1 :
			harl.complain("ERROR");
			break ;
	}
	return (0);
}
