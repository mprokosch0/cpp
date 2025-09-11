#include "../includes/RPN.hpp"

std::stack<float> RPN::_pile;

//Operators-----------------------------------------------------------

RPN & RPN::operator=(RPN const &right)
{
	(void)right;
	return *this;
}

//Constructors/destructors--------------------------------------------

RPN::RPN(void){}

RPN::RPN(RPN const &right)
{
	(void)right;
	return ;
}

RPN::~RPN(void){}

//Member functions----------------------------------------------------

static void trim(std::string &str)
{
	str.erase(str.find_last_not_of(" \n\r\t") + 1);
	str.erase(0, str.find_first_not_of(" \n\r\t"));
}

static int isOperator(char c)
{
	if (c == '*' || c == '+' || c == '-' || c == '/')
		return 1;
	return 0;
}

static void whichOperator(char c, float &dest, float src)
{
	switch ((c == '+') ? 1 : (c == '-') ? 2 : (c == '*') ? 3 : 4)
	{
		case 1:
			dest += src;
			break ;
		case 2:
			dest -= src;
			break ;
		case 3:
			dest *= src;
			break ;
		case 4:
			dest /= src;
			break ;
		default:
			break;
	}
}

void RPN::calculate(std::string str)
{
	trim(str);
	std::string::iterator it = str.begin();
	int i = 0;
	while (it != str.end())
	{
		if (*it != ' ' && !isdigit(*it) && !isOperator(*it))
		{
			std::cerr << RED "Error: Unidentified char" RESET << std::endl;
			return ;
		}
		if ((it == str.begin() && !isdigit(*it))) //if a char is at the wrong place or the first char isn't a operator
		{
			std::cerr << RED "Error: Input isn't formated corretly " RESET << std::endl;
			return ;
		}
		if (isdigit(*it))
			_pile.push(*it - 48);
		else if (isOperator(*it))
		{
			if (_pile.size() <= 1) //if we don't have enouth numbers to compute
			{
				std::cerr << RED "Error: Input isn't formated corretly " RESET << std::endl;
				return ;
			}
			int nb = _pile.top();
			_pile.pop();
			whichOperator(*it, _pile.top(), nb);
		}
		i++;
		it++;
	}
	if (_pile.size() != 1) // if we hadn't enouth operator and the stack is left with more than a number
		std::cerr << RED "Error: Input isn't formated corretly " RESET << std::endl;
	else
		std::cout << _pile.top() << std::endl;
	return ;
}