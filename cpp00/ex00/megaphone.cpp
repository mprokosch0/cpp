#include <iostream>
#include <cctype>

#define print std::cout
#define endl std::endl

void upper(char *str)
{
	for (size_t i = 0; str[i]; i++)
		str[i] = std::toupper(str[i]);
}

int main(int ac, char **av)
{
	if (ac == 1)
		return (print << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl , 0);
	for (size_t i = 1; av[i]; i++)
	{
		upper(av[i]);
		print << av[i] << ' ';
	}
	return (print << endl, 0);
}
