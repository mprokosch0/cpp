#ifndef RPN_HPP

# define RPN_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <stdlib.h>
# include <stack>

# define GREEN "\033[32m"
# define RESET "\033[0m"
# define YELLOW "\033[33m"
# define RED "\033[31m"
# define BLUE "\033[34m"
# define GRAY "\033[90m"
# define PINK "\033[35m"

class RPN
{
	private:
		static std::stack<float> _pile;
	
	private:
		RPN(void);
		RPN(RPN const &right);
		RPN &operator=(RPN const &right);
		~RPN(void);
	
	public:
		static void calculate(std::string str);
};


#endif