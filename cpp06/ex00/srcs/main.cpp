
#include "../includes/ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << RED "Error: More or less than 1 arg" RESET << std::endl;
		return 1;
	}
	ScalarConverter::convert(av[1]);
	return 0;
}