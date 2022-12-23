#include <iostream>
#include <cctype>
#include <cstring>

enum e_type { INT, FLOAT, DOUBLE, CHAR, OTHER};

std::string supress_space(std::string &input)
{
    std::string result;
    size_t start = 0;
    size_t end = input.size() - 1;

    while (start <= end && std::isspace(input[start]))
        ++start;
    while (end >= start && std::isspace(input[end]))
        --end;
    for (size_t i = start; i <= end; ++i)
        result += input[i];

    return result;
}

e_type parsing(std::string input)
{
    unsigned int i = 0;
    if (!input[i])
        return OTHER;
    std::string str = supress_space(input);
    if (!str[0])
        return OTHER;
    for (unsigned int j; j < str.size(); j++){
        if (!isprint(str[j]))
            return OTHER;}
   	if (str == "nanf" || str == "-inff" || str == "+inff")
		return FLOAT;
	if (str == "nan" || str == "-inf" || str == "+inf")
		return DOUBLE;
    if (!std::isdigit(str[0]) && (str.size() == 1))
        return CHAR;
    if (str[i] == '+' || str[i] == '-')
        i++;
    while (str[i] && std::isdigit(str[i]))
        i++;
    if (!str[i])
        return INT;
    if (str[i] == '.')
        i++;
    while (str[i] && std::isdigit(str[i]))
        i++;
    if (!str[i])
        return DOUBLE;
    if ((str[i] == 'f') && (i == (str.size() - 1)))
        return FLOAT;
    return OTHER; 
}

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "Not enough arguments" << std::endl;
		return (1);
	}
	else if (ac > 2)
	{
		std::cout << "Too many arguments" << std::endl;
		return (1);
	}
	std::string s(av[1]);
	switch (parsing(av[1]))
    {
        case FLOAT :
            std::cout << "float" << std::endl;
            break;
        case DOUBLE :
            std::cout << "double" << std::endl;
            break;
        case CHAR :
            std::cout << "char" << std::endl;
            break;
        case INT :
            std::cout << "int" << std::endl;
            break;
        case OTHER :
            std::cout << "other" << std::endl;
            break;
    }
	return (0);
}