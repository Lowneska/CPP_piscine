#include "Brain.hpp"
#include <string>
Brain::Brain()
{
    std::cout << "Brain default constructor created." << std::endl;
};

Brain::Brain(Brain const &copy)
{
    std::cout << "Brain copy constructor created." << std::endl;
	for (int i = 0 ; i < 100; i++)
		this->ideas_[i] = copy.ideas_[i];
}

Brain::~Brain(void)
{
    std::cout << "Brain destructor called." << std::endl;
};

std::string Brain::getIdea(int i) const
{
    if ((i >= 100) || (i < 0))
        return (std::cout << "Incorrect index." << std::endl, "");
    else
	    return (this->ideas_[i]);
}

void Brain::setIdea(std::string idea, int index)
{
    if ((index >= 100) || (index < 0))
        std::cout << "Incorrect index." << std::endl;
    else
        this->ideas_[index] = idea;
}

Brain	&Brain::operator=(Brain const &brain)
{
	for (int i = 0 ; i < 100; i++)
		this->ideas_[i] = brain.ideas_[i];
	return *this;
}