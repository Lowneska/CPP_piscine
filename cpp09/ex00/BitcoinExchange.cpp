#include " BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

BitcoinExchange::BitcoinExchange(void)
{
	return ;
}

BitcoinExchange::BitcoinExchange(std::string filename)
{
    loadData("data.csv", ',');
    if (!check_input(filename, '|'))
    {
        return ;
    }
	return ;
}
BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
	*this = src;
	return ;
}

BitcoinExchange &	BitcoinExchange::operator=(const BitcoinExchange &src)
{
    this->filename = src.filename;
	*this = src;
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
	return ;
}

/*-------------------------------------------------------------------------*/
/*--------------------------- Utils et checkers --------------------------*/
/*-----------------------------------------------------------------------*/

std::string BitcoinExchange::trim(const std::string& str)
{
    size_t first = str.find_first_not_of(' ');
    if (std::string::npos == first) {
        return ""; // La chaîne est composée uniquement d'espaces
    }

    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

int BitcoinExchange::check_delimiter(std::string line, char delimiter)
{

    size_t foundPos = line.find(delimiter);

    if (foundPos != std::string::npos && line.find(delimiter, foundPos + 1) == std::string::npos) {
        return 1;
    }

    return 0;
}

int BitcoinExchange::check_value_format(std::string value, float *d_value, int type)
{
    size_t i = 0;
    while (value[i] == ' ' || value[i] == '\t')
        i++;
    if (i == value.length())
        return (0);
    while (i < value.length())
    {
        if (((value[i] > 57) || (value[i] < 48)) && (value[i] != '.') && (value[i] != '-'))
            return (0);
        i++;
    }
    if (value[0] == '-')
        return (std::cout << "Error: not a positive number." << std::endl, 0);
    std::istringstream iss(value);
    iss >> *d_value;
    if (type == 1)
    {
        if ((*d_value > 1000))
            return (std::cout << "Error: too large of a number." << std::endl, 0);
        else if (*d_value < 0)
            return (std::cout <<"Error: not a positive number." << std::endl, 0);
    }
    return (1);
}

int BitcoinExchange::is_digit(std::string str)
{
    size_t i = 0;
    while (i < str.length())
    {
        if (((str[i] > 57) || (str[i] < 48)))
            return (0);
        i++;
    }
    return (1);
}

int BitcoinExchange::check_date_format(std::string c_date)
{
    std::string year, month, day, date;
    date = trim(c_date);
    std::stringstream date_ss(date);

    if ((date.length() != 10) || (date[4] != '-') || (date[7] != '-'))
        return (0);
    getline(date_ss, year, '-');
    if (!is_digit(year))
        return(0);
    int i_year = std::atoi(year.c_str());
    if ((i_year < 2009) || (i_year > 2024))
        return (0);
    getline(date_ss, month, '-');
    if (!is_digit(month))
        return(0);
    int i_month = std::atoi(month.c_str());
    if (i_month < 1 || i_month > 12)
        return (0);
    getline(date_ss, day);
    if (!is_digit(day))
        return(0);
    int i_day = std::atoi(day.c_str());
    if (i_month == 1 || i_month == 3 || i_month == 5 || i_month == 7 || i_month == 8 || i_month == 10 || i_month == 12)
    {
        if (i_day < 1 || i_day > 31)
            return (0);
    }
    else if (i_month == 2)
    {
        if (i_year % 4 == 0)
        {
            if (i_day < 1 || i_day > 29)
                return (0);
        }
        else
        {
            if (i_day < 1 || i_day > 28)
                return (0);
        }
    }
    else
    {
        if (i_day < 1 || i_day > 30)
            return (0);
    }
    //dates specifiques

    //autres
    if (i_year == 2009 && i_month == 1 && i_day < 2)
        return (0);
    return (1);
}

/*--------------------------------------------------------------*/
/*------------------------ "Parsing" --------------------------*/
/*------------------------------------------------------------*/

int BitcoinExchange::check_input(const std::string& filename, char delimiter)
{
    std::fstream file;
    std::string line, date, value;
    float d_value;
    float db_value;

    file.open(filename.c_str(), std::ios::in);
    if (!file.is_open())
        return (std::cout << "No such file." << std::endl, 0);
    else
    {
        getline(file, line);
        while(getline(file, line))
        {
            if (!check_delimiter(line, delimiter))
            {
                std::cout << "Error: bad input => " << line << std::endl;
                continue ;
            }
            std::stringstream line_ss(line);
            getline(line_ss, date, delimiter);
            getline(line_ss, value);
            if (!check_value_format(value, &d_value, 1))
                continue;
            if (!check_date_format(date))
            {
                std::cout << "Error: bad input => " << date << std::endl;
                continue;
            }
            findDate(trim(date), &db_value);
            std::cout << date << " => " << d_value << " = " << db_value * d_value << std::endl;
        }
    }
    return 1;
}

std::string BitcoinExchange::lowerExistingDate(std::string date)
{
    std::stringstream date_ss(date);
    std::string year, month, day;
    getline(date_ss, year, '-');
    getline(date_ss, month, '-');
    getline(date_ss, day);
    int i_year = std::atoi(year.c_str());
    int i_month = std::atoi(month.c_str());
    int i_day = std::atoi(day.c_str());
    if (i_day == 1)
    {
        if (i_month == 3 || i_month == 5 || i_month == 7 || i_month == 8 || i_month == 10 || i_month == 12)
        {
            i_month--;
            i_day = 31;
        }
        else if (i_month == 2)
        {
            i_month--;
            if (i_year % 4 == 0)
                i_day = 29;
            else
                i_day = 28;
        }
        else if (i_month == 1)
        {
            i_year--;
            i_month = 12;
            i_day = 31;
        }
        else
        {
            i_month--;
            i_day = 30;
        }
    }
    else
        i_day --;
    std::ostringstream result;
    result << i_year << '-' << std::setw(2) << std::setfill('0') << i_month << '-' << std::setw(2) << std::setfill('0') << i_day;

    return (result.str());
}
void BitcoinExchange::findDate(std::string date, float *db_value)
{
    if (database.find(date) != database.end())
    {
        *db_value = database[date];
    } else {
        std::string new_date = lowerExistingDate(date);
        findDate(new_date, db_value);
    }
}

int BitcoinExchange::loadData(const std::string& filename, char delimiter)
{
    std::fstream file;
    std::string line, date, value;
    float d_value;

    file.open(filename.c_str(), std::ios::in);
    if (!file.is_open())
        return (std::cout << "No such file." << std::endl, 0);
    else
    {
        getline(file, line);
        while(getline(file, line))
        {
            std::stringstream line_ss(line);
            getline(line_ss, date, delimiter);
            getline(line_ss, value);
            if (!check_value_format(value, &d_value, 0))
                return (std::cout << "Wrong value format." << std::endl, 0);
            if (!check_date_format(date))
                return (std::cout << "Wrong date format." << std::endl, 0);
            database[trim(date)] = d_value;
        }
    }
    return 1;
}
