#include "../includes/BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << RED "Error: Wrong number of arguments, expected 1" RESET << std::endl;
		std::cerr << GRAY "Usage: ./btc file.txt" RESET << std::endl;
		return 1;
	}
	BitcoinExchange::loadDatabase();
	BitcoinExchange::convertFile(av[1]);
	return 0;
}