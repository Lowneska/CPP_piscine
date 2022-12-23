#include <iostream>
#include <cctype>
#include <cstring>
#include <string>
#include <climits>

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

e_type getType(std::string input)
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

void isInt(std::string input)
{
    long value = stol(input, NULL, 10);
    if (value < INT_MIN || value > INT_MAX)
        std::cout << "Overflow : conversion de type en char, int, float, double impossible." << std::endl;
    else
    {
        if (value < CHAR_MIN || value > CHAR_MAX)
            std::cout << "char: impossible" << std::endl;
        else if(!isprint(static_cast<char>(value)))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char : '" << static_cast<char>(value) <<"'" << std::endl;
    }
}


void parsing(std::string input)
{
    switch (getType(input))
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
            isInt(input);
            break;
        case OTHER :
            std::cout << "other" << std::endl;
            break;
    }
}


int main(int ac, char **argv)
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
    parsing(argv[1]);


	return (0);
}