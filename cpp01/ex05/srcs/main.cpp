#include "../includes/harl.hpp"

int	main(void)
{
	Harl test;

	test.complain("DEBUG");
	test.complain("INFO");
	test.complain("WARNING");
	test.complain("ERROR");
	return 0;
}