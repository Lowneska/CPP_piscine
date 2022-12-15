#ifndef _HARL_
#define _HARL_
#include <iostream>
class Harl;
typedef void (Harl::*func)(void);
typedef struct s_pair
{
    std::string key;
    func        value;
} t_pair;

typedef struct s_newpair
{
    std::string key;
    int        value;
} t_newpair;
class Harl
{
    private :

        static t_pair function[];
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