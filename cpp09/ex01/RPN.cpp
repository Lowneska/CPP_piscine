#include "RPN.hpp"

/*--------------------------------------------*/
/*-------------------------------------------*/

int	RPN::is_integer(char str)
{
	if (str < '0' || str > '9')
		return (0);
	return (1);
}
int	RPN::is_operator(char str)
{
    if (str == '+' || str == '-' || str == '/' || str == '*')
		return (1);
    return (0);
    
}

void RPN::exec()
{
	int	num1, num2, result;
	char op;

	num1 = numbers.top();
	numbers.pop();
	num2 = numbers.top();
	numbers.pop();
	op = operators.top();
	operators.pop();
	if (op == '+')
		result = num1 + num2;
	else if (op == '-')
		result = num1 - num2;
	else if (op == '*')
		result = num1 * num2;
	else if (op == '/')
		result = num1 / num2;
	numbers.push(result);
}

int RPN::converter(std::string infix)
{
	int i = 0;
    int size = infix.size();
	if (size == 0)
		return (0);
    while (i < size)
    {
        if (infix[i] != ' ')
        {
            if (is_integer(infix[i]) != 0)
				numbers.push(infix[i] - '0');
			else if (is_operator(infix[i]))
            {
                operators.push(infix[i]);
                if (numbers.size() <= operators.size())
                    return (0);
            }
			else
                return (0);
            if (operators.size() == 1 && numbers.size() >= 2)
			    exec();
        }
		i++;
    }
    return (1);
}

/*-------------------------------------------------*/
/*------------------------------------------------*/
RPN::RPN(void){}
RPN::RPN(std::string infix)
{
    this->infix = infix;
    if (converter(infix) == 0)
		std::cout << "Error" << std::endl;
    else
		std::cout << numbers.top() << std::endl;

}

RPN::RPN(RPN const &src)
{
	*this = src;
}

RPN &	RPN::operator=(const RPN &src)
{
	this->infix = src.infix;
	return (*this);
}

RPN::~RPN(void){ return ;}