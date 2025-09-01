#ifndef BASE_HPP

# define BASE_HPP

# include <iostream>
# include <string>
# include <ctime>
# include <cstdlib>

# define GREEN "\033[32m"
# define RESET "\033[0m"
# define YELLOW "\033[33m"
# define RED "\033[31m"
# define BLUE "\033[34m"
# define GRAY "\033[90m"
# define PINK "\033[35m"

class Base
{
	public:
		virtual ~Base(void);
};

Base	* generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif