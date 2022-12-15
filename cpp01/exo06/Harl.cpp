#include "Harl.hpp"
#include <string>
#include <iostream>

t_pair	Harl::function[] = {
	{std::string("DEBUG"), &Harl::debug},
	{std::string("INFO"), &Harl::info},
	{std::string("WARNING"), &Harl::warning},
	{std::string("ERROR"), &Harl::error},
};

Harl::Harl(){};

Harl::~Harl(){};

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
    int i;
    for(i = 0; i < 4; i++)
    {
        if (this->function[i].key.compare(level) == 0)
        {
            (this->*function[i].value)();
            break;
        }
    }
    if (i == 4)
        std::cout << "No value found !\n" << std::endl;
}
