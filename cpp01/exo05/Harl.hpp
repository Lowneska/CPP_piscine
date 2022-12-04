#ifndef _HARL_
#define _HARL_
#include <iostream>
#include <map>
class Harl;
typedef void (Harl::*func)(void);

class Harl
{
    private :

        std::map<std::string, func> function;

        void debug(void);
        void info(void );
        void warning(void);
        void error(void);
    public :
        Harl();
        ~Harl();
        void complain(std::string level);
};
#endif