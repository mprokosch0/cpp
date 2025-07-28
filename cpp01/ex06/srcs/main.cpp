#include "../includes/harl.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "\n[Probably complaining about insignificant problems]\n"
				<< std::endl;
		return 1;
	}
	Harl test;
	std::string	imput;
	imput = av[1];
	test.complain(imput);
	return 0;
}
