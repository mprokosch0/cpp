#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

# define GREEN "\033[32m"
# define RESET "\033[0m"
# define YELLOW "\033[33m"
# define RED "\033[31m"
# define BLUE "\033[34m"
# define GRAY "\033[90m"
# define PINK "\033[35m"

class Harl
{
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
	
	public:
		Harl(void);
		~Harl(void);
		void complain(std::string level);
};

#endif