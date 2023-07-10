#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <cstdlib>
#include <stack>
#include <iostream>
#include <stack>
#include <sstream>
#include <cstdlib>
#include <string>
class RPN
{
	public:

        RPN();
		RPN(std::string infix);
		RPN(RPN const &src);
		RPN&	operator=(RPN const &src);
		~RPN(void);
        int converter(std::string infix);
        int	is_operator(char str);
        int	is_integer(char str);
        void exec();
        

    private:
        std::string infix;
        std::stack<char> operators;
        std::stack<int> numbers;
        
};

#endif
