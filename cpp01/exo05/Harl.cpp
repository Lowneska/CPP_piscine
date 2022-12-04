#include "Harl.hpp"
#include <map>
#include <string>
#include <iostream>
#include <utility>

Harl::Harl()
{
    function.insert(std::pair<std::string, func>("DEBUG", &Harl::debug));
    function.insert(std::pair<std::string, func>("INFO", &Harl::info));
    function.insert(std::pair<std::string, func>("WARNING", &Harl::warning));
    function.insert(std::pair<std::string, func>("ERROR", &Harl::error));
}

Harl::~Harl()
{
    std::cout << "Harl destroyed." << std::endl;

}
void Harl::debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\nI really do !\n" << std::endl;
}
void Harl::info(void )
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger !\nIf you did, I wouldn’t be asking for more !\n" << std::endl;
}
void Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}
void Harl::error(void)
{
    std::cout << "This is unacceptable ! I want to speak to the manager now.\n" << std::endl;
}

void Harl::complain(std::string level)
{
    if (function.find(level) == function.end()) {
        std::cout << "Value not found !" << std::endl;
    } else {
        (this->*function[level])();
    }
}
