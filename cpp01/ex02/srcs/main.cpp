#include <iostream>
#include <string>

#define GREEN "\033[32m"
#define RESET "\033[0m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define BLUE "\033[34m"
#define GRAY "\033[90m"
#define PINK "\033[35m"

int	main(void)
{
	std::string stringBAS = "HI THIS IS BRAIN";
	std::string *stringPTR = &stringBAS;
	std::string &stringREF = stringBAS;

	std::cout << PINK "Memory adresses :" RESET << std::endl;
	std::cout << BLUE "stringBAS: " GREEN << &stringBAS << RESET << std::endl
			<< BLUE "stringPTR: " GREEN << stringPTR << RESET << std::endl
			<< BLUE "stringREF: " GREEN << &stringREF << RESET << std::endl << std::endl;

	std::cout << PINK "Values :" RESET << std::endl;
	std::cout << BLUE "stringBAS: " GREEN << stringBAS << RESET << std::endl
			<< BLUE "stringPTR: " GREEN << *stringPTR << RESET << std::endl
			<< BLUE "stringREF: " GREEN << stringREF << RESET << std::endl;
	return 0;
}
