#ifndef _BRAIN_HPP_
#define _BRAIN_HPP_
#include <iostream>

class Brain
{
private :
    std::string ideas_[100];
public :
	Brain(void);
	Brain(Brain const &copy);
	virtual ~Brain(void);
    Brain	&operator=(Brain const &brain);
    std::string getIdea(int i) const;
    void setIdea(std::string idea, int index);
};
#endif