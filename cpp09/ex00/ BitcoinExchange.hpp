#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include <unistd.h>

class BitcoinExchange {
public:
    // Constructeur par défaut et copie
    BitcoinExchange();
    BitcoinExchange(std::string filename);
    BitcoinExchange(BitcoinExchange const &src);
    BitcoinExchange&	operator=(BitcoinExchange const &src);
    ~BitcoinExchange();

    // Méthode pour charger les données de prix depuis un fichier et les mettre dans une map
    int loadData(const std::string& filename, char delimiter);
    void findDate(std::string date, float *db_value);
    int check_date_format(std::string c_date);
    int is_digit(std::string str);
    int check_value_format(std::string value, float *d_value, int type);
    int check_delimiter(std::string line, char delimiter);
    int check_input(const std::string& filename, char delimiter);
    std::string trim(const std::string& str);
    std::string lowerExistingDate(std::string date);

private:
    std::map<std::string, float> database;
    std::string filename;
};

#endif