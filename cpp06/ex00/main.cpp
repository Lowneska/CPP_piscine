/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 10:54:28 by skhali            #+#    #+#             */
/*   Updated: 2022/12/24 10:54:28 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <cstring>
#include <string>
#include <climits>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <cfloat>

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

// The std::fixed manipulator is then used to set the output format to fixed-point notation,
// and the std::setprecision manipulator is used to set the precision to one decimal place.
void isInt(std::string input)
{
    std::string str = supress_space(input);
    long value = strtol(str.c_str(), NULL, 10);
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
        std::cout << "int: " << value << std::endl
        << std::setprecision(1) << std::fixed << 
        "float: " << static_cast<float>(value) << "f" << std::endl <<
        "double: " << static_cast<double>(value) << std::endl;
    }
}

//LES CHARCTERS non affichables ne sont pas passé au programme
void isChar(std::string input)
{
    std::string str = supress_space(input);
    char value = str[0];
    if(!isprint(static_cast<char>(value)))
        std::cout << "char: Non displayable" << std::endl;
    else
    std::cout << "char : '" << value <<"'" << std::endl;
    std::cout << "int: " << static_cast<int>(value) << std::endl
    << std::setprecision(1) << std::fixed << 
    "float: " << static_cast<float>(value) << "f" << std::endl <<
    "double: " << static_cast<double>(value) << std::endl;
}

void isFloat(std::string input)
{
    std::string str = supress_space(input);
    float value = strtof(str.c_str(), NULL);
    if (round(value) < CHAR_MIN || round(value) > CHAR_MAX || isnanf(value))
        std::cout << "char: impossible" << std::endl;
    else if(!isprint(static_cast<char>(value)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char : '" << static_cast<char>(value) <<"'" << std::endl;

    if (round(value) < INT_MIN || round(value) > INT_MAX || isnanf(value))
		std::cout << "int : impossible" << std::endl;
	else
		std::cout << "int :" << static_cast<int>(round(value)) << std::endl;
    std::cout << std::setprecision(1) << std::fixed << 
    "float: " << value << "f" << std::endl <<
    "double: " << static_cast<double>(value) << std::endl;
}

void isDouble(std::string input)
{
    std::string str = supress_space(input);
    double value = strtod(str.c_str(), NULL);
    if (round(value) < CHAR_MIN || round(value) > CHAR_MAX || isnanf(value))
        std::cout << "char: impossible" << std::endl;
    else if(!isprint(static_cast<char>(value)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char : '" << static_cast<char>(value) <<"'" << std::endl;

    if (round(value) < INT_MIN || round(value) > INT_MAX || std::isnan(value))
		std::cout << "int : impossible" << std::endl;
	else
		std::cout << "int :" << static_cast<int>(round(value)) << std::endl;

    std::cout << std::setprecision(1) << std::fixed;
    if (!std::isinf(value) && (value < FLT_MIN || value > FLT_MAX))
		std::cout << "float : impossible" << std::endl;
	else
		std::cout << "float :" << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << value << std::endl;
}

void parsing(std::string input)
{
    switch (getType(input))
    {
        case FLOAT :
            isFloat(input);
            break;
        case DOUBLE :
            isDouble(input);
            break;
        case CHAR :
            isChar(input);
            break;
        case INT :
            isInt(input);
            break;
        case OTHER :
            std::cout << input <<": is neither an int, nor a displayable char, float or double." << std::endl;
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