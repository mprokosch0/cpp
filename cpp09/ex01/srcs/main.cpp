#include "../includes/RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << RED "Error: Wrong number of arguments, expected 1" RESET << std::endl;
		std::cerr << GRAY "Usage: ./RPN <list of operations>" RESET << std::endl;
		return 1;
	}
	RPN::calculate(av[1]);
	return 0;
}