#include <iostream>
#include <string>

int	main(void)
{
	std::string stringBAS = "HI THIS IS BRAIN";
	std::string *stringPTR = &stringBAS;
	std::string &stringREF = stringBAS;

	std::cout << "Memory adresses :" << std::endl;
	std::cout << "stringBAS: " << &stringBAS << std::endl
			<< "stringPTR: " << stringPTR << std::endl
			<< "stringREF: " << &stringREF << std::endl << std::endl;

	std::cout << "Values :" << std::endl;
	std::cout << "stringBAS: " << stringBAS << std::endl
			<< "stringPTR: " << *stringPTR << std::endl
			<< "stringREF: " << stringREF << std::endl;
	return 0;
}
